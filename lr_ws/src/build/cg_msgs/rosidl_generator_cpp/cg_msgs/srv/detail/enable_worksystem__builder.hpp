// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:srv/EnableWorksystem.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__BUILDER_HPP_
#define CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/srv/detail/enable_worksystem__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace srv
{

namespace builder
{

class Init_EnableWorksystem_Request_enable_worksystem
{
public:
  Init_EnableWorksystem_Request_enable_worksystem()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cg_msgs::srv::EnableWorksystem_Request enable_worksystem(::cg_msgs::srv::EnableWorksystem_Request::_enable_worksystem_type arg)
  {
    msg_.enable_worksystem = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::srv::EnableWorksystem_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::srv::EnableWorksystem_Request>()
{
  return cg_msgs::srv::builder::Init_EnableWorksystem_Request_enable_worksystem();
}

}  // namespace cg_msgs


namespace cg_msgs
{

namespace srv
{

namespace builder
{

class Init_EnableWorksystem_Response_worksystem_enabled
{
public:
  Init_EnableWorksystem_Response_worksystem_enabled()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cg_msgs::srv::EnableWorksystem_Response worksystem_enabled(::cg_msgs::srv::EnableWorksystem_Response::_worksystem_enabled_type arg)
  {
    msg_.worksystem_enabled = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::srv::EnableWorksystem_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::srv::EnableWorksystem_Response>()
{
  return cg_msgs::srv::builder::Init_EnableWorksystem_Response_worksystem_enabled();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__BUILDER_HPP_
