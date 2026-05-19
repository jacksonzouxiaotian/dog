from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='narrow_passage_nav',
            executable='depth_perception_node',
            name='depth_perception_node',
            output='screen',
            parameters=['config/params.yaml'],
        ),
        Node(
            package='narrow_passage_nav',
            executable='mode_decision_node',
            name='mode_decision_node',
            output='screen',
            parameters=['config/params.yaml'],
        ),
        Node(
            package='narrow_passage_nav',
            executable='safety_fusion_node',
            name='safety_fusion_node',
            output='screen',
            parameters=['config/params.yaml'],
        ),
    ])
