#include <iostream>
#include <memory>
#include "remeha-can-od.h"
#include "remeha-can-od-data.h"

namespace remeha_can_lib {

const ODEntry* RemehaOD::get_entry(uint16_t index, uint8_t subindex) {
  auto it = ObjectDictionary.find(index << 8 | subindex);
  if (it != ObjectDictionary.end()) {
    return &it->second;
  }
  return nullptr;
}

}; // namespace remeha_can
