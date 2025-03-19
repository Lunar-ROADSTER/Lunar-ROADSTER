// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lx_msgs:srv/BermService.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lx_msgs/srv/detail/berm_service__rosidl_typesupport_introspection_c.h"
#include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lx_msgs/srv/detail/berm_service__functions.h"
#include "lx_msgs/srv/detail/berm_service__struct.h"


// Include directives for member types
// Member `berm`
#include "lx_msgs/msg/berm_config.h"
// Member `berm`
#include "lx_msgs/msg/detail/berm_config__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lx_msgs__srv__BermService_Request__init(message_memory);
}

void lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_fini_function(void * message_memory)
{
  lx_msgs__srv__BermService_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_message_member_array[1] = {
  {
    "berm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__srv__BermService_Request, berm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_message_members = {
  "lx_msgs__srv",  // message namespace
  "BermService_Request",  // message name
  1,  // number of fields
  sizeof(lx_msgs__srv__BermService_Request),
  lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_message_member_array,  // message members
  lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_message_type_support_handle = {
  0,
  &lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, BermService_Request)() {
  lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, msg, BermConfig)();
  if (!lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_message_type_support_handle.typesupport_identifier) {
    lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lx_msgs__srv__BermService_Request__rosidl_typesupport_introspection_c__BermService_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "lx_msgs/srv/detail/berm_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "lx_msgs/srv/detail/berm_service__functions.h"
// already included above
// #include "lx_msgs/srv/detail/berm_service__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lx_msgs__srv__BermService_Response__init(message_memory);
}

void lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_fini_function(void * message_memory)
{
  lx_msgs__srv__BermService_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__srv__BermService_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_message_members = {
  "lx_msgs__srv",  // message namespace
  "BermService_Response",  // message name
  1,  // number of fields
  sizeof(lx_msgs__srv__BermService_Response),
  lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_message_member_array,  // message members
  lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_message_type_support_handle = {
  0,
  &lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, BermService_Response)() {
  if (!lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_message_type_support_handle.typesupport_identifier) {
    lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lx_msgs__srv__BermService_Response__rosidl_typesupport_introspection_c__BermService_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "lx_msgs/srv/detail/berm_service__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers lx_msgs__srv__detail__berm_service__rosidl_typesupport_introspection_c__BermService_service_members = {
  "lx_msgs__srv",  // service namespace
  "BermService",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // lx_msgs__srv__detail__berm_service__rosidl_typesupport_introspection_c__BermService_Request_message_type_support_handle,
  NULL  // response message
  // lx_msgs__srv__detail__berm_service__rosidl_typesupport_introspection_c__BermService_Response_message_type_support_handle
};

static rosidl_service_type_support_t lx_msgs__srv__detail__berm_service__rosidl_typesupport_introspection_c__BermService_service_type_support_handle = {
  0,
  &lx_msgs__srv__detail__berm_service__rosidl_typesupport_introspection_c__BermService_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, BermService_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, BermService_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, BermService)() {
  if (!lx_msgs__srv__detail__berm_service__rosidl_typesupport_introspection_c__BermService_service_type_support_handle.typesupport_identifier) {
    lx_msgs__srv__detail__berm_service__rosidl_typesupport_introspection_c__BermService_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)lx_msgs__srv__detail__berm_service__rosidl_typesupport_introspection_c__BermService_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, BermService_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, srv, BermService_Response)()->data;
  }

  return &lx_msgs__srv__detail__berm_service__rosidl_typesupport_introspection_c__BermService_service_type_support_handle;
}
