// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cg_msgs:srv/EnableWorksystem.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__STRUCT_H_
#define CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/EnableWorksystem in the package cg_msgs.
typedef struct cg_msgs__srv__EnableWorksystem_Request
{
  bool enable_worksystem;
} cg_msgs__srv__EnableWorksystem_Request;

// Struct for a sequence of cg_msgs__srv__EnableWorksystem_Request.
typedef struct cg_msgs__srv__EnableWorksystem_Request__Sequence
{
  cg_msgs__srv__EnableWorksystem_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__srv__EnableWorksystem_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/EnableWorksystem in the package cg_msgs.
typedef struct cg_msgs__srv__EnableWorksystem_Response
{
  bool worksystem_enabled;
} cg_msgs__srv__EnableWorksystem_Response;

// Struct for a sequence of cg_msgs__srv__EnableWorksystem_Response.
typedef struct cg_msgs__srv__EnableWorksystem_Response__Sequence
{
  cg_msgs__srv__EnableWorksystem_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cg_msgs__srv__EnableWorksystem_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__STRUCT_H_
