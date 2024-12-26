#!/bin/zsh
set -e

source ~/.zshrc

# Start the VNC server, in shared mode so more than one user can access, must be last command to run
# x11vnc -forever -usepw -create -shared

# Execute the given command
exec "$@"
