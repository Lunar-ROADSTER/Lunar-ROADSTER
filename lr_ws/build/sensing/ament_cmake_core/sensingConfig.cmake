# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_sensing_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED sensing_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(sensing_FOUND FALSE)
  elseif(NOT sensing_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(sensing_FOUND FALSE)
  endif()
  return()
endif()
set(_sensing_CONFIG_INCLUDED TRUE)

# output package information
if(NOT sensing_FIND_QUIETLY)
  message(STATUS "Found sensing: 0.0.0 (${sensing_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'sensing' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${sensing_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(sensing_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${sensing_DIR}/${_extra}")
endforeach()
