/*
 * plugin_fizz.h
 * Author: Yuki Furuta <furushchev@jsk.imi.i.u-tokyo.ac.jp>
 */

#ifndef PLUGIN_FIZZ_H__
#define PLUGIN_FIZZ_H__

#include <pluginlib_examples/plugin_base.h>

namespace pluginlib_examples {
  class PluginFizz: public PluginBase {
  public:
    PluginFizz(){};
    ~PluginFizz(){};
    void initialize();
    std::string trigger(const int &msg);
  };
}

#endif // PLUGIN_FIZZ_H__
