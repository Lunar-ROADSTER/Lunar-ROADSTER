from launch import LaunchDescription
from launch_ros.actions import Node
import launch

def generate_launch_description():
    use_sim_time_param = launch.substitutions.LaunchConfiguration('use_sim_time', default='false')  
    launch_rviz = launch.substitutions.LaunchConfiguration('launch_rviz', default='false')
    
    pc_handler_node = Node(
            package='mapping',
            executable='pc_handler_node',
            name='pc_handler_node',
            emulate_tty=True,
            parameters=[{'use_sim_time': use_sim_time_param}]
        )
    
    global_mapping_node = Node(
            package='mapping',
            executable='global_mapping_node',
            name='global_mapping_node',
            emulate_tty=True,
            parameters=[{'use_sim_time': use_sim_time_param}]
        )
    
    local_mapping_node = Node(
            package='mapping',
            executable='local_mapping_node',
            name='local_mapping_node',
            emulate_tty=True,
            parameters=[{'use_sim_time': use_sim_time_param}]
        )

    ld = LaunchDescription()
    ld.add_action(pc_handler_node)
    ld.add_action(global_mapping_node)
    ld.add_action(local_mapping_node)

    return ld