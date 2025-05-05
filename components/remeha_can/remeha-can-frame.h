#pragma once

#include <vector>
#include <optional>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "remeha-can-types.h"
#include "remeha-can-od-types.h"

namespace remeha_can_lib {

// communication objects
enum COB {
  NMT            = 0b0000,
  SYNC           = 0b0001,
  EMCY,                   // SYNC and EMCY share the same function code
  TIME           = 0b0010,
  TRANSMIT_PDO_1 = 0b0011,
  RECEIVE_PDO_1  = 0b0100,
  TRANSMIT_PDO_2 = 0b0101,
  RECEIVE_PDO_2  = 0b0110,
  TRANSMIT_PDO_3 = 0b0111,
  RECEIVE_PDO_3  = 0b1000,
  TRANSMIT_PDO_4 = 0b1001,
  RECEIVE_PDO_4  = 0b1010,
  TRANSMIT_SDO   = 0b1011,
  RECEIVE_SDO    = 0b1100,
  UNUSED_1       = 0b1101,
  HEARTBEAT      = 0b1110,
  UNUSED_2       = 0b1111,
};

class Frame {
  private:
    COB                    cob_;
    std::optional<ODEntry> value_ = std::nullopt;

  public:
    const uint16_t  cob_id;
    const bool      rtr;
    const uint8_t   size;
    const FrameData data;
    const uint8_t   node_id;

    Frame(uint16_t, bool, uint8_t, const FrameData&);

    static std::unique_ptr<Frame> for_COB(uint16_t, bool, uint8_t, const FrameData&);

    explicit operator std::string() const {
      std::ostringstream os;

      // TODO: commobject
      os << "cob_id=0x" << std::setfill('0') << std::setw(4) << std::hex << this->cob_id << " ";
      os << "node_id=" << std::dec << static_cast<int>(this->node_id) << " ";
      os << "rtr=" << this->rtr << " ";
      os << "size=" << static_cast<int>(this->size) << " ";

      std::ostringstream framedata;
      for (const auto& byte: this->data) {
        framedata << std::setfill('0') << std::setw(2) << std::hex << +byte;
      }
      os << "data=" << framedata.str();
      return os.str();
    }

    // recreate original frame header
    FrameData header() const {
      uint16_t header = (this->cob_id << 5 & 0b1111111111100000) | (this->rtr << 4 & 0b10000) | (this->size & 0b1111);
      return { static_cast<uint8_t>(header >> 8), static_cast<uint8_t>(header & 0xff) };
    }

    bool is_SDO() const {
      return this->cob_ == TRANSMIT_SDO || this->cob_ == RECEIVE_SDO;
    }

    bool is_PDO(int8_t idx = -1) const {
      bool is_PDO_1 = this->cob_ == TRANSMIT_PDO_1 || this->cob_ == RECEIVE_PDO_1;
      bool is_PDO_2 = this->cob_ == TRANSMIT_PDO_2 || this->cob_ == RECEIVE_PDO_2;
      bool is_PDO_3 = this->cob_ == TRANSMIT_PDO_3 || this->cob_ == RECEIVE_PDO_3;
      bool is_PDO_4 = this->cob_ == TRANSMIT_PDO_4 || this->cob_ == RECEIVE_PDO_4;

      if (idx == 1) return is_PDO_1;
      if (idx == 2) return is_PDO_2;
      if (idx == 3) return is_PDO_3;
      if (idx == 4) return is_PDO_4;

      return is_PDO_1 || is_PDO_2 || is_PDO_3 || is_PDO_4;
    }

    bool is_TRANSMIT() const {
      return this->cob_ == TRANSMIT_PDO_1 || this->cob_ == TRANSMIT_PDO_2 ||
             this->cob_ == TRANSMIT_PDO_3 || this->cob_ == TRANSMIT_PDO_4 ||
             this->cob_ == TRANSMIT_SDO;
    }

    bool is_RECEIVE() const {
      return this->cob_ == RECEIVE_PDO_1 || this->cob_ == RECEIVE_PDO_2 ||
             this->cob_ == RECEIVE_PDO_3 || this->cob_ == RECEIVE_PDO_4 ||
             this->cob_ == RECEIVE_SDO;
    }

    bool is_UNKNOWN() const {
      return this->cob_ == UNUSED_1 || this->cob_ == UNUSED_2;
    }

    const ODEntry* value() {
      if (this->value_.has_value()) {
        return &this->value_.value();
      }
      return nullptr;
    }
};

class NMT_Frame : public Frame {
  public:
    NMT_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class SYNC_Frame : public Frame {
  public:
    SYNC_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class EMCY_Frame : public Frame {
  public:
    EMCY_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class TIME_Frame : public Frame {
  public:
    TIME_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class TRANSMIT_PDO_1_Frame : public Frame {
  public:
    TRANSMIT_PDO_1_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class RECEIVE_PDO_1_Frame : public Frame {
  public:
    RECEIVE_PDO_1_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class TRANSMIT_PDO_2_Frame : public Frame {
  public:
    TRANSMIT_PDO_2_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class RECEIVE_PDO_2_Frame : public Frame {
  public:
    RECEIVE_PDO_2_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class TRANSMIT_PDO_3_Frame : public Frame {
  public:
    TRANSMIT_PDO_3_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class RECEIVE_PDO_3_Frame : public Frame {

  public:
    RECEIVE_PDO_3_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class TRANSMIT_PDO_4_Frame : public Frame {
  public:
    TRANSMIT_PDO_4_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class RECEIVE_PDO_4_Frame : public Frame {
  public:
    RECEIVE_PDO_4_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class TRANSMIT_SDO_Frame : public Frame {
  public:
    TRANSMIT_SDO_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class RECEIVE_SDO_Frame : public Frame {
  public:
    RECEIVE_SDO_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class UNUSED_1_Frame : public Frame {
  public:
    UNUSED_1_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class HEARTBEAT_Frame : public Frame {
  public:
    HEARTBEAT_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

class UNUSED_2_Frame : public Frame {
  public:
    UNUSED_2_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {}
};

}; // namespace remeha_can
