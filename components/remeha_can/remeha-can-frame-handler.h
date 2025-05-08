#pragma once

#include <functional>
#include <variant>
#include "remeha-can-types.h"
#include "remeha-can-frame.h"
#include "remeha-can-od-types.h"

namespace remeha_can_lib {

using MessageHandler = std::function<void(std::string, const ODEntry*, const ODValue&)>;

class FrameHandler {
  private:
    const MessageHandler on_message;

  public:
    explicit FrameHandler(const MessageHandler& on_message) : on_message(on_message) {}

    void add_raw_frame(const FrameData&);
    void add_can_frame(uint16_t, bool, const FrameData&);
    void process_frame(const Frame&);
    void process_SDO_frame(const SDO_Frame&);
};

}; // namespace remeha_can
