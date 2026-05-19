import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
import math

class CmdVelSafetyFusion(Node):
    def __init__(self):
        super().__init__('cmd_vel_safety_fusion')

        # 参数
        self.declare_parameter('alpha', 0.8)  # 低通滤波系数
        self.alpha = self.get_parameter('alpha').value

        # 订阅
        self.nav2_cmd_sub = self.create_subscription(
            Twist, '/nav2_cmd_vel', self.nav2_cmd_callback, 10
        )
        self.safety_cmd_sub = self.create_subscription(
            Twist, '/safety_cmd_vel', self.safety_cmd_callback, 10
        )
        self.narrow_can_pass_sub = self.create_subscription(
            Bool, '/narrow_can_pass', self.narrow_can_pass_callback, 10
        )

        # 发布
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # 状态
        self.nav2_cmd = Twist()
        self.safety_cmd = Twist()
        self.pass_conf = 1.0

        # ===== Tunable Parameters =====
        self.conf_up_rate = 0.15     # True → 上升慢
        self.conf_down_rate = 0.40   # False → 下降快

        self.timer = self.create_timer(0.02, self.fusion_step)  # 50 Hz

        self.get_logger().info("CmdVelSafetyFusion (stable version) started")

    def nav2_cmd_callback(self, msg):
        self.nav2_cmd = msg

    def safety_cmd_callback(self, msg):
        self.safety_cmd = msg

    def can_pass_callback(self, msg: Bool):
        """
        bool → 连续置信度（EMA + 非对称更新）
        """
        target = 1.0 if msg.data else 0.0

        if target > self.pass_conf:
            rate = self.conf_up_rate
        else:
            rate = self.conf_down_rate

        self.pass_conf += rate * (target - self.pass_conf)
        self.pass_conf = max(0.0, min(1.0, self.pass_conf))

    # Fusion
    def fusion_step(self):
        raw_cmd = Twist()

        nav_v = self.nav2_cmd.linear.x
        safe_v = self.safety_cmd.linear.x

        conf = self.pass_conf

        # --- Linear velocity fusion ---
        if abs(nav_v) < 1e-3:
            raw_cmd.linear.x = safe_v
        else:
            safety_scale = min(1.0, safe_v / max(abs(nav_v), 1e-3))
            scale = conf + (1.0 - conf) * safety_scale
            raw_cmd.linear.x = nav_v * scale

        # --- Angular velocity fusion ---
        raw_cmd.angular.z = self.clip_with_safety(
            self.nav2_cmd.angular.z,
            self.safety_cmd.angular.z
        )

        self.cmd_pub.publish(raw_cmd)

        # --- Debug (optional) ---
        self.get_logger().debug(
            f"[Fusion] conf={conf:.2f}, "
            f"nav_v={nav_v:.2f}, safe_v={safe_v:.2f}, "
            f"out_v={raw_cmd.linear.x:.2f}"
        )


    @staticmethod
    def clip_with_safety(nav, safe):
        """
        Safety 限制 angular.z
        """
        if abs(safe) < abs(nav):
            return safe
        return nav


def main(args=None):
    rclpy.init(args=args)
    node = CmdVelSafetyFusion()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
