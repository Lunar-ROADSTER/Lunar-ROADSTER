#include <planning/fsm/goals_remaining.hpp>
#include <iostream> // DEBUG

namespace cg {
namespace planning {

void GoalsRemaining::runState(std::vector<cg_msgs::msg::Pose2D> &current_goal_poses, cg_msgs::msg::Pose2D &current_goal_pose, std::vector<std::string> &current_goalPose_types, std::string &current_goalPose_type) {
  std::cout << "GOALS_REMAINING" << std::endl;

  // Update shared current state and the precursing signal
  if (current_goal_poses.size() > 0) {
    // Update the current goal pose
    current_goal_pose = current_goal_poses[0];
    current_goalPose_type = current_goalPose_types[0];
    // Remove that goal pose from the list of poses
    current_goal_poses.erase(current_goal_poses.begin());
    current_goalPose_types.erase(current_goalPose_types.begin());

    // Change state to follow trajectory
    pre_signal_ = Signal::FOLLOW_TRAJECTORY;
    curr_state_l0_ = StateL0::FOLLOWING_TRAJECTORY;
    return;
  }

  // No more goals are left
  pre_signal_ = Signal::TRANSPORT_PLANNED;
  curr_state_l0_ = StateL0::GET_TRANSPORT_GOALS;
}

} // planning namespace
} // cg namespace
