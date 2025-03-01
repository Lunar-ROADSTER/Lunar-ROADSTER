# CMake generated Testfile for 
# Source directory: /home/williamfbx/Lunar-ROADSTER/lr_ws/src/drivers/kindr/test
# Build directory: /home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_kindr "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr/test_results/kindr/test_kindr.gtest.xml" "--package-name" "kindr" "--output-file" "/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr/ament_cmake_gtest/test_kindr.txt" "--command" "/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr/test/test_kindr" "--gtest_output=xml:/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr/test_results/kindr/test_kindr.gtest.xml")
set_tests_properties(test_kindr PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr/test/test_kindr" TIMEOUT "60" WORKING_DIRECTORY "/home/williamfbx/Lunar-ROADSTER/lr_ws/build/kindr/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/williamfbx/Lunar-ROADSTER/lr_ws/src/drivers/kindr/test/CMakeLists.txt;170;ament_add_gtest;/home/williamfbx/Lunar-ROADSTER/lr_ws/src/drivers/kindr/test/CMakeLists.txt;0;")
subdirs("../gtest")
