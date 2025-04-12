#include "planning/behavior_executive_node.hpp"

namespace cg {
namespace planning {

BehaviorExecutive::BehaviorExecutive() : Node("behavior_executive_node")
{
  /* Initialize publishers and subscribers */
  // viz_path_pub_ = this->create_publisher<nav_msgs::msg::Path>("/viz/planning/current_path", 1);
  // viz_visited_trajectories_pub_ = this->create_publisher<nav_msgs::msg::Path>("/viz/planning/visited_trajectories", 1);
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
  this->declare_parameter<int>("height", 70);
  this->get_parameter("height", map_height);
  this->declare_parameter<int>("width", 70);
  this->get_parameter("width", map_width);
  this->declare_parameter<float>("resolution", 0.1);
  this->get_parameter("resolution", map_resolution);
  this->declare_parameter<std::string>("design_topo_filepath", "/root/Lunar_ROADSTER/lr_ws/src/planning/saved_maps/zeros_height_map.csv");
  this->get_parameter("design_topo_filepath", design_topo_filepath);
  this->declare_parameter<std::string>("site_topo_filepath", "/root/Lunar_ROADSTER/lr_ws/src/planning/saved_maps/elevation_map_1d.csv");
  this->get_parameter("site_topo_filepath", site_topo_filepath);
  // this->declare_parameter<std::string>("design_topo_filepath", "/home/williamfbx/Lunar-ROADSTER/lr_ws/src/planning/saved_maps/zeros_height_map.csv");
  // this->get_parameter("design_topo_filepath", design_topo_filepath);
  // this->declare_parameter<std::string>("site_topo_filepath", "/home/williamfbx/Lunar-ROADSTER/lr_ws/src/planning/saved_maps/elevation_map_1d.csv");
  // this->get_parameter("site_topo_filepath", site_topo_filepath);
  float xTransform;
  float yTransform;
  this->declare_parameter<float>("xTransform", 0.0);
  this->get_parameter("xTransform", xTransform);
  this->declare_parameter<float>("yTransform", 0.0);
  this->get_parameter("yTransform", yTransform);
  
  // Transport planner
  transport_planner_ = std::make_unique<TransportPlanner>(TransportPlanner());
  float source_threshold_z;
  float sink_threshold_z;
  this->declare_parameter<float>("source_threshold_z", 0.01);
  this->get_parameter("source_threshold_z", source_threshold_z);
  this->declare_parameter<float>("sink_threshold_z", 0.01);
  this->get_parameter("sink_threshold_z", sink_threshold_z);

  transport_planner_->setSourceThresholdZ(source_threshold_z);
  transport_planner_->setSinkThresholdZ(sink_threshold_z);

  float boundary_min; 
  float boundary_max;
  this->declare_parameter<float>("boundary_min", 0.4);
  this->get_parameter("boundary_min", boundary_min);
  this->declare_parameter<float>("boundary_max", 4.6);
  this->get_parameter("boundary_max", boundary_max);

  transport_planner_->setBoundaryMin(boundary_min);
  transport_planner_->setBoundaryMax(boundary_max);

  float thresh_filter_assignment_pos;
  double thresh_filter_assignment_head;
  this->declare_parameter<float>("thresh_filter_assignment_pos", 0.0);
  this->get_parameter("thresh_filter_assignment_pos", thresh_filter_assignment_pos);
  this->declare_parameter<double>("thresh_filter_assignment_head", 6.28);
  this->get_parameter("thresh_filter_assignment_head", thresh_filter_assignment_head);

  transport_planner_->setThreshFilterAssignmentPos(thresh_filter_assignment_pos);
  transport_planner_->setThreshFilterAssignmentHead(thresh_filter_assignment_head);

  this->declare_parameter<float>("thresh_max_assignment_distance", 0.7);
  this->get_parameter("thresh_max_assignment_distance", thresh_max_assignment_distance_);
  this->declare_parameter<int>("transport_plan_max_calls", INT_MAX);
  this->get_parameter("transport_plan_max_calls", transport_plan_max_calls_);

  double last_pose_offset;
  double source_pose_offset;
  this->declare_parameter<double>("last_pose_offset", 1.0);
  this->get_parameter("last_pose_offset", last_pose_offset);
  this->declare_parameter<double>("source_pose_offset", 1.0);
  this->get_parameter("source_pose_offset", source_pose_offset);

  transport_planner_->setLastPoseOffset(last_pose_offset);
  transport_planner_->setSourcePoseOffset(source_pose_offset);

  //Update map parameters
  bool current_height_map_initialized = current_height_map_.load_map_from_file(site_topo_filepath);
  bool design_height_map_initialized = design_height_map_.load_map_from_file(design_topo_filepath);
  seen_map_.load_map_from_file(site_topo_filepath);

  // Validation parameters
  this->declare_parameter<float>("topology_equality_threshold", 0.03);
  this->get_parameter("topology_equality_threshold", topology_equality_threshold_);

  if (!current_height_map_initialized) {
    RCLCPP_FATAL(this->get_logger(), "Current map loading error");
    rclcpp::shutdown();
  }

  if (!design_height_map_initialized) {
    RCLCPP_FATAL(this->get_logger(), "Design map loading error");
    rclcpp::shutdown();
  }

  if ((design_height_map_.getHeight() != current_height_map_.getHeight()) \
        || (design_height_map_.getWidth() != current_height_map_.getWidth()) \
        || (design_height_map_.getResolution() != current_height_map_.getResolution())) {
    RCLCPP_FATAL(this->get_logger(), "Map dimensions do not align!\n    Site map <height, width, resolution, data.size()> <%ld, %ld, %f, %ld>\n    Design map <height, width, resolution, data.size()>: <%ld, %ld, %f, %ld>", current_height_map_.getHeight(), current_height_map_.getWidth(), current_height_map_.getResolution(), current_height_map_.getCellData().size(), design_height_map_.getHeight(), design_height_map_.getWidth(), design_height_map_.getResolution(), design_height_map_.getCellData().size());
    rclcpp::shutdown();
  }

  // Create pose of local map, assumed with no rotation
  local_map_relative_to_global_frame_ = create_pose2d(xTransform, yTransform, 0.0);
  global_map_relative_to_local_frame_ = create_pose2d(-xTransform, -yTransform, 0.0);

  // Viz
  this->declare_parameter<double>("viz_planning_height", 0.0);
  this->get_parameter("viz_planning_height", viz_planning_height_);
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
    plan_transport_.runState(*transport_planner_, current_height_map_, design_height_map_, current_seen_map_, thresh_max_assignment_distance_);
    break;

  case cg::planning::FSM::StateL0::GET_TRANSPORT_GOALS:
    // TODO: Ankit & Deepam
    // Implement transport stack
    // Uses the cg::Planning::TransportPlanner object handler from PLAN_TRANSPORT to extract a list of transport goals
    // Need to update object handler to have new method that nav_transport_ = false if only nav, nav_transport_ = true when nav + tool planner
    num_poses_before_ = current_goal_poses_.size(); // DEBUG
    get_transport_goals_.runState(current_goal_poses_, viz_state_l1_goal_poses_, *transport_planner_, current_agent_pose_, current_height_map_);
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
    following_trajectory_.runState(current_goal_pose_);


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

  // Robot state initialization
  init_robot_pose_ = true;

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
  // current_agent_pose_ = cg::planning::transformPose(global_robot_pose_, global_map_relative_to_local_frame_);

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

  // Agent
  if (init_robot_pose_) {
    cg_msgs::msg::Pose2D global_agent_pose = cg::planning::transformPose(current_agent_pose_, local_map_relative_to_global_frame_);
    viz_agent_.pose.position.x = global_agent_pose.pt.x;
    viz_agent_.pose.position.y = global_agent_pose.pt.y;
    viz_agent_.pose.position.z = viz_planning_height_;
  
    tf2::Quaternion q_agent;
    q_agent.setRPY(0, 0, global_agent_pose.yaw);
    viz_agent_.pose.orientation.x = q_agent.x();
    viz_agent_.pose.orientation.y = q_agent.y();
    viz_agent_.pose.orientation.z = q_agent.z();
    viz_agent_.pose.orientation.w = q_agent.w();
  
    viz_agent_.header.stamp = this->get_clock()->now();
    viz_agent_.header.frame_id = "map";
  
    viz_agent_pub_->publish(viz_agent_);
  }
  else {
    if (debug_trigger_) {
      std::cout << "Robot pose not initialized" << std::endl;
    }
  }

  // Current goal
  cg_msgs::msg::Pose2D global_curr_goal_pose = cg::planning::transformPose(current_goal_pose_, local_map_relative_to_global_frame_);
  viz_curr_goal_.pose.position.x = global_curr_goal_pose.pt.x;
  viz_curr_goal_.pose.position.y = global_curr_goal_pose.pt.y;
  viz_curr_goal_.pose.position.z = viz_planning_height_;

  tf2::Quaternion q_curr_goal;
  q_curr_goal.setRPY(0, 0, global_curr_goal_pose.yaw);
  viz_curr_goal_.pose.orientation.x = q_curr_goal.x();
  viz_curr_goal_.pose.orientation.y = q_curr_goal.y();
  viz_curr_goal_.pose.orientation.z = q_curr_goal.z();
  viz_curr_goal_.pose.orientation.w = q_curr_goal.w();

  viz_curr_goal_.header.stamp = this->get_clock()->now();
  viz_curr_goal_.header.frame_id = "map";

  viz_curr_goal_pub_->publish(viz_curr_goal_);

  // Goal poses
  viz_goals_.poses.clear();
  for (cg_msgs::msg::Pose2D goal_pose : current_goal_poses_) {
    cg_msgs::msg::Pose2D global_goal_pose = cg::planning::transformPose(goal_pose, local_map_relative_to_global_frame_);

    geometry_msgs::msg::Pose pose_single;
    pose_single.position.x = global_goal_pose.pt.x;
    pose_single.position.y = global_goal_pose.pt.y;
    pose_single.position.z = viz_planning_height_;

    tf2::Quaternion q;
    q.setRPY(0, 0, global_goal_pose.yaw);
    pose_single.orientation.x = q.x();
    pose_single.orientation.y = q.y();
    pose_single.orientation.z = q.z();
    pose_single.orientation.w = q.w();

    viz_goals_.poses.push_back(pose_single);
  }
  viz_goals_.header.stamp = this->get_clock()->now();
  viz_goals_.header.frame_id = "map";
  viz_goals_pub_->publish(viz_goals_);

  // StateL1 goal poses
  viz_state_l1_goals_.poses.clear();
  for (cg_msgs::msg::Pose2D goal_pose : viz_state_l1_goal_poses_) {
    cg_msgs::msg::Pose2D global_goal_pose = cg::planning::transformPose(goal_pose, local_map_relative_to_global_frame_);

    geometry_msgs::msg::Pose pose_single;
    pose_single.position.x = global_goal_pose.pt.x;
    pose_single.position.y = global_goal_pose.pt.y;
    pose_single.position.z = viz_planning_height_ * 0.9; // Make L1 goals covered by current goals when overlapping

    tf2::Quaternion q;
    q.setRPY(0, 0, global_goal_pose.yaw);
    pose_single.orientation.x = q.x();
    pose_single.orientation.y = q.y();
    pose_single.orientation.z = q.z();
    pose_single.orientation.w = q.w();

    viz_state_l1_goals_.poses.push_back(pose_single);
  }
  viz_state_l1_goals_.header.stamp = this->get_clock()->now();
  viz_state_l1_goals_.header.frame_id = "map";
  viz_state_l1_goals_pub_->publish(viz_state_l1_goals_);
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

  std::vector<int> temp_current_seen_map(4900, 1);
  current_seen_map_ = temp_current_seen_map;
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
