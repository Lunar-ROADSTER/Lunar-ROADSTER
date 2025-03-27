// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:msg/MuxMode.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__MUX_MODE__STRUCT_H_
#define CG_MSGS__MSG__DETAIL__MUX_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'IDLE'.
enum
{
  cg_msgs__msg__MuxMode__IDLE = 0
};

/// Constant 'AUTOGRADER'.
enum
{
  cg_msgs__msg__MuxMode__AUTOGRADER = 1
};

/// Constant 'FULL_AUTONOMY'.
enum
{
  cg_msgs__msg__MuxMode__FULL_AUTONOMY = 2
};

/// Constant 'FULL_TELEOP'.
enum
{
  cg_msgs__msg__MuxMode__FULL_TELEOP = 3
};

/// Constant 'HIGHEST_VALID_MODE'.
enum
{
  cg_msgs__msg__MuxMode__HIGHEST_VALID_MODE = 3
};

/// Struct defined in msg/MuxMode in the package cg_msgs.
typedef struct cg_msgs__msg__MuxMode
{
  uint8_t mode;
} cg_msgs__msg__MuxMode;

// Struct for a sequence of cg_msgs__msg__MuxMode.
typedef struct cg_msgs__msg__MuxMode__Sequence
{
  cg_msgs__msg__MuxMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__msg__MuxMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__MSG__DETAIL__MUX_MODE__STRUCT_H_
