// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cg_msgs:msg/BeaconMultiTag.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cg_msgs/msg/detail/beacon_multi_tag__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cg_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BeaconMultiTag_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cg_msgs::msg::BeaconMultiTag(_init);
}

void BeaconMultiTag_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cg_msgs::msg::BeaconMultiTag *>(message_memory);
  typed_message->~BeaconMultiTag();
}

size_t size_function__BeaconMultiTag__TagsList(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__BeaconMultiTag__TagsList(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<cg_msgs::msg::BeaconTag, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__BeaconMultiTag__TagsList(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<cg_msgs::msg::BeaconTag, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__BeaconMultiTag__TagsList(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const cg_msgs::msg::BeaconTag *>(
    get_const_function__BeaconMultiTag__TagsList(untyped_member, index));
  auto & value = *reinterpret_cast<cg_msgs::msg::BeaconTag *>(untyped_value);
  value = item;
}

void assign_function__BeaconMultiTag__TagsList(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<cg_msgs::msg::BeaconTag *>(
    get_function__BeaconMultiTag__TagsList(untyped_member, index));
  const auto & value = *reinterpret_cast<const cg_msgs::msg::BeaconTag *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BeaconMultiTag_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_msgs::msg::BeaconMultiTag, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "TagsList",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<cg_msgs::msg::BeaconTag>(),  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(cg_msgs::msg::BeaconMultiTag, TagsList),  // bytes offset in struct
    nullptr,  // default value
    size_function__BeaconMultiTag__TagsList,  // size() function pointer
    get_const_function__BeaconMultiTag__TagsList,  // get_const(index) function pointer
    get_function__BeaconMultiTag__TagsList,  // get(index) function pointer
    fetch_function__BeaconMultiTag__TagsList,  // fetch(index, &value) function pointer
    assign_function__BeaconMultiTag__TagsList,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BeaconMultiTag_message_members = {
  "cg_msgs::msg",  // message namespace
  "BeaconMultiTag",  // message name
  2,  // number of fields
  sizeof(cg_msgs::msg::BeaconMultiTag),
  BeaconMultiTag_message_member_array,  // message members
  BeaconMultiTag_init_function,  // function to initialize message memory (memory has to be allocated)
  BeaconMultiTag_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BeaconMultiTag_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BeaconMultiTag_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cg_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cg_msgs::msg::BeaconMultiTag>()
{
  return &::cg_msgs::msg::rosidl_typesupport_introspection_cpp::BeaconMultiTag_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cg_msgs, msg, BeaconMultiTag)() {
  return &::cg_msgs::msg::rosidl_typesupport_introspection_cpp::BeaconMultiTag_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
