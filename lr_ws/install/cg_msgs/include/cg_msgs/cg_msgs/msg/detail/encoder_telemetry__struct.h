// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:msg/EncoderTelemetry.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__STRUCT_H_
#define CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__STRUCT_H_

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

/// Struct defined in msg/EncoderTelemetry in the package cg_msgs.
typedef struct cg_msgs__msg__EncoderTelemetry
{
  std_msgs__msg__Header header;
  int32_t steer_pos_front;
  int32_t steer_pos_rear;
  int32_t tool_pos;
  int32_t drive_vel_front;
  int32_t drive_vel_rear;
  int32_t drive_delta_front;
  int32_t drive_delta_rear;
  int32_t term_byte;
} cg_msgs__msg__EncoderTelemetry;

// Struct for a sequence of cg_msgs__msg__EncoderTelemetry.
typedef struct cg_msgs__msg__EncoderTelemetry__Sequence
{
  cg_msgs__msg__EncoderTelemetry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__msg__EncoderTelemetry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__STRUCT_H_
