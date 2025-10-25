cmake_minimum_required(VERSION 3.8)
project(planning)

# Default to C++20
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find saved map directory
add_definitions(-DPLANNING_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(lr_msgs REQUIRED)
find_package(mapping REQUIRED)
# find_package(ortools CONFIG REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(nav_msgs REQUIRED) # viz
find_package(geometry_msgs REQUIRED) # viz
find_package(tf2_ros REQUIRED) # viz
find_package(pcl_ros REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(nav2_msgs REQUIRED)

# Add Eigen3 Library
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIRS})


include_directories(include)

include_directories(../mapping/include)

add_executable(behavior_executive_node src/behavior_executive_main.cpp
  src/behavior_executive_node.cpp
  # State machine
  src/fsm/fsm.cpp
  src/fsm/ready.cpp
  src/fsm/update_map.cpp
  src/fsm/site_work_done.cpp
  src/fsm/map_explored.cpp
  src/fsm/plan_transport.cpp
  src/fsm/get_transport_goals.cpp
  src/fsm/goals_remaining.cpp
  src/fsm/get_worksystem_trajectory.cpp
  src/fsm/following_trajectory.cpp
  src/fsm/end_mission.cpp
  src/fsm/stopped.cpp
  # Planner Modules 
  src/transport_planner.cpp
  src/common.cpp
  # Mapping Modules
  src/planning_util.cpp
  # Navigation Modules
  src/navigation_util.cpp
)
ament_target_dependencies(behavior_executive_node
  rclcpp
  rclcpp_action
  lr_msgs
  mapping
  nav_msgs # viz
  geometry_msgs # viz
  tf2_ros # viz
  pcl_ros
  pcl_conversions
  nav2_msgs
)
# target_link_libraries(behavior_executive_node ortools::ortools)

# Install targets
install(TARGETS behavior_executive_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install directories
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include/${PROJECT_NAME}
)
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)
install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}/
)


# Export library files so other packages can link
ament_export_include_directories(include)

ament_package()
