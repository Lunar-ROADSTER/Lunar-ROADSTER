// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:msg/Point2D.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__POINT2_D__STRUCT_H_
#define CG_MSGS__MSG__DETAIL__POINT2_D__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Point2D in the package cg_msgs.
typedef struct cg_msgs__msg__Point2D
{
  double x;
  double y;
} cg_msgs__msg__Point2D;

// Struct for a sequence of cg_msgs__msg__Point2D.
typedef struct cg_msgs__msg__Point2D__Sequence
{
  cg_msgs__msg__Point2D * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__msg__Point2D__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__POINT2_D__STRUCT_H_
