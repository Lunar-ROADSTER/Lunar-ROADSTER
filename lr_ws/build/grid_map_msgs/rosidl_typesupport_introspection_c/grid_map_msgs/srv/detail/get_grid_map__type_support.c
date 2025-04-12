// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from grid_map_msgs:srv/GetGridMap.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "grid_map_msgs/srv/detail/get_grid_map__rosidl_typesupport_introspection_c.h"
#include "grid_map_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "grid_map_msgs/srv/detail/get_grid_map__functions.h"
#include "grid_map_msgs/srv/detail/get_grid_map__struct.h"


// Include directives for member types
// Member `frame_id`
// Member `layers`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grid_map_msgs__srv__GetGridMap_Request__init(message_memory);
}

void grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_fini_function(void * message_memory)
{
  grid_map_msgs__srv__GetGridMap_Request__fini(message_memory);
}

size_t grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__size_function__GetGridMap_Request__layers(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__get_const_function__GetGridMap_Request__layers(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__get_function__GetGridMap_Request__layers(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__fetch_function__GetGridMap_Request__layers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__get_const_function__GetGridMap_Request__layers(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__assign_function__GetGridMap_Request__layers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__get_function__GetGridMap_Request__layers(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__resize_function__GetGridMap_Request__layers(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_message_member_array[6] = {
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__srv__GetGridMap_Request, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__srv__GetGridMap_Request, position_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__srv__GetGridMap_Request, position_y),  // bytes offset in struct
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
    offsetof(grid_map_msgs__srv__GetGridMap_Request, length_x),  // bytes offset in struct
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
    offsetof(grid_map_msgs__srv__GetGridMap_Request, length_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "layers",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__srv__GetGridMap_Request, layers),  // bytes offset in struct
    NULL,  // default value
    grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__size_function__GetGridMap_Request__layers,  // size() function pointer
    grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__get_const_function__GetGridMap_Request__layers,  // get_const(index) function pointer
    grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__get_function__GetGridMap_Request__layers,  // get(index) function pointer
    grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__fetch_function__GetGridMap_Request__layers,  // fetch(index, &value) function pointer
    grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__assign_function__GetGridMap_Request__layers,  // assign(index, value) function pointer
    grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__resize_function__GetGridMap_Request__layers  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_message_members = {
  "grid_map_msgs__srv",  // message namespace
  "GetGridMap_Request",  // message name
  6,  // number of fields
  sizeof(grid_map_msgs__srv__GetGridMap_Request),
  grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_message_member_array,  // message members
  grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_message_type_support_handle = {
  0,
  &grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grid_map_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, srv, GetGridMap_Request)() {
  if (!grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_message_type_support_handle.typesupport_identifier) {
    grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grid_map_msgs__srv__GetGridMap_Request__rosidl_typesupport_introspection_c__GetGridMap_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "grid_map_msgs/srv/detail/get_grid_map__rosidl_typesupport_introspection_c.h"
// already included above
// #include "grid_map_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "grid_map_msgs/srv/detail/get_grid_map__functions.h"
// already included above
// #include "grid_map_msgs/srv/detail/get_grid_map__struct.h"


// Include directives for member types
// Member `map`
#include "grid_map_msgs/msg/grid_map.h"
// Member `map`
#include "grid_map_msgs/msg/detail/grid_map__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grid_map_msgs__srv__GetGridMap_Response__init(message_memory);
}

void grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_fini_function(void * message_memory)
{
  grid_map_msgs__srv__GetGridMap_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_message_member_array[1] = {
  {
    "map",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__srv__GetGridMap_Response, map),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_message_members = {
  "grid_map_msgs__srv",  // message namespace
  "GetGridMap_Response",  // message name
  1,  // number of fields
  sizeof(grid_map_msgs__srv__GetGridMap_Response),
  grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_message_member_array,  // message members
  grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_message_type_support_handle = {
  0,
  &grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grid_map_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, srv, GetGridMap_Response)() {
  grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, msg, GridMap)();
  if (!grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_message_type_support_handle.typesupport_identifier) {
    grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grid_map_msgs__srv__GetGridMap_Response__rosidl_typesupport_introspection_c__GetGridMap_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "grid_map_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "grid_map_msgs/srv/detail/get_grid_map__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers grid_map_msgs__srv__detail__get_grid_map__rosidl_typesupport_introspection_c__GetGridMap_service_members = {
  "grid_map_msgs__srv",  // service namespace
  "GetGridMap",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // grid_map_msgs__srv__detail__get_grid_map__rosidl_typesupport_introspection_c__GetGridMap_Request_message_type_support_handle,
  NULL  // response message
  // grid_map_msgs__srv__detail__get_grid_map__rosidl_typesupport_introspection_c__GetGridMap_Response_message_type_support_handle
};

static rosidl_service_type_support_t grid_map_msgs__srv__detail__get_grid_map__rosidl_typesupport_introspection_c__GetGridMap_service_type_support_handle = {
  0,
  &grid_map_msgs__srv__detail__get_grid_map__rosidl_typesupport_introspection_c__GetGridMap_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, srv, GetGridMap_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, srv, GetGridMap_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grid_map_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, srv, GetGridMap)() {
  if (!grid_map_msgs__srv__detail__get_grid_map__rosidl_typesupport_introspection_c__GetGridMap_service_type_support_handle.typesupport_identifier) {
    grid_map_msgs__srv__detail__get_grid_map__rosidl_typesupport_introspection_c__GetGridMap_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)grid_map_msgs__srv__detail__get_grid_map__rosidl_typesupport_introspection_c__GetGridMap_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, srv, GetGridMap_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, srv, GetGridMap_Response)()->data;
  }

  return &grid_map_msgs__srv__detail__get_grid_map__rosidl_typesupport_introspection_c__GetGridMap_service_type_support_handle;
}
