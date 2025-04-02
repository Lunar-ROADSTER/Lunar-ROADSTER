#ifndef PLANNING__BEHAVIOR_EXECUTIVE_HPP
#define PLANNING__BEHAVIOR_EXECUTIVE_HPP

#include <rclcpp/rclcpp.hpp>
#include <planning/planning_util.hpp>
#include <cg_msgs/srv/site_map.hpp> // Service for receiving SiteMap height data
#include <cg_msgs/srv/update_trajectory.hpp>   // Service for updating current trajectory
#include <cg_msgs/srv/enable_worksystem.hpp> // Service to enable/disable worksystem controller
#include <nav_msgs/msg/odometry.hpp> // Callback for pose
#include <tf2/LinearMath/Matrix3x3.h> // For converting from nav_msgs quaternions to rpy
#include <limits> // used for infinity values

// Finite state machine and states
#include <planning/fsm/fsm.hpp>
#include <planning/fsm/ready.hpp>
#include <planning/fsm/update_map.hpp>
#include <planning/fsm/site_work_done.hpp>
#include <planning/fsm/map_explored.hpp>
#include <planning/fsm/plan_transport.hpp>
#include <planning/fsm/get_transport_goals.hpp>
#include <planning/fsm/goals_remaining.hpp>
#include <planning/fsm/get_worksystem_trajectory.hpp>
#include <planning/fsm/following_trajectory.hpp>
#include <planning/fsm/end_mission.hpp>
#include <planning/fsm/stopped.hpp>

// Viz
#include <nav_msgs/msg/path.hpp> // For visualizing the current trajectory
#include <geometry_msgs/msg/pose_stamped.hpp> // For visualizing the current trajectory and agent pose
#include <geometry_msgs/msg/pose_array.hpp> // For visualizing the current goal poses
#include <tf2/LinearMath/Quaternion.h> // For visualizing the current goal poses

// Debug
#include <std_msgs/msg/bool.hpp> // Stepping through planning debug

namespace cg {
namespace planning {

class BehaviorExecutive : public rclcpp::Node {

public:
  BehaviorExecutive();

private: 
  /* Publishers and Subscribers */
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr viz_path_pub_;
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr viz_visited_trajectories_pub_;
  rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr viz_goals_pub_;
  rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr viz_state_l1_goals_pub_;
  rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr viz_agent_pub_;
  rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr viz_curr_goal_pub_;

  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr global_robot_state_sub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_robot_state_sub_;

  rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr debug_trigger_sub_;

  /* Services */
  // Create callback groups for service call in timer: https://docs.ros.org/en/galactic/How-To-Guides/Using-callback-groups.html
  rclcpp::CallbackGroup::SharedPtr site_map_client_group_;
  rclcpp::CallbackGroup::SharedPtr update_trajectory_client_group_;
  rclcpp::CallbackGroup::SharedPtr enable_worksystem_client_group_;

  rclcpp::CallbackGroup::SharedPtr fsm_timer_cb_group_;
  rclcpp::TimerBase::SharedPtr fsm_timer_; // For controlled looping fsm updates

  rclcpp::CallbackGroup::SharedPtr viz_timer_cb_group_;
  rclcpp::TimerBase::SharedPtr viz_timer_; // For controlled looping viz updates

  rclcpp::Client<cg_msgs::srv::SiteMap>::SharedPtr site_map_client_;
  rclcpp::Client<cg_msgs::srv::UpdateTrajectory>::SharedPtr update_trajectory_client_;
  rclcpp::Client<cg_msgs::srv::EnableWorksystem>::SharedPtr enable_worksystem_client_;

  int fsm_timer_callback_ms_;
  long int viz_timer_callback_ms_;
  long int service_response_timeout_ms_;
  bool sync_callback_groups_{true};

  /* Callbacks */
  void fsmTimerCallback(); // For looping publish
  void vizTimerCallback(); // For looping publish

  void globalRobotStateCallback(const nav_msgs::msg::Odometry::SharedPtr msg);
  void odomRobotStateCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

  void debugTriggerCallback(const std_msgs::msg::Bool::SharedPtr msg);

  /* Services */
  bool updateMapFromService(bool verbose);
  void generateZeroMapCsv();
  bool enableWorksystemService(const bool enable_worksystem, bool verbose);

  /* Poses */
  nav_msgs::msg::Odometry global_robot_state_;
  nav_msgs::msg::Odometry odom_robot_state_;
  cg_msgs::msg::Pose2D current_agent_pose_;

  /* Debug */
  bool traj_debug_ = false;
  bool debug_trigger_ = false;

  /* FSM parameters */
  bool map_updated_ = false;

  std::vector<cg_msgs::msg::Pose2D> current_goal_poses_;
  cg_msgs::msg::Pose2D current_goal_pose_;

  bool nav_transport_ = false;
  bool enable_worksystem_ = false;

  /* Map parameters */
  size_t map_height;
  size_t map_width;
  float map_resolution;
  std::string design_topo_filepath;

  /* FSM */
  cg::planning::FSM fsm_;

  // FSM states
  cg::planning::Ready ready_;
  cg::planning::UpdateMap update_map_;
  cg::planning::SiteWorkDone site_work_done_;
  cg::planning::MapExplored map_explored_;
  cg::planning::PlanTransport plan_transport_;
  cg::planning::GetTransportGoals get_transport_goals_;
  cg::planning::GoalsRemaining goals_remaining_;
  cg::planning::GetWorksystemTrajectory get_worksystem_trajectory_;
  cg::planning::FollowingTrajectory following_trajectory_;
  cg::planning::EndMission end_mission_;
  cg::planning::Stopped stopped_;

}; // class BehaviorExecutive

} // namespace planning
} // namespace cg

#endif // PLANNING__BEHAVIOR_EXECUTIVE_HPP