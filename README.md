# 🚀 Lunar ROADSTER – System Bring-Up & Operation Guide

This document provides complete startup, bring-up, and debugging instructions for running the full Lunar ROADSTER autonomy stack on the NVIDIA Jetson Orin platform.

For details about the project’s motivation, system architecture, and team, visit:  
https://mrsdprojects.ri.cmu.edu/2025teami/

---

# 📦 Orin System Bring-Up (Standard Startup)

Follow these steps when launching the system outside Docker for quick startup.

### 1. Set UDEV Rules  
`sudo ./set-udev-rules-orin.sh`

### 2. Configure Fisheye Camera
`./set_fisheye.sh`

### 3. Start Sensors  
`./start_sensors.sh`

### 4. Launch Autonomy Stack  
`./autonomy_start.sh`

---

# 🐳 Orin Full System Bring-Up (with Docker)

Used for full deployment & development. This is a deeper dive into the same commands that the startup script launches.

### 1. Set UDEV Rules  
`./set-udev-rules-orin.sh`

### 2. Start Docker Container  
`docker start -i lunar_roadster_dev_orin`

Open another terminal inside Docker:  
`docker exec -it lunar_roadster_dev_orin zsh`

---

# 📡 Micro-ROS Bring-Up (Arduino + Sensor Drivers)

Inside Docker:

```bash
cd ~/microros_ws
source install/local_setup.zsh
ros2 run micro_ros_setup create_agent_ws.sh
ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/lr_dev/tty_arduino -v6
```


---

# 🎮 Teleoperation Bring-Up (Manual Control)

```bash
cd Lunar_ROADSTER/lr_ws
source install/setup.zsh
ros2 launch motion_control motion_control_launch.py
```


Switch MUX to teleop:  
`ros2 topic pub /mux_mode lr_msgs/msg/MuxMode "{mode: 3}" --once`

---

# 🧭 Localization Bring-Up

### 1. Launch VectorNav  
`ros2 launch vectornav vectornav.launch.py`

### 2. Launch IMU Transform Pipeline  
`ros2 launch imu imu_launch.py`

### 3. Launch EKF Localization  
`ros2 launch localization ekf_localization.launch.py`

### 4. Calibrate IMU  

`
ros2 action send_goal /ts_prism_transformer/calibrate_imu lr_msgs/action/CalibrateImu "{dont_move_rover: false, time: 4}"
`

### 5. (Optional) Ceiltrack Localization
`ros2 launch ceiltrack ceiltrack.launch.py`

---

# 🗺️ Navigation Bring-Up

### 1. Map Server  

`ros2 run nav2_map_server map_server --ros-args -p yaml_filename:=/root/Lunar_ROADSTER/lr_ws/src/navigation/maps/global_costmap.yaml -p frame_id:=map`

If `/map` is not publishing:

```bash
ros2 lifecycle set /map_server configure
ros2 lifecycle set /map_server activate
```


### 2. Publish Crater Features

```bash
ros2 run navigation crater_centroids_pub
ros2 run navigation crater_diameters_pub
```

### 3. Global Navigation Planner  

`ros2 run navigation global_astar_node --ros-args --params-file /root/Lunar_ROADSTER/lr_ws/src/navigation/config/global_plan_params.yaml`

### 4. Local Navigation Planner

`ros2 run navigation manipulation_planner_node`


### 5. Navigation Controller  

`ros2 run navigation global_planner_controller_main --ros-args -p yaml_filename:=/root/Lunar_ROADSTER/lr_ws/src/navigation/config/global_planner_controller.yaml`

---

# 🧪 Validation Stack Bring-Up

```bash
ros2 launch sensing sensing_launch.py
ros2 launch validation validation.launch.py
```

---

# 👁️ Perception Bring-Up

### 1. Launch YOLOv8

```bash
conda activate <env_name>
source ~/.zshrc
ros2 run perception detection_ankit.py
```
### 2. Run Pose Extractor

`ros2 run perception pose_extractor`

---

# 🧩 BEN (Finite-State Machine) Bring-Up

`ros2 launch ben ben.launch.py`

---

# 🐞 Debug Mode Instructions

### Enter Debug Mode  
`ros2 topic pub /ben_debug_trigger std_msgs/msg/Bool "{data: true}" --once`

### Exit Debug Mode  
Provide current crater index + current state:

`ros2 topic pub --once /ben_exit_debug_trigger lr_msgs/msg/ExitDebug '{current_crater_index: 0, current_state: "START_MISSION"}'`


### Valid States  
- START_MISSION  
- GLOBAL_NAV_PLANNER  
- GLOBAL_NAV_CONTROLLER  
- VALIDATION  
- TOOL_PLANNER  
- PERCEPTION  
- MANIPULATION_PLANNER  
- MANIPULATION_CONTROLLER  
- END_MISSION  
- STOPPED  
- DEBUG  

**Do NOT transition to `MANUAL_OVERRIDE` via `/ben_exit_debug_trigger`.**  
Always use the manual override trigger.

---

# 🎮 Manual Override (Teleop Mode)

You must already be in **DEBUG** state.

### Enter Manual Override  
`ros2 topic pub /ben_manual_override_trigger std_msgs/msg/Bool "{data: true}" --once`

### Exit Manual Override  
(Returns to DEBUG.)  
`ros2 topic pub /ben_manual_override_trigger std_msgs/msg/Bool "{data: false}" --once`

---

# 📘 Additional Documentation

For project overview, motivation, hardware design, and team details: https://mrsdprojects.ri.cmu.edu/2025teami/

---

# © Team I – CMU MRSD 2025

The Lunar ROADSTER system is developed as part of the Carnegie Mellon University MRSD Program.  
Feel free to file issues or contact the team regarding deployment or development.

Team:
- [Bhaswanth Ayapilla](https://github.com/Bhaswanth-A)
- [Boxiang (William) Fu](https://github.com/williamfbx)
- [Ankit Aggarwal](https://github.com/AnkitAggarwal0)
- [Deepam Ameria](https://github.com/Deepam-Ameria)
- [Simson D'Souza](https://github.com/simsondsouza)
