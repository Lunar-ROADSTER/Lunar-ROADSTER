// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:msg/ToolInfo.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__TOOL_INFO__STRUCT_HPP_
#define LX_MSGS__MSG__DETAIL__TOOL_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lx_msgs__msg__ToolInfo __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__msg__ToolInfo __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ToolInfo_
{
  using Type = ToolInfo_<ContainerAllocator>;

  explicit ToolInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drum_pos = 0.0;
      this->drum_current = 0.0;
    }
  }

  explicit ToolInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drum_pos = 0.0;
      this->drum_current = 0.0;
    }
  }

  // field types and members
  using _drum_pos_type =
    double;
  _drum_pos_type drum_pos;
  using _drum_current_type =
    double;
  _drum_current_type drum_current;

  // setters for named parameter idiom
  Type & set__drum_pos(
    const double & _arg)
  {
    this->drum_pos = _arg;
    return *this;
  }
  Type & set__drum_current(
    const double & _arg)
  {
    this->drum_current = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::msg::ToolInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::msg::ToolInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::msg::ToolInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::msg::ToolInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::ToolInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::ToolInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::ToolInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::ToolInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::msg::ToolInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::msg::ToolInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__msg__ToolInfo
    std::shared_ptr<lx_msgs::msg::ToolInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__msg__ToolInfo
    std::shared_ptr<lx_msgs::msg::ToolInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ToolInfo_ & other) const
  {
    if (this->drum_pos != other.drum_pos) {
      return false;
    }
    if (this->drum_current != other.drum_current) {
      return false;
    }
    return true;
  }
  bool operator!=(const ToolInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ToolInfo_

// alias to use template instance with default allocator
using ToolInfo =
  lx_msgs::msg::ToolInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__TOOL_INFO__STRUCT_HPP_
