#!/usr/bin/env python3
# late_fusion_node.py
# ROS2 rclpy node: subscribes Livox PointCloud2 + camera RGB + depth, produces matches

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2, Image, CameraInfo
from std_msgs.msg import String
import numpy as np
import cv2
import sensor_msgs_py.point_cloud2 as pc2
import threading
import time
from sklearn.cluster import DBSCAN
from shapely.geometry import Polygon
import cv_bridge

# -------------------------
# Utility / matching funcs
# -------------------------
def pc2_to_xyz_array(msg: PointCloud2):
    points = []
    for p in pc2.read_points(msg, skip_nans=True, field_names=("x","y","z")):
        points.append([p[0], p[1], p[2]])
    if len(points)==0:
        return np.zeros((0,3))
    return np.array(points)

def cluster_points_dbscan(points, eps=0.05, min_samples=8):
    if points.shape[0] == 0:
        return []
    cl = DBSCAN(eps=eps, min_samples=min_samples).fit(points)
    labels = cl.labels_
    boxes = []
    for lab in set(labels):
        if lab == -1: continue
        pts = points[labels==lab]
        min_xyz = pts.min(axis=0)
        max_xyz = pts.max(axis=0)
        center = (min_xyz + max_xyz) / 2.0
        size = (max_xyz - min_xyz)
        boxes.append({'center':center.tolist(), 'size':size.tolist(), 'yaw':0.0, 'class':'unknown', 'score':1.0})
    return boxes

def make_polygon_from_mask(mask):
    # mask: HxW binary numpy uint8
    contours, _ = cv2.findContours(mask.astype('uint8'), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if len(contours)==0:
        return None
    # take largest contour
    c = max(contours, key=lambda x: cv2.contourArea(x))
    pts = c.squeeze()
    if pts.ndim != 2 or pts.shape[0] < 3:
        return None
    return Polygon(pts)

def bbox_to_polygon(bbox):
    x1,y1,x2,y2 = bbox
    return Polygon([[x1,y1],[x2,y1],[x2,y2],[x1,y2]])

def project_3d_box_to_image(box3, K, T_l2c):
    # box3: dict {center:[X,Y,Z], size:[l,w,h], yaw}
    cx,cy,cz = box3['center']
    l,w,h = box3['size']
    yaw = box3.get('yaw', 0.0)
    # corners (local)
    x_c = np.array([ l/2,  l/2, -l/2, -l/2,  l/2,  l/2, -l/2, -l/2 ])
    y_c = np.array([ w/2, -w/2, -w/2,  w/2,  w/2, -w/2, -w/2,  w/2 ])
    z_c = np.array([ h/2,  h/2,  h/2,  h/2, -h/2, -h/2, -h/2, -h/2 ])
    corners = np.stack([x_c, y_c, z_c], axis=0)
    R = np.array([[np.cos(yaw), -np.sin(yaw), 0],
                  [np.sin(yaw),  np.cos(yaw), 0],
                  [0,0,1]])
    corners_rot = R @ corners
    corners_world = corners_rot + np.array([[cx],[cy],[cz]])
    corners_h = np.vstack([corners_world, np.ones((1,8))])  # 4x8
    corners_cam = T_l2c @ corners_h
    z_vals = corners_cam[2,:]
    if np.any(z_vals <= 0):
        return None, None
    proj = K @ corners_cam[:3,:]
    xs = proj[0,:] / proj[2,:]
    ys = proj[1,:] / proj[2,:]
    poly = Polygon(np.stack([xs, ys], axis=-1))
    centroid = np.array([xs.mean(), ys.mean()])
    return poly, centroid

def poly_iou(poly1, poly2):
    if poly1 is None or poly2 is None: return 0.0
    inter = poly1.intersection(poly2).area
    union = poly1.union(poly2).area
    if union == 0: return 0.0
    return inter/union

# -------------------------
# ROS2 Node
# -------------------------
class LateFusionNode(Node):
    def __init__(self):
        super().__init__('late_fusion_node')
        self.declare_parameter('pc_topic', '/livox/points')
        self.declare_parameter('img_topic', '/camera/color/image_raw')
        self.declare_parameter('depth_topic', '/camera/depth/image_raw')
        self.declare_parameter('camera_info_topic', '/camera/color/camera_info')
        self.pc_topic = self.get_parameter('pc_topic').get_parameter_value().string_value
        self.img_topic = self.get_parameter('img_topic').get_parameter_value().string_value
        self.depth_topic = self.get_parameter('depth_topic').get_parameter_value().string_value
        self.caminfo_topic = self.get_parameter('camera_info_topic').get_parameter_value().string_value

        self.pc_sub = self.create_subscription(PointCloud2, self.pc_topic, self.pc_cb, 10)
        self.img_sub = self.create_subscription(Image, self.img_topic, self.img_cb, 10)
        self.depth_sub = self.create_subscription(Image, self.depth_topic, self.depth_cb, 10)
        self.caminfo_sub = self.create_subscription(CameraInfo, self.caminfo_topic, self.caminfo_cb, 10)

        self.pub_matches = self.create_publisher(String, 'late_fusion/matches', 10)  # simple json text for now

        self.bridge = cv_bridge.CvBridge()
        self.latest_img = None
        self.latest_depth = None
        self.latest_caminfo = None
        self.latest_pc = None
        self.lock = threading.Lock()

        # params
        self.dbscan_eps = 0.06
        self.dbscan_minpts = 8
        self.w_iou = 0.7
        self.w_center = 0.3
        self.iou_min = 0.02
        self.score_thresh = 0.25

        # example LiDAR->cam transform (should be replaced by real calib)
        self.T_l2c = np.eye(4)

        self.get_logger().info('LateFusionNode started, subscribing pc: %s img: %s' % (self.pc_topic, self.img_topic))
        self.timer = self.create_timer(0.5, self.run_matching)  # run at 2 Hz

    def pc_cb(self, msg):
        with self.lock:
            self.latest_pc = msg

    def img_cb(self, msg):
        with self.lock:
            self.latest_img = msg

    def depth_cb(self, msg):
        with self.lock:
            self.latest_depth = msg

    def caminfo_cb(self, msg):
        with self.lock:
            self.latest_caminfo = msg

    def run_matching(self):
        with self.lock:
            if self.latest_pc is None or self.latest_img is None or self.latest_caminfo is None:
                return
            pc_msg = self.latest_pc
            img_msg = self.latest_img
            caminfo = self.latest_caminfo
            depth_msg = self.latest_depth

            # reset latest so we always run fresh
            # (keep them if you prefer)
            self.latest_pc = None
            self.latest_img = None
            self.latest_depth = None
            self.latest_caminfo = None

        # convert camera intrinsics
        K = np.array([[caminfo.k[0], caminfo.k[1], caminfo.k[2]],
                      [caminfo.k[3], caminfo.k[4], caminfo.k[5]],
                      [caminfo.k[6], caminfo.k[7], caminfo.k[8]]])
        # convert image
        try:
            img = self.bridge.imgmsg_to_cv2(img_msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().warn('img convert failed: %s' % str(e))
            return
        H, W = img.shape[:2]

        # pointcloud -> numpy
        pts = pc2_to_xyz_array(pc_msg)
        # cluster to 3D boxes
        boxes3d = cluster_points_dbscan(pts, eps=self.dbscan_eps, min_samples=self.dbscan_minpts)

        # simple 2D detection from depth if depth available (fallback)
        det2_list = []
        if depth_msg is not None:
            try:
                depth = self.bridge.imgmsg_to_cv2(depth_msg, desired_encoding='passthrough')
                # simple foreground by threshold (near objects)
                mask = (depth > 0.3) & (depth < 3.0)
                mask = mask.astype('uint8')*255
                # connected components
                num, labels, stats, centroids = cv2.connectedComponentsWithStats(mask, connectivity=8)
                for i in range(1, num):
                    x,y,w0,h0,area = stats[i]
                    if area < 200: continue
                    x1,y1,x2,y2 = x, y, x+w0, y+h0
                    m = (labels==i).astype('uint8')
                    det2_list.append({'id':i-1, 'class':'unknown', 'bbox':[x1,y1,x2,y2], 'mask':m, 'score':0.8})
            except Exception as e:
                self.get_logger().warn('depth convert failed: %s' % str(e))
        else:
            # no depth: do simple color threshold to detect obstacles (placeholder)
            gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            _, m = cv2.threshold(gray, 10, 255, cv2.THRESH_BINARY)
            det2_list.append({'id':0, 'class':'unknown', 'bbox':[0,0,W-1,H-1], 'mask':m, 'score':0.2})

        # prepare polygons/centroids for det2
        det2_polys = []
        det2_centroids = []
        for det in det2_list:
            if det['mask'] is not None:
                poly = make_polygon_from_mask(det['mask'])
                ys, xs = np.where(det['mask']>0)
                if xs.size==0:
                    centroid = np.array([(det['bbox'][0]+det['bbox'][2])/2, (det['bbox'][1]+det['bbox'][3])/2])
                else:
                    centroid = np.array([xs.mean(), ys.mean()])
            else:
                poly = bbox_to_polygon(det['bbox'])
                x1,y1,x2,y2 = det['bbox']
                centroid = np.array([(x1+x2)/2, (y1+y2)/2])
            det2_polys.append(poly)
            det2_centroids.append(centroid)

        # project 3D boxes
        box3_polys = []
        box3_centroids = []
        for b in boxes3d:
            poly, c = project_3d_box_to_image(b, K, self.T_l2c)
            box3_polys.append(poly)
            box3_centroids.append(c)

        # score pairs
        pairs = []
        for i,b in enumerate(boxes3d):
            if box3_polys[i] is None: continue
            for j,det in enumerate(det2_list):
                iou = poly_iou(box3_polys[i], det2_polys[j])
                if iou < self.iou_min: continue
                d = np.linalg.norm(box3_centroids[i] - det2_centroids[j])
                d_max = np.sqrt(H*H + W*W) / 3.0
                score = self.w_iou * iou + self.w_center * max(0.0, 1.0 - d/d_max)
                pairs.append({'3d_id':i, '2d_id':j, 'score':score, 'iou':iou, 'dist':d})

        # mutual best
        best_3d_to_2d = {}
        best_2d_to_3d = {}
        for p in pairs:
            i,j,s = p['3d_id'], p['2d_id'], p['score']
            if i not in best_3d_to_2d or s > best_3d_to_2d[i][1]:
                best_3d_to_2d[i] = (j,s)
            if j not in best_2d_to_3d or s > best_2d_to_3d[j][1]:
                best_2d_to_3d[j] = (i,s)

        matches = []
        unmatched_3d = set(range(len(boxes3d)))
        unmatched_2d = set(range(len(det2_list)))
        for p in pairs:
            i,j,s = p['3d_id'], p['2d_id'], p['score']
            if best_3d_to_2d[i][0] == j and best_2d_to_3d[j][0] == i and s >= self.score_thresh:
                matches.append({'3d_id':i, '2d_id':j, 'score':s})
                unmatched_3d.discard(i)
                unmatched_2d.discard(j)

        # prepare publish (simple JSON string)
        out = {'matches': matches, 'unmatched_3d': list(unmatched_3d), 'unmatched_2d': list(unmatched_2d)}
        import json
        self.pub_matches.publish(String(data=json.dumps(out)))

        # optional: draw visualization on img and show (for debug)
        vis = img.copy()
        # draw det2 bboxes
        for det in det2_list:
            x1,y1,x2,y2 = det['bbox']
            cv2.rectangle(vis, (int(x1),int(y1)), (int(x2),int(y2)), (0,255,0), 2)
        # draw projected polygons for matched 3D
        for idx, b in enumerate(boxes3d):
            poly = box3_polys[idx]
            if poly is None: continue
            pts = np.array(poly.exterior.coords).astype(int)
            cv2.polylines(vis, [pts], True, (0,0,255), 2)
        cv2.imshow('late_fusion_vis', vis)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = LateFusionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
