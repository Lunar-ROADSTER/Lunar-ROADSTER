cmake_minimum_required(VERSION 3.8)
project(sensing)

# Default to C++20
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_sensor_msgs REQUIRED)
find_package(pcl_ros REQUIRED)
find_package(pcl_conversions REQUIRED)

include_directories(include)

add_executable(pc_handler_node src/pc_handler_node.cpp src/pc_handler.cpp)
ament_target_dependencies(pc_handler_node 
  rclcpp
  tf2_geometry_msgs
  std_msgs
  sensor_msgs
  tf2_sensor_msgs
  geometry_msgs
  nav_msgs
  tf2_ros
  tf2_eigen
  tf2
  pcl_ros
  pcl_conversions
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS 
  pc_handler_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install directories
install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

target_link_libraries(pc_handler_node ${PCL_LIBRARIES})

ament_package()
