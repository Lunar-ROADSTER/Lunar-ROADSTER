// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:msg/BermProgress.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_PROGRESS__BUILDER_HPP_
#define LX_MSGS__MSG__DETAIL__BERM_PROGRESS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/msg/detail/berm_progress__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace msg
{

namespace builder
{

class Init_BermProgress_volumes
{
public:
  explicit Init_BermProgress_volumes(::lx_msgs::msg::BermProgress & msg)
  : msg_(msg)
  {}
  ::lx_msgs::msg::BermProgress volumes(::lx_msgs::msg::BermProgress::_volumes_type arg)
  {
    msg_.volumes = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::msg::BermProgress msg_;
};

class Init_BermProgress_timestamps
{
public:
  explicit Init_BermProgress_timestamps(::lx_msgs::msg::BermProgress & msg)
  : msg_(msg)
  {}
  Init_BermProgress_volumes timestamps(::lx_msgs::msg::BermProgress::_timestamps_type arg)
  {
    msg_.timestamps = std::move(arg);
    return Init_BermProgress_volumes(msg_);
  }

private:
  ::lx_msgs::msg::BermProgress msg_;
};

class Init_BermProgress_peakline_error
{
public:
  explicit Init_BermProgress_peakline_error(::lx_msgs::msg::BermProgress & msg)
  : msg_(msg)
  {}
  Init_BermProgress_timestamps peakline_error(::lx_msgs::msg::BermProgress::_peakline_error_type arg)
  {
    msg_.peakline_error = std::move(arg);
    return Init_BermProgress_timestamps(msg_);
  }

private:
  ::lx_msgs::msg::BermProgress msg_;
};

class Init_BermProgress_length
{
public:
  explicit Init_BermProgress_length(::lx_msgs::msg::BermProgress & msg)
  : msg_(msg)
  {}
  Init_BermProgress_peakline_error length(::lx_msgs::msg::BermProgress::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_BermProgress_peakline_error(msg_);
  }

private:
  ::lx_msgs::msg::BermProgress msg_;
};

class Init_BermProgress_average_height
{
public:
  explicit Init_BermProgress_average_height(::lx_msgs::msg::BermProgress & msg)
  : msg_(msg)
  {}
  Init_BermProgress_length average_height(::lx_msgs::msg::BermProgress::_average_height_type arg)
  {
    msg_.average_height = std::move(arg);
    return Init_BermProgress_length(msg_);
  }

private:
  ::lx_msgs::msg::BermProgress msg_;
};

class Init_BermProgress_heights
{
public:
  explicit Init_BermProgress_heights(::lx_msgs::msg::BermProgress & msg)
  : msg_(msg)
  {}
  Init_BermProgress_average_height heights(::lx_msgs::msg::BermProgress::_heights_type arg)
  {
    msg_.heights = std::move(arg);
    return Init_BermProgress_average_height(msg_);
  }

private:
  ::lx_msgs::msg::BermProgress msg_;
};

class Init_BermProgress_berm_points
{
public:
  Init_BermProgress_berm_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BermProgress_heights berm_points(::lx_msgs::msg::BermProgress::_berm_points_type arg)
  {
    msg_.berm_points = std::move(arg);
    return Init_BermProgress_heights(msg_);
  }

private:
  ::lx_msgs::msg::BermProgress msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::msg::BermProgress>()
{
  return lx_msgs::msg::builder::Init_BermProgress_berm_points();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__BERM_PROGRESS__BUILDER_HPP_
