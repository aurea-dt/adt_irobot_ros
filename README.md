# adt_irobot_ros
This code provides a ROS node to control the iRobot create 2 platform in the form of a C++ object
 ADT_iRobot_ros. 
ADT_iRobot_ros is a derived class of [ADT_iRobot](https://github.com/aurea-dt/ADT_iRobot) 
which contains all the actual functionality to control the iRobot create 2. The 
derived class only contains the ROS related functionality, messages, topics and services. 

##ROS elements


#Compiling
##Prerequisites
To compile the code you will need glib develpment package libglib2.0-dev .
``` bash
$ sudo apt-get install libglib2.0-dev
```

##ROS version
This code is a catkin package developed under ROS indigo and Ubuntu 14.04.4 LTS.


##Compile
``` bash
$ cd your_catkin_workspace
$ cd src
$ git clone https://github.com/aurea-dt/adt_irobot_ros.git
$ catkin_make_isolated --install --source src/adt_irobot_ros/
```
