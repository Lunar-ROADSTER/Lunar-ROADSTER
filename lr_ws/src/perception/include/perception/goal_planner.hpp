#ifndef PERCEPTION__GOAL_PLANNER_HPP
#define PERCEPTION__GOAL_PLANNER_HPP

#include <perception/common.hpp>
#include <mapping/map.hpp>

namespace lr {
namespace perception {

class GoalPlanner {

public:
  virtual std::vector<lr_msgs::msg::Pose2D> getGoalPose(
    const lr_msgs::msg::Pose2D& agent_pose, const lr::mapping::Map<float>& map, std::vector<std::string> &goalPose_types) = 0;
};

} // namespace perception
} // namespace lr

#endif // PERCEPTION__GOAL_PLANNER_HPP
