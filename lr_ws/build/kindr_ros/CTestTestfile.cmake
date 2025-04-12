# CMake generated Testfile for 
# Source directory: /root/Lunar_ROADSTER/lr_ws/src/drivers/kindr_ros/kindr_ros
# Build directory: /root/Lunar_ROADSTER/lr_ws/build/kindr_ros
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(kindr_ros-test "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/root/Lunar_ROADSTER/lr_ws/build/kindr_ros/test_results/kindr_ros/kindr_ros-test.gtest.xml" "--package-name" "kindr_ros" "--output-file" "/root/Lunar_ROADSTER/lr_ws/build/kindr_ros/ament_cmake_gtest/kindr_ros-test.txt" "--command" "/root/Lunar_ROADSTER/lr_ws/build/kindr_ros/kindr_ros-test" "--gtest_output=xml:/root/Lunar_ROADSTER/lr_ws/build/kindr_ros/test_results/kindr_ros/kindr_ros-test.gtest.xml")
set_tests_properties(kindr_ros-test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/root/Lunar_ROADSTER/lr_ws/build/kindr_ros/kindr_ros-test" TIMEOUT "60" WORKING_DIRECTORY "/root/Lunar_ROADSTER/lr_ws/src/drivers/kindr_ros/kindr_ros/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/root/Lunar_ROADSTER/lr_ws/src/drivers/kindr_ros/kindr_ros/CMakeLists.txt;37;ament_add_gtest;/root/Lunar_ROADSTER/lr_ws/src/drivers/kindr_ros/kindr_ros/CMakeLists.txt;0;")
subdirs("gtest")
