// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:msg/ToolInfo.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__TOOL_INFO__STRUCT_H_
#define LX_MSGS__MSG__DETAIL__TOOL_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ToolInfo in the package lx_msgs.
typedef struct lx_msgs__msg__ToolInfo
{
  double drum_pos;
  double drum_current;
} lx_msgs__msg__ToolInfo;

// Struct for a sequence of lx_msgs__msg__ToolInfo.
typedef struct lx_msgs__msg__ToolInfo__Sequence
{
  lx_msgs__msg__ToolInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__msg__ToolInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__MSG__DETAIL__TOOL_INFO__STRUCT_H_
