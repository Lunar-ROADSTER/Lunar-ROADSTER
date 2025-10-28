#include "navigation/global_planner_node.hpp"

namespace navigation
{
    AStarPlanner::AStarPlanner() : Node("global_astar_planner")
    {
        map_sub_ = create_subscription<nav_msgs::msg::OccupancyGrid>(
            "/map",
            10,
            std::bind(&AStarPlanner::mapCallback, this, _1));
        centroids_sub_ = create_subscription<geometry_msgs::msg::PoseArray>(
            "/crater_centroids",
            10,
            std::bind(&AStarPlanner::craterCentroidsCallback, this, _1));
        diameters_sub_ = create_subscription<std_msgs::msg::Float32MultiArray>(
            "/crater_diameters",
            10,
            std::bind(&AStarPlanner::craterDiametersCallback, this, _1));
        // goal_pose_sub_ = create_subscription<geometry_msgs::msg::PoseStamped>(
        //     "/goal_pose",
        //     10,
        //     std::bind(&AStarPlanner::goalPoseCallback, this, _1));

        ring_path_pub_ = create_publisher<nav_msgs::msg::Path>("ring_path", 1);
        planner_viz_pub_ = create_publisher<visualization_msgs::msg::MarkerArray>("crater_debug", 1);
        planned_path_pub_ = create_publisher<nav_msgs::msg::Path>("planned_path", 1);
        start_goal_markers_pub_ = create_publisher<visualization_msgs::msg::MarkerArray>("start_goal_markers", 1);
        latitude_circle_pub_ = create_publisher<visualization_msgs::msg::Marker>("latitude_circle", 1);

        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        // timer_ = create_wall_timer(
        //     std::chrono::milliseconds(200),
        //     std::bind(&AStarPlanner::runPlanner, this));
        plan_srv_ = create_service<lr_msgs::srv::PlanPath>(
            "~/plan_path",
            std::bind(&AStarPlanner::handlePlanRequest, this, std::placeholders::_1,
                      std::placeholders::_2, std::placeholders::_3));
        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        timer_ = create_wall_timer(
            std::chrono::milliseconds(200),
            std::bind(&AStarPlanner::runPlanner, this));

        loadParams();

        RCLCPP_INFO(get_logger(), "Global Planner Started ....");
    }

    AStarPlanner::~AStarPlanner()
    {
    }

    void AStarPlanner::loadParams()
    {
        declare_parameter("crater_threshold", crater_threshold_);
        declare_parameter("ring_bias_k", ring_bias_k_);
        declare_parameter("align_k", align_k_);

        declare_parameter("wheelbase", wheelbase_);
        declare_parameter("step_length", step_length_);
        declare_parameter("max_steer_front_deg", 25.0);
        declare_parameter("max_steer_rear_deg", 25.0);

        declare_parameter("occupancy_threshold", occupancy_threshold_);
        declare_parameter("obstacle_weight", obstacle_weight_);
        declare_parameter("sample_ds", sample_ds_);

        // declare_parameter("start_x", start_x_);
        // declare_parameter("start_y", start_y_);
        // declare_parameter("start_yaw_deg", 0.0);
        declare_parameter("goal_x", goal_x_);
        declare_parameter("goal_y", goal_y_);
        declare_parameter("goal_yaw_deg", goal_yaw_);
        declare_parameter("goal_ccw_advance", goal_ccw_advance_);
        declare_parameter("goal_s_tolerance", goal_s_tolerance_);
        declare_parameter("xy_tolerance", xy_tolerance_);
        declare_parameter("yaw_tolerance_deg", 15.0);
        declare_parameter("max_expansions", max_expansions_);

        declare_parameter("weight_data", weight_data_);
        declare_parameter("weight_smooth", weight_smooth_);

        get_parameter("crater_threshold", crater_threshold_);
        get_parameter("ring_bias_k", ring_bias_k_);
        get_parameter("align_k", align_k_);

        get_parameter("wheelbase", wheelbase_);
        get_parameter("step_length", step_length_);
        double fdeg, rdeg;
        get_parameter("max_steer_front_deg", fdeg);
        get_parameter("max_steer_rear_deg", rdeg);
        max_steer_front_ = fdeg * M_PI / 180.0;
        max_steer_rear_ = rdeg * M_PI / 180.0;

        get_parameter("occupancy_threshold", occupancy_threshold_);
        get_parameter("obstacle_weight", obstacle_weight_);
        get_parameter("sample_ds", sample_ds_);

        // get_parameter("start_x", start_x_);
        // get_parameter("start_y", start_y_);
        // double start_yaw_deg;
        // get_parameter("start_yaw_deg", start_yaw_deg);
        // start_yaw_ = start_yaw_deg * M_PI / 180.0;
        get_parameter("goal_x", goal_x_);
        get_parameter("goal_y", goal_y_);
        double goal_yaw_deg;
        get_parameter("goal_yaw_deg", goal_yaw_deg);
        goal_yaw_ = goal_yaw_deg * M_PI / 180.0;

        get_parameter("goal_ccw_advance", goal_ccw_advance_);
        get_parameter("goal_s_tolerance", goal_s_tolerance_);
        get_parameter("xy_tolerance", xy_tolerance_);
        double yaw_tol_deg;
        get_parameter("yaw_tolerance_deg", yaw_tol_deg);
        yaw_tolerance_ = yaw_tol_deg * M_PI / 180.0;

        get_parameter("max_expansions", max_expansions_);

        get_parameter("weight_data", weight_data_);
        get_parameter("weight_smooth", weight_smooth_);
    }

    void AStarPlanner::mapCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr map_msg)
    {
        map_ = *map_msg;
        map_loaded_ = true;

        RCLCPP_INFO(get_logger(), "Map received: %u x %u, res=%.3f, origin=(%.2f, %.2f)",
                    map_msg->info.width, map_msg->info.height, map_msg->info.resolution,
                    map_msg->info.origin.position.x, map_msg->info.origin.position.y);
    }

    bool AStarPlanner::lookupBaseInMap(geometry_msgs::msg::PoseStamped &out)
    {
        try
        {
            auto tf = tf_buffer_->lookupTransform(
                "map", "base_link", tf2::TimePointZero, tf2::durationFromSec(0.1));

            out.header = tf.header;
            out.header.frame_id = "map";
            out.pose.position.x = tf.transform.translation.x;
            out.pose.position.y = tf.transform.translation.y;
            out.pose.position.z = tf.transform.translation.z;
            out.pose.orientation = tf.transform.rotation;
            return true;
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_WARN(get_logger(), "TF lookup map->base_link failed: %s", ex.what());
            return false;
        }
    bool AStarPlanner::lookupBaseInMap(geometry_msgs::msg::PoseStamped &out) const
    {
        try
        {
            auto tf = tf_buffer_->lookupTransform(
                "map", "base_link", tf2::TimePointZero, tf2::durationFromSec(0.1));

            out.header = tf.header;
            out.header.frame_id = "map";
            out.pose.position.x = tf.transform.translation.x;
            out.pose.position.y = tf.transform.translation.y;
            out.pose.position.z = tf.transform.translation.z;
            out.pose.orientation = tf.transform.rotation;
            return true;
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_WARN(get_logger(), "TF lookup map->base_link failed: %s", ex.what());
            return false;
        }
    }

    void AStarPlanner::goalPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
        // if (start_msg->header.frame_id != "map")
        // {
        //     RCLCPP_WARN(get_logger(), "goal_pose frame_id='%s' != 'map' — assuming it's in map.",
        //                 start_msg->header.frame_id.c_str());
        // }

        // start_x_ = start_msg->pose.position.x;
        // start_y_ = start_msg->pose.position.y;

        // double yaw = tf2::getYaw(start_msg->pose.orientation);
        // start_yaw_ = angleWrap(yaw);

        // got_start_pose_ = true;

        // RCLCPP_INFO(get_logger(),
        //             "Start pose set from /goal_pose: (%.2f, %.2f, %.1f°)",
        //             start_x_, start_y_, start_yaw_ * 180.0 / M_PI);

        geometry_msgs::msg::PoseStamped in = *msg;
        geometry_msgs::msg::PoseStamped map_goal;

        if (in.header.frame_id != "map" && !in.header.frame_id.empty())
        {
            try
            {
                map_goal = tf_buffer_->transform(in, "map", tf2::durationFromSec(0.2));
            }
            catch (const tf2::TransformException &ex)
            {
                RCLCPP_WARN(get_logger(),
                            "Transforming goal %s->map failed: %s. Using as-is.",
                            in.header.frame_id.c_str(), ex.what());
                map_goal = in;
                map_goal.header.frame_id = "map";
            }
        }
        else
        {
            map_goal = in;
            map_goal.header.frame_id = "map";
        }

        goal_x_ = map_goal.pose.position.x;
        goal_y_ = map_goal.pose.position.y;
        goal_yaw_ = angleWrap(tf2::getYaw(map_goal.pose.orientation));

        got_goal_pose_ = true;

        RCLCPP_INFO(get_logger(), "Goal set from /goal_pose: (%.2f, %.2f, %.1f°)",
                    goal_x_, goal_y_, goal_yaw_ * 180.0 / M_PI);
    }

    // void AStarPlanner::goalPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    // {
    //     // if (start_msg->header.frame_id != "map")
    //     // {
    //     //     RCLCPP_WARN(get_logger(), "goal_pose frame_id='%s' != 'map' — assuming it's in map.",
    //     //                 start_msg->header.frame_id.c_str());
    //     // }

    //     // start_x_ = start_msg->pose.position.x;
    //     // start_y_ = start_msg->pose.position.y;

    //     // double yaw = tf2::getYaw(start_msg->pose.orientation);
    //     // start_yaw_ = angleWrap(yaw);

    //     // got_start_pose_ = true;

    //     // RCLCPP_INFO(get_logger(),
    //     //             "Start pose set from /goal_pose: (%.2f, %.2f, %.1f°)",
    //     //             start_x_, start_y_, start_yaw_ * 180.0 / M_PI);

    //     geometry_msgs::msg::PoseStamped in = *msg;
    //     geometry_msgs::msg::PoseStamped map_goal;

    //     if (in.header.frame_id != "map" && !in.header.frame_id.empty())
    //     {
    //         try
    //         {
    //             map_goal = tf_buffer_->transform(in, "map", tf2::durationFromSec(0.2));
    //         }
    //         catch (const tf2::TransformException &ex)
    //         {
    //             RCLCPP_WARN(get_logger(),
    //                         "Transforming goal %s->map failed: %s. Using as-is.",
    //                         in.header.frame_id.c_str(), ex.what());
    //             map_goal = in;
    //             map_goal.header.frame_id = "map";
    //         }
    //     }
    //     else
    //     {
    //         map_goal = in;
    //         map_goal.header.frame_id = "map";
    //     }

    //     goal_x_ = map_goal.pose.position.x;
    //     goal_y_ = map_goal.pose.position.y;
    //     goal_yaw_ = angleWrap(tf2::getYaw(map_goal.pose.orientation));

    //     got_goal_pose_ = true;

    //     RCLCPP_INFO(get_logger(), "Goal set from /goal_pose: (%.2f, %.2f, %.1f°)",
    //                 goal_x_, goal_y_, goal_yaw_ * 180.0 / M_PI);
    // }

    void AStarPlanner::craterCentroidsCallback(const geometry_msgs::msg::PoseArray::SharedPtr centroids_msg)
    {
        crater_centroids_.clear();
        crater_centroids_.reserve(centroids_msg->poses.size());

        for (const auto &p : centroids_msg->poses)
        {
            geometry_msgs::msg::Point pt;
            pt.x = p.position.x;
            pt.y = p.position.y;
            pt.z = 0.0;
            crater_centroids_.emplace_back(pt);
        }

        fuseCraters();
    }

    void AStarPlanner::craterDiametersCallback(const std_msgs::msg::Float32MultiArray::SharedPtr diameters_msg)
    {
        crater_diameters_.assign(diameters_msg->data.begin(), diameters_msg->data.end());

        fuseCraters();
    }

    void AStarPlanner::fuseCraters()
    {
        if (crater_centroids_.empty() || crater_diameters_.empty())
            return;

        if (crater_centroids_.size() != crater_diameters_.size())
        {
            RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 2000, "Mismatched crater centers (%zu) and diameters (%zu).",
                                 crater_centroids_.size(), crater_diameters_.size());

            return;
        }

        craters_.clear();
        craters_.reserve(crater_centroids_.size());

        for (size_t i = 0; i < crater_centroids_.size(); i++)
        {
            Crater c;
            c.x = crater_centroids_[i].x;
            c.y = crater_centroids_[i].y;
            c.diameter = static_cast<double>(crater_diameters_[i]);

            craters_.emplace_back(c);
        }

        craters_loaded_ = true;

        // RCLCPP_INFO(get_logger(), "Centroids=%zu, Diameters=%zu", crater_centroids_.size(), crater_diameters_.size());
        // RCLCPP_INFO(get_logger(), "Craters fused: %zu", craters_.size());
    }

    void AStarPlanner::handlePlanRequest(
        const std::shared_ptr<rmw_request_id_t>,
        const std::shared_ptr<lr_msgs::srv::PlanPath::Request> req,
        std::shared_ptr<lr_msgs::srv::PlanPath::Response> res)
    {
        if (!map_loaded_ || !craters_loaded_)
        {
            res->success = false;
            res->message = "Map/craters not ready yet.";
            return;
        }

        if (!req->goal.header.frame_id.empty() && req->goal.header.frame_id != "map")
        {
            RCLCPP_ERROR(get_logger(), "Plan request goal frame is '%s' but must be 'map'.",
                         req->goal.header.frame_id.c_str());
            res->success = false;
            res->message = "Goal must be in 'map' frame.";
            return;
        }

        geometry_msgs::msg::PoseStamped goal_in_map = req->goal;
        goal_in_map.header.frame_id = "map";
        if (!got_goal_pose_)
        {
            RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 2000,
                                 "No goal yet. Click a goal in RViz on /goal_pose.");
            return;
        }

        RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 2000,
                             "map_loaded=%d, craters_loaded=%d, ring_ready=%d",
                             map_loaded_, craters_loaded_, ring_ready_);

        nav_msgs::msg::Path path;
        const bool ok = planOnce(goal_in_map, path, req->smooth);

        res->success = ok;
        res->path = path;
        res->message = ok ? "OK" : "Planning failed";
    }

    bool AStarPlanner::planOnce(const geometry_msgs::msg::PoseStamped &goal_msg,
                                nav_msgs::msg::Path &out_path,
                                bool do_smooth)
    {
        std::vector<Crater> gradable, obstacles;
        gradable.reserve(craters_.size());
        obstacles.reserve(craters_.size());
        for (const auto &c : craters_)
        {
            if (c.diameter <= crater_threshold_)
                gradable.emplace_back(c);
            else
                obstacles.emplace_back(c);
        }

        publishCraterDebug(gradable, obstacles);

        if (gradable.size() < 3)
        {
            ring_ready_ = false;
            publishCraterDebug(gradable, obstacles);
            RCLCPP_WARN(get_logger(), "Need at least 3 gradable craters to build ring.");
            return false;
        }

        if (auto circle = bestFitCircleAllCraters())
        {
            auto [cx0, cy0, R0] = *circle;
            double cx = cx0, cy = cy0, R = R0;
            // refine geometrically; set huber_k>0 to downweight big outlier crater
            refineCircleGaussNewton(cx, cy, R, 15, /*huber_k=*/0.25); // tune 0.1–0.5 m as needed

            publishLatitudeCircle(cx, cy, R);

            auto st = computeDeviationStatsWeighted(final_planned_path_, cx, cy, R);
            RCLCPP_INFO(get_logger(),
                        "Circle (refined): C=(%.3f,%.3f), R=%.3f | mean=%.3f, rms=%.3f, max=%.3f, cum=%.3f, len=%.2f",
                        cx, cy, R, st.mean, st.rms, st.max, st.cumulative, st.path_length);
        }

        else
        {
            RCLCPP_WARN(get_logger(), "Latitude circle fit failed (need >=3 craters with good geometry).");
        }

        geometry_msgs::msg::PoseStamped start_ps;
        if (!lookupBaseInMap(start_ps))
        {
            RCLCPP_WARN(get_logger(), "TF (map<-base_link) not available.");
            return false;
        }
        start_x_ = start_ps.pose.position.x;
        start_y_ = start_ps.pose.position.y;
        start_yaw_ = angleWrap(tf2::getYaw(start_ps.pose.orientation));

        goal_x_ = goal_msg.pose.position.x;
        goal_y_ = goal_msg.pose.position.y;
        goal_yaw_ = angleWrap(tf2::getYaw(goal_msg.pose.orientation));

        auto viz_points = buildRingCCW(gradable);
        publishRingPath(viz_points);
        if (!ring_ready_)
        {
            return false;
        }

        generateSubGoals();

        final_planned_path_.poses.clear();
        final_planned_path_.header.stamp = now();
        final_planned_path_.header.frame_id = "map";

        NodeState current_start = getInitialStartState();
        final_planned_path_.poses.push_back(nodeToPoseStamped(current_start));

        for (const auto &sub_goal : sub_goals_)
        {
            auto seg = runLatticeAStar(current_start, sub_goal);
            if (seg.empty())
            {
                RCLCPP_ERROR(get_logger(), "Failed to plan segment to a sub-goal.");
                final_planned_path_.poses.clear();
                break;
            }
            for (size_t i = 1; i < seg.size(); ++i)
            {
                final_planned_path_.poses.push_back(nodeToPoseStamped(seg[i]));
        geometry_msgs::msg::PoseStamped base_in_map;
        if (!lookupBaseInMap(base_in_map))
        {
            RCLCPP_WARN(get_logger(), "Robot pose unavailable from TF (map->base_link) ...");
            return;
        }
        start_x_ = base_in_map.pose.position.x;
        start_y_ = base_in_map.pose.position.y;
        start_yaw_ = angleWrap(tf2::getYaw(base_in_map.pose.orientation));

        std::vector<geometry_msgs::msg::PoseStamped> viz_points = buildRingCCW(gradable);
        publishRingPath(viz_points);

        if (!ring_ready_)
        {
            got_start_pose_ = false;
            return;
        }

        generateSubGoals();

        final_planned_path_.poses.clear();
        final_planned_path_.header.stamp = now();
        final_planned_path_.header.frame_id = "map";

        NodeState current_start = getInitialStartState();
        final_planned_path_.poses.push_back(nodeToPoseStamped(current_start));

        for (const auto &sub_goal : sub_goals_)
        {
            std::vector<NodeState> path_segment = runLatticeAStar(current_start, sub_goal);

            if (path_segment.empty())
            {
                RCLCPP_ERROR(get_logger(), "Failed to plan segment to sub-goal!");
                final_planned_path_.poses.clear();
                break;
            }

            for (size_t i = 1; i < path_segment.size(); ++i)
            {
                final_planned_path_.poses.push_back(nodeToPoseStamped(path_segment[i]));
            }
            current_start = seg.back();
        }

        if (final_planned_path_.poses.empty())
        {
            return false;
        }

        if (do_smooth)
        {
            smoothPath(final_planned_path_, weight_smooth_, weight_data_);
        }

        planned_path_pub_->publish(final_planned_path_);
        out_path = final_planned_path_;

        return true;
            current_start = path_segment.back();
        }

        if (!final_planned_path_.poses.empty())
        {
            smoothPath(final_planned_path_, weight_smooth_, weight_data_);
            planned_path_pub_->publish(final_planned_path_);
        }
    }

    // void AStarPlanner::runPlanner()
    // {
    //     if (!map_loaded_ || !craters_loaded_)
    //     {
    //         RCLCPP_WARN(get_logger(), "map_loaded=%d, craters_loaded=%d, ring_ready=%d",
    //                     map_loaded_, craters_loaded_, ring_ready_);

    //         return;
    //     }

    //     if (!got_goal_pose_)
    //     {
    //         RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 2000,
    //                              "No goal yet. Click a goal in RViz on /goal_pose.");
    //         return;
    //     }

    //     RCLCPP_INFO_THROTTLE(get_logger(), *get_clock(), 2000,
    //                          "map_loaded=%d, craters_loaded=%d, ring_ready=%d",
    //                          map_loaded_, craters_loaded_, ring_ready_);

    //     std::vector<Crater> gradable, obstacles;

    //     gradable.reserve(craters_.size());
    //     obstacles.reserve(craters_.size());

    //     for (const auto &c : craters_)
    //     {
    //         if (c.diameter <= crater_threshold_)
    //             gradable.emplace_back(c);

    //         else
    //             obstacles.emplace_back(c);
    //     }

    //     if (gradable.size() < 3)
    //     {
    //         ring_ready_ = false;
    //         RCLCPP_WARN(get_logger(), "Need at least 3 gradable craters for a spline ring, have %zu.", gradable.size());
    //         publishCraterDebug(gradable, obstacles);
    //         return;
    //     }

    //     geometry_msgs::msg::PoseStamped base_in_map;
    //     if (!lookupBaseInMap(base_in_map))
    //     {
    //         RCLCPP_WARN(get_logger(), "Robot pose unavailable from TF (map->base_link) ...");
    //         return;
    //     }
    //     start_x_ = base_in_map.pose.position.x;
    //     start_y_ = base_in_map.pose.position.y;
    //     start_yaw_ = angleWrap(tf2::getYaw(base_in_map.pose.orientation));

    //     std::vector<geometry_msgs::msg::PoseStamped> viz_points = buildRingCCW(gradable);
    //     publishRingPath(viz_points);

    //     if (!ring_ready_)
    //     {
    //         got_start_pose_ = false;
    //         return;
    //     }

    //     generateSubGoals();

    //     final_planned_path_.poses.clear();
    //     final_planned_path_.header.stamp = now();
    //     final_planned_path_.header.frame_id = "map";

    //     NodeState current_start = getInitialStartState();
    //     final_planned_path_.poses.push_back(nodeToPoseStamped(current_start));

    //     for (const auto &sub_goal : sub_goals_)
    //     {
    //         std::vector<NodeState> path_segment = runLatticeAStar(current_start, sub_goal);

    //         if (path_segment.empty())
    //         {
    //             RCLCPP_ERROR(get_logger(), "Failed to plan segment to sub-goal!");
    //             final_planned_path_.poses.clear();
    //             break;
    //         }

    //         for (size_t i = 1; i < path_segment.size(); ++i)
    //         {
    //             final_planned_path_.poses.push_back(nodeToPoseStamped(path_segment[i]));
    //         }

    //         current_start = path_segment.back();
    //     }

    //     if (!final_planned_path_.poses.empty())
    //     {
    //         smoothPath(final_planned_path_, weight_smooth_, weight_data_);
    //         planned_path_pub_->publish(final_planned_path_);
    //     }
    // }

    geometry_msgs::msg::Point AStarPlanner::evalCatmullRom(double t, const geometry_msgs::msg::Point &p0, const geometry_msgs::msg::Point &p1, const geometry_msgs::msg::Point &p2, const geometry_msgs::msg::Point &p3) const
    {
        double t2 = t * t;
        double t3 = t2 * t;
        double c0 = -0.5 * t3 + t2 - 0.5 * t;
        double c1 = 1.5 * t3 - 2.5 * t2 + 1.0;
        double c2 = -1.5 * t3 + 2.0 * t2 + 0.5 * t;
        double c3 = 0.5 * t3 - 0.5 * t2;
        geometry_msgs::msg::Point out;
        out.x = c0 * p0.x + c1 * p1.x + c2 * p2.x + c3 * p3.x;
        out.y = c0 * p0.y + c1 * p1.y + c2 * p2.y + c3 * p3.y;
        return out;
    }

    geometry_msgs::msg::Point AStarPlanner::evalCatmullRomDerivative(double t, const geometry_msgs::msg::Point &p0, const geometry_msgs::msg::Point &p1, const geometry_msgs::msg::Point &p2, const geometry_msgs::msg::Point &p3) const
    {
        double t2 = t * t;
        double dc0 = -1.5 * t2 + 2.0 * t - 0.5;
        double dc1 = 4.5 * t2 - 5.0 * t;
        double dc2 = -4.5 * t2 + 4.0 * t + 0.5;
        double dc3 = 1.5 * t2 - 1.0 * t;
        geometry_msgs::msg::Point out;
        out.x = dc0 * p0.x + dc1 * p1.x + dc2 * p2.x + dc3 * p3.x;
        out.y = dc0 * p0.y + dc1 * p1.y + dc2 * p2.y + dc3 * p3.y;
        return out;
    }

    std::vector<geometry_msgs::msg::PoseStamped> AStarPlanner::buildRingCCW(const std::vector<Crater> &gradable)
    {
        double cx = 0.0, cy = 0.0;
        for (const auto &c : gradable)
        {
            cx += c.x;
            cy += c.y;
        }
        cx /= gradable.size();
        cy /= gradable.size();
        ring_centroid_.x = cx;
        ring_centroid_.y = cy;

        std::vector<AngleCrater> angs;
        angs.reserve(gradable.size());
        for (const auto &c : gradable)
        {
            angs.emplace_back(AngleCrater{std::atan2(c.y - cy, c.x - cx), &c});
        }
        std::sort(angs.begin(), angs.end(), [](const AngleCrater &a, const AngleCrater &b)
                  { return a.angle < b.angle; });

        std::vector<geometry_msgs::msg::PoseStamped> control_points;
        control_points.reserve(angs.size());
        for (const auto &ap : angs)
        {
            geometry_msgs::msg::PoseStamped ps;
            ps.header.stamp = now();
            ps.header.frame_id = "map";
            ps.pose.position.x = ap.c->x;
            ps.pose.position.y = ap.c->y;
            control_points.emplace_back(ps);
        }

        updateRingCache(control_points);
        ring_ready_ = true;

        std::vector<geometry_msgs::msg::PoseStamped> viz_pts;
        if (ring_total_length_ > 0)
        {
            for (double s = 0; s < ring_total_length_; s += 0.2)
            {
                viz_pts.push_back(getPoseAtS(s));
            }
            viz_pts.push_back(getPoseAtS(0));
        }
        return viz_pts;
    }

    std::tuple<geometry_msgs::msg::Point, geometry_msgs::msg::Point, geometry_msgs::msg::Point, geometry_msgs::msg::Point> AStarPlanner::getSplineControlPoints(size_t i) const
    {
        const size_t N = ring_pts_.size();
        const auto &p0 = ring_pts_[(i + N - 1) % N].pose.position;
        const auto &p1 = ring_pts_[i].pose.position;
        const auto &p2 = ring_pts_[(i + 1) % N].pose.position;
        const auto &p3 = ring_pts_[(i + 2) % N].pose.position;
        return {p0, p1, p2, p3};
    }

    void AStarPlanner::updateRingCache(const std::vector<geometry_msgs::msg::PoseStamped> &pts)
    {
        ring_pts_ = pts;
        if (ring_pts_.size() < 3)
            return;

        cumulative_arc_lengths_.clear();
        cumulative_arc_lengths_.reserve(ring_pts_.size() + 1);
        cumulative_arc_lengths_.push_back(0.0);

        double total_s = 0.0;
        const int samples_per_segment = 20;

        for (size_t i = 0; i < ring_pts_.size(); ++i)
        {
            auto [p0, p1, p2, p3] = getSplineControlPoints(i);
            geometry_msgs::msg::Point last_pt = p1;
            double segment_s = 0.0;
            for (int j = 1; j <= samples_per_segment; ++j)
            {
                double t = static_cast<double>(j) / samples_per_segment;
                geometry_msgs::msg::Point current_pt = evalCatmullRom(t, p0, p1, p2, p3);
                segment_s += std::hypot(current_pt.x - last_pt.x, current_pt.y - last_pt.y);
                last_pt = current_pt;
            }
            total_s += segment_s;
            cumulative_arc_lengths_.push_back(total_s);
        }
        ring_total_length_ = total_s;
    }

    std::pair<size_t, double> AStarPlanner::sToSegmentT(double s) const
    {
        if (!ring_ready_ || ring_pts_.empty() || ring_total_length_ <= 0.0)
            return {0, 0.0};

        double ss = std::fmod(s, ring_total_length_);
        if (ss < 0)
            ss += ring_total_length_;

        auto it = std::upper_bound(cumulative_arc_lengths_.begin(), cumulative_arc_lengths_.end(), ss);
        size_t idx = std::distance(cumulative_arc_lengths_.begin(), it) - 1;
        idx = std::min(idx, ring_pts_.size() - 1);

        double s_base = cumulative_arc_lengths_[idx];
        double s_seg = cumulative_arc_lengths_[idx + 1] - s_base;
        double t = (s_seg > 1e-6) ? (ss - s_base) / s_seg : 0.0;

        return {idx, t};
    }

    geometry_msgs::msg::PoseStamped AStarPlanner::getPoseAtS(double s) const
    {
        auto [seg_idx, t] = sToSegmentT(s);
        auto [p0, p1, p2, p3] = getSplineControlPoints(seg_idx);

        geometry_msgs::msg::PoseStamped ps;
        ps.header.stamp = now();
        ps.header.frame_id = "map";
        ps.pose.position = evalCatmullRom(t, p0, p1, p2, p3);

        auto deriv = evalCatmullRomDerivative(t, p0, p1, p2, p3);
        double yaw = std::atan2(deriv.y, deriv.x);
        ps.pose.orientation = yawToQuat(yaw);
        return ps;
    }

    double AStarPlanner::tangentYawAtS(double s) const
    {
        auto [seg_idx, t] = sToSegmentT(s);
        auto [p0, p1, p2, p3] = getSplineControlPoints(seg_idx);
        auto deriv = evalCatmullRomDerivative(t, p0, p1, p2, p3);
        return std::atan2(deriv.y, deriv.x);
    }

    RingProj AStarPlanner::projectOntoRing(double x, double y) const
    {
        RingProj out;
        if (!ring_ready_ || ring_pts_.size() < 3)
        {
            out.dist = std::numeric_limits<double>::infinity();
            return out;
        }

        double best_d2 = std::numeric_limits<double>::infinity();
        const int samples_per_segment = 20;

        for (size_t i = 0; i < ring_pts_.size(); ++i)
        {
            auto [p0, p1, p2, p3] = getSplineControlPoints(i);
            for (int j = 0; j <= samples_per_segment; ++j)
            {
                double t = static_cast<double>(j) / samples_per_segment;
                geometry_msgs::msg::Point pt_on_spline = evalCatmullRom(t, p0, p1, p2, p3);
                double d2 = sqr(x - pt_on_spline.x) + sqr(y - pt_on_spline.y);

                if (d2 < best_d2)
                {
                    best_d2 = d2;
                    out.seg_idx = i;
                    out.t = t;
                    out.foot = pt_on_spline;
                }
            }
        }

        out.dist = std::sqrt(best_d2);

        double s_base = cumulative_arc_lengths_[out.seg_idx];
        double s_seg_total = cumulative_arc_lengths_[out.seg_idx + 1] - s_base;
        out.s = s_base + out.t * s_seg_total;

        auto [p0, p1, p2, p3] = getSplineControlPoints(out.seg_idx);
        auto deriv = evalCatmullRomDerivative(out.t, p0, p1, p2, p3);
        out.tangent_yaw = std::atan2(deriv.y, deriv.x);

        double dx = x - out.foot.x;
        double dy = y - out.foot.y;
        double c = std::cos(out.tangent_yaw), s = std::sin(out.tangent_yaw);
        out.signed_off = -s * dx + c * dy;

        return out;
    }

    double AStarPlanner::forwardProgressDelta(double s_prev, double s_next) const
    {
        if (!ring_ready_ || ring_total_length_ <= 0.0)
            return 0.0;

        auto wrap = [&](double x)
        {
            double v = std::fmod(x, ring_total_length_);
            if (v < 0)
                v += ring_total_length_;
            return v;
        };

        double a = wrap(s_prev), b = wrap(s_next);

        double d = b - a;
        if (d < 0)
            d += ring_total_length_;

        return d;
    }

    void AStarPlanner::publishRingPath(const std::vector<geometry_msgs::msg::PoseStamped> &pts)
    {
        nav_msgs::msg::Path ring;
        ring.header.stamp = now();
        ring.header.frame_id = "map";
        ring.poses = pts;
        ring_path_pub_->publish(ring);
    }

    void AStarPlanner::publishCraterDebug(const std::vector<Crater> &gradable,
                                          const std::vector<Crater> &obstacles)
    {
        visualization_msgs::msg::MarkerArray arr;

        auto emit = [&](const std::vector<Crater> &vv, int id_base,
                        float r, float g, float b)
        {
            for (size_t i = 0; i < vv.size(); ++i)
            {
                visualization_msgs::msg::Marker m;
                m.header.frame_id = "map";
                m.header.stamp = now();
                m.ns = "craters";
                m.id = id_base + static_cast<int>(i);
                m.type = visualization_msgs::msg::Marker::SPHERE;
                m.action = visualization_msgs::msg::Marker::ADD;
                m.pose.position.x = vv[i].x;
                m.pose.position.y = vv[i].y;
                m.pose.position.z = 0.0;
                m.scale.x = vv[i].diameter;
                m.scale.y = vv[i].diameter;
                m.scale.z = 0.05;
                m.color.a = 1.0f;
                m.color.r = r;
                m.color.g = g;
                m.color.b = b;
                m.lifetime = rclcpp::Duration(0, 0);
                arr.markers.push_back(std::move(m));
            }
        };

        // Green = gradable, Red = obstacles
        emit(gradable, 0, 0.2f, 0.8f, 0.2f);
        emit(obstacles, 10000, 0.9f, 0.2f, 0.2f);

        planner_viz_pub_->publish(arr);
    }

    visualization_msgs::msg::Marker AStarPlanner::make_sphere(int id, double x, double y, float r, float g, float b) const
    {
        visualization_msgs::msg::Marker m;
        m.header.frame_id = "map";
        m.header.stamp = now();
        m.ns = "start_goal_markers";
        m.id = id;
        m.type = visualization_msgs::msg::Marker::SPHERE;
        m.action = visualization_msgs::msg::Marker::ADD;
        m.pose.position.x = x;
        m.pose.position.y = y;
        m.scale.x = m.scale.y = 0.6;
        m.scale.z = 0.1;
        m.color.a = 1.0;
        m.color.r = r;
        m.color.g = g;
        m.color.b = b;
        return m;
    }

    visualization_msgs::msg::Marker AStarPlanner::make_arrow(int id, double x, double y, double yaw, float r, float g, float b) const
    {
        visualization_msgs::msg::Marker m;
        m.header.frame_id = "map";
        m.header.stamp = now();
        m.ns = "start_goal_markers";
        m.id = id;
        m.type = visualization_msgs::msg::Marker::ARROW;
        m.action = visualization_msgs::msg::Marker::ADD;
        m.pose.position.x = x;
        m.pose.position.y = y;
        m.pose.position.z = 0.05;
        m.pose.orientation = yawToQuat(yaw);
        m.scale.x = 0.5;
        m.scale.y = 0.15;
        m.scale.z = 0.25;
        m.color.a = 1.0;
        m.color.r = r;
        m.color.g = g;
        m.color.b = b;
        return m;
    }

    void AStarPlanner::publishStartGoalMarkers(const NodeState &start, const NodeState &goal)
    {
        visualization_msgs::msg::MarkerArray arr;
        arr.markers.push_back(make_sphere(0, start.x, start.y, 0.1f, 0.5f, 1.0f));
        arr.markers.push_back(make_arrow(1, start.x, start.y, start.yaw, 0.1f, 0.5f, 1.0f));
        arr.markers.push_back(make_sphere(2, goal.x, goal.y, 1.0f, 0.2f, 1.0f));
        arr.markers.push_back(make_arrow(3, goal.x, goal.y, goal.yaw, 1.0f, 0.2f, 1.0f));
        start_goal_markers_pub_->publish(arr);
    }

    double AStarPlanner::ringBiasCost(double signed_off) const
    {
        return ring_bias_k_ * sqr(signed_off);
    }

    double AStarPlanner::alignCost(double yaw_err) const
    {
        return align_k_ * sqr(angleWrap(yaw_err));
    }

    bool AStarPlanner::worldToMap(double wx, double wy, int &mx, int &my) const
    {
        if (!map_loaded_)
            return false;

        const auto &info = map_.info;
        const double origin_x = info.origin.position.x;
        const double origin_y = info.origin.position.y;
        const double res = info.resolution;

        const double dx = wx - origin_x;
        const double dy = wy - origin_y;
        if (dx < 0.0 || dy < 0.0)
            return false;

        mx = static_cast<int>(std::floor(dx / res));
        my = static_cast<int>(std::floor(dy / res));

        if (mx < 0 || my < 0 || mx >= static_cast<int>(info.width) || my >= static_cast<int>(info.height))
            return false;

        return true;
    }

    int AStarPlanner::occAt(int mx, int my) const
    {
        const auto &info = map_.info;
        const int idx = my * static_cast<int>(info.width) + mx;
        if (idx < 0 || idx >= static_cast<int>(map_.data.size()))
            return -1;
        return map_.data[idx];
    }

    double AStarPlanner::obstacleCostAlongPrimitive(const NodeState &from, double kappa, double length) const
    {
        if (!map_loaded_)
            return 0.0;

        const int N = std::max(1, static_cast<int>(std::ceil(length / sample_ds_)));
        double x = from.x;
        double y = from.y;
        double yaw = from.yaw;

        double accum = 0.0;

        for (int i = 1; i <= N; i++)
        {
            const double ds = length / static_cast<double>(N);

            x += ds * std::cos(yaw);
            y += ds * std::sin(yaw);
            yaw = angleWrap(yaw + ds * kappa);

            int mx, my;
            if (!worldToMap(x, y, mx, my))
                return 1e6;

            const int occ = occAt(mx, my);
            if (occ < 0)
            {
                accum += 0.2;
                continue;
            }
            if (occ >= occupancy_threshold_)
            {
                return 1e6;
            }

            accum += static_cast<double>(occ) / 100.0;
        }

        return accum / static_cast<double>(N);
    }

    std::vector<Succ> AStarPlanner::generateSuccessors4WS(const NodeState &cur) const
    {
        std::vector<Succ> out;
        out.reserve(3);

        const double df[3] = {0.0, max_steer_front_, -max_steer_front_};
        const double dr[3] = {0.0, -max_steer_rear_, max_steer_rear_};

        for (int i = 0; i < 3; i++)
        {
            NodeState ns = cur;

            double tf = std::tan(df[i]);
            double tr = std::tan(dr[i]);

            double kappa = (tf - tr) / wheelbase_;

            if (std::abs(kappa) < 1e-6)
            {
                ns.x += step_length_ * std::cos(ns.yaw);
                ns.y += step_length_ * std::sin(ns.yaw);
            }
            else
            {
                double dtheta = step_length_ * kappa;
                ns.x += step_length_ * std::cos(ns.yaw);
                ns.y += step_length_ * std::sin(ns.yaw);
                ns.yaw = angleWrap(ns.yaw + dtheta);
            }

            auto proj = projectOntoRing(ns.x, ns.y);
            ns.s_on_ring = proj.s;

            double cost_len = step_length_;
            double cost_steer = sqr(df[i] - cur.last_df) + sqr(dr[i] - cur.last_dr);
            double cost_ring = ringBiasCost(proj.signed_off);
            double yaw_err = angleWrap(ns.yaw - proj.tangent_yaw);
            double cost_align = alignCost(yaw_err);
            double dccw = forwardProgressDelta(cur.s_on_ring, ns.s_on_ring);
            double cost_dir = (dccw <= 1e-3) ? 10.0 : 0.0;
            double cost_obs = obstacle_weight_ * obstacleCostAlongPrimitive(cur, kappa, step_length_);

            Succ su;
            su.state = ns;
            su.state.last_df = df[i];
            su.state.last_dr = dr[i];
            su.incremental_cost =
                cost_len +
                0.5 * cost_steer +
                cost_ring +
                cost_align +
                cost_dir +
                cost_obs;

            out.emplace_back(su);
        }

        return out;
    }

    double AStarPlanner::heuristic(const NodeState &from, const NodeState &goal) const
    {
        const double dx = goal.x - from.x;
        const double dy = goal.y - from.y;
        double h = std::hypot(dx, dy);

        auto proj = projectOntoRing(from.x, from.y);
        const double yaw_err = angleWrap(from.yaw - proj.tangent_yaw);
        h += 0.2 * std::abs(proj.signed_off) + 0.1 * std::abs(yaw_err);

        return h;
    }

    bool AStarPlanner::goalReached(const NodeState &st, const NodeState &goal) const
    {
        const double dx = st.x - goal.x;
        const double dy = st.y - goal.y;
        if (std::hypot(dx, dy) > xy_tolerance_)
            return false;

        if (std::abs(angleWrap(st.yaw - goal.yaw)) > yaw_tolerance_)
            return false;

        const double L = ring_total_length_;
        double ds = std::abs(st.s_on_ring - goal.s_on_ring);
        ds = std::min(ds, L - ds);

        return ds <= goal_s_tolerance_;
    }

    int AStarPlanner::discYaw(double yaw) const
    {
        const int bins = 16;
        double a = angleWrap(yaw);
        double t = (a + M_PI) / (2.0 * M_PI);
        int k = static_cast<int>(std::floor(t * bins));
        if (k < 0)
            k = 0;
        if (k >= bins)
            k = bins - 1;

        return k;
    }

    std::tuple<int, int, int> AStarPlanner::discKey(const NodeState &s) const
    {
        const double res = (map_loaded_ ? map_.info.resolution : 0.1);
        int ix = static_cast<int>(std::floor(s.x / res));
        int iy = static_cast<int>(std::floor(s.y / res));
        int iyaw = discYaw(s.yaw);

        return {ix, iy, iyaw};
    }

    NodeState AStarPlanner::getInitialStartState() const
    {
        NodeState start;
        start.x = start_x_;
        start.y = start_y_;
        start.yaw = start_yaw_;
        auto proj = projectOntoRing(start.x, start.y);
        start.s_on_ring = proj.s;
        return start;
    }

    geometry_msgs::msg::PoseStamped AStarPlanner::nodeToPoseStamped(const NodeState &node) const
    {
        geometry_msgs::msg::PoseStamped ps;
        ps.header.stamp = now();
        ps.header.frame_id = "map";
        ps.pose.position.x = node.x;
        ps.pose.position.y = node.y;
        ps.pose.orientation = yawToQuat(node.yaw);
        return ps;
    }

    NodeState AStarPlanner::nodeFromPose(const geometry_msgs::msg::PoseStamped &ps) const
    {
        NodeState node;
        node.x = ps.pose.position.x;
        node.y = ps.pose.position.y;
        node.yaw = tf2::getYaw(ps.pose.orientation);

        auto proj = projectOntoRing(node.x, node.y);
        node.s_on_ring = proj.s;

        return node;
    }

    void AStarPlanner::generateSubGoals()
    {
        sub_goals_.clear();

        // 1. Project the robot's start pose and the final goal pose to find their positions on the spline.
        auto start_proj = projectOntoRing(start_x_, start_y_);
        auto final_proj = projectOntoRing(goal_x_, goal_y_);

        size_t start_crater_idx = start_proj.seg_idx;
        // If the robot is already significantly past the start of the spline segment
        // (e.g., more than 10% of the way along it), it means we have "passed" the crater
        // at that index. The first crater we should target is therefore the *next* one.
        if (start_proj.t > 0.1) // 0.1 is a tunable threshold (10% of the segment length)
        {
            start_crater_idx = (start_crater_idx + 1) % ring_pts_.size();
        }
        size_t final_crater_idx = final_proj.seg_idx;

        // 2. CORRECTED LOGIC: Build the list of crater indices to visit, correctly handling wrap-around.
        std::vector<size_t> crater_indices_to_visit;
        if (ring_ready_ && !ring_pts_.empty())
        {
            size_t current_idx = start_crater_idx;
            while (true)
            {
                crater_indices_to_visit.push_back(current_idx);
                if (current_idx == final_crater_idx)
                {
                    // If the final goal is very close to the start of its segment, we might not need the next one.
                    if (final_proj.t < 0.1)
                    {
                        break;
                    }
                }
                if (crater_indices_to_visit.size() > ring_pts_.size())
                {
                    // Safety break to prevent infinite loops
                    RCLCPP_ERROR(get_logger(), "Sub-goal generation created too many points, aborting.");
                    sub_goals_.clear();
                    return;
                }
                current_idx = (current_idx + 1) % ring_pts_.size();

                // Break if we've looped all the way around and passed the goal index again
                if (current_idx == (final_crater_idx + 1) % ring_pts_.size())
                {
                    break;
                }
            }
        }

        // 3. Generate waypoints for each segment
        // First, add the center of the very first crater as the first target.
        if (!crater_indices_to_visit.empty())
        {
            double s_first_crater = cumulative_arc_lengths_[crater_indices_to_visit[0]];
            sub_goals_.push_back(nodeFromPose(getPoseAtS(s_first_crater)));
        }

        if (crater_indices_to_visit.size() > 1)
        {
            for (size_t i = 0; i < crater_indices_to_visit.size() - 1; ++i)
            {
                size_t c_idx1 = crater_indices_to_visit[i];
                size_t c_idx2 = crater_indices_to_visit[i + 1];

                double s1 = cumulative_arc_lengths_[c_idx1];
                double s2 = cumulative_arc_lengths_[c_idx2];
                if (s2 < s1)
                    s2 += ring_total_length_;

                sub_goals_.push_back(nodeFromPose(getPoseAtS(s1 + (s2 - s1) * 0.33)));
                sub_goals_.push_back(nodeFromPose(getPoseAtS(s1 + (s2 - s1) * 0.66)));

                sub_goals_.push_back(nodeFromPose(getPoseAtS(s2)));
            }
        }

        NodeState final_goal;
        final_goal.x = goal_x_;
        final_goal.y = goal_y_;
        final_goal.yaw = goal_yaw_;
        final_goal.s_on_ring = final_proj.s;

        if (!sub_goals_.empty() && std::hypot(sub_goals_.back().x - final_goal.x, sub_goals_.back().y - final_goal.y) < 1.0)
        {
            sub_goals_.back() = final_goal;
        }
        else
        {
            sub_goals_.push_back(final_goal);
        }

        visualization_msgs::msg::MarkerArray markers;
        int id = 100;
        for (const auto &goal : sub_goals_)
        {
            markers.markers.push_back(make_arrow(id++, goal.x, goal.y, goal.yaw, 1.f, 0.5f, 0.f));
        }
        start_goal_markers_pub_->publish(markers);
    }

    std::vector<NodeState> AStarPlanner::runLatticeAStar(const NodeState &start, const NodeState &goal)
    {
        publishStartGoalMarkers(start, goal);

        std::vector<NodeState> nodes;
        nodes.reserve(max_expansions_);
        nodes.push_back(start);
        nodes[0].g = 0.0;
        nodes[0].h = heuristic(start, goal);
        nodes[0].parent = -1;

        auto cmp = [](const OpenRec &a, const OpenRec &b)
        { return a.f > b.f; };
        std::priority_queue<OpenRec, std::vector<OpenRec>, decltype(cmp)> open(cmp);
        open.push(OpenRec{nodes[0], nodes[0].g + nodes[0].h, 0});

        std::unordered_map<std::tuple<int, int, int>, double, KeyHash> closed;
        closed.reserve(max_expansions_ * 2);
        closed.emplace(discKey(nodes[0]), nodes[0].g);

        int expansions = 0;
        int goal_idx = -1;

        while (!open.empty() && expansions < max_expansions_)
        {
            auto curRec = open.top();
            open.pop();
            const int idx = curRec.idx;
            const NodeState &cur = nodes[idx];

            if (goalReached(cur, goal))
            {
                goal_idx = idx;
                break;
            }

            expansions++;

            for (auto &su : generateSuccessors4WS(cur))
            {
                const auto key = discKey(su.state);
                const double g_new = cur.g + su.incremental_cost;

                auto it = closed.find(key);
                if (it != closed.end() && g_new >= it->second)
                {
                    continue;
                }

                int new_idx = nodes.size();
                nodes.push_back(su.state);
                nodes.back().g = g_new;
                nodes.back().h = heuristic(nodes.back(), goal);
                nodes.back().parent = idx;

                closed[key] = g_new;
                open.push(OpenRec{nodes.back(), g_new + nodes.back().h, new_idx});
            }
        }

        if (goal_idx >= 0)
        {
            std::vector<NodeState> path_segment;
            for (int i = goal_idx; i != -1; i = nodes[i].parent)
            {
                path_segment.push_back(nodes[i]);
            }
            std::reverse(path_segment.begin(), path_segment.end());
            return path_segment;
        }

        return {};
    }

    void AStarPlanner::smoothPath(nav_msgs::msg::Path &path, double weight_data, double weight_smooth) const
    {
        if (path.poses.size() <= 2)
        {
            return;
        }

        nav_msgs::msg::Path original_path = path;
        int iterations = 50;

        for (int i = 0; i < iterations; ++i)
        {
            for (size_t j = 1; j < path.poses.size() - 1; ++j)
            {
                double data_x = original_path.poses[j].pose.position.x;
                double data_y = original_path.poses[j].pose.position.y;

                double prev_x = path.poses[j - 1].pose.position.x;
                double prev_y = path.poses[j - 1].pose.position.y;
                double next_x = path.poses[j + 1].pose.position.x;
                double next_y = path.poses[j + 1].pose.position.y;
                double smooth_x = (prev_x + next_x) / 2.0;
                double smooth_y = (prev_y + next_y) / 2.0;

                double correction_x = weight_smooth * (smooth_x - path.poses[j].pose.position.x);
                double correction_y = weight_smooth * (smooth_y - path.poses[j].pose.position.y);

                path.poses[j].pose.position.x += weight_data * (data_x - path.poses[j].pose.position.x) + correction_x;
                path.poses[j].pose.position.y += weight_data * (data_y - path.poses[j].pose.position.y) + correction_y;
            }
        }

        for (size_t j = 1; j < path.poses.size(); ++j)
        {
            double dx = path.poses[j].pose.position.x - path.poses[j - 1].pose.position.x;
            double dy = path.poses[j].pose.position.y - path.poses[j - 1].pose.position.y;
            double yaw = std::atan2(dy, dx);
            path.poses[j - 1].pose.orientation = yawToQuat(yaw);
        }
        if (path.poses.size() > 1)
        {
            path.poses.back().pose.orientation = path.poses[path.poses.size() - 2].pose.orientation;
        }
    }

    void AStarPlanner::publishPlannedPath(const std::vector<NodeState> &nodes, int goal_idx)
    {
        nav_msgs::msg::Path path;
        path.header.frame_id = "map";
        path.header.stamp = now();

        std::vector<geometry_msgs::msg::PoseStamped> poses;
        for (int i = goal_idx; i >= 0; i = nodes[i].parent)
        {
            geometry_msgs::msg::PoseStamped ps;
            ps.header = path.header;
            ps.pose.position.x = nodes[i].x;
            ps.pose.position.y = nodes[i].y;
            ps.pose.orientation = yawToQuat(nodes[i].yaw);
            poses.push_back(ps);
        }
        std::reverse(poses.begin(), poses.end());
        path.poses = std::move(poses);

        planned_path_pub_->publish(path);
    }

    std::optional<std::tuple<double, double, double>> AStarPlanner::bestFitCircleAllCraters() const
    {
        if (craters_.size() < 3)
            return std::nullopt;

        double Sx = 0, Sy = 0, Sxx = 0, Syy = 0, Sxy = 0, Sxz = 0, Syz = 0, Sz = 0;
        size_t n = 0;
        for (const auto &c : craters_)
        {
            const double x = c.x;
            const double y = c.y;
            const double z = x * x + y * y;
            Sx += x;
            Sy += y;
            Sz += z;
            Sxx += x * x;
            Syy += y * y;
            Sxy += x * y;
            Sxz += x * z;
            Syz += y * z;
            ++n;
        }

        // Normal equations
        double M[3][3] = {
            {Sxx, Sxy, Sx},
            {Sxy, Syy, Sy},
            {Sx, Sy, static_cast<double>(n)}};
        double b[3] = {-Sxz, -Syz, -Sz};

        auto solve3 = [](double M[3][3], double b[3], double x[3]) -> bool
        {
            // Forward elimination with partial pivoting
            for (int k = 0; k < 2; ++k)
            {
                int piv = k;
                double best = fabs(M[k][k]);
                for (int r = k + 1; r < 3; ++r)
                {
                    double v = fabs(M[r][k]);
                    if (v > best)
                    {
                        best = v;
                        piv = r;
                    }
                }
                if (piv != k)
                {
                    for (int c = k; c < 3; ++c)
                        std::swap(M[k][c], M[piv][c]);
                    std::swap(b[k], b[piv]);
                }
                const double pk = M[k][k];
                if (fabs(pk) < 1e-12)
                    return false;
                for (int r = k + 1; r < 3; ++r)
                {
                    const double f = M[r][k] / pk;
                    for (int c = k; c < 3; ++c)
                        M[r][c] -= f * M[k][c];
                    b[r] -= f * b[k];
                }
            }
            // Back substitution
            for (int i = 2; i >= 0; --i)
            {
                double s = b[i];
                for (int c = i + 1; c < 3; ++c)
                    s -= M[i][c] * x[c];
                const double pii = M[i][i];
                if (fabs(pii) < 1e-12)
                    return false;
                x[i] = s / pii;
            }
            return true;
        };

        // Copy to scratch (optional; solve3 mutates its inputs)
        double MM[3][3];
        std::memcpy(MM, M, sizeof(MM));
        double bb[3];
        std::memcpy(bb, b, sizeof(bb));

        double xsol[3] = {0.0, 0.0, 0.0};
        if (!solve3(MM, bb, xsol))
            return std::nullopt;

        const double A = xsol[0];
        const double B = xsol[1];
        const double C = xsol[2];

        const double cx = -A / 2.0;
        const double cy = -B / 2.0;
        const double R2 = cx * cx + cy * cy - C;
        if (R2 <= 0.0)
            return std::nullopt;
        const double R = std::sqrt(R2);

        return std::make_tuple(cx, cy, R);
    }

    bool AStarPlanner::solve3x3(double M[3][3], double b[3], double x[3]) const
    {
        for (int k = 0; k < 2; k++)
        {
            int piv = k;
            double best = fabs(M[k][k]);
            for (int r = k + 1; r < 3; r++)
            {
                double v = fabs(M[r][k]);
                if (v > best)
                {
                    best = v;
                    piv = r;
                }
            }
            if (piv != k)
            {
                for (int c = k; c < 3; c++)
                    std::swap(M[k][c], M[piv][c]);
                std::swap(b[k], b[piv]);
            }
            const double pk = M[k][k];
            if (fabs(pk) < 1e-12)
                return false;
            for (int r = k + 1; r < 3; r++)
            {
                const double f = M[r][k] / pk;
                for (int c = k; c < 3; c++)
                    M[r][c] -= f * M[k][c];
                b[r] -= f * b[k];
            }
        }
        for (int i = 2; i >= 0; i--)
        {
            double s = b[i];
            for (int c = i + 1; c < 3; c++)
                s -= M[i][c] * x[c];
            const double pii = M[i][i];
            if (fabs(pii) < 1e-12)
                return false;
            x[i] = s / pii;
        }
        return true;
    }

    bool AStarPlanner::refineCircleGaussNewton(double &cx, double &cy, double &R,
                                               int iters, double huber_k) const
    {
        if (craters_.size() < 3)
            return false;

        for (int it = 0; it < iters; ++it)
        {
            double JTJ[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
            double JTr[3] = {0, 0, 0};
            double cost = 0.0;

            for (const auto &c : craters_)
            {
                const double dx = c.x - cx;
                const double dy = c.y - cy;
                const double ri = std::hypot(dx, dy);
                if (ri < 1e-9)
                    continue;
                double e = ri - R;

                // Huber weight (optional)
                double w = 1.0;
                if (huber_k > 0.0)
                {
                    const double a = fabs(e);
                    if (a > huber_k)
                        w = huber_k / a;
                }

                // Jacobian of e wrt [cx, cy, R]:
                // de/dcx = -(dx/ri), de/dcy = -(dy/ri), de/dR = -1
                const double j0 = -(dx / ri);
                const double j1 = -(dy / ri);
                const double j2 = -1.0;

                const double jw0 = w * j0, jw1 = w * j1, jw2 = w * j2;
                const double we = w * e;

                // Accumulate JTJ and JTr
                JTJ[0][0] += jw0 * j0;
                JTJ[0][1] += jw0 * j1;
                JTJ[0][2] += jw0 * j2;
                JTJ[1][0] += jw1 * j0;
                JTJ[1][1] += jw1 * j1;
                JTJ[1][2] += jw1 * j2;
                JTJ[2][0] += jw2 * j0;
                JTJ[2][1] += jw2 * j1;
                JTJ[2][2] += jw2 * j2;

                JTr[0] += jw0 * e;
                JTr[1] += jw1 * e;
                JTr[2] += jw2 * e;

                cost += w * e * e;
            }

            // Solve JTJ * delta = -JTr
            double A[3][3];
            double b[3];
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                    A[r][c] = JTJ[r][c];
                b[r] = -JTr[r];
            }

            double delta[3] = {0, 0, 0};
            if (!solve3x3(A, b, delta))
                break;

            cx += delta[0];
            cy += delta[1];
            R += delta[2];

            if (std::hypot(delta[0], delta[1]) < 1e-6 && fabs(delta[2]) < 1e-6)
                break;
        }
        return true;
    }

    void AStarPlanner::publishLatitudeCircle(double cx, double cy, double R)
    {
        visualization_msgs::msg::Marker m;
        m.header.frame_id = "map";
        m.header.stamp = now();
        m.ns = "latitude_circle";
        m.id = 1;
        m.type = visualization_msgs::msg::Marker::LINE_STRIP;
        m.action = visualization_msgs::msg::Marker::ADD;
        m.pose.orientation.w = 1.0;

        const int N = 256;
        m.points.clear();
        m.points.reserve(N + 1);
        for (int i = 0; i <= N; ++i)
        {
            const double th = (2.0 * M_PI * i) / N;
            geometry_msgs::msg::Point p;
            p.x = cx + R * std::cos(th);
            p.y = cy + R * std::sin(th);
            p.z = 0.02;
            m.points.push_back(p);
        }
        m.scale.x = 0.05;
        m.color.a = 1.0;
        m.color.r = 0.1f;
        m.color.g = 0.6f;
        m.color.b = 1.0f;

        latitude_circle_pub_->publish(m); // OK now
    }

    DeviationStats AStarPlanner::computeDeviationStatsWeighted(const nav_msgs::msg::Path &path,
                                                               double cx, double cy, double R) const
    {
        DeviationStats out{};
        if (path.poses.size() < 2)
            return out;

        double sum_abs_trap = 0.0; // ∑ 0.5*(|e_i|+|e_{i+1}|)*ds
        double sum_sq_trap = 0.0;  // ∑ 0.5*(e_i^2+e_{i+1}^2)*ds
        double total_len = 0.0;
        double max_abs = 0.0;
        size_t samples = 0;

        auto err = [&](double x, double y)
        {
            const double r = std::hypot(x - cx, y - cy);
            return std::fabs(r - R); // radial deviation magnitude
        };

        for (size_t i = 0; i + 1 < path.poses.size(); ++i)
        {
            const auto &p0 = path.poses[i].pose.position;
            const auto &p1 = path.poses[i + 1].pose.position;

            const double e0 = err(p0.x, p0.y);
            const double e1 = err(p1.x, p1.y);
            const double ds = std::hypot(p1.x - p0.x, p1.y - p0.y);
            if (ds <= 1e-6)
                continue;

            sum_abs_trap += 0.5 * (e0 + e1) * ds;
            sum_sq_trap += 0.5 * (e0 * e0 + e1 * e1) * ds;
            total_len += ds;
            max_abs = std::max(max_abs, std::max(e0, e1));
            samples += 2;
        }

        out.cumulative = sum_abs_trap;                                          // [meters^2] (integral of |error| along path)
        out.mean = (total_len > 0.0) ? (sum_abs_trap / total_len) : 0.0;        // [m]
        out.rms = (total_len > 0.0) ? std::sqrt(sum_sq_trap / total_len) : 0.0; // [m]
        out.max = max_abs;                                                      // [m]
        out.path_length = total_len;                                            // [m]
        out.samples = samples;
        return out;
    }

}