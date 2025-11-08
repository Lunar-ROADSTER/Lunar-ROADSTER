#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.duration import Duration
from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import PointStamped
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import numpy as np
from tf2_ros import Buffer, TransformListener
import tf2_geometry_msgs


class DepthProjector:
    """Handles 2D→3D projection using depth image + camera intrinsics."""
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
    """YOLO + ZED-depth crater detector with 2D→3D projection and smoothing."""
    def __init__(self):
        super().__init__('crater_detection_node')

        self.bridge = CvBridge()
        self.projector = DepthProjector()

        # --- Load YOLO model ---
        model_path = '/root/Lunar_ROADSTER/lr_ws/src/perception/perception/best.pt'
        self.model = YOLO(model_path)
        self.get_logger().info(f'Loaded YOLOv8 model from {model_path}')

        # --- TF setup ---
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # --- Publishers & subscribers ---
        self.crater_pub = self.create_publisher(PointStamped, '/crater_detection/point', 10)
        self.sub_rgb = self.create_subscription(Image, '/zed/zed_node/rgb/image_rect_color', self.image_callback, 10)
        self.sub_depth = self.create_subscription(Image, '/zed/zed_node/depth/depth_registered', self.depth_callback, 10)
        self.sub_camera_info = self.create_subscription(CameraInfo, '/zed/zed_node/rgb/camera_info', self.camera_info_callback, 10)

        # --- Detection timing & smoothing ---
        self.start_time = self.get_clock().now()
        self.wait_duration = 3.0  # seconds to wait before stable detections
        self.smoothing_duration = 15.0  # seconds of data collection
        self.detections = []

        self.baseline = 0.12  # m offset from left camera to camera_center

    # ----------------- Callbacks -----------------
    def camera_info_callback(self, msg):
        self.projector.update_intrinsics(msg)

    def depth_callback(self, msg):
        self.projector.update_depth(msg, self.bridge)

    def image_callback(self, msg):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            annotated = frame.copy()

            results = self.model(frame, verbose=False)[0]
            now = self.get_clock().now()
            elapsed = (now - self.start_time).nanoseconds / 1e9

            crater_coords = None
            for box, conf in zip(results.boxes.xyxy, results.boxes.conf):
                if conf < 0.6:
                    continue

                x1, y1, x2, y2 = map(int, box)
                cx, cy = int((x1 + x2) / 2), int((y1 + y2) / 2)
                point_3d = self.projector.pixel_to_camera(cx, cy)
                if point_3d is None:
                    continue

                X, Y, Z = point_3d
                # Offset for camera_center
                X_center = X + self.baseline / 2
                Y_center = Y
                Z_center = Z

                # Diameter in meters
                diameter = (x2 - x1) * Z_center / self.projector.fx

                # Only record stable detections after wait_duration
                if elapsed > self.wait_duration:
                    self.detections.append([X_center, Y_center, Z_center, diameter])

                crater_coords = (X_center, Y_center, Z_center, diameter)

                # Publish crater center
                crater_msg = PointStamped()
                crater_msg.header.stamp = now.to_msg()
                crater_msg.header.frame_id = "zed_camera_center"
                crater_msg.point.x = X_center
                crater_msg.point.y = Y_center
                crater_msg.point.z = Z_center
                self.crater_pub.publish(crater_msg)

                # Transform to base_link
                try:
                    transform = self.tf_buffer.lookup_transform(
                        'base_link', 'zed_camera_center', rclpy.time.Time())
                    crater_msg_base = tf2_geometry_msgs.do_transform_point(crater_msg, transform)
                    Xb, Yb, Zb = (crater_msg_base.point.x,
                                  crater_msg_base.point.y,
                                  crater_msg_base.point.z)
                except Exception as e:
                    Xb = Yb = Zb = None
                    self.get_logger().warn(f"No transform available")

                # --- Draw overlay ---
                cv2.rectangle(annotated, (x1, y1), (x2, y2), (0, 255, 0), 1)
                line_y = cy
                cv2.line(annotated, (x1, line_y), (x2, line_y), (255, 0, 0), 1)
                cv2.drawMarker(annotated, (cx, cy), (0, 0, 255),
                               markerType=cv2.MARKER_CROSS, markerSize=8, thickness=2)
                cv2.putText(annotated,
                            f"Cam: X:{X_center:.2f} Y:{Y_center:.2f} Z:{Z_center:.2f} D:{diameter:.2f}m",
                            (10, 25), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255,255,255), 2)
                if Xb is not None:
                    cv2.putText(annotated,
                                f"Base: X:{Xb:.2f} Y:{Yb:.2f} Z:{Zb:.2f}",
                                (10, 50), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0,255,0), 2)

            # --- After 15 s, show smoothed coordinates ---
            if elapsed > self.wait_duration + self.smoothing_duration and len(self.detections) > 0:
                mean_vals = np.mean(self.detections, axis=0)
                Xs, Ys, Zs, Ds = mean_vals
                cv2.putText(annotated,
                            f"Smoothed: X:{Xs:.2f} Y:{Ys:.2f} Z:{Zs:.2f} D:{Ds:.2f}m",
                            (10, 80), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0,255,255), 2)

            cv2.imshow("Crater Detection with Diameter", annotated)
            cv2.waitKey(1)

        except Exception as e:
            self.get_logger().error(f"Error in image_callback: {e}")


def main(args=None):
    rclpy.init(args=args)
    node = CraterDetectionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down Crater Detection Node...")
    finally:
        node.destroy_node()
        cv2.destroyAllWindows()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
