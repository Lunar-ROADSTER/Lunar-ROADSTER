#include "perception/robot_pose_extractor.hpp"
#include "perception/srv/pose_extract.hpp"

namespace lr
{

    namespace perception
    {

        PoseExtractor::PoseExtractor(const rclcpp::Node::SharedPtr &node)
            : GoalPlanner(),
              tf_buffer_(node->get_clock()),
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
            // Nothing else yet; TF buffer and listener are initialized
        }

        void PoseExtractor::makeGoalsfromCraterGeometry(std::vector<lr_msgs::msg::Pose2D> &goalPoses, std::vector<std::string> &goalPose_types, std::vector<float> &craterCentroid, float &craterDiameter)
        {
            // Get current rover pose
            geometry_msgs::msg::PoseStamped rover_pose = getRoverPose("map", "base_link");

            // Calculate manipulation distance
            float manipulation_distance = (craterDiameter / 2) + manipulation_offset_;

            // Find angle of approach to the crater (yaw)
            double yaw = static_cast<double>(atan2((craterCentroid[1] - rover_pose.pose.position.y), (craterCentroid[0] - rover_pose.pose.position.x)));

            // Set up source pose
            double source_pose_x = craterCentroid[0] - (manipulation_distance + robot_half_length_) * std::cos(yaw);
            double source_pose_y = craterCentroid[1] - (manipulation_distance + robot_half_length_) * std::sin(yaw);
            lr_msgs::msg::Pose2D source_pose = lr::perception::create_pose2d(source_pose_x, source_pose_y, yaw);

            // Set up sink pose
            double sink_pose_x = craterCentroid[0];
            double sink_pose_y = craterCentroid[1];
            lr_msgs::msg::Pose2D sink_pose = lr::perception::create_pose2d(sink_pose_x, sink_pose_y, yaw);

            // Set up backblading source pose
            double backblading_pose_x = sink_pose.pt.x + (manipulation_distance + robot_half_length_) * std::cos(yaw);
            double backblading_pose_y = sink_pose.pt.y + (manipulation_distance + robot_half_length_) * std::sin(yaw);
            lr_msgs::msg::Pose2D source_pose_backblading = lr::perception::create_pose2d(backblading_pose_x, backblading_pose_y, yaw);

            // Set up last offset pose
            double last_offset_pose_x = backblading_pose_x - (manipulation_distance + robot_half_length_) * std::cos(yaw) * backblading_multipler_;
            double last_offset_pose_y = backblading_pose_y - (manipulation_distance + robot_half_length_) * std::sin(yaw) * backblading_multipler_;
            lr_msgs::msg::Pose2D last_offset_pose = lr::perception::create_pose2d(last_offset_pose_x, last_offset_pose_y, yaw);

            if (offset_pose_x > boundary_max_ ||
                offset_pose_x < boundary_min_ ||
                offset_pose_y > boundary_max_ ||
                offset_pose_y < boundary_min_)
            {

                while (offset_pose_x > boundary_max_ ||
                       offset_pose_x < boundary_min_ ||
                       offset_pose_y > boundary_max_ ||
                       offset_pose_y < boundary_min_)
                {

                    last_pose_offset_constrained -= boundary_increment_;
                    if (last_pose_offset_constrained <= 0.0f)
                    {
                        offset_pose_x = source_pose.pt.x;
                        offset_pose_y = source_pose.pt.y;
                        break;
                    }
                    offset_pose_x = source_pose.pt.x - last_pose_offset_constrained * std::cos(yaw);
                    offset_pose_y = source_pose.pt.y - last_pose_offset_constrained * std::sin(yaw);
                }
            }

            // Push back the goal poses
            goalPoses.push_back(source_pose);
            goalPoses.push_back(sink_pose);
            goalPoses.push_back(backblading_pose);
            goalPoses.push_back(last_offset_pose);
            goalPose_types.push_back("source");
            goalPose_types.push_back("sink");
            goalPose_types.push_back("source");
            goalPose_types.push_back("sink");
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

    auto service = node->create_service<::perception::srv::PoseExtract>(
        "generate_crater_goals",
        [pose_extractor](
            const std::shared_ptr<::perception::srv::PoseExtract::Request> request,
            std::shared_ptr<::perception::srv::PoseExtract::Response> response)
        {
            std::vector<lr_msgs::msg::Pose2D> goal_poses;
            std::vector<std::string> goal_types;
            std::vector<float> crater_centroid{
                request->centroid.x,
                request->centroid.y,
                request->centroid.z};

            float diameter = request->diameter;

            pose_extractor->makeGoalsfromCraterGeometry(goal_poses, goal_types, crater_centroid, diameter);

            response->goal_poses = goal_poses;
            response->goal_types = goal_types;
            response->success = !goal_poses.empty();
            response->message = "Generated " + std::to_string(goal_poses.size()) + " goal poses.";
        });

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
