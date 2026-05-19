import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool

class CmdVelSafetyArbiter(Node):
    def __init__(self):
        super().__init__('cmd_vel_safety_arbiter')

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

        self.get_logger().info('CmdVelSafetyArbiter started!')

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
        """根据安全条件和Nav2命令决定最终发布的cmd_vel"""
        if self.can_pass:
            self.cmd_vel_pub.publish(self.nav2_cmd)  # 正常发布Nav2的命令
        else:
            self.cmd_vel_pub.publish(self.safety_cmd)  # 如果不能通过，发布安全命令

    def timer_callback(self):
        """周期性更新cmd_vel"""
        self.update_cmd_vel()

def main(args=None):
    rclpy.init(args=args)

    cmd_vel_arbiter = CmdVelSafetyArbiter()

    # 设置一个定时器
    timer = cmd_vel_arbiter.create_timer(0.1, cmd_vel_arbiter.timer_callback)  # 每100ms检查一次

    rclpy.spin(cmd_vel_arbiter)

    cmd_vel_arbiter.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
