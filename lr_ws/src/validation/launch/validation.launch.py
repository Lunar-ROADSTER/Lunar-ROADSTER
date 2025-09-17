from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='validation',
            executable='validation_node',
            name='validation_node'
        ),
    ])
