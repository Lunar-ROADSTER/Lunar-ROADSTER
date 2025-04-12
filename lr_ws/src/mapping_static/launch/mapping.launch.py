from launch import LaunchDescription
from launch_ros.actions import Node
import launch

def generate_launch_description():
    use_sim_time_param = launch.substitutions.LaunchConfiguration('use_sim_time', default='false')  
    
    global_mapping_node = Node(
            package='mapping_static',
            executable='global_mapping_node',
            name='global_mapping_node',
            emulate_tty=True,
            parameters=[{'use_sim_time': use_sim_time_param}]
        )

    ld = LaunchDescription()
    ld.add_action(global_mapping_node)

    return ld