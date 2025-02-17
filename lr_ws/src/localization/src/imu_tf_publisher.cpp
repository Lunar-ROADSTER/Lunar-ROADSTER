#include "localization/imu_tf_publisher.hpp"

namespace cg
{
    namespace imu_rlts
    {
        ImuTfPublisher::ImuTfPublisher() : Node("imu_tf_publisher")
        {

            /* Publishers and Subscribers*/
            imu_subscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
                "/imu/data/base_link", 10, std::binf(&ImuTfPublisher::imuCallback, this, std::placeholders::_1));

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
            transformStamped.header.child_frame_id = base_link_frame;

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
            visualization_msgs::msg::Marker marker;

            marker.header.frame_id = base_link_frame;
            marker.header.stamp = this->get_clock()->now();
            marker.ns = "imu_orientation";
            marker.id = 0;
            marker.type = visualization_msgs::msg::Marker::ARROW;
            marker.action = visualization_msgs::msg::Marker::ADD;

            marker.pose.orientation = msg->orientation;

            // Set scale for visualization
            marker.scale.x = 0.3;
            marker.scale.y = 0.05;
            marker_scale.z = 0.05;

            marker.color.r = 0.0;
            marker.color.g = 1.0;
            marker.color.b = 0.0;
            marker.color.a = 1.0;

            // Publish marker
            marker_pub_->publish(marker);
        }
    }

}

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ImuTfPublisher>());
    rclcpp::shutdown();
    return 0;
}