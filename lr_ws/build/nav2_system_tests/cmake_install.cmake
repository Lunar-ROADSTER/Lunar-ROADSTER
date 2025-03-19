# Install script for directory: /root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_system_tests

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/root/Lunar_ROADSTER/lr_ws/install/nav2_system_tests")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests" TYPE DIRECTORY FILES "/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_system_tests/maps")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/nav2_system_tests")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/nav2_system_tests")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests/environment" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests/environment" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_index/share/ament_index/resource_index/packages/nav2_system_tests")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests/cmake" TYPE FILE FILES
    "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_core/nav2_system_testsConfig.cmake"
    "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/ament_cmake_core/nav2_system_testsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/nav2_system_tests" TYPE FILE FILES "/root/Lunar_ROADSTER/lr_ws/src/navigation2/nav2_system_tests/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/behavior_tree/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/planning/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/localization/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/system/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/system_failure/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/updown/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/waypoint_follower/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/behaviors/spin/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/behaviors/wait/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/behaviors/backup/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/behaviors/drive_on_heading/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/behaviors/assisted_teleop/cmake_install.cmake")
  include("/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/src/costmap_filters/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/root/Lunar_ROADSTER/lr_ws/build/nav2_system_tests/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
