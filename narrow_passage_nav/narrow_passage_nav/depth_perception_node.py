#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math
import numpy as np
from dataclasses import dataclass

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data

from sensor_msgs.msg import Image
from std_msgs.msg import Bool
from cv_bridge import CvBridge

from narrow_passage_msgs.msg import NarrowDecision

@dataclass
class DepthDecision:
    can_pass: bool
    d_min: float
    d_center: float
    gap_x: float
    cx: float
    norm_e: float
    has_valid_gap: bool

    left_near: float = 0.0
    center_near: float = 0.0
    right_near: float = 0.0

    left_far: float = 0.0
    center_far: float = 0.0
    right_far: float = 0.0

    d_hat: float = 0.0
    d_min_required: float = 0.0
    geom_margin: float = 0.0
    obs_confidence: float = 0.0

    mode_hint: str = "EXPLORE"
    recovery_hint: str = "NONE"


class DepthPerceptionNode(Node):
    def __init__(self):
        super().__init__('depth_perception_node')

        # Topics
        self.declare_parameter('depth_topic', '/camera/depth/image_rect_raw')
        self.declare_parameter('publish_can_pass_topic', '/narrow_can_pass')
        self.declare_parameter('publish_decision_topic', '/narrow_decision')

        # Depth & ROI
        self.declare_parameter('max_depth', 5.0)
        self.declare_parameter('roi_y_start_ratio', 0.6)
        self.declare_parameter('roi_height_ratio', 0.4)
        self.declare_parameter('num_bins', 40)
        self.declare_parameter('bin_valid_ratio_th', 0.02)
        self.declare_parameter('unknown_free_depth', 2.0)

        # Narrow passage thresholds
        self.declare_parameter('min_obs_near', 0.35)
        self.declare_parameter('corridor_near', 1.2)
        self.declare_parameter('corridor_margin', 0.10)

        # Geometry prior params (paper-aligned placeholders)
        self.declare_parameter('robot_body_width', 0.42)
        self.declare_parameter('robot_body_length', 0.65)
        self.declare_parameter('robot_body_height', 0.22)
        self.declare_parameter('leg_swing_margin', 0.06)
        self.declare_parameter('sensor_swing_margin', 0.03)
        self.declare_parameter('max_roll_deg', 8.0)
        self.declare_parameter('uncertainty_margin', 0.03)
        self.declare_parameter('yaw_assumption_deg', 0.0)

        self.bridge = CvBridge()
        self.last_encoding_warned = False

        depth_topic = self.get_parameter('depth_topic').value
        pub_decision_topic = self.get_parameter('publish_decision_topic').value
        pub_can_pass_topic = self.get_parameter('publish_can_pass_topic').value

        self.sub_depth = self.create_subscription(
            Image, depth_topic, self.depth_callback, qos_profile_sensor_data
        )
        self.pub_decision = self.create_publisher(NarrowDecision, pub_decision_topic, 10)
        self.pub_can_pass = self.create_publisher(Bool, pub_can_pass_topic, 10)

        self.get_logger().info(f"[DepthPerceptionNode] depth_topic={depth_topic}")

    def depth_callback(self, msg: Image):
        try:
            if msg.encoding == '32FC1':
                depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='32FC1')
                depth = depth_image.astype(np.float32)
            elif msg.encoding == '16UC1':
                depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='16UC1')
                depth = depth_image.astype(np.float32) / 1000.0
            else:
                if not self.last_encoding_warned:
                    self.get_logger().warn(f"Unsupported depth encoding: {msg.encoding}")
                    self.last_encoding_warned = True
                return
        except Exception as e:
            self.get_logger().warn(f"Failed to convert depth image: {e}")
            return

        decision = self.analyze_depth(depth)

        out = NarrowDecision()
        out.header = msg.header

        out.can_pass = decision.can_pass
        # ===== passability / risk: replace the old saturated formula =====
        left_right_diff = abs(decision.left_near - decision.right_near)
        # 左右越不对称，balance 越差
        balance_score = 1.0 - np.clip(left_right_diff / 0.12, 0.0, 1.0)
        # 对齐误差越大，得分越低
        align_score = 1.0 - np.clip(abs(decision.norm_e) / 0.30, 0.0, 1.0)
        # 前向距离越大越好
        clearance_score = np.clip((decision.d_center - 0.35) / 0.35, 0.0, 1.0)
        # 几何裕量映射到 [0,1]
        margin_score = np.clip((decision.geom_margin + 0.10) / 0.35, 0.0, 1.0)
        # 最终 passability 不再只靠 geom_margin + obs_confidence
        raw_passability = (
            0.35 * margin_score +
            0.25 * clearance_score +
            0.20 * balance_score +
            0.20 * align_score
        )
        out.passability = float(np.clip(raw_passability, 0.0, 1.0))
        # risk 与 passability 相反，但额外惩罚左右不平衡和姿态偏差
        raw_risk = (
            0.50 * (1.0 - out.passability) +
            0.30 * np.clip(left_right_diff / 0.10, 0.0, 1.0) +
            0.20 * np.clip(abs(decision.norm_e) / 0.25, 0.0, 1.0)
        )
        out.risk = float(np.clip(raw_risk, 0.0, 1.0))

        out.d_min = decision.d_min
        out.d_center = decision.d_center
        out.gap_x = decision.gap_x
        out.cx = decision.cx
        out.norm_e = decision.norm_e
        out.has_valid_gap = decision.has_valid_gap

        out.left_near = decision.left_near
        out.center_near = decision.center_near
        out.right_near = decision.right_near

        out.left_far = decision.left_far
        out.center_far = decision.center_far
        out.right_far = decision.right_far

        out.d_hat = decision.d_hat
        out.d_min_required = decision.d_min_required
        out.geom_margin = decision.geom_margin
        out.obs_confidence = decision.obs_confidence

        out.mode_hint = decision.mode_hint
        out.recovery_hint = decision.recovery_hint

        self.pub_decision.publish(out)

        can_msg = Bool()
        can_msg.data = decision.can_pass
        self.pub_can_pass.publish(can_msg)

    def analyze_depth(self, depth: np.ndarray) -> DepthDecision:
        h, w = depth.shape

        max_depth = float(self.get_parameter('max_depth').value)
        roi_y_start_ratio = float(self.get_parameter('roi_y_start_ratio').value)
        roi_height_ratio = float(self.get_parameter('roi_height_ratio').value)

        y1 = int(h * roi_y_start_ratio)
        roi_height = int(h * roi_height_ratio)
        y2 = min(h, y1 + roi_height)
        if y2 <= y1:
            y1 = int(h * 0.5)
            y2 = h

        roi = depth[y1:y2, :]
        valid_roi_mask = np.isfinite(roi) & (roi > 0.05) & (roi < max_depth)
        valid_roi_depths = roi[valid_roi_mask]

        if valid_roi_depths.size == 0:
            return DepthDecision(
                can_pass=False,
                d_min=0.0,
                d_center=0.0,
                gap_x=w / 2.0,
                cx=w / 2.0,
                norm_e=0.0,
                has_valid_gap=False,
                d_hat=0.0,
                d_min_required=self.compute_required_width(),
                geom_margin=-1.0,
                obs_confidence=0.0,
                mode_hint="EXPLORE",
                recovery_hint="BACK"
            )

        d_min = float(np.percentile(valid_roi_depths, 20))
        d_center = float(np.median(valid_roi_depths))

        num_bins = max(5, int(self.get_parameter('num_bins').value))
        h_roi, w_roi = roi.shape
        yb1 = int(h_roi * 0.5)
        roi_bottom = roi[yb1:h_roi, :]
        cols = np.array_split(np.arange(w_roi), num_bins)

        profile = np.zeros(num_bins, dtype=np.float32)
        valid_ratio = np.zeros(num_bins, dtype=np.float32)
        has_valid = np.zeros(num_bins, dtype=bool)

        for i, col_idx in enumerate(cols):
            strip = roi_bottom[:, col_idx]
            valid = np.isfinite(strip) & (strip > 0.05) & (strip < max_depth)
            vals = strip[valid]

            vr = float(vals.size) / float(strip.size + 1e-6)
            valid_ratio[i] = vr

            if vals.size == 0:
                profile[i] = max_depth
                has_valid[i] = False
            else:
                profile[i] = float(np.percentile(vals, 20))
                has_valid[i] = True

        bin_centers_x = np.array([float(col_idx.mean()) for col_idx in cols], dtype=np.float32)

        N = num_bins
        left_bins = profile[:N // 3]
        center_bins = profile[N // 3:2 * N // 3]
        right_bins = profile[2 * N // 3:]
 
            
        def near_min(arr):
            mask = (arr > 0.3) & (arr < 1.5)
            if np.any(mask):
                return float(np.min(arr[mask]))
            else:
                return float(max_depth)

        def far_min(arr):
            mask = (arr >= 0.8) & (arr < max_depth)
            if np.any(mask):
                return float(np.min(arr[mask]))
            else:
                return float(max_depth)

        left_near = near_min(left_bins)
        center_near = near_min(center_bins)
        right_near = near_min(right_bins)

        left_far = far_min(left_bins)
        center_far = far_min(center_bins)
        right_far = far_min(right_bins)

        min_obs_near = float(self.get_parameter('min_obs_near').value)
        corridor_near = float(self.get_parameter('corridor_near').value)
        corridor_margin = float(self.get_parameter('corridor_margin').value)

        is_corridor = (
            np.isfinite(left_near) and np.isfinite(right_near) and
            left_near < corridor_near and right_near < corridor_near
        )

       # if is_corridor:
        #    can_pass = (
        #        left_near > min_obs_near and
        #        center_near > min_obs_near and
        #        right_near > min_obs_near
        #    )
        #else:
        #    can_pass = (d_center > min_obs_near)
            
            
        if is_corridor:
            raw_can_pass = (
                left_near > min_obs_near and
                center_near > min_obs_near and
                right_near > min_obs_near
            )
        else:
            raw_can_pass = (d_center > min_obs_near)

        bin_valid_ratio_th = float(self.get_parameter('bin_valid_ratio_th').value)
        unknown_free_depth = float(self.get_parameter('unknown_free_depth').value)

        profile_eff = profile.copy()
        profile_eff[~has_valid] = min(max_depth, unknown_free_depth)

        free_confident = (profile > min_obs_near) & (valid_ratio >= bin_valid_ratio_th)
        free_loose = (profile_eff > min_obs_near) & (valid_ratio >= 0.5 * bin_valid_ratio_th)
        free_mask = free_confident | free_loose

        free_mask_filled = free_mask.copy()
        for i in range(1, N - 1):
            if (not free_mask[i]) and free_mask[i - 1] and free_mask[i + 1]:
                free_mask_filled[i] = True
        free_mask = free_mask_filled

        best_len = 0
        best_start = None
        cur_start = None
        cur_len = 0

        for i in range(N):
            if free_mask[i]:
                if cur_start is None:
                    cur_start = i
                    cur_len = 1
                else:
                    cur_len += 1
            else:
                if cur_start is not None and cur_len > best_len:
                    best_len = cur_len
                    best_start = cur_start
                cur_start = None
                cur_len = 0

        if cur_start is not None and cur_len > best_len:
            best_len = cur_len
            best_start = cur_start

        has_valid_gap = best_len > 0
        cx = w / 2.0
        gap_x = cx

        if has_valid_gap:
            best_center_bin = best_start + best_len / 2.0
            idx = int(np.clip(round(best_center_bin), 0, num_bins - 1))
            gap_x = float(bin_centers_x[idx])

        norm_e = float((gap_x - cx) / (w / 2.0))

        # --- geometry prior ---
        d_hat = self.estimate_gap_width(best_len, num_bins)
        d_min_required = self.compute_required_width()
        geom_margin = d_hat - d_min_required

        obs_confidence = float(np.clip(np.mean(valid_ratio) * 2.0, 0.0, 1.0))
        
        can_pass = (
            raw_can_pass and
            has_valid_gap and
            geom_margin > -0.02 and
            abs(norm_e) < 0.45 and
            obs_confidence > 0.15
        )

        # simple mode hint
        if not can_pass and geom_margin < -0.05:
            mode_hint = "REJECT"
        elif not can_pass:
            mode_hint = "EXPLORE"
        elif abs(norm_e) > 0.25:
            mode_hint = "EXPLORE"
        else:
            mode_hint = "COMMIT"

        recovery_hint = "NONE"
        if not can_pass and geom_margin < -0.05:
            recovery_hint = "BACK"
        elif abs(norm_e) > 0.3:
            recovery_hint = "REALIGN"

        return DepthDecision(
            can_pass=can_pass,
            d_min=d_min,
            d_center=d_center,
            gap_x=gap_x,
            cx=cx,
            norm_e=norm_e,
            has_valid_gap=has_valid_gap,
            left_near=left_near,
            center_near=center_near,
            right_near=right_near,
            left_far=left_far,
            center_far=center_far,
            right_far=right_far,
            d_hat=d_hat,
            d_min_required=d_min_required,
            geom_margin=geom_margin,
            obs_confidence=obs_confidence,
            mode_hint=mode_hint,
            recovery_hint=recovery_hint,
        )

    def compute_required_width(self) -> float:
        wb = float(self.get_parameter('robot_body_width').value)
        lb = float(self.get_parameter('robot_body_length').value)
        hb = float(self.get_parameter('robot_body_height').value)
        dleg = float(self.get_parameter('leg_swing_margin').value)
        dsensor = float(self.get_parameter('sensor_swing_margin').value)
        eps = float(self.get_parameter('uncertainty_margin').value)
        phi_deg = float(self.get_parameter('max_roll_deg').value)
        yaw_deg = float(self.get_parameter('yaw_assumption_deg').value)

        phi = math.radians(phi_deg)
        yaw = math.radians(yaw_deg)

        return (
            abs((wb + 2.0 * dleg) * math.cos(yaw))
            + abs(lb * math.sin(yaw))
            + 2.0 * dsensor
            + hb * abs(math.sin(phi))
            + 2.0 * eps
        )

    def estimate_gap_width(self, best_len: int, num_bins: int) -> float:
        # chu版：把最长自由区间长度映射成估计宽度
        # 后续替换成相机模型/深度几何投影
        if best_len <= 0:
            return 0.0
        normalized = float(best_len) / float(max(1, num_bins))
        return 0.25 + 0.75 * normalized


def main(args=None):
    rclpy.init(args=args)
    node = DepthPerceptionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
