#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <chrono>
#include <vector>

class CraterCentroidsPublisher : public rclcpp::Node
{
public:
    CraterCentroidsPublisher() : Node("crater_centroids_publisher")
    {
        pub_ = create_publisher<geometry_msgs::msg::PoseArray>("/crater_centroids", 1);
        timer_ = create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&CraterCentroidsPublisher::publishCentroids, this));
        RCLCPP_INFO(get_logger(), "Crater Centroids Publisher started.");
    }

private:
    void publishCentroids()
    {
        // C1: (2.780,  1.466)
        // Int1: (4.697, 1.219)
        // C2: (5.588,  2.431)
        // C3: (5.353,  5.431) 
        // Int2: (4.361, 5.597)
        // C4: (3.068,  5.839)
        // Int3: (1.589, 5.378)
        // C5: (1.356,  3.806)
        const std::vector<std::pair<double, double>> centroids = {
            {2.780, 1.466},
            // {4.697, 1.219},
            {5.588, 2.431},
            {5.353, 5.431},
            // {4.361, 5.597},
            {3.068, 5.839},
            // {1.589, 5.378},
            {1.356, 3.806}};

        geometry_msgs::msg::PoseArray arr;
        arr.header.stamp = now();
        arr.header.frame_id = "map";

        for (const auto &[x, y] : centroids)
        {
            geometry_msgs::msg::Pose p;
            p.position.x = x;
            p.position.y = y;
            p.position.z = 0.0;
            p.orientation.w = 1.0;
            arr.poses.push_back(p);
        }

        pub_->publish(arr);
    }

    rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CraterCentroidsPublisher>());
    rclcpp::shutdown();
    return 0;
}
