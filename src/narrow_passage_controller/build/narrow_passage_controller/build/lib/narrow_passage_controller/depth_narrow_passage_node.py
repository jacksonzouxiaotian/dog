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
    # 新增一些 summary，便于以后控制或 RL
    left_near: float = 0.0
    center_near: float = 0.0
    right_near: float = 0.0
    left_far: float = 0.0
    center_far: float = 0.0
    right_far: float = 0.0


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
        
        # --- 狭窄通道判定/可通行判定参数化 ---
        self.declare_parameter('min_obs_near', 0.35)      # 最近安全距离（小于它就危险）
        self.declare_parameter('corridor_near', 1.2)      # 左右都 < 该阈值才认为是“被夹住”
        self.declare_parameter('corridor_margin', 0.10)   # center 比左右远多少才算“中间更通畅”

        # --- 对齐控制的稳定化 ---
        self.declare_parameter('e_deadband', 0.05)        # 小偏差不转
        self.declare_parameter('e_lpf_alpha', 0.30)       # 归一化偏差的一阶低通滤波系数(0~1)
        
        # --- 贴墙趋势检测参数 ---
        self.declare_parameter('near_drop_th', 0.08)   # “急剧减小”的阈值(米)，比如 0.08~0.15
        self.declare_parameter('near_low_th', 0.35)    # 贴得太近(米)
        self.declare_parameter('near_safe_th', 0.40)   # 另一侧相对安全(米)

        # --- 小步纠偏动作参数 ---
        self.declare_parameter('step_v_back', 0.05)    # 后退速度（m/s）
        self.declare_parameter('step_omega', 0.6)      # 转向角速度（rad/s）
        self.declare_parameter('step_ticks', 6)        # 持续多少帧（取决于相机帧率；6帧≈0.2~0.3s）
        
        self.declare_parameter('bin_valid_ratio_th', 0.02)     # 这个 bin 至少要有这么多有效点才算“可信”
        self.declare_parameter('unknown_free_depth', 2.0)      # unknown 时用多少米作为“可能空旷”的参考

        # 上一帧 near
        self.prev_left_near = None
        self.prev_center_near = None
        self.prev_right_near = None

        # 纠偏动作状态机
        self.step_mode = None      # 'BACK_RIGHT' / 'BACK_LEFT' / 'BACK'
        self.step_count = 0
        

        # 低通滤波状态
        self.e_filt = 0.0
        

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
        self.pub_cmd_vel = self.create_publisher(Twist, '/safety_cmd_vel', 10)

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
        yb1 = int(h_roi * 0.5)
        roi_bottom = roi[yb1:h_roi, :]
        # ---- 用 array_split 保障每个 bin 至少有 1 列（不会出现 bin_width=0）----
        cols = np.array_split(np.arange(w_roi), num_bins)

        profile = np.zeros(num_bins, dtype=np.float32)
        valid_ratio = np.zeros(num_bins, dtype=np.float32)   # 新增：每个 bin 的有效点比例
        has_valid = np.zeros(num_bins, dtype=bool)

        for i, col_idx in enumerate(cols):
            strip = roi_bottom[:, col_idx]  # (h, w_bin)

            valid = np.isfinite(strip) & (strip > 0.05) & (strip < max_depth)
            vals = strip[valid]

            vr = float(vals.size) / float(strip.size + 1e-6)
            valid_ratio[i] = vr

            if vals.size == 0:
                # 仍然用 max_depth 表示“未知/很远”，但不要直接一票否决
                profile[i] = max_depth
                has_valid[i] = False
            else:
                profile[i] = float(np.percentile(vals, 20))
                has_valid[i] = True

        # 用真实 bin 像素宽近似 gap_x
        bin_centers_x = np.array([float(col_idx.mean()) for col_idx in cols], dtype=np.float32)

        # -------- 3. 基于左右/中间做 can_pass 判断 --------
        depth_threshold = self.get_parameter('depth_threshold').get_parameter_value().double_value

        # 拿左右三分之一做统计
        N = num_bins
        left_bins   = profile[: N // 3]
        center_bins = profile[N // 3 : 2 * N // 3]
        right_bins  = profile[2 * N // 3 :]

        def near_min(arr):
            mask = (arr > 0.3) & (arr < 1.5)
            if np.any(mask):
                return float(np.min(arr[mask]))
            else:
                return float('inf')

        # 远距：0.X ~ max_depth，用最小值（远处障碍提前出现）
        def far_min(arr):
            mask = (arr >= 0.8) & (arr < max_depth)
            if np.any(mask):
                return float(np.min(arr[mask]))
            else:
                return float('inf')

        left_near   = near_min(left_bins)
        center_near = near_min(center_bins)
        right_near  = near_min(right_bins)

        left_far    = far_min(left_bins)
        center_far  = far_min(center_bins)
        right_far   = far_min(right_bins)

        # 原始平均值（保留一份）
        left_raw   = float(np.nanmean(left_bins))
        center_raw = float(np.nanmean(center_bins))
        right_raw  = float(np.nanmean(right_bins))

        # 对远处更敏感：用 1/depth 作为附加特征（避免除 0）
        eps = 1e-6
        left_inv   = 1.0 / max(left_raw,   eps)
        center_inv = 1.0 / max(center_raw, eps)
        right_inv  = 1.0 / max(right_raw,  eps)

        # DEBUG 打印更丰富
        self.get_logger().info(
            "[DEBUG] near L/C/R = "
            f"{left_near:.2f}/{center_near:.2f}/{right_near:.2f}, "
            f"far L/C/R = {left_far:.2f}/{center_far:.2f}/{right_far:.2f}, "
            f"raw L/C/R = {left_raw:.2f}/{center_raw:.2f}/{right_raw:.2f}, "
            f"d_min={d_min:.2f}"
        )
        
        

        # 最小安全距离（靠箱子太近就认为不安全）
        min_obs_near = self.get_parameter('min_obs_near').get_parameter_value().double_value
        corridor_near = self.get_parameter('corridor_near').get_parameter_value().double_value
        corridor_margin = self.get_parameter('corridor_margin').get_parameter_value().double_value

        # 判定是否被两侧“夹住”（窄通道模式）
        is_corridor = (
            np.isfinite(left_near) and np.isfinite(right_near) and
            left_near < corridor_near and right_near < corridor_near
        )

        if is_corridor:
            # 被夹住时需谨慎：左右近距都不能太小，且 center_near 要比左右远一点
            can_pass = (
                left_near   > min_obs_near and
                right_near  > min_obs_near and
                center_near > min_obs_near and
                center_near > left_near  + corridor_margin and
                center_near > right_near + corridor_margin
            )
        else:
            # 否则就是开放模式：只要最近障碍不太近即可
            can_pass = (d_min > min_obs_near)

        # -------- 4. 在 profile 上找“最长连续可通行区间”做为 gap --------
        # 判定某个 bin 是否“可通行”：深度 > min_obs
        bin_valid_ratio_th = self.get_parameter('bin_valid_ratio_th').get_parameter_value().double_value
        unknown_free_depth = self.get_parameter('unknown_free_depth').get_parameter_value().double_value
        is_unknown = ~has_valid
        # 对 unknown：如果 profile==max_depth，我们把它当作“可能很远”，但可信度低
        profile_eff = profile.copy()
        profile_eff[is_unknown] = min(max_depth, unknown_free_depth)
        # 可信 free：有足够有效点且深度安全
        free_confident = (profile > min_obs_near) & (valid_ratio >= bin_valid_ratio_th)
        # 宽松 free：unknown 也允许作为候选（但仍要求周围整体不要太近）
        # unknown 只能在 valid_ratio 不是完全 0 的情况下参与（否则太冒险）
        free_loose = (profile_eff > min_obs_near) & (valid_ratio >= (0.5 * bin_valid_ratio_th))
        # 最终用于找 gap 的 free_mask：优先 confident，但 loose 也可连通
        free_mask = free_confident | free_loose
        # ---- 填小洞：free_mask 中间出现单个 False 会导致 gap 被切断 ----
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
            gap_x = float(bin_centers_x[int(np.clip(round(best_center_bin), 0, num_bins - 1))])  # 转成像素坐标

        e = gap_x - cx
        norm_e = e / (w / 2.0)
        
        #forward 距离（只看中间 20% 宽度的 ROI）
        mid_w = int(w_roi * 0.2)  # 中间带宽度比例可再参数化
        x_mid1 = max(0, w_roi // 2 - mid_w // 2)
        x_mid2 = min(w_roi, w_roi // 2 + mid_w // 2)
        roi_mid = roi[:, x_mid1:x_mid2]
        valid_mid = np.isfinite(roi_mid) & (roi_mid > 0.05) & (roi_mid < max_depth)
        vals_mid = roi_mid[valid_mid]
        if vals_mid.size > 0:
            d_forward = float(np.percentile(vals_mid, 30))  # 比 median 更“看前方”
        else:
            d_forward = d_center  # fallback

        return DepthDecision(
            can_pass=can_pass,
            d_min=d_min,
            d_center=d_forward,
            gap_x=float(gap_x),
            cx=float(cx),
            norm_e=float(norm_e),
            has_valid_gap=has_valid_gap,
            left_near=left_near,
            center_near=center_near,
            right_near=right_near,
            left_far=left_far,
            center_far=center_far,
            right_far=right_far,
        )


    # ===================== 四、部分 2：控制 / 下命令 =====================

    def compute_cmd_from_decision(self, decision: DepthDecision) -> Twist:
        """
        输入: DepthDecision（来自感知层）
        输出: 速度指令 Twist（给 /cmd_vel）

        这里面你可以随时改控制逻辑，而不用担心“看图逻辑”。
        """
        cmd = Twist()
        
        # ---------- 0) 贴墙趋势（near 急剧减小）优先纠偏 ----------
        near_drop_th = self.get_parameter('near_drop_th').get_parameter_value().double_value
        near_low_th  = self.get_parameter('near_low_th').get_parameter_value().double_value
        near_safe_th = self.get_parameter('near_safe_th').get_parameter_value().double_value

        step_v_back  = self.get_parameter('step_v_back').get_parameter_value().double_value
        step_omega   = self.get_parameter('step_omega').get_parameter_value().double_value
        step_ticks   = self.get_parameter('step_ticks').get_parameter_value().integer_value

        L = decision.left_near
        C = decision.center_near
        R = decision.right_near

        # 计算“急剧减小”：drop = prev - current
        def compute_drop(prev, cur):
            if prev is None or (not np.isfinite(cur)) or (not np.isfinite(prev)):
                return 0.0
            return float(prev - cur)

        dL = compute_drop(self.prev_left_near, L)
        dC = compute_drop(self.prev_center_near, C)
        dR = compute_drop(self.prev_right_near, R)

        # 更新 prev（先算 drop，再更新）
        self.prev_left_near = L if np.isfinite(L) else self.prev_left_near
        self.prev_center_near = C if np.isfinite(C) else self.prev_center_near
        self.prev_right_near = R if np.isfinite(R) else self.prev_right_near

        # 触发条件：你描述的三种情况
        left_too_close_trend  = (dL > near_drop_th) and (L < near_low_th) and (R > near_safe_th)
        right_too_close_trend = (dR > near_drop_th) and (R < near_low_th) and (L > near_safe_th)
        all_too_close_trend   = (dL > near_drop_th) and (dC > near_drop_th) and (dR > near_drop_th) and \
                                (L < near_safe_th) and (C < near_safe_th) and (R < near_safe_th)

        # 如果当前没有在执行小步动作，则根据触发条件进入动作
        if self.step_mode is None:
            if all_too_close_trend:
                self.step_mode = 'BACK'
                self.step_count = step_ticks
            elif left_too_close_trend:
                self.step_mode = 'BACK_RIGHT'
                self.step_count = step_ticks
            elif right_too_close_trend:
                self.step_mode = 'BACK_LEFT'
                self.step_count = step_ticks

        # 如果在执行小步动作，直接输出固定 cmd，优先级最高
        if self.step_mode is not None and self.step_count > 0:
            if self.step_mode == 'BACK_RIGHT':
                cmd.linear.x = -step_v_back
                cmd.angular.z = +step_omega
            elif self.step_mode == 'BACK_LEFT':
                cmd.linear.x = -step_v_back
                cmd.angular.z = -step_omega
            else:  # 'BACK'
                cmd.linear.x = -step_v_back
                cmd.angular.z = 0.0

            self.step_count -= 1
            if self.step_count <= 0:
                self.step_mode = None

            return cmd

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
            # --- 1) norm_e 低通滤波，减少 bin 离散导致的抖动 ---
            alpha = self.get_parameter('e_lpf_alpha').get_parameter_value().double_value
            self.e_filt = (1.0 - alpha) * self.e_filt + alpha * decision.norm_e

            # --- 2) 死区：小偏差不转 ---
            deadband = self.get_parameter('e_deadband').get_parameter_value().double_value
            e = self.e_filt
            if abs(e) < deadband:
                e = 0.0

            omega = -k_omega_align * e
            omega = float(np.clip(omega, -omega_max, omega_max))

            # 偏差大：先慢走（必要时你也可以改成直接停转）
            if abs(e) > 0.25:
                cmd.linear.x = min(cmd.linear.x, 0.05)
        else:
            omega = 0.0
            # 没有 gap 时把滤波状态慢慢回零，避免下一帧突然大转
            self.e_filt *= 0.9

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
