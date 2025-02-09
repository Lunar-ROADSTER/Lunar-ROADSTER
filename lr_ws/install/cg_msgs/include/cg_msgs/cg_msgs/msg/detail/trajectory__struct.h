// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_
#define CG_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path'
#include "cg_msgs/msg/detail/pose2_d__struct.h"
// Member 'velocity_targets'
// Member 'tool_positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Trajectory in the package cg_msgs.
typedef struct cg_msgs__msg__Trajectory
{
  cg_msgs__msg__Pose2D__Sequence path;
  rosidl_runtime_c__float__Sequence velocity_targets;
  rosidl_runtime_c__float__Sequence tool_positions;
} cg_msgs__msg__Trajectory;

// Struct for a sequence of cg_msgs__msg__Trajectory.
typedef struct cg_msgs__msg__Trajectory__Sequence
{
  cg_msgs__msg__Trajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__msg__Trajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__TRAJECTORY__STRUCT_H_
