// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from grid_map_msgs:msg/GridMapInfo.idl
// generated code does not contain a copyright notice
#include "grid_map_msgs/msg/detail/grid_map_info__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "grid_map_msgs/msg/detail/grid_map_info__struct.hpp"

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
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Pose &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::Pose &);

size_t get_serialized_size(
  const geometry_msgs::msg::Pose &,
  size_t current_alignment);

size_t
max_serialized_size_Pose(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace grid_map_msgs
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_serialize(
  const grid_map_msgs::msg::GridMapInfo & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: resolution
  rv = ucdr_serialize_double(cdr, ros_message.resolution);
  // Member: length_x
  rv = ucdr_serialize_double(cdr, ros_message.length_x);
  // Member: length_y
  rv = ucdr_serialize_double(cdr, ros_message.length_y);
  // Member: pose
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.pose,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  grid_map_msgs::msg::GridMapInfo & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: resolution
  rv = ucdr_deserialize_double(cdr, &ros_message.resolution);
  // Member: length_x
  rv = ucdr_deserialize_double(cdr, &ros_message.length_x);
  // Member: length_y
  rv = ucdr_deserialize_double(cdr, &ros_message.length_y);
  // Member: pose
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.pose);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
get_serialized_size(
  const grid_map_msgs::msg::GridMapInfo & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: resolution
  {
    const size_t item_size = sizeof(ros_message.resolution);
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
  // Member: pose
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.pose,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_grid_map_msgs
max_serialized_size_GridMapInfo(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: resolution
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: length_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: length_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: pose
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Pose(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _GridMapInfo__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const grid_map_msgs::msg::GridMapInfo *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GridMapInfo__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<grid_map_msgs::msg::GridMapInfo *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GridMapInfo__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const grid_map_msgs::msg::GridMapInfo *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GridMapInfo__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const grid_map_msgs::msg::GridMapInfo *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _GridMapInfo__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_GridMapInfo(&full_bounded, 0);
}

static message_type_support_callbacks_t _GridMapInfo__callbacks = {
  "grid_map_msgs::msg",
  "GridMapInfo",
  _GridMapInfo__cdr_serialize,
  _GridMapInfo__cdr_deserialize,
  _GridMapInfo__get_serialized_size,
  _GridMapInfo__get_serialized_size_with_initial_alignment,
  _GridMapInfo__max_serialized_size
};

static rosidl_message_type_support_t _GridMapInfo__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_GridMapInfo__callbacks,
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
get_message_type_support_handle<grid_map_msgs::msg::GridMapInfo>()
{
  return &grid_map_msgs::msg::typesupport_microxrcedds_cpp::_GridMapInfo__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, grid_map_msgs, msg, GridMapInfo)() {
  return &grid_map_msgs::msg::typesupport_microxrcedds_cpp::_GridMapInfo__handle;
}

#ifdef __cplusplus
}
#endif
