// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:srv/Plan.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__PLAN__STRUCT_H_
#define LX_MSGS__SRV__DETAIL__PLAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'berm_input'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in srv/Plan in the package lx_msgs.
typedef struct lx_msgs__srv__Plan_Request
{
  geometry_msgs__msg__Point__Sequence berm_input;
  float berm_height;
  float section_length;
  bool new_plan;
} lx_msgs__srv__Plan_Request;

// Struct for a sequence of lx_msgs__srv__Plan_Request.
typedef struct lx_msgs__srv__Plan_Request__Sequence
{
  lx_msgs__srv__Plan_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__Plan_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'plan'
#include "lx_msgs/msg/detail/planned_task__struct.h"

/// Struct defined in srv/Plan in the package lx_msgs.
typedef struct lx_msgs__srv__Plan_Response
{
  lx_msgs__msg__PlannedTask__Sequence plan;
} lx_msgs__srv__Plan_Response;

// Struct for a sequence of lx_msgs__srv__Plan_Response.
typedef struct lx_msgs__srv__Plan_Response__Sequence
{
  lx_msgs__srv__Plan_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__Plan_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__SRV__DETAIL__PLAN__STRUCT_H_
