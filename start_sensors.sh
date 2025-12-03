#!/usr/bin/env bash
set -euo pipefail

SESSION="lunar_roadster_sensors"
CTR="lunar_roadster_dev_orin"
MAP_YAML="/root/Lunar_ROADSTER/lr_ws/src/navigation/maps/global_costmap.yaml"

# --- Ensure container exists & running ---
docker inspect "$CTR" >/dev/null 2>&1 || { echo "Container '$CTR' not found"; exit 1; }
if ! docker inspect -f '{{.State.Running}}' "$CTR" | grep -q true; then
  docker start "$CTR" >/dev/null || { echo "Failed to start '$CTR'"; exit 1; }
fi

# Reattach if exists
if tmux has-session -t "$SESSION" 2>/dev/null; then
  exec tmux attach -t "$SESSION"
fi

# Helper: add a new pane in the 'stack' window and run a command inside the container
add_pane() {
  tmux split-window -t "$SESSION":stack -v
  tmux select-layout -t "$SESSION":stack tiled

  if [ $# -eq 0 ]; then
    # No command given ? just open a shell in the container
    tmux send-keys -t "$SESSION":stack "docker exec -it $CTR zsh" C-m
  else
    # Run the provided command
    tmux send-keys -t "$SESSION":stack "docker exec -it $CTR zsh -lic '$*'" C-m
  fi
}

# Create session with first pane (interactive shell in container)
tmux new-session -d -s "$SESSION" -n stack "docker exec -it $CTR zsh"
tmux select-layout -t "$SESSION":stack tiled

# ---------- Your panes ----------
# 1) Micro-ROS
add_pane "ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/ttyACM0 -v6"

# 2) Teleop launch
add_pane "ros2 launch motion_control motion_control_launch.py"

# 3) Set mux to teleop (one-shot)
add_pane "ros2 launch foxglove_bridge foxglove_bridge_launch.xml" 

# 4) VectorNav
add_pane "ros2 launch vectornav vectornav.launch.py"

# 5) IMU transforms
add_pane "ros2 launch imu imu_launch.py"

# 6) EKF localization
add_pane "ros2 launch localization ekf_localization.launch.py"

# 7) IMU calibration (one-shot)
add_pane 


# --- tmux QoL ---
tmux set -g mouse on
tmux set -g remain-on-exit on
tmux setw -t "$SESSION":stack allow-rename off
tmux select-layout -t "$SESSION":stack tiled
tmux select-pane -t "$SESSION":stack.0

exec tmux attach -t "$SESSION"
