// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:msg/SiteMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__SITE_MAP__STRUCT_HPP_
#define CG_MSGS__MSG__DETAIL__SITE_MAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cg_msgs__msg__SiteMap __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__msg__SiteMap __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SiteMap_
{
  using Type = SiteMap_<ContainerAllocator>;

  explicit SiteMap_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit SiteMap_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _height_map_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _height_map_type height_map;

  // setters for named parameter idiom
  Type & set__height_map(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->height_map = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::msg::SiteMap_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::msg::SiteMap_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::msg::SiteMap_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::msg::SiteMap_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::SiteMap_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::SiteMap_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::SiteMap_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::SiteMap_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::msg::SiteMap_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::msg::SiteMap_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__msg__SiteMap
    std::shared_ptr<cg_msgs::msg::SiteMap_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__msg__SiteMap
    std::shared_ptr<cg_msgs::msg::SiteMap_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SiteMap_ & other) const
  {
    if (this->height_map != other.height_map) {
      return false;
    }
    return true;
  }
  bool operator!=(const SiteMap_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SiteMap_

// alias to use template instance with default allocator
using SiteMap =
  cg_msgs::msg::SiteMap_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__SITE_MAP__STRUCT_HPP_
