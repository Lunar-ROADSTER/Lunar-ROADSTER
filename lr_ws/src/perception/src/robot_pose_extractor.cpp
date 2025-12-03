
/**
 * @file pose_extractor.cpp
 * @brief Generates crater-interaction goal poses (source, sink, backblade) from crater geometry and rover pose.
 *
 * This node provides the geometric processing backend for the Lunar ROADSTER crater grading system.
 * It exposes a ROS2 service that accepts a crater centroid and diameter and returns four
 * manipulation-ready goal poses for the rover:
 *
 *   1. Source Pose
 *   2. Sink Pose
 *   3. Source Backblade Pose
 *   4. Sink Backblade (Last Offset) Pose
 *
 * The node retrieves the rover’s current pose from TF, computes the crater approach direction,
 * applies configurable geometric offsets, and enforces boundary constraints to ensure safe and
 * feasible goal generation. It also publishes RViz marker visualization for debugging.
 *
 * @version 1.0.0
 * @date 2025-12-02
 *
 * Maintainer: Ankit Aggarwal 
 * Contributors: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu  
 * Team: Lunar ROADSTER
 *
 * -----------------------------------------------------------------------------
 * Subscribers:
 *   - None
 *     This node uses TF transforms instead of direct topic subscription.
 *
 * Publishers:
 *   - /goal_markers  
 *       Type: visualization_msgs::msg::MarkerArray  
 *       Publishes visualization spheres for generated poses to RViz.
 *
 * Service Servers:
 *   - /generate_crater_goals  
 *       Type: lr_msgs::srv::PoseExtract  
 *       Input: crater centroid (x,y,z) and diameter  
 *       Output: vector of Pose2D poses + type labels  
 *       Function: Core interface for generating crater manipulation poses.
 *
 * Service Clients:
 *   - None
 *
 * Action Servers / Action Clients:
 *   - None
 *
 * TF Interfaces:
 *   - Lookup: map → base_link  
 *     Used to compute rover approach direction (yaw) relative to crater position.
 *
 * Parameters:
 *   - manipulation_offset (double)
 *       Offset added to crater radius to determine source pose stand-off distance.
 *
 *   - last_pose_offset (double)
 *       Initial offset for sink backblade last pose, before constraint checks.
 *
 *   - backblading_multipler (double)
 *       Scaling factor used to compute backblading retreat distances.
 *
 *   - boundary_min, boundary_max (double)
 *       Limits for constraining the last pose within safe map boundaries.
 *
 *   - boundary_increment (double)
 *       Incremental safety margin applied when adjusting last pose.
 *
 *   - robot_half_length (double)
 *       Half of rover’s wheelbase—used for approach geometry if needed.
 *
 *   - source_pose_offset_x / source_pose_offset_y (double)
 *       Additional tunable offsets applied to source pose.
 *
 *   - sink_pose_offset_x / sink_pose_offset_y (double)
 *       Additional tunable offsets applied to sink pose.
 *
 *   - source_backblade_pose_offset_x / source_backblade_pose_offset_y (double)
 *       Offsets applied to computing the source backblade pose.
 *
 *   - sink_backblade_pose_offset_x / sink_backblade_pose_offset_y (double)
 *       Offsets applied to computing the sink backblade final pose.
 *
 * Features:
 *   - Computes yaw alignment based on rover pose.
 *   - Generates 4 crater manipulation poses with proper geometry.
 *   - Applies boundary clamping to ensure valid sink backblade poses.
 *   - Publishes RViz markers for debugging.
 *   - Fully configurable via ROS2 param server.
 *
 * @credit Core component of the Lunar ROADSTER dozing and manipulation pipeline.
 */

#include "perception/robot_pose_extractor.hpp"
#include "lr_msgs/srv/pose_extract.hpp"

namespace lr
{

    namespace perception
    {

        PoseExtractor::PoseExtractor(const rclcpp::Node::SharedPtr &node)
            : tf_buffer_(node->get_clock()),
              tf_listener_(tf_buffer_),
              clock_(node->get_clock())
        {
            node->declare_parameter<double>("manipulation_offset", static_cast<double>(manipulation_offset_));
            manipulation_offset_ = static_cast<float>(node->get_parameter("manipulation_offset").as_double());

            node->declare_parameter<double>("last_pose_offset", static_cast<double>(last_pose_offset_));
            last_pose_offset_ = static_cast<float>(node->get_parameter("last_pose_offset").as_double());

            node->declare_parameter<double>("backblading_multipler", static_cast<double>(backblading_multipler_));
            backblading_multipler_ = static_cast<float>(node->get_parameter("backblading_multipler").as_double());

            node->declare_parameter<double>("boundary_min", static_cast<double>(boundary_min_));
            boundary_min_ = static_cast<float>(node->get_parameter("boundary_min").as_double());

            node->declare_parameter<double>("boundary_max", static_cast<double>(boundary_max_));
            boundary_max_ = static_cast<float>(node->get_parameter("boundary_max").as_double());

            node->declare_parameter<double>("boundary_increment", static_cast<double>(boundary_increment_));
            boundary_increment_ = static_cast<float>(node->get_parameter("boundary_increment").as_double());

            node->declare_parameter<double>("robot_half_length", static_cast<double>(robot_half_length_));
            robot_half_length_ = static_cast<float>(node->get_parameter("robot_half_length").as_double());

            node->declare_parameter<double>("source_pose_offset_x", static_cast<double>(source_pose_offset_x_));
            source_pose_offset_x_ = static_cast<float>(node->get_parameter("source_pose_offset_x").as_double());

            node->declare_parameter<double>("source_pose_offset_y", static_cast<double>(source_pose_offset_y_));
            source_pose_offset_y_ = static_cast<float>(node->get_parameter("source_pose_offset_y").as_double());

            node->declare_parameter<double>("sink_pose_offset_x", static_cast<double>(sink_pose_offset_x_));
            sink_pose_offset_x_ = static_cast<float>(node->get_parameter("sink_pose_offset_x").as_double());

            node->declare_parameter<double>("sink_pose_offset_y", static_cast<double>(sink_pose_offset_y_));
            sink_pose_offset_y_ = static_cast<float>(node->get_parameter("sink_pose_offset_y").as_double());

            node->declare_parameter<double>("sink_backblade_pose_offset_x", static_cast<double>(sink_backblade_pose_offset_x_));
            sink_backblade_pose_offset_x_ = static_cast<float>(node->get_parameter("sink_backblade_pose_offset_x").as_double());

            node->declare_parameter<double>("sink_backblade_pose_offset_y", static_cast<double>(sink_backblade_pose_offset_y_));
            sink_backblade_pose_offset_y_ = static_cast<float>(node->get_parameter("sink_backblade_pose_offset_y").as_double());

            node->declare_parameter<double>("source_backblade_pose_offset_x", static_cast<double>(source_backblade_pose_offset_x_));
            source_backblade_pose_offset_x_ = static_cast<float>(node->get_parameter("source_backblade_pose_offset_x").as_double());

            node->declare_parameter<double>("source_backblade_pose_offset_y", static_cast<double>(source_backblade_pose_offset_y_));
            source_backblade_pose_offset_y_ = static_cast<float>(node->get_parameter("source_backblade_pose_offset_y").as_double());

            // Nothing else yet; TF buffer and listener are initialized

            // RCLCPP_INFO(this->rclcpp::get_logger(), "PoseExtractor initialized.");
            marker_pub = node->create_publisher<visualization_msgs::msg::MarkerArray>(
                "/goal_markers", 10);
        }

        void PoseExtractor::makeGoalsfromCraterGeometry(std::vector<lr_msgs::msg::Pose2D> &goalPoses, std::vector<std::string> &goalPose_types, std::vector<double> &craterCentroid, double &craterDiameter)
        {
            // Get current rover pose

            geometry_msgs::msg::PoseStamped rover_pose = getRoverPose("map", "base_link");
            // RCLCPP_INFO(this->rclcpp::get_logger(), "Obtained Rover Pose.");

            // Calculate manipulation distance
            float manipulation_distance = (craterDiameter / 2) + manipulation_offset_;

            // Find angle of approach to the crater (yaw)
            // double yaw = static_cast<double>(atan2((craterCentroid[1] - rover_pose.pose.position.y), (craterCentroid[0] - rover_pose.pose.position.x)));
            geometry_msgs::msg::Quaternion quat_msg = rover_pose.pose.orientation;

            tf2::Quaternion quat_tf;
            tf2::fromMsg(quat_msg, quat_tf);

            double yaw = tf2::getYaw(quat_tf);

            // Set up source pose
            double source_pose_x = craterCentroid[0] - (manipulation_distance + source_pose_offset_x_) * std::cos(yaw);
            double source_pose_y = craterCentroid[1] - (manipulation_distance + source_pose_offset_y_) * std::sin(yaw);
            lr_msgs::msg::Pose2D source_pose = lr::perception::create_pose2d(source_pose_x, source_pose_y, yaw);

            // Set up sink pose
            double sink_pose_x = craterCentroid[0] - sink_pose_offset_x_ * std::cos(yaw);
            double sink_pose_y = craterCentroid[1] - sink_pose_offset_y_ * std::sin(yaw);
            lr_msgs::msg::Pose2D sink_pose = lr::perception::create_pose2d(sink_pose_x, sink_pose_y, yaw);

            // Set up backblading source pose
            double backblading_pose_x = sink_pose.pt.x + (manipulation_distance - source_backblade_pose_offset_x_) * std::cos(yaw);
            double backblading_pose_y = sink_pose.pt.y + (manipulation_distance - source_backblade_pose_offset_y_) * std::sin(yaw);
            lr_msgs::msg::Pose2D source_pose_backblading = lr::perception::create_pose2d(backblading_pose_x, backblading_pose_y, yaw);

            // Set up last offset pose - sink backblade
            double last_offset_pose_x = backblading_pose_x - (manipulation_distance + sink_backblade_pose_offset_x_) * std::cos(yaw) * backblading_multipler_;
            double last_offset_pose_y = backblading_pose_y - (manipulation_distance + sink_backblade_pose_offset_y_) * std::sin(yaw) * backblading_multipler_;
            lr_msgs::msg::Pose2D last_offset_pose = lr::perception::create_pose2d(last_offset_pose_x, last_offset_pose_y, yaw);

            double last_pose_offset_constrained = last_pose_offset_;

            if (last_offset_pose_x > boundary_max_ ||
                last_offset_pose_x < boundary_min_ ||
                last_offset_pose_y > boundary_max_ ||
                last_offset_pose_y < boundary_min_)
            {

                while (last_offset_pose_x > boundary_max_ ||
                       last_offset_pose_x < boundary_min_ ||
                       last_offset_pose_y > boundary_max_ ||
                       last_offset_pose_y < boundary_min_)
                {

                    last_pose_offset_constrained -= boundary_increment_;
                    if (last_pose_offset_constrained <= 0.0f)
                    {
                        last_offset_pose_x = source_pose.pt.x;
                        last_offset_pose_y = source_pose.pt.y;
                        break;
                    }
                    last_offset_pose_x = source_pose.pt.x - last_pose_offset_constrained * std::cos(yaw);
                    last_offset_pose_y = source_pose.pt.y - last_pose_offset_constrained * std::sin(yaw);
                }
            }

            // Push back the goal poses
            goalPoses.push_back(source_pose);
            goalPoses.push_back(sink_pose);
            goalPoses.push_back(source_pose_backblading);
            goalPoses.push_back(last_offset_pose);
            goalPose_types.push_back("source");
            goalPose_types.push_back("sink");
            goalPose_types.push_back("source_backblade");
            goalPose_types.push_back("sink_backblade");

            // RCLCPP_INFO(this->rclcpp::get_logger(), "Generated %zu goal poses for crater at (%.2f, %.2f) with diameter %.2f m.",
            //              goalPoses.size(), craterCentroid[0], craterCentroid[1], craterDiameter);
        }

        // TF query for rover pose
        geometry_msgs::msg::PoseStamped PoseExtractor::getRoverPose(const std::string &target_frame, const std::string &rover_frame)
        {
            geometry_msgs::msg::PoseStamped rover_pose;

            try
            {
                // Lookup transform from target_frame -> rover_frame
                auto transformStamped = tf_buffer_.lookupTransform(
                    target_frame, rover_frame,
                    tf2::TimePointZero);

                // Fill PoseStamped
                rover_pose.header = transformStamped.header;
                rover_pose.pose.position.x = transformStamped.transform.translation.x;
                rover_pose.pose.position.y = transformStamped.transform.translation.y;
                rover_pose.pose.position.z = transformStamped.transform.translation.z;
                rover_pose.pose.orientation = transformStamped.transform.rotation;
            }
            catch (const tf2::TransformException &ex)
            {
                RCLCPP_WARN(rclcpp::get_logger("PoseExtractor"),
                            "Could not transform %s to %s: %s",
                            target_frame.c_str(), rover_frame.c_str(), ex.what());
                // Pose will be default-initialized (all zeros)
            }

            return rover_pose;
        }

    } // namespace perception

} // namespace lr

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    const auto node = rclcpp::Node::make_shared("pose_extractor");
    auto pose_extractor = std::make_shared<lr::perception::PoseExtractor>(node);

    // RCLCPP_INFO(node->get_logger(), "Pose Extractor Service is ready.");
    auto service = node->create_service<::lr_msgs::srv::PoseExtract>(
        "generate_crater_goals",
        [pose_extractor, node](
            const std::shared_ptr<::lr_msgs::srv::PoseExtract::Request> request,
            std::shared_ptr<::lr_msgs::srv::PoseExtract::Response> response)
        {
            std::vector<lr_msgs::msg::Pose2D> goal_poses;
            std::vector<std::string> goal_types;
            std::vector<double> crater_centroid{
                request->centroid.x,
                request->centroid.y,
                request->centroid.z};

            double diameter = request->diameter;

            pose_extractor->makeGoalsfromCraterGeometry(goal_poses, goal_types, crater_centroid, diameter);

            response->goal_poses = goal_poses;
            response->goal_types = goal_types;
            response->success = !goal_poses.empty();
            response->message = "Generated " + std::to_string(goal_poses.size()) + " goal poses.";
            
            visualization_msgs::msg::MarkerArray marker_array;
            for (size_t i = 0; i < goal_poses.size(); ++i)
            {
                visualization_msgs::msg::Marker marker;
                marker.header.frame_id = "map";
                marker.header.stamp = node->now();
                marker.ns = "goal_poses";
                marker.id = i;
                marker.type = visualization_msgs::msg::Marker::SPHERE;
                marker.action = visualization_msgs::msg::Marker::ADD;

                marker.pose.position.x = goal_poses[i].pt.x;
                marker.pose.position.y = goal_poses[i].pt.y;
                marker.pose.position.z = 0.0;
                marker.pose.orientation.w = 1.0;

                marker.scale.x = marker.scale.y = marker.scale.z = 0.2;
                marker.color.r = 1.0;
                marker.color.g = 0.0;
                marker.color.b = 1.0;
                marker.color.a = 1.0;

                marker_array.markers.push_back(marker);
            }
            pose_extractor->marker_pub->publish(marker_array);
        });

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
