// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:srv/UserInputRecord.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__USER_INPUT_RECORD__BUILDER_HPP_
#define LX_MSGS__SRV__DETAIL__USER_INPUT_RECORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/srv/detail/user_input_record__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_UserInputRecord_Request_empty
{
public:
  Init_UserInputRecord_Request_empty()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::UserInputRecord_Request empty(::lx_msgs::srv::UserInputRecord_Request::_empty_type arg)
  {
    msg_.empty = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::UserInputRecord_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::UserInputRecord_Request>()
{
  return lx_msgs::srv::builder::Init_UserInputRecord_Request_empty();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_UserInputRecord_Response_success
{
public:
  Init_UserInputRecord_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::UserInputRecord_Response success(::lx_msgs::srv::UserInputRecord_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::UserInputRecord_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::UserInputRecord_Response>()
{
  return lx_msgs::srv::builder::Init_UserInputRecord_Response_success();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__USER_INPUT_RECORD__BUILDER_HPP_
