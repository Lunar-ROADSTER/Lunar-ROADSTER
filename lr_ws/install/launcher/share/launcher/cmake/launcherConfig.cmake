# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_launcher_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED launcher_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(launcher_FOUND FALSE)
  elseif(NOT launcher_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(launcher_FOUND FALSE)
  endif()
  return()
endif()
set(_launcher_CONFIG_INCLUDED TRUE)

# output package information
if(NOT launcher_FIND_QUIETLY)
  message(STATUS "Found launcher: 1.0.0 (${launcher_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'launcher' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${launcher_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(launcher_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${launcher_DIR}/${_extra}")
endforeach()
