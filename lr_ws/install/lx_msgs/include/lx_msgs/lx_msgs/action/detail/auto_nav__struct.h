// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:action/AutoNav.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__ACTION__DETAIL__AUTO_NAV__STRUCT_H_
#define LX_MSGS__ACTION__DETAIL__AUTO_NAV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goal'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in action/AutoNav in the package lx_msgs.
typedef struct lx_msgs__action__AutoNav_Goal
{
  geometry_msgs__msg__PoseStamped goal;
  int32_t next;
} lx_msgs__action__AutoNav_Goal;

// Struct for a sequence of lx_msgs__action__AutoNav_Goal.
typedef struct lx_msgs__action__AutoNav_Goal__Sequence
{
  lx_msgs__action__AutoNav_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__action__AutoNav_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/AutoNav in the package lx_msgs.
typedef struct lx_msgs__action__AutoNav_Result
{
  bool success;
} lx_msgs__action__AutoNav_Result;

// Struct for a sequence of lx_msgs__action__AutoNav_Result.
typedef struct lx_msgs__action__AutoNav_Result__Sequence
{
  lx_msgs__action__AutoNav_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__action__AutoNav_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/AutoNav in the package lx_msgs.
typedef struct lx_msgs__action__AutoNav_Feedback
{
  rosidl_runtime_c__String status;
} lx_msgs__action__AutoNav_Feedback;

// Struct for a sequence of lx_msgs__action__AutoNav_Feedback.
typedef struct lx_msgs__action__AutoNav_Feedback__Sequence
{
  lx_msgs__action__AutoNav_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__action__AutoNav_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "lx_msgs/action/detail/auto_nav__struct.h"

/// Struct defined in action/AutoNav in the package lx_msgs.
typedef struct lx_msgs__action__AutoNav_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  lx_msgs__action__AutoNav_Goal goal;
} lx_msgs__action__AutoNav_SendGoal_Request;

// Struct for a sequence of lx_msgs__action__AutoNav_SendGoal_Request.
typedef struct lx_msgs__action__AutoNav_SendGoal_Request__Sequence
{
  lx_msgs__action__AutoNav_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__action__AutoNav_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/AutoNav in the package lx_msgs.
typedef struct lx_msgs__action__AutoNav_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} lx_msgs__action__AutoNav_SendGoal_Response;

// Struct for a sequence of lx_msgs__action__AutoNav_SendGoal_Response.
typedef struct lx_msgs__action__AutoNav_SendGoal_Response__Sequence
{
  lx_msgs__action__AutoNav_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__action__AutoNav_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/AutoNav in the package lx_msgs.
typedef struct lx_msgs__action__AutoNav_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} lx_msgs__action__AutoNav_GetResult_Request;

// Struct for a sequence of lx_msgs__action__AutoNav_GetResult_Request.
typedef struct lx_msgs__action__AutoNav_GetResult_Request__Sequence
{
  lx_msgs__action__AutoNav_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__action__AutoNav_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "lx_msgs/action/detail/auto_nav__struct.h"

/// Struct defined in action/AutoNav in the package lx_msgs.
typedef struct lx_msgs__action__AutoNav_GetResult_Response
{
  int8_t status;
  lx_msgs__action__AutoNav_Result result;
} lx_msgs__action__AutoNav_GetResult_Response;

// Struct for a sequence of lx_msgs__action__AutoNav_GetResult_Response.
typedef struct lx_msgs__action__AutoNav_GetResult_Response__Sequence
{
  lx_msgs__action__AutoNav_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__action__AutoNav_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "lx_msgs/action/detail/auto_nav__struct.h"

/// Struct defined in action/AutoNav in the package lx_msgs.
typedef struct lx_msgs__action__AutoNav_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  lx_msgs__action__AutoNav_Feedback feedback;
} lx_msgs__action__AutoNav_FeedbackMessage;

// Struct for a sequence of lx_msgs__action__AutoNav_FeedbackMessage.
typedef struct lx_msgs__action__AutoNav_FeedbackMessage__Sequence
{
  lx_msgs__action__AutoNav_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__action__AutoNav_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__ACTION__DETAIL__AUTO_NAV__STRUCT_H_
