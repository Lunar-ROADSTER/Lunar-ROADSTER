from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='visualization',
            executable='visualization_node',
            name='visualization_node'
        ),
        Node(
            package='visualization',
            executable='local_visualization_node',
            name='local_visualization_node'
        )
    ])
