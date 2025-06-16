#include <planning/fsm/following_trajectory.hpp>
#include <iostream> // DEBUG

namespace cg {
namespace planning {

bool FollowingTrajectory::runState(cg_msgs::msg::Pose2D &current_goal_pose, const bool goal_reached, std::string &current_goalPose_type) {
  std::cout << "FOLLOWING_TRAJECTORY" << std::endl;

  std::cout << "Current goal pose: " << current_goal_pose.pt.x << ", " << current_goal_pose.pt.y  << ", " << current_goal_pose.yaw << " | Type: " << current_goalPose_type << std::endl;

  // Move to next state if goal is reached
  if (goal_reached) {
    pre_signal_ = Signal::GOAL_REACHED;
    curr_state_l0_ = StateL0::GOALS_REMAINING;
    return true;
  }

  // DEBUG
  // pre_signal_ = Signal::GOAL_REACHED;
  // curr_state_l0_ = StateL0::GOALS_REMAINING;

  return false;
}

} // planning namespace
} // cg namespace