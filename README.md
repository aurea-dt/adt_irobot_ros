# adt_irobot_ros
This code provides a ROS node to control the iRobot create 2 platform in the form of a C++ object
 ADT_iRobot_ros. 
ADT_iRobot_ros is a derived class of [ADT_iRobot](https://github.com/aurea-dt/ADT_iRobot) 
which contains all the actual functionality to control the iRobot create 2. The 
derived class only contains the ROS related functionality, messages, topics and services.
This result in a compact and easy to read code.

## ROS elements
### Topics
The values of the iRobot sensors are published through the topic __adt_iRobot_status__.

### Services
To control the iRobot movements the service __adt_iRobot_move_service__ enable to request
a change in velocity and turn radius.
###Spin
Becuase the events on the parent class ADT_iRobot are managed by glib main loop 
the code uses __ros::spinOnce()__ instead of ros::spin().

# Compiling
## Dependencies
To compile the code you will need glib develpment package __libglib2.0-dev__ .
``` bash
$ sudo apt-get install libglib2.0-dev
```

##ROS version
This code is a catkin package developed under __ROS indigo__ and __Ubuntu 14.04.4 LTS__.


## Compile
``` bash
$ cd your_catkin_workspace
$ cd src
$ git clone https://github.com/aurea-dt/adt_irobot_ros.git
$ cd ..
$ catkin_make_isolated --install --source src/adt_irobot_ros/
```
