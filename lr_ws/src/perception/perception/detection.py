#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import numpy as np

class CraterDetectionNode(Node):
    def __init__(self):
        super().__init__('crater_detection_node')

        # Initialize CV bridge
        self.bridge = CvBridge()

        # Load YOLOv8 model on GPU if available
        model_path = '/root/Lunar_ROADSTER/lr_ws/src/perception/perception/best.pt'
        self.model = YOLO(model_path)  # use device='cuda:0' if GPU is available
        self.get_logger().info(f'Loaded YOLOv8 model from {model_path}')

        # Subscribe to ZED2i RGB topic
        self.subscription = self.create_subscription(
            Image,
            '/zed/zed_node/rgb/image_rect_color',
            self.image_callback,
            10  # QoS depth
        )
        self.subscription  # prevent unused variable warning

    def image_callback(self, msg):
        try:
            # Convert ROS Image to OpenCV image
            frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

            # Optional: resize to speed up inference (comment out if you want full-res)
            scale_factor = 0.5  # reduce resolution by 50%
            frame_small = cv2.resize(frame, (0, 0), fx=scale_factor, fy=scale_factor)

            # Run YOLO inference
            results = self.model(frame_small, verbose=False)[0]

            # Draw bounding boxes and crosshairs manually
            annotated_frame = frame_small.copy()
            for box in results.boxes.xyxy:  # xyxy = [x1, y1, x2, y2]
                x1, y1, x2, y2 = map(int, box)
                # Draw bounding box
                cv2.rectangle(annotated_frame, (x1, y1), (x2, y2), (0, 255, 0), 2)

                # Compute midpoint
                cx = int((x1 + x2) / 2)
                cy = int((y1 + y2) / 2)

                # Draw crosshair
                size = 5  # half-length of crosshair lines
                cv2.line(annotated_frame, (cx - size, cy), (cx + size, cy), (0, 0, 255), 2)
                cv2.line(annotated_frame, (cx, cy - size), (cx, cy + size), (0, 0, 255), 2)

            # Display the annotated frame
            cv2.imshow('Crater Detection', annotated_frame)
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
