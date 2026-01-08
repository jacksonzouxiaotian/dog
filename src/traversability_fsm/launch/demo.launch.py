from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='traversability_fsm',
            executable='failure_monitor',
            output='screen'
        ),
        Node(
            package='traversability_fsm',
            executable='traversability_fsm',
            output='screen'
        ),
        Node(
            package='traversability_fsm',
            executable='motion_gate',
            output='screen'
        ),
    ])

