#pragma once

#include <vector>
#include <map>
#include <optional>
#include "remeha-can-types.h"

namespace remeha_can_lib {

using EnumValues = std::map<uint8_t, const char*>;

class ODEntry {
  public:
    const char*                 name;
    const char*                 parameter;
    bool                        readonly;
    int8_t                      max_array_size;
    std::optional<float>        gain;
    std::optional<const char*>  unit;
    std::optional<EnumValues>   values;

    ODEntry(
      const char*                 name,
      const char*                 parameter,
      bool                        readonly,
      int8_t                      max_array_size,
      std::optional<float>        gain,
      std::optional<const char*>  unit,
      std::optional<EnumValues>   values
    ) : name(name), parameter(parameter),
        readonly(readonly),
        max_array_size(max_array_size),
        gain(gain), unit(unit),
        values(values) {}

    template <typename T>
    T parse(const FrameData&);
};

template <typename T, int num_bits>
class IntODEntry : public ODEntry {

  // inherit base class ctor
  using ODEntry::ODEntry;

  public:
    T parse(const FrameData& data) {
      return *reinterpret_cast<T*>(&data[0]);
      /*
      if (num_bits == 32) {
        return static_cast<T>(data[0])        |
              (static_cast<T>(data[1]) << 8)  |
              (static_cast<T>(data[2]) << 16) |
              (static_cast<T>(data[3]) << 24);
      } else if (num_bits == 16) {
        return static_cast<T>(data[0]) | (static_cast<T>(data[1]) << 8);
      } else if (num_bits == 8) {
        return static_cast<T>(data[0]);
      }
      */
    }
};

using U8  = IntODEntry<uint8_t, 8>;
using U16 = IntODEntry<uint8_t, 16>;
using U32 = IntODEntry<uint8_t, 32>;

using I8  = IntODEntry<int8_t, 8>;
using I16 = IntODEntry<int8_t, 16>;
using I32 = IntODEntry<int8_t, 32>;

using RemehaObjectDictionary = std::map<uint32_t, const ODEntry&>;

};
