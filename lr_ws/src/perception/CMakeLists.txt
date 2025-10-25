cmake_minimum_required(VERSION 3.5)
project(perception)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(planning REQUIRED)

add_executable(pose_extractor src/robot_pose_extractor.cpp)
ament_target_dependencies(pose_extractor rclcpp planning)

include_directories(include)

install(TARGETS
  pose_extractor
  DESTINATION lib/${PROJECT_NAME})

ament_package()
