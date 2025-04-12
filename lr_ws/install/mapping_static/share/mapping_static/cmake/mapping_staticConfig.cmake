# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_mapping_static_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED mapping_static_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(mapping_static_FOUND FALSE)
  elseif(NOT mapping_static_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(mapping_static_FOUND FALSE)
  endif()
  return()
endif()
set(_mapping_static_CONFIG_INCLUDED TRUE)

# output package information
if(NOT mapping_static_FIND_QUIETLY)
  message(STATUS "Found mapping_static: 0.0.0 (${mapping_static_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'mapping_static' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${mapping_static_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(mapping_static_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${mapping_static_DIR}/${_extra}")
endforeach()
