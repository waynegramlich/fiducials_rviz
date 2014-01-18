cmake_minimum_required(VERSION 2.8.3)
project(fiducials_rviz)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  visualization_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES fiducials_rviz
  CATKIN_DEPENDS roscpp visualization_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp library
add_library(fiducials_rviz src/fiducials_rviz.cpp)
target_link_libraries(fiducials_rviz ${catkin_LIBRARIES})

## Declare a cpp executable

add_executable(test2 test.c)
target_link_libraries(test2 fiducials_rviz ${catkin_LIBRARIES})


#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executables and/or libraries for installation
install(TARGETS test2
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
