#ifndef MANIPULATION_PLANNER_HPP
#define MANIPULATION_PLANNER_HPP

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>

#include <tf2/exceptions.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

#include <lr_msgs/srv/plan_path.hpp>

#include <vector>
#include <queue>
#include <cmath>
#include <limits>
#include <optional>

struct Cell
{
    int idx;
    double f;
    double g;
    int parent;
};

struct PQComp
{
    bool operator()(Cell const &a, Cell const &b) const
    {
        return a.f > b.f; // min-heap by f
    }
};

class ManipulationPlanner : public rclcpp::Node
{
public:
    ManipulationPlanner();

private:
    void mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);
    void planService(
        const std::shared_ptr<lr_msgs::srv::PlanPath::Request> request,
        std::shared_ptr<lr_msgs::srv::PlanPath::Response> response);

    std::optional<std::vector<int>> runAStar(int start_idx, int goal_idx);

    bool isOccupied(int idx) const;
    bool isValidIndex(int idx) const;
    int worldToIndex(double wx, double wy) const;
    std::pair<double, double> indexToWorld(int idx) const;
    std::pair<int, int> indexToXY(int idx) const;
    int xyToIndex(int x, int y) const;

    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
    rclcpp::Service<lr_msgs::srv::PlanPath>::SharedPtr plan_srv_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;

    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

    nav_msgs::msg::OccupancyGrid map_;
    std::vector<int8_t> map_data_;
    bool map_received_{false};

    unsigned int width_{0}, height_{0};
    double resolution_{0.0};
    geometry_msgs::msg::Pose origin_;

    std::string map_topic_;
    std::string map_frame_;
    std::string base_frame_;
    int occupied_threshold_{65};
    bool use_8_connected_{true};
};

#endif // MANIPULATION_PLANNER_HPP
