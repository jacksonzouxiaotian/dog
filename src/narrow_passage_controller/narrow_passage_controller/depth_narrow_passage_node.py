#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
将“做出判断”和“下命令控制”拆成两个清晰部分，便于调试：

1) analyze_depth() 负责根据深度图做判断（感知层）
2) compute_cmd_from_decision() 负责根据判断结果生成控制指令（控制层）

流程:
depth Image(msg) -> numpy depth -> decision(决策结果) -> cmd_vel(Twist)
"""

import numpy as np
from dataclasses import dataclass

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from std_msgs.msg import Bool
from geometry_msgs.msg import Twist

from cv_bridge import CvBridge
from rclpy.qos import qos_profile_sensor_data

# ===================== 一、决策结果结构体 =====================

@dataclass
class DepthDecision:
    """感知部分的输出，方便打印和调试"""
    can_pass: bool           # 是否认为可以通过狭窄区域
    d_min: float             # ROI 内最小有效深度 (最近障碍物)
    d_center: float          # ROI 内中位数深度 (整体前方距离)
    gap_x: float             # 认为狭缝中心在图像中的 x 像素坐标
    cx: float                # 图像中心的 x 像素坐标
    norm_e: float            # gap_x 与 cx 的归一化偏差 (约 [-1,1])，>0: 通道在右边
    has_valid_gap: bool      # 是否找到了合理的通道方向


# ===================== 二、主节点 =====================

class DepthNarrowPassageNode(Node):
    def __init__(self):
        super().__init__('depth_narrow_passage_node')

        # ---------- 参数 ----------
        self.declare_parameter('depth_topic', '/camera/depth/image_rect_raw')
        self.declare_parameter('depth_threshold', 1.0)   # d_min > 该阈值才认为 can_pass=True
        self.declare_parameter('max_depth', 5.0)

        # ROI 设置
        self.declare_parameter('roi_y_start_ratio', 0.6)
        self.declare_parameter('roi_height_ratio', 0.4)

        # bin 设置（用于找狭缝中心）
        self.declare_parameter('num_bins', 40)
        self.declare_parameter('bin_min_valid_ratio', 0.2)
        self.declare_parameter('min_bin_depth', 0.4)

        # 线速度控制参数
        self.declare_parameter('safe_distance', 0.7)
        self.declare_parameter('k_v', 0.5)
        self.declare_parameter('v_max', 0.3)

        # 角速度控制参数（对齐狭缝）
        self.declare_parameter('k_omega_align', 2.0)
        self.declare_parameter('omega_max', 0.8)

        # 不可通过时是否强制停
        self.declare_parameter('stop_if_not_can_pass', True)

        depth_topic = self.get_parameter('depth_topic').get_parameter_value().string_value

        self.bridge = CvBridge()
        self.last_encoding_warned = False

        # ---------- 订阅 & 发布 ----------
        self.sub_depth = self.create_subscription(
            Image,
            depth_topic,
            self.depth_callback,
            qos_profile_sensor_data
        )

        self.pub_can_pass = self.create_publisher(Bool, '/narrow_can_pass', 10)
        self.pub_cmd_vel = self.create_publisher(Twist, '/cmd_vel', 10)

        self.get_logger().info(f"[depth_narrow_passage_node] Subscribing depth: {depth_topic}")

    # ========== 回调入口：这里只负责“串起来”两个部分 ==========

    def depth_callback(self, msg: Image):
        """1) 把 ROS Image 转成 numpy depth
           2) 调用感知部分 analyze_depth()
           3) 调用控制部分 compute_cmd_from_decision()
        """
        # ---- 1. 转成 numpy 深度图，单位: m ----
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

        # ---- 2. 感知部分：根据深度图做判断 ----
        decision = self.analyze_depth(depth)

        # 发布 can_pass 方便外部调试
        can_pass_msg = Bool()
        can_pass_msg.data = decision.can_pass
        self.pub_can_pass.publish(can_pass_msg)

        # 打印一些关键调试信息（你调试时可以开 info / debug）
        self.get_logger().debug(
            f"can_pass={decision.can_pass}, "
            f"d_min={decision.d_min:.3f}m, d_center={decision.d_center:.3f}m, "
            f"has_valid_gap={decision.has_valid_gap}, norm_e={decision.norm_e:.3f}"
        )

        # ---- 3. 控制部分：根据决策生成 cmd_vel ----
        cmd = self.compute_cmd_from_decision(decision)

        # 发布控制指令
        self.pub_cmd_vel.publish(cmd)

    # ===================== 三、部分 1：感知 / 判断 =====================

    def analyze_depth(self, depth: np.ndarray) -> DepthDecision:
        """
        输入: depth (h x w, 单位 m)
        输出: DepthDecision 结构体

        升级版:
        - 用 20% 分位代替纯最小值，减少地板/噪声影响
        - 通过“中间 vs 左右”的相对关系判断 can_pass
        - 横向做一维 depth profile 再找最长可通行区间作为 gap
        """
        h, w = depth.shape

        max_depth = self.get_parameter('max_depth').get_parameter_value().double_value
        roi_y_start_ratio = self.get_parameter('roi_y_start_ratio').get_parameter_value().double_value
        roi_height_ratio  = self.get_parameter('roi_height_ratio').get_parameter_value().double_value

        # -------- 1. 取 ROI（前方底部） --------
        y1 = int(h * roi_y_start_ratio)
        roi_height = int(h * roi_height_ratio)
        y2 = min(h, y1 + roi_height)
        if y2 <= y1:
            y1 = int(h * 0.5)
            y2 = h

        roi = depth[y1:y2, :]

        # 去掉无效点
        valid_roi_mask = np.isfinite(roi) & (roi > 0.05) & (roi < max_depth)
        valid_roi_depths = roi[valid_roi_mask]

        if valid_roi_depths.size == 0:
            # 无任何有效深度，保守起见: 不可通过
            return DepthDecision(
                can_pass=False,
                d_min=0.0,
                d_center=0.0,
                gap_x=w / 2.0,
                cx=w / 2.0,
                norm_e=0.0,
                has_valid_gap=False
            )

        # 用 20% 分位估计“最近一批点”的深度，避免单点噪声
        d_min = float(np.percentile(valid_roi_depths, 20))
        d_center = float(np.median(valid_roi_depths))

        # -------- 2. 构造一维 depth profile --------
        num_bins = self.get_parameter('num_bins').get_parameter_value().integer_value
        if num_bins < 5:
            num_bins = 5

        h_roi, w_roi = roi.shape
        bin_width = w_roi // num_bins if num_bins > 0 else w_roi

        # 只用 ROI 的下半部分做 profile（避开远处噪声）
        yb1 = int(h_roi * 0.5)
        yb2 = h_roi
        roi_bottom = roi[yb1:yb2, :]

        profile = np.zeros(num_bins, dtype=np.float32)
        has_valid = np.zeros(num_bins, dtype=bool)

        for i in range(num_bins):
            x1 = i * bin_width
            x2 = (i + 1) * bin_width if i < num_bins - 1 else w_roi
            strip = roi_bottom[:, x1:x2]

            valid = np.isfinite(strip) & (strip > 0.05) & (strip < max_depth)
            vals = strip[valid]
            if vals.size == 0:
                # 用 max_depth 代表“没测到/很远”，留给后面处理
                profile[i] = max_depth
                has_valid[i] = False
            else:
                # 取 20% 分位：数值越小越近，越危险
                profile[i] = np.percentile(vals, 20)
                has_valid[i] = True

        # -------- 3. 基于左右/中间做 can_pass 判断 --------
        depth_threshold = self.get_parameter('depth_threshold').get_parameter_value().double_value

        # 拿左右三分之一做统计
        N = num_bins
        left_bins   = profile[: N // 3]
        center_bins = profile[N // 3 : 2 * N // 3]
        right_bins  = profile[2 * N // 3 :]

        left   = float(np.nanmean(left_bins))
        center = float(np.nanmean(center_bins))
        right  = float(np.nanmean(right_bins))

        # 最小安全距离（靠箱子太近就认为不安全）
        min_obs = 0.35   # 可以调
        # 中间比左右至少远一点才认为是通道
        gap_margin = 0.15

        can_pass = (
            left   > min_obs and
            right  > min_obs and
            center > min_obs and
            center > left  + gap_margin and
            center > right + gap_margin and
            d_min  > depth_threshold   # 整体上最近距离也不能太小
        )

        # -------- 4. 在 profile 上找“最长连续可通行区间”做为 gap --------
        # 判定某个 bin 是否“可通行”：深度 > min_obs
        free_mask = profile > min_obs

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

        # 尾段连续区间的处理
        if cur_start is not None and cur_len > best_len:
            best_len = cur_len
            best_start = cur_start

        has_valid_gap = best_len > 0

        cx = w / 2.0
        gap_x = cx

        if has_valid_gap:
            # 取这段连续 free 区间的中心 bin
            best_center_bin = best_start + best_len / 2.0
            gap_x = (best_center_bin + 0.5) * bin_width  # 转成像素坐标

        e = gap_x - cx
        norm_e = e / (w / 2.0)

        return DepthDecision(
            can_pass=can_pass,
            d_min=d_min,
            d_center=d_center,
            gap_x=float(gap_x),
            cx=float(cx),
            norm_e=float(norm_e),
            has_valid_gap=has_valid_gap
        )


    # ===================== 四、部分 2：控制 / 下命令 =====================

    def compute_cmd_from_decision(self, decision: DepthDecision) -> Twist:
        """
        输入: DepthDecision（来自感知层）
        输出: 速度指令 Twist（给 /cmd_vel）

        这里面你可以随时改控制逻辑，而不用担心“看图逻辑”。
        """
        cmd = Twist()

        # ---- 1. 线速度控制：根据前方距离 d_center ----
        safe_distance = self.get_parameter('safe_distance').get_parameter_value().double_value
        k_v           = self.get_parameter('k_v').get_parameter_value().double_value
        v_max         = self.get_parameter('v_max').get_parameter_value().double_value
        stop_if_not_can_pass = self.get_parameter('stop_if_not_can_pass').get_parameter_value().bool_value

        if (not decision.can_pass) and stop_if_not_can_pass:
            v = 0.0
        else:
            error_d = decision.d_center - safe_distance
            v = k_v * error_d
            v = float(np.clip(v, 0.0, v_max))

        cmd.linear.x = v

        # ---- 2. 角速度控制：对齐狭缝中心 ----
        k_omega_align = self.get_parameter('k_omega_align').get_parameter_value().double_value
        omega_max     = self.get_parameter('omega_max').get_parameter_value().double_value

        if decision.has_valid_gap:
            omega = k_omega_align * decision.norm_e
            omega = float(np.clip(omega, -omega_max, omega_max))

            # 如果偏差非常大，可以考虑减小线速度或停下来先转
            if abs(decision.norm_e) > 0.25:
                cmd.linear.x = min(cmd.linear.x, 0.05)
        else:
            # 没有找到合理通道方向，先不转头
            omega = 0.0

        cmd.angular.z = omega

        return cmd


# ===================== 五、入口 =====================

def main(args=None):
    rclpy.init(args=args)
    node = DepthNarrowPassageNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
