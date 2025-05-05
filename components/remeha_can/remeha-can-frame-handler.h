#pragma once

#include <functional>
#include "remeha-can-nvs.h"
#include "remeha-can-types.h"
#include "remeha-can-frame.h"

namespace remeha_can_lib {

using MessageHandler = std::function<void(std::string)>;

class FrameHandler {
  private:
    const MessageHandler on_message;
    std::unique_ptr<NVS> nvs;

  public:
    explicit FrameHandler(const MessageHandler& on_message) : on_message(on_message) {
      // TODO: use #define's for partition/namespace
      this->nvs = std::make_unique<NVS>("remehadata", "remehacan");
    }

    void add_raw_frame(const FrameData&);
    void add_can_frame(uint16_t, bool, const FrameData&);
    void process_frame(const Frame&);
};

}; // namespace remeha_can
