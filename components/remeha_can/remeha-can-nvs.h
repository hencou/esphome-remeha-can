#pragma once

#include <string>
#include <optional>
#include "esphome/core/log.h"
#include "remeha-can.h"
#include "nvs_flash.h"
#include "nvs.h"

// TODO: set define from __init__.py
#define REMEHA_NVS_MAX_DATA_SIZE 5500

namespace remeha_can_lib {

class NVS {
  private:
    const char*  partition_;
    const char*  namespace_;
    nvs_handle_t handle_;

  public:
    esp_err_t last_error  = ESP_OK;
    bool      initialized = false;

    NVS(const char* partition_, const char* namespace_) : partition_(partition_), namespace_(namespace_) {
      // initialize NVS
      this->last_error = nvs_flash_init_partition(partition_);
      if (this->last_error != ESP_OK && this->last_error != ESP_ERR_NVS_NO_FREE_PAGES) {
        ESP_LOGE(TAG, "NVS init failed: %s", esp_err_to_name(this->last_error));
        return;
      }

      this->last_error = nvs_open_from_partition(partition_, namespace_, NVS_READONLY, &this->handle_);
      if (this->last_error != ESP_OK) {
        ESP_LOGE(TAG, "NVS open failed: %s", esp_err_to_name(this->last_error));
        return;
      }
      this->initialized = true;
    }

    ~NVS() {
      if (this->initialized) {
        nvs_close(this->handle_);
      }
    }

    std::optional<std::vector<uint8_t>> get(const std::string& key) {
      if (! this->initialized) {
        return std::nullopt;
      }

      size_t required_size = 0;
      std::vector<uint8_t> buffer(REMEHA_NVS_MAX_DATA_SIZE);
      this->last_error = nvs_get_blob(this->handle_, key.c_str(), buffer.data(), &required_size);
      if (this->last_error != ESP_OK) {
        ESP_LOGE(TAG, "NVS get failed: %s", esp_err_to_name(this->last_error ));
        return std::nullopt;
      }
      return buffer;

      /*
      size_t required_size = 0;
      esp_err_t err = nvs_get_blob(this->nvs_handle_, "302300", NULL, &required_size);
      if (err == ESP_OK && required_size > 0) {
        std::vector<uint8_t> buffer(required_size);
        err = nvs_get_blob(this->nvs_handle_, "302300", buffer.data(), &required_size);
        if (err == ESP_OK) {
          ESP_LOGI("NVS", "Read %d bytes: %02X %02X", required_size, buffer[0], buffer[1]);
        }
      }
      */
    }
};

}; // namespace remeha_can_lib
