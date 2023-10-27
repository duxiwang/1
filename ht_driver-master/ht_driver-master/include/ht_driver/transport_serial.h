#ifndef TRANSPORT_SERIAL_H
#define TRANSPORT_SERIAL_H

#include <ros/ros.h>
#include <std_msgs/String.h> // 根据你的需求修改消息类型

namespace ht_driver{

class TransportSerial : public Transport {
public:
    TransportSerial();
    TransportSerial(std::string url, unsigned int baurate);
    ~TransportSerial();

private:
    ros::Publisher weed_publisher_; // 添加发布者的声明
    // 其他代码...
};

}//namespace ht_driver

#endif