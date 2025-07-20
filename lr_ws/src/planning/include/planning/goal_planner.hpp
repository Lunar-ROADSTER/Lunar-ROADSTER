#ifndef PLANNING__GOAL_PLANNER_HPP
#define PLANNING__GOAL_PLANNER_HPP

#include <planning/common.hpp>
#include <mapping/map.hpp>

namespace lr {
namespace planning {

class GoalPlanner {

public:
  virtual std::vector<lr_msgs::msg::Pose2D> getGoalPose(
    const lr_msgs::msg::Pose2D& agent_pose, const lr::mapping::Map<float>& map, std::vector<std::string> &goalPose_types) = 0;
};

} // namespace planning
} // namespace lr

#endif // PLANNING__GOAL_PLANNER_HPP
