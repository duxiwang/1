#ifndef KINEMATIC_DECOMPOSITON_H
#define KINEMATIC_DECOMPOSITON_H

#include <ros/ros.h>
#include <std_msgs/String.h> // 根据yolov8话题的消息类型进行修改

namespace ht_driver{

class KinematicDecompositon {
public:
    KinematicDecompositon(ros::NodeHandle nh); // 修改构造函数以接收一个NodeHandle
    ~KinematicDecompositon();
    void weedCallback(const std_msgs::String::ConstPtr& msg); // 添加回调函数的声明

private:
    ros::Subscriber weed_subscriber_; // 添加订阅者的声明
};

}//namespace ht_driver

#endif