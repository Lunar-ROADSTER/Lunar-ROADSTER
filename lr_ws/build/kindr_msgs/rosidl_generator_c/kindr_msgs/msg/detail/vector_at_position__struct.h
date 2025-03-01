// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kindr_msgs:msg/VectorAtPosition.idl
// generated code does not contain a copyright notice

#ifndef KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__STRUCT_H_
#define KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TYPE_TYPELESS'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_TYPELESS = 0
};

/// Constant 'TYPE_JERK'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_JERK = 6
};

/// Constant 'TYPE_ACCELERATION'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_ACCELERATION = 7
};

/// Constant 'TYPE_VELOCITY'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_VELOCITY = 8
};

/// Constant 'TYPE_POSITION'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_POSITION = 9
};

/// Constant 'TYPE_FORCE'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_FORCE = 10
};

/// Constant 'TYPE_MOMEMTUM'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_MOMEMTUM = 11
};

/// Constant 'TYPE_ANGULAR_JERK'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_ANGULAR_JERK = 12
};

/// Constant 'TYPE_ANGULAR_ACCELERATION'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_ANGULAR_ACCELERATION = 13
};

/// Constant 'TYPE_ANGULAR_VELOCITY'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_ANGULAR_VELOCITY = 14
};

/// Constant 'TYPE_TORQUE'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_TORQUE = 16
};

/// Constant 'TYPE_ANGULAR_MOMEMTUM'.
enum
{
  kindr_msgs__msg__VectorAtPosition__TYPE_ANGULAR_MOMEMTUM = 17
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'name'
// Member 'position_frame_id'
#include "rosidl_runtime_c/string.h"
// Member 'vector'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/VectorAtPosition in the package kindr_msgs.
/**
  * Vector type definition (based on Kindr definitions)
 */
typedef struct kindr_msgs__msg__VectorAtPosition
{
  std_msgs__msg__Header header;
  uint8_t type;
  rosidl_runtime_c__String name;
  /// Frame defined in header
  geometry_msgs__msg__Vector3 vector;
  /// Point of origin of the vector
  geometry_msgs__msg__Point position;
  /// If empty same as vector frame
  rosidl_runtime_c__String position_frame_id;
} kindr_msgs__msg__VectorAtPosition;

// Struct for a sequence of kindr_msgs__msg__VectorAtPosition.
typedef struct kindr_msgs__msg__VectorAtPosition__Sequence
{
  kindr_msgs__msg__VectorAtPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kindr_msgs__msg__VectorAtPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__STRUCT_H_
