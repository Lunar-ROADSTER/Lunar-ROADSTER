#include "perception/robot_pose_extractor.hpp"

float manipulation_offset = 0.1 // metres

    namespace lr
{

    namespace perception
    {

        PoseExtractor::PoseExtractor(std::shared_ptr<rclcpp::Node> node)
            : GoalPlanner(),
              tf_buffer_(node->get_clock()),
              tf_listener_(tf_buffer_),
              clock_(node->get_clock())
        {
            // Nothing else yet; TF buffer and listener are initialized
        }

        void PoseExtractor::makeGoalsfromCraterGeometry(std::vector<lr_msgs::msg::Pose2D> &goalPoses, std::vector<std::string> &goalPose_types, std::vector<float> &craterCentroid, float &craterDiameter)
        {
            // Get current rover pose
            geometry_msgs::msg::PoseStamped rover_pose = getRoverPose('map', 'base_link');

            // Calculate manipulation distance
            float manipulation_distance = (craterDiameter / 2) + manipulation_offset_;

            // Find angle of approach to the crater (yaw)
            double yaw = static_cast<double>(atan2((craterCentroid[1] - rover_pose.pose.position.y), (craterCentroid[0] - rover_pose.pose.position.x)));

            // Set up source pose
            double source_pose_x = craterCentroid[0] - manipulation_distance * std::cos(yaw);
            double source_pose_y = craterCentroid[1] - manipulation_distance * std::sin(yaw);
            lr_msgs::msg::Pose2D source_pose = lr::planning::create_pose2d(source_pose_x, source_pose_y, yaw);

            // Set up sink pose
            double sink_pose_x = craterCentroid[0];
            double sink_pose_y = craterCentroid[1];
            lr_msgs::msg::Pose2D sink_pose = lr::planning::create_pose2d(sink_pose_x, sink_pose_y, yaw);

            // Set up backblading source pose
            double backblading_pose_x = sink_pose.pt.x + manipulation_distance * std::cos(yaw);
            double backblading_pose_y = sink_pose.pt.y + manipulation_distance * std::sin(yaw);
            lr_msgs::msg::Pose2D source_pose_backblading = lr::planning::create_pose2d(backblading_pose_x, backblading_pose_y, yaw);

            // Set up last offset pose
            double last_offset_pose_x = backblading_pose_x - manipulation_distance * std::cos(yaw) * backblading_multipler_;
            double last_offset_pose_y = backblading_pose_y - manipulation_distance * std::sin(yaw) * backblading_multipler_;
            lr_msgs::msg::Pose2D last_offset_pose = lr::planning::create_pose2d(last_offset_pose_x, last_offset_pose_y, yaw);

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