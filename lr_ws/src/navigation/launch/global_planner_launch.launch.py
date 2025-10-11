from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('navigation')

    default_map = os.path.join(pkg_share, 'maps', 'crater_ring_map.yaml')
    default_cfg = os.path.join(pkg_share, 'config', 'global_plan_params.yaml')

    map_yaml = LaunchConfiguration('map')
    planner_yaml = LaunchConfiguration('planner_config')

    return LaunchDescription([
        DeclareLaunchArgument(
            'map',
            default_value=default_map,
            description='Full path to the map YAML file'),
        DeclareLaunchArgument(
            'planner_config',
            default_value=default_cfg,
            description='Full path to the global A* planner parameters YAML'),

        # Node(
        #     package='nav2_map_server',
        #     executable='map_server',
        #     name='map_server',
        #     output='screen',
        #     parameters=[{'yaml_filename': '/home/bhaswanth_a/Lunar-ROADSTER/lr_ws/src/navigation/maps/crater_ring_map.yaml'},
        #                 {'frame_id': 'map'}]
        # ),

        Node(
            package='navigation',
            executable='global_astar_node',   
            name='global_astar_node',
            output='screen',
            parameters=[planner_yaml]
        ),
    ])
