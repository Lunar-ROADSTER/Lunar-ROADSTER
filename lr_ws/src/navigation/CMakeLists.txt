cmake_minimum_required(VERSION 3.8)
project(navigation)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(lr_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)

include_directories(include)

add_executable(global_astar_node
  src/global_planner_node.cpp
  src/global_planner_main.cpp
)
ament_target_dependencies(global_astar_node
  rclcpp
  nav_msgs
  geometry_msgs
  std_msgs
  visualization_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  lr_msgs
)

add_executable(crater_centroids_pub
  src/crater_centroids_pub.cpp
)
ament_target_dependencies(crater_centroids_pub
  rclcpp
  geometry_msgs
)

add_executable(crater_diameters_pub
  src/crater_diameters_pub.cpp
)
ament_target_dependencies(crater_diameters_pub
  rclcpp
  std_msgs
)


add_executable(global_planner_controller_main
  src/global_planner_controller_main.cpp
  src/global_planner_controller_node.cpp
)

ament_target_dependencies(global_planner_controller_main
  rclcpp
  nav_msgs
  geometry_msgs
  tf2_ros
  tf2_geometry_msgs
  visualization_msgs
  lr_msgs
  rclcpp_action
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS global_astar_node
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS crater_centroids_pub crater_diameters_pub
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  global_planner_controller_main
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)


ament_package()
