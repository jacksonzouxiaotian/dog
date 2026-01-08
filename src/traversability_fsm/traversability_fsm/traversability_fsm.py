import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool, String


class TraversabilityFSM(Node):

    def __init__(self):
        super().__init__('traversability_fsm')

        self.failure_count = 0
        self.failure_threshold = 5
        self.state = 'TRYING'

        self.create_subscription(
            Bool,
            '/failure/stuck',
            self.failure_cb,
            10)

        self.pub_state = self.create_publisher(String, '/traversability/state', 10)

        self.timer = self.create_timer(0.5, self.publish_state)

    def failure_cb(self, msg):
        if self.state != 'TRYING':
            return

        if msg.data:
            self.failure_count += 1
            self.get_logger().warn(
                f'Failure detected: {self.failure_count}/{self.failure_threshold}'
            )

        if self.failure_count >= self.failure_threshold:
            self.state = 'UNPASSABLE'
            self.get_logger().error('Channel judged UNPASSABLE')

    def publish_state(self):
        msg = String()
        msg.data = self.state
        self.pub_state.publish(msg)


def main():
    rclpy.init()
    node = TraversabilityFSM()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

