#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import PointStamped
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import numpy as np

from perception.action import CraterDetect


class CraterDetectionNode(Node):
    def __init__(self):
        super().__init__('crater_detection_node')

        self.bridge = CvBridge()
        self.projector = DepthProjector()

        # Load YOLO
        model_path = '/root/Lunar_ROADSTER/lr_ws/src/perception/perception/best.pt'
        self.model = YOLO(model_path)
        self.get_logger().info(f'Loaded YOLOv8 model from {model_path}')

        # Publisher for crater points
        self.crater_pub = self.create_publisher(PointStamped, '/crater_detection/point', 10)

        # Action server
        self._action_server = ActionServer(
            self,
            CraterDetect,
            'detect_crater',
            self.execute_callback
        )

        # Subscriptions (created dynamically when detection starts)
        self.sub_rgb = None
        self.sub_depth = None
        self.sub_camera_info = None
        self.active = False

    async def execute_callback(self, goal_handle):
        """Triggered when FSM sends a start_detection goal."""
        self.active = True
        self.get_logger().info("Crater detection activated.")
        feedback = CraterDetect.Feedback()

        # Subscribe dynamically
        if self.sub_rgb is None:
            self.sub_rgb = self.create_subscription(Image, '/zed/zed_node/rgb/image_rect_color', self.image_callback, 10)
            self.sub_depth = self.create_subscription(Image, '/zed/zed_node/depth/depth_registered', self.depth_callback, 10)
            self.sub_camera_info = self.create_subscription(CameraInfo, '/zed/zed_node/rgb/camera_info', self.camera_info_callback, 10)

        # Run detection for ~10 seconds or until canceled
        start_time = self.get_clock().now().seconds_nanoseconds()[0]
        num_craters = 0
        while rclpy.ok() and self.active:
            # Send feedback (optional)
            feedback.num_craters_detected = num_craters
            goal_handle.publish_feedback(feedback)

            await rclpy.sleep(0.5)

            # Timeout after 15 seconds
            if self.get_clock().now().seconds_nanoseconds()[0] - start_time > 15:
                break

        # Wrap up
        self.deactivate_subscribers()
        result = CraterDetect.Result()
        result.success = True
        result.message = f"Crater detection finished with {num_craters} detections."
        goal_handle.succeed()
        self.get_logger().info(result.message)
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

                # Estimate diameter
                u_left, u_right = x1, x2
                diameter = (u_right - u_left) * Z_center / self.projector.fx

                # 🟢 Publish crater info as PointStamped
                crater_msg = PointStamped()
                crater_msg.header.stamp = self.get_clock().now().to_msg()
                crater_msg.header.frame_id = f"{diameter:.3f}"  # encode diameter in frame_id
                crater_msg.point.x = X_center
                crater_msg.point.y = Y_center
                crater_msg.point.z = Z_center
                self.crater_pub.publish(crater_msg)

                self.get_logger().info(
                    f"Published crater -> X:{X_center:.2f}, Y:{Y_center:.2f}, Z:{Z_center:.2f}, D:{diameter:.2f}m"
                )

                # Annotate for visualization
                cv2.rectangle(annotated, (x1, y1), (x2, y2), (0, 255, 0), 1)
                crater_texts.append(f"X:{X_center:.2f} Y:{Y_center:.2f} Z:{Z_center:.2f} D:{diameter:.2f}m")

            for i, text in enumerate(crater_texts):
                cv2.putText(annotated, text, (10, 20 + i * 20),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2, cv2.LINE_AA)
            cv2.imshow("Crater Detection", annotated)
            cv2.waitKey(1)

        except Exception as e:
            self.get_logger().error(f'Error in image_callback: {e}')


def main(args=None):
    rclpy.init(args=args)
    node = CraterDetectionNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
