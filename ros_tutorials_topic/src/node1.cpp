#include "ros/ros.h"                            
#include "ros_tutorials_topic/MsgTutorial.h"    

// msgCallback 함수, subsrcirber에 입력된 msg 정보 불러오기
void msgCallback(const ros_tutorials_topic::MsgTutorial::ConstPtr& msg)
{
  ROS_INFO("recieve node2_msg = %d", (msg->data));        
}


int main(int argc, char **argv)                 
{
  // Node와 NodeHande 설정
  ros::init(argc, argv, "node1");     
  ros::NodeHandle nh;                           

  
  // Publisher, Subscriber 생성
  ros::Publisher ros_tutorial_pub = nh.advertise<ros_tutorials_topic::MsgTutorial>("msg_send", 100);
  ros::Subscriber ros_tutorial_sub = nh.subscribe("msg_receive", 100, msgCallback);

  // loop sleep 조절, msg_send 생성
  ros::Rate loop_rate(10);
  ros_tutorials_topic::MsgTutorial msg_send;     

  
  int count = 0;                            

  while (ros::ok())
  {
    // msg_send 변수 설정        
    msg_send.data  = count;

    // 변수 출력                      
    ROS_INFO("send node1_msg = %d", msg_send.data);        

    // 변수 업데이트
    ros_tutorial_pub.publish(msg_send);          

    // 루프 시간 조절
    loop_rate.sleep();                     

    // msgCallback 실행 대기
    ros::spinOnce();

    ++count;
  }

  return 0;
}
