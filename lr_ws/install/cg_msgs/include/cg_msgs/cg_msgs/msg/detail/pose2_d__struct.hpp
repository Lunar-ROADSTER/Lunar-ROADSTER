// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:msg/Pose2D.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__POSE2_D__STRUCT_HPP_
#define CG_MSGS__MSG__DETAIL__POSE2_D__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pt'
#include "cg_msgs/msg/detail/point2_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cg_msgs__msg__Pose2D __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__msg__Pose2D __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Pose2D_
{
  using Type = Pose2D_<ContainerAllocator>;

  explicit Pose2D_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pt(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->yaw = 0.0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->yaw = 0.0;
    }
  }

  explicit Pose2D_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pt(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->yaw = 0.0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _pt_type =
    cg_msgs::msg::Point2D_<ContainerAllocator>;
  _pt_type pt;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__pt(
    const cg_msgs::msg::Point2D_<ContainerAllocator> & _arg)
  {
    this->pt = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::msg::Pose2D_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::msg::Pose2D_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::msg::Pose2D_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::msg::Pose2D_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::Pose2D_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::Pose2D_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::Pose2D_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::Pose2D_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::msg::Pose2D_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::msg::Pose2D_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__msg__Pose2D
    std::shared_ptr<cg_msgs::msg::Pose2D_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__msg__Pose2D
    std::shared_ptr<cg_msgs::msg::Pose2D_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Pose2D_ & other) const
  {
    if (this->pt != other.pt) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const Pose2D_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Pose2D_

// alias to use template instance with default allocator
using Pose2D =
  cg_msgs::msg::Pose2D_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__POSE2_D__STRUCT_HPP_
