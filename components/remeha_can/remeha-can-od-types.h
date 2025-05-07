#pragma once

#include <vector>
#include <map>
#include <optional>
#include "remeha-can-types.h"

namespace remeha_can_lib {

using ODEnumValues = std::map<uint8_t, const char*>;

enum class ODValueType {
  U8, U16, U32,
  I8, I16, I32,
  STRING
//  Enum, String
};

struct ODValue {
  ODValueType type;
  union {
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    int8_t i8;
    int16_t i16;
    int32_t i32;
  };
  std::string str;

  // Constructors
  explicit ODValue(uint8_t val)         : type(ODValueType::U8),     u8(val) {}
  explicit ODValue(uint16_t val)        : type(ODValueType::U16),    u16(val) {}
  explicit ODValue(uint32_t val)        : type(ODValueType::U32),    u32(val) {}
  explicit ODValue(int8_t val)          : type(ODValueType::I8),     i8(val) {}
  explicit ODValue(int16_t val)         : type(ODValueType::I16),    i16(val) {}
  explicit ODValue(int32_t val)         : type(ODValueType::I32),    i32(val) {}
  explicit ODValue(const std::string& s): type(ODValueType::STRING), str(s) {}

  operator uint8_t() const {
    return u8;
  }

  operator uint16_t() const {
    return u16;
  }

  operator uint32_t() const {
    return u32;
  }
};

class ODEntry {
  public:
    const char*                 name;
    const char*                 parameter;
    bool                        readonly;
    int8_t                      max_array_size;
    std::optional<float>        gain;
    std::optional<const char*>  unit;

    ODEntry(
      const char*                 name,
      const char*                 parameter,
      bool                        readonly,
      int8_t                      max_array_size,
      std::optional<float>        gain,
      std::optional<const char*>  unit
    ) : name(name), parameter(parameter),
        readonly(readonly),
        max_array_size(max_array_size),
        gain(gain), unit(unit) {}

    virtual ODValue parse(const FrameData&) const;
};

template <typename T>
class IntODEntry : public ODEntry {
  static_assert(std::is_integral<T>::value, "T must be an integral type");

  // inherit base class ctor
  using ODEntry::ODEntry;

  public:
    ODValue parse(const FrameData& data) const {
      //return *reinterpret_cast<T*>(&data[0]);
      T value = 0;
      for (size_t i = 0; i < sizeof(T); ++i) {
          value |= static_cast<T>(data[i]) << (8 * i);
      }
      return ODValue(value);
    }
};

using U8Entry  = IntODEntry<uint8_t>;
using U16Entry = IntODEntry<uint16_t>;
using U32Entry = IntODEntry<uint32_t>;

using I8Entry  = IntODEntry<int8_t>;
using I16Entry = IntODEntry<int16_t>;
using I32Entry = IntODEntry<int32_t>;

class EnumEntry : public U8Entry {
  public:
    std::optional<ODEnumValues> values;

    EnumEntry(
      const char*                 name,
      const char*                 parameter,
      bool                        readonly,
      int8_t                      max_array_size,
      std::optional<float>        gain,
      std::optional<const char*>  unit,
      const ODEnumValues&         values
    ) : U8Entry(name, parameter, readonly, max_array_size, gain, unit), values(values) {}
};

using RemehaObjectDictionary = std::map<uint32_t, const ODEntry&>;

};
