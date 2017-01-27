/*
 * plugin_buzz.h
 * Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>
 */

#ifndef PLUGIN_BUZZ_H__
#define PLUGIN_BUZZ_H__

#include <pluginlib_examples/plugin_base.h>

namespace pluginlib_examples {
  class PluginBuzz : public PluginBase {
  public:
    PluginBuzz(){};
    ~PluginBuzz(){};
    void initialize();
    std::string trigger(const int &msg);
  };
}

#endif // PLUGIN_BUZZ_H__
