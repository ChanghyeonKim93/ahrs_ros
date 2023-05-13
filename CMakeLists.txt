cmake_minimum_required(VERSION 3.10)
project(ahrs)
message("   -- [PROJECT]: " ahrs)

find_package(catkin REQUIRED cmake_modules)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  sensor_msgs
  nav_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp
)

add_subdirectory(core)
add_subdirectory(ros1)
