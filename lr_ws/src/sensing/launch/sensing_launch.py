from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
import os
import yaml

def generate_launch_description():
    

    camera_model_arg = DeclareLaunchArgument(
        "camera_model",
        default_value="zed2i",
        description="Model of the ZED camera"
    )

    zed_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('zed_wrapper'), 'launch/zed_camera.launch.py')
        ),
        launch_arguments={
            "camera_model": LaunchConfiguration("camera_model"),
            "publish_tf": "false",          # disable odom->camera TF
            "publish_map_tf": "false",      # disable map->odom TF
            "pos_tracking_enabled": "false" # disable positional tracking
        }.items()
        # Other changed camera settings in zed-ros2-wrapper/zed_wrapper/config/zed2i.yaml and zed-ros2-wrapper/zed_wrapper/config/common_stereo.yaml
    )

    tf_yaml = os.path.join(
        get_package_share_directory('sensing'),
        'config',
        'zed_static_tf_params.yaml'
    )
    with open(tf_yaml, 'r') as f:
        params = yaml.load(f, Loader=yaml.SafeLoader)['zed_static_transform_publisher']['ros__parameters']

    zed_static_tf_pub = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        arguments=[
            str(params['x']), str(params['y']), str(params['z']),
            str(params['yaw']), str(params['pitch']), str(params['roll']),
            str(params['parent_frame_id']), str(params['child_frame_id'])
        ],
        output='screen',
        name='zed_static_tf_pub'
    )

    realsense_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('realsense'), 'launch/realsense_launch.py')
        )
    )

    imu_launch = IncludeLaunchDescription(
      PythonLaunchDescriptionSource(
        os.path.join(get_package_share_directory('imu'), 'launch/imu_launch.py')
      )
    )

    # For debugging purposes
    pseudo_base_link = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        # x y z yaw pitch roll parent child
        arguments=['0', '0', '0', '0', '0', '0', 'map', 'odom'],
        name='odom_to_base_link_static'
    )

    pseudo_base_link_2 = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        # x y z yaw pitch roll parent child
        arguments=['0', '0', '0', '0', '0', '0', 'odom', 'base_link'],
        name='odom_to_base_link_static'
    )

    return LaunchDescription([
        camera_model_arg,
        zed_launch,
        zed_static_tf_pub,
        # realsense_launch,
        # imu_launch,
        # pseudo_base_link,
        # pseudo_base_link_2
    ])
