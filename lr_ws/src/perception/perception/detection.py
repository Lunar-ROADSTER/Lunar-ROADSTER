#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import PointStamped
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import numpy as np
import time

from lr_msgs.action import CraterDetect
from tf2_ros import Buffer, TransformListener
import tf_transformations
from lr_msgs.msg import CraterStamped


import numpy as np
import cv2
from sensor_msgs.msg import CameraInfo, Image
import asyncio
import time

class DepthProjector:
    """Utility class to project 2D image pixels to 3D camera coordinates."""

    def __init__(self):
        self.fx = None
        self.fy = None
        self.cx = None
        self.cy = None
        self.depth_image = None
        self.depth_timestamp = None

    def update_intrinsics(self, camera_info_msg: CameraInfo):
        """Extract and store camera intrinsics from CameraInfo."""
        K = camera_info_msg.k
        self.fx = K[0]
        self.fy = K[4]
        self.cx = K[2]
        self.cy = K[5]

    def update_depth(self, depth_msg: Image, bridge):
        """Convert ROS depth image to numpy array and store."""
        try:
            depth_image = bridge.imgmsg_to_cv2(depth_msg, desired_encoding='passthrough')
            if depth_image is not None:
                self.depth_image = np.nan_to_num(depth_image, nan=0.0)
                self.depth_timestamp = depth_msg.header.stamp
        except Exception as e:
            print(f"[DepthProjector] Failed to convert depth image: {e}")

    def pixel_to_camera(self, u, v):
        """Project pixel (u, v) and depth to 3D (X, Y, Z) in camera frame."""
        if self.depth_image is None:
            return None
        if self.fx is None or self.fy is None or self.cx is None or self.cy is None:
            return None
        
        if v >= self.depth_image.shape[0] or u >= self.depth_image.shape[1]:
            return None

        Z = float(self.depth_image[v, u])  # depth in meters
        if Z <= 0.0:
            return None

        X = (u - self.cx) * Z / self.fx
        Y = (v - self.cy) * Z / self.fy
        return X, Y, Z


class CraterDetectionNode(Node):
    
    def transform_point(self, x, y, z, from_frame='zed_camera_center', to_frame='map'):
        try:
            # Lookup the latest available transform
            trans = self.tf_buffer.lookup_transform(
                to_frame,
                from_frame,
                rclpy.time.Time()
            )

            # Extract translation and rotation
            t = trans.transform.translation
            q = trans.transform.rotation
            rot_matrix = tf_transformations.quaternion_matrix([q.x, q.y, q.z, q.w])

            # Apply transform
            point = np.array([x, y, z, 1.0])
            translation = np.array([t.x, t.y, t.z])
            transformed = rot_matrix.dot(point)
            transformed[:3] += translation
            return transformed[0], transformed[1], transformed[2]
        except Exception as e:
            self.get_logger().warn(f"Transform lookup failed: {e}")
            return None
        
    def __init__(self):
        super().__init__('crater_detection_node')

        self.bridge = CvBridge()
        self.projector = DepthProjector()
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)


        # Parameters
        self.declare_parameter('filter_type', 'mean')  # mean or median
        self.filter_type = self.get_parameter('filter_type').get_parameter_value().string_value
        self.get_logger().info(f"Filter type: {self.filter_type}")

        # Load YOLO model
        model_path = '/root/Lunar_ROADSTER/lr_ws/src/perception/perception/best.pt'
        self.model = YOLO(model_path)
        self.get_logger().info(f'Loaded YOLOv8 model from {model_path}')

        # QoS with latched behavior (so data stays alive for planner to read)
        qos_profile = QoSProfile(
            depth=1,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL
        )

        # Publisher for crater point
        self.crater_pub = self.create_publisher(CraterStamped, '/crater_detection/crater', qos_profile)

        # Action server
        self._action_server = ActionServer(
            self,
            CraterDetect,
            'detect_crater',
            self.execute_callback
        )

        # Subscriptions
        self.sub_rgb = None
        self.sub_depth = None
        self.sub_camera_info = None
        self.active = False

        # Data buffers
        self.xs, self.ys, self.zs, self.ds = [], [], [], []
        self.last_confidence_time = None
        self.has_stable_detection = False

    def execute_callback(self, goal_handle):
        """Triggered by FSM via action goal."""
        self.xs, self.ys, self.zs, self.ds = [], [], [], []
        self.active = True
        self.get_logger().info("Crater detection activated.")
        feedback = CraterDetect.Feedback()

        # Dynamic subscription
        if self.sub_rgb is None:
            self.sub_rgb = self.create_subscription(Image, '/zed/zed_node/rgb/image_rect_color', self.image_callback, 10)
            self.sub_depth = self.create_subscription(Image, '/zed/zed_node/depth/depth_registered', self.depth_callback, 10)
            self.sub_camera_info = self.create_subscription(CameraInfo, '/zed/zed_node/rgb/camera_info', self.camera_info_callback, 10)

        # 1️⃣ Wait for stable detection (conf > 0.7 for ≥ 3s)
        self.get_logger().info("Waiting for stable detection (≥0.70 confidence for 3s)...")
        stable_start = None
        while rclpy.ok() and self.active:
            if self.has_stable_detection:
                if stable_start is None:
                    stable_start = time.time()
                elif time.time() - stable_start >= 3.0:
                    self.get_logger().info("Stable detection achieved.")
                    break
            else:
                stable_start = None
            time.sleep(0.1)

        if not self.has_stable_detection:
            self.get_logger().warn("No stable detection found. Exiting action.")
            result = CraterDetect.Result()
            result.success = False
            result.message = "No stable crater detected."
            goal_handle.succeed()
            self.deactivate_subscribers()
            return result

        # 2️⃣ Collect for 15 seconds
        self.get_logger().info("Collecting crater data for 15 seconds...")
        start_collect = time.time()
        while rclpy.ok() and self.active:
            feedback.num_craters_detected = len(self.xs)
            goal_handle.publish_feedback(feedback)
            if time.time() - start_collect >= 15.0:
                break
            time.sleep(0.1)


        

        # 3️⃣ Apply filtering
        if len(self.xs) == 0:
            self.get_logger().warn("No crater data collected during 15 seconds.")
            result = CraterDetect.Result()
            result.success = False
            result.message = "No crater data collected."
            goal_handle.succeed()
            self.deactivate_subscribers()
            return result

        if self.filter_type == 'median':
            X, Y, Z, D = np.median(self.xs), np.median(self.ys), np.median(self.zs), np.median(self.ds)
        else:
            X, Y, Z, D = np.mean(self.xs), np.mean(self.ys), np.mean(self.zs), np.mean(self.ds)

                # Transform to world (map) frame
        transformed = self.transform_point(X, Y, Z, from_frame='zed_camera_center', to_frame='map')
        if transformed is not None:
            X, Y, Z = transformed
        else:
            self.get_logger().warn("Could not transform crater point to map frame, using camera frame.")


        # 4️⃣ Publish averaged crater point
        crater_msg = CraterStamped()
        crater_msg.header.stamp = self.get_clock().now().to_msg()
        crater_msg.header.frame_id = 'map'  # since you transformed to world frame
        crater_msg.position.x = float(X)
        crater_msg.position.y = float(Y)
        crater_msg.position.z = float(Z)
        crater_msg.diameter = float(D)

        self.crater_pub.publish(crater_msg)
        self.get_logger().info(f"Published crater in map frame -> "
                            f"X:{X:.2f}, Y:{Y:.2f}, Z:{Z:.2f}, Diameter:{D:.2f}m")

        # 5️⃣ Cleanup
        self.deactivate_subscribers()
        result = CraterDetect.Result()
        result.success = True
        result.message = "Crater detection finished successfully."
        goal_handle.succeed()
        return result

    def deactivate_subscribers(self):
        self.active = False
        self.get_logger().info("Deactivating crater detection subscribers.")

        if self.sub_rgb is not None:
            self.destroy_subscription(self.sub_rgb)
            self.sub_rgb = None

        if self.sub_depth is not None:
            self.destroy_subscription(self.sub_depth)
            self.sub_depth = None

        if self.sub_camera_info is not None:
            self.destroy_subscription(self.sub_camera_info)
            self.sub_camera_info = None

    def camera_info_callback(self, msg):
        if self.active:
            self.projector.update_intrinsics(msg)

    def depth_callback(self, msg):
        if self.active:
            self.projector.update_depth(msg, self.bridge)

    def image_callback(self, msg):
        if not self.active:
            return

        try:
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            results = self.model(frame, verbose=False)[0]

            if len(results.boxes) == 0:
                self.has_stable_detection = False
                return

            for box, conf in zip(results.boxes.xyxy, results.boxes.conf):
                confidence = float(conf)
                if confidence < 0.7:
                    self.has_stable_detection = False
                    continue

                # Mark stable detection if we see ≥0.7 confidence consistently
                self.has_stable_detection = True

                # Get coordinates and project
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
                diameter = (x2 - x1) * Z_center / self.projector.fx

                # Store for filtering
                self.xs.append(X_center)
                self.ys.append(Y_center)
                self.zs.append(Z_center)
                self.ds.append(diameter)

        except Exception as e:
            self.get_logger().error(f'Error in image_callback: {e}')


def main(args=None):
    rclpy.init(args=args)
    node = CraterDetectionNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
