// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:msg/BermProgress.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_PROGRESS__STRUCT_HPP_
#define LX_MSGS__MSG__DETAIL__BERM_PROGRESS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'berm_points'
#include "geometry_msgs/msg/detail/point_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__msg__BermProgress __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__msg__BermProgress __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BermProgress_
{
  using Type = BermProgress_<ContainerAllocator>;

  explicit BermProgress_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->average_height = 0.0f;
      this->length = 0.0f;
      this->peakline_error = 0.0f;
    }
  }

  explicit BermProgress_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->average_height = 0.0f;
      this->length = 0.0f;
      this->peakline_error = 0.0f;
    }
  }

  // field types and members
  using _berm_points_type =
    std::vector<geometry_msgs::msg::PointStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PointStamped_<ContainerAllocator>>>;
  _berm_points_type berm_points;
  using _heights_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _heights_type heights;
  using _average_height_type =
    float;
  _average_height_type average_height;
  using _length_type =
    float;
  _length_type length;
  using _peakline_error_type =
    float;
  _peakline_error_type peakline_error;
  using _timestamps_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _timestamps_type timestamps;
  using _volumes_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _volumes_type volumes;

  // setters for named parameter idiom
  Type & set__berm_points(
    const std::vector<geometry_msgs::msg::PointStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PointStamped_<ContainerAllocator>>> & _arg)
  {
    this->berm_points = _arg;
    return *this;
  }
  Type & set__heights(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->heights = _arg;
    return *this;
  }
  Type & set__average_height(
    const float & _arg)
  {
    this->average_height = _arg;
    return *this;
  }
  Type & set__length(
    const float & _arg)
  {
    this->length = _arg;
    return *this;
  }
  Type & set__peakline_error(
    const float & _arg)
  {
    this->peakline_error = _arg;
    return *this;
  }
  Type & set__timestamps(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->timestamps = _arg;
    return *this;
  }
  Type & set__volumes(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->volumes = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::msg::BermProgress_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::msg::BermProgress_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::msg::BermProgress_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::msg::BermProgress_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::BermProgress_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::BermProgress_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::BermProgress_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::BermProgress_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::msg::BermProgress_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::msg::BermProgress_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__msg__BermProgress
    std::shared_ptr<lx_msgs::msg::BermProgress_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__msg__BermProgress
    std::shared_ptr<lx_msgs::msg::BermProgress_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BermProgress_ & other) const
  {
    if (this->berm_points != other.berm_points) {
      return false;
    }
    if (this->heights != other.heights) {
      return false;
    }
    if (this->average_height != other.average_height) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->peakline_error != other.peakline_error) {
      return false;
    }
    if (this->timestamps != other.timestamps) {
      return false;
    }
    if (this->volumes != other.volumes) {
      return false;
    }
    return true;
  }
  bool operator!=(const BermProgress_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BermProgress_

// alias to use template instance with default allocator
using BermProgress =
  lx_msgs::msg::BermProgress_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__BERM_PROGRESS__STRUCT_HPP_
