// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:msg/NodeDiagnostics.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__NODE_DIAGNOSTICS__STRUCT_HPP_
#define LX_MSGS__MSG__DETAIL__NODE_DIAGNOSTICS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__msg__NodeDiagnostics __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__msg__NodeDiagnostics __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NodeDiagnostics_
{
  using Type = NodeDiagnostics_<ContainerAllocator>;

  explicit NodeDiagnostics_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_name = "";
    }
  }

  explicit NodeDiagnostics_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init),
    node_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_name = "";
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _node_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _node_name_type node_name;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__node_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->node_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::msg::NodeDiagnostics_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::msg::NodeDiagnostics_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::msg::NodeDiagnostics_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::msg::NodeDiagnostics_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::NodeDiagnostics_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::NodeDiagnostics_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::NodeDiagnostics_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::NodeDiagnostics_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::msg::NodeDiagnostics_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::msg::NodeDiagnostics_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__msg__NodeDiagnostics
    std::shared_ptr<lx_msgs::msg::NodeDiagnostics_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__msg__NodeDiagnostics
    std::shared_ptr<lx_msgs::msg::NodeDiagnostics_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NodeDiagnostics_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->node_name != other.node_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const NodeDiagnostics_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NodeDiagnostics_

// alias to use template instance with default allocator
using NodeDiagnostics =
  lx_msgs::msg::NodeDiagnostics_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__NODE_DIAGNOSTICS__STRUCT_HPP_
