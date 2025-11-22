from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os
import yaml

def generate_launch_description():

    # Load rtls parameters
    total_station_params =  os.path.join(
        get_package_share_directory('total_station'),
        'config',
        'total_station.yaml'
    )

    return LaunchDescription([
        Node(
            package='total_station',
            executable='total_station_node',
            name='total_station_node',
            parameters=[total_station_params]
        ),
    ])
