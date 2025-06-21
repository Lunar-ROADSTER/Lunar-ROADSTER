#!/usr/bin/env zsh

CONTAINER_NAME="lunar_roadster_dev_jetson"

# Start container if not running
if ! docker ps | grep -q "$CONTAINER_NAME"; then
  docker start -i "$CONTAINER_NAME"
fi

# Start Motion Control
tilix -a app-new-session -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh &&
ros2 launch motion_control motion_control_launch.py &&
exec zsh'"

# Split down and start Teleop
tilix -a session-add-down -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh && 
ros2 topic pub /mux_mode cg_msgs/msg/MuxMode "{mode: 3}" --once &&
exec zsh'"

# New session and launch vectornav
tilix -a app-new-session -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh &&
ros2 launch vectornav vectornav.launch.py &&
exec zsh'"

# Split down and launch IMU base link transform
tilix -a session-add-down -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh && 
ros2 launch imu imu_launch.py &&
exec zsh'"

# New session and launch localization
tilix -a app-new-session -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh &&
ros2 launch localization ekf_localization.launch.py &&
exec zsh'"

# New session and calibrate IMU
tilix -a app-new-session -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh &&
ros2 action send_goal /ts_prism_transformer/calibrate_imu lx_msgs/action/CalibrateImu "{dont_move_rover: false, time: 4}" &&
exec zsh'"

# New session and run map server
tilix -a app-new-session -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh &&
ros2 run nav2_map_server map_server --ros-args -p yaml_filename:=/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_bringup/maps/map.yaml &&
exec zsh'"

# Split down and activate map server
tilix -a session-add-down -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh && 
ros2 lifecycle set /map_server configure &&
ros2 lifecycle set /map_server activate &&
exec zsh'"

# New session and launch navigation stack
tilix -a app-new-session -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh &&
ros2 launch nav2_bringup bringup_launch.py slam:=False map:=/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_bringup/maps/map.yaml use_sim_time:=false &&
exec zsh'"

# New session and launch autonomy command
tilix -a app-new-session -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh &&
ros2 run nav2_bringup autonomy_command &&
exec zsh'"

# New session and launch visualization
tilix -a app-new-session -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh &&
ros2 launch launcher launch.py &&
exec zsh'"

# New session and launch planning stack
tilix -a app-new-session -e zsh -c "docker exec -it $CONTAINER_NAME zsh -c '
source install/setup.zsh &&
ros2 launch planning planning_launch.py &&
exec zsh'"
