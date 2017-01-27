/*
 * plugin_fizz.cpp
 * Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>
 */

#include <pluginlib/class_list_macros.h>
#include <pluginlib_examples/plugin_fizz.h>

namespace pluginlib_examples {
  void PluginFizz::initialize() {
    ROS_INFO("Fizz initialize called");
  }

  std::string PluginFizz::trigger(const int &msg) {
    ROS_DEBUG_STREAM("Fizz received " << msg);
    if (msg % 3 == 0) return "fizz";
    else return "";
  }
}

PLUGINLIB_EXPORT_CLASS(pluginlib_examples::PluginFizz, pluginlib_examples::PluginBase);
