import numpy as np
import cv2

# ============ 1. Input: camera intrinsics (from your JSON) ============
fx = 962.946
fy = 962.946
cx = 965.923
cy = 534.936

K = np.array([
    [fx, 0,  cx],
    [0,  fy, cy],
    [0,  0,   1]
])

# ============ 2. Input: T_l2c you are using in fusion_node.py ============
# Example (你需要替换成你 node 里的 T_l2c)
T_l2c = np.eye(4)
# 例如你之前 baseline= -49.86 mm → 约 -0.04986 m，若左相机参考：
T_l2c[0, 3] = -0.04986  # 举例，记得替换成你的版本

# ============ 3. Test 3D point (Lidar frame) ============
# Example point (手动给一个，你也可以替换为点云里的一个)
P_lidar = np.array([1.0, 0.0, 1.0])   # (x=1m, y=0, z=1m)
P_lidar_h = np.hstack([P_lidar, 1.0])

# ============ 4. Transform Lidar → Camera =============
P_cam = T_l2c @ P_lidar_h
Xc, Yc, Zc = P_cam[:3]

print("Camera-frame point:", P_cam[:3])

if Zc <= 0:
    print("⚠️ 该点在相机后方（Z<=0），无法投影！")
    exit()

# ============ 5. Project to 2D =============
px = fx * (Xc / Zc) + cx
py = fy * (Yc / Zc) + cy

print(f"Projected pixel = ({px:.2f}, {py:.2f})")

# ============ 6. Check if the pixel is inside the image ============
w, h = 1920, 1080

if 0 <= px < w and 0 <= py < h:
    print("✅ 点成功投影到图像内部")
else:
    print("❌ 投影点落在图像外，外参可能有问题")
