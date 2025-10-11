#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>
#include <vector>

class CraterDiametersPublisher : public rclcpp::Node
{
public:
    CraterDiametersPublisher() : Node("crater_diameters_publisher")
    {
        pub_ = create_publisher<std_msgs::msg::Float32MultiArray>("/crater_diameters", 1);
        timer_ = create_wall_timer(std::chrono::seconds(1),
                                   std::bind(&CraterDiametersPublisher::publishDiameters, this));
        RCLCPP_INFO(get_logger(), "Crater Diameters Publisher started.");
    }

private:
    void publishDiameters()
    {
        std::vector<double> crater_rs = {42, 28, 35, 30, 22, 40, 26, 34};
        double extra_small = 18.0;

        std_msgs::msg::Float32MultiArray msg;
        msg.data.reserve(crater_rs.size() + 1);
        for (double r_px : crater_rs)
            msg.data.push_back(2.0f * r_px * 0.05f);   

        msg.data.push_back(2.0f * extra_small * 0.05f); 
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
