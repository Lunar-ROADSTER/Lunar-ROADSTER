# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.6)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.20)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget rviz_plugin_zed_od::rviz_plugin_zed_od)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target rviz_plugin_zed_od::rviz_plugin_zed_od
add_library(rviz_plugin_zed_od::rviz_plugin_zed_od SHARED IMPORTED)

set_target_properties(rviz_plugin_zed_od::rviz_plugin_zed_od PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "PLUGINLIB__DISABLE_BOOST_FUNCTIONS"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include;/usr/include;/usr/include/eigen3;/opt/ros/humble/include/resource_retriever;/opt/ros/humble/include/ament_index_cpp;/opt/ros/humble/include/rviz_rendering;/opt/ros/humble/include/rviz_rendering;/usr/include/eigen3;/usr/include;/opt/ros/humble/include/geometry_msgs;/opt/ros/humble/include/pluginlib;/opt/ros/humble/include/rclcpp;/opt/ros/humble/include/sensor_msgs;/opt/ros/humble/include/std_msgs;/opt/ros/humble/include/tf2;/opt/ros/humble/include/tf2_geometry_msgs;/opt/ros/humble/include/tf2_ros;/opt/ros/humble/include/urdf;/opt/ros/humble/include/rviz_common;/opt/ros/humble/include/builtin_interfaces;/opt/ros/humble/include/std_msgs;/opt/ros/humble/include/geometry_msgs;/opt/ros/humble/include/shape_msgs;/opt/ros/humble/include/rosidl_runtime_c;/opt/ros/humble/include/rosidl_typesupport_interface;/opt/ros/humble/include/rcutils;/opt/ros/humble/include/rosidl_runtime_cpp;/opt/ros/humble/include/rosidl_typesupport_fastrtps_c;/opt/ros/humble/include/rosidl_typesupport_fastrtps_cpp;/opt/ros/humble/include/rmw;/opt/ros/humble/include/rosidl_typesupport_c;/opt/ros/humble/include/rosidl_typesupport_cpp;/opt/ros/humble/include/rcpputils;/opt/ros/humble/include/rosidl_typesupport_introspection_c;/opt/ros/humble/include/rosidl_typesupport_introspection_cpp;/opt/ros/humble/include/zed_msgs;/opt/ros/humble/opt/rviz_ogre_vendor/include/OGRE;/usr/include/x86_64-linux-gnu/qt5/;/usr/include/x86_64-linux-gnu/qt5/QtWidgets;/usr/include/x86_64-linux-gnu/qt5/QtGui;/usr/include/x86_64-linux-gnu/qt5/QtCore;/usr/lib/x86_64-linux-gnu/qt5//mkspecs/linux-g++;/opt/ros/humble/include/resource_retriever;/opt/ros/humble/include/ament_index_cpp;/usr/include/x86_64-linux-gnu;${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "zed_msgs::zed_msgs__rosidl_generator_c;zed_msgs::zed_msgs__rosidl_typesupport_fastrtps_c;zed_msgs::zed_msgs__rosidl_generator_cpp;zed_msgs::zed_msgs__rosidl_typesupport_fastrtps_cpp;zed_msgs::zed_msgs__rosidl_typesupport_introspection_c;zed_msgs::zed_msgs__rosidl_typesupport_c;zed_msgs::zed_msgs__rosidl_typesupport_introspection_cpp;zed_msgs::zed_msgs__rosidl_typesupport_cpp;zed_msgs::zed_msgs__rosidl_generator_py;rclcpp::rclcpp;rviz_common::rviz_common"
)

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  message(FATAL_ERROR "This file relies on consumers using CMake 2.8.12 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/rviz_plugin_zed_odExport-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
