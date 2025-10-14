from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():

    validation_params = os.path.join(
        get_package_share_directory('validation'),
        'config',
        'validation_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='validation',
            executable='validation_node',
            name='validation_node',
            parameters=[validation_params]
        ),
    ])
