// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grid_map_msgs:msg/GridMap.idl
// generated code does not contain a copyright notice

#ifndef GRID_MAP_MSGS__MSG__DETAIL__GRID_MAP__STRUCT_H_
#define GRID_MAP_MSGS__MSG__DETAIL__GRID_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'info'
#include "grid_map_msgs/msg/detail/grid_map_info__struct.h"
// Member 'layers'
// Member 'basic_layers'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "std_msgs/msg/detail/float32_multi_array__struct.h"

/// Struct defined in msg/GridMap in the package grid_map_msgs.
/**
  * Header (time and frame)
 */
typedef struct grid_map_msgs__msg__GridMap
{
  std_msgs__msg__Header header;
  /// Grid map header
  grid_map_msgs__msg__GridMapInfo info;
  /// Grid map layer names.
  rosidl_runtime_c__String__Sequence layers;
  /// Grid map basic layer names (optional). The basic layers
  /// determine which layers from `layers` need to be valid
  /// in order for a cell of the grid map to be valid.
  rosidl_runtime_c__String__Sequence basic_layers;
  /// Grid map data.
  std_msgs__msg__Float32MultiArray__Sequence data;
  /// Row start index (default 0).
  uint16_t outer_start_index;
  /// Column start index (default 0).
  uint16_t inner_start_index;
} grid_map_msgs__msg__GridMap;

// Struct for a sequence of grid_map_msgs__msg__GridMap.
typedef struct grid_map_msgs__msg__GridMap__Sequence
{
  grid_map_msgs__msg__GridMap * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grid_map_msgs__msg__GridMap__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRID_MAP_MSGS__MSG__DETAIL__GRID_MAP__STRUCT_H_
