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
find_package(lr_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(Eigen3 REQUIRED)


# --- Action File Generation ---
# rosidl_generate_interfaces(${PROJECT_NAME}
#   "action/CraterDetect.action"
#   "srv/PoseExtract.srv"
#   DEPENDENCIES builtin_interfaces std_msgs geometry_msgs lr_msgs
# )

ament_export_dependencies(
  rosidl_default_runtime
  rclcpp
  geometry_msgs
  nav_msgs
  tf2_ros
  tf2
  lr_msgs
  Eigen3
)

# --- C++ Executables ---
add_library(perception_common src/common.cpp)
target_include_directories(perception_common PUBLIC include)
ament_target_dependencies(perception_common
  geometry_msgs
  nav_msgs
  tf2_ros
  tf2
  lr_msgs
)
target_link_libraries(perception_common Eigen3::Eigen)

add_executable(pose_extractor src/robot_pose_extractor.cpp)
target_include_directories(pose_extractor PUBLIC include)
ament_target_dependencies(pose_extractor
  rclcpp
  geometry_msgs
  nav_msgs
  tf2_ros
  tf2
  lr_msgs
  tf2_geometry_msgs
  visualization_msgs
)
target_link_libraries(pose_extractor Eigen3::Eigen perception_common)
# rosidl_target_interfaces(pose_extractor
#  ${PROJECT_NAME} "rosidl_typesupport_cpp")

ament_export_include_directories(include)
ament_export_libraries(perception_common)

# --- Install Targets ---
install(
  TARGETS
    perception_common
    pose_extractor
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
  INCLUDES DESTINATION include
)

# --- Install Python Nodes ---
install(PROGRAMS
  perception/detection.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
