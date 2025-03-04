import os
import launch
import launch.actions
import launch.substitutions
import launch_ros.actions
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():

    # Launch from elevation_mapping launch file
    share_dir = get_package_share_directory('elevation_mapping')
    config_dir = os.path.join(share_dir, 'config')
    xacro_path = os.path.join(config_dir, 'robot.urdf.xacro')
    list_params = []
    for filee in ["robots/robot_config.yaml","elevation_maps/elevation_map_config.yaml","sensor_processors/sensor_processor_config.yaml","postprocessing/postprocessor_pipeline.yaml"]:
        list_params.append(os.path.join(config_dir, filee))

    # Launch from mapping launch file
    # share_dir = get_package_share_directory('elevation_mapping')
    # config_dir = os.path.join(share_dir, 'config')
    # mapping_share_dir = get_package_share_directory('mapping')
    # mapping_config_dir = os.path.join(mapping_share_dir, 'config')
    # # list_params = []
    # # for filee in ["robots/robot_config.yaml","elevation_maps/elevation_map_config.yaml","sensor_processors/sensor_processor_config.yaml","postprocessing/postprocessor_pipeline.yaml"]:
    # #     list_params.append(os.path.join(mapping_config_dir, filee))
    # list_params = []
    # for filee in ["robots/ground_truth_demo.yaml","elevation_maps/long_range.yaml","sensor_processors/perfect.yaml","postprocessing/postprocessor_pipeline.yaml"]:
    #     list_params.append(os.path.join(mapping_config_dir, filee))
        
    return launch.LaunchDescription(
        [
            launch_ros.actions.Node(
                package='elevation_mapping',
                executable='elevation_mapping',
                name='elevation_mapping',
                output='screen',
                parameters=list_params,
            ),
            #launch_ros.actions.Node(
            #package='robot_state_publisher',
            #executable='robot_state_publisher',
            #name='robot_state_publisher',
            #output='screen',
            #parameters=[{
            #    'robot_description': launch.substitutions.Command(['xacro', ' ', xacro_path])
            #}]
        #)
            launch_ros.actions.Node(
                package= 'rviz2',
                executable= 'rviz2',
                name= 'rviz',
                arguments= ['--display-config', os.path.join(share_dir, 'rviz2', 'custom_rviz2.rviz')],
                output= 'screen'
            )
        ]
    )
