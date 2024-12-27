#!/bin/zsh
set -e

# source ~/.zshrc

# Start the VNC server
# Xvfb :0 -screen 0 1024x768x24 &
# x11vnc -display :0 -forever -passwd lunarroadster -rfbport 5900 -shared

# Execute the given command
exec "$@"
