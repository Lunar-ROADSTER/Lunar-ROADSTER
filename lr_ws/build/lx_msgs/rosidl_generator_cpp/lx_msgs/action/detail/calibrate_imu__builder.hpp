// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:action/CalibrateImu.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__ACTION__DETAIL__CALIBRATE_IMU__BUILDER_HPP_
#define LX_MSGS__ACTION__DETAIL__CALIBRATE_IMU__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/action/detail/calibrate_imu__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace action
{

namespace builder
{

class Init_CalibrateImu_Goal_time
{
public:
  explicit Init_CalibrateImu_Goal_time(::lx_msgs::action::CalibrateImu_Goal & msg)
  : msg_(msg)
  {}
  ::lx_msgs::action::CalibrateImu_Goal time(::lx_msgs::action::CalibrateImu_Goal::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_Goal msg_;
};

class Init_CalibrateImu_Goal_dont_move_rover
{
public:
  Init_CalibrateImu_Goal_dont_move_rover()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalibrateImu_Goal_time dont_move_rover(::lx_msgs::action::CalibrateImu_Goal::_dont_move_rover_type arg)
  {
    msg_.dont_move_rover = std::move(arg);
    return Init_CalibrateImu_Goal_time(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::action::CalibrateImu_Goal>()
{
  return lx_msgs::action::builder::Init_CalibrateImu_Goal_dont_move_rover();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace action
{

namespace builder
{

class Init_CalibrateImu_Result_success
{
public:
  Init_CalibrateImu_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::action::CalibrateImu_Result success(::lx_msgs::action::CalibrateImu_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::action::CalibrateImu_Result>()
{
  return lx_msgs::action::builder::Init_CalibrateImu_Result_success();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace action
{

namespace builder
{

class Init_CalibrateImu_Feedback_status
{
public:
  Init_CalibrateImu_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::action::CalibrateImu_Feedback status(::lx_msgs::action::CalibrateImu_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::action::CalibrateImu_Feedback>()
{
  return lx_msgs::action::builder::Init_CalibrateImu_Feedback_status();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace action
{

namespace builder
{

class Init_CalibrateImu_SendGoal_Request_goal
{
public:
  explicit Init_CalibrateImu_SendGoal_Request_goal(::lx_msgs::action::CalibrateImu_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::lx_msgs::action::CalibrateImu_SendGoal_Request goal(::lx_msgs::action::CalibrateImu_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_SendGoal_Request msg_;
};

class Init_CalibrateImu_SendGoal_Request_goal_id
{
public:
  Init_CalibrateImu_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalibrateImu_SendGoal_Request_goal goal_id(::lx_msgs::action::CalibrateImu_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_CalibrateImu_SendGoal_Request_goal(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::action::CalibrateImu_SendGoal_Request>()
{
  return lx_msgs::action::builder::Init_CalibrateImu_SendGoal_Request_goal_id();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace action
{

namespace builder
{

class Init_CalibrateImu_SendGoal_Response_stamp
{
public:
  explicit Init_CalibrateImu_SendGoal_Response_stamp(::lx_msgs::action::CalibrateImu_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::lx_msgs::action::CalibrateImu_SendGoal_Response stamp(::lx_msgs::action::CalibrateImu_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_SendGoal_Response msg_;
};

class Init_CalibrateImu_SendGoal_Response_accepted
{
public:
  Init_CalibrateImu_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalibrateImu_SendGoal_Response_stamp accepted(::lx_msgs::action::CalibrateImu_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_CalibrateImu_SendGoal_Response_stamp(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::action::CalibrateImu_SendGoal_Response>()
{
  return lx_msgs::action::builder::Init_CalibrateImu_SendGoal_Response_accepted();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace action
{

namespace builder
{

class Init_CalibrateImu_GetResult_Request_goal_id
{
public:
  Init_CalibrateImu_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::action::CalibrateImu_GetResult_Request goal_id(::lx_msgs::action::CalibrateImu_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::action::CalibrateImu_GetResult_Request>()
{
  return lx_msgs::action::builder::Init_CalibrateImu_GetResult_Request_goal_id();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace action
{

namespace builder
{

class Init_CalibrateImu_GetResult_Response_result
{
public:
  explicit Init_CalibrateImu_GetResult_Response_result(::lx_msgs::action::CalibrateImu_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::lx_msgs::action::CalibrateImu_GetResult_Response result(::lx_msgs::action::CalibrateImu_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_GetResult_Response msg_;
};

class Init_CalibrateImu_GetResult_Response_status
{
public:
  Init_CalibrateImu_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalibrateImu_GetResult_Response_result status(::lx_msgs::action::CalibrateImu_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_CalibrateImu_GetResult_Response_result(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::action::CalibrateImu_GetResult_Response>()
{
  return lx_msgs::action::builder::Init_CalibrateImu_GetResult_Response_status();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace action
{

namespace builder
{

class Init_CalibrateImu_FeedbackMessage_feedback
{
public:
  explicit Init_CalibrateImu_FeedbackMessage_feedback(::lx_msgs::action::CalibrateImu_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::lx_msgs::action::CalibrateImu_FeedbackMessage feedback(::lx_msgs::action::CalibrateImu_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_FeedbackMessage msg_;
};

class Init_CalibrateImu_FeedbackMessage_goal_id
{
public:
  Init_CalibrateImu_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CalibrateImu_FeedbackMessage_feedback goal_id(::lx_msgs::action::CalibrateImu_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_CalibrateImu_FeedbackMessage_feedback(msg_);
  }

private:
  ::lx_msgs::action::CalibrateImu_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::action::CalibrateImu_FeedbackMessage>()
{
  return lx_msgs::action::builder::Init_CalibrateImu_FeedbackMessage_goal_id();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__ACTION__DETAIL__CALIBRATE_IMU__BUILDER_HPP_
