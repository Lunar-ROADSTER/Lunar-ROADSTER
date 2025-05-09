#include <planning/fsm/get_transport_goals.hpp>
#include <iostream> // DEBUG

namespace cg {
namespace planning {

  void GetTransportGoals::runState(std::vector<cg_msgs::msg::Pose2D> &current_goal_poses, std::vector<cg_msgs::msg::Pose2D> &viz_state_l1_goal_poses, cg::planning::TransportPlanner &transport_planner, const cg_msgs::msg::Pose2D &agent_pose, const cg::mapping::Map<float> &map, std::vector<std::string> &goalPose_types, std::vector<std::string> &current_goalPose_types)
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
} // cg namespace