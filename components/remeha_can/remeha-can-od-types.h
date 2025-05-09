#pragma once

#include <vector>
#include <map>
#include <optional>
#include <variant>
#include "remeha-can-types.h"

#include "esphome/core/log.h"

namespace remeha_can_lib {

using ODValue = std::variant<std::monostate, float, std::string>;

class ODEntry {
  public:
    const char*                 name;
    const char*                 parameter;
    bool                        readonly;
    int8_t                      max_array_size;
    float                       gain;

    ODEntry(
      const char*                 name,
      const char*                 parameter,
      bool                        readonly,
      int8_t                      max_array_size,
      float                       gain
    ) : name(name), parameter(parameter),
        readonly(readonly),
        max_array_size(max_array_size),
        gain(gain) {}

    virtual ODValue parse(const FrameData&) const;
};

template <typename T>
class IntODEntry : public ODEntry {
  static_assert(std::is_integral<T>::value, "T must be an integral type");

  // inherit base class ctor
  using ODEntry::ODEntry;

  public:
    ODValue parse(const FrameData& data) const {
      T value = 0;
      for (size_t i = 0; i < sizeof(T); ++i) {
        value |= static_cast<T>(data[i]) << (8 * i);
      }
      float ret = static_cast<float>(value);
      if (this->gain) {
        ret *= this->gain;
      }
      return ODValue(ret);
    }
};

using U8  = IntODEntry<uint8_t>;
using U16 = IntODEntry<uint16_t>;
using U32 = IntODEntry<uint32_t>;

using I8  = IntODEntry<int8_t>;
using I16 = IntODEntry<int16_t>;
using I32 = IntODEntry<int32_t>;

class Enum : public ODEntry {

  using ODEnumValues = std::map<uint8_t, const char*>;

  public:
    ODEnumValues values;

    Enum(
      const char*  name,
      const char*  parameter,
      bool         readonly,
      int8_t       max_array_size,
      float        gain,
      ODEnumValues values
    ) : ODEntry(name, parameter, readonly, max_array_size, gain), values(values) {}

    ODValue parse(const FrameData& data) const override {
      uint8_t index = data[0];
      if (auto value = values.find(index); value != values.end()) {
        return ODValue(std::string(value->second));
      }
      return ODValue(std::monostate{});
    }
};

using RemehaObjectDictionary = std::map<uint32_t, ODEntry*>;

};
