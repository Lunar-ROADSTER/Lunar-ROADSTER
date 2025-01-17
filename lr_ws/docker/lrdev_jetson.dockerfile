# ------- ZED Camera SDK -------- 
# FROM stereolabs/zed:4.2-runtime-cuda12.1-ubuntu22.04
# FROM stereolabs/zed:4.2-runtime-jetson-jp6.1.0
FROM stereolabs/zed:4.2-devel-jetson-jp6.1.0

# ------- ROS 2 Humble image -------- 
# FROM dustynv/ros:humble-desktop-l4t-r36.2.0

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive \
  ROS_DISTRO=humble \
  WORKSPACE=/root/Lunar_ROADSTER/lr_ws

# Copy ZED SDK from the source image
# COPY --from=zed_sdk /usr/local/zed /usr/local/zed

# Add ZED SDK environment variables
# ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/zed/lib
# ENV PATH=$PATH:/usr/local/zed/bin

COPY ./ $WORKSPACE

# ---------------- Base environment configuration -------------------------
# Setup shell
COPY docker/.p10k.zsh /root/.p10k.zsh
ENV TERM=xterm-256color
RUN apt-get update && apt-get install -y zsh bash wget \
  && PATH="$PATH:/usr/bin/zsh" \
  # Install Oh-My-Zsh with default theme
  && sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.3/zsh-in-docker.sh)" \
  # Initialize custom zsh theme
  && echo "[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh" >> ~/.zshrc \
  # Source ROS 
  && echo '# ROS' >> /root/.zshrc \
  && echo '# ROS' >> /root/.bashrc \
  && echo 'source /opt/ros/$ROS_DISTRO/setup.zsh' >> /root/.zshrc \
  && echo 'source /opt/ros/$ROS_DISTRO/setup.bash' >> /root/.bashrc \
  # Fix zsh autocomplete for ROS2 packages
  && echo 'eval "$(register-python-argcomplete3 ros2)"' >> /root/.zshrc \
  && echo 'eval "$(register-python-argcomplete3 colcon)"' >> /root/.zshrc \
  # Welcome message
  && echo '# Welcome message' >> /root/.zshrc \
  && echo "figlet -f slant -w 120 'Lunar ROADSTER'" >> /root/.zshrc

SHELL ["/usr/bin/zsh", "-c"]
# ---------------------------------------------------------------------------


# ----------------------- Base system packages ------------------------------
# Install "starter pack" of some basic tools
RUN apt-get update && apt-get install -y \
  figlet \
  libgl1-mesa-glx \
  nano \
  iputils-ping \
  tree \
  curl \
  # Install vnc, xvfb for VNC configuration, fluxbox for VNC window managment
  x11vnc \
  xvfb \
  fluxbox \
  && rm -rf /var/lib/apt/lists/*

# Add ROS 2 repository and keys
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg && \
  echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null

# Install essential development tools and utilities
RUN apt-get update && apt-get install -y --no-install-recommends \
  build-essential \
  cmake \
  python3-pip \
  nano \
  python3-rosdep \
  python3-colcon-common-extensions \
  python3-argcomplete && \
  rosdep init && \
  rosdep update \
  && rm -rf /var/lib/apt/lists/*
# ---------------------------------------------------------------------------


# --------------------------- Install ROS2 Humble -----------------------------

# Install ROS 2 Base (minimal installation without GUI tools)
RUN apt-get update && apt-get install -y \
  ros-${ROS_DISTRO}-ros-base \
  && rm -rf /var/lib/apt/lists/*

# Install ROS 2 core tools (minimal visualization and debugging tools)
# Run the following with DEBIAN_FRONTEND=noninteractive to avoid prompt for keyboard language, see https://askubuntu.com/questions/876240/how-to-automate-setting-up-of-keyboard-configuration-package
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
  # General ROS2 debug
  ros-$ROS_DISTRO-rviz2 \
  ros-$ROS_DISTRO-rqt-graph \
  ros-$ROS_DISTRO-rqt-reconfigure \
  ros-$ROS_DISTRO-plotjuggler-ros \
  # Teleop
  ros-$ROS_DISTRO-joy \
  # robot_localization package ekf/ukf
  ros-$ROS_DISTRO-robot-localization \
  # PCL
  keyboard-configuration \
  libpcl-dev \
  ros-$ROS_DISTRO-pcl-conversions \
  ros-$ROS_DISTRO-pcl-ros \
  ros-$ROS_DISTRO-pcl-msgs \
  # Health monitoring gui
  ros-$ROS_DISTRO-rosbridge-suite \
  && rm -rf /var/lib/apt/lists/*
# ---------------------------------------------------------------------------  


# --------------------------- Install Micro-ROS -----------------------------
WORKDIR /root/microros_ws
RUN git clone -b $ROS_DISTRO https://github.com/micro-ROS/micro_ros_setup.git src/micro_ros_setup \
  && apt-get update && rosdep update \
  && rosdep install --from-path src --ignore-src -y \
  && . /opt/ros/$ROS_DISTRO/setup.sh \
  && colcon build \
  && . install/local_setup.sh \
  && ros2 run micro_ros_setup create_firmware_ws.sh host \
  && ros2 run micro_ros_setup build_firmware.sh \
  && . install/local_setup.sh \
  && ros2 run micro_ros_setup create_agent_ws.sh \
  && ros2 run micro_ros_setup build_agent.sh \
  && . install/local_setup.sh
# ---------------------------------------------------------------------------  


# --------------------------- VNC configuration -----------------------------
# Setup a VNC password
RUN  mkdir ~/.vnc \
  && x11vnc -storepasswd lunarroadster ~/.vnc/passwd \
  # Start the VNC server
  && echo '# VNC setup' >> /root/.zshrc \
  && echo '# VNC setup' >> /root/.bashrc \
  && echo "export DISPLAY=:0" >> ~/.zshrc \
  && echo "export DISPLAY=:0" >> ~/.bashrc \
  # Always try to start windows management in background to be ready for VNC
  && echo "( fluxbox > /dev/null 2>&1 & )" >> ~/.zshrc \
  && echo "( fluxbox > /dev/null 2>&1 & )" >> ~/.bashrc \
  # Clean up unnecessary output files
  && echo "rm -f /root/Lunar_ROADSTER/lr_ws/nohup.out" >> ~/.zshrc \
  && echo "rm -f /root/Lunar_ROADSTER/lr_ws/nohup.out" >> ~/.bashrc
# ---------------------------------------------------------------------------


# ----------------- Setup Lunar ROADSTER environment packages ---------------------------
# Build cmake from source for cross-compliation
# See the following, WITHOUT PURGE! https://stackoverflow.com/a/59689105
# (purging cmake can affect ROS: https://askubuntu.com/a/829311)
RUN wget https://github.com/Kitware/CMake/releases/download/v3.23.4/cmake-3.23.4.tar.gz -P /root/ \
  && cd /root/ \
  && tar zxvf cmake-3.23.4.tar.gz \
  && cd cmake-3.23.4 \
  && ./bootstrap \
  && make \
  && make install \ 
  && cd /root/ \
  && rm -rf cmake-3.23.4 cmake-3.23.4.tar.gz 


# Setup Python environment
COPY ./docker/requirements.txt /root/requirements.txt
RUN pip3 install --no-cache-dir -r /root/requirements.txt && rm -f /root/requirements.txt

# Prep for colcon build, but don't build anything yet
WORKDIR $WORKSPACE
COPY ./src $WORKSPACE/src
RUN rosdep install --from-paths src --ignore-src -r -y
# --------------------------------------------------------------------------------------

# -------------------------- Container entrypoint --------------------------------------
# Copy entrypoint script for workspace setup
RUN chmod +x /root/Lunar_ROADSTER/lr_ws/docker/lr_entrypoint.sh

# # Make entry
WORKDIR /root/Lunar_ROADSTER/lr_ws
ENTRYPOINT [ "/root/Lunar_ROADSTER/lr_ws/docker/lr_entrypoint.sh" ]
CMD [ "zsh", "-i" ]
# ---------------------------------------------------------------------------------------

