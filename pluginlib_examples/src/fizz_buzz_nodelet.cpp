/*
 * fizz_buzz_nodelet.cpp
 * Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>
 */

#include <pluginlib_examples/fizz_buzz_nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <pluginlib/class_loader.h>

namespace pluginlib_examples {
  void FizzBuzzNodelet::onInit() {
    ros::NodeHandle& nh = getNodeHandle();
    ros::NodeHandle& pnh = getPrivateNodeHandle();

    std::vector<std::string> plugin_names;
    pnh.param<std::vector<std::string> >("plugins", plugin_names, std::vector<std::string>());

    pluginlib::ClassLoader<PluginBase> loader("pluginlib_examples", "pluginlib_examples::PluginBase");
    for (int i = 0; i < plugin_names.size(); ++i) {
      std::string plugin_name = plugin_names[i];
      try {
        NODELET_INFO_STREAM("loading plugin " << plugin_name);
        boost::shared_ptr<PluginBase> plugin = loader.createInstance(plugin_name);
        plugin->initialize();
        plugins_.push_back(plugin);
        NODELET_INFO_STREAM("plugin " << plugin_name << " initialized");
      } catch (const pluginlib::PluginlibException &e) {
        NODELET_ERROR_STREAM("Failed to load plugin " << plugin_name << ": " << e.what());
      }
    }

    count_sub_ = pnh.subscribe("count", 1, &FizzBuzzNodelet::onCount, this);
    NODELET_INFO_STREAM("nodelet initialized");
  }

  void FizzBuzzNodelet::onCount(const std_msgs::Int32::ConstPtr &msg) {
    int counter = msg->data;
    std::ostringstream ss;
    ss << counter << ": ";
    for (int i = 0; i < plugins_.size(); ++i) {
      ss << plugins_[i]->trigger(counter);
    }
    NODELET_WARN_STREAM(ss.str());
  }

  PLUGINLIB_DECLARE_CLASS(pluginlib_examples, FizzBuzzNodelet, pluginlib_examples::FizzBuzzNodelet, nodelet::Nodelet);
}

