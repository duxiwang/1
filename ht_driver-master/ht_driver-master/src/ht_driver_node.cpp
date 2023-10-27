#include <ros/ros.h>
#include <std_msgs/String.h> // 根据yolov8话题的消息类型进行修改
#include <signal.h>
#include "ht_driver/ht_driver.h"

using namespace ht_driver;

bool signal_track = true;

void UserSignalHandler(int sig);

// 创建一个订阅者
ros::Subscriber weed_subscriber;

// 创建一个回调函数
void weedCallback(const std_msgs::String::ConstPtr& msg)
{
    // 在这里处理杂草的信息，并将其发送到STM32
    // 你需要根据你的具体情况来实现这个函数
}

int main(int argc, char** argv){
    ros::init(argc, argv, "ht_driver");
    signal(SIGINT, UserSignalHandler);
    ros::AsyncSpinner spinner(4);
    spinner.start();

    ros::NodeHandle nh;

    // 初始化订阅者
    weed_subscriber = nh.subscribe("yolov8", 1000, weedCallback);

    boost::shared_ptr<HtDriver> htdriver;
    htdriver = boost::make_shared<HtDriver>(nh);

    htdriver->DataReceive();
    htdriver->DataReSend();
    htdriver->DataSend();
    htdriver->OdomCalucation();

    int rate;
    ros::param::param<int>("~rate", rate, 1);
    ros::Rate loop_dynamic_rate(rate);
    while (ros::ok() && signal_track ==true)
    {
        loop_dynamic_rate.sleep();
    }
    spinner.stop();
    ros::waitForShutdown();
        
    return 0;
}

void UserSignalHandler(int sig){
    signal_track = false;
    ros::NodeHandle nh;
    ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    geometry_msgs::Twist robot_stop_command;
    robot_stop_command.linear.x = 0.0;
    robot_stop_command.linear.y = 0.0;
    robot_stop_command.linear.z = 0.0;
    robot_stop_command.angular.x = 0.0;
    robot_stop_command.angular.y = 0.0;
    robot_stop_command.angular.z = 0.0;
    cmd_vel_pub.publish(robot_stop_command);
    ros::shutdown();
}