// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lx_msgs:msg/BermConfig.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lx_msgs/msg/detail/berm_config__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace lx_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BermConfig_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lx_msgs::msg::BermConfig(_init);
}

void BermConfig_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lx_msgs::msg::BermConfig *>(message_memory);
  typed_message->~BermConfig();
}

size_t size_function__BermConfig__berm_configuration(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::PointStamped> *>(untyped_member);
  return member->size();
}

const void * get_const_function__BermConfig__berm_configuration(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::PointStamped> *>(untyped_member);
  return &member[index];
}

void * get_function__BermConfig__berm_configuration(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::PointStamped> *>(untyped_member);
  return &member[index];
}

void fetch_function__BermConfig__berm_configuration(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::PointStamped *>(
    get_const_function__BermConfig__berm_configuration(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::PointStamped *>(untyped_value);
  value = item;
}

void assign_function__BermConfig__berm_configuration(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::PointStamped *>(
    get_function__BermConfig__berm_configuration(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::PointStamped *>(untyped_value);
  item = value;
}

void resize_function__BermConfig__berm_configuration(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::PointStamped> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BermConfig_message_member_array[1] = {
  {
    "berm_configuration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::PointStamped>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs::msg::BermConfig, berm_configuration),  // bytes offset in struct
    nullptr,  // default value
    size_function__BermConfig__berm_configuration,  // size() function pointer
    get_const_function__BermConfig__berm_configuration,  // get_const(index) function pointer
    get_function__BermConfig__berm_configuration,  // get(index) function pointer
    fetch_function__BermConfig__berm_configuration,  // fetch(index, &value) function pointer
    assign_function__BermConfig__berm_configuration,  // assign(index, value) function pointer
    resize_function__BermConfig__berm_configuration  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BermConfig_message_members = {
  "lx_msgs::msg",  // message namespace
  "BermConfig",  // message name
  1,  // number of fields
  sizeof(lx_msgs::msg::BermConfig),
  BermConfig_message_member_array,  // message members
  BermConfig_init_function,  // function to initialize message memory (memory has to be allocated)
  BermConfig_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BermConfig_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BermConfig_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace lx_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lx_msgs::msg::BermConfig>()
{
  return &::lx_msgs::msg::rosidl_typesupport_introspection_cpp::BermConfig_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lx_msgs, msg, BermConfig)() {
  return &::lx_msgs::msg::rosidl_typesupport_introspection_cpp::BermConfig_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
