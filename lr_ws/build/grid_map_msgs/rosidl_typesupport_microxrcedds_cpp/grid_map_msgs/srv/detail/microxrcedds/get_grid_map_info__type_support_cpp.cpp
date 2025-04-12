// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from grid_map_msgs:srv/GetGridMapInfo.idl
// generated code does not contain a copyright notice
#include "grid_map_msgs/srv/detail/get_grid_map_info__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "grid_map_msgs/srv/detail/get_grid_map_info__struct.hpp"

#include <limits>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cstring>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
#include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions

namespace grid_map_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_serialize(
  const grid_map_msgs::srv::GetGridMapInfo_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: structure_needs_at_least_one_member
  rv = ucdr_serialize_uint8_t(cdr, ros_message.structure_needs_at_least_one_member);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  grid_map_msgs::srv::GetGridMapInfo_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: structure_needs_at_least_one_member
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message.structure_needs_at_least_one_member);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
get_serialized_size(
  const grid_map_msgs::srv::GetGridMapInfo_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  {
    const size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
max_serialized_size_GetGridMapInfo_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);

  return current_alignment - initial_alignment;
}

static bool _GetGridMapInfo_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMapInfo_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GetGridMapInfo_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<grid_map_msgs::srv::GetGridMapInfo_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GetGridMapInfo_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMapInfo_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GetGridMapInfo_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMapInfo_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _GetGridMapInfo_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_GetGridMapInfo_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _GetGridMapInfo_Request__callbacks = {
  "grid_map_msgs::srv",
  "GetGridMapInfo_Request",
  _GetGridMapInfo_Request__cdr_serialize,
  _GetGridMapInfo_Request__cdr_deserialize,
  _GetGridMapInfo_Request__get_serialized_size,
  _GetGridMapInfo_Request__get_serialized_size_with_initial_alignment,
  _GetGridMapInfo_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetGridMapInfo_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GetGridMapInfo_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace grid_map_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_grid_map_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<grid_map_msgs::srv::GetGridMapInfo_Request>()
{
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMapInfo_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMapInfo_Request)() {
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMapInfo_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace grid_map_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const grid_map_msgs::msg::GridMapInfo &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  grid_map_msgs::msg::GridMapInfo &);

size_t get_serialized_size(
  const grid_map_msgs::msg::GridMapInfo &,
  size_t current_alignment);

size_t
max_serialized_size_GridMapInfo(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace grid_map_msgs


namespace grid_map_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_serialize(
  const grid_map_msgs::srv::GetGridMapInfo_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: info
  rv = grid_map_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.info,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  grid_map_msgs::srv::GetGridMapInfo_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: info
  rv = grid_map_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.info);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
get_serialized_size(
  const grid_map_msgs::srv::GetGridMapInfo_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: info
  current_alignment += grid_map_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.info,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
max_serialized_size_GetGridMapInfo_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: info
  current_alignment += grid_map_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_GridMapInfo(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _GetGridMapInfo_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMapInfo_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GetGridMapInfo_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<grid_map_msgs::srv::GetGridMapInfo_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GetGridMapInfo_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMapInfo_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GetGridMapInfo_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMapInfo_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _GetGridMapInfo_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_GetGridMapInfo_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _GetGridMapInfo_Response__callbacks = {
  "grid_map_msgs::srv",
  "GetGridMapInfo_Response",
  _GetGridMapInfo_Response__cdr_serialize,
  _GetGridMapInfo_Response__cdr_deserialize,
  _GetGridMapInfo_Response__get_serialized_size,
  _GetGridMapInfo_Response__get_serialized_size_with_initial_alignment,
  _GetGridMapInfo_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetGridMapInfo_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GetGridMapInfo_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace grid_map_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_grid_map_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<grid_map_msgs::srv::GetGridMapInfo_Response>()
{
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMapInfo_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMapInfo_Response)() {
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMapInfo_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/service_type_support_decl.hpp"

namespace grid_map_msgs
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

static service_type_support_callbacks_t _GetGridMapInfo__callbacks = {
  "grid_map_msgs::srv",
  "GetGridMapInfo",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMapInfo_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMapInfo_Response),
};

static rosidl_service_type_support_t _GetGridMapInfo__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GetGridMapInfo__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace grid_map_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_grid_map_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<grid_map_msgs::srv::GetGridMapInfo>()
{
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMapInfo__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMapInfo)() {
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMapInfo__handle;
}

#ifdef __cplusplus
}
#endif
