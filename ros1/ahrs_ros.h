#ifndef _AHRS_ROS_H_
#define _AHRS_ROS_H_
#include <iostream>
#include <ros/ros.h>

class AHRSROS
{
public:
	AHRSROS(const ros::NodeHandle& nh);
  ~AHRSROS();

private:
  void run();

private:
  ros::NodeHandle nh_;
};

#endif
