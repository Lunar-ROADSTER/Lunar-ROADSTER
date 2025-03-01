# CMake generated Testfile for 
# Source directory: /home/williamfbx/Lunar-ROADSTER/lr_ws/src/drivers/kindr_ros/kindr_ros
# Build directory: /home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr_ros
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(kindr_ros-test "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr_ros/test_results/kindr_ros/kindr_ros-test.gtest.xml" "--package-name" "kindr_ros" "--output-file" "/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr_ros/ament_cmake_gtest/kindr_ros-test.txt" "--command" "/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr_ros/kindr_ros-test" "--gtest_output=xml:/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr_ros/test_results/kindr_ros/kindr_ros-test.gtest.xml")
set_tests_properties(kindr_ros-test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr_ros/kindr_ros-test" TIMEOUT "60" WORKING_DIRECTORY "/home/williamfbx/Lunar-ROADSTER/lr_ws/src/drivers/kindr_ros/kindr_ros/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/williamfbx/Lunar-ROADSTER/lr_ws/src/drivers/kindr_ros/kindr_ros/CMakeLists.txt;37;ament_add_gtest;/home/williamfbx/Lunar-ROADSTER/lr_ws/src/drivers/kindr_ros/kindr_ros/CMakeLists.txt;0;")
subdirs("gtest")
