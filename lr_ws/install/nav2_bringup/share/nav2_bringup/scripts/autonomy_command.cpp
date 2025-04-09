#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <cg_msgs/msg/actuator_command.hpp> 

class CmdVelToActuator : public rclcpp::Node {
public:
    CmdVelToActuator() : Node("cmd_vel_to_actuator"), max_linear_speed(0.5), max_steering_angle(0.5) {
        subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/cmd_vel", 10, std::bind(&CmdVelToActuator::cmd_vel_callback, this, std::placeholders::_1));
        publisher_ = this->create_publisher<cg_msgs::msg::ActuatorCommand>("/actuator_cmd", 10);
    }

private:
    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg) {
        auto actuator_msg = cg_msgs::msg::ActuatorCommand();
        actuator_msg.header.stamp = this->get_clock()->now();
        
        // Convert linear velocity to wheel velocity
        actuator_msg.wheel_velocity = (msg->linear.x / max_linear_speed) * 100.0;
        actuator_msg.wheel_velocity = std::clamp(actuator_msg.wheel_velocity, -15.0, 15.0);
        
        // Convert angular velocity to steer position
        actuator_msg.steer_position = -(msg->angular.z / max_steering_angle) * 100.0;
        actuator_msg.steer_position = std::clamp(actuator_msg.steer_position, -100.0, 100.0);
        
        // Publish the message
        publisher_->publish(actuator_msg);
        RCLCPP_INFO(this->get_logger(), "Published ActuatorCommand: wheel_velocity=%.2f, steer_position=%.2f",
                    actuator_msg.wheel_velocity, actuator_msg.steer_position);
    }
    
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    rclcpp::Publisher<cg_msgs::msg::ActuatorCommand>::SharedPtr publisher_;
    
    const double max_linear_speed;
    const double max_steering_angle;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CmdVelToActuator>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
