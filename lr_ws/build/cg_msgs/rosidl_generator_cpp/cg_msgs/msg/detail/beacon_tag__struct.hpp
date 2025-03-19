// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:msg/BeaconTag.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__BEACON_TAG__STRUCT_HPP_
#define CG_MSGS__MSG__DETAIL__BEACON_TAG__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__cg_msgs__msg__BeaconTag __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__msg__BeaconTag __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BeaconTag_
{
  using Type = BeaconTag_<ContainerAllocator>;

  explicit BeaconTag_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag_id = "";
      this->pose_x = 0.0;
      this->pose_y = 0.0;
      this->pose_z = 0.0;
      this->orientation_x = 0.0;
      this->orientation_y = 0.0;
      this->orientation_z = 0.0;
      this->orientation_w = 0.0;
    }
  }

  explicit BeaconTag_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    tag_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag_id = "";
      this->pose_x = 0.0;
      this->pose_y = 0.0;
      this->pose_z = 0.0;
      this->orientation_x = 0.0;
      this->orientation_y = 0.0;
      this->orientation_z = 0.0;
      this->orientation_w = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _tag_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tag_id_type tag_id;
  using _pose_x_type =
    double;
  _pose_x_type pose_x;
  using _pose_y_type =
    double;
  _pose_y_type pose_y;
  using _pose_z_type =
    double;
  _pose_z_type pose_z;
  using _orientation_x_type =
    double;
  _orientation_x_type orientation_x;
  using _orientation_y_type =
    double;
  _orientation_y_type orientation_y;
  using _orientation_z_type =
    double;
  _orientation_z_type orientation_z;
  using _orientation_w_type =
    double;
  _orientation_w_type orientation_w;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__tag_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tag_id = _arg;
    return *this;
  }
  Type & set__pose_x(
    const double & _arg)
  {
    this->pose_x = _arg;
    return *this;
  }
  Type & set__pose_y(
    const double & _arg)
  {
    this->pose_y = _arg;
    return *this;
  }
  Type & set__pose_z(
    const double & _arg)
  {
    this->pose_z = _arg;
    return *this;
  }
  Type & set__orientation_x(
    const double & _arg)
  {
    this->orientation_x = _arg;
    return *this;
  }
  Type & set__orientation_y(
    const double & _arg)
  {
    this->orientation_y = _arg;
    return *this;
  }
  Type & set__orientation_z(
    const double & _arg)
  {
    this->orientation_z = _arg;
    return *this;
  }
  Type & set__orientation_w(
    const double & _arg)
  {
    this->orientation_w = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::msg::BeaconTag_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::msg::BeaconTag_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::msg::BeaconTag_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::msg::BeaconTag_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::BeaconTag_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::BeaconTag_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::BeaconTag_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::BeaconTag_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::msg::BeaconTag_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::msg::BeaconTag_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__msg__BeaconTag
    std::shared_ptr<cg_msgs::msg::BeaconTag_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__msg__BeaconTag
    std::shared_ptr<cg_msgs::msg::BeaconTag_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BeaconTag_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->tag_id != other.tag_id) {
      return false;
    }
    if (this->pose_x != other.pose_x) {
      return false;
    }
    if (this->pose_y != other.pose_y) {
      return false;
    }
    if (this->pose_z != other.pose_z) {
      return false;
    }
    if (this->orientation_x != other.orientation_x) {
      return false;
    }
    if (this->orientation_y != other.orientation_y) {
      return false;
    }
    if (this->orientation_z != other.orientation_z) {
      return false;
    }
    if (this->orientation_w != other.orientation_w) {
      return false;
    }
    return true;
  }
  bool operator!=(const BeaconTag_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BeaconTag_

// alias to use template instance with default allocator
using BeaconTag =
  cg_msgs::msg::BeaconTag_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__BEACON_TAG__STRUCT_HPP_
