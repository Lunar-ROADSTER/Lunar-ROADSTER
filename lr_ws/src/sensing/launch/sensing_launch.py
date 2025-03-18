from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    

    # camera_model_arg = DeclareLaunchArgument(
    #     "camera_model",
    #     default_value="zed2i",
    #     description="Model of the ZED camera"
    # )

    # zed_launch = IncludeLaunchDescription(
    #     PythonLaunchDescriptionSource(
    #         os.path.join(get_package_share_directory('zed_wrapper'), 'launch/zed_camera.launch.py')
    #     ),
    #     launch_arguments={"camera_model": LaunchConfiguration("camera_model")}.items()
    # )

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

    return LaunchDescription([
        # camera_model_arg,
        # zed_launch,
        realsense_launch,
        imu_launch
    ])