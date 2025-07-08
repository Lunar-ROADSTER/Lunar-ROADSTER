/**
 * @file imu_tf_publisher.cpp
 * @brief Publishes a static transform between base_link and IMU, and visualizes IMU orientation in RViz.
 *
 * This node subscribes to IMU data and continuously publishes a transform from the `base_link` to the `imu_link`
 * based on the orientation received in the IMU message. It assumes a fixed translation (zero offset), and publishes
 * a visualization marker (green arrow) in RViz for real-time orientation feedback.
 *
 * This node is useful for debugging IMU alignment and integrating orientation data into a TF tree.
 *
 * @version 1.0.0
 * @date 2025-07-07
 *
 * Maintainer: Bhaswanth Ayapilla, Boxiang (William) Fu
 * Team: Lunar ROADSTER 
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /imu/data/base_link: [sensor_msgs::msg::Imu] Incoming IMU data containing orientation for the base_link frame.
 *
 * Publishers:
 * - /imu_orientation_marker: [visualization_msgs::msg::Marker] RViz marker showing orientation from IMU.
 * - TF: [geometry_msgs::msg::TransformStamped] Broadcasts a transform from base_link to imu_link using orientation from IMU.
 *
 * Services:
 * - None
 *
 * Parameters:
 * - None (uses hardcoded frame names: "base_link" and "imu_link")
 *
 * @credit Inspired by standard IMU TF and RViz marker publishers in ROS2.
 */


#include "localization/imu_tf_publisher.hpp"

namespace lr
{
    namespace imu_rlts
    {
        ImuTfPublisher::ImuTfPublisher() : Node("imu_tf_publisher")
        {

            /* Publishers and Subscribers*/
            imu_subscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
                "/imu/data/base_link", 10, std::bind(&ImuTfPublisher::imuCallback, this, std::placeholders::_1));

            marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>(
                "/imu_orientation_marker", 10);

            // Tf Broadcaster
            tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);
        }


        void ImuTfPublisher::imuCallback(const sensor_msgs::msg::Imu::SharedPtr imu_msg)
        {
            geometry_msgs::msg::TransformStamped transformStamped;

            // Set Tf Header
            transformStamped.header.stamp = this->get_clock()->now();
            transformStamped.header.frame_id = base_link_frame;
            transformStamped.child_frame_id = imu_frame;

            // Imu frame is fixed to base link frame
            transformStamped.transform.translation.x = 0.0;
            transformStamped.transform.translation.y = 0.0;
            transformStamped.transform.translation.z = 0.0;

            // Set orientation from Imu
            transformStamped.transform.rotation = imu_msg->orientation;

            // Broadcast transform
            tf_broadcaster_->sendTransform(transformStamped);

            // Publish to visualize
            publishImuMarker(imu_msg);

        }


        void ImuTfPublisher::publishImuMarker(const sensor_msgs::msg::Imu::SharedPtr msg)
        {
            marker.header.frame_id = imu_frame;
            marker.header.stamp = this->get_clock()->now();
            marker.ns = "imu_orientation";
            marker.id = 0;
            marker.type = visualization_msgs::msg::Marker::ARROW;
            marker.action = visualization_msgs::msg::Marker::ADD;

            marker.pose.orientation = msg->orientation;

            // Set scale for visualization
            marker.scale.x = 0.3;
            marker.scale.y = 0.05;
            marker.scale.z = 0.05;

            marker.color.r = 0.0;
            marker.color.g = 1.0;
            marker.color.b = 0.0;
            marker.color.a = 1.0;

            // Publish marker
            marker_pub_->publish(marker);
        }
    }

}