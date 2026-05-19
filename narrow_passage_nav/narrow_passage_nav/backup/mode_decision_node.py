#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from collections import deque
from dataclasses import dataclass
import numpy as np

import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from narrow_passage_msgs.msg import NarrowDecision

@dataclass
class MemoryItem:
    geom_margin: float
    norm_e: float
    left_near: float
    right_near: float
    risk: float
    mode: str
    success_like: float


class ModeDecisionNode(Node):
    def __init__(self):
        super().__init__('mode_decision_node')

        self.declare_parameter('decision_topic', '/narrow_decision')
        self.declare_parameter('nominal_cmd_topic', '/nominal_cmd_vel')
        self.declare_parameter('memory_size', 50)

        self.declare_parameter('safe_distance', 0.7)
        self.declare_parameter('k_v', 0.5)
        self.declare_parameter('v_max', 0.3)

        self.declare_parameter('k_omega_align', 2.0)
        self.declare_parameter('omega_max', 0.8)

        self.declare_parameter('explore_speed', 0.05)
        self.declare_parameter('reject_stop', True)

        self.declare_parameter('step_v_back', 0.05)
        self.declare_parameter('step_omega', 0.6)

        self.memory = deque(maxlen=int(self.get_parameter('memory_size').value))
        self.current_mode = "EXPLORE"

        decision_topic = self.get_parameter('decision_topic').value
        nominal_cmd_topic = self.get_parameter('nominal_cmd_topic').value

        self.sub_decision = self.create_subscription(
            NarrowDecision, decision_topic, self.decision_callback, 10
        )
        self.pub_nominal_cmd = self.create_publisher(Twist, nominal_cmd_topic, 10)

        self.get_logger().info(f"[ModeDecisionNode] sub={decision_topic}, pub={nominal_cmd_topic}")

    def decision_callback(self, msg: NarrowDecision):
        memory_risk = self.retrieve_memory_risk(msg)
        fused_risk = float(np.clip(0.7 * msg.risk + 0.3 * memory_risk, 0.0, 1.0))
        passability = float(np.clip(0.7 * msg.passability + 0.3 * (1.0 - memory_risk), 0.0, 1.0))

        mode = self.select_mode(msg, passability, fused_risk)
        self.current_mode = mode

        cmd = self.compute_nominal_action(msg, mode)
        self.pub_nominal_cmd.publish(cmd)

        self.update_memory(msg, mode, passability, fused_risk)

    def retrieve_memory_risk(self, msg: NarrowDecision) -> float:
        if len(self.memory) == 0:
            return msg.risk

        sims = []
        for item in self.memory:
            dist = (
                abs(item.geom_margin - msg.geom_margin)
                + 0.5 * abs(item.norm_e - msg.norm_e)
                + 0.2 * abs(item.left_near - msg.left_near)
                + 0.2 * abs(item.right_near - msg.right_near)
            )
            sims.append((dist, item))

        sims.sort(key=lambda x: x[0])
        topk = sims[:min(5, len(sims))]
        if len(topk) == 0:
            return msg.risk

        risks = [it.risk for _, it in topk]
        return float(np.mean(risks))

    def select_mode(self, msg: NarrowDecision, passability: float, risk: float) -> str:
        if msg.geom_margin < -0.08:
            return "REJECT"

        if risk > 0.75:
            return "RECOVER"

        if passability < 0.45 or not msg.has_valid_gap:
            return "EXPLORE"

        if abs(msg.norm_e) > 0.25:
            return "EXPLORE"

        return "COMMIT"

    def compute_nominal_action(self, msg: NarrowDecision, mode: str) -> Twist:
        cmd = Twist()

        safe_distance = float(self.get_parameter('safe_distance').value)
        k_v = float(self.get_parameter('k_v').value)
        v_max = float(self.get_parameter('v_max').value)
        k_omega_align = float(self.get_parameter('k_omega_align').value)
        omega_max = float(self.get_parameter('omega_max').value)

        explore_speed = float(self.get_parameter('explore_speed').value)
        reject_stop = bool(self.get_parameter('reject_stop').value)
        step_v_back = float(self.get_parameter('step_v_back').value)
        step_omega = float(self.get_parameter('step_omega').value)

        if mode == "REJECT":
            if reject_stop:
                cmd.linear.x = 0.0
                cmd.angular.z = 0.0
            return cmd

        if mode == "RECOVER":
            cmd.linear.x = -step_v_back
            cmd.angular.z = -step_omega if msg.norm_e > 0.0 else step_omega
            return cmd

        if mode == "EXPLORE":
            cmd.linear.x = explore_speed
            omega = float(np.clip(-k_omega_align * msg.norm_e, -omega_max, omega_max))
            cmd.angular.z = 0.5 * omega
            return cmd

        # COMMIT
        error_d = msg.d_center - safe_distance
        v = float(np.clip(k_v * error_d, 0.0, v_max))
        omega = float(np.clip(-k_omega_align * msg.norm_e, -omega_max, omega_max))

        if abs(msg.norm_e) > 0.25:
            v = min(v, 0.05)

        cmd.linear.x = v
        cmd.angular.z = omega
        return cmd

    def update_memory(self, msg: NarrowDecision, mode: str, passability: float, risk: float):
        success_like = float(passability * (1.0 - risk))
        item = MemoryItem(
            geom_margin=msg.geom_margin,
            norm_e=msg.norm_e,
            left_near=msg.left_near,
            right_near=msg.right_near,
            risk=risk,
            mode=mode,
            success_like=success_like,
        )
        self.memory.append(item)


def main(args=None):
    rclpy.init(args=args)
    node = ModeDecisionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
