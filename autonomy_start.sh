#!/usr/bin/env bash
set -euo pipefail

SESSION="lunar_roadster_autonomy"
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
# 8) Map server
add_pane "ros2 run nav2_map_server map_server --ros-args -p yaml_filename:=$MAP_YAML"

# 9) Map lifecycle (one-shot)
add_pane

# 10) Publish crater centroids
add_pane "ros2 run navigation crater_centroids_pub"

# 11) Publish crater diameters
add_pane "ros2 run navigation crater_diameters_pub"

# 12) Navigation Planner
add_pane "ros2 run navigation global_astar_node --ros-args --params-file /root/Lunar_ROADSTER/lr_ws/src/navigation/config/global_plan_params.yaml"

# 13) Navigation Controller
add_pane "ros2 run navigation global_planner_controller_main --ros-args -p yaml_filename:=/root/Lunar-ROADSTER/lr_ws/src/navigation/config/global_planner_controller.yaml"

# 14) Autonomy command
add_pane "ros2 run navigation manipulation_planner_node"

# 15) Validation TFs
add_pane "ros2 launch sensing sensing_launch.py"

# 16) Validation launch
add_pane "ros2 launch validation validation.launch.py"

# 17) Perception - crater detection
add_pane

# 18) Perception - pose extractor
add_pane "ros2 run perception pose_extractor"

# 19) BEN
add_pane 

# --- tmux QoL ---
tmux set -g mouse on
tmux set -g remain-on-exit on
tmux setw -t "$SESSION":stack allow-rename off
tmux select-layout -t "$SESSION":stack tiled
tmux select-pane -t "$SESSION":stack.0

exec tmux attach -t "$SESSION"
