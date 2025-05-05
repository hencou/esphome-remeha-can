#pragma once
#include "remeha-can-od-types.h"

namespace remeha_can_lib {

class RemehaOD {
  public:
    RemehaOD () {}

    const ODEntry* get_entry(uint16_t, uint8_t = 0);
};

}; // namespace remeha_can 

