#pragma once

#define TAG "RemehaCAN"

#include "esphome/components/canbus/canbus.h"
#include "esphome/core/component.h"

namespace esphome {
namespace remeha_can {

class RemehaCAN: public Component {
 protected:
  bool           log_frames_ = false;
  uint32_t       node_id_;
  canbus::Canbus *canbus_;

 public:
  RemehaCAN(uint32_t node_id) : node_id_(node_id) {};
  void set_canbus(canbus::Canbus *canbus);
  void on_frame(uint32_t can_id, bool rtr, std::vector<uint8_t> &data);
  void set_log_frames(bool log_frames) {
    this->log_frames_ = log_frames;
  }
};

}  // namespace remeha_can
}  // namespace esphome
