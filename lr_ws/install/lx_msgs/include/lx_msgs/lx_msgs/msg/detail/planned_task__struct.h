// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:msg/PlannedTask.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__PLANNED_TASK__STRUCT_H_
#define LX_MSGS__MSG__DETAIL__PLANNED_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'berm_point'
#include "lx_msgs/msg/detail/berm_section__struct.h"

/// Struct defined in msg/PlannedTask in the package lx_msgs.
typedef struct lx_msgs__msg__PlannedTask
{
  uint32_t task_type;
  geometry_msgs__msg__Pose pose;
  lx_msgs__msg__BermSection berm_point;
} lx_msgs__msg__PlannedTask;

// Struct for a sequence of lx_msgs__msg__PlannedTask.
typedef struct lx_msgs__msg__PlannedTask__Sequence
{
  lx_msgs__msg__PlannedTask * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__msg__PlannedTask__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__MSG__DETAIL__PLANNED_TASK__STRUCT_H_
