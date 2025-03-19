// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:msg/BermProgress.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_PROGRESS__STRUCT_H_
#define LX_MSGS__MSG__DETAIL__BERM_PROGRESS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'berm_points'
#include "geometry_msgs/msg/detail/point_stamped__struct.h"
// Member 'heights'
// Member 'timestamps'
// Member 'volumes'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/BermProgress in the package lx_msgs.
typedef struct lx_msgs__msg__BermProgress
{
  geometry_msgs__msg__PointStamped__Sequence berm_points;
  rosidl_runtime_c__float__Sequence heights;
  float average_height;
  float length;
  float peakline_error;
  rosidl_runtime_c__float__Sequence timestamps;
  rosidl_runtime_c__float__Sequence volumes;
} lx_msgs__msg__BermProgress;

// Struct for a sequence of lx_msgs__msg__BermProgress.
typedef struct lx_msgs__msg__BermProgress__Sequence
{
  lx_msgs__msg__BermProgress * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__msg__BermProgress__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__MSG__DETAIL__BERM_PROGRESS__STRUCT_H_
