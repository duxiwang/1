/*
 * @Descripttion: 
 * @version: 
 * @Author: Nova Wu
 * @Date: 2021-09-24 10:59:26
 * @LastEditors: Nova Wu
 * @LastEditTime: 2021-09-24 10:59:27
 */
#include "ht_driver/kinematic_decompositon.h"
#include <std_msgs/String.h> // 根据yolov8话题的消息类型进行修改

namespace ht_driver{

KinematicDecompositon::KinematicDecompositon(ros::NodeHandle nh) // 修改构造函数以接收一个NodeHandle
{
    // 初始化订阅者
    weed_subscriber_ = nh.subscribe("yolov8", 1000, &KinematicDecompositon::weedCallback, this);
}

void KinematicDecompositon::weedCallback(const std_msgs::String::ConstPtr& msg) // 添加一个回调函数
{
    // 在这里处理杂草的信息，并将其发送到STM32
    // 你需要根据你的具体情况来实现这个函数
}

KinematicDecompositon::~KinematicDecompositon()
{
}

}//namespace ht_driver