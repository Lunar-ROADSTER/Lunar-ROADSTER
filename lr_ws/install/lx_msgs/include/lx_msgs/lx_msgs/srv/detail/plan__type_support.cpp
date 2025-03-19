// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lx_msgs:srv/Plan.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lx_msgs/srv/detail/plan__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace lx_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void Plan_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lx_msgs::srv::Plan_Request(_init);
}

void Plan_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lx_msgs::srv::Plan_Request *>(message_memory);
  typed_message->~Plan_Request();
}

size_t size_function__Plan_Request__berm_input(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Plan_Request__berm_input(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__Plan_Request__berm_input(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__Plan_Request__berm_input(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__Plan_Request__berm_input(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__Plan_Request__berm_input(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__Plan_Request__berm_input(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__Plan_Request__berm_input(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Plan_Request_message_member_array[4] = {
  {
    "berm_input",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs::srv::Plan_Request, berm_input),  // bytes offset in struct
    nullptr,  // default value
    size_function__Plan_Request__berm_input,  // size() function pointer
    get_const_function__Plan_Request__berm_input,  // get_const(index) function pointer
    get_function__Plan_Request__berm_input,  // get(index) function pointer
    fetch_function__Plan_Request__berm_input,  // fetch(index, &value) function pointer
    assign_function__Plan_Request__berm_input,  // assign(index, value) function pointer
    resize_function__Plan_Request__berm_input  // resize(index) function pointer
  },
  {
    "berm_height",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs::srv::Plan_Request, berm_height),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "section_length",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs::srv::Plan_Request, section_length),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "new_plan",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs::srv::Plan_Request, new_plan),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Plan_Request_message_members = {
  "lx_msgs::srv",  // message namespace
  "Plan_Request",  // message name
  4,  // number of fields
  sizeof(lx_msgs::srv::Plan_Request),
  Plan_Request_message_member_array,  // message members
  Plan_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Plan_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Plan_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Plan_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace lx_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lx_msgs::srv::Plan_Request>()
{
  return &::lx_msgs::srv::rosidl_typesupport_introspection_cpp::Plan_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lx_msgs, srv, Plan_Request)() {
  return &::lx_msgs::srv::rosidl_typesupport_introspection_cpp::Plan_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "lx_msgs/srv/detail/plan__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace lx_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void Plan_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lx_msgs::srv::Plan_Response(_init);
}

void Plan_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lx_msgs::srv::Plan_Response *>(message_memory);
  typed_message->~Plan_Response();
}

size_t size_function__Plan_Response__plan(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lx_msgs::msg::PlannedTask> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Plan_Response__plan(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lx_msgs::msg::PlannedTask> *>(untyped_member);
  return &member[index];
}

void * get_function__Plan_Response__plan(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lx_msgs::msg::PlannedTask> *>(untyped_member);
  return &member[index];
}

void fetch_function__Plan_Response__plan(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lx_msgs::msg::PlannedTask *>(
    get_const_function__Plan_Response__plan(untyped_member, index));
  auto & value = *reinterpret_cast<lx_msgs::msg::PlannedTask *>(untyped_value);
  value = item;
}

void assign_function__Plan_Response__plan(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lx_msgs::msg::PlannedTask *>(
    get_function__Plan_Response__plan(untyped_member, index));
  const auto & value = *reinterpret_cast<const lx_msgs::msg::PlannedTask *>(untyped_value);
  item = value;
}

void resize_function__Plan_Response__plan(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lx_msgs::msg::PlannedTask> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Plan_Response_message_member_array[1] = {
  {
    "plan",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lx_msgs::msg::PlannedTask>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs::srv::Plan_Response, plan),  // bytes offset in struct
    nullptr,  // default value
    size_function__Plan_Response__plan,  // size() function pointer
    get_const_function__Plan_Response__plan,  // get_const(index) function pointer
    get_function__Plan_Response__plan,  // get(index) function pointer
    fetch_function__Plan_Response__plan,  // fetch(index, &value) function pointer
    assign_function__Plan_Response__plan,  // assign(index, value) function pointer
    resize_function__Plan_Response__plan  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Plan_Response_message_members = {
  "lx_msgs::srv",  // message namespace
  "Plan_Response",  // message name
  1,  // number of fields
  sizeof(lx_msgs::srv::Plan_Response),
  Plan_Response_message_member_array,  // message members
  Plan_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Plan_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Plan_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Plan_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace lx_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lx_msgs::srv::Plan_Response>()
{
  return &::lx_msgs::srv::rosidl_typesupport_introspection_cpp::Plan_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lx_msgs, srv, Plan_Response)() {
  return &::lx_msgs::srv::rosidl_typesupport_introspection_cpp::Plan_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "lx_msgs/srv/detail/plan__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace lx_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers Plan_service_members = {
  "lx_msgs::srv",  // service namespace
  "Plan",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<lx_msgs::srv::Plan>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t Plan_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Plan_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace lx_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<lx_msgs::srv::Plan>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::lx_msgs::srv::rosidl_typesupport_introspection_cpp::Plan_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::lx_msgs::srv::Plan_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::lx_msgs::srv::Plan_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lx_msgs, srv, Plan)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<lx_msgs::srv::Plan>();
}

#ifdef __cplusplus
}
#endif
