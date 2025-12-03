#!/usr/bin/env python3
"""
================================================================================
CRATER DETECTION NODE (ROS2)
================================================================================

Version: 1.0.0
Date   : 2025-12-02
--------------------------------------------------------------------------------

Maintainer: Deepam Ameria, Ankit Aggarwal 
Contributors: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu  
Team: Lunar ROADSTER
 
Node  : crater_detection_node_ankit
Desc  : 
    Performs real-time crater detection using YOLOv8 on ZED RGB + depth data.
    Projects 2D detections to 3D using depth and camera intrinsics, transforms
    crater coordinates to the map frame, smooths detections over time, and
    publishes:
        - Crater centroid (CraterStamped)
        - RViz visualization marker
        - Annotated RGB debugging image

    Activated through an action server (detect_crater). The state machine sends
    a goal to trigger detection, wait for stable detections, collect samples,
    filter them, and return final averaged crater coordinates.

--------------------------------------------------------------------------------
SUBSCRIBERS
--------------------------------------------------------------------------------
1. /zed/zed_node/rgb/image_rect_color  (sensor_msgs/Image)
2. /zed/zed_node/depth/depth_registered (sensor_msgs/Image)
3. /zed/zed_node/rgb/camera_info        (sensor_msgs/CameraInfo)

Subscribers are activated only during an action request and destroyed after
completion to reduce CPU/GPU usage.

--------------------------------------------------------------------------------
PUBLISHERS
--------------------------------------------------------------------------------
1. /crater_detection/crater     (lr_msgs/CraterStamped)
2. /crater_detection/marker     (visualization_msgs/Marker)
3. /crater_detection/annotated  (sensor_msgs/Image)

--------------------------------------------------------------------------------
ACTION SERVER
--------------------------------------------------------------------------------
Action Name: detect_crater  
Action Type: lr_msgs/action/CraterDetect

Workflow:
    1. Wait for stable >0.7 conf crater detection for ≥ 3 sec.
    2. Collect (X, Y, Z, diameter) samples for 15 sec.
    3. Apply mean/median filter.
    4. Transform crater point to map frame.
    5. Publish CraterStamped + RViz marker.
    6. Shutdown subscribers.

--------------------------------------------------------------------------------
UTILITIES / INTERNAL MODULES
--------------------------------------------------------------------------------
• YOLOv8 model inference on GPU
• DepthProjector 
      - Manages camera intrinsics
      - Converts (u, v) pixel to 3D point
• TF2 transform handling (camera → map)
• GPU memory cleanup + warmup
• Smoothing, filtering, confidence gating
• Annotated image visualization

--------------------------------------------------------------------------------
NOTES
--------------------------------------------------------------------------------
- Designed for Jetson Orin (JetPack 6.1, CUDA 12.6)
- Ensure ZED node publishes synchronized RGB + depth
- Requires best.pt YOLO weights placed at configured path

================================================================================
"""

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
import torch
from lr_msgs.action import CraterDetect
from tf2_ros import Buffer, TransformListener
import tf_transformations
from lr_msgs.msg import CraterStamped
from visualization_msgs.msg import Marker
import gc

import pdb


import threading

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
    
    def transform_point(self, x, y, z, from_frame='zed_camera_link', to_frame='map'):
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
        super().__init__('crater_detection_node_ankit')
        
        torch.cuda.empty_cache()
        gc.collect()

        self.bridge = CvBridge()
        self.projector = DepthProjector()
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.current_frame_detections = []
        self.marker_pub = self.create_publisher(Marker, '/crater_detection/marker', 10)
        self.annotated_pub = self.create_publisher(Image, "/crater_detection/annotated", 10)


        self.clock = self.get_clock()

        self.device = 'cuda'
        self.first_inference = True
        
        # --- Load YOLO model ---
        model_path = '/root/Lunar_ROADSTER/lr_ws/src/perception/perception/best.pt'
        self.model = YOLO(model_path)
        # self.model.model.half()
        self.model.to(self.device)
        self.get_logger().info( f'Loaded YOLOv8 model from {model_path}')
        # self.model.model.is_fused = lambda *args, **kwargs: True
        torch.cuda.empty_cache()
        gc.collect()

        self.sub_rgb = self.create_subscription(Image, '/zed/zed_node/rgb/image_rect_color', self.image_callback, 10)
        self.sub_depth = self.create_subscription(Image, '/zed/zed_node/depth/depth_registered', self.depth_callback, 10)
        self.sub_camera_info = self.create_subscription(CameraInfo, '/zed/zed_node/rgb/camera_info', self.camera_info_callback, 10)

        # --- Detection timing & smoothing ---
        self.start_time = self.get_clock().now()
        self.wait_duration = 3.0  # seconds to wait before stable detections
        self.smoothing_duration = 15.0  # seconds of data collection
        self.detections = []

        self.baseline = 0.12  # m offset from left camera to camera_center
        self.threshold_value = 0.1

        # Parameters
        self.declare_parameter('filter_type', 'mean')  # mean or median
        self.filter_type = self.get_parameter('filter_type').get_parameter_value().string_value
        self.get_logger().info( f"Filter type: {self.filter_type}")


        # QoS with latched behavior (so data stays alive for planner to read)
        qos_profile = QoSProfile(
            depth=1,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE
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


        self.active = False

        # Data buffers
        self.xs, self.ys, self.zs, self.ds = [], [], [], []
        self.last_confidence_time = None
        self.has_stable_detection = False

    def execute_callback(self, goal_handle):
        """Triggered by FSM via action goal."""
        self.xs, self.ys, self.zs, self.ds = [], [], [], []
        self.active = True
        self.get_logger().info( "Crater detection activated.")
        feedback = CraterDetect.Feedback()

        # Dynamic subscription
        if self.sub_rgb is None:
            self.sub_rgb = self.create_subscription(Image, '/zed/zed_node/rgb/image_rect_color', self.image_callback, 10)
            self.sub_depth = self.create_subscription(Image, '/zed/zed_node/depth/depth_registered', self.depth_callback, 10)
            self.sub_camera_info = self.create_subscription(CameraInfo, '/zed/zed_node/rgb/camera_info', self.camera_info_callback, 10)

        # 1️⃣ Wait for stable detection (conf > 0.7 for ≥ 3s)
        self.get_logger().info("Waiting for stable detection (≥0.7 confidence for 3s)...")
        stable_start = None
        while rclpy.ok() and self.active:
            rclpy.spin_once(self, timeout_sec=0.1)  # <-- allow callbacks!
            if self.has_stable_detection:
                if stable_start is None:
                    stable_start = time.time()
                elif time.time() - stable_start >= 3.0:
                    self.get_logger().info( "Stable detection achieved.")
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
            feedback.num_craters_detected = len(self.current_frame_detections)
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


        self.get_logger().info(f"Crater Point in Camera Frame -> X: {X:.3f}, Y: {Y:.3f}, Z: {Z:.3f}, Diameter: {D:.3f}m")
                # Transform to world (map) frame
        transformed = self.transform_point(X, Y, Z, from_frame='zed_camera_link', to_frame='map')
        if transformed is not None:
            X_base, Y_base, Z_base = transformed
            Z_base = 0.0
            Y_base = Y_base - 0.35
            X_base = X_base - 0.20
        else:
            self.get_logger().warn("Could not transform crater point to map frame, using camera frame.")

        transformed_map = self.transform_point(X, Y, Z,
                                   from_frame='zed_camera_link',
                                   to_frame='map')
        if transformed_map is not None:
            X_map, Y_map, Z_map = transformed_map
            self.get_logger().info( 
                f"[CRATER DEBUG] Map Frame Coordinates -> "
                f"X: {X_map:.3f}, Y: {Y_map:.3f}, Z: {Z_map:.3f}"
            )
        else:
            self.get_logger().warn("Transform to map frame failed. Using camera frame values.")




        # 4️⃣ Publish averaged crater point
        crater_msg = CraterStamped()
        crater_msg.header.stamp = self.get_clock().now().to_msg()
        crater_msg.header.frame_id = 'map' 
        crater_msg.point.x = float(X_base)
        crater_msg.point.y = float(Y_base)
        crater_msg.point.z = float(Z_base)
        crater_msg.diameter = float(D)
        
        # Visualization Marker
        marker = Marker()
        marker.header.frame_id = 'map'  # or 'map' if transformed to map frame
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "crater_centroid"
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.pose.position.x = float(X_base)
        marker.pose.position.y = float(Y_base)
        marker.pose.position.z = float(Z_base)
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0

        # Diameter of sphere = crater diameter
        marker.scale.x = float(D)
        marker.scale.y = float(D)
        marker.scale.z = 0.05  # thin height for visualization if you want

        # Color RGBA
        marker.color.r = 1.0
        marker.color.g = 0.0
        marker.color.b = 0.0
        marker.color.a = 0.8

        marker.lifetime.sec = 0  # 0 = forever
        self.marker_pub.publish(marker)

        self.crater_pub.publish(crater_msg)
        self.get_logger().info( f"Published crater in map frame -> "
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

            if self.first_inference:
                self.get_logger().info("Running first inference (this may take a moment)...")
                torch.cuda.empty_cache()
                gc.collect()
                
                try:
                    # First inference with explicit no_grad and half precision
                    with torch.no_grad():
                        _ = self.model.predict(frame, verbose=False, device=self.device, half=True, imgsz=640)
                    
                    self.first_inference = False
                    self.get_logger().info("✅ Model warmed up successfully")
                    torch.cuda.empty_cache()
                    return  # Skip processing this first frame
                    
                except RuntimeError as e:
                    if "CUDNN_STATUS_NOT_INITIALIZED" in str(e):
                        self.get_logger().error("cuDNN initialization failed - GPU memory may be insufficient")
                        self.get_logger().info("Falling back to CPU for this inference...")
                        
                        # Try CPU as fallback
                        self.model.to('cpu')
                        with torch.no_grad():
                            _ = self.model.predict(frame, verbose=False, device='cpu')
                        self.model.to('cuda')
                        self.model.model.half()
                        
                        self.first_inference = False
                        self.get_logger().info("✅ Warmup complete (used CPU fallback)")
                        return
                    else:
                        raise

            annotated = frame.copy()
            with torch.no_grad():
                results = self.model(frame, verbose=False)[0]
            # pdb.set_trace()
            # results = self.model(frame, stream=False, device=self.device, verbose=False)
            self.current_frame_detections = results.boxes.xyxy  # store current frame boxes

            # --- Draw all detections ---
            for i, box in enumerate(results.boxes.xyxy):
                conf = float(results.boxes.conf[i])
                # if conf < 0.5:
                #     continue  # skip low-confidence
                x1, y1, x2, y2 = map(int, box)
                cv2.rectangle(annotated, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv2.putText(
                    annotated,
                    f"{conf:.2f}",
                    (x1, y1 - 5),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    0.5,
                    (0, 255, 0),
                    2
                )

            # --- Select highest-confidence detection ---
            highest_conf_idx = None
            # highest_conf = 0.0
            # for i, conf in enumerate(results.boxes.conf):
            #     if float(conf) >= 0.1 and float(conf) > (highest_conf-0.2):
            #         highest_conf = float(conf)
            #         highest_conf_idx = i
            #         self.get_logger().info("Print highest conf: {highest_conf}")

            if results.boxes.conf.shape[0] > 0:
                for conf in results.boxes.conf:
                    if conf > self.threshold_value: 
                        self.has_stable_detection = True
                    else: 
                        self.has_stable_detection = False
                        self.get_logger().warn("No valid detection above confidence threshold this frame.")
                        return
            else: 
                self.has_stable_detection = False
                self.get_logger().warn("No detections this frame.")
                return
            
            highest_conf_idx = np.argmax(results.boxes.conf.cpu().numpy())


            # Only process the highest-confidence box
            box = results.boxes.xyxy[highest_conf_idx]
            x1, y1, x2, y2 = map(int, box)
            cx, cy = int((x1 + x2) / 2), int((y1 + y2) / 2)
            point_3d = self.projector.pixel_to_camera(cx, cy)

            self.get_logger().info(f"Highest-confidence detection box: ({x1}, {y1}), ({x2}, {y2}) with center at ({cx}, {cy})")
            self.get_logger().info(f"Point 3D at crater center: {point_3d}")
            self.get_logger().info(f"Camera Intrinsics: fx={self.projector.fx}, fy={self.projector.fy}, cx={self.projector.cx}, cy={self.projector.cy}")

            if point_3d is None:
                self.has_stable_detection = False
                self.get_logger().warn("Highest-confidence detection has invalid depth.")
                return

            # Compute coordinates
            X, Y, Z = point_3d
            X_center = X + self.baseline / 2
            Y_center = Y
            Z_center = Z
            diameter = (x2 - x1) * Z_center / self.projector.fx

            # Store for filtering
            self.xs.append(X_center)
            self.ys.append(Y_center)
            self.zs.append(Z_center)
            self.ds.append(diameter)

            # self.has_stable_detection = True

            frame_has_valid_detection = point_3d is not None
            if not frame_has_valid_detection:
                if self.projector.fx is None:
                    self.get_logger().warn("No camera intrinsics yet (fx=None)")
                elif self.projector.depth_frame is None:
                    self.get_logger().warn("No depth frame yet")
                else:
                    self.get_logger().warn("Detections seen but no valid depth at crater center")
            else:
                self.get_logger().info("✅ Valid crater detection this frame!")

            self.has_stable_detection = frame_has_valid_detection

        except Exception as e:
            self.get_logger().error(f'Error in image_callback: {e}')
    
        # cv2.imshow("YOLO Crater Detections", annotated)
        # cv2.waitKey(1)

        # Publish annotated image
        annotated_msg = self.bridge.cv2_to_imgmsg(annotated, encoding="bgr8")
        annotated_msg.header = msg.header
        self.annotated_pub.publish(annotated_msg)




def main(args=None):
    rclpy.init(args=args)
    node = CraterDetectionNode()
    rclpy.spin(node)
    cv2.destroyAllWindows()
    rclpy.shutdown()


if __name__ == '__main__':
    main()