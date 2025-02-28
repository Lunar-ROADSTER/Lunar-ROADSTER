#include <rclcpp/rclcpp.hpp>
#include "localization/imu_tf_publisher.hpp"

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<cg::imu_rlts::ImuTfPublisher>());
    rclcpp::shutdown();
    return 0;
}