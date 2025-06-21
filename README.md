# Rover Bringup

Owner: Lunar ROADSTER  
Tags: Guides and Processes

# Full System Bring-Up Instructions

1. `sudo ./jetsonstartup.zsh`
2. `cd /sd_card/Lunar-ROADSTER/lr_ws`
3. `docker start -i lunar_roadster_dev_jetson`
4. To open a new terminal: `sudo docker exec -it lunar_roadster_dev_jetson zsh`
5. Start Micro-ROS:
    1. `cd ~/microros_ws`
    2. `source install/local_setup.zsh`
    3. `ros2 run micro_ros_setup create_agent_ws.sh`
    4. `ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/cg_dev/tty_arduino -v6`
6. Start teleop:
    1. `cd Lunar_ROADSTER/lr_ws`
    2. `source install/setup.zsh`
    3. `ros2 launch motion_control motion_control_launch.py`
    4. Change mux mode to teleop: `ros2 topic pub /mux_mode cg_msgs/msg/MuxMode "{mode: 3}" --once`
7. Start localization:
    1. Launch vectornav: `ros2 launch vectornav vectornav.launch.py`
    2. Launch IMU transformations: `ros2 launch imu imu_launch.py`
    3. Launch localization: `ros2 launch localization ekf_localization.launch.py`
    4. Calibrate IMU: `ros2 action send_goal /ts_prism_transformer/calibrate_imu lx_msgs/action/CalibrateImu "{dont_move_rover: false, time: 4}"`
8. Start navigation:
    1. Run map server: `ros2 run nav2_map_server map_server --ros-args -p yaml_filename:=/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_bringup/maps/map.yaml`
    2. If map_server doesn’t publish to `/map` topic, then run the commands
        1. `ros2 lifecycle set /map_server configure`
        2. `ros2 lifecycle set /map_server activate`
    3.  `ros2 launch nav2_bringup bringup_launch.py slam:=False map:=/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_bringup/maps/map.yaml use_sim_time:=false`
    4. `ros2 run nav2_bringup autonomy_command`
9. Launch visualization - `ros2 launch launcher launch.py`
10. `ros2 launch planning planning_launch.py`

# Lunar ROADSTER & Crater Grader Docker Bringup

The docker image is contained within the USB attached to the Jetson. The following procedure should be followed to obtain access to the Crater Grader docker container:

1. `sudo chmod 755 /usb /sd_card`
2. Type `df -h` to find mounting port of the USB drive. It should be `/dev/sda1` or `/dev/sdb1`
3. `sudo mount /dev/sda1 /usb` (replace with `/dev/sd{Port}1` if it is mounted elsewhere. You should see `CRATER_GRADER` under `ls`, if not `cd ..` and then `cd /usb` back)
4. `sudo mount /dev/mmcblk1p1 /sd_card`
5. Go inside `cd /sd_card`
6. `sudo systemctl restart docker` (you might need to rerun `sudo chmod 755 /usb /sd_card`if permissions are revoked)
7. `sudo docker start -i lunar_roadster_dev_jetson`
8. To open a new terminal: `sudo docker exec -it lunar_roadster_dev_jetson zsh`
9. For CraterGrader:
    1. Go inside `/usb`:`docker-compose up -d cg-dev-hw`
    2. Go inside `cd ./scripts`
    3. `source [set-udev-rules.sh](http://set-udev-rules.sh/)`
    4. `docker-compose exec cg-dev-hw zsh`
    5. You should now be inside Crater Grader docker and see their logo
    6. `source ./install/local_setup.zsh`
    7. Make sure the directory `/dev/cg_dev` is present and contains `tty_arduino`. This is the hardware interface from inside the docker to the Jetson.

# New Instructions

1. `sudo ./jetsonstartup.sh`
2. `cd /sd_card`
3. `sudo systemctl restart docker`
4. `cd`
5. `sudo ./jetsonstartup.sh`
6. `cd /sd_card/LUNAR_ROADSTER/lr_ws`
7. `docker start -i lunar_roadster_dev_jetson`
8. To open a new terminal: `sudo docker exec -it lunar_roadster_dev_jetson zsh`

## Debug Trigger

Send this to trigger state transition when rover gets stuck:

`ros2 topic pub /behavior_exec_debug_trigger std_msgs/msg/Bool "{data: true}" --once`

# Connecting Additional Terminals to the Docker

1. `cd /usb/CRATER_GRADER/`
2. `docker-compose exec cg-dev-hw zsh`
3. `source ./install/local_setup.zsh`
4. If it says `zsh: corrupt history file /root/.zsh_history` copy and paste Step 3 again

# Crater Grader Teleop Bringup

1. Open at least 2 terminals connected to the docker
2. `source ./install/local_setup.zsh` on aals
3. Check if the LEDs on the RoboClaws (RC1, RC2, and RC3) are flashing green. If not, press the `Reset` button on the Arduino
4. `colcon build` if not already built, then `source ./install/local_setup.zsh` again if needed
5. `ros2 launch motion_control motion_control_launch.py`
6. Use the other terminal and change the `mux_mode` to `teleop` using 
    
    `ros2 topic pub /mux_mode cg_msgs/msg/MuxMode "{mode: 3}" --once`
    
7. You should be able to teleop the rover now. If not, check debugging section below

# Checking if Gadgets and Links are Functioning Properly (for Teleop)

The following topics should be publishing messages if the links and gadgets are functioning properly:

- **Joystick to Jetson**: `ros2 topic echo /joy`
- **Jetson to Arduino Interface**: `ros2 topic echo /teleop_cmd`
- **Arduino Interface to Arduino**: `ros2 topic echo /arduino_cmd`
- **Arduino to Jetson**: `ros2 topic echo /arduino_feedback`

One common issue that we found was that the `micro_ros_agent` was not being initialized properly. A potential checklist to solve this is as follows:

1. `source install/local_setup.zsh`
2. `ros2 run micro_ros_setup create_agent_ws.sh`
3. `ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/cg_dev/tty_arduino -v6`
4. If the logger is not showing info, press the reset button on the Arduino. You should see `recv_message` and `send_message` if the `micro_ros_agent` is set up properly.

Another common issue is that the joystick is not toggled to `X`. Make sure the button on the front-center of the joystick is toggled to `X`.

## Demo

**Pre-setup**

- `sudo ./jetsonstartup.zsh`
- `cd /usb/CRATER_GRADER/scripts/`
- `sudo ./set-udev-rules.sh`
- `cd`
- `cd /sd_card/Lunar-ROADSTER/lr_ws`

Terminal 1 (2 terminals):

- `docker start -i lunar_roadster_dev_jetson`
- `source install/setup.zsh`
- `ros2 launch motion_control motion_control_launch.py`

Sub-terminal

- `docker exec -it lunar_roadster_dev_jetson zsh`
- `source install/setup.zsh`
- `ros2 topic pub /mux_mode cg_msgs/msg/MuxMode "{mode: 3}" --once`
- Calibrate IMU: `ros2 action send_goal /ts_prism_transformer/calibrate_imu lx_msgs/action/CalibrateImu "{dont_move_rover: false, time: 4}"`

Terminal 2 (Two terminals):

- `docker exec -it lunar_roadster_dev_jetson zsh`
- `source install/setup.zsh`
- `ros2 launch vectornav vectornav.launch.py`
- `ros2 launch imu imu_launch.py`

Terminal 3:

- `docker exec -it lunar_roadster_dev_jetson zsh`
- `source install/setup.zsh`
- `ros2 launch localization ekf_localization.launch.py`

Terminal 4 (Two terminals):

- `docker exec -it lunar_roadster_dev_jetson zsh`
- `source install/setup.zsh`
- `ros2 run nav2_map_server map_server --ros-args -p yaml_filename:=/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_bringup/maps/map.yaml`
- `ros2 lifecycle set /map_server configure`
- `ros2 lifecycle set /map_server activate`

Terminal 5:

- `docker exec -it lunar_roadster_dev_jetson zsh`
- `source install/setup.zsh`
- `ros2 launch nav2_bringup bringup_launch.py slam:=False map:=/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_bringup/maps/map.yaml use_sim_time:=false`

Terminal 6:

- `docker exec -it lunar_roadster_dev_jetson zsh`
- `source install/setup.zsh`
- `ros2 run nav2_bringup autonomy_command`

Terminal 7:

- `docker exec -it lunar_roadster_dev_jetson zsh`
- `source install/setup.zsh`
- `ros2 launch launcher launch.py`

Terminal 8:

- `docker exec -it lunar_roadster_dev_jetson zsh`
- `source install/setup.zsh`
- `ros2 launch planning planning_launch.py`

## Debug Trigger

Send this to trigger state transition when rover gets stuck:

`ros2 topic pub /behavior_exec_debug_trigger std_msgs/msg/Bool "{data: true}" --once`
