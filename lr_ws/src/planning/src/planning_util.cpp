#include "planning/planning_util.hpp"

namespace cg {
namespace planning {

cg_msgs::msg::Point2D create_point2d(const double& x, const double& y) {
  cg_msgs::msg::Point2D pt;
  pt.x = x;
  pt.y = y;
  return pt;
}

cg_msgs::msg::Pose2D create_pose2d(const double& x, const double& y, const double& yaw) {
  cg_msgs::msg::Pose2D pose;
  pose.pt = create_point2d(x, y);

  // Normalize yaw within 0,2*M_PI for distance thresholding and debugging
  float norm_yaw = std::fmod(yaw, 2.0*M_PI);
  if (norm_yaw < 0.0f) norm_yaw += 2.0*M_PI;

  pose.yaw = norm_yaw;
  return pose;
}

} // planning namespace
} // cg namespace
