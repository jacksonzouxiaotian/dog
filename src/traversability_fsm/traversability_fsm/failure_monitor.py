import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
import time


class FailureMonitor(Node):

    def __init__(self):
        super().__init__('failure_monitor')

        self.prev_x = None
        self.prev_time = None
        self.last_cmd_time = time.time()

        self.create_subscription(Odometry, '/odom', self.odom_cb, 10)
        self.create_subscription(Twist, '/cmd_vel_raw', self.cmd_cb, 10)

        self.pub_stuck = self.create_publisher(Bool, '/failure/stuck', 10)

    def cmd_cb(self, msg):
        self.last_cmd_time = time.time()

    def odom_cb(self, msg):
        x = msg.pose.pose.position.x
        t = time.time()

        if self.prev_x is not None:
            dx = x - self.prev_x
            dt = t - self.prev_time

            stuck = abs(dx) < 0.01 and dt > 1.0 and (t - self.last_cmd_time) < 0.5

            msg_out = Bool()
            msg_out.data = stuck
            self.pub_stuck.publish(msg_out)

        self.prev_x = x
        self.prev_time = t


def main():
    rclpy.init()
    node = FailureMonitor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

