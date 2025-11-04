#include "skycam/skycam.hpp"

int main(int argc, char** argv){
	rclcpp::init(argc, argv);

	// Initialize node
	auto node = std::make_shared<lr::skycam::SkycamNode>();

	rclcpp::spin(node);

	rclcpp::shutdown();

	return 0;
}
