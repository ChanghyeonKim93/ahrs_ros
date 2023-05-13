#include "ahrs_ros.h"

AHRSROS::AHRSROS(const ros::NodeHandle& nh)
: nh_(nh)
{
  ROS_INFO_STREAM("AHRSROS is constructed.");

  this->run();
}

AHRSROS::~AHRSROS()
{
  ROS_INFO_STREAM("AHRSROS is destructed.");
}

void AHRSROS::run()
{
  ROS_INFO_STREAM("AHRSROS node runs at 5,000 Hz");
  ros::Rate rate(5000);
  while(ros::ok())
  {
    ros::spinOnce();
    rate.sleep();
  }
}