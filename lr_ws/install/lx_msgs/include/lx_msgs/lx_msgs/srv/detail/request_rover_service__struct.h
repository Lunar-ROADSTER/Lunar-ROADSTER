// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lx_msgs:srv/RequestRoverService.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__STRUCT_H_
#define LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'berm'
#include "lx_msgs/msg/detail/berm_config__struct.h"
// Member 'restricted_zone_coordinates'
// Member 'excavation_zone_coordinates'
#include "geometry_msgs/msg/detail/point_stamped__struct.h"

/// Struct defined in srv/RequestRoverService in the package lx_msgs.
typedef struct lx_msgs__srv__RequestRoverService_Request
{
  lx_msgs__msg__BermConfig berm;
  geometry_msgs__msg__PointStamped__Sequence restricted_zone_coordinates;
  geometry_msgs__msg__PointStamped__Sequence excavation_zone_coordinates;
} lx_msgs__srv__RequestRoverService_Request;

// Struct for a sequence of lx_msgs__srv__RequestRoverService_Request.
typedef struct lx_msgs__srv__RequestRoverService_Request__Sequence
{
  lx_msgs__srv__RequestRoverService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__RequestRoverService_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/RequestRoverService in the package lx_msgs.
typedef struct lx_msgs__srv__RequestRoverService_Response
{
  bool success;
} lx_msgs__srv__RequestRoverService_Response;

// Struct for a sequence of lx_msgs__srv__RequestRoverService_Response.
typedef struct lx_msgs__srv__RequestRoverService_Response__Sequence
{
  lx_msgs__srv__RequestRoverService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lx_msgs__srv__RequestRoverService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__STRUCT_H_
