/**
 * @file get_transport_goals.cpp
 * @brief Get Transport Goals state implementation for finite state machine in planning module.
 *
 * This module implements the Get Transport Goals state, which retrieves unvisited goal poses and plans the next goals based on the agent's pose and map data, then updates the FSM state accordingly.
 * It supports running the state to fetch and process goals, handling cases where no goals remain by transitioning to the end mission state.
 *
 * The implementation uses a transport planner to manage goal retrieval and state transitions:
 *   - runState(): Retrieves goals, checks for remaining goals, and updates signals and states.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - current_goal_poses [std::vector<lr_msgs::msg::Pose2D>&]: Vector of current goal poses to be updated.
 * - viz_state_l1_goal_poses [std::vector<lr_msgs::msg::Pose2D>&]: Vector for visualizing state L1 goal poses.
 * - transport_planner [lr::planning::TransportPlanner&]: Reference to the transport planner object.
 * - agent_pose [const lr_msgs::msg::Pose2D&]: The current pose of the agent.
 * - map [const lr::mapping::Map<float>&]: The map data used for planning.
 * - goalPose_types [std::vector<std::string>&]: Vector of goal pose types.
 * - current_goalPose_types [std::vector<std::string>&]: Vector of types for the current goal poses.
 *
 * Methods:
 * - runState(): Executes the logic to get transport goals and update states; outputs: None (void), but modifies inputs by reference and updates FSM signals/states as side effects.
 *
 * @credit John Harrington, Team CraterGrader.
 */
 
#include <planning/fsm/get_transport_goals.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

  void GetTransportGoals::runState(std::vector<lr_msgs::msg::Pose2D> &current_goal_poses, std::vector<lr_msgs::msg::Pose2D> &viz_state_l1_goal_poses, lr::planning::TransportPlanner &transport_planner, const lr_msgs::msg::Pose2D &agent_pose, const lr::mapping::Map<float> &map, std::vector<std::string> &goalPose_types, std::vector<std::string> &current_goalPose_types)
  {
    std::cout << "GET_TRANSPORT_GOALS" << std::endl;
    
    viz_state_l1_goal_poses = transport_planner.getUnvisitedGoalPoses(goalPose_types);
    
    current_goal_poses = transport_planner.getGoalPose(agent_pose, map, goalPose_types);

    transport_planner.getGoalPoseType(current_goalPose_types);

    // DEBUG
    std::cout << "Current goal poses size: " << current_goal_poses.size() << std::endl;
    for (size_t i = 0; i < current_goal_poses.size(); i++) {
      std::cout << "  Pose " << i << ": (" << current_goal_poses[i].pt.x << ", "
                << current_goal_poses[i].pt.y << "), yaw: " << current_goal_poses[i].yaw
                << " | Type: " << current_goalPose_types[i] << std::endl;
    }

    // End the mission when all the transport goals are completed
    if (current_goal_poses.size() == 0) {
      pre_signal_ = Signal::NO;
      curr_state_l0_ = StateL0::END_MISSION;
    }
    // Update shared current state and the precursing signal
    else {
      pre_signal_ = Signal::DRIVE;
      curr_state_l0_ = StateL0::GOALS_REMAINING;
    }
  }

} // planning namespace
} // lr namespace