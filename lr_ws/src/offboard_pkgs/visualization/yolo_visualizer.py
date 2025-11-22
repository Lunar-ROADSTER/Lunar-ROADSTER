#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import torch
from ultralytics import YOLO
import threading
import queue
import numpy as np

class YOLOStreamer(Node):
    def __init__(self):
        super().__init__('yolo_streamer')

        # ---- YOLO model (CPU mode) ----
        self.model = YOLO('./best.pt')

        if torch.cuda.is_available():
            self.get_logger().info("CUDA detected! Using GPU mode.")
            self.model.to('cuda')
        else:
            self.get_logger().info("CUDA not detected. Using CPU mode.")
            self.model.to('cpu')

        self.bridge = CvBridge()

        # ---- Thread-safe queue for frames ----
        self.frame_queue = queue.Queue(maxsize=2)

        # ---- Subscriber & Publisher ----
        self.sub = self.create_subscription(
            Image,
            '/zed/zed_node/rgb/image_rect_color',
            self.image_callback,
            10)

        self.pub = self.create_publisher(Image, '/viz/yolo_feed', 10)

        # ---- Start worker thread ----
        self.worker = threading.Thread(target=self.yolo_worker, daemon=True)
        self.worker.start()

        self.get_logger().info("YOLO streamer node ready!")

    def image_callback(self, msg):
        """Receive frames as fast as they arrive."""
        try:
            cv_frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

            # Drop old frames if queue full → keeps system real-time
            if not self.frame_queue.full():
                self.frame_queue.put(cv_frame)
        except Exception as e:
            self.get_logger().error(f"image_callback error: {e}")

    def yolo_worker(self):
        """Thread: consumes frames & runs YOLO."""
        while True:
            frame = self.frame_queue.get()
            if frame is None:
                continue

            try:
                # ---- YOLO ----
                results = self.model(frame, verbose=False)[0]

                annotated = frame.copy()
                for box, conf in zip(results.boxes.xyxy, results.boxes.conf):
                    x1, y1, x2, y2 = map(int, box)
                    cv2.rectangle(annotated, (x1, y1), (x2, y2), (0,255,0), 2)
                    cv2.putText(
                        annotated,
                        f"{float(conf):.2f}",
                        (x1, y1 - 5),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        0.5,
                        (0,255,0),
                        2
                    )

                # ---- Publish YOLO annotated image ----
                msg_out = self.bridge.cv2_to_imgmsg(annotated, encoding="bgr8")
                self.pub.publish(msg_out)
                self.get_logger().info("Published YOLO annotated frame.")

            except Exception as e:
                print(f"YOLO worker error: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = YOLOStreamer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()

if __name__ == '__main__':
    main()
