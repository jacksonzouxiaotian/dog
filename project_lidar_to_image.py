#!/usr/bin/env python3
"""
Project many LiDAR points to camera and save debug image.

Usage:
  # make sure ROS2 Foxy environment is sourced (and your workspace built)
  python3 project_lidar_to_image.py

Parameters (edit at top of file or pass via ROS params if you adapt):
  - pc_topic (default /livox/points)
  - img_topic (default /camera/color/image_raw)
  - caminfo_topic (default /camera/color/camera_info)
  - out_image_path (default /tmp/projection_vis.png)
  - num_points_sample (default 3000)
  - use_calib_file (optional): path to JSON with intrinsics+rotation baseline (if you use that)
  - lidar_to_cam_override: [tx,ty,tz] in meters (optional)
"""
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2, Image, CameraInfo
from cv_bridge import CvBridge
import numpy as np
import cv2
import json
import struct
import os
import random
from sensor_msgs_py import point_cloud2

class ProjectorNode(Node):
    def __init__(self):
        super().__init__('lidar_to_image_projector')
        # params (tweak here if you prefer)
        self.declare_parameter('pc_topic', '/livox/points')
        self.declare_parameter('img_topic', '/camera/color/image_raw')
        self.declare_parameter('caminfo_topic', '/camera/color/camera_info')
        self.declare_parameter('out_image_path', '/tmp/projection_vis.png')
        self.declare_parameter('num_points_sample', 3000)
        self.declare_parameter('calib_file', '')  # optional path to JSON
        self.declare_parameter('lidar_to_cam_t', [0.0, 0.0, 0.0])  # optional override (meters)

        self.pc_topic = self.get_parameter('pc_topic').get_parameter_value().string_value
        self.img_topic = self.get_parameter('img_topic').get_parameter_value().string_value
        self.caminfo_topic = self.get_parameter('caminfo_topic').get_parameter_value().string_value
        self.out_image_path = self.get_parameter('out_image_path').get_parameter_value().string_value
        self.num_points_sample = int(self.get_parameter('num_points_sample').get_parameter_value().integer_value)
        calib_file = self.get_parameter('calib_file').get_parameter_value().string_value
        t_param = list(self.get_parameter('lidar_to_cam_t').get_parameter_value().double_array_value)

        # subs
        self.pc_msg = None
        self.img_msg = None
        self.caminfo_msg = None
        self.pc_sub = self.create_subscription(PointCloud2, self.pc_topic, self.pc_cb, 10)
        self.img_sub = self.create_subscription(Image, self.img_topic, self.img_cb, 10)
        self.caminfo_sub = self.create_subscription(CameraInfo, self.caminfo_topic, self.caminfo_cb, 10)

        self.bridge = CvBridge()
        self.get_logger().info(f"Subscribed to pc:{self.pc_topic} img:{self.img_topic} caminfo:{self.caminfo_topic}")

        # intrinsics / extrinsics initial values
        self.K = None
        self.T_l2c = np.eye(4, dtype=np.float32)

        # if calib file given, try load (same parsing logic as earlier)
        if calib_file and os.path.exists(calib_file):
            try:
                with open(calib_file, 'r') as f:
                    calib = json.load(f)
                prefix = 'rectified.0'
                if f"{prefix}.fx" in calib:
                    fx = float(calib[f"{prefix}.fx"])
                    fy = float(calib[f"{prefix}.fy"])
                    ppx = float(calib[f"{prefix}.ppx"])
                    ppy = float(calib[f"{prefix}.ppy"])
                    self.K = np.array([[fx,0,ppx],[0,fy,ppy],[0,0,1]], dtype=np.float32)
                # rotation
                if "world2left_rot.x.x" in calib:
                    R = np.array([
                        [float(calib["world2left_rot.x.x"]), float(calib["world2left_rot.x.y"]), float(calib["world2left_rot.x.z"])],
                        [float(calib["world2left_rot.y.x"]), float(calib["world2left_rot.y.y"]), float(calib["world2left_rot.y.z"])],
                        [float(calib["world2left_rot.z.x"]), float(calib["world2left_rot.z.y"]), float(calib["world2left_rot.z.z"])]
                    ], dtype=np.float32)
                else:
                    R = np.eye(3, dtype=np.float32)
                # translation override or baseline
                if any(abs(x) > 1e-9 for x in t_param):
                    t = np.array(t_param, dtype=np.float32)
                else:
                    t = np.zeros((3,), dtype=np.float32)
                    if 'baseline' in calib:
                        b = float(calib['baseline'])
                        b_m = b/1000.0 if abs(b) > 1.0 else b
                        t[0] = b_m
                T = np.eye(4, dtype=np.float32)
                T[:3,:3] = R
                T[:3,3] = t
                self.T_l2c = T
                self.get_logger().info(f"Loaded calib_file {calib_file}; K loaded? {self.K is not None}; T_l2c:\n{self.T_l2c}")
            except Exception as e:
                self.get_logger().warn(f"Failed load calib_file: {e}")
        else:
            if calib_file:
                self.get_logger().warn(f"calib_file {calib_file} not found, will get K from camera_info at runtime")
            # use t_param if provided
            if any(abs(x) > 1e-9 for x in t_param):
                self.T_l2c[:3,3] = np.array(t_param, dtype=np.float32)

        # single-shot timer to wait for topics then run once
        self.timer = self.create_timer(0.5, self.run_once)

    def pc_cb(self, msg):
        self.pc_msg = msg

    def img_cb(self, msg):
        self.img_msg = msg

    def caminfo_cb(self, msg):
        self.caminfo_msg = msg

    def pointcloud2_to_xyz(self, cloud_msg):
        # robust aggregator using sensor_msgs_py.point_cloud2
        pts = []
        for p in point_cloud2.read_points(cloud_msg, skip_nans=True, field_names=('x','y','z')):
            pts.append([p[0], p[1], p[2]])
        if len(pts) == 0:
            return np.zeros((0,3), dtype=np.float32)
        return np.array(pts, dtype=np.float32)

    def run_once(self):
        # run only once
        if self.pc_msg is None or self.img_msg is None or self.caminfo_msg is None:
            self.get_logger().info("Waiting for pc/img/caminfo...")
            return

        self.get_logger().info("Got pc/img/caminfo -> processing projection")
        # convert camera info if K not loaded
        if self.K is None:
            k = self.caminfo_msg.k
            self.K = np.array([[k[0], k[1], k[2]],[k[3], k[4], k[5]],[k[6], k[7], k[8]]], dtype=np.float32)
            self.get_logger().info(f"Loaded K from camera_info: {self.K}")

        # convert image (support depth 16UC1 or normal color)
        try:
            # don't force bgr8; let CvBridge give raw encoding
            img_raw = self.bridge.imgmsg_to_cv2(self.img_msg, desired_encoding='passthrough')
        except Exception as e:
            self.get_logger().error(f"Failed to convert image (passthrough): {e}")
            return

        # If this is a depth image (16UC1), convert to a nice 3-channel BGR for visualization
        if img_raw.dtype == np.uint16:
            depth = img_raw.astype(np.float32)
            valid = depth > 0
            if np.any(valid):
                max_d = np.percentile(depth[valid], 95)
                max_d = max(max_d, 1.0)
            else:
                max_d = 5.0
            depth_norm = np.clip(depth / max_d, 0.0, 1.0)
            img_gray = (depth_norm * 255.0).astype(np.uint8)
            img = cv2.cvtColor(img_gray, cv2.COLOR_GRAY2BGR)
            self.get_logger().info("Converted 16UC1 depth image to BGR for visualization")
        else:
            # if it's already 8-bit grayscale
            if len(img_raw.shape) == 2:
                img = cv2.cvtColor(img_raw, cv2.COLOR_GRAY2BGR)
            else:
                # assume it's already BGR/RGB-like
                img = img_raw  
            
        H, W = img.shape[:2]

        # get point cloud points
        pts = self.pointcloud2_to_xyz(self.pc_msg)
        if pts.shape[0] == 0:
            self.get_logger().warn("Point cloud empty")
            return

        # sample points (random) to limit drawing load
        N = self.num_points_sample
        if pts.shape[0] > N:
            idx = np.random.choice(pts.shape[0], size=N, replace=False)
            pts_s = pts[idx]
        else:
            pts_s = pts

        # convert to homogeneous and transform LiDAR->camera
        ones = np.ones((pts_s.shape[0],1), dtype=np.float32)
        pts_h = np.hstack([pts_s, ones])  # Nx4
        pts_cam = (self.T_l2c @ pts_h.T).T  # Nx4
        Z = pts_cam[:,2]
        valid = Z > 1e-6
        num_valid = int(np.sum(valid))
        self.get_logger().info(f"Sampled {pts_s.shape[0]} pts, valid in front of camera: {num_valid}")

        # project valid
        proj = np.zeros((pts_s.shape[0],2), dtype=np.float32)
        proj[valid,0] = self.K[0,0] * (pts_cam[valid,0] / pts_cam[valid,2]) + self.K[0,2]
        proj[valid,1] = self.K[1,1] * (pts_cam[valid,1] / pts_cam[valid,2]) + self.K[1,2]

        # draw points colored by depth
        vis = img.copy()
        max_depth = np.percentile(pts_cam[valid,2], 95) if num_valid>0 else 5.0
        min_depth = np.percentile(pts_cam[valid,2], 5) if num_valid>0 else 0.1
        for (u,v), vz, ok in zip(proj, pts_cam[:,2], valid):
            if not ok: continue
            ui = int(round(u)); vi = int(round(v))
            if ui < 0 or ui >= W or vi < 0 or vi >= H:
                continue
            # color map depth: near->red, far->blue
            z = float(vz)
            zc = (z - min_depth) / max(1e-6, (max_depth - min_depth))
            zc = min(1.0, max(0.0, zc))
            col = (int(255*(1-zc)), int(0), int(255*zc))  # BGR: near red -> far blue
            cv2.circle(vis, (ui,vi), 1, col, -1)

        # save image
        try:
            cv2.imwrite(self.out_image_path, vis)
            self.get_logger().info(f"Wrote projection visualization to {self.out_image_path}")
        except Exception as e:
            self.get_logger().warn(f"Failed to write image: {e}")

        # publish debug image topic for remote viewing (optionally)
        try:
            from sensor_msgs.msg import Image as RosImage
            ros_img = self.bridge.cv2_to_imgmsg(vis, encoding='bgr8')
            pub = self.create_publisher(RosImage, '/late_fusion/projection_debug', 1)
            pub.publish(ros_img)
            self.get_logger().info("Published debug image to /late_fusion/projection_debug")
        except Exception as e:
            self.get_logger().warn(f"Failed to publish debug image: {e}")

        # after one run, shutdown
        self.get_logger().info("Projection done — shutting down node")
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = ProjectorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    # if rclpy shutdown not triggered above, destroy node
    try:
        node.destroy_node()
    except Exception:
        pass

if __name__ == "__main__":
    main()
