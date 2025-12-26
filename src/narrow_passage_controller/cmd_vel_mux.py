#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy

from geometry_msgs.msg import Twist
from std_msgs.msg import Bool


def make_qos(depth=10, reliable=True):
    qos = QoSProfile(
        depth=depth,
        history=HistoryPolicy.KEEP_LAST,
        durability=DurabilityPolicy.VOLATILE
    )
    qos.reliability = ReliabilityPolicy.RELIABLE if reliable else ReliabilityPolicy.BEST_EFFORT
    return qos


class CmdVelMux(Node):
    """
    Simple velocity multiplexer:
    - Default: forward Nav2 cmd_vel
    - When narrow_active True OR narrow cmd fresh: forward narrow cmd_vel
    - Publish only ONE /cmd_vel to base (motion_sender)
    """

    def __init__(self):
        super().__init__('cmd_vel_mux')

        # ---- parameters ----
        self.declare_parameter('nav_topic', '/nav2_cmd_vel')
        self.declare_parameter('narrow_topic', '/narrow_cmd_vel')
        self.declare_parameter('active_topic', '/narrow_active')
        self.declare_parameter('out_topic', '/cmd_vel')

        self.declare_parameter('nav_timeout', 0.5)      # seconds
        self.declare_parameter('narrow_timeout', 0.25)  # seconds
        self.declare_parameter('publish_rate', 30.0)    # Hz

        self.nav_topic = self.get_parameter('nav_topic').value
        self.narrow_topic = self.get_parameter('narrow_topic').value
        self.active_topic = self.get_parameter('active_topic').value
        self.out_topic = self.get_parameter('out_topic').value

        self.nav_timeout = float(self.get_parameter('nav_timeout').value)
        self.narrow_timeout = float(self.get_parameter('narrow_timeout').value)
        self.publish_rate = float(self.get_parameter('publish_rate').value)

        # ---- state ----
        self.last_nav = Twist()
        self.last_narrow = Twist()
        self.nav_stamp = None
        self.narrow_stamp = None
        self.narrow_active = False

        # ---- QoS ----
        # Subscribe to Nav2 with RELIABLE (matches controller_server/recoveries_server)
        sub_qos_nav = make_qos(depth=10, reliable=True)
        # Subscribe to narrow with BEST_EFFORT ok, but RELIABLE also fine; choose RELIABLE for safety
        sub_qos_narrow = make_qos(depth=10, reliable=True)
        sub_qos_active = make_qos(depth=10, reliable=True)

        # Publish to base with BEST_EFFORT (matches motion_sender subscriber)
        pub_qos_out = make_qos(depth=10, reliable=False)

        self.sub_nav = self.create_subscription(
            Twist, self.nav_topic, self.on_nav, sub_qos_nav
        )
        self.sub_narrow = self.create_subscription(
            Twist, self.narrow_topic, self.on_narrow, sub_qos_narrow
        )
        self.sub_active = self.create_subscription(
            Bool, self.active_topic, self.on_active, sub_qos_active
        )

        self.pub_out = self.create_publisher(Twist, self.out_topic, pub_qos_out)

        period = 1.0 / max(1.0, self.publish_rate)
        self.timer = self.create_timer(period, self.on_timer)

        self.get_logger().info(
            f"[cmd_vel_mux] nav={self.nav_topic}, narrow={self.narrow_topic}, active={self.active_topic}, out={self.out_topic}"
        )

    def now_sec(self):
        return self.get_clock().now().nanoseconds * 1e-9

    def on_nav(self, msg: Twist):
        self.last_nav = msg
        self.nav_stamp = self.now_sec()

    def on_narrow(self, msg: Twist):
        self.last_narrow = msg
        self.narrow_stamp = self.now_sec()

    def on_active(self, msg: Bool):
        self.narrow_active = bool(msg.data)

    def is_fresh(self, stamp, timeout):
        if stamp is None:
            return False
        return (self.now_sec() - stamp) <= timeout

    def on_timer(self):
        nav_ok = self.is_fresh(self.nav_stamp, self.nav_timeout)
        narrow_ok = self.is_fresh(self.narrow_stamp, self.narrow_timeout)

        out = Twist()

        # Priority:
        # 1) narrow_active AND narrow cmd fresh -> use narrow
        # 2) narrow cmd fresh (even if active missing) -> use narrow (safety)
        # 3) nav cmd fresh -> use nav
        # 4) else -> stop
        if (self.narrow_active and narrow_ok) or narrow_ok:
            out = self.last_narrow
        elif nav_ok:
            out = self.last_nav
        else:
            # stop
            out.linear.x = 0.0
            out.angular.z = 0.0

        self.pub_out.publish(out)


def main(args=None):
    rclpy.init(args=args)
    node = CmdVelMux()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
