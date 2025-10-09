#include <rclcpp/rclcpp.hpp>
#include "navigation/local_controller_node.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<navigation::AStarPlanner>();
    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
