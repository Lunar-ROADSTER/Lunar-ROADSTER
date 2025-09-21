cmake_minimum_required(VERSION 3.8)
project(skycam)

# Default to C++20
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(lr_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

# TODO: Need to change directory path if compiled elsewhere
set(Torch_DIR "/home/williamfbx/libtorch/share/cmake/Torch/")
find_package(Torch REQUIRED)

include_directories(include)
include_directories(config)

add_executable(skycam_data_collection_node 
  src/skycam_data_collection_main.cpp
  src/skycam_data_collection_node.cpp
)

ament_target_dependencies(skycam_data_collection_node
  rclcpp
  sensor_msgs
  geometry_msgs
  lr_msgs
  cv_bridge
)

target_link_libraries(skycam_data_collection_node
  ${OpenCV_LIBS}
)

add_executable(skycam_node 
  src/skycam_main.cpp
  src/skycam_node.cpp
)

ament_target_dependencies(skycam_node
  rclcpp
  sensor_msgs
  geometry_msgs
  lr_msgs
  cv_bridge
)

target_link_libraries(skycam_node
  ${OpenCV_LIBS}
  "${TORCH_LIBRARIES}"
)

set_property(TARGET skycam_node PROPERTY POSITION_INDEPENDENT_CODE ON)

# TODO: Need to change directory path if compiled elsewhere
set(LIBTORCH_LIB_DIR "/home/williamfbx/libtorch/lib")
set_target_properties(skycam_node PROPERTIES
  BUILD_RPATH "${LIBTORCH_LIB_DIR}"
  INSTALL_RPATH "${LIBTORCH_LIB_DIR}"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS skycam_data_collection_node skycam_node
DESTINATION lib/${PROJECT_NAME})

install(TARGETS skycam_node
DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include/${PROJECT_NAME})

install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
