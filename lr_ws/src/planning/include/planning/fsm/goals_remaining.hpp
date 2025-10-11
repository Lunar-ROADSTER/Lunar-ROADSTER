#ifndef PLANNING__GOALS_REMAINING_HPP
#define PLANNING__GOALS_REMAINING_HPP

#include <planning/fsm/fsm.hpp>
#include <vector>
#include <lr_msgs/msg/pose2_d.hpp>

namespace lr {
namespace planning {

// Inherit from FSM to have access to current state/signal
class GoalsRemaining : public FSM {

public:
  void runState(std::vector<lr_msgs::msg::Pose2D> &current_goal_poses, lr_msgs::msg::Pose2D &current_goal_pose, std::vector<std::string> &current_goalPose_types, std::string &current_goalPose_type); // Main function to run current state; optionally modifies signal and state for transition

}; // class State

} // namespace planning
} // namespace lr

#endif // PLANNING__GOALS_REMAINING_HPP
