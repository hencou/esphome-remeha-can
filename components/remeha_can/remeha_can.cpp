#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "esphome.h"
#include "remeha_can.h"
#include "esphome/core/log.h"

std::string uint8_vector_to_hex_string(const std::vector<uint8_t>& v) {
  std::stringstream ss;
  ss << std::hex << std::setfill('0');
  std::vector<uint8_t>::const_iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    ss << std::setw(2) << static_cast<unsigned>(*it);
  }
  return ss.str();
}

namespace esphome {
namespace remeha_can {

void RemehaCAN::set_canbus(canbus::Canbus *canbus) {
  this->canbus_ = canbus;

  // Set up trigger for CAN bus component
  canbus::CanbusTrigger *trigger = new canbus::CanbusTrigger(canbus, 0, 0, false);
  trigger->set_component_source("canbus");
  App.register_component(trigger);

  // Create automation to trigger on frames.
  Automation<std::vector<uint8_t>, uint32_t, bool> *automation = new Automation<std::vector<uint8_t>, uint32_t, bool>(trigger);

  auto callback = [this](std::vector<uint8_t> x, uint32_t can_id, bool remote_transmission_request) -> void {
    this->on_frame(can_id, remote_transmission_request, x);
  };

  LambdaAction<std::vector<uint8_t>, uint32_t, bool> *lambdaaction = new LambdaAction<std::vector<uint8_t>, uint32_t, bool>(callback);
  automation->add_actions({ lambdaaction });
}

void RemehaCAN::on_frame(uint32_t can_id, bool rtr, std::vector<uint8_t>& data) {
  if (this->log_frames_) {
    ESP_LOGI(TAG, "can_id=0x%04x rtr=%u size=%u data=%s", can_id, rtr, data.size(), uint8_vector_to_hex_string(data).c_str());
  }
}

} // namespace remeha_can
} // namespace esphome
