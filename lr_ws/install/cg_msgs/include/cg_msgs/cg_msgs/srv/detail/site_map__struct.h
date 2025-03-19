// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:srv/SiteMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__SITE_MAP__STRUCT_H_
#define CG_MSGS__SRV__DETAIL__SITE_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SiteMap in the package cg_msgs.
typedef struct cg_msgs__srv__SiteMap_Request
{
  uint8_t structure_needs_at_least_one_member;
} cg_msgs__srv__SiteMap_Request;

// Struct for a sequence of cg_msgs__srv__SiteMap_Request.
typedef struct cg_msgs__srv__SiteMap_Request__Sequence
{
  cg_msgs__srv__SiteMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__srv__SiteMap_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'site_map'
#include "cg_msgs/msg/detail/site_map__struct.h"

/// Struct defined in srv/SiteMap in the package cg_msgs.
typedef struct cg_msgs__srv__SiteMap_Response
{
  cg_msgs__msg__SiteMap site_map;
  bool map_fully_explored;
  bool success;
} cg_msgs__srv__SiteMap_Response;

// Struct for a sequence of cg_msgs__srv__SiteMap_Response.
typedef struct cg_msgs__srv__SiteMap_Response__Sequence
{
  cg_msgs__srv__SiteMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__srv__SiteMap_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__SRV__DETAIL__SITE_MAP__STRUCT_H_
