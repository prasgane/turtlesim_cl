#include <ros/ros.h>
#include <turtle_cl/turtlecl.h>


int main(int argc, char** argv)
{
  ros::init(argc,argv,"turtle_cl_node");
  ros::NodeHandle nh;

  turtle_cl::turtleCL hello;


  hello.velocity_calc();

  ros::spin();
}
