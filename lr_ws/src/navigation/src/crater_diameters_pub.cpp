/**
 * @file crater_diameters_publisher.cpp
 * @brief Publishes fixed crater diameter measurements as a Float32MultiArray for testing crater-aware navigation.
 *
 * This node periodically publishes a predefined list of crater diameters to the "/crater_diameters" topic.
 * These diameters correspond to crater sizes in meters and are aligned with the ordering of crater centroids
 * published elsewhere in the system. The data provides synthetic crater size measurements for debugging,
 * visualization, and planner testing within the Lunar ROADSTER autonomy stack.
 *
 * The diameters are hard-coded and published at 1 Hz as a std_msgs::msg::Float32MultiArray message.
 *
 * @version 1.0.0
 * @date 2025-12-02
 *
 * Maintainer: Bhaswanth Ayapilla
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla,
 *               Simson D’Souza, Boxiang (William) Fu
 *
 * Publishers:
 * - /crater_diameters
 *     std_msgs::msg::Float32MultiArray
 *     Ordered crater diameters (meters) corresponding to the published crater centroids.
 *
 * Parameters:
 * - (none)
 *     All crater diameter values are currently hard-coded into the source.
 *
 * Features:
 * - Publishes a vector of crater diameters at a fixed rate (1 Hz).
 * - Provides synthetic crater size information for integration testing and debugging.
 * - Ensures consistent ordering aligned with crater centroid publishing.
 *
 * @credit Utility tool for crater-based path planning and grading experiments
 *         in the Lunar ROADSTER autonomy system.
 */

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <chrono>
#include <vector>

class CraterDiametersPublisher : public rclcpp::Node
{
public:
    CraterDiametersPublisher() : Node("crater_diameters_publisher")
    {
        pub_ = create_publisher<std_msgs::msg::Float32MultiArray>("/crater_diameters", 1);
        timer_ = create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&CraterDiametersPublisher::publishDiameters, this));
        RCLCPP_INFO(get_logger(), "Crater Diameters Publisher started.");
    }

private:
    void publishDiameters()
    {
        // Match order of centroids: C1, C2, C3, C5
        // C1: 0.340 m, C2: 0.320 m, C3: 0.400 m, C5: 0.280 m
        const std::vector<float> diameters_m = {0.340f, 0.320f, 1.000f, 0.280f, 0.400f};

        std_msgs::msg::Float32MultiArray msg;
        msg.data = diameters_m;
        pub_->publish(msg);
    }

    rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CraterDiametersPublisher>());
    rclcpp::shutdown();
    return 0;
}
