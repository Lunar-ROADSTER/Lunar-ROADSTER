# ------- ZED Camera SDK -------- 
FROM deepamameria/zed_ros2_sdk:36.4.0

# ------- ROS 2 Humble image -------- 
# FROM dustynv/ros:humble-desktop-l4t-r36.2.0

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive \
  ROS_DISTRO=humble \
  WORKSPACE=/root/Lunar_ROADSTER/lr_ws

# ---------------- NVIDIA Libraries Configuration -------------------------
# Ensure NVIDIA drivers and CUDA libraries are accessible inside the container
ENV NVIDIA_VISIBLE_DEVICES=all
ENV NVIDIA_DRIVER_CAPABILITIES=all
ENV LD_LIBRARY_PATH=/usr/local/cuda/lib64:/usr/lib/aarch64-linux-gnu:/usr/lib/aarch64-linux-gnu/tegra:$LD_LIBRARY_PATH


COPY ./ $WORKSPACE

# ---------------- Base environment configuration -------------------------
# Setup shell
COPY docker/.p10k.zsh /root/.p10k.zsh
ENV TERM=xterm-256color
RUN apt-get update && apt-get install -y zsh bash wget \
  && PATH="$PATH:/usr/bin/zsh" \
  # Install Oh-My-Zsh with default theme
  && sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.3/zsh-in-docker.sh)" \
  # Zsh Autocomplete
  && git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-/root/.oh-my-zsh/custom}/plugins/zsh-autosuggestions \
  && echo "ZSH_AUTOSUGGEST_HIGHLIGHT_STYLE='fg=#777777'" >> ~/.zshrc \
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
      python3-argcomplete \
  && if [ ! -f /etc/ros/rosdep/sources.list.d/20-default.list ]; then rosdep init; fi \
  && rosdep update \
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
  # Localization 
  ros-$ROS_DISTRO-robot-localization \
  # Map server
  ros-$ROS_DISTRO-nav2-map-server \
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

# --- Foxglove Bridge (ROS 2) ---
RUN apt-get update && apt-get install -y --no-install-recommends \
    ros-$ROS_DISTRO-foxglove-bridge \
 && rm -rf /var/lib/apt/lists/*

# Default Foxglove WebSocket port
EXPOSE 8765


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


# Fast CMake via Kitware APT (works on Jammy/arm64)
# RUN apt-get update && apt-get install -y --no-install-recommends \
#       ca-certificates gnupg wget \
#   && mkdir -p /etc/apt/keyrings \
#   && wget -qO- https://apt.kitware.com/keys/kitware-archive-latest.asc \
#      | gpg --dearmor -o /etc/apt/keyrings/kitware-archive-keyring.gpg \
#   && echo "deb [signed-by=/etc/apt/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ $(. /etc/os-release && echo $UBUNTU_CODENAME) main" \
#      > /etc/apt/sources.list.d/kitware.list \
#   && apt-get update \
#   && apt-get install -y --no-install-recommends cmake \
#   && rm -rf /var/lib/apt/lists/*

# Install OR-Tools; see https://github.com/google/or-tools/blob/stable/cmake/README.md
RUN cd /root/ && git clone https://github.com/CraterGrader/or-tools.git \
  && cd or-tools && mkdir build \
  && cmake -S. -Bbuild -DBUILD_SAMPLES:BOOL=OFF -DBUILD_EXAMPLES:BOOL=OFF -DBUILD_DEPS:BOOL=ON -DUSE_COINOR:BOOL=OFF -DUSE_SCIP:BOOL=OFF -DUSE_PDLP:BOOL=ON \
  && cmake --build build \
  && cd build/ && make install \
  && cd /root/ \
  && rm -rf or-tools



# Setup Python environment
COPY docker/requirements.txt /root/requirements.txt


# Use the public PyPI unless you really need Jetson?s mirror for some package
ENV PIP_INDEX_URL=https://pypi.org/simple
# ENV PIP_EXTRA_INDEX_URL=


# Jetson/aarch64: install OpenCV from apt
RUN if [ "$(uname -m)" = "aarch64" ]; then \
      apt-get update && apt-get install -y --no-install-recommends python3-opencv && \
      rm -rf /var/lib/apt/lists/* ; \
    fi

RUN pip3 install --no-cache-dir -r /root/requirements.txt && rm -f /root/requirements.txt

# Prep for colcon build, but don't build anything yet
WORKDIR $WORKSPACE
COPY /src $WORKSPACE/src


# Make sure we have OpenCV headers from Jetson repo
# RUN apt-get update && apt-get install -y --no-install-recommends libopencv-dev

# Bring in source packages that otherwise come from apt and clash with OpenCV
WORKDIR $WORKSPACE/src
# cv_bridge
RUN git clone -b humble --depth 1 https://github.com/ros-perception/vision_opencv.git
# grid_map for ROS 2
RUN git clone -b ros2 --depth 1 https://github.com/ANYbotics/grid_map.git
# example_interfaces (to avoid apt fallback if your packages depend on it)
RUN git clone -b humble --depth 1 https://github.com/ros2/common_interfaces.git

WORKDIR $WORKSPACE
# Important: update apt before rosdep; skip OpenCV keys to avoid downgrades
RUN apt-get update \
 && rosdep update \
 && rosdep install --from-paths src --ignore-src -r -y --rosdistro $ROS_DISTRO \
      --skip-keys="opencv opencv4 libopencv-dev libopencv-core-dev libopencv-viz-dev" \
 && rm -rf /var/lib/apt/lists/*
# --------------------------------------------------------------------------------------

# -------------------------- Container entrypoint --------------------------------------
# Copy entrypoint script for workspace setup
RUN chmod +x /root/Lunar_ROADSTER/lr_ws/docker/lr_entrypoint.sh

# # Make entry
WORKDIR /root/Lunar_ROADSTER/lr_ws
ENTRYPOINT [ "/root/Lunar_ROADSTER/lr_ws/docker/lr_entrypoint.sh" ]
CMD [ "zsh", "-i" ]
# ---------------------------------------------------------------------------------------

