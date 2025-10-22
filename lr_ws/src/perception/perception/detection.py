#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import PointStamped
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import numpy as np

class DepthProjector:
    def __init__(self):
        self.fx = self.fy = self.cx = self.cy = None
        self.depth_frame = None

    def update_intrinsics(self, camera_info):
        self.fx = camera_info.k[0]
        self.fy = camera_info.k[4]
        self.cx = camera_info.k[2]
        self.cy = camera_info.k[5]

    def update_depth(self, depth_img_msg, bridge):
        self.depth_frame = bridge.imgmsg_to_cv2(depth_img_msg, desired_encoding='passthrough')

    def pixel_to_camera(self, u, v):
        if self.depth_frame is None or self.fx is None:
            return None
        if v < 0 or v >= self.depth_frame.shape[0] or u < 0 or u >= self.depth_frame.shape[1]:
            return None
        Z = float(self.depth_frame[v, u])
        if np.isnan(Z) or Z <= 0.0:
            return None
        X = (u - self.cx) * Z / self.fx
        Y = (v - self.cy) * Z / self.fy
        return np.array([X, Y, Z])

class CraterDetectionNode(Node):
    def __init__(self):
        super().__init__('crater_detection_node')

        self.bridge = CvBridge()
        self.projector = DepthProjector()

        # Load YOLO model
        model_path = '/root/Lunar_ROADSTER/lr_ws/src/perception/perception/best.pt'
        self.model = YOLO(model_path)
        self.get_logger().info(f'Loaded YOLOv8 model from {model_path}')

        # ROS2 Publishers
        self.crater_pub = self.create_publisher(PointStamped, '/crater_detection/point', 10)

        # Subscriptions
        self.sub_rgb = self.create_subscription(Image, '/zed/zed_node/rgb/image_rect_color', self.image_callback, 10)
        self.sub_depth = self.create_subscription(Image, '/zed/zed_node/depth/depth_registered', self.depth_callback, 10)
        self.sub_camera_info = self.create_subscription(CameraInfo, '/zed/zed_node/rgb/camera_info', self.camera_info_callback, 10)

    def camera_info_callback(self, msg):
        self.projector.update_intrinsics(msg)

    def depth_callback(self, msg):
        self.projector.update_depth(msg, self.bridge)

    def image_callback(self, msg):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            annotated = frame.copy()
            crater_texts = []

            results = self.model(frame, verbose=False)[0]

            for box in results.boxes.xyxy:
                x1, y1, x2, y2 = map(int, box)
                cx, cy = int((x1 + x2) / 2), int((y1 + y2) / 2)

                point_3d = self.projector.pixel_to_camera(cx, cy)
                if point_3d is None:
                    continue
                X, Y, Z = point_3d
                baseline = 0.12
                X_center = X + baseline / 2
                Y_center = Y
                Z_center = Z

                # Diameter estimation (along X-axis)
                u_left, u_right = x1, x2
                diameter = (u_right - u_left) * Z_center / self.projector.fx

                # Publish crater center and diameter
                crater_msg = PointStamped()
                crater_msg.header.stamp = self.get_clock().now().to_msg()
                crater_msg.header.frame_id = f"{diameter:.3f}"  # encode diameter here
                crater_msg.point.x = X_center
                crater_msg.point.y = Y_center
                crater_msg.point.z = Z_center
                self.crater_pub.publish(crater_msg)

                self.get_logger().info(
                    f"Published crater -> X:{X_center:.2f}, Y:{Y_center:.2f}, Z:{Z_center:.2f}, D:{diameter:.2f}m"
                )

                # Draw visual aids
                cv2.rectangle(annotated, (x1, y1), (x2, y2), (0, 255, 0), 1)
                line_y = cy
                cv2.line(annotated, (x1, line_y), (x2, line_y), (255, 0, 0), 1)
                crater_texts.append(f"X:{X_center:.2f} Y:{Y_center:.2f} Z:{Z_center:.2f} D:{diameter:.2f}m")

            for i, text in enumerate(crater_texts):
                cv2.putText(annotated, text, (10, 20 + i * 20),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2, cv2.LINE_AA)

            cv2.imshow("Crater Detection with Diameter", annotated)
            cv2.waitKey(1)

        except Exception as e:
            self.get_logger().error(f'Error in image_callback: {e}')


def main(args=None):
    rclpy.init(args=args)
    node = CraterDetectionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
