// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:msg/RoverCommand.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__ROVER_COMMAND__STRUCT_HPP_
#define LX_MSGS__MSG__DETAIL__ROVER_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'mobility_twist'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__msg__RoverCommand __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__msg__RoverCommand __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RoverCommand_
{
  using Type = RoverCommand_<ContainerAllocator>;

  explicit RoverCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mobility_twist(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->actuator_speed = 0.0;
      this->drum_speed = 0.0;
    }
  }

  explicit RoverCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mobility_twist(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->actuator_speed = 0.0;
      this->drum_speed = 0.0;
    }
  }

  // field types and members
  using _mobility_twist_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _mobility_twist_type mobility_twist;
  using _actuator_speed_type =
    double;
  _actuator_speed_type actuator_speed;
  using _drum_speed_type =
    double;
  _drum_speed_type drum_speed;

  // setters for named parameter idiom
  Type & set__mobility_twist(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->mobility_twist = _arg;
    return *this;
  }
  Type & set__actuator_speed(
    const double & _arg)
  {
    this->actuator_speed = _arg;
    return *this;
  }
  Type & set__drum_speed(
    const double & _arg)
  {
    this->drum_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::msg::RoverCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::msg::RoverCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::msg::RoverCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::msg::RoverCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::RoverCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::RoverCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::RoverCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::RoverCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::msg::RoverCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::msg::RoverCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__msg__RoverCommand
    std::shared_ptr<lx_msgs::msg::RoverCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__msg__RoverCommand
    std::shared_ptr<lx_msgs::msg::RoverCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RoverCommand_ & other) const
  {
    if (this->mobility_twist != other.mobility_twist) {
      return false;
    }
    if (this->actuator_speed != other.actuator_speed) {
      return false;
    }
    if (this->drum_speed != other.drum_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const RoverCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RoverCommand_

// alias to use template instance with default allocator
using RoverCommand =
  lx_msgs::msg::RoverCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__ROVER_COMMAND__STRUCT_HPP_
