/*
 * fizz_buzz_nodelet.h
 * Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>
 */

#ifndef FIZZ_BUZZ_NODELET_H__
#define FIZZ_BUZZ_NODELET_H__

#include <boost/shared_ptr.hpp>
#include <nodelet/nodelet.h>
#include <sstream>
#include <std_msgs/Int32.h>
#include <string>
#include <vector>
#include <pluginlib_examples/plugin_base.h>

namespace pluginlib_examples {
  class FizzBuzzNodelet: public nodelet::Nodelet {
    std::vector< boost::shared_ptr<PluginBase> > plugins_;
    ros::Subscriber count_sub_;
  protected:
    virtual void onInit();
    virtual void onCount(const std_msgs::Int32::ConstPtr &msg);
  };
}

#endif // FIZZ_BUZZ_NODELET_H__
