set(CMAKE_BUILD_TYPE Release) # Release, RelWithDebInfo
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -pg -O2")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}) 

find_package(catkin REQUIRED cmake_modules)
find_package(Eigen3 REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
  sensor_msgs
  nav_msgs
)

set(SRC ${SRC}
  ahrs_ros.cpp
)

include_directories( ${catkin_INCLUDE_DIRS} )
include_directories( ${CMAKE_SOURCE_DIR} )
include_directories( ${Eigen3_INCLUDE_DIRS} )

# executables
add_executable(ahrs_node node_ahrs.cpp ${SRC})
target_link_libraries (ahrs_node ahrs_core ${catkin_LIBRARIES} ${Eigen3_LIBRARIES})