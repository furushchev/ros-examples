/*
 * fizz_buzz_node.cpp
 * Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>
 */

#include <ros/ros.h>
#include <nodelet/loader.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "fizz_buzz");

  nodelet::Loader loader;
  nodelet::M_string remap(ros::names::getRemappings());
  nodelet::V_string nargv;

  loader.load(ros::this_node::getName(),
              "pluginlib_examples/FizzBuzz",
              remap, nargv);

  ros::spin();

  return 0;
}
