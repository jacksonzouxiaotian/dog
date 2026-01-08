import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import String


class MotionGate(Node):

    def __init__(self):
        super().__init__('motion_gate')

        self.allow = True

        self.create_subscription(
            Twist,
            '/cmd_vel_raw',
            self.cmd_cb,
            10)

        self.create_subscription(
            String,
            '/traversability/state',
            self.state_cb,
            10)

        self.pub = self.create_publisher(Twist, '/cmd_vel', 10)

    def state_cb(self, msg):
        if msg.data == 'UNPASSABLE':
            self.allow = False

    def cmd_cb(self, msg):
        out = Twist()

        if self.allow:
            out = msg
        else:
            # 主动退出：后退
            out.linear.x = -0.1
            out.angular.z = 0.0

        self.pub.publish(out)


def main():
    rclpy.init()
    node = MotionGate()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

