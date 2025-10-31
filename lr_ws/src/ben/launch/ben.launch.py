from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():

    ben_params = os.path.join(
        get_package_share_directory('ben'),
        'config',
        'ben_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='ben',
            executable='ben_node',
            name='ben_node',
            parameters=[ben_params]
        ),
    ])
