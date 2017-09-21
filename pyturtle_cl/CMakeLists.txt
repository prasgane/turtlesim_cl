cmake_minimum_required(VERSION 2.8.3)
project(pyturtle_cl)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  rospy
  std_msgs
  turtlesim
)

catkin_package()

catkin_install_python(PROGRAMS
  src/turtle_cl_test.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
