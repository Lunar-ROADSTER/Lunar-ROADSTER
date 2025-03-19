// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:srv/SaveMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__SAVE_MAP__STRUCT_H_
#define CG_MSGS__SRV__DETAIL__SAVE_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'filepath'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SaveMap in the package cg_msgs.
typedef struct cg_msgs__srv__SaveMap_Request
{
  rosidl_runtime_c__String filepath;
} cg_msgs__srv__SaveMap_Request;

// Struct for a sequence of cg_msgs__srv__SaveMap_Request.
typedef struct cg_msgs__srv__SaveMap_Request__Sequence
{
  cg_msgs__srv__SaveMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__srv__SaveMap_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SaveMap in the package cg_msgs.
typedef struct cg_msgs__srv__SaveMap_Response
{
  bool map_saved;
} cg_msgs__srv__SaveMap_Response;

// Struct for a sequence of cg_msgs__srv__SaveMap_Response.
typedef struct cg_msgs__srv__SaveMap_Response__Sequence
{
  cg_msgs__srv__SaveMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__srv__SaveMap_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__SRV__DETAIL__SAVE_MAP__STRUCT_H_
