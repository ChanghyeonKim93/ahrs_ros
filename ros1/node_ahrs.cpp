#include <iostream>
#include <exception>
#include <memory>

#include <ros/ros.h>

#include "ahrs_ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "ahrs_node", ros::init_options::NoSigintHandler);
  // ros::init(argc, argv, "ahrs_node");

  ros::NodeHandle nh("~");
  ROS_INFO_STREAM("ahrs_node - STARTS.");

	try{
		if(ros::ok()){
			std::unique_ptr<AHRSROS> ahrs_ros;
			ahrs_ros = std::make_unique<AHRSROS>(nh);			
		}
		else throw std::runtime_error("ROS not ok");
	}
	catch (std::exception& e){
        ROS_ERROR(e.what());

	}
	ROS_INFO_STREAM("ahrs_node - TERMINATED.");
	return 0;
}