#include "ben/ben.hpp"

int main(int argc, char** argv){
	
	// Use multithreaded executor for service call in timer callback: https://docs.ros.org/en/galactic/How-To-Guides/Using-callback-groups.html
	rclcpp::init(argc, argv);

	// Initialize node
	auto node = std::make_shared<lr::ben::BenNode>();
	rclcpp::executors::MultiThreadedExecutor executor;
	executor.add_node(node);
	executor.spin();

	rclcpp::shutdown();
	return 0;
}