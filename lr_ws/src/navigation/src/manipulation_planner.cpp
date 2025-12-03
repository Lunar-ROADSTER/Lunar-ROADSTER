/**
 * @file manipulation_planner_node.cpp
 * @brief Short-range A* grid planner for precise manipulation positioning.
 *
 * This node provides a lightweight, local manipulation planner used to
 * reposition the Lunar ROADSTER base near the worksite. It:
 *  - Subscribes to a 2D occupancy grid map (nav_msgs::msg::OccupancyGrid).
 *  - Retrieves the robot’s current pose via TF (map_frame ← base_frame).
 *  - Receives a goal pose through the PlanPath service.
 *  - Performs 4- or 8-connected A* search over the grid.
 *  - Outputs a nav_msgs::msg::Path suitable for slow, precise alignment
 *    before deploying the grading tool.
 *
 * This planner is distinct from the larger crater ring planner and is
 * intended for the `Forward_manipulation` phase, where fine placement
 * matters more than global travel efficiency.
 *
 * @version 1.0.0
 * @date 2025-12-02
 *
 * Maintainer: Bhaswanth Ayapilla
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria,
 *               Bhaswanth Ayapilla, Simson D’Souza,
 *               Boxiang (William) Fu
 *
 * Subscribers:
 *  - map_topic (default: /map)
 *      nav_msgs::msg::OccupancyGrid
 *      Occupancy map used as the planning grid.
 *
 * Service Servers:
 *  - /manipulation_planner/plan_path (lr_msgs::srv::PlanPath)
 *      Request:
 *        goal (geometry_msgs::msg::PoseStamped)
 *        smooth (bool, unused)
 *      Response:
 *        success (bool)
 *        message (string)
 *        path (nav_msgs::msg::Path)
 *
 * Publishers:
 *  - /manipulation_planner/path
 *      nav_msgs::msg::Path (A* result path)
 *  - /manipulation_planner/goal_marker
 *      visualization_msgs::msg::Marker (green sphere at goal)
 *
 * Parameters:
 *  - map_topic (string, "/map")
 *  - occupied_threshold (int, 100)
 *  - use_8_connected (bool, true)
 *  - map_frame (string, "map")
 *  - base_frame (string, "base_link")
 *
 * Features:
 *  - Uses Euclidean heuristic in world coordinates.
 *  - Selectable 4- or 8-connected neighborhood.
 *  - Cleanly integrates with ring planner via shared PlanPath interface.
 *  - Designed for slow and precise base alignment near the manipulation site.
 *
 * @credit Local manipulation planner for fine base positioning in the
 *         Lunar ROADSTER autonomy stack.
 */

#include "navigation/manipulation_planner.hpp"

using PlanPath = lr_msgs::srv::PlanPath;

ManipulationPlanner::ManipulationPlanner()
    : Node("manipulation_planner"), map_received_(false)
{
  this->declare_parameter<std::string>("map_topic", "/map");
  this->declare_parameter<int>("occupied_threshold", 100);
  this->declare_parameter<bool>("use_8_connected", true);
  this->declare_parameter<std::string>("map_frame", "map");
  this->declare_parameter<std::string>("base_frame", "base_link");

  map_topic_ = this->get_parameter("map_topic").as_string();
  occupied_threshold_ = this->get_parameter("occupied_threshold").as_int();
  use_8_connected_ = this->get_parameter("use_8_connected").as_bool();
  map_frame_ = this->get_parameter("map_frame").as_string();
  base_frame_ = this->get_parameter("base_frame").as_string();

  RCLCPP_INFO(get_logger(),
              "ManipulationPlanner: map=%s  occupied_threshold=%d  use_8_connected=%s",
              map_topic_.c_str(), occupied_threshold_,
              use_8_connected_ ? "true" : "false");

  map_sub_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
      map_topic_, 10, std::bind(&ManipulationPlanner::mapCallback, this, std::placeholders::_1));

  plan_srv_ = this->create_service<PlanPath>(
      "/manipulation_planner/plan_path",
      std::bind(&ManipulationPlanner::planService, this, std::placeholders::_1, std::placeholders::_2));

  path_pub_ = this->create_publisher<nav_msgs::msg::Path>("/manipulation_planner/path", 1);

  goal_marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>(
      "/manipulation_planner/goal_marker", 10);

  tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

  RCLCPP_INFO(get_logger(), "ManipulationPlanner node initialized.");
}

void ManipulationPlanner::mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
{
  map_ = *msg;
  width_ = map_.info.width;
  height_ = map_.info.height;
  resolution_ = map_.info.resolution;
  origin_ = map_.info.origin;
  map_data_ = map_.data;
  map_received_ = true;

  RCLCPP_INFO(get_logger(), "Map received: %u x %u (res=%.3f)", width_, height_, resolution_);
}

void ManipulationPlanner::planService(
    const std::shared_ptr<PlanPath::Request> request,
    std::shared_ptr<PlanPath::Response> response)
{
  if (!map_received_)
  {
    response->success = false;
    response->message = "No map received yet.";
    RCLCPP_WARN(get_logger(), "[Service] No map yet.");
    return;
  }

  visualization_msgs::msg::Marker goal_marker;
  goal_marker.header.frame_id = map_frame_;
  goal_marker.header.stamp = now();
  goal_marker.ns = "manipulation_goal";
  goal_marker.id = 0;
  goal_marker.type = visualization_msgs::msg::Marker::SPHERE;
  goal_marker.action = visualization_msgs::msg::Marker::ADD;

  goal_marker.pose.position.x = request->goal.pose.position.x;
  goal_marker.pose.position.y = request->goal.pose.position.y;
  goal_marker.pose.position.z = 0.0;
  goal_marker.pose.orientation.w = 1.0;

  goal_marker.scale.x = goal_marker.scale.y = goal_marker.scale.z = 0.3; // size of sphere
  goal_marker.color.r = 0.0f;
  goal_marker.color.g = 1.0f;
  goal_marker.color.b = 0.0f;
  goal_marker.color.a = 1.0f;

  goal_marker.lifetime = rclcpp::Duration(0, 0); // persist
  goal_marker_pub_->publish(goal_marker);

  geometry_msgs::msg::TransformStamped tfst;
  try
  {
    tfst = tf_buffer_->lookupTransform(map_frame_, base_frame_, tf2::TimePointZero);
  }
  catch (tf2::TransformException &ex)
  {
    response->success = false;
    response->message = std::string("TF lookup failed: ") + ex.what();
    RCLCPP_WARN(get_logger(), "[Service] TF lookup failed: %s", ex.what());
    return;
  }

  geometry_msgs::msg::Pose start_pose;
  start_pose.position.x = tfst.transform.translation.x;
  start_pose.position.y = tfst.transform.translation.y;
  start_pose.orientation = tfst.transform.rotation;

  int start_idx = worldToIndex(start_pose.position.x, start_pose.position.y);
  int goal_idx = worldToIndex(request->goal.pose.position.x, request->goal.pose.position.y);

  if (!isValidIndex(start_idx) || !isValidIndex(goal_idx))
  {
    response->success = false;
    response->message = "Start or goal outside map bounds.";
    RCLCPP_ERROR(get_logger(), "[Service] Invalid start or goal index.");
    return;
  }

  if (isOccupied(goal_idx))
  {
    RCLCPP_WARN(get_logger(), "[Service] Goal cell is occupied.");
  }

  RCLCPP_INFO(get_logger(),
              "[Service] Planning from (%.2f, %.2f) → (%.2f, %.2f)",
              start_pose.position.x, start_pose.position.y,
              request->goal.pose.position.x, request->goal.pose.position.y);

  auto path_opt = runAStar(start_idx, goal_idx);
  if (!path_opt.has_value())
  {
    response->success = false;
    response->message = "A* failed to find a path.";
    return;
  }

  nav_msgs::msg::Path path_msg;
  path_msg.header.frame_id = map_frame_;
  path_msg.header.stamp = now();
  for (int idx : path_opt.value())
  {
    geometry_msgs::msg::PoseStamped p;
    p.header = path_msg.header;
    auto w = indexToWorld(idx);
    p.pose.position.x = w.first;
    p.pose.position.y = w.second;
    p.pose.orientation.w = 1.0;
    path_msg.poses.push_back(p);
  }

  path_pub_->publish(path_msg);
  response->path = path_msg;
  response->success = true;
  response->message = "Path computed successfully.";

  RCLCPP_INFO(get_logger(), "[Service] Path found with %zu poses.", path_msg.poses.size());
}

std::optional<std::vector<int>> ManipulationPlanner::runAStar(int start_idx, int goal_idx)
{
  const double inf = std::numeric_limits<double>::infinity();
  int N = width_ * height_;
  std::vector<double> g_cost(N, inf);
  std::vector<int> parent(N, -1);
  std::vector<char> closed(N, 0);

  auto heuristic = [&](int a_idx, int b_idx) -> double
  {
    auto aw = indexToWorld(a_idx);
    auto bw = indexToWorld(b_idx);
    return std::hypot(aw.first - bw.first, aw.second - bw.second);
  };

  std::priority_queue<Cell, std::vector<Cell>, PQComp> open;
  g_cost[start_idx] = 0.0;
  open.push(Cell{start_idx, heuristic(start_idx, goal_idx), 0.0, -1});

  std::vector<std::pair<int, int>> neighbors = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  if (use_8_connected_)
  {
    neighbors.insert(neighbors.end(), {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}});
  }

  while (!open.empty())
  {
    Cell current = open.top();
    open.pop();
    int u = current.idx;
    if (closed[u])
      continue;
    closed[u] = 1;
    parent[u] = current.parent;

    if (u == goal_idx)
    {
      std::vector<int> path;
      for (int cur = u; cur != -1; cur = parent[cur])
        path.push_back(cur);
      std::reverse(path.begin(), path.end());
      return path;
    }

    auto [ux, uy] = indexToXY(u);
    for (auto &d : neighbors)
    {
      int nx = ux + d.first;
      int ny = uy + d.second;
      if (nx < 0 || nx >= (int)width_ || ny < 0 || ny >= (int)height_)
        continue;
      int v = xyToIndex(nx, ny);
      if (closed[v] || isOccupied(v))
        continue;

      double step = std::hypot(d.first * resolution_, d.second * resolution_);
      double tentative_g = g_cost[u] + step;
      if (tentative_g < g_cost[v])
      {
        g_cost[v] = tentative_g;
        double f = tentative_g + heuristic(v, goal_idx);
        open.push(Cell{v, f, tentative_g, u});
      }
    }
  }
  return std::nullopt;
}

bool ManipulationPlanner::isOccupied(int idx) const
{
  // if (!isValidIndex(idx))
  //   return true;
  // int8_t val = map_data_[idx];
  // if (val < 0)
  //   return false; // unknown = free
  // return val >= occupied_threshold_;

  return false;
}

bool ManipulationPlanner::isValidIndex(int idx) const
{
  return idx >= 0 && idx < (int)map_data_.size();
}

int ManipulationPlanner::worldToIndex(double wx, double wy) const
{
  double mx = (wx - origin_.position.x) / resolution_;
  double my = (wy - origin_.position.y) / resolution_;
  int ix = static_cast<int>(std::floor(mx));
  int iy = static_cast<int>(std::floor(my));
  return xyToIndex(ix, iy);
}

std::pair<double, double> ManipulationPlanner::indexToWorld(int idx) const
{
  auto [x, y] = indexToXY(idx);
  double wx = origin_.position.x + (x + 0.5) * resolution_;
  double wy = origin_.position.y + (y + 0.5) * resolution_;
  return {wx, wy};
}

std::pair<int, int> ManipulationPlanner::indexToXY(int idx) const
{
  int x = idx % width_;
  int y = idx / width_;
  return {x, y};
}

int ManipulationPlanner::xyToIndex(int x, int y) const
{
  if (x < 0 || x >= (int)width_ || y < 0 || y >= (int)height_)
    return -1;
  return y * width_ + x;
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ManipulationPlanner>());
  rclcpp::shutdown();
  return 0;
}
