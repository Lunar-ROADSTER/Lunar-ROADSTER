from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
import os

def generate_launch_description():

    sensing_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('sensing'), 'launch/sensing_launch.py')
        )
    )

    mapping_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('mapping'), 'launch/mapping.launch.py')
        )
    )

    mapping_static_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('mapping_static'), 'launch/mapping.launch.py')
        )
    )

    visualization_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('visualization'), 'launch/visualization.launch.py')
        )
    )

    motion_control_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('motion_control'), 'launch/motion_control_launch.py')
        )
    )

    vectornav_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('vectornav'), 'launch/vectornav.launch.py')
        )
    )

    imu_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('imu'), 'launch/imu_launch.py')
        )
    )

    localization_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('localization'), 'launch/ekf_localization.launch.py')
        )
    )

    planning_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('planning'), 'launch/planning_launch.py')
        )
    )

    rviz_static_map_config_path = os.path.join(get_package_share_directory('launcher'), 'launch/svd_viz.rviz')

    rviz_static_map_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_static_map_config_path],
        output='screen'
    )

    rviz_local_map_config_path = os.path.join(get_package_share_directory('launcher'), 'launch/svd_local_map_viz.rviz')

    rviz_local_map_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_local_map_config_path],
        output='screen'
    )

    return LaunchDescription([
        # sensing_launch,
        # mapping_launch,
        # mapping_static_launch,
        # visualization_launch,
        # motion_control_launch,
        # vectornav_launch,
        # imu_launch,
        # localization_launch,
        # planning_launch,
        # rviz_static_map_node,
        rviz_local_map_node,
    ])