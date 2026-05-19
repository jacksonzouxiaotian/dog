import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
import math

class CmdVelSafetyFusion(Node):
    def __init__(self):
        super().__init__('cmd_vel_safety_fusion')

        # 设置参数
        self.declare_parameter('safety_distance_threshold', 0.5)
        self.safety_distance_threshold = self.get_parameter('safety_distance_threshold').get_parameter_value().double_value

        # 订阅
        self.nav2_cmd_sub = self.create_subscription(
            Twist,
            '/nav2_cmd_vel',
            self.nav2_cmd_callback,
            10
        )
        self.safety_cmd_sub = self.create_subscription(
            Twist,
            '/safety_cmd_vel',
            self.safety_cmd_callback,
            10
        )
        self.narrow_can_pass_sub = self.create_subscription(
            Bool,
            '/narrow_can_pass',
            self.narrow_can_pass_callback,
            10
        )

        # 发布
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # 初始化状态
        self.safety_cmd = Twist()
        self.nav2_cmd = Twist()
        self.can_pass = True

        self.get_logger().info('CmdVelSafetyFusion started!')

    def nav2_cmd_callback(self, msg):
        """接收来自Nav2的cmd_vel命令"""
        self.nav2_cmd = msg

    def safety_cmd_callback(self, msg):
        """接收来自安全层的cmd_vel命令"""
        self.safety_cmd = msg

    def narrow_can_pass_callback(self, msg):
        """接收是否能通过的信号"""
        self.can_pass = msg.data

    def update_cmd_vel(self):
        """基于安全状态和Nav2命令调整最终的cmd_vel"""
        cmd = Twist()
        if self.can_pass:
            # 没有碰到障碍时，正常放行Nav2命令
            cmd.linear.x = self.nav2_cmd.linear.x
            cmd.angular.z = self.nav2_cmd.angular.z
        else:
            # 当不能通过时，根据安全命令来限制Nav2命令
            cmd.linear.x = min(self.nav2_cmd.linear.x, self.safety_cmd.linear.x)
            cmd.angular.z = min(self.nav2_cmd.angular.z, self.safety_cmd.angular.z)

        self.cmd_vel_pub.publish(cmd)

    def timer_callback(self):
        """周期性更新cmd_vel"""
        self.update_cmd_vel()

def main(args=None):
    rclpy.init(args=args)

    cmd_vel_fusion = CmdVelSafetyFusion()

    # 设置一个定时器
    timer = cmd_vel_fusion.create_timer(0.1, cmd_vel_fusion.timer_callback)  # 每100ms检查一次

    rclpy.spin(cmd_vel_fusion)

    cmd_vel_fusion.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
