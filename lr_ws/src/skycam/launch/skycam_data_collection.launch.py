from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():

    skycam_data_collection_params = os.path.join(
        get_package_share_directory('skycam'),
        'config',
        'skycam_data_collection_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='skycam',
            executable='skycam_data_collection_node',
            name='skycam_data_collection_node',
            parameters=[skycam_data_collection_params]
        ),
    ])
