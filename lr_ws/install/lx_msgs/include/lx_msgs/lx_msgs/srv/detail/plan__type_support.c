// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lx_msgs:srv/Plan.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lx_msgs/srv/detail/plan__rosidl_typesupport_introspection_c.h"
#include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lx_msgs/srv/detail/plan__functions.h"
#include "lx_msgs/srv/detail/plan__struct.h"


// Include directives for member types
// Member `berm_input`
#include "geometry_msgs/msg/point.h"
// Member `berm_input`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lx_msgs__srv__Plan_Request__init(message_memory);
}

void lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_fini_function(void * message_memory)
{
  lx_msgs__srv__Plan_Request__fini(message_memory);
}

size_t lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__size_function__Plan_Request__berm_input(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__get_const_function__Plan_Request__berm_input(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__get_function__Plan_Request__berm_input(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__fetch_function__Plan_Request__berm_input(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__get_const_function__Plan_Request__berm_input(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__assign_function__Plan_Request__berm_input(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__get_function__Plan_Request__berm_input(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__resize_function__Plan_Request__berm_input(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_message_member_array[4] = {
  {
    "berm_input",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__srv__Plan_Request, berm_input),  // bytes offset in struct
    NULL,  // default value
    lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__size_function__Plan_Request__berm_input,  // size() function pointer
    lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__get_const_function__Plan_Request__berm_input,  // get_const(index) function pointer
    lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__get_function__Plan_Request__berm_input,  // get(index) function pointer
    lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__fetch_function__Plan_Request__berm_input,  // fetch(index, &value) function pointer
    lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__assign_function__Plan_Request__berm_input,  // assign(index, value) function pointer
    lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__resize_function__Plan_Request__berm_input  // resize(index) function pointer
  },
  {
    "berm_height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__srv__Plan_Request, berm_height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "section_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__srv__Plan_Request, section_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "new_plan",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__srv__Plan_Request, new_plan),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_message_members = {
  "lx_msgs__srv",  // message namespace
  "Plan_Request",  // message name
  4,  // number of fields
  sizeof(lx_msgs__srv__Plan_Request),
  lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_message_member_array,  // message members
  lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_message_type_support_handle = {
  0,
  &lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, Plan_Request)() {
  lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_message_type_support_handle.typesupport_identifier) {
    lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lx_msgs__srv__Plan_Request__rosidl_typesupport_introspection_c__Plan_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "lx_msgs/srv/detail/plan__rosidl_typesupport_introspection_c.h"
// already included above
// #include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "lx_msgs/srv/detail/plan__functions.h"
// already included above
// #include "lx_msgs/srv/detail/plan__struct.h"


// Include directives for member types
// Member `plan`
#include "lx_msgs/msg/planned_task.h"
// Member `plan`
#include "lx_msgs/msg/detail/planned_task__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lx_msgs__srv__Plan_Response__init(message_memory);
}

void lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_fini_function(void * message_memory)
{
  lx_msgs__srv__Plan_Response__fini(message_memory);
}

size_t lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__size_function__Plan_Response__plan(
  const void * untyped_member)
{
  const lx_msgs__msg__PlannedTask__Sequence * member =
    (const lx_msgs__msg__PlannedTask__Sequence *)(untyped_member);
  return member->size;
}

const void * lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__get_const_function__Plan_Response__plan(
  const void * untyped_member, size_t index)
{
  const lx_msgs__msg__PlannedTask__Sequence * member =
    (const lx_msgs__msg__PlannedTask__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__get_function__Plan_Response__plan(
  void * untyped_member, size_t index)
{
  lx_msgs__msg__PlannedTask__Sequence * member =
    (lx_msgs__msg__PlannedTask__Sequence *)(untyped_member);
  return &member->data[index];
}

void lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__fetch_function__Plan_Response__plan(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lx_msgs__msg__PlannedTask * item =
    ((const lx_msgs__msg__PlannedTask *)
    lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__get_const_function__Plan_Response__plan(untyped_member, index));
  lx_msgs__msg__PlannedTask * value =
    (lx_msgs__msg__PlannedTask *)(untyped_value);
  *value = *item;
}

void lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__assign_function__Plan_Response__plan(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lx_msgs__msg__PlannedTask * item =
    ((lx_msgs__msg__PlannedTask *)
    lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__get_function__Plan_Response__plan(untyped_member, index));
  const lx_msgs__msg__PlannedTask * value =
    (const lx_msgs__msg__PlannedTask *)(untyped_value);
  *item = *value;
}

bool lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__resize_function__Plan_Response__plan(
  void * untyped_member, size_t size)
{
  lx_msgs__msg__PlannedTask__Sequence * member =
    (lx_msgs__msg__PlannedTask__Sequence *)(untyped_member);
  lx_msgs__msg__PlannedTask__Sequence__fini(member);
  return lx_msgs__msg__PlannedTask__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_message_member_array[1] = {
  {
    "plan",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__srv__Plan_Response, plan),  // bytes offset in struct
    NULL,  // default value
    lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__size_function__Plan_Response__plan,  // size() function pointer
    lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__get_const_function__Plan_Response__plan,  // get_const(index) function pointer
    lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__get_function__Plan_Response__plan,  // get(index) function pointer
    lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__fetch_function__Plan_Response__plan,  // fetch(index, &value) function pointer
    lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__assign_function__Plan_Response__plan,  // assign(index, value) function pointer
    lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__resize_function__Plan_Response__plan  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_message_members = {
  "lx_msgs__srv",  // message namespace
  "Plan_Response",  // message name
  1,  // number of fields
  sizeof(lx_msgs__srv__Plan_Response),
  lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_message_member_array,  // message members
  lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_message_type_support_handle = {
  0,
  &lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, Plan_Response)() {
  lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, msg, PlannedTask)();
  if (!lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_message_type_support_handle.typesupport_identifier) {
    lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lx_msgs__srv__Plan_Response__rosidl_typesupport_introspection_c__Plan_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "lx_msgs/srv/detail/plan__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers lx_msgs__srv__detail__plan__rosidl_typesupport_introspection_c__Plan_service_members = {
  "lx_msgs__srv",  // service namespace
  "Plan",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // lx_msgs__srv__detail__plan__rosidl_typesupport_introspection_c__Plan_Request_message_type_support_handle,
  NULL  // response message
  // lx_msgs__srv__detail__plan__rosidl_typesupport_introspection_c__Plan_Response_message_type_support_handle
};

static rosidl_service_type_support_t lx_msgs__srv__detail__plan__rosidl_typesupport_introspection_c__Plan_service_type_support_handle = {
  0,
  &lx_msgs__srv__detail__plan__rosidl_typesupport_introspection_c__Plan_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, Plan_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, Plan_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, Plan)() {
  if (!lx_msgs__srv__detail__plan__rosidl_typesupport_introspection_c__Plan_service_type_support_handle.typesupport_identifier) {
    lx_msgs__srv__detail__plan__rosidl_typesupport_introspection_c__Plan_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)lx_msgs__srv__detail__plan__rosidl_typesupport_introspection_c__Plan_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, Plan_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, Plan_Response)()->data;
  }

  return &lx_msgs__srv__detail__plan__rosidl_typesupport_introspection_c__Plan_service_type_support_handle;
}
