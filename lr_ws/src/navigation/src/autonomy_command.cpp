/**
 * @file autonomy_command.cpp
 * @brief Converts high-level /cmd_vel twists into low-level actuator commands for the Lunar ROADSTER drive system.
 *
 * This node receives velocity commands in the form of `geometry_msgs::msg::Twist` (typically from
 * teleoperation or a navigation controller) and converts them into the low-level actuator interface
 * used by the Lunar ROADSTER drivetrain. It scales linear velocity into normalized wheel velocity
 * commands and angular velocity into steering angle commands, enforcing actuator limits and publishing
 * the final `lr_msgs::msg::ActuatorCommand` message.
 *
 * The conversion uses configurable maximum linear and angular speeds to normalize values and clamp
 * actuator outputs, ensuring safe operation of the platform. This node acts as the bridge between
 * generic ROS2 control commands and the vehicle-specific actuator protocol.
 *
 * @version 1.0.0
 * @date 2025-12-02
 *
 * Maintainer: Bhaswanth Ayapilla, Simson D’Souza
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /command_vel
 *   Type: `geometry_msgs::msg::Twist`
 *   High-level linear/angular velocity commands, typically from a joystick, teleop node, or navigation stack.
 *
 * Publishers:
 * - /actuator_cmd
 *   Type: `lr_msgs::msg::ActuatorCommand`
 *   Low-level wheel velocity and steering position commands sent to the robot's drivetrain controller.
 *
 * Parameters (internal constants):
 * - max_linear_speed (double)
 *   Maximum expected linear speed (m/s). Used to scale and clamp wheel velocity commands.
 *
 * - max_steering_angle (double)
 *   Maximum expected angular speed (rad/s). Used to scale and clamp steering commands.
 *
 * Features:
 * - Converts generic /cmd_vel to platform-specific actuator values.
 * - Normalizes and clamps velocities to actuator safe ranges.
 * - Publishes actuator-friendly commands at the incoming /cmd_vel rate.
 * - Provides logging for debugging actuator outputs.
 *
 * @credit Part of the drive subsystem interface for the Lunar ROADSTER autonomous rover.
 **/

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <lr_msgs/msg/actuator_command.hpp>

class CmdVelToActuator : public rclcpp::Node
{
public:
    CmdVelToActuator() : Node("cmd_vel_to_actuator"), max_linear_speed(0.5), max_steering_angle(0.5)
    {
        subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/command_vel", 10, std::bind(&CmdVelToActuator::cmd_vel_callback, this, std::placeholders::_1));
        publisher_ = this->create_publisher<lr_msgs::msg::ActuatorCommand>("/actuator_cmd", 10);
    }

private:
    void cmd_vel_callback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {
        auto actuator_msg = lr_msgs::msg::ActuatorCommand();
        actuator_msg.header.stamp = this->get_clock()->now();

        // Convert linear velocity to wheel velocity
        actuator_msg.wheel_velocity = (msg->linear.x / max_linear_speed) * 100.0;
        actuator_msg.wheel_velocity = std::clamp(actuator_msg.wheel_velocity, -65.0, 65.0);

        // Convert angular velocity to steer position
        actuator_msg.steer_position = (msg->angular.z / max_steering_angle) * 100.0;
        actuator_msg.steer_position = std::clamp(actuator_msg.steer_position, -60.0, 60.0);

        // actuator_msg.tool_position = 100.0;

        // Publish the message
        publisher_->publish(actuator_msg);
        RCLCPP_INFO(this->get_logger(), "Published ActuatorCommand: wheel_velocity=%.2f, steer_position=%.2f, tool_position=%.2f",
                    actuator_msg.wheel_velocity, actuator_msg.steer_position, actuator_msg.tool_position);
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    rclcpp::Publisher<lr_msgs::msg::ActuatorCommand>::SharedPtr publisher_;

    const double max_linear_speed;
    const double max_steering_angle;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CmdVelToActuator>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}