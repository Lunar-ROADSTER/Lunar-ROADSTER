// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:srv/ZoneService.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__ZONE_SERVICE__STRUCT_H_
#define LX_MSGS__SRV__DETAIL__ZONE_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'zone_type'
#include "rosidl_runtime_c/string.h"
// Member 'zone_coordinates'
#include "geometry_msgs/msg/detail/point_stamped__struct.h"

/// Struct defined in srv/ZoneService in the package lx_msgs.
typedef struct lx_msgs__srv__ZoneService_Request
{
  rosidl_runtime_c__String zone_type;
  geometry_msgs__msg__PointStamped__Sequence zone_coordinates;
} lx_msgs__srv__ZoneService_Request;

// Struct for a sequence of lx_msgs__srv__ZoneService_Request.
typedef struct lx_msgs__srv__ZoneService_Request__Sequence
{
  lx_msgs__srv__ZoneService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__ZoneService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ZoneService in the package lx_msgs.
typedef struct lx_msgs__srv__ZoneService_Response
{
  bool success;
} lx_msgs__srv__ZoneService_Response;

// Struct for a sequence of lx_msgs__srv__ZoneService_Response.
typedef struct lx_msgs__srv__ZoneService_Response__Sequence
{
  lx_msgs__srv__ZoneService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__ZoneService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__SRV__DETAIL__ZONE_SERVICE__STRUCT_H_
