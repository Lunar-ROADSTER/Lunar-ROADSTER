// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:srv/Switch.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__SWITCH__STRUCT_H_
#define LX_MSGS__SRV__DETAIL__SWITCH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'current_berm_segment'
// Member 'prev_berm_segment'
#include "lx_msgs/msg/detail/berm_section__struct.h"

/// Struct defined in srv/Switch in the package lx_msgs.
typedef struct lx_msgs__srv__Switch_Request
{
  bool switch_state;
  lx_msgs__msg__BermSection current_berm_segment;
  lx_msgs__msg__BermSection prev_berm_segment;
  bool first_seg_dump;
} lx_msgs__srv__Switch_Request;

// Struct for a sequence of lx_msgs__srv__Switch_Request.
typedef struct lx_msgs__srv__Switch_Request__Sequence
{
  lx_msgs__srv__Switch_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__Switch_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Switch in the package lx_msgs.
typedef struct lx_msgs__srv__Switch_Response
{
  bool success;
} lx_msgs__srv__Switch_Response;

// Struct for a sequence of lx_msgs__srv__Switch_Response.
typedef struct lx_msgs__srv__Switch_Response__Sequence
{
  lx_msgs__srv__Switch_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__Switch_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__SRV__DETAIL__SWITCH__STRUCT_H_
