// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:msg/BermSection.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_SECTION__STRUCT_H_
#define LX_MSGS__MSG__DETAIL__BERM_SECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BermSection in the package lx_msgs.
typedef struct lx_msgs__msg__BermSection
{
  float x;
  float y;
  float theta;
} lx_msgs__msg__BermSection;

// Struct for a sequence of lx_msgs__msg__BermSection.
typedef struct lx_msgs__msg__BermSection__Sequence
{
  lx_msgs__msg__BermSection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__msg__BermSection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__MSG__DETAIL__BERM_SECTION__STRUCT_H_
