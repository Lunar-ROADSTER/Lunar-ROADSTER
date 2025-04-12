#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "grid_map_rviz_plugin::grid_map_rviz_plugin" for configuration "Release"
set_property(TARGET grid_map_rviz_plugin::grid_map_rviz_plugin APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(grid_map_rviz_plugin::grid_map_rviz_plugin PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libgrid_map_rviz_plugin.so"
  IMPORTED_SONAME_RELEASE "libgrid_map_rviz_plugin.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS grid_map_rviz_plugin::grid_map_rviz_plugin )
list(APPEND _IMPORT_CHECK_FILES_FOR_grid_map_rviz_plugin::grid_map_rviz_plugin "${_IMPORT_PREFIX}/lib/libgrid_map_rviz_plugin.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
