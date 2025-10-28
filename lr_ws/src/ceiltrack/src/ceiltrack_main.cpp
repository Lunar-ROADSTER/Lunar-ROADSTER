#include "ceiltrack/ceiltrack.hpp"

int main(int argc, char** argv){
	rclcpp::init(argc, argv);

	// Initialize node
	auto node = std::make_shared<lr::ceiltrack::CeiltrackNode>();

	rclcpp::spin(node);

	rclcpp::shutdown();

	return 0;
}
