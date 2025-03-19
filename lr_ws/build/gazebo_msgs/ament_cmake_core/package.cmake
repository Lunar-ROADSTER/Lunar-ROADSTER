set(_AMENT_PACKAGE_NAME "gazebo_msgs")
set(gazebo_msgs_VERSION "3.9.0")
set(gazebo_msgs_MAINTAINER "Jose Luis Rivero <jrivero@osrfoundation.org>, Louise Poubel <louise@openrobotics.org>")
set(gazebo_msgs_BUILD_DEPENDS "builtin_interfaces" "geometry_msgs" "trajectory_msgs" "std_msgs")
set(gazebo_msgs_BUILDTOOL_DEPENDS "ament_cmake" "rosidl_default_generators")
set(gazebo_msgs_BUILD_EXPORT_DEPENDS )
set(gazebo_msgs_BUILDTOOL_EXPORT_DEPENDS )
set(gazebo_msgs_EXEC_DEPENDS "rosidl_default_runtime" "builtin_interfaces" "geometry_msgs" "trajectory_msgs" "std_msgs")
set(gazebo_msgs_TEST_DEPENDS "ament_lint_common")
set(gazebo_msgs_GROUP_DEPENDS )
set(gazebo_msgs_MEMBER_OF_GROUPS "rosidl_interface_packages")
set(gazebo_msgs_DEPRECATED "This package has been deprecated as of January 2025 with Gazebo classic 11 reaching
      end-of-life. Users are highly encouraged to migrate to the new Gazebo
      using our migration guides (https://gazebosim.org/docs/latest/gazebo_classic_migration)")
set(gazebo_msgs_EXPORT_TAGS)
list(APPEND gazebo_msgs_EXPORT_TAGS "<build_type>ament_cmake</build_type>")
list(APPEND gazebo_msgs_EXPORT_TAGS "<ros1_bridge mapping_rules=\"gazebo_msgs_mapping_rules.yaml\"/>")
list(APPEND gazebo_msgs_EXPORT_TAGS "<deprecated>This package has been deprecated as of January 2025 with Gazebo classic 11 reaching
      end-of-life. Users are highly encouraged to migrate to the new Gazebo
      using our migration guides (https://gazebosim.org/docs/latest/gazebo_classic_migration)</deprecated>")
