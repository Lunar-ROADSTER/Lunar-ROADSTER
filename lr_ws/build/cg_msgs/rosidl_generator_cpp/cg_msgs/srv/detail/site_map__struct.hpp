// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:srv/SiteMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__SITE_MAP__STRUCT_HPP_
#define CG_MSGS__SRV__DETAIL__SITE_MAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cg_msgs__srv__SiteMap_Request __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__srv__SiteMap_Request __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SiteMap_Request_
{
  using Type = SiteMap_Request_<ContainerAllocator>;

  explicit SiteMap_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit SiteMap_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::srv::SiteMap_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::srv::SiteMap_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::srv::SiteMap_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::srv::SiteMap_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::SiteMap_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::SiteMap_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::SiteMap_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::SiteMap_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::srv::SiteMap_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::srv::SiteMap_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__srv__SiteMap_Request
    std::shared_ptr<cg_msgs::srv::SiteMap_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__srv__SiteMap_Request
    std::shared_ptr<cg_msgs::srv::SiteMap_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SiteMap_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const SiteMap_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SiteMap_Request_

// alias to use template instance with default allocator
using SiteMap_Request =
  cg_msgs::srv::SiteMap_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cg_msgs


// Include directives for member types
// Member 'site_map'
#include "cg_msgs/msg/detail/site_map__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cg_msgs__srv__SiteMap_Response __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__srv__SiteMap_Response __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SiteMap_Response_
{
  using Type = SiteMap_Response_<ContainerAllocator>;

  explicit SiteMap_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : site_map(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->map_fully_explored = false;
      this->success = false;
    }
  }

  explicit SiteMap_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : site_map(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->map_fully_explored = false;
      this->success = false;
    }
  }

  // field types and members
  using _site_map_type =
    cg_msgs::msg::SiteMap_<ContainerAllocator>;
  _site_map_type site_map;
  using _map_fully_explored_type =
    bool;
  _map_fully_explored_type map_fully_explored;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__site_map(
    const cg_msgs::msg::SiteMap_<ContainerAllocator> & _arg)
  {
    this->site_map = _arg;
    return *this;
  }
  Type & set__map_fully_explored(
    const bool & _arg)
  {
    this->map_fully_explored = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::srv::SiteMap_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::srv::SiteMap_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::srv::SiteMap_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::srv::SiteMap_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::SiteMap_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::SiteMap_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::SiteMap_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::SiteMap_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::srv::SiteMap_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::srv::SiteMap_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__srv__SiteMap_Response
    std::shared_ptr<cg_msgs::srv::SiteMap_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__srv__SiteMap_Response
    std::shared_ptr<cg_msgs::srv::SiteMap_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SiteMap_Response_ & other) const
  {
    if (this->site_map != other.site_map) {
      return false;
    }
    if (this->map_fully_explored != other.map_fully_explored) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SiteMap_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SiteMap_Response_

// alias to use template instance with default allocator
using SiteMap_Response =
  cg_msgs::srv::SiteMap_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cg_msgs

namespace cg_msgs
{

namespace srv
{

struct SiteMap
{
  using Request = cg_msgs::srv::SiteMap_Request;
  using Response = cg_msgs::srv::SiteMap_Response;
};

}  // namespace srv

}  // namespace cg_msgs

#endif  // CG_MSGS__SRV__DETAIL__SITE_MAP__STRUCT_HPP_
