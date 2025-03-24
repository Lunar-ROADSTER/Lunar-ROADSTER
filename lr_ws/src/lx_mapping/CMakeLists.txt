cmake_minimum_required(VERSION 3.5)
project(lx_mapping)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(lx_msgs REQUIRED)
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
find_package(visualization_msgs REQUIRED)
find_package(lx_library REQUIRED)


include_directories(include)

add_executable(world_model_node src/world_model_node.cpp src/world_model.cpp src/bayes_filter.cpp include/lx_mapping/bayes_filter.hpp)
ament_target_dependencies(world_model_node lx_msgs rclcpp tf2_geometry_msgs lx_msgs rclcpp std_msgs sensor_msgs tf2_sensor_msgs geometry_msgs nav_msgs tf2_ros tf2_eigen tf2 pcl_ros pcl_conversions lx_library)

add_executable(global_mapping_node src/global_mapping_node.cpp src/global_mapping.cpp src/bayes_filter.cpp include/lx_mapping/bayes_filter.hpp)
ament_target_dependencies(global_mapping_node lx_msgs rclcpp tf2_geometry_msgs lx_msgs rclcpp std_msgs sensor_msgs tf2_sensor_msgs geometry_msgs nav_msgs tf2_ros tf2_eigen tf2 pcl_ros pcl_conversions lx_library)

add_executable(pc_handler_node src/pc_handler_node.cpp src/pc_handler.cpp)
ament_target_dependencies(pc_handler_node lx_msgs rclcpp tf2_geometry_msgs lx_msgs rclcpp std_msgs sensor_msgs tf2_sensor_msgs geometry_msgs nav_msgs tf2_ros tf2_eigen tf2 pcl_ros pcl_conversions lx_library)

install(TARGETS 
  world_model_node
  global_mapping_node
  pc_handler_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

target_link_libraries(world_model_node ${PCL_LIBRARIES})
target_link_libraries(global_mapping_node ${PCL_LIBRARIES})
target_link_libraries(pc_handler_node ${PCL_LIBRARIES})

ament_package()
