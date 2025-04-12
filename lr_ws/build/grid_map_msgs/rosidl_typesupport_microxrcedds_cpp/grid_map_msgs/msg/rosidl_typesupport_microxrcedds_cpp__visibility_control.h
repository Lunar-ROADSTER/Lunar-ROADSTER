// generated from
// rosidl_typesupport_microxrcedds_cpp/resource/rosidl_typesupport_microxrcedds_cpp__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef GRID_MAP_MSGS__MSG__ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP__VISIBILITY_CONTROL_H_
#define GRID_MAP_MSGS__MSG__ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_grid_map_msgs __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_IMPORT_grid_map_msgs __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_grid_map_msgs __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_IMPORT_grid_map_msgs __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_BUILDING_DLL_grid_map_msgs
    #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_grid_map_msgs
  #else
    #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_IMPORT_grid_map_msgs
  #endif
#else
  #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_grid_map_msgs __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_IMPORT_grid_map_msgs
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // GRID_MAP_MSGS__MSG__ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP__VISIBILITY_CONTROL_H_
