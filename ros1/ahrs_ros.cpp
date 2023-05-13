#include "ahrs_ros.h"

AHRSROS::AHRSROS(const ros::NodeHandle& nh)
: nh_(nh)
{
  ROS_INFO_STREAM("AHRSROS is constructed.");

  // Get ROS parameters from launch file
  this->getParameters();

  // AHRS object
  ahrs_ = std::make_unique<AHRS>();

  // Subscribers
  sub_imu_ = nh_.subscribe<sensor_msgs::Imu>
    (topicname_imu_, 5, &AHRSROS::callbackIMU, this);
  sub_mag_ = nh_.subscribe<sensor_msgs::MagneticField>
    (topicname_mag_, 5, &AHRSROS::callbackMagnetometer, this);

  // Publisher
  pub_filtered_pose_ = nh_.advertise<nav_msgs::Odometry>
    (topicname_filtered_pose_, 1);

  this->run();
}

AHRSROS::~AHRSROS()
{
  ROS_INFO_STREAM("AHRSROS is destructed.");
}

void AHRSROS::run()
{
  ROS_INFO_STREAM("AHRSROS node runs at 2000 Hz");
  ros::Rate rate(2000);
  while(ros::ok())
  {
    ros::spinOnce();
    rate.sleep();
  }
}

void AHRSROS::getParameters()
{
  if(!ros::param::has("~topicname_imu")) 
    throw std::runtime_error("In 'AHRSROS::getParameters()', '~topicname_imu' is not set.");
  ros::param::get("~topicname_imu", topicname_imu_);

  if(!ros::param::has("~topicname_mag")) 
    throw std::runtime_error("In 'AHRSROS::getParameters()', '~topicname_mag' is not set.");
  ros::param::get("~topicname_mag", topicname_mag_);
}

void AHRSROS::callbackIMU(const sensor_msgs::ImuConstPtr& msg)
{
  double time_curr = msg->header.stamp.toSec();
}

void AHRSROS::callbackMagnetometer(const sensor_msgs::MagneticFieldConstPtr& msg)
{
  double time_curr = msg->header.stamp.toSec();
}
