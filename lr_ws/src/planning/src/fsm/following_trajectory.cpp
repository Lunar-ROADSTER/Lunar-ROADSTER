/**
 * @file following_trajectory.cpp
 * @brief Following Trajectory state implementation for finite state machine in planning module.
 *
 * This module implements the Following Trajectory state, which manages trajectory execution by checking if the goal is reached and updating the state accordingly.
 * It supports running the state to monitor the current goal pose and transition to the next state when the goal is achieved.
 *
 * The implementation uses a simple FSM mechanism:
 *   - runState(): Checks if the goal is reached and updates the preceding signal and current state.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - current_goal_pose [lr_msgs/msg/Pose2D]: A Pose2D message representing the current goal position and orientation.
 * - goal_reached [bool]: A boolean indicating whether the goal has been reached.
 * - current_goalPose_type [std::string]: A string describing the type of the current goal pose.
 *
 * Methods:
 * - runState(): Executes the trajectory following logic and handles state transitions.
 *
 * @credit John Harrington, Team CraterGrader.
 */
#include <planning/fsm/following_trajectory.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

bool FollowingTrajectory::runState(lr_msgs::msg::Pose2D &current_goal_pose, const bool goal_reached, std::string &current_goalPose_type) {
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
} // lr namespace