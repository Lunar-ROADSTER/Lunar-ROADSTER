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

        # Load YOLOv8 model
        model_path = 'best.pt'  # TODO: update this path
        self.model = YOLO(model_path)
        self.get_logger().info(f'Loaded YOLOv8 model from {model_path}')

        # Subscribe to ZED2i RGB topic
        self.subscription = self.create_subscription(
            Image,
            '/zed/zed_node/rgb/image_rect_color',
            self.image_callback,
            10
        )
        self.subscription  # prevent unused variable warning

    def image_callback(self, msg):
        # Convert ROS Image to OpenCV image
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

        # Run YOLO inference
        results = self.model(frame, verbose=False)[0]

        # Draw detections on the image
        annotated_frame = results.plot()

        # Display result
        cv2.imshow('Crater Detection', annotated_frame)
        cv2.waitKey(1)

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
