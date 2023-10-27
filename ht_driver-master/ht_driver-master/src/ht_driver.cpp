/*
 * @Descripttion: 
 * @version: 
 * @Author: Nova Wu
 * @Date: 2021-09-24 09:50:36
 * @LastEditors: Nova Wu
 * @LastEditTime: 2021-09-24 16:16:03
 */
#include "ht_driver/ht_driver.h"

namespace ht_driver{

HtDriver::HtDriver(ros::NodeHandle nh)
{
    // 初始化订阅者
    weed_subscriber_ = nh.subscribe("yolov8", 1000, &HtDriver::weedCallback, this);
}

void HtDriver::weedCallback(const std_msgs::String::ConstPtr& msg) // 添加一个回调函数
{
    // 在这里处理杂草的信息，并将其发送到STM32
    // 你需要根据你的具体情况来实现这个函数
}

// 其他代码...

}//namespace ht_driver