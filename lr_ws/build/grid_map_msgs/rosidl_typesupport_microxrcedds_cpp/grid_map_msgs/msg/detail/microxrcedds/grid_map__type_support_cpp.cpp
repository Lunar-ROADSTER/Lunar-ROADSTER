// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from grid_map_msgs:msg/GridMap.idl
// generated code does not contain a copyright notice
#include "grid_map_msgs/msg/detail/grid_map__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "grid_map_msgs/msg/detail/grid_map__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  std_msgs::msg::Header &);

size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);

size_t
max_serialized_size_Header(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace std_msgs

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

namespace std_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Float32MultiArray &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  std_msgs::msg::Float32MultiArray &);

size_t get_serialized_size(
  const std_msgs::msg::Float32MultiArray &,
  size_t current_alignment);

size_t
max_serialized_size_Float32MultiArray(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace std_msgs


namespace grid_map_msgs
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_serialize(
  const grid_map_msgs::msg::GridMap & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: header
  rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: info
  rv = grid_map_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.info,
    cdr);
  // Member: layers
  {
    size_t size = ros_message.layers.size();
    rv = ucdr_serialize_uint32_t(cdr, size);
    for (size_t i = 0; rv && i < size; ++i) {
      rv = ucdr_serialize_string(cdr, ros_message.layers[i].c_str());
    }
  }
  // Member: basic_layers
  {
    size_t size = ros_message.basic_layers.size();
    rv = ucdr_serialize_uint32_t(cdr, size);
    for (size_t i = 0; rv && i < size; ++i) {
      rv = ucdr_serialize_string(cdr, ros_message.basic_layers[i].c_str());
    }
  }
  // Member: data
  {
    size_t size = ros_message.data.size();
    rv = ucdr_serialize_uint32_t(cdr, size);

    size_t i = 0;
    while (i < size && rv) {
      rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
        ros_message.data[i],
        cdr);
      i++;
    }
  }
  // Member: outer_start_index
  rv = ucdr_serialize_uint16_t(cdr, ros_message.outer_start_index);
  // Member: inner_start_index
  rv = ucdr_serialize_uint16_t(cdr, ros_message.inner_start_index);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  grid_map_msgs::msg::GridMap & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: header
  rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.header);
  // Member: info
  rv = grid_map_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.info);
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
  // Member: basic_layers
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if (size > ros_message.basic_layers.capacity()) {
      ros_message.basic_layers.resize(size);
    } else {
      ros_message.basic_layers.resize(ros_message.basic_layers.capacity());
    }

    for (size_t i = 0; rv && i < size; i++) {
      uint32_t capacity = ros_message.basic_layers[i].capacity();
      char * temp = static_cast<char *>(malloc(capacity * sizeof(char)));
      rv = ucdr_deserialize_string(cdr, temp, capacity);
      if (rv) {
        std::string stemp(temp);
        stemp.shrink_to_fit();
        ros_message.basic_layers[i] = std::move(stemp);
      }
      free(temp);
    }
  }
  // Member: data
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);
    ros_message.data.resize(size);

    size_t i = 0;
    while (i < size && rv) {
      rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
        cdr,
        ros_message.data[i]);
      i++;
    }
  }
  // Member: outer_start_index
  rv = ucdr_deserialize_uint16_t(cdr, &ros_message.outer_start_index);
  // Member: inner_start_index
  rv = ucdr_deserialize_uint16_t(cdr, &ros_message.inner_start_index);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
get_serialized_size(
  const grid_map_msgs::msg::GridMap & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment += std_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.header,
    current_alignment);
  // Member: info
  current_alignment += grid_map_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.info,
    current_alignment);
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
  // Member: basic_layers
  {
  // Member is abstractsequence
    const size_t sequence_size = ros_message.basic_layers.size();
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for (size_t i = 0; i < sequence_size; i++) {
      const size_t item_size = ros_message.basic_layers[i].size() + 1;
      current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
    }
  }
  // Member: data
  {
  // Member is abstractsequence
    const size_t sequence_size = ros_message.data.size();
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for (size_t i = 0; i < sequence_size; i++) {
      const size_t item_size = std_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
        ros_message.data[i],
        current_alignment);
      current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
    }
  }
  // Member: outer_start_index
  {
    const size_t item_size = sizeof(ros_message.outer_start_index);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: inner_start_index
  {
    const size_t item_size = sizeof(ros_message.inner_start_index);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
max_serialized_size_GridMap(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment += std_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Header(
    full_bounded,
    current_alignment);
  // Member: info
  current_alignment += grid_map_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_GridMapInfo(
    full_bounded,
    current_alignment);
  // Member: layers
  {
    *full_bounded = false;
  }
  // Member: basic_layers
  {
    *full_bounded = false;
  }
  // Member: data
  {
    *full_bounded = false;
  }
  // Member: outer_start_index
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint16_t)) + sizeof(uint16_t);
  // Member: inner_start_index
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint16_t)) + sizeof(uint16_t);

  return current_alignment - initial_alignment;
}

static bool _GridMap__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const grid_map_msgs::msg::GridMap *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GridMap__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<grid_map_msgs::msg::GridMap *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GridMap__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const grid_map_msgs::msg::GridMap *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GridMap__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const grid_map_msgs::msg::GridMap *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _GridMap__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_GridMap(&full_bounded, 0);
}

static message_type_support_callbacks_t _GridMap__callbacks = {
  "grid_map_msgs::msg",
  "GridMap",
  _GridMap__cdr_serialize,
  _GridMap__cdr_deserialize,
  _GridMap__get_serialized_size,
  _GridMap__get_serialized_size_with_initial_alignment,
  _GridMap__max_serialized_size
};

static rosidl_message_type_support_t _GridMap__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GridMap__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace msg

}  // namespace grid_map_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_grid_map_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<grid_map_msgs::msg::GridMap>()
{
  return &grid_map_msgs::msg::typesupport_microxrcedds_cpp::_GridMap__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, msg, GridMap)() {
  return &grid_map_msgs::msg::typesupport_microxrcedds_cpp::_GridMap__handle;
}

#ifdef __cplusplus
}
#endif
