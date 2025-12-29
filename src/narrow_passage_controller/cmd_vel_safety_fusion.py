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
        self.can_pass = True

        self.prev_cmd = Twist()  # 用于滤波

        self.timer = self.create_timer(0.1, self.timer_callback)

        self.get_logger().info('CmdVelSafetyFusion (stable) started')

    def nav2_cmd_callback(self, msg):
        self.nav2_cmd = msg

    def safety_cmd_callback(self, msg):
        self.safety_cmd = msg

    def narrow_can_pass_callback(self, msg):
        self.can_pass = msg.data

    def clip_with_limit(self, value, limit):
        if limit <= 0.0:
            return 0.0
        return math.copysign(min(abs(value), abs(limit)), value)

    def timer_callback(self):
        raw_cmd = Twist()

        #  速度约束
        if self.can_pass:
            raw_cmd.linear.x = self.nav2_cmd.linear.x
            raw_cmd.angular.z = self.nav2_cmd.angular.z
        else:
            raw_cmd.linear.x = min(self.nav2_cmd.linear.x,
                                    max(0.0, self.safety_cmd.linear.x))
            raw_cmd.angular.z = self.clip_with_limit(
                self.nav2_cmd.angular.z,
                self.safety_cmd.angular.z
            )

        # 一阶低通滤波
        cmd = Twist()
        cmd.linear.x = (
            self.alpha * self.prev_cmd.linear.x +
            (1.0 - self.alpha) * raw_cmd.linear.x
        )
        cmd.angular.z = (
            self.alpha * self.prev_cmd.angular.z +
            (1.0 - self.alpha) * raw_cmd.angular.z
        )

        self.prev_cmd = cmd
        self.cmd_vel_pub.publish(cmd)

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
