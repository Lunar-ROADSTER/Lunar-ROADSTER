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
        // C2: (5.588,  2.431)
        // C3: (1.372,  3.803)
        // C4: (5.353,  5.431)
        // C5: (3.043,  6.126)
        const std::vector<std::pair<double, double>> centroids = {
            {2.780, 1.466},
            {5.588, 2.431},
            {1.372, 3.803},
            {5.353, 5.431},
            {3.043, 6.126}};

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
