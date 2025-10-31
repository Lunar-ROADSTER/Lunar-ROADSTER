from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('navigation')

    default_map = os.path.join(pkg_share, 'maps', 'global_costmap.yaml')
    default_cfg = os.path.join(pkg_share, 'config', 'global_plan_params.yaml')

    map_yaml = LaunchConfiguration('map')
    planner_yaml = LaunchConfiguration('planner_config')

    return LaunchDescription([
        DeclareLaunchArgument(
            'map',
            default_value=default_map,
            description='Path to map metadata YAML (contains image/resolution/origin...)'
        ),
        DeclareLaunchArgument(
            'planner_config',
            default_value=default_cfg,
            description='Path to global A* planner params YAML'
        ),

        Node(
            package='nav2_map_server',
            executable='map_server',
            name='map_server',
            output='screen',
            parameters=[{'yaml_filename': map_yaml}, {'frame_id': 'map'}]
        ),
        Node(
            package='nav2_lifecycle_manager',
            executable='lifecycle_manager',
            name='lifecycle_manager_map_server',
            output='screen',
            parameters=[{'autostart': True, 'node_names': ['map_server']}]
        ),

        Node(
            package='navigation',
            executable='global_astar_node',
            name='global_astar_node',
            output='screen',
            parameters=[planner_yaml]
        ),
    ])
