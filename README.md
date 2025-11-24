关于机器狗的定位导航算法


点云使用 sensor_msgs/PointCloud2 → 转 NumPy → DBSCAN 聚类生成 3D boxes（简单轴对齐包围盒）

2D 检测临时用深度图做阈值分割 + connected components 生成 masks & bboxes（如果已有 Detectron2 输出，只需把其 detections 转成 det2_list）

投影使用 camera_info 的 K + T_l2c（当前节点里 T_l2c 用单位矩阵占位，真实工程应用真实标定外参替换）

匹配逻辑与之前方案一致：mask/bbox IoU + centroid 距离加权 → 双向 mutual → uncertainty（unmatched）

输出通过 /late_fusion/matches（String JSON）发布，方便上层消费。也可以改为自定义消息。
