#include "planning/behavior_executive_node.hpp"

namespace cg {
namespace planning {

BehaviorExecutive::BehaviorExecutive() : Node("behavior_executive_node")
{
  /* Initialize publishers and subscribers */
  viz_path_pub_ = this->create_publisher<nav_msgs::msg::Path>("/viz/planning/current_path", 1);
  viz_visited_trajectories_pub_ = this->create_publisher<nav_msgs::msg::Path>("/viz/planning/visited_trajectories", 1);
  viz_goals_pub_ = this->create_publisher<geometry_msgs::msg::PoseArray>("/viz/planning/current_goals", 1);
  viz_state_l1_goals_pub_ = this->create_publisher<geometry_msgs::msg::PoseArray>("/viz/planning/all_state_l1_goals", 1);
  viz_agent_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/viz/planning/current_agent", 1);
  viz_curr_goal_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/viz/planning/current_goal", 1);

  /* Initialize services */
  // Create reentrant callback group for service call in timer: https://docs.ros.org/en/galactic/How-To-Guides/Using-callback-groups.html
  this->declare_parameter<bool>("sync_callback_groups", true);
  this->get_parameter("sync_callback_groups", sync_callback_groups_);

  fsm_timer_cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
  if (!sync_callback_groups_) {
    viz_timer_cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    viz_timer_ = this->create_wall_timer(std::chrono::milliseconds(viz_timer_callback_ms_), std::bind(&BehaviorExecutive::vizTimerCallback, this), viz_timer_cb_group_);
  }

  // site_map_client_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
  update_trajectory_client_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
  enable_worksystem_client_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

  // Commented out for now - may be used to avoid memory collisions by putting subs into same callback group as FSM
  // rclcpp::SubscriptionOptions subcriber_options;
  // subcriber_options.callback_group = fsm_timer_cb_group_;
  global_robot_state_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/odometry/filtered/ekf_global_node", 1, std::bind(&BehaviorExecutive::globalRobotStateCallback, this, std::placeholders::_1));
  odom_robot_state_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/odometry/filtered/ekf_odom_node", 1, std::bind(&BehaviorExecutive::odomRobotStateCallback, this, std::placeholders::_1));

  debug_trigger_sub_ = this->create_subscription<std_msgs::msg::Bool>(
      "/behavior_exec_debug_trigger", 1, std::bind(&BehaviorExecutive::debugTriggerCallback, this, std::placeholders::_1));


  // Create the service client, joined to the callback group
  // site_map_client_ = this->create_client<cg_msgs::srv::SiteMap>("site_map_server", rmw_qos_profile_services_default, site_map_client_group_);
  update_trajectory_client_ = this->create_client<cg_msgs::srv::UpdateTrajectory>("update_trajectory_server", rmw_qos_profile_services_default, update_trajectory_client_group_);
  enable_worksystem_client_ = this->create_client<cg_msgs::srv::EnableWorksystem>("enable_worksystem_server", rmw_qos_profile_services_default, enable_worksystem_client_group_);

  // Timer callback, joined to the callback group
  this->declare_parameter<int>("fsm_timer_callback_ms", 2000);
  this->get_parameter("fsm_timer_callback_ms", fsm_timer_callback_ms_);
  this->declare_parameter<int>("service_response_timeout_ms", 2000);
  this->get_parameter("service_response_timeout_ms", service_response_timeout_ms_);
  this->declare_parameter<int>("viz_timer_callback_ms", 500);
  this->get_parameter("viz_timer_callback_ms", viz_timer_callback_ms_);
  fsm_timer_ = this->create_wall_timer(std::chrono::milliseconds(fsm_timer_callback_ms_), std::bind(&BehaviorExecutive::fsmTimerCallback, this), fsm_timer_cb_group_);

  /* Load parameters */
  // Map parameters
  this->declare_parameter<int>("height", 50);
  this->get_parameter("height", map_height);
  this->declare_parameter<int>("width", 50);
  this->get_parameter("width", map_width);
  this->declare_parameter<float>("resolution", 0.1);
  this->get_parameter("resolution", map_resolution);
}

void BehaviorExecutive::fsmTimerCallback()
{
  // Run machine
  std::cout << "~~~~~~~ Machine iteration" << std::endl;
  std::cout << "    Pre-Signal: " << fsm_.preSignalToString() << std::endl;
  std::cout << "      State L0: " << fsm_.currStateL0ToString() << std::endl;
  std::cout << "      State L1: " << fsm_.currStateL1ToString() << std::endl;

  switch (fsm_.getCurrStateL0())
  {
  case cg::planning::FSM::StateL0::READY:
    ready_.runState();
    break;

  case cg::planning::FSM::StateL0::UPDATE_MAP:
    map_updated_ = updateMap(false);
    // Check that map was updated correctly
    update_map_.runState(map_updated_, traj_debug_);
    break;

  case cg::planning::FSM::StateL0::SITE_WORK_DONE:
  // TODO: FVD Task
  // Implement validation stack
    site_work_done_.runState();
    break;

  case cg::planning::FSM::StateL0::MAP_EXPLORED:
    map_explored_.runState();
    break;

  case cg::planning::FSM::StateL0::PLAN_TRANSPORT:
    // TODO: Ankit & Deepam
    // Implement transport stack
    // Runs GLOP. If doing beforehand, then extract the saved optimization results and return an object handler of type cg::Planning::TransportPlanner
    // Refer to CG code for what expected input and return shall be
    plan_transport_.runState();
    break;

  case cg::planning::FSM::StateL0::GET_TRANSPORT_GOALS:
    // TODO: Ankit & Deepam
    // Implement transport stack
    // Uses the cg::Planning::TransportPlanner object handler from PLAN_TRANSPORT to extract a list of transport goals
    // Need to update object handler to have new method that nav_transport_ = false if only nav, nav_transport_ = true when nav + tool planner
    get_transport_goals_.runState();
    break;

  case cg::planning::FSM::StateL0::GOALS_REMAINING:
    goals_remaining_.runState(current_goal_poses_, current_goal_pose_);
    break;

  case cg::planning::FSM::StateL0::GET_WORKSYSTEM_TRAJECTORY:
    // TODO: Bhaswanth & Simson
    // Implement nav stack
    // Use current_goal_pose_ to generate a path from current pose to the goal pose. Refer to CG code for what expected input and return shall be
    // To enable the nav worksystem, use worksystem_enabled_ = enableWorksystemService(enable_worksystem_, true);
    get_worksystem_trajectory_.runState();
    break;

  case cg::planning::FSM::StateL0::FOLLOWING_TRAJECTORY:
    // TODO: Bhaswanth & Simson
    // Implement nav stack
    // Follow the generated path from the previous stack
    // nav_transport_ = false if only nav, nav_transport_ = true when nav + tool planner. Feed this as a parameter into .runState()
    following_trajectory_.runState();


    // bool keep_following = following_trajectory_.runState();

    // // Disable worksystem if goal is reached
    // if (!keep_following) {
    //   enable_worksystem_ = false;
    //   worksystem_enabled_ = enableWorksystemService(enable_worksystem_, true);
    // }
    break;

  case cg::planning::FSM::StateL0::END_MISSION:
    end_mission_.runState();
    break;

  case cg::planning::FSM::StateL0::STOPPED:
    // Stop the worksystem
    enable_worksystem_ = false;
    enableWorksystemService(enable_worksystem_, true);

    stopped_.runState();
    break;

  default:
    std::cout << "~ ~ ~ ~ ! Invalid State !" << std::endl;
    break;
  }

  if (sync_callback_groups_) vizTimerCallback();
}


// Callbacks
void BehaviorExecutive::globalRobotStateCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
  // Read in the message
  global_robot_state_ = *msg;

  // Convert to pose
  tf2::Quaternion q(global_robot_state_.pose.pose.orientation.x,
                    global_robot_state_.pose.pose.orientation.y,
                    global_robot_state_.pose.pose.orientation.z,
                    global_robot_state_.pose.pose.orientation.w);
  tf2::Matrix3x3 m(q);
  double global_robot_roll, global_robot_pitch, global_robot_yaw;
  m.getRPY(global_robot_roll, global_robot_pitch, global_robot_yaw);

  current_agent_pose_ = cg::planning::create_pose2d(global_robot_state_.pose.pose.position.x, global_robot_state_.pose.pose.position.y,  global_robot_yaw);

  if (debug_trigger_) {
    std::cout << "Pose2D: x = " << current_agent_pose_.pt.x
              << ", y = " << current_agent_pose_.pt.y
              << ", yaw = " << current_agent_pose_.yaw << std::endl;
  }
}

void BehaviorExecutive::odomRobotStateCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
  odom_robot_state_ = *msg;
}

void BehaviorExecutive::vizTimerCallback() {
  // TODO: Bhaswanth & Simson
  // Viz callback implementation
}

void BehaviorExecutive::debugTriggerCallback(const std_msgs::msg::Bool::SharedPtr msg) {
  (void)msg; // Message not used, just "touch" to hide unused parameter warning
  debug_trigger_ = true;
}


// Services
bool BehaviorExecutive::updateMap(bool verbose = false) {
  
  (void)verbose;
  // Both maps will be saved as CSV files in the /saved_maps directory
  cg::planning::generateZeroMapCsv(map_height, map_width, map_resolution);
  cg::planning::generateElevationMapCsv(map_height, map_width, map_resolution);

  return true;
}


bool BehaviorExecutive::enableWorksystemService(const bool enable_worksystem, bool verbose = false) {
  // TODO: Bhaswanth & Simson
  // Start or stop navigation stack
  (void)enable_worksystem;
  return verbose;
}


} // namespace planning
} // namespace cg
