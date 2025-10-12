#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>

#include <tf2/exceptions.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

#include <vector>
#include <queue>
#include <cmath>
#include <limits>
#include <optional>

using std::placeholders::_1;

struct Cell {
  int idx;
  double f;
  double g;
  int parent;
};

struct PQComp {
  bool operator()(Cell const &a, Cell const &b) const {
    return a.f > b.f; // min-heap by f
  }
};

class AStarPlanner : public rclcpp::Node {
public:
  AStarPlanner()
  : Node("astar_planner"),
    map_received_(false)
  {
    // parameters
    this->declare_parameter<std::string>("map_topic", "/map");
    this->declare_parameter<std::string>("goal_topic", "/goal_pose");
    this->declare_parameter<std::string>("path_topic", "/planned_path");
    this->declare_parameter<int>("occupied_threshold", 65);
    this->declare_parameter<bool>("use_8_connected", true);
    this->declare_parameter<std::string>("map_frame", "map");
    this->declare_parameter<std::string>("base_frame", "base_link");

    map_topic_ = this->get_parameter("map_topic").as_string();
    goal_topic_ = this->get_parameter("goal_topic").as_string();
    path_topic_ = this->get_parameter("path_topic").as_string();
    occupied_threshold_ = this->get_parameter("occupied_threshold").as_int();
    use_8_connected_ = this->get_parameter("use_8_connected").as_bool();
    map_frame_ = this->get_parameter("map_frame").as_string();
    base_frame_ = this->get_parameter("base_frame").as_string();

    RCLCPP_INFO(this->get_logger(), "A* planner: map=%s goal=%s path_pub=%s map_frame=%s base_frame=%s",
                map_topic_.c_str(), goal_topic_.c_str(), path_topic_.c_str(),
                map_frame_.c_str(), base_frame_.c_str());

    // subscriptions & publishers
    map_sub_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
      map_topic_, 10, std::bind(&AStarPlanner::mapCallback, this, _1));
    goal_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
      goal_topic_, 10, std::bind(&AStarPlanner::goalCallback, this, _1));
    path_pub_ = this->create_publisher<nav_msgs::msg::Path>(path_topic_, 10);

    // TF buffer & listener
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
  }

private:
  // callbacks
  void mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg) {
    map_ = *msg;
    width_ = map_.info.width;
    height_ = map_.info.height;
    resolution_ = map_.info.resolution;
    origin_ = map_.info.origin;
    map_data_ = map_.data;
    map_received_ = true;
    RCLCPP_INFO(this->get_logger(), "Map received: %d x %d", width_, height_);
  }

  void goalCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
    if (!map_received_) {
      RCLCPP_WARN(this->get_logger(), "No map yet - ignoring goal");
      return;
    }

    // get start pose from TF: transform base_frame -> map_frame
    geometry_msgs::msg::TransformStamped tfst;
    try {
      // use latest available transform (time 0)
      tfst = tf_buffer_->lookupTransform(map_frame_, base_frame_, tf2::TimePointZero);
    } catch (tf2::TransformException &ex) {
      RCLCPP_WARN(this->get_logger(), "TF lookup failed: %s. Ignoring goal.", ex.what());
      return;
    }

    // convert TF transform to pose
    latest_start_.position.x = tfst.transform.translation.x;
    latest_start_.position.y = tfst.transform.translation.y;
    latest_start_.position.z = tfst.transform.translation.z;
    latest_start_.orientation = tfst.transform.rotation;
    have_start_ = true;

    // convert start and goal to indices
    int start_idx = worldToIndex(latest_start_.position.x, latest_start_.position.y);
    int goal_idx = worldToIndex(msg->pose.position.x, msg->pose.position.y);

    if (!isValidIndex(start_idx) || !isValidIndex(goal_idx)) {
      RCLCPP_ERROR(this->get_logger(), "Start or goal outside map bounds");
      return;
    }

    if (isOccupied(goal_idx)) {
      RCLCPP_WARN(this->get_logger(), "Goal cell is occupied. Attempting anyway, but path may not be found.");
    }

    RCLCPP_INFO(this->get_logger(), "Planning from idx %d -> idx %d", start_idx, goal_idx);

    auto path_indices_opt = runAStar(start_idx, goal_idx);

    if (!path_indices_opt.has_value()) {
      RCLCPP_WARN(this->get_logger(), "A* failed to find a path");
      nav_msgs::msg::Path empty_path;
      empty_path.header.frame_id = map_frame_;
      empty_path.header.stamp = this->now();
      path_pub_->publish(empty_path);
      return;
    }

    // convert to nav_msgs/Path
    auto path_indices = path_indices_opt.value();
    nav_msgs::msg::Path path_msg;
    path_msg.header.frame_id = map_frame_;
    path_msg.header.stamp = this->now();

    for (int idx : path_indices) {
      geometry_msgs::msg::PoseStamped p;
      p.header = path_msg.header;
      auto w = indexToWorld(idx);
      p.pose.position.x = w.first;
      p.pose.position.y = w.second;
      p.pose.position.z = 0.0;
      p.pose.orientation.w = 1.0;
      path_msg.poses.push_back(p);
    }

    path_pub_->publish(path_msg);
    RCLCPP_INFO(this->get_logger(), "Published path with %zu poses", path_msg.poses.size());
  }

  // A* implementation (unchanged logic)
  std::optional<std::vector<int>> runAStar(int start_idx, int goal_idx) {
    const double inf = std::numeric_limits<double>::infinity();
    int N = width_ * height_;
    std::vector<double> g_cost(N, inf);
    std::vector<int> parent(N, -1);
    std::vector<char> closed(N, 0);

    auto heuristic = [&](int a_idx, int b_idx) -> double {
      auto aw = indexToWorld(a_idx);
      auto bw = indexToWorld(b_idx);
      double dx = aw.first - bw.first;
      double dy = aw.second - bw.second;
      return std::hypot(dx, dy);
    };

    std::priority_queue<Cell, std::vector<Cell>, PQComp> open;
    g_cost[start_idx] = 0.0;
    open.push(Cell{start_idx, heuristic(start_idx, goal_idx), 0.0, -1});

    // neighbour offsets for 8-connected or 4-connected grid
    std::vector<std::pair<int,int>> neighbors;
    neighbors.push_back({1, 0});
    neighbors.push_back({-1, 0});
    neighbors.push_back({0, 1});
    neighbors.push_back({0, -1});
    if (use_8_connected_) {
      neighbors.push_back({1,1});
      neighbors.push_back({1,-1});
      neighbors.push_back({-1,1});
      neighbors.push_back({-1,-1});
    }

    int iterations = 0;
    const int max_iterations = N * 10; // safety
    while (!open.empty()) {
      if (++iterations > max_iterations) {
        RCLCPP_WARN(this->get_logger(), "A* iterations exceeded limit");
        break;
      }
      Cell current = open.top();
      open.pop();

      int u = current.idx;
      if (closed[u]) continue;
      closed[u] = 1;
      parent[u] = current.parent;

      if (u == goal_idx) {
        // reconstruct path
        std::vector<int> path;
        int cur = u;
        while (cur != -1) {
          path.push_back(cur);
          cur = parent[cur];
        }
        std::reverse(path.begin(), path.end());
        return path;
      }

      auto [ux, uy] = indexToXY(u);

      for (auto &d : neighbors) {
        int nx = ux + d.first;
        int ny = uy + d.second;
        if (nx < 0 || nx >= (int)width_ || ny < 0 || ny >= (int)height_) continue;
        int v = xyToIndex(nx, ny);
        if (closed[v]) continue;
        if (isOccupied(v)) continue; // skip occupied

        double step_cost = std::hypot(d.first * resolution_, d.second * resolution_);
        double tentative_g = g_cost[u] + step_cost;
        if (tentative_g < g_cost[v]) {
          g_cost[v] = tentative_g;
          double f = tentative_g + heuristic(v, goal_idx);
          open.push(Cell{v, f, tentative_g, u});
        }
      }
    }

    return std::nullopt;
  }

  // map helpers
  bool isOccupied(int idx) const {
    if (!isValidIndex(idx)) return true;
    int8_t val = map_data_[idx];
    // unknown (-1) treat as free (optionally obstacle); here treat unknown as free
    if (val < 0) return false;
    return val >= occupied_threshold_;
  }

  bool isValidIndex(int idx) const {
    return idx >= 0 && idx < (int)map_data_.size();
  }

  int worldToIndex(double wx, double wy) const {
    double mx = (wx - origin_.position.x) / resolution_;
    double my = (wy - origin_.position.y) / resolution_;
    int ix = static_cast<int>(std::floor(mx));
    int iy = static_cast<int>(std::floor(my));
    return xyToIndex(ix, iy);
  }

  std::pair<double,double> indexToWorld(int idx) const {
    auto [x, y] = indexToXY(idx);
    double wx = origin_.position.x + (x + 0.5) * resolution_;
    double wy = origin_.position.y + (y + 0.5) * resolution_;
    return {wx, wy};
  }

  std::pair<int,int> indexToXY(int idx) const {
    int x = idx % width_;
    int y = idx / width_;
    return {x, y};
  }

  int xyToIndex(int x, int y) const {
    if (x < 0 || x >= (int)width_ || y < 0 || y >= (int)height_) return -1;
    return y * width_ + x;
  }

  // members
  rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
  rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr goal_sub_;
  rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;

  nav_msgs::msg::OccupancyGrid map_;
  std::vector<int8_t> map_data_;
  bool map_received_;
  bool have_start_{false};
  geometry_msgs::msg::Pose latest_start_;

  // tf
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
  std::string map_frame_, base_frame_;

  // config
  std::string map_topic_, goal_topic_, path_topic_;
  int occupied_threshold_;
  bool use_8_connected_;

  // map meta
  unsigned int width_{0}, height_{0};
  double resolution_{0.0};
  geometry_msgs::msg::Pose origin_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<AStarPlanner>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
