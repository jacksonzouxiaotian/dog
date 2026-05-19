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

        # ---------- 高层 mode 参数 ----------
        self.declare_parameter('reject_margin_th', -0.20)
        self.declare_parameter('recover_risk_th', 0.75)
        self.declare_parameter('explore_passability_th', 0.45)
        self.declare_parameter('align_explore_th', 0.25)

        # ---------- 原先低层控制逻辑参数 ----------
        self.declare_parameter('safe_distance', 0.7)
        self.declare_parameter('k_v', 0.5)
        self.declare_parameter('v_max', 0.3)

        self.declare_parameter('k_omega_align', 2.0)
        self.declare_parameter('omega_max', 0.8)
        self.declare_parameter('k_side_bias', 0.8)

        self.declare_parameter('e_deadband', 0.05)
        self.declare_parameter('e_lpf_alpha', 0.30)

        self.declare_parameter('explore_speed', 0.05)
        self.declare_parameter('reject_stop', True)

        self.declare_parameter('near_drop_th', 0.08)
        self.declare_parameter('near_low_th', 0.35)
        self.declare_parameter('near_safe_th', 0.40)

        self.declare_parameter('step_v_back', 0.05)
        self.declare_parameter('step_omega', 0.6)
        self.declare_parameter('step_ticks', 6)

        # ---------- 状态 ----------
        self.memory = deque(maxlen=int(self.get_parameter('memory_size').value))
        self.current_mode = "EXPLORE"

        self.prev_left_near = None
        self.prev_center_near = None
        self.prev_right_near = None

        self.step_mode = None
        self.step_count = 0

        self.e_filt = 0.0

        decision_topic = self.get_parameter('decision_topic').value
        nominal_cmd_topic = self.get_parameter('nominal_cmd_topic').value

        self.sub_decision = self.create_subscription(
            NarrowDecision, decision_topic, self.decision_callback, 10
        )
        self.pub_nominal_cmd = self.create_publisher(Twist, nominal_cmd_topic, 10)

        self.get_logger().info(
            f"[ModeDecisionNode] sub={decision_topic}, pub={nominal_cmd_topic}"
        )

    def decision_callback(self, msg: NarrowDecision):
        memory_risk = self.retrieve_memory_risk(msg)
        fused_risk = float(np.clip(0.7 * msg.risk + 0.3 * memory_risk, 0.0, 1.0))
        fused_passability = float(
            np.clip(0.7 * msg.passability + 0.3 * (1.0 - memory_risk), 0.0, 1.0)
        )

        mode = self.select_mode(msg, fused_passability, fused_risk)
        self.current_mode = mode

        cmd = self.compute_nominal_action(msg, mode)
        self.pub_nominal_cmd.publish(cmd)

        self.update_memory(msg, mode, fused_passability, fused_risk)
       

    # =========================
    # Memory
    # =========================
    def retrieve_memory_risk(self, msg: NarrowDecision) -> float:
        if len(self.memory) == 0:
            return float(msg.risk)

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
            return float(msg.risk)

        risks = [it.risk for _, it in topk]
        return float(np.mean(risks))

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

    # =========================
    # High-level mode selection
    # =========================
    def select_mode(self, msg: NarrowDecision, passability: float, risk: float) -> str:
        reject_margin_th = float(self.get_parameter('reject_margin_th').value)
        recover_risk_th = float(self.get_parameter('recover_risk_th').value)
        explore_passability_th = float(self.get_parameter('explore_passability_th').value)
        align_explore_th = float(self.get_parameter('align_explore_th').value)

        if msg.geom_margin < reject_margin_th:
            return "REJECT"

        if risk > recover_risk_th:
            return "RECOVER"

        if (not msg.has_valid_gap) or (passability < explore_passability_th):
            return "EXPLORE"

        if abs(msg.norm_e) > align_explore_th:
            return "EXPLORE"

        if not msg.can_pass:
            return "EXPLORE"

        return "COMMIT"

    # =========================
    # Low-level controller
    # Borrowed from your old logic
    # =========================
    def compute_nominal_action(self, msg: NarrowDecision, mode: str) -> Twist:
        # 1) 先尝试原先的“小步恢复状态机”
        recovery_cmd = self.try_recovery_from_near_trend(msg)
        if recovery_cmd is not None:
            return recovery_cmd

        # 2) 再根据 high-level mode 走 nominal action
        if mode == "REJECT":
            return self.zero_cmd()

        if mode == "RECOVER":
            return self.force_backoff_cmd(msg)

        omega = self.compute_alignment_omega(msg)
        v_commit = self.compute_forward_speed(msg)

        cmd = Twist()

        if mode == "EXPLORE":
            explore_speed = float(self.get_parameter('explore_speed').value)
            cmd.linear.x = min(explore_speed, max(0.0, v_commit))
            cmd.angular.z = omega
            return cmd

        # COMMIT
        cmd.linear.x = v_commit
        cmd.angular.z = omega
        return cmd

    def try_recovery_from_near_trend(self, msg: NarrowDecision):
        near_drop_th = float(self.get_parameter('near_drop_th').value)
        near_low_th = float(self.get_parameter('near_low_th').value)
        near_safe_th = float(self.get_parameter('near_safe_th').value)

        step_v_back = float(self.get_parameter('step_v_back').value)
        step_omega = float(self.get_parameter('step_omega').value)
        step_ticks = int(self.get_parameter('step_ticks').value)

        L = float(msg.left_near)
        C = float(msg.center_near)
        R = float(msg.right_near)

        def compute_drop(prev, cur):
            if prev is None or (not np.isfinite(cur)) or (not np.isfinite(prev)):
                return 0.0
            return float(prev - cur)

        dL = compute_drop(self.prev_left_near, L)
        dC = compute_drop(self.prev_center_near, C)
        dR = compute_drop(self.prev_right_near, R)

        self.prev_left_near = L if np.isfinite(L) else self.prev_left_near
        self.prev_center_near = C if np.isfinite(C) else self.prev_center_near
        self.prev_right_near = R if np.isfinite(R) else self.prev_right_near

        left_too_close_trend = (dL > near_drop_th) and (L < near_low_th) and (R > near_safe_th)
        right_too_close_trend = (dR > near_drop_th) and (R < near_low_th) and (L > near_safe_th)
        all_too_close_trend = (
            (dL > near_drop_th) and
            (dC > near_drop_th) and
            (dR > near_drop_th) and
            (L < near_safe_th) and
            (C < near_safe_th) and
            (R < near_safe_th)
        )

        if self.step_mode is None:
            if all_too_close_trend:
                self.step_mode = 'BACK'
                self.step_count = step_ticks
            elif left_too_close_trend:
                self.step_mode = 'BACK_RIGHT'
                self.step_count = step_ticks
            elif right_too_close_trend:
                self.step_mode = 'BACK_LEFT'
                self.step_count = step_ticks

        if self.step_mode is not None and self.step_count > 0:
            cmd = Twist()
            if self.step_mode == 'BACK_RIGHT':
                cmd.linear.x = -step_v_back
                cmd.angular.z = +step_omega
            elif self.step_mode == 'BACK_LEFT':
                cmd.linear.x = -step_v_back
                cmd.angular.z = -step_omega
            else:  # BACK
                cmd.linear.x = -step_v_back
                cmd.angular.z = 0.0

            self.step_count -= 1
            if self.step_count <= 0:
                self.step_mode = None

            return cmd

        return None

    def compute_forward_speed(self, msg: NarrowDecision) -> float:
        safe_distance = float(self.get_parameter('safe_distance').value)
        k_v = float(self.get_parameter('k_v').value)
        v_max = float(self.get_parameter('v_max').value)

        error_d = float(msg.d_center) - safe_distance
        v = k_v * error_d
        v = float(np.clip(v, 0.0, v_max))

        # 原始逻辑：误差很大时主动降速
        if abs(float(msg.norm_e)) > 0.25:
            v = min(v, 0.05)

        return v

        
    def compute_alignment_omega(self, msg: NarrowDecision) -> float:
        k_omega_align = float(self.get_parameter('k_omega_align').value)
        omega_max = float(self.get_parameter('omega_max').value)
        alpha = float(self.get_parameter('e_lpf_alpha').value)
        deadband = float(self.get_parameter('e_deadband').value)
        k_side_bias = float(self.get_parameter('k_side_bias').value)
        eps = 1e-6

        if bool(msg.has_valid_gap):
            # 右侧更远 => side_bias > 0；左侧更远 => side_bias < 0
            side_bias = float(msg.right_near - msg.left_near) / max(
                float(msg.right_near + msg.left_near), eps
            )

            # gap中心偏差 + 左右空间不平衡偏差
            e_total = float(msg.norm_e) + k_side_bias * side_bias

            self.e_filt = (1.0 - alpha) * self.e_filt + alpha * e_total
            e = self.e_filt

            if abs(e) < deadband:
                e = 0.0

            omega = -k_omega_align * e
            omega = float(np.clip(omega, -omega_max, omega_max))
        else:
            omega = 0.0
            self.e_filt *= 0.9

        return omega        
    

    def force_backoff_cmd(self, msg: NarrowDecision) -> Twist:
        step_v_back = float(self.get_parameter('step_v_back').value)
        step_omega = float(self.get_parameter('step_omega').value)

        cmd = Twist()
        cmd.linear.x = -step_v_back

        # 根据 gap 在左右的位置选一个恢复方向
        if float(msg.norm_e) > 0.0:
            cmd.angular.z = -step_omega
        else:
            cmd.angular.z = +step_omega
        return cmd

    @staticmethod
    def zero_cmd() -> Twist:
        return Twist()


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
