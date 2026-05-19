#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
from narrow_passage_msgs.msg import NarrowDecision


class SafetyFusionNode(Node):
    def __init__(self):
        super().__init__('safety_fusion_node')

        self.declare_parameter('nav2_topic', '/nav2_cmd_vel')
        self.declare_parameter('nominal_topic', '/nominal_cmd_vel')
        self.declare_parameter('can_pass_topic', '/narrow_can_pass')
        self.declare_parameter('decision_topic', '/narrow_decision')
        self.declare_parameter('output_topic', '/cmd_vel')

        self.declare_parameter('conf_up_rate', 0.08)      # 上升更慢一点
        self.declare_parameter('conf_down_rate', 0.35)    # 下降更快一点
        self.declare_parameter('cmd_timeout', 0.3)

        # can_pass=False 时，对连续置信度再加一个硬限制
        self.declare_parameter('false_conf_cap', 0.15)

        # 风险加权参数
        self.declare_parameter('risk_weight', 0.5)
        self.declare_parameter('side_bias_weight', 0.2)
        self.declare_parameter('align_weight', 0.2)
        self.declare_parameter('max_out_vx', 0.35)
        self.declare_parameter('max_out_wz', 0.6)
        self.declare_parameter('allow_nominal_when_nav_stopped', True)

        self.conf_up_rate = float(self.get_parameter('conf_up_rate').value)
        self.conf_down_rate = float(self.get_parameter('conf_down_rate').value)
        self.cmd_timeout = float(self.get_parameter('cmd_timeout').value)

        self.false_conf_cap = float(self.get_parameter('false_conf_cap').value)
        self.risk_weight = float(self.get_parameter('risk_weight').value)
        self.side_bias_weight = float(self.get_parameter('side_bias_weight').value)
        self.align_weight = float(self.get_parameter('align_weight').value)
        self.max_out_vx = float(self.get_parameter('max_out_vx').value)
        self.max_out_wz = float(self.get_parameter('max_out_wz').value)
        self.allow_nominal_when_nav_stopped = bool(
            self.get_parameter('allow_nominal_when_nav_stopped').value
        )

        nav2_topic = self.get_parameter('nav2_topic').value
        nominal_topic = self.get_parameter('nominal_topic').value
        can_pass_topic = self.get_parameter('can_pass_topic').value
        decision_topic = self.get_parameter('decision_topic').value
        output_topic = self.get_parameter('output_topic').value

        self.sub_nav2 = self.create_subscription(
            Twist, nav2_topic, self.nav2_callback, 10
        )
        self.sub_nominal = self.create_subscription(
            Twist, nominal_topic, self.nominal_callback, 10
        )
        self.sub_can_pass = self.create_subscription(
            Bool, can_pass_topic, self.can_pass_callback, 10
        )
        self.sub_decision = self.create_subscription(
            NarrowDecision, decision_topic, self.decision_callback, 10
        )

        self.pub_cmd = self.create_publisher(Twist, output_topic, 10)

        self.nav2_cmd = Twist()
        self.nominal_cmd = Twist()

        self.pass_conf = 1.0
        self.can_pass_bool = True

        self.last_nav2_time = self.get_clock().now()
        self.last_nominal_time = self.get_clock().now()
        self.last_decision_time = self.get_clock().now()

        self.timer = self.create_timer(0.02, self.fusion_step)

        self.get_logger().info(f"[SafetyFusionNode] output={output_topic}")

    def nav2_callback(self, msg: Twist):
        self.nav2_cmd = msg
        self.last_nav2_time = self.get_clock().now()

    def nominal_callback(self, msg: Twist):
        self.nominal_cmd = msg
        self.last_nominal_time = self.get_clock().now()

    def can_pass_callback(self, msg: Bool):
        # 只保留为硬门控，不直接更新 pass_conf
        self.can_pass_bool = bool(msg.data)

    def decision_callback(self, msg: NarrowDecision):
        self.last_decision_time = self.get_clock().now()

        # 1) 以 passability 为基线
        target = float(msg.passability)

        # 2) 风险越高，置信度越低
        target -= self.risk_weight * float(msg.risk)

        # 3) 左右不平衡越大，置信度越低
        left_right_diff = abs(float(msg.left_near) - float(msg.right_near))
        side_penalty = min(1.0, left_right_diff / 0.10)
        target -= self.side_bias_weight * side_penalty

        # 4) 对齐误差越大，置信度越低
        align_penalty = min(1.0, abs(float(msg.norm_e)) / 0.25)
        target -= self.align_weight * align_penalty

        target = max(0.0, min(1.0, target))

        rate = self.conf_up_rate if target > self.pass_conf else self.conf_down_rate
        self.pass_conf += rate * (target - self.pass_conf)
        self.pass_conf = max(0.0, min(1.0, self.pass_conf))

    def is_fresh(self, t) -> bool:
        dt = (self.get_clock().now() - t).nanoseconds * 1e-9
        return dt < self.cmd_timeout

    def fusion_step(self):
        out = Twist()

        nav_fresh = self.is_fresh(self.last_nav2_time)
        nominal_fresh = self.is_fresh(self.last_nominal_time)
        decision_fresh = self.is_fresh(self.last_decision_time)

        nav = self.nav2_cmd if nav_fresh else Twist()
        nominal = self.nominal_cmd if nominal_fresh else Twist()

        conf = self.pass_conf

        # 如果 can_pass=False，则进一步压低置信度
        if not self.can_pass_bool:
            conf = min(conf, self.false_conf_cap)

        # 如果 decision 太久没更新，保守一点
        if not decision_fresh:
            conf = min(conf, 0.2)

        nav_v = nav.linear.x
        nom_v = nominal.linear.x

        # -------- Linear fusion --------
        if abs(nav_v) < 1e-3:
            out.linear.x = nom_v if self.allow_nominal_when_nav_stopped else 0.0  # 调试初期设为 True，在 Nav2 犹豫时让窄通道模块接管。正式做安全对比时，设为 False。
        else:
            if nav_v > 0.0:
                if nom_v < 0.0:
                    # nominal 想后退，优先 nominal
                    out.linear.x = nom_v
                else:
                    safety_scale = min(1.0, max(0.0, nom_v / max(nav_v, 1e-3)))
                    scale = conf + (1.0 - conf) * safety_scale
                    out.linear.x = nav_v * scale
            else:
                out.linear.x = nav_v

        # -------- Angular fusion --------
        out.angular.z = self.fuse_angular(nav.angular.z, nominal.angular.z, conf)
        out.linear.x = max(-self.max_out_vx, min(self.max_out_vx, out.linear.x))
        out.angular.z = max(-self.max_out_wz, min(self.max_out_wz, out.angular.z))

        self.pub_cmd.publish(out)

    @staticmethod
    def fuse_angular(nav_w: float, nominal_w: float, conf: float) -> float:
        # 如果两个方向相反，优先 nominal（更安全）
        if nav_w * nominal_w < 0.0:
            return nominal_w

        if abs(nominal_w) < 1e-3:
            conservative = nav_w
        else:
            conservative = (1.0 if nominal_w >= 0.0 else -1.0) * min(abs(nav_w), abs(nominal_w))

        return conf * nav_w + (1.0 - conf) * conservative


def main(args=None):
    rclpy.init(args=args)
    node = SafetyFusionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
