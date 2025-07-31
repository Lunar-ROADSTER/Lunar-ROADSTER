# Full System Bring-Up Instructions

These are the steps to bring up the full Lunar ROADSTER system on the Jetson platform, including micro-ROS agents, localization, teleoperation, and full navigation using Nav2. Each step below includes the necessary terminal commands and a brief explanation of what each does.

---

## 1. Jetson Setup

```bash
sudo ./jetsonstartup.zsh
```

Runs a custom startup script on the Jetson to initialize device permissions, mounts, or system-level configurations necessary before launching Docker or ROS.

---

## 2. Start Docker Container

```bash
docker start -i lunar_roadster_dev_jetson
```

Starts and attaches to the main development container which has ROS 2 and all dependencies pre-installed.

---

## 3. Open New Terminal into Container

```bash
sudo docker exec -it lunar_roadster_dev_jetson zsh
```

If you need a second terminal into the same container, use this to avoid restarting the container.

---

## 4. Start Micro-ROS Agent

```bash
cd ~/microros_ws
source install/local_setup.zsh
ros2 run micro_ros_setup create_agent_ws.sh
ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/cg_dev/tty_arduino -v6
```

This sets up and starts the micro-ROS agent which bridges communication between the microcontroller (Arduino) and the Jetson host via serial.

---

## 5. Start Teleoperation

```bash
cd Lunar_ROADSTER/lr_ws
source install/setup.zsh
ros2 launch motion_control motion_control_launch.py
ros2 topic pub /mux_mode cg_msgs/msg/MuxMode "{mode: 3}" --once
```

Launches the motion control node to interpret teleop commands. The mux mode switch tells the robot to listen to teleop commands rather than autonomous input.

---

## 6. Start Localization

```bash
ros2 launch vectornav vectornav.launch.py

ros2 launch imu imu_launch.py

ros2 launch localization ekf_localization.launch.py

ros2 action send_goal /ts_prism_transformer/calibrate_imu lx_msgs/action/CalibrateImu "{dont_move_rover: false, time: 4}"
```

Starts the full localization pipeline: VectorNav IMU driver, IMU data reframe to base\_link, EKF localization node, and finally calibrates IMU bias using total station reference.

---

## 7. Start Navigation

```bash
ros2 run nav2_map_server map_server --ros-args -p yaml_filename:=/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_bringup/maps/map.yaml

ros2 lifecycle set /map_server configure
ros2 lifecycle set /map_server activate

ros2 launch nav2_bringup bringup_launch.py slam:=False map:=/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_bringup/maps/map.yaml use_sim_time:=false

ros2 run nav2_bringup autonomy_command
```

This launches the full Nav2 navigation stack using a preloaded static map. It sets the lifecycle of map\_server, brings up Nav2 modules (planner, controller, recoveries, etc.), and starts the command node for autonomous execution.

---

## 8. Launch Visualization

```bash
ros2 launch launcher launch.py
```

This launches the RViz visualizer along with any additional visual tools or debug layers required.

---

## 9. Launch Planning Stack

```bash
ros2 launch planning planning_launch.py
```

Starts the global planner used for sending waypoints or tasks to the robot autonomously.

---

**Note:** Always ensure that the transforms are active and all hardware is connected before launching autonomous components.
