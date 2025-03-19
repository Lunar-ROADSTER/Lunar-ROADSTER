// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:msg/BermConfig.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_CONFIG__STRUCT_H_
#define LX_MSGS__MSG__DETAIL__BERM_CONFIG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'berm_configuration'
#include "geometry_msgs/msg/detail/point_stamped__struct.h"

/// Struct defined in msg/BermConfig in the package lx_msgs.
typedef struct lx_msgs__msg__BermConfig
{
  geometry_msgs__msg__PointStamped__Sequence berm_configuration;
} lx_msgs__msg__BermConfig;

// Struct for a sequence of lx_msgs__msg__BermConfig.
typedef struct lx_msgs__msg__BermConfig__Sequence
{
  lx_msgs__msg__BermConfig * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__msg__BermConfig__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__MSG__DETAIL__BERM_CONFIG__STRUCT_H_
