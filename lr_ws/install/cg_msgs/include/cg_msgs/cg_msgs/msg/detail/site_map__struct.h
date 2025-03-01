// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:msg/SiteMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__SITE_MAP__STRUCT_H_
#define CG_MSGS__MSG__DETAIL__SITE_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'height_map'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/SiteMap in the package cg_msgs.
typedef struct cg_msgs__msg__SiteMap
{
  rosidl_runtime_c__float__Sequence height_map;
} cg_msgs__msg__SiteMap;

// Struct for a sequence of cg_msgs__msg__SiteMap.
typedef struct cg_msgs__msg__SiteMap__Sequence
{
  cg_msgs__msg__SiteMap * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__msg__SiteMap__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__SITE_MAP__STRUCT_H_
