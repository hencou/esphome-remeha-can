#pragma once

#include "esphome/core/component.h"
#include "esphome/components/canbus/canbus.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "remeha-can.h"

namespace esphome {
namespace remeha_can {

using namespace remeha_can_lib;
using sensor::Sensor;
using text_sensor::TextSensor;

using SensorMap     = std::map<std::string, Sensor*>;
using TextSensorMap = std::map<std::string, TextSensor*>;

class RemehaCAN: public Component {
  protected:
    bool                          log_frames_ = false;
    uint32_t                      node_id_;
    SensorMap                     sensors_;
    TextSensorMap                 text_sensors_;
    canbus::Canbus                *canbus_ = nullptr;
    std::unique_ptr<FrameHandler> frame_handler_;

  public:
    explicit RemehaCAN(uint32_t node_id) : node_id_(node_id) {
      this->frame_handler_ = std::make_unique<FrameHandler>([](const std::string& name, auto entry, auto value) {
        ESP_LOGI(TAG, "on_message(%s):", name.c_str());
        if (std::holds_alternative<float>(value)) {
          // Emit float message
          ESP_LOGI(TAG, "  GOT NUMERICAL VALUE: %f", std::get<float>(value));
          return;
        }
        if (std::holds_alternative<std::string>(value)) {
          // Emit string message
          ESP_LOGI(TAG, "  GOT STRING VALUE: %s", std::get<std::string>(value).c_str());
          return;
        }
        ESP_LOGI(TAG, "  NO VALUE");
      });
    }

    void add_sensor(const std::string& name, Sensor* sensor) {
      this->sensors_[name] = sensor;
    }

    void add_text_sensor(const std::string& name, TextSensor* sensor) {
      this->text_sensors_[name] = sensor;
    }

    void set_canbus(canbus::Canbus *canbus);
    void on_frame(uint32_t can_id, bool rtr, std::vector<uint8_t> &data);
    void set_log_frames(bool log_frames) {
      this->log_frames_ = log_frames;
    }
};

}  // namespace remeha_can
}  // namespace esphome
