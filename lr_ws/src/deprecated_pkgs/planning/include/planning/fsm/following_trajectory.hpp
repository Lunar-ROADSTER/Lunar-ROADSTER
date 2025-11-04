#ifndef PLANNING__FOLLOWING_TRAJECTORY_HPP
#define PLANNING__FOLLOWING_TRAJECTORY_HPP

#include <planning/fsm/fsm.hpp>
#include <lr_msgs/msg/pose2_d.hpp>

namespace lr {
namespace planning {

// Inherit from FSM to have access to current state/signal
class FollowingTrajectory : public FSM {

public:
  bool runState(lr_msgs::msg::Pose2D &current_goal_pose, const bool goal_reached, std::string &current_goalPose_type);

private:

}; // class State

} // namespace planning
} // namespace lr

#endif // PLANNING__FOLLOWING_TRAJECTORY_HPP
