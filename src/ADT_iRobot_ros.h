////////////////////////////////////////////////////////////////////////////////
/**
*	@file	ADT_iRobot_ros.h
*	@author	Mario Chirinos Colunga
*	@date	
*	@note	header template
*/
////////////////////////////////////////////////////////////////////////////////

#ifndef ADT_IROBOT_ROS_H
#define ADT_IROBOT_ROS_H

//------------------------------------------------------------------------------
#include <ros/ros.h>
#include "ADT_iRobot.h"
#include "adt_irobot_ros/iRobot_ros_move_service.h"
#include "adt_irobot_ros/status_msg.h"
//------------------------------------------------------------------------------
class ADT_iRobot_ros: public ADT_iRobot
{
 private:
	//ROS elements
	ros::NodeHandle nodeHandler;
	ros::Publisher statusPublisher;
	ros::ServiceServer moveService;
	
	//ROS callbacks
	bool moveService_callBack(adt_irobot_ros::iRobot_ros_move_service::Request  &req, adt_irobot_ros::iRobot_ros_move_service::Response &res);

	//Glib callbacks
	static int rosSpin_callback (void* userdata);
	static int sensorsTimer_callback (void* userdata);

 public:
 	ADT_iRobot_ros(const char* portName);

};
//------------------------------------------------------------------------------
#endif
