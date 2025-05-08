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

// SDO types
enum SDO_Type {
  DOWNLOAD_SEGMENT_REQ,
  INITIATE_DOWNLOAD_REQ,
  INITIATE_UPLOAD_REQ,
  UPLOAD_SEGMENT_REQ,
  ABORT_TRANSFER_REQ,
  UPLOAD_SEGMENT_RES,
  DOWNLOAD_SEGMENT_RES,
  INITIATE_UPLOAD_RES,
  INITIATE_DOWNLOAD_RES,
  UNKNOWN_SDO
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
  using Frame::Frame;
};

class SYNC_Frame : public Frame {
  using Frame::Frame;
};

class EMCY_Frame : public Frame {
  using Frame::Frame;
};

class TIME_Frame : public Frame {
  using Frame::Frame;
};

class TRANSMIT_PDO_1_Frame : public Frame {
  using Frame::Frame;
};

class RECEIVE_PDO_1_Frame : public Frame {
  using Frame::Frame;
};

class TRANSMIT_PDO_2_Frame : public Frame {
  using Frame::Frame;
};

class RECEIVE_PDO_2_Frame : public Frame {
  using Frame::Frame;
};

class TRANSMIT_PDO_3_Frame : public Frame {
  using Frame::Frame;
};

class RECEIVE_PDO_3_Frame : public Frame {
  using Frame::Frame;
};

class TRANSMIT_PDO_4_Frame : public Frame {
  using Frame::Frame;
};

class RECEIVE_PDO_4_Frame : public Frame {
  using Frame::Frame;
};

class SDO_Frame : public Frame {
  protected:
    SDO_Type  type_;
    bool      expedited_    = false;
    uint8_t   payload_size_ = 0;
    FrameData payload_;

  public:

    SDO_Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : Frame(cob_id, rtr, size, data) {
      if (size < 1) {
        this->type_ = UNKNOWN_SDO;
        return;
      }

      // select SDO type based on command specifier and direction
      bool recv = this->is_RECEIVE();
      bool xmit = this->is_TRANSMIT();
      switch((data[0] >> 5) & 0b111) {
        case 0:
          this->type_ = recv ? DOWNLOAD_SEGMENT_REQ : xmit ? UPLOAD_SEGMENT_RES : UNKNOWN_SDO;
          break;
        case 1:
          this->type_ = recv ? INITIATE_DOWNLOAD_REQ : xmit ? DOWNLOAD_SEGMENT_RES : UNKNOWN_SDO;
          break;
        case 2:
          this->type_ = recv ? INITIATE_UPLOAD_REQ : xmit ? INITIATE_UPLOAD_RES : UNKNOWN_SDO;
          break;
        case 3:
          this->type_ = recv ? UPLOAD_SEGMENT_REQ : xmit ? INITIATE_DOWNLOAD_RES : UNKNOWN_SDO;
          break;
        case 4:
          this->type_ = recv ? ABORT_TRANSFER_REQ : UNKNOWN_SDO;
          break;
        default:
          this->type_ = UNKNOWN_SDO;
          break;
      }

      // extract payload for certain types
      if (this->type_ == INITIATE_DOWNLOAD_REQ || this->type_ == INITIATE_UPLOAD_RES) {
        uint8_t command = data[0];
        uint8_t n       = (command >> 2) & 0b11; // number of no-data bytes
        uint8_t e       = (command >> 1) & 0b1;  // expedited?
        // uint8_t s       = command        & 0b1;  // size indicator

        this->expedited_ = e;
        if (e) {
          this->payload_size_ = 4 - n;
          this->payload_      = FrameData(data.begin() + 4, data.begin() + 4 + 4 - n);
        } else {
          this->payload_size_ = data[4];
        }
      }
    }

    SDO_Type type() const {
      return this->type_;
    }

    bool is_type(SDO_Type type) const {
      return this->type_ == type;
    }

    bool is_expedited() const {
      return this->expedited_;
    }

    bool has_payload() const {
      return this->payload_size_ != 0;
    }

    uint8_t payload_size() const {
      return this->payload_size_;
    }

    const FrameData& payload() const {
      return this->payload_;
    }
};

class TRANSMIT_SDO_Frame : public SDO_Frame {
  using SDO_Frame::SDO_Frame;
};

class RECEIVE_SDO_Frame : public SDO_Frame {
  using SDO_Frame::SDO_Frame;
};

class UNUSED_1_Frame : public Frame {
  using Frame::Frame;
};

class HEARTBEAT_Frame : public Frame {
  using Frame::Frame;
};

class UNUSED_2_Frame : public Frame {
  using Frame::Frame;
};

}; // namespace remeha_can
