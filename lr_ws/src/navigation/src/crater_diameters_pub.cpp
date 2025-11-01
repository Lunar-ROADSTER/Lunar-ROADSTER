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
