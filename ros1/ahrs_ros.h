#ifndef _AHRS_ROS_H_
#define _AHRS_ROS_H_
#include <iostream>
#include <exception>
#include <string>

#include <ros/ros.h>
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/MagneticField.h"
#include "nav_msgs/Odometry.h"

class AHRSROS
{
public:
	AHRSROS(const ros::NodeHandle& nh);
  ~AHRSROS();

private:
  void run();

  void getParameters();

  void callbackIMU(const sensor_msgs::ImuConstPtr& msg);
  void callbackMagnetometer(const sensor_msgs::MagneticFieldConstPtr& msg);

private:
  ros::NodeHandle nh_;

// Subscribers
private:
  ros::Subscriber sub_imu_;
  std::string topicname_imu_;

  ros::Subscriber sub_mag_;
  std::string topicname_mag_;

// Publisher
private:
  ros::Publisher pub_filtered_pose_;
  std::string topicname_filtered_pose_;

};

#endif
