// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:msg/BermConfig.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_CONFIG__STRUCT_HPP_
#define LX_MSGS__MSG__DETAIL__BERM_CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'berm_configuration'
#include "geometry_msgs/msg/detail/point_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__msg__BermConfig __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__msg__BermConfig __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BermConfig_
{
  using Type = BermConfig_<ContainerAllocator>;

  explicit BermConfig_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit BermConfig_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _berm_configuration_type =
    std::vector<geometry_msgs::msg::PointStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PointStamped_<ContainerAllocator>>>;
  _berm_configuration_type berm_configuration;

  // setters for named parameter idiom
  Type & set__berm_configuration(
    const std::vector<geometry_msgs::msg::PointStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PointStamped_<ContainerAllocator>>> & _arg)
  {
    this->berm_configuration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::msg::BermConfig_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::msg::BermConfig_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::msg::BermConfig_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::msg::BermConfig_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::BermConfig_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::BermConfig_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::BermConfig_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::BermConfig_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::msg::BermConfig_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::msg::BermConfig_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__msg__BermConfig
    std::shared_ptr<lx_msgs::msg::BermConfig_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__msg__BermConfig
    std::shared_ptr<lx_msgs::msg::BermConfig_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BermConfig_ & other) const
  {
    if (this->berm_configuration != other.berm_configuration) {
      return false;
    }
    return true;
  }
  bool operator!=(const BermConfig_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BermConfig_

// alias to use template instance with default allocator
using BermConfig =
  lx_msgs::msg::BermConfig_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__BERM_CONFIG__STRUCT_HPP_
