/*
 * plugin_buzz.cpp
 * Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>
 */

#include <pluginlib/class_list_macros.h>
#include <pluginlib_examples/plugin_buzz.h>

namespace pluginlib_examples {
  void PluginBuzz::initialize() {
    ROS_INFO("Buzz initialize called");
  }

  std::string PluginBuzz::trigger(const int &msg) {
    ROS_DEBUG_STREAM("Buzz received: " << msg);
    if (msg % 5 == 0) return "buzz";
    else return "";
  }
}

PLUGINLIB_EXPORT_CLASS(pluginlib_examples::PluginBuzz, pluginlib_examples::PluginBase);
