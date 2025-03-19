// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/BeaconTag.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__BEACON_TAG__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__BEACON_TAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/beacon_tag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_BeaconTag_orientation_w
{
public:
  explicit Init_BeaconTag_orientation_w(::cg_msgs::msg::BeaconTag & msg)
  : msg_(msg)
  {}
  ::cg_msgs::msg::BeaconTag orientation_w(::cg_msgs::msg::BeaconTag::_orientation_w_type arg)
  {
    msg_.orientation_w = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::BeaconTag msg_;
};

class Init_BeaconTag_orientation_z
{
public:
  explicit Init_BeaconTag_orientation_z(::cg_msgs::msg::BeaconTag & msg)
  : msg_(msg)
  {}
  Init_BeaconTag_orientation_w orientation_z(::cg_msgs::msg::BeaconTag::_orientation_z_type arg)
  {
    msg_.orientation_z = std::move(arg);
    return Init_BeaconTag_orientation_w(msg_);
  }

private:
  ::cg_msgs::msg::BeaconTag msg_;
};

class Init_BeaconTag_orientation_y
{
public:
  explicit Init_BeaconTag_orientation_y(::cg_msgs::msg::BeaconTag & msg)
  : msg_(msg)
  {}
  Init_BeaconTag_orientation_z orientation_y(::cg_msgs::msg::BeaconTag::_orientation_y_type arg)
  {
    msg_.orientation_y = std::move(arg);
    return Init_BeaconTag_orientation_z(msg_);
  }

private:
  ::cg_msgs::msg::BeaconTag msg_;
};

class Init_BeaconTag_orientation_x
{
public:
  explicit Init_BeaconTag_orientation_x(::cg_msgs::msg::BeaconTag & msg)
  : msg_(msg)
  {}
  Init_BeaconTag_orientation_y orientation_x(::cg_msgs::msg::BeaconTag::_orientation_x_type arg)
  {
    msg_.orientation_x = std::move(arg);
    return Init_BeaconTag_orientation_y(msg_);
  }

private:
  ::cg_msgs::msg::BeaconTag msg_;
};

class Init_BeaconTag_pose_z
{
public:
  explicit Init_BeaconTag_pose_z(::cg_msgs::msg::BeaconTag & msg)
  : msg_(msg)
  {}
  Init_BeaconTag_orientation_x pose_z(::cg_msgs::msg::BeaconTag::_pose_z_type arg)
  {
    msg_.pose_z = std::move(arg);
    return Init_BeaconTag_orientation_x(msg_);
  }

private:
  ::cg_msgs::msg::BeaconTag msg_;
};

class Init_BeaconTag_pose_y
{
public:
  explicit Init_BeaconTag_pose_y(::cg_msgs::msg::BeaconTag & msg)
  : msg_(msg)
  {}
  Init_BeaconTag_pose_z pose_y(::cg_msgs::msg::BeaconTag::_pose_y_type arg)
  {
    msg_.pose_y = std::move(arg);
    return Init_BeaconTag_pose_z(msg_);
  }

private:
  ::cg_msgs::msg::BeaconTag msg_;
};

class Init_BeaconTag_pose_x
{
public:
  explicit Init_BeaconTag_pose_x(::cg_msgs::msg::BeaconTag & msg)
  : msg_(msg)
  {}
  Init_BeaconTag_pose_y pose_x(::cg_msgs::msg::BeaconTag::_pose_x_type arg)
  {
    msg_.pose_x = std::move(arg);
    return Init_BeaconTag_pose_y(msg_);
  }

private:
  ::cg_msgs::msg::BeaconTag msg_;
};

class Init_BeaconTag_tag_id
{
public:
  explicit Init_BeaconTag_tag_id(::cg_msgs::msg::BeaconTag & msg)
  : msg_(msg)
  {}
  Init_BeaconTag_pose_x tag_id(::cg_msgs::msg::BeaconTag::_tag_id_type arg)
  {
    msg_.tag_id = std::move(arg);
    return Init_BeaconTag_pose_x(msg_);
  }

private:
  ::cg_msgs::msg::BeaconTag msg_;
};

class Init_BeaconTag_header
{
public:
  Init_BeaconTag_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BeaconTag_tag_id header(::cg_msgs::msg::BeaconTag::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BeaconTag_tag_id(msg_);
  }

private:
  ::cg_msgs::msg::BeaconTag msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::BeaconTag>()
{
  return cg_msgs::msg::builder::Init_BeaconTag_header();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__BEACON_TAG__BUILDER_HPP_
