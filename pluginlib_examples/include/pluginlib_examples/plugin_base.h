/*
 * plugin_base.h
 * Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>
 */

#ifndef PLUGIN_BASE_H__
#define PLUGIN_BASE_H__

#include <string>
#include <ros/ros.h>

namespace pluginlib_examples {
  class PluginBase {
  public:
    virtual ~PluginBase(){};
    virtual void initialize() = 0;
    virtual std::string trigger(const int &msg) = 0;
  protected:
    PluginBase(){};
  };
}

#endif // PLUGIN_BASE_H__
