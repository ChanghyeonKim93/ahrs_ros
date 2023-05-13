set(CMAKE_BUILD_TYPE Release) # Release, RelWithDebInfo
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -pg -O2")
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}) 

find_package(Eigen3 REQUIRED)

include_directories( ${Eigen3_INCLUDE_DIRS} )
include_directories( ${CMAKE_SOURCE_DIR} )

set(SRC ${SRC} 
  ahrs.cpp
)

# executables
add_library(${CMAKE_PROJECT_NAME}_core STATIC ${SRC})
target_link_libraries(${CMAKE_PROJECT_NAME}_core ${Eigen3_LIBRARIES})
install(TARGETS ${CMAKE_PROJECT_NAME}_core 
  DESTINATION lib/${CMAKE_PROJECT_NAME}
  CONFIGURATIONS Release)
