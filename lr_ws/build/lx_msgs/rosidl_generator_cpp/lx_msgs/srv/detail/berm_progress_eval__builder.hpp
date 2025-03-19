// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:srv/BermProgressEval.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__BUILDER_HPP_
#define LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/srv/detail/berm_progress_eval__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_BermProgressEval_Request_need_metrics
{
public:
  Init_BermProgressEval_Request_need_metrics()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::BermProgressEval_Request need_metrics(::lx_msgs::srv::BermProgressEval_Request::_need_metrics_type arg)
  {
    msg_.need_metrics = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::BermProgressEval_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::BermProgressEval_Request>()
{
  return lx_msgs::srv::builder::Init_BermProgressEval_Request_need_metrics();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_BermProgressEval_Response_progress
{
public:
  Init_BermProgressEval_Response_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::BermProgressEval_Response progress(::lx_msgs::srv::BermProgressEval_Response::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::BermProgressEval_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::BermProgressEval_Response>()
{
  return lx_msgs::srv::builder::Init_BermProgressEval_Response_progress();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__BUILDER_HPP_
