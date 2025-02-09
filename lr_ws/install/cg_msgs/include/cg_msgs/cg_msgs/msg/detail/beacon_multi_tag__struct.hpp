// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:msg/BeaconMultiTag.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__STRUCT_HPP_
#define CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__STRUCT_HPP_

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
// Member 'TagsList'
#include "cg_msgs/msg/detail/beacon_tag__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cg_msgs__msg__BeaconMultiTag __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__msg__BeaconMultiTag __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BeaconMultiTag_
{
  using Type = BeaconMultiTag_<ContainerAllocator>;

  explicit BeaconMultiTag_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->TagsList.fill(cg_msgs::msg::BeaconTag_<ContainerAllocator>{_init});
    }
  }

  explicit BeaconMultiTag_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    TagsList(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->TagsList.fill(cg_msgs::msg::BeaconTag_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _TagsList_type =
    std::array<cg_msgs::msg::BeaconTag_<ContainerAllocator>, 2>;
  _TagsList_type TagsList;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__TagsList(
    const std::array<cg_msgs::msg::BeaconTag_<ContainerAllocator>, 2> & _arg)
  {
    this->TagsList = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::msg::BeaconMultiTag_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::msg::BeaconMultiTag_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::msg::BeaconMultiTag_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::msg::BeaconMultiTag_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::BeaconMultiTag_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::BeaconMultiTag_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::BeaconMultiTag_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::BeaconMultiTag_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::msg::BeaconMultiTag_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::msg::BeaconMultiTag_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__msg__BeaconMultiTag
    std::shared_ptr<cg_msgs::msg::BeaconMultiTag_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__msg__BeaconMultiTag
    std::shared_ptr<cg_msgs::msg::BeaconMultiTag_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BeaconMultiTag_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->TagsList != other.TagsList) {
      return false;
    }
    return true;
  }
  bool operator!=(const BeaconMultiTag_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BeaconMultiTag_

// alias to use template instance with default allocator
using BeaconMultiTag =
  cg_msgs::msg::BeaconMultiTag_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__STRUCT_HPP_
