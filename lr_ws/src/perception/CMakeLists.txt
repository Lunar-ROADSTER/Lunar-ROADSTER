cmake_minimum_required(VERSION 3.5)
project(perception)

# --- Dependencies ---
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(action_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(std_msgs REQUIRED)
find_package(planning REQUIRED)  # keep if needed by your C++ node

# --- Action File Generation ---
rosidl_generate_interfaces(${PROJECT_NAME}
  "action/CraterDetect.action"
  DEPENDENCIES builtin_interfaces std_msgs geometry_msgs
)

ament_export_dependencies(rosidl_default_runtime)

# --- C++ Executables ---
add_executable(pose_extractor src/robot_pose_extractor.cpp)
ament_target_dependencies(pose_extractor rclcpp planning)

# --- Include Directories ---
include_directories(include)

# --- Install Targets ---
install(TARGETS
  pose_extractor
  DESTINATION lib/${PROJECT_NAME}
)

# --- Install Python Nodes ---
install(PROGRAMS
  scripts/detection.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
