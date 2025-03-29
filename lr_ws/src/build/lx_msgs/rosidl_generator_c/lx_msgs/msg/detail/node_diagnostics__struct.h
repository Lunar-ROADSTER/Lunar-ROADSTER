// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:msg/NodeDiagnostics.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__NODE_DIAGNOSTICS__STRUCT_H_
#define LX_MSGS__MSG__DETAIL__NODE_DIAGNOSTICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'node_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/NodeDiagnostics in the package lx_msgs.
typedef struct lx_msgs__msg__NodeDiagnostics
{
  builtin_interfaces__msg__Time stamp;
  rosidl_runtime_c__String node_name;
} lx_msgs__msg__NodeDiagnostics;

// Struct for a sequence of lx_msgs__msg__NodeDiagnostics.
typedef struct lx_msgs__msg__NodeDiagnostics__Sequence
{
  lx_msgs__msg__NodeDiagnostics * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__msg__NodeDiagnostics__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__MSG__DETAIL__NODE_DIAGNOSTICS__STRUCT_H_
