// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:msg/Slip.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__SLIP__STRUCT_H_
#define CG_MSGS__MSG__DETAIL__SLIP__STRUCT_H_

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

/// Struct defined in msg/Slip in the package cg_msgs.
typedef struct cg_msgs__msg__Slip
{
  std_msgs__msg__Header header;
  float slip;
  float slip_avg;
  bool slip_latch;
  float vel;
  float vel_avg;
} cg_msgs__msg__Slip;

// Struct for a sequence of cg_msgs__msg__Slip.
typedef struct cg_msgs__msg__Slip__Sequence
{
  cg_msgs__msg__Slip * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__msg__Slip__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__SLIP__STRUCT_H_
