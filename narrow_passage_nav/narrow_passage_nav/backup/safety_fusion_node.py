#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool


class SafetyFusionNode(Node):
    def __init__(self):
        super().__init__('safety_fusion_node')

        self.declare_parameter('nav2_topic', '/nav2_cmd_vel')
        self.declare_parameter('nominal_topic', '/nominal_cmd_vel')
        self.declare_parameter('can_pass_topic', '/narrow_can_pass')
        self.declare_parameter('output_topic', '/cmd_vel')

        self.declare_parameter('conf_up_rate', 0.15)
        self.declare_parameter('conf_down_rate', 0.40)
        self.declare_parameter('cmd_timeout', 0.3)

        self.conf_up_rate = float(self.get_parameter('conf_up_rate').value)
        self.conf_down_rate = float(self.get_parameter('conf_down_rate').value)
        self.cmd_timeout = float(self.get_parameter('cmd_timeout').value)

        nav2_topic = self.get_parameter('nav2_topic').value
        nominal_topic = self.get_parameter('nominal_topic').value
        can_pass_topic = self.get_parameter('can_pass_topic').value
        output_topic = self.get_parameter('output_topic').value

        self.sub_nav2 = self.create_subscription(Twist, nav2_topic, self.nav2_callback, 10)
        self.sub_nominal = self.create_subscription(Twist, nominal_topic, self.nominal_callback, 10)
        self.sub_can_pass = self.create_subscription(Bool, can_pass_topic, self.can_pass_callback, 10)

        self.pub_cmd = self.create_publisher(Twist, output_topic, 10)

        self.nav2_cmd = Twist()
        self.nominal_cmd = Twist()
        self.pass_conf = 1.0

        self.last_nav2_time = self.get_clock().now()
        self.last_nominal_time = self.get_clock().now()

        self.timer = self.create_timer(0.02, self.fusion_step)

        self.get_logger().info(f"[SafetyFusionNode] output={output_topic}")

    def nav2_callback(self, msg: Twist):
        self.nav2_cmd = msg
        self.last_nav2_time = self.get_clock().now()

    def nominal_callback(self, msg: Twist):
        self.nominal_cmd = msg
        self.last_nominal_time = self.get_clock().now()

    def can_pass_callback(self, msg: Bool):
        target = 1.0 if msg.data else 0.0
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

        nav = self.nav2_cmd if nav_fresh else Twist()
        nominal = self.nominal_cmd if nominal_fresh else Twist()

        conf = self.pass_conf

        nav_v = nav.linear.x
        nom_v = nominal.linear.x

        if abs(nav_v) < 1e-3:
            out.linear.x = nom_v
        else:
            if nav_v > 0.0:
                if nom_v < 0.0:
                    out.linear.x = nom_v
                else:
                    safety_scale = min(1.0, max(0.0, nom_v / max(nav_v, 1e-3)))
                    scale = conf + (1.0 - conf) * safety_scale
                    out.linear.x = nav_v * scale
            else:
                out.linear.x = nav_v

        out.angular.z = self.fuse_angular(nav.angular.z, nominal.angular.z, conf)

        self.pub_cmd.publish(out)

    @staticmethod
    def fuse_angular(nav_w: float, nominal_w: float, conf: float) -> float:
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
