#include "remeha-can-frame.h"

namespace remeha_can_lib {

Frame::Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : cob_id(cob_id & 0x07ff), rtr(rtr), size(size), data(data), node_id(cob_id & 0b1111111) {
  this->cob_ = static_cast<COB>((this->cob_id >> 7) & 0b1111);
}

std::unique_ptr<Frame> Frame::for_COB(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) {
  // extract function code, which maps to a Communication Object/COB
  COB cob = static_cast<COB>(((cob_id & 0x07ff) >> 7) & 0b1111);

  std::unique_ptr<Frame> frame;
  switch(cob) {
    case NMT:
      frame = std::make_unique<NMT_Frame>(cob_id, rtr, size, data);
      break;
    case SYNC: {
        // special case
        uint8_t node_id = cob_id & 0b1111111;
        if (node_id != 0) {
          frame = std::make_unique<EMCY_Frame>(cob_id, rtr, size, data);
        } else {
          frame = std::make_unique<SYNC_Frame>(cob_id, rtr, size, data);
        }
      }
      break;
    case TIME:
      frame = std::make_unique<TIME_Frame>(cob_id, rtr, size, data);
      break;
    case TRANSMIT_PDO_1:
      frame = std::make_unique<TRANSMIT_PDO_1_Frame>(cob_id, rtr, size, data);
      break;
    case RECEIVE_PDO_1:
      frame = std::make_unique<RECEIVE_PDO_1_Frame>(cob_id, rtr, size, data);
      break;
    case TRANSMIT_PDO_2:
      frame = std::make_unique<TRANSMIT_PDO_2_Frame>(cob_id, rtr, size, data);
      break;
    case RECEIVE_PDO_2:
      frame = std::make_unique<RECEIVE_PDO_2_Frame>(cob_id, rtr, size, data);
      break;
    case TRANSMIT_PDO_3:
      frame = std::make_unique<TRANSMIT_PDO_3_Frame>(cob_id, rtr, size, data);
      break;
    case RECEIVE_PDO_3:
      frame = std::make_unique<RECEIVE_PDO_3_Frame>(cob_id, rtr, size, data);
      break;
    case TRANSMIT_PDO_4:
      frame = std::make_unique<TRANSMIT_PDO_4_Frame>(cob_id, rtr, size, data);
      break;
    case RECEIVE_PDO_4:
      frame = std::make_unique<RECEIVE_PDO_4_Frame>(cob_id, rtr, size, data);
      break;
    case TRANSMIT_SDO:
      frame = std::make_unique<TRANSMIT_SDO_Frame>(cob_id, rtr, size, data);
      break;
    case RECEIVE_SDO:
      frame = std::make_unique<RECEIVE_SDO_Frame>(cob_id, rtr, size, data);
      break;
    case UNUSED_1:
      frame = std::make_unique<UNUSED_1_Frame>(cob_id, rtr, size, data);
      break;
    case HEARTBEAT:
      frame = std::make_unique<HEARTBEAT_Frame>(cob_id, rtr, size, data);
      break;
    case UNUSED_2:
      frame = std::make_unique<UNUSED_2_Frame>(cob_id, rtr, size, data);
      break;
  }
  return frame;
}

/*
Frame::Frame(uint16_t cob_id, bool rtr, uint8_t size, const FrameData& data) : cob_id(cob_id & 0x07ff), rtr(rtr), size(size), data(data), node_id(cob_id & 0b1111111) {
  // extract function code, which maps to a Communication Object/COB
  this->cob_ = static_cast<COB>((this->cob_id >> 7) & 0b1111);

  // special case
  if (this->cob_ == SYNC && this->node_id != 0) {
    this->cob_ = EMCY;
  }
}
*/

}; // namespace remeha_can
