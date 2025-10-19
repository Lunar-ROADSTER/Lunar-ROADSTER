from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():

    ceiltrack_params = os.path.join(
        get_package_share_directory('ceiltrack'),
        'config',
        'ceiltrack_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='ceiltrack',
            executable='ceiltrack_node',
            name='ceiltrack_node',
            parameters=[ceiltrack_params]
        ),
    ])
