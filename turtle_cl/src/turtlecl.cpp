#include "turtle_cl/turtlecl.h"

namespace turtle_cl
{
  turtleCL::turtleCL() :
    nh_(ros::NodeHandle()),
    nh_private_(ros::NodeHandle("~"))
  {

    pose_subscriber_ = nh_.subscribe<turtlesim::Pose>
                        ("/turtle1/pose",10, &turtleCL::poseCallback, this);

    vel_publisher_ = nh_.advertise<geometry_msgs::Twist>
                        ("/turtle1/cmd_vel",10,this);

    nh_private_.param<float>("p_gain_linear",k_p_lin,0.1);
    nh_private_.param<float>("p_gain_ang",k_p_ang,0.1);
    nh_private_.param<float>("tolerance",tol,0.1);
    nh_private_.param<float>("xGoal",goal_x,1);
    nh_private_.param<float>("yGoal",goal_y,1);
    mag = 10;
  }

  void turtleCL::poseCallback(const turtlesim::PoseConstPtr &msg)
  {
    current_pose = *msg;
    float mag1, mag2;
    mag1 = pow((goal_x - msg->x),2);
    mag2 = pow((goal_y - msg->y),2);
    mag = sqrt(mag1 + mag2);
    ROS_INFO("in callback");
    // if(mag >= tol)
    //   velocity_calc();

  }

  void turtleCL::velocity_calc()
  {
    while(mag >= tol)
    {
      ROS_INFO("in velocity_cal %f",mag);
      float velx,angx,angy;
      angx = goal_x - current_pose.x;
      angy = goal_y - current_pose.y;
      cmd_vel.linear.x = k_p_lin * mag;
      cmd_vel.angular.z = k_p_ang * atan2(angy,angx) - current_pose.theta;
      vel_publisher_.publish(cmd_vel);
      ros::spinOnce();
    }
    //ROS_INFO("in while %f",current_pose.x);

  }

}
