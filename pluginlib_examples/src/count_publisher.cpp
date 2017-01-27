/*
 * count_publisher.cpp
 * Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>
 */

#include <ros/ros.h>
#include <std_msgs/Int32.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "count_publisher");

  int count = 0;

  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::Int32>("counter", 1);

  ros::Rate r(1.0);
  while (ros::ok()) {
    std_msgs::Int32 msg;
    msg.data = count++;
    pub.publish(msg);
    ros::spinOnce();
    r.sleep();
  }

  return 0;
}
