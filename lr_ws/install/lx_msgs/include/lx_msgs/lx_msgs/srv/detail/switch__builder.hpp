// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:srv/Switch.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__SWITCH__BUILDER_HPP_
#define LX_MSGS__SRV__DETAIL__SWITCH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/srv/detail/switch__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_Switch_Request_first_seg_dump
{
public:
  explicit Init_Switch_Request_first_seg_dump(::lx_msgs::srv::Switch_Request & msg)
  : msg_(msg)
  {}
  ::lx_msgs::srv::Switch_Request first_seg_dump(::lx_msgs::srv::Switch_Request::_first_seg_dump_type arg)
  {
    msg_.first_seg_dump = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::Switch_Request msg_;
};

class Init_Switch_Request_prev_berm_segment
{
public:
  explicit Init_Switch_Request_prev_berm_segment(::lx_msgs::srv::Switch_Request & msg)
  : msg_(msg)
  {}
  Init_Switch_Request_first_seg_dump prev_berm_segment(::lx_msgs::srv::Switch_Request::_prev_berm_segment_type arg)
  {
    msg_.prev_berm_segment = std::move(arg);
    return Init_Switch_Request_first_seg_dump(msg_);
  }

private:
  ::lx_msgs::srv::Switch_Request msg_;
};

class Init_Switch_Request_current_berm_segment
{
public:
  explicit Init_Switch_Request_current_berm_segment(::lx_msgs::srv::Switch_Request & msg)
  : msg_(msg)
  {}
  Init_Switch_Request_prev_berm_segment current_berm_segment(::lx_msgs::srv::Switch_Request::_current_berm_segment_type arg)
  {
    msg_.current_berm_segment = std::move(arg);
    return Init_Switch_Request_prev_berm_segment(msg_);
  }

private:
  ::lx_msgs::srv::Switch_Request msg_;
};

class Init_Switch_Request_switch_state
{
public:
  Init_Switch_Request_switch_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Switch_Request_current_berm_segment switch_state(::lx_msgs::srv::Switch_Request::_switch_state_type arg)
  {
    msg_.switch_state = std::move(arg);
    return Init_Switch_Request_current_berm_segment(msg_);
  }

private:
  ::lx_msgs::srv::Switch_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::Switch_Request>()
{
  return lx_msgs::srv::builder::Init_Switch_Request_switch_state();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_Switch_Response_success
{
public:
  Init_Switch_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::Switch_Response success(::lx_msgs::srv::Switch_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::Switch_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::Switch_Response>()
{
  return lx_msgs::srv::builder::Init_Switch_Response_success();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__SWITCH__BUILDER_HPP_
