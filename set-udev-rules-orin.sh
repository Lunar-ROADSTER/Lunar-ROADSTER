#!/usr/bin/env bash
set -euo pipefail

RULES_FILE="/etc/udev/rules.d/49-lr-custom.rules"

echo "[INFO] Setting udev rules in $RULES_FILE"

# Remove old rules file if it exists
sudo rm -f "$RULES_FILE"

# Write new rules
sudo tee "$RULES_FILE" >/dev/null <<'EOF'
# ================== Lunar Roadster Custom Rules ==================

# Arduino Due (Programming Port, CDC ACM)
# VID:PID = 2341:003d ? /dev/lr_dev/tty_arduino
ACTION=="add", SUBSYSTEM=="tty", KERNEL=="ttyACM[0-9]*", \
  ATTRS{idVendor}=="2341", ATTRS{idProduct}=="003d", \
  GROUP="dialout", MODE="0666", SYMLINK+="lr_dev/tty_arduino"

# DWM1001-Dev Beacon (adjust VID/PID if your lsusb differs)
# VID:PID = 1366:0105 ? /dev/lr_dev/tty_uwb1
ACTION=="add", SUBSYSTEM=="tty", KERNEL=="ttyACM[0-9]*", \
  ATTRS{idVendor}=="1366", ATTRS{idProduct}=="0105", \
  GROUP="dialout", MODE="0666", SYMLINK+="lr_dev/tty_uwb1"

# IMU (FTDI USB-Serial, adjust if different)
# VID:PID = 0403:6001 ? /dev/lr_dev/tty_imu
ACTION=="add", SUBSYSTEM=="tty", KERNEL=="ttyUSB[0-9]*", \
  ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6001", \
  GROUP="dialout", MODE="0666", SYMLINK+="lr_dev/tty_imu"

# Sun Camera (V4L2 device, adjust VID/PID if needed)
# VID:PID = 32e4:9230 ? /dev/lr_dev/sun_camera
ACTION=="add", SUBSYSTEM=="video4linux", KERNEL=="video[0-9]*", \
  ATTRS{idVendor}=="32e4", ATTRS{idProduct}=="9230", \
  MODE="0666", SYMLINK+="lr_dev/sun_camera"

# ================================================================
EOF

# Reload and trigger udev so rules take effect immediately
echo "[INFO] Reloading udev rules..."
sudo udevadm control --reload-rules
sudo udevadm trigger

echo "[INFO] Udev rules set. Current /dev/lr_dev symlinks:"
ls -l /dev/lr_dev/* 2>/dev/null || echo "  (no devices plugged in yet)"
