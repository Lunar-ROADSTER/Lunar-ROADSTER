#ifndef GLOBAL_PLANNER_HPP
#define GLOBAL_PLANNER_HPP

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <nav_msgs/msg/path.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/utils.h>

#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <cmath>
#include <optional>
#include <limits>
#include <array>
#include <queue>
#include <unordered_map>
#include <tuple>

using std::placeholders::_1;

struct Crater
{
    double x{0.0}, y{0.0};
    double diameter{0.0};
};

struct AngleCrater
{
    double angle;
    const Crater *c;
};

struct RingProj
{
    size_t seg_idx{0};              // segment [i -> i+1]
    double t{0.0};                  // param on segment, [0,1]
    double s{0.0};                  // arc-length along ring at foot point
    double dist{0.0};               // Euclidean distance from robot to foot
    double signed_off{0.0};         // signed lateral offset: how far left (+) or right (−) the robot is relative to the CCW tangent
    geometry_msgs::msg::Point foot; // foot point on ring
    double tangent_yaw{0.0};        // CCW tangent yaw at foot
};

struct NodeState
{
    double x{0.0}, y{0.0}, yaw{0.0};
    double s_on_ring{0.0}; // from projectOntoRing
    double g{0.0}, h{0.0};
    int parent{-1};
    double last_df{0.0}, last_dr{0.0};
};

struct Succ
{
    NodeState state;
    double incremental_cost{0.0};
};

struct OpenRec
{
    NodeState st;
    double f;
    int idx;
};

struct KeyHash
{
    std::size_t operator()(const std::tuple<int, int, int> &k) const noexcept
    {
        auto [ix, iy, iyaw] = k;
        return std::hash<int>()((ix * 73856093) ^ (iy * 19349663) ^ (iyaw * 83492791));
    }
};

namespace navigation
{
    class AStarPlanner : public rclcpp::Node
    {
    public:
        AStarPlanner();
        ~AStarPlanner();

        geometry_msgs::msg::Quaternion yawToQuat(double yaw) const
        {
            tf2::Quaternion q;
            q.setRPY(0, 0, yaw);
            return tf2::toMsg(q);
        }

        static inline double clamp(double v, double low, double high)
        {
            return std::max(low, std::min(high, v));
        }

        static inline double angleWrap(double a)
        {
            while (a <= -M_PI)
                a += 2 * M_PI;

            while (a > M_PI)
                a -= 2 * M_PI;

            return a;
        }

        static inline double sqr(double a)
        {
            return a * a;
        }

    private:
        double crater_threshold_ = 0.5;

        rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr map_sub_;
        rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr centroids_sub_;
        rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr diameters_sub_;
        rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr goal_pose_sub_;

        rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr ring_path_pub_;
        rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr planner_viz_pub_;
        rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr planned_path_pub_;
        rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr start_goal_markers_pub_;

        rclcpp::TimerBase::SharedPtr timer_;

        nav_msgs::msg::OccupancyGrid map_;
        bool map_loaded_ = false;

        bool got_start_pose_{false};

        std::vector<geometry_msgs::msg::Point> crater_centroids_;
        std::vector<float> crater_diameters_;
        std::vector<Crater> craters_;
        bool craters_loaded_ = false;

        std::vector<geometry_msgs::msg::PoseStamped> ring_pts_;
        std::vector<double> cumulative_arc_lengths_;
        double ring_total_length_ = 0.0;
        geometry_msgs::msg::Point ring_centroid_;
        bool ring_ready_ = false;

        double ring_bias_k_ = 2.0;
        double align_k_ = 0.2;

        double wheelbase_ = 0.7;
        double step_length_ = 0.5;
        double max_steer_front_ = 25.0 * M_PI / 180.0;
        double max_steer_rear_ = 25.0 * M_PI / 180.0;
        std::array<double, 5> steer_scale_{0.0, 0.5, -0.5, 0.4, -0.4};

        int occupancy_threshold_ = 200;
        double obstacle_weight_ = 5.0;
        double sample_ds_ = 0.1;

        double start_x_{0.0}, start_y_{0.0}, start_yaw_{0.0};
        double goal_x_{17.6808}, goal_y_{9.62737}, goal_yaw_{22.4871154};
        double goal_ccw_advance_{8.0};
        double goal_s_tolerance_{0.5};
        double xy_tolerance_{0.3};
        double yaw_tolerance_{15.0 * M_PI / 180.0};
        int max_expansions_{5000};

        std::vector<NodeState> sub_goals_;
        nav_msgs::msg::Path final_planned_path_;

        double weight_data_{0.0}, weight_smooth_{0.0};

        void loadParams();
        void mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr map_msg);
        void craterCentroidsCallback(const geometry_msgs::msg::PoseArray::SharedPtr centroids_msg);
        void craterDiametersCallback(const std_msgs::msg::Float32MultiArray::SharedPtr diameters_msg);
        void goalPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr start_msg);
        void fuseCraters();
        void runPlanner();
        std::vector<geometry_msgs::msg::PoseStamped> buildRingCCW(const std::vector<Crater> &gradable);
        void publishRingPath(const std::vector<geometry_msgs::msg::PoseStamped> &points);
        void publishCraterDebug(const std::vector<Crater> &gradable, const std::vector<Crater> &obstacles);
        void publishStartGoalMarkers(const NodeState &start, const NodeState &goal);
        geometry_msgs::msg::Point evalCatmullRom(double t, const geometry_msgs::msg::Point &p0, const geometry_msgs::msg::Point &p1, const geometry_msgs::msg::Point &p2, const geometry_msgs::msg::Point &p3) const;
        geometry_msgs::msg::Point evalCatmullRomDerivative(double t, const geometry_msgs::msg::Point &p0, const geometry_msgs::msg::Point &p1, const geometry_msgs::msg::Point &p2, const geometry_msgs::msg::Point &p3) const;
        std::tuple<geometry_msgs::msg::Point, geometry_msgs::msg::Point, geometry_msgs::msg::Point, geometry_msgs::msg::Point> getSplineControlPoints(size_t i) const;
        std::pair<size_t, double> sToSegmentT(double s) const;
        geometry_msgs::msg::PoseStamped getPoseAtS(double s) const;

        void updateRingCache(const std::vector<geometry_msgs::msg::PoseStamped> &pts);
        RingProj projectOntoRing(double x, double y) const;
        double ringBiasCost(double signed_off) const;
        double alignCost(double yaw_err) const;
        double tangentYawAtS(double s) const;
        double forwardProgressDelta(double s_prev, double s_next) const; // CCW positive

        std::vector<Succ> generateSuccessors4WS(const NodeState &cur) const;
        double heuristic(const NodeState &from, const NodeState &goal) const;

        bool worldToMap(double wx, double wy, int &mx, int &my) const;
        int occAt(int mx, int my) const;
        double obstacleCostAlongPrimitive(const NodeState &from, double kappa, double length) const;

        bool goalReached(const NodeState &st, const NodeState &goal) const;
        std::tuple<int, int, int> discKey(const NodeState &s) const;
        int discYaw(double yaw) const;
        std::vector<NodeState> runLatticeAStar(const NodeState &start, const NodeState &goal);
        void publishPlannedPath(const std::vector<NodeState> &nodes, int goal_idx);
        void generateSubGoals();
        NodeState getInitialStartState() const;
        geometry_msgs::msg::PoseStamped nodeToPoseStamped(const NodeState &node) const;
        NodeState nodeFromPose(const geometry_msgs::msg::PoseStamped &ps) const;
        visualization_msgs::msg::Marker make_sphere(int id, double x, double y, float r, float g, float b) const;
        visualization_msgs::msg::Marker make_arrow(int id, double x, double y, double yaw, float r, float g, float b) const;
        void smoothPath(nav_msgs::msg::Path &path, double weight_smooth, double weight_data) const;
    };
}

#endif // GLOBAL_PLANNER_HPP