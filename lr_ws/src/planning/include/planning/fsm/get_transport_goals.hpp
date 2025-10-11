#ifndef PLANNING__GET_TRANSPORT_GOALS_HPP
#define PLANNING__GET_TRANSPORT_GOALS_HPP

#include <planning/fsm/fsm.hpp>
#include <planning/transport_planner.hpp>

namespace lr {
namespace planning {

// Inherit from FSM to have access to current state/signal
class GetTransportGoals : public FSM {

public:
void runState(std::vector<lr_msgs::msg::Pose2D> &current_goal_poses, std::vector<lr_msgs::msg::Pose2D> &viz_state_l1_goal_poses, lr::planning::TransportPlanner &transport_planner, const lr_msgs::msg::Pose2D &agent_pose, const lr::mapping::Map<float> &map, std::vector<std::string> &goalPose_types, std::vector<std::string> &current_goalPose_types);
}; // class State

} // namespace planning
} // namespace lr

#endif // PLANNING__GET_TRANSPORT_GOALS_HPP
