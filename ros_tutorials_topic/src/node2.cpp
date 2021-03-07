#include "ros/ros.h"                         
#include "ros_tutorials_topic/MsgTutorial.h"  

// Callback 함수에서 subscriber의 정보를 new_msg에 저장
double new_msg;
void msgCallback(const ros_tutorials_topic::MsgTutorial::ConstPtr& msg)
{
  ROS_INFO("recieve node1_msg = %d", (msg->data));        
  new_msg = msg ->data;
}


int main(int argc, char **argv)                         
{
  ros::init(argc, argv, "node2");           
  ros::NodeHandle nh;                                   

  ros::Publisher ros_tutorial_pub = nh.advertise<ros_tutorials_topic::MsgTutorial>("msg_receive", 100);
  ros::Subscriber ros_tutorial_sub = nh.subscribe("msg_send", 100, msgCallback);

  ros_tutorials_topic::MsgTutorial msg_receive;   
  ros::Rate loop_rate(10);

  
  while (ros::ok())
  {
    // msg_send = new_msg
    // msg_receive = new_send * 3 구현
    msg_receive.data  = new_msg*3 ;               

    // 출력과 저장       
    ROS_INFO("send node2_msg = %d", msg_receive.data);     
    ros_tutorial_pub.publish(msg_receive);        


    loop_rate.sleep();                      

    ros::spinOnce();
  }

  return 0;
}
