// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:msg/BeaconMultiTag.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__STRUCT_H_
#define CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__STRUCT_H_

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
// Member 'TagsList'
#include "cg_msgs/msg/detail/beacon_tag__struct.h"

/// Struct defined in msg/BeaconMultiTag in the package cg_msgs.
typedef struct cg_msgs__msg__BeaconMultiTag
{
  std_msgs__msg__Header header;
  cg_msgs__msg__BeaconTag TagsList[2];
} cg_msgs__msg__BeaconMultiTag;

// Struct for a sequence of cg_msgs__msg__BeaconMultiTag.
typedef struct cg_msgs__msg__BeaconMultiTag__Sequence
{
  cg_msgs__msg__BeaconMultiTag * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__msg__BeaconMultiTag__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__STRUCT_H_
