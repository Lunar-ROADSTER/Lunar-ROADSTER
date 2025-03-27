// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/BeaconMultiTag.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/beacon_multi_tag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_BeaconMultiTag_TagsList
{
public:
  explicit Init_BeaconMultiTag_TagsList(::cg_msgs::msg::BeaconMultiTag & msg)
  : msg_(msg)
  {}
  ::cg_msgs::msg::BeaconMultiTag TagsList(::cg_msgs::msg::BeaconMultiTag::_TagsList_type arg)
  {
    msg_.TagsList = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::BeaconMultiTag msg_;
};

class Init_BeaconMultiTag_header
{
public:
  Init_BeaconMultiTag_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BeaconMultiTag_TagsList header(::cg_msgs::msg::BeaconMultiTag::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BeaconMultiTag_TagsList(msg_);
  }

private:
  ::cg_msgs::msg::BeaconMultiTag msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::BeaconMultiTag>()
{
  return cg_msgs::msg::builder::Init_BeaconMultiTag_header();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__BUILDER_HPP_
