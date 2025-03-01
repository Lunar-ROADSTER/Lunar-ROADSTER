# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_zed_depth_to_laserscan_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED zed_depth_to_laserscan_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(zed_depth_to_laserscan_FOUND FALSE)
  elseif(NOT zed_depth_to_laserscan_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(zed_depth_to_laserscan_FOUND FALSE)
  endif()
  return()
endif()
set(_zed_depth_to_laserscan_CONFIG_INCLUDED TRUE)

# output package information
if(NOT zed_depth_to_laserscan_FIND_QUIETLY)
  message(STATUS "Found zed_depth_to_laserscan: 4.2.1 (${zed_depth_to_laserscan_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'zed_depth_to_laserscan' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${zed_depth_to_laserscan_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(zed_depth_to_laserscan_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${zed_depth_to_laserscan_DIR}/${_extra}")
endforeach()
