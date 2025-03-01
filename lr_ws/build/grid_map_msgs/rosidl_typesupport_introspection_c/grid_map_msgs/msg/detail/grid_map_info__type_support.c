// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from grid_map_msgs:msg/GridMapInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "grid_map_msgs/msg/detail/grid_map_info__rosidl_typesupport_introspection_c.h"
#include "grid_map_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "grid_map_msgs/msg/detail/grid_map_info__functions.h"
#include "grid_map_msgs/msg/detail/grid_map_info__struct.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grid_map_msgs__msg__GridMapInfo__init(message_memory);
}

void grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_fini_function(void * message_memory)
{
  grid_map_msgs__msg__GridMapInfo__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_message_member_array[4] = {
  {
    "resolution",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMapInfo, resolution),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "length_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMapInfo, length_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "length_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMapInfo, length_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMapInfo, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_message_members = {
  "grid_map_msgs__msg",  // message namespace
  "GridMapInfo",  // message name
  4,  // number of fields
  sizeof(grid_map_msgs__msg__GridMapInfo),
  grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_message_member_array,  // message members
  grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_message_type_support_handle = {
  0,
  &grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grid_map_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, msg, GridMapInfo)() {
  grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_message_type_support_handle.typesupport_identifier) {
    grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grid_map_msgs__msg__GridMapInfo__rosidl_typesupport_introspection_c__GridMapInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
