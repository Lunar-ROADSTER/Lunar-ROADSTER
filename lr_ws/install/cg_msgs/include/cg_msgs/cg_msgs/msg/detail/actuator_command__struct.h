// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:msg/ActuatorCommand.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__ACTUATOR_COMMAND__STRUCT_H_
#define CG_MSGS__MSG__DETAIL__ACTUATOR_COMMAND__STRUCT_H_

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

/// Struct defined in msg/ActuatorCommand in the package cg_msgs.
typedef struct cg_msgs__msg__ActuatorCommand
{
  std_msgs__msg__Header header;
  double wheel_velocity;
  double steer_position;
  double tool_position;
} cg_msgs__msg__ActuatorCommand;

// Struct for a sequence of cg_msgs__msg__ActuatorCommand.
typedef struct cg_msgs__msg__ActuatorCommand__Sequence
{
  cg_msgs__msg__ActuatorCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__msg__ActuatorCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__ACTUATOR_COMMAND__STRUCT_H_
