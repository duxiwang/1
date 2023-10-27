#include "ht_driver/transport_serial.h"

namespace ht_driver{

TransportSerial::TransportSerial(): Transport("uart_com:/dev/ttyUSB0")
{
    params_.serial_port_ = "/dev/ttyUSB0";
    // 初始化发布者
    weed_publisher_ = nh.advertise<std_msgs::String>("weed_info", 1000); // 根据你的需求修改话题名和消息类型
}

// 其他代码...

}//namespace ht_driver