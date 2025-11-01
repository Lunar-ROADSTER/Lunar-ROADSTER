#!/usr/bin/env bash

DEVICE="/dev/video2"

if [ ! -e "$DEVICE" ]; then
  echo "Device $DEVICE not found."
  exit 1
fi

# User controls
v4l2-ctl -d "$DEVICE" --set-ctrl=brightness=0
v4l2-ctl -d "$DEVICE" --set-ctrl=contrast=64
v4l2-ctl -d "$DEVICE" --set-ctrl=saturation=64
v4l2-ctl -d "$DEVICE" --set-ctrl=hue=0
v4l2-ctl -d "$DEVICE" --set-ctrl=white_balance_automatic=0
v4l2-ctl -d "$DEVICE" --set-ctrl=white_balance_temperature=4600
v4l2-ctl -d "$DEVICE" --set-ctrl=gamma=100
v4l2-ctl -d "$DEVICE" --set-ctrl=gain=0
v4l2-ctl -d "$DEVICE" --set-ctrl=power_line_frequency=2
v4l2-ctl -d "$DEVICE" --set-ctrl=sharpness=2
v4l2-ctl -d "$DEVICE" --set-ctrl=backlight_compensation=1

# Camera controls
v4l2-ctl -d "$DEVICE" --set-ctrl=auto_exposure=1
v4l2-ctl -d "$DEVICE" --set-ctrl=exposure_time_absolute=10
v4l2-ctl -d "$DEVICE" --set-ctrl=exposure_dynamic_framerate=0

echo "Camera controls applied to $DEVICE."
