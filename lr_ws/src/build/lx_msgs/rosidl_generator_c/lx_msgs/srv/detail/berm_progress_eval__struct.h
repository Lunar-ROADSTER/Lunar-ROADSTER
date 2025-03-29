// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:srv/BermProgressEval.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__STRUCT_H_
#define LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/BermProgressEval in the package lx_msgs.
typedef struct lx_msgs__srv__BermProgressEval_Request
{
  bool need_metrics;
} lx_msgs__srv__BermProgressEval_Request;

// Struct for a sequence of lx_msgs__srv__BermProgressEval_Request.
typedef struct lx_msgs__srv__BermProgressEval_Request__Sequence
{
  lx_msgs__srv__BermProgressEval_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__BermProgressEval_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'progress'
#include "lx_msgs/msg/detail/berm_progress__struct.h"

/// Struct defined in srv/BermProgressEval in the package lx_msgs.
typedef struct lx_msgs__srv__BermProgressEval_Response
{
  lx_msgs__msg__BermProgress progress;
} lx_msgs__srv__BermProgressEval_Response;

// Struct for a sequence of lx_msgs__srv__BermProgressEval_Response.
typedef struct lx_msgs__srv__BermProgressEval_Response__Sequence
{
  lx_msgs__srv__BermProgressEval_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__BermProgressEval_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__STRUCT_H_
