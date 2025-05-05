#pragma once

#include "esphome/components/canbus/canbus.h"
#include "esphome/core/component.h"
#include "remeha-can.h"

namespace esphome {
namespace remeha_can {

using namespace remeha_can_lib;

class RemehaCAN: public Component {
  protected:
    bool                          log_frames_ = false;
    uint32_t                      node_id_;
    canbus::Canbus                *canbus_ = nullptr;
    std::unique_ptr<FrameHandler> frame_handler_;

  public:
    explicit RemehaCAN(uint32_t node_id) : node_id_(node_id) {
      this->frame_handler_ = std::make_unique<FrameHandler>([](const std::string& s) {
      });
    }

    void set_canbus(canbus::Canbus *canbus);
    void on_frame(uint32_t can_id, bool rtr, std::vector<uint8_t> &data);
    void set_log_frames(bool log_frames) {
      this->log_frames_ = log_frames;
    }
};

}  // namespace remeha_can
}  // namespace esphome
