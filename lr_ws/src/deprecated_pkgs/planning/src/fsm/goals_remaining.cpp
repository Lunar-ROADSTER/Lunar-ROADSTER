/**
 * @file goals_remaining.cpp
 * @brief Oversees the processing of pending goals within the planning FSM.
 *
 * This file delivers mechanisms to track and handle ongoing goals, facilitating sequential execution and state shifts when goals are exhausted or advanced.
 * It prioritizes efficient goal management, including updates to poses and signals for smooth mission flow.
 *
 * Notable aspects:
 *   - runState(): Orchestrates goal selection, removal, and FSM transitions.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - current_goal_poses [std::vector<lr_msgs::msg::Pose2D>&]: Collection of remaining goal poses to manage.
 * - current_goal_pose [lr_msgs::msg::Pose2D&]: The active goal pose under processing.
 * - current_goalPose_types [std::vector<std::string>&]: Types associated with the remaining goals.
 * - current_goalPose_type [std::string&]: Type of the current goal being handled.
 *
 * Methods:
 * - runState(): Manages goal processing and state changes; outputs: None (void), but updates inputs by reference and modifies FSM states.
 *
 * @credit John Harrington, Team CraterGrader.
 */

#include <planning/fsm/goals_remaining.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

void GoalsRemaining::runState(std::vector<lr_msgs::msg::Pose2D> &current_goal_poses, lr_msgs::msg::Pose2D &current_goal_pose, std::vector<std::string> &current_goalPose_types, std::string &current_goalPose_type) {
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
    pre_signal_ = Signal::YES;
    curr_state_l0_ = StateL0::GET_WORKSYSTEM_TRAJECTORY;

    // pre_signal_ = Signal::FOLLOW_TRAJECTORY;
    // curr_state_l0_ = StateL0::FOLLOWING_TRAJECTORY;
    return;
  }

  // No more goals are left
  pre_signal_ = Signal::TRANSPORT_PLANNED;
  curr_state_l0_ = StateL0::GET_TRANSPORT_GOALS;
}

} // planning namespace
} // lr namespace
