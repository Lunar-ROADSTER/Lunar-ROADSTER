// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:msg/BeaconTag.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__BEACON_TAG__STRUCT_H_
#define CG_MSGS__MSG__DETAIL__BEACON_TAG__STRUCT_H_

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
// Member 'tag_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BeaconTag in the package cg_msgs.
typedef struct cg_msgs__msg__BeaconTag
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String tag_id;
  double pose_x;
  double pose_y;
  double pose_z;
  double orientation_x;
  double orientation_y;
  double orientation_z;
  double orientation_w;
} cg_msgs__msg__BeaconTag;

// Struct for a sequence of cg_msgs__msg__BeaconTag.
typedef struct cg_msgs__msg__BeaconTag__Sequence
{
  cg_msgs__msg__BeaconTag * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__msg__BeaconTag__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__BEACON_TAG__STRUCT_H_
