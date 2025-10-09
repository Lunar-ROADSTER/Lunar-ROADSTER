#include "global_controller/global_planner_controller.hpp"
#include <rclcpp/rclcpp.hpp>

/**
 * @brief Main entry point for the global_planner_controller node.
 * @param argc
 * @param argv
 * @return 0 on successful execution.
 */
int main(int argc, char * argv[])
{
    // Initialize ROS2
    rclcpp::init(argc, argv);

    rclcpp::NodeOptions options;

    // Create the GlobalPlannerController node using the new namespace
    auto node = std::make_shared<lr_global_planner_controller::GlobalPlannerController>(options);

    rclcpp::spin(node);

    rclcpp::shutdown();
    
    return 0;
}

