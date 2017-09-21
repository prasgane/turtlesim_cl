cmake_minimum_required(VERSION 2.8.3)
project(turtle_cl)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  turtlesim
)

catkin_package()

include_directories(include)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_cl_node
              src/turtlecl_node.cpp
              src/turtlecl.cpp)

target_link_libraries(turtle_cl_node
                ${catkin_LIBRARIES}
                )
