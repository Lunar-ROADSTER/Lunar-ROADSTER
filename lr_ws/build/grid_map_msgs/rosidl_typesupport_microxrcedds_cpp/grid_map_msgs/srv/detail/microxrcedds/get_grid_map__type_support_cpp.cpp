// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from grid_map_msgs:srv/GetGridMap.idl
// generated code does not contain a copyright notice
#include "grid_map_msgs/srv/detail/get_grid_map__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "grid_map_msgs/srv/detail/get_grid_map__struct.hpp"

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
  const grid_map_msgs::srv::GetGridMap_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: frame_id
  rv = ucdr_serialize_string(cdr, ros_message.frame_id.c_str());
  // Member: position_x
  rv = ucdr_serialize_double(cdr, ros_message.position_x);
  // Member: position_y
  rv = ucdr_serialize_double(cdr, ros_message.position_y);
  // Member: length_x
  rv = ucdr_serialize_double(cdr, ros_message.length_x);
  // Member: length_y
  rv = ucdr_serialize_double(cdr, ros_message.length_y);
  // Member: layers
  {
    size_t size = ros_message.layers.size();
    rv = ucdr_serialize_uint32_t(cdr, size);
    for (size_t i = 0; rv && i < size; ++i) {
      rv = ucdr_serialize_string(cdr, ros_message.layers[i].c_str());
    }
  }

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  grid_map_msgs::srv::GetGridMap_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: frame_id
  ros_message.frame_id.resize(ros_message.frame_id.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.frame_id[0], ros_message.frame_id.capacity());
  if (rv) {
    ros_message.frame_id.resize(std::strlen(&ros_message.frame_id[0]));
  }
  // Member: position_x
  rv = ucdr_deserialize_double(cdr, &ros_message.position_x);
  // Member: position_y
  rv = ucdr_deserialize_double(cdr, &ros_message.position_y);
  // Member: length_x
  rv = ucdr_deserialize_double(cdr, &ros_message.length_x);
  // Member: length_y
  rv = ucdr_deserialize_double(cdr, &ros_message.length_y);
  // Member: layers
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if (size > ros_message.layers.capacity()) {
      ros_message.layers.resize(size);
    } else {
      ros_message.layers.resize(ros_message.layers.capacity());
    }

    for (size_t i = 0; rv && i < size; i++) {
      uint32_t capacity = ros_message.layers[i].capacity();
      char * temp = static_cast<char *>(malloc(capacity * sizeof(char)));
      rv = ucdr_deserialize_string(cdr, temp, capacity);
      if (rv) {
        std::string stemp(temp);
        stemp.shrink_to_fit();
        ros_message.layers[i] = std::move(stemp);
      }
      free(temp);
    }
  }

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
get_serialized_size(
  const grid_map_msgs::srv::GetGridMap_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: frame_id
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.frame_id.size() + 1;
  // Member: position_x
  {
    const size_t item_size = sizeof(ros_message.position_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: position_y
  {
    const size_t item_size = sizeof(ros_message.position_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: length_x
  {
    const size_t item_size = sizeof(ros_message.length_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: length_y
  {
    const size_t item_size = sizeof(ros_message.length_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: layers
  {
  // Member is abstractsequence
    const size_t sequence_size = ros_message.layers.size();
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for (size_t i = 0; i < sequence_size; i++) {
      const size_t item_size = ros_message.layers[i].size() + 1;
      current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
max_serialized_size_GetGridMap_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: frame_id
  *full_bounded = false;
  // Member: position_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: position_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: length_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: length_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: layers
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static bool _GetGridMap_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMap_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GetGridMap_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<grid_map_msgs::srv::GetGridMap_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GetGridMap_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMap_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GetGridMap_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMap_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _GetGridMap_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_GetGridMap_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _GetGridMap_Request__callbacks = {
  "grid_map_msgs::srv",
  "GetGridMap_Request",
  _GetGridMap_Request__cdr_serialize,
  _GetGridMap_Request__cdr_deserialize,
  _GetGridMap_Request__get_serialized_size,
  _GetGridMap_Request__get_serialized_size_with_initial_alignment,
  _GetGridMap_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetGridMap_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GetGridMap_Request__callbacks,
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
get_message_type_support_handle<grid_map_msgs::srv::GetGridMap_Request>()
{
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMap_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMap_Request)() {
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMap_Request__handle;
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
  const grid_map_msgs::msg::GridMap &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  grid_map_msgs::msg::GridMap &);

size_t get_serialized_size(
  const grid_map_msgs::msg::GridMap &,
  size_t current_alignment);

size_t
max_serialized_size_GridMap(
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
  const grid_map_msgs::srv::GetGridMap_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: map
  rv = grid_map_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.map,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  grid_map_msgs::srv::GetGridMap_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: map
  rv = grid_map_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.map);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
get_serialized_size(
  const grid_map_msgs::srv::GetGridMap_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: map
  current_alignment += grid_map_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.map,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
max_serialized_size_GetGridMap_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: map
  current_alignment += grid_map_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_GridMap(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _GetGridMap_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMap_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GetGridMap_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<grid_map_msgs::srv::GetGridMap_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GetGridMap_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMap_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GetGridMap_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const grid_map_msgs::srv::GetGridMap_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _GetGridMap_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_GetGridMap_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _GetGridMap_Response__callbacks = {
  "grid_map_msgs::srv",
  "GetGridMap_Response",
  _GetGridMap_Response__cdr_serialize,
  _GetGridMap_Response__cdr_deserialize,
  _GetGridMap_Response__get_serialized_size,
  _GetGridMap_Response__get_serialized_size_with_initial_alignment,
  _GetGridMap_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetGridMap_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GetGridMap_Response__callbacks,
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
get_message_type_support_handle<grid_map_msgs::srv::GetGridMap_Response>()
{
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMap_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMap_Response)() {
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMap_Response__handle;
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

static service_type_support_callbacks_t _GetGridMap__callbacks = {
  "grid_map_msgs::srv",
  "GetGridMap",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMap_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMap_Response),
};

static rosidl_service_type_support_t _GetGridMap__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GetGridMap__callbacks,
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
get_service_type_support_handle<grid_map_msgs::srv::GetGridMap>()
{
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMap__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, srv, GetGridMap)() {
  return &grid_map_msgs::srv::typesupport_microxrcedds_cpp::_GetGridMap__handle;
}

#ifdef __cplusplus
}
#endif
