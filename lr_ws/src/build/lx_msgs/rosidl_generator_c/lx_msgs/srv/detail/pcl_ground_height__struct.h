// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:srv/PclGroundHeight.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__PCL_GROUND_HEIGHT__STRUCT_H_
#define LX_MSGS__SRV__DETAIL__PCL_GROUND_HEIGHT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/PclGroundHeight in the package lx_msgs.
typedef struct lx_msgs__srv__PclGroundHeight_Request
{
  bool need_height;
} lx_msgs__srv__PclGroundHeight_Request;

// Struct for a sequence of lx_msgs__srv__PclGroundHeight_Request.
typedef struct lx_msgs__srv__PclGroundHeight_Request__Sequence
{
  lx_msgs__srv__PclGroundHeight_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__PclGroundHeight_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/PclGroundHeight in the package lx_msgs.
typedef struct lx_msgs__srv__PclGroundHeight_Response
{
  bool success;
} lx_msgs__srv__PclGroundHeight_Response;

// Struct for a sequence of lx_msgs__srv__PclGroundHeight_Response.
typedef struct lx_msgs__srv__PclGroundHeight_Response__Sequence
{
  lx_msgs__srv__PclGroundHeight_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__PclGroundHeight_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__SRV__DETAIL__PCL_GROUND_HEIGHT__STRUCT_H_
