////////////////////////////////////////////////////////////////////////////////
/**
*	@file	ADT_iRobot_ros.cpp
*	@author	Mario Chirinos Colunga
*	@date	
*	@note	cpp template
*/
////////////////////////////////////////////////////////////////////////////////
#include "ADT_iRobot_ros.h"

#include <iostream>
#include <thread>

const char nSensorsToRead = 2;
char  sensorToReadIndex = 0;
const ADT_iRobot_SensorPackets sensorsToRead[nSensorsToRead]={ADT_iRobot_PACKETID_BATTERY_CHARGE,ADT_iRobot_PACKETID_BATTERY_CAPACITY};

using namespace std;
//------------------------------------------------------------------------------
/**
*	ADT_iRobot_ros constructor
*
*/
ADT_iRobot_ros::ADT_iRobot_ros(const char* portName):ADT_iRobot(portName)
{
	cout << "ADT_iRobot_ros" << endl; 
	statusPublisher = nodeHandler.advertise<adt_irobot_ros::status_msg>("adt_iRobot_status", 1);
	moveService = nodeHandler.advertiseService("adt_iRobot_move_service", &ADT_iRobot_ros::moveService_callBack, this);

	setMode(PASSIVE);
	setMode(FULL);

	g_timeout_add(50,rosSpin_callback, this);
	g_timeout_add(500,sensorsTimer_callback, this);
}
//------------------------------------------------------------------------------
bool ADT_iRobot_ros::moveService_callBack(adt_irobot_ros::iRobot_ros_move_service::Request  &req, adt_irobot_ros::iRobot_ros_move_service::Response &res)
{
	cout << "moveService_callBack" << endl;
	setMode(PASSIVE);
	setMode(FULL);
	cout << "speed: " << req.speed <<", radius: " << req.radius << endl;
	drive(req.speed, req.radius);

	res.status=1;
	return true;
}
//------------------------------------------------------------------------------
int ADT_iRobot_ros::rosSpin_callback (void* userdata)
{
//	cout << "rosSpin_callback" << endl;
	ros::spinOnce();
	return true;
}
//------------------------------------------------------------------------------
int ADT_iRobot_ros::sensorsTimer_callback (void* userdata)
{
//	cout << "sensorsTimer_callback" << endl;
	((ADT_iRobot_ros*)userdata)->getSensor(sensorsToRead[sensorToReadIndex]);
	sensorToReadIndex++;
	if(sensorToReadIndex>=nSensorsToRead)
		sensorToReadIndex=0;


	adt_irobot_ros::status_msg msg;
	msg.batteryCharge = ((ADT_iRobot_ros*)userdata)->sensors[ADT_iRobot_PACKETID_BATTERY_CHARGE];
	msg.batteryCapacity = ((ADT_iRobot_ros*)userdata)->sensors[ADT_iRobot_PACKETID_BATTERY_CAPACITY];
	((ADT_iRobot_ros*)userdata)->statusPublisher.publish(msg);
	return true;
}
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	if(argc < 0)
	{
		cerr << "too few arguments" << endl;
		return EXIT_FAILURE;
	}
	ros::init(argc, argv, "ADT_iRobot_ros");

	ADT_iRobot_ros iRobot("/dev/ttyUSB0");


	GMainLoop* main_loop = NULL;
	main_loop = g_main_loop_new (NULL, FALSE);

	//thread t(g_main_loop_run, main_loop);	
	//thread t(ros::spin);
	g_main_loop_run(main_loop);

	//ros::spin();

	//t.join();
 return 0;
}
//------------------------------------------------------------------------------

