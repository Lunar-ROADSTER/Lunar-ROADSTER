// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:srv/Plan.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__PLAN__BUILDER_HPP_
#define LX_MSGS__SRV__DETAIL__PLAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/srv/detail/plan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_Plan_Request_new_plan
{
public:
  explicit Init_Plan_Request_new_plan(::lx_msgs::srv::Plan_Request & msg)
  : msg_(msg)
  {}
  ::lx_msgs::srv::Plan_Request new_plan(::lx_msgs::srv::Plan_Request::_new_plan_type arg)
  {
    msg_.new_plan = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::Plan_Request msg_;
};

class Init_Plan_Request_section_length
{
public:
  explicit Init_Plan_Request_section_length(::lx_msgs::srv::Plan_Request & msg)
  : msg_(msg)
  {}
  Init_Plan_Request_new_plan section_length(::lx_msgs::srv::Plan_Request::_section_length_type arg)
  {
    msg_.section_length = std::move(arg);
    return Init_Plan_Request_new_plan(msg_);
  }

private:
  ::lx_msgs::srv::Plan_Request msg_;
};

class Init_Plan_Request_berm_height
{
public:
  explicit Init_Plan_Request_berm_height(::lx_msgs::srv::Plan_Request & msg)
  : msg_(msg)
  {}
  Init_Plan_Request_section_length berm_height(::lx_msgs::srv::Plan_Request::_berm_height_type arg)
  {
    msg_.berm_height = std::move(arg);
    return Init_Plan_Request_section_length(msg_);
  }

private:
  ::lx_msgs::srv::Plan_Request msg_;
};

class Init_Plan_Request_berm_input
{
public:
  Init_Plan_Request_berm_input()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Plan_Request_berm_height berm_input(::lx_msgs::srv::Plan_Request::_berm_input_type arg)
  {
    msg_.berm_input = std::move(arg);
    return Init_Plan_Request_berm_height(msg_);
  }

private:
  ::lx_msgs::srv::Plan_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::Plan_Request>()
{
  return lx_msgs::srv::builder::Init_Plan_Request_berm_input();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_Plan_Response_plan
{
public:
  Init_Plan_Response_plan()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::Plan_Response plan(::lx_msgs::srv::Plan_Response::_plan_type arg)
  {
    msg_.plan = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::Plan_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::Plan_Response>()
{
  return lx_msgs::srv::builder::Init_Plan_Response_plan();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__PLAN__BUILDER_HPP_
