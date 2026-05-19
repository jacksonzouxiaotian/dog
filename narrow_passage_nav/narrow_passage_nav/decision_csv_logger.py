#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import csv
import os
from datetime import datetime

import rclpy
from rclpy.node import Node

from narrow_passage_msgs.msg import NarrowDecision


class DecisionCsvLogger(Node):
    def __init__(self):
        super().__init__('decision_csv_logger')

        self.declare_parameter('decision_topic', '/narrow_decision')
        self.declare_parameter('output_dir', os.path.expanduser('~/narrow_logs'))
        self.declare_parameter('scene_name', 'default_scene')
        self.declare_parameter('trial_id', 'trial_001')
        self.declare_parameter('robot_id', 'robot_1')
        self.declare_parameter('param_version', 'v1')
        self.declare_parameter('note', '')

        topic = self.get_parameter('decision_topic').value
        output_dir = self.get_parameter('output_dir').value
        self.scene_name = self.get_parameter('scene_name').value
        self.trial_id = self.get_parameter('trial_id').value
        self.robot_id = self.get_parameter('robot_id').value
        self.param_version = self.get_parameter('param_version').value
        self.note = self.get_parameter('note').value

        os.makedirs(output_dir, exist_ok=True)
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        self.csv_path = os.path.join(
            output_dir,
            f"decision_log_{self.scene_name}_{self.trial_id}_{timestamp}.csv"
        )

        self.fieldnames = [
            'stamp_sec', 'stamp_nanosec', 'frame_id',
            'scene_name', 'trial_id', 'robot_id', 'param_version', 'note',
            'can_pass', 'passability', 'risk',
            'd_min', 'd_center', 'gap_x', 'cx', 'norm_e', 'has_valid_gap',
            'left_near', 'center_near', 'right_near',
            'left_far', 'center_far', 'right_far',
            'd_hat', 'd_min_required', 'geom_margin', 'obs_confidence',
            'mode_hint', 'recovery_hint'
        ]

        self.csv_file = open(self.csv_path, 'w', newline='', encoding='utf-8')
        self.writer = csv.DictWriter(self.csv_file, fieldnames=self.fieldnames)
        self.writer.writeheader()
        self.csv_file.flush()

        self.sub = self.create_subscription(
            NarrowDecision,
            topic,
            self.decision_callback,
            10
        )

        self.get_logger().info(f'Logging to: {self.csv_path}')

    def decision_callback(self, msg: NarrowDecision):
        row = {
            'stamp_sec': msg.header.stamp.sec,
            'stamp_nanosec': msg.header.stamp.nanosec,
            'frame_id': msg.header.frame_id,

            'scene_name': self.scene_name,
            'trial_id': self.trial_id,
            'robot_id': self.robot_id,
            'param_version': self.param_version,
            'note': self.note,

            'can_pass': msg.can_pass,
            'passability': msg.passability,
            'risk': msg.risk,

            'd_min': msg.d_min,
            'd_center': msg.d_center,
            'gap_x': msg.gap_x,
            'cx': msg.cx,
            'norm_e': msg.norm_e,
            'has_valid_gap': msg.has_valid_gap,

            'left_near': msg.left_near,
            'center_near': msg.center_near,
            'right_near': msg.right_near,

            'left_far': msg.left_far,
            'center_far': msg.center_far,
            'right_far': msg.right_far,

            'd_hat': msg.d_hat,
            'd_min_required': msg.d_min_required,
            'geom_margin': msg.geom_margin,
            'obs_confidence': msg.obs_confidence,

            'mode_hint': msg.mode_hint,
            'recovery_hint': msg.recovery_hint,
        }

        self.writer.writerow(row)
        self.csv_file.flush()

    def destroy_node(self):
        try:
            if hasattr(self, 'csv_file') and self.csv_file:
                self.csv_file.close()
        finally:
            super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = DecisionCsvLogger()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
