// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kindr_msgs:msg/VectorAtPosition.idl
// generated code does not contain a copyright notice

#ifndef KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__STRUCT_HPP_
#define KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'vector'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kindr_msgs__msg__VectorAtPosition __attribute__((deprecated))
#else
# define DEPRECATED__kindr_msgs__msg__VectorAtPosition __declspec(deprecated)
#endif

namespace kindr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VectorAtPosition_
{
  using Type = VectorAtPosition_<ContainerAllocator>;

  explicit VectorAtPosition_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    vector(_init),
    position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->name = "";
      this->position_frame_id = "";
    }
  }

  explicit VectorAtPosition_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    name(_alloc),
    vector(_alloc, _init),
    position(_alloc, _init),
    position_frame_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->name = "";
      this->position_frame_id = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _type_type =
    uint8_t;
  _type_type type;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _vector_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _vector_type vector;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _position_frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _position_frame_id_type position_frame_id;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__vector(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->vector = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__position_frame_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->position_frame_id = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TYPE_TYPELESS =
    0u;
  static constexpr uint8_t TYPE_JERK =
    6u;
  static constexpr uint8_t TYPE_ACCELERATION =
    7u;
  static constexpr uint8_t TYPE_VELOCITY =
    8u;
  static constexpr uint8_t TYPE_POSITION =
    9u;
  static constexpr uint8_t TYPE_FORCE =
    10u;
  static constexpr uint8_t TYPE_MOMEMTUM =
    11u;
  static constexpr uint8_t TYPE_ANGULAR_JERK =
    12u;
  static constexpr uint8_t TYPE_ANGULAR_ACCELERATION =
    13u;
  static constexpr uint8_t TYPE_ANGULAR_VELOCITY =
    14u;
  static constexpr uint8_t TYPE_TORQUE =
    16u;
  static constexpr uint8_t TYPE_ANGULAR_MOMEMTUM =
    17u;

  // pointer types
  using RawPtr =
    kindr_msgs::msg::VectorAtPosition_<ContainerAllocator> *;
  using ConstRawPtr =
    const kindr_msgs::msg::VectorAtPosition_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kindr_msgs::msg::VectorAtPosition_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kindr_msgs::msg::VectorAtPosition_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kindr_msgs::msg::VectorAtPosition_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kindr_msgs::msg::VectorAtPosition_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kindr_msgs::msg::VectorAtPosition_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kindr_msgs::msg::VectorAtPosition_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kindr_msgs::msg::VectorAtPosition_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kindr_msgs::msg::VectorAtPosition_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kindr_msgs__msg__VectorAtPosition
    std::shared_ptr<kindr_msgs::msg::VectorAtPosition_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kindr_msgs__msg__VectorAtPosition
    std::shared_ptr<kindr_msgs::msg::VectorAtPosition_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VectorAtPosition_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->vector != other.vector) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->position_frame_id != other.position_frame_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const VectorAtPosition_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VectorAtPosition_

// alias to use template instance with default allocator
using VectorAtPosition =
  kindr_msgs::msg::VectorAtPosition_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_TYPELESS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_JERK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_ACCELERATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_VELOCITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_POSITION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_FORCE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_MOMEMTUM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_ANGULAR_JERK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_ANGULAR_ACCELERATION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_ANGULAR_VELOCITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_TORQUE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t VectorAtPosition_<ContainerAllocator>::TYPE_ANGULAR_MOMEMTUM;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace kindr_msgs

#endif  // KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__STRUCT_HPP_
