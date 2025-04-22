cmake_minimum_required(VERSION 3.8)
project(visualization)

# Default to C++20
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(grid_map_ros REQUIRED)
find_package(grid_map_msgs REQUIRED)
find_package(grid_map_core REQUIRED)
find_package(grid_map_cv REQUIRED)

include_directories(include)

add_executable(visualization_node 
  src/visualization.cpp
  src/visualization_node.cpp
)

ament_target_dependencies(visualization_node
  rclcpp
  nav_msgs
  grid_map_ros
  grid_map_msgs
  grid_map_core
  grid_map_cv
)

add_executable(local_visualization_node 
  src/local_visualization.cpp
  src/local_visualization_node.cpp
)

ament_target_dependencies(local_visualization_node
  rclcpp
  nav_msgs
  grid_map_ros
  grid_map_msgs
  grid_map_core
  grid_map_cv
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS visualization_node
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS local_visualization_node
DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
