// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:srv/UpdateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__STRUCT_H_
#define CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
#include "cg_msgs/msg/detail/trajectory__struct.h"

/// Struct defined in srv/UpdateTrajectory in the package cg_msgs.
typedef struct cg_msgs__srv__UpdateTrajectory_Request
{
  cg_msgs__msg__Trajectory trajectory;
} cg_msgs__srv__UpdateTrajectory_Request;

// Struct for a sequence of cg_msgs__srv__UpdateTrajectory_Request.
typedef struct cg_msgs__srv__UpdateTrajectory_Request__Sequence
{
  cg_msgs__srv__UpdateTrajectory_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__srv__UpdateTrajectory_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/UpdateTrajectory in the package cg_msgs.
typedef struct cg_msgs__srv__UpdateTrajectory_Response
{
  bool updated_trajectory;
} cg_msgs__srv__UpdateTrajectory_Response;

// Struct for a sequence of cg_msgs__srv__UpdateTrajectory_Response.
typedef struct cg_msgs__srv__UpdateTrajectory_Response__Sequence
{
  cg_msgs__srv__UpdateTrajectory_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__srv__UpdateTrajectory_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__STRUCT_H_
