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

from perception.action import CraterDetect


class CraterDetectionNode(Node):
    def __init__(self):
        super().__init__('crater_detection_node')

        self.bridge = CvBridge()
        self.projector = DepthProjector()

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
        self.crater_pub = self.create_publisher(PointStamped, '/crater_detection/point', qos_profile)

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

    async def execute_callback(self, goal_handle):
        """Triggered by FSM via action goal."""
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
            await rclpy.sleep(0.1)

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
            await rclpy.sleep(0.1)

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

        # 4️⃣ Publish averaged crater point
        crater_msg = PointStamped()
        crater_msg.header.stamp = self.get_clock().now().to_msg()
        crater_msg.header.frame_id = f"{D:.3f}"
        crater_msg.point.x = X
        crater_msg.point.y = Y
        crater_msg.point.z = Z
        self.crater_pub.publish(crater_msg)
        self.get_logger().info(f"Published filtered crater -> X:{X:.2f}, Y:{Y:.2f}, Z:{Z:.2f}, D:{D:.2f}m")

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
        self.sub_rgb = None
        self.sub_depth = None
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
