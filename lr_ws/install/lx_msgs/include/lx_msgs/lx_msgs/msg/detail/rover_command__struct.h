// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:msg/RoverCommand.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__ROVER_COMMAND__STRUCT_H_
#define LX_MSGS__MSG__DETAIL__ROVER_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mobility_twist'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/RoverCommand in the package lx_msgs.
typedef struct lx_msgs__msg__RoverCommand
{
  geometry_msgs__msg__Twist mobility_twist;
  double actuator_speed;
  double drum_speed;
} lx_msgs__msg__RoverCommand;

// Struct for a sequence of lx_msgs__msg__RoverCommand.
typedef struct lx_msgs__msg__RoverCommand__Sequence
{
  lx_msgs__msg__RoverCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__msg__RoverCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__MSG__DETAIL__ROVER_COMMAND__STRUCT_H_
