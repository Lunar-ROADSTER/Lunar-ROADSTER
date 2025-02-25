from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os
import yaml

def generate_launch_description():
  ekf_odom_params = os.path.join(
    get_package_share_directory('localization'),
    'config',
    'ekf_odom_node_params.yaml'
  )
  ekf_global_params = os.path.join(
    get_package_share_directory('localization'),
    'config',
    'ekf_global_node_params.yaml'
  )
  total_station_beacon_static_tf_params_path = os.path.join(
    get_package_share_directory('localization'),
    'config',
    'total_station_beacon_static_tf_params.yaml'
  )
  with open(total_station_beacon_static_tf_params_path, 'r') as stream:
      total_station_beacon_static_tf_params = yaml.load(
          stream,
          Loader=yaml.SafeLoader
      )['total_station_beacon_static_transform_publisher']['ros__parameters']


  return LaunchDescription([
    Node(
      package='robot_localization',
      executable='ekf_node',
      name='ekf_odom_node',
      parameters=[ekf_odom_params],
      remappings=[
        ('odometry/filtered', 'odometry/filtered/ekf_odom_node')
      ]
    ),
    Node(
      package='robot_localization',
      executable='ekf_node',
      name='ekf_global_node',
      parameters=[ekf_global_params],
      remappings=[
        ('odometry/filtered', 'odometry/filtered/ekf_global_node')
      ]
    ),
    Node(
            package='localization',
            executable='ts_prism_transformer',
            name='ts_prism_transformer',
            output='screen'
    ),
    # Static tf publisher
    # Order of args is [x, y, z, yaw, pitch, roll, parent_frame, child_frame]
    # http://docs.ros.org/en/foxy/Tutorials/Tf2/Writing-A-Tf2-Static-Broadcaster-Cpp.html#the-proper-way-to-publish-static-transforms
    Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        arguments=[
            total_station_beacon_static_tf_params['total_station_prism']['x'], total_station_beacon_static_tf_params['total_station_prism']['y'], total_station_beacon_static_tf_params['total_station_prism']['z'],
            total_station_beacon_static_tf_params['total_station_prism']['yaw'], total_station_beacon_static_tf_params['total_station_prism']['pitch'], total_station_beacon_static_tf_params['total_station_prism']['roll'],
            total_station_beacon_static_tf_params['total_station_prism']['parent_frame_id'], total_station_beacon_static_tf_params['total_station_prism']['child_frame_id']
        ]
    ),
  ])