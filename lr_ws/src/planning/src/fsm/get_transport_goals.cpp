#include <planning/fsm/get_transport_goals.hpp>
#include <iostream> // DEBUG

namespace cg {
namespace planning {

  void GetTransportGoals::runState(std::vector<cg_msgs::msg::Pose2D> &current_goal_poses, std::vector<cg_msgs::msg::Pose2D> &viz_state_l1_goal_poses, cg::planning::TransportPlanner &transport_planner, const cg_msgs::msg::Pose2D &agent_pose, const cg::mapping::Map<float> &map)
  {
    std::cout << "GET_TRANSPORT_GOALS" << std::endl;
    
    viz_state_l1_goal_poses = transport_planner.getUnvisitedGoalPoses();
    
    current_goal_poses = transport_planner.getGoalPose(agent_pose, map);

    // DEBUG
    std::cout << "Current goal poses size: " << current_goal_poses.size() << std::endl;
    for (size_t i = 0; i < current_goal_poses.size(); i++) {
      std::cout << "Current goal pose " << i << ": " << current_goal_poses[i].pt.x << ", " << current_goal_poses[i].pt.y  << "," << current_goal_poses[i].yaw << std::endl;
    }
    

    // Update shared current state and the precursing signal
    pre_signal_ = Signal::DRIVE;
    curr_state_l0_ = StateL0::GOALS_REMAINING;
  }

} // planning namespace
} // cg namespace
