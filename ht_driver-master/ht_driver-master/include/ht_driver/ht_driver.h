#ifndef HT_DRIVER_H
#define HT_DRIVER_H

#include <ros/ros.h>
#include <std_msgs/String.h> // 根据yolov8话题的消息类型进行修改

namespace ht_driver{

class HtDriver
{
public:
    HtDriver(ros::NodeHandle nh);
    ~HtDriver();
    void OdomCalucation();
    void DataReceive();
    void DataSend();
    void DataReSend();
    void weedCallback(const std_msgs::String::ConstPtr& msg); // 添加一个回调函数

private:
    void OdomCalucationImpl();
    void DataReceiveImpl();
    void DataSendImpl();
    void DataReSendImpl();
    ros::Subscriber weed_subscriber_; // 添加一个订阅者
};

}//namespace ht_driver

#endif