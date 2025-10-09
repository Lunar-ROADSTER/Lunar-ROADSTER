from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    global_controller_yaml = ''
    local_controller_yaml = ''
    map_file = ''
        
    return LaunchDescription([

        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[
                {'yaml_filename': map_file},
                {'frame_id': 'map'}
            ]
        ),
        
        Node(
            package='navigation',
            executable='astar_planner',
            name='astar_planner',
            output='screen'
        ),
        
        Node(
            package='navigation',
            executable='local_controller_node',
            name='local_controller_node',
            parameters=[local_controller_yaml],
            output='screen'
        )
    ])
