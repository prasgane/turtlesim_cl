#ifndef TURTLECL_H
#define TURTLECL_H

#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

namespace turtle_cl
{
  class turtleCL
  {

  public:
    turtleCL();
    void velocity_calc();
    


  private:
    ros::NodeHandle nh_;
    ros::NodeHandle nh_private_;

    ros::Subscriber pose_subscriber_;
    ros::Publisher vel_publisher_;

    void poseCallback(const turtlesim::PoseConstPtr &msg);


    turtlesim::Pose current_pose;
    geometry_msgs::Twist cmd_vel;

    float k_p_lin, k_p_ang, tol, goal_x, goal_y, mag;
  };

}
#endif
