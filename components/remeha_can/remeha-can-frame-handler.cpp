#include <cstdio>
#include "remeha-can.h"
#include "remeha-can-frame-handler.h"
#include "remeha-can-frame.h"
#include "remeha-can-od.h"

namespace remeha_can_lib {

RemehaOD OD;

void FrameHandler::add_raw_frame(const FrameData& data) {
  uint16_t header = data[0] << 8 | data[1];
  auto cob_id     = (header >> 5) & 0b11111111111;
  auto rtr        = (header >> 4) & 0b1;
  auto size       = header        & 0b1111;
  auto frame_data = FrameData(data.begin() + 2, data.begin() + 2 + size);

  this->add_can_frame(cob_id, rtr, frame_data);
}

void FrameHandler::add_can_frame(uint16_t can_id, bool rtr, const FrameData& data) {
  auto frame = Frame::for_COB(can_id, rtr, data.size(), data);
  this->process_frame(*frame);
}

void FrameHandler::process_frame(const Frame& frame) {
  // PDOs containing "repackaged" SDO frame; extract
  // the data, convert to an SDO, and parse again.
  if (frame.is_PDO() && frame.node_id >> 6 == 1) {
    auto header = frame.header();
    auto data   = frame.data;

    // set new function code ({TRANSMIT, RECEIVE}_SDO)
    auto function_code = frame.is_TRANSMIT() ? 0b1011 : 0b1100;
    header[0] = ((header[0] & 0b00001111) | (function_code << 4)) & 0xff;

    // unset high bit from node id
    header[0] = header[0] & 0b11110111;

    // unset high bit from first data byte
    data[0] = data[0] & 0b01111111;

    // create new frame from data
    uint16_t cob_id = ((header[0] << 8 | header[1]) >> 5) & 0b11111111111;
    auto newframe = Frame::for_COB(cob_id, frame.rtr, frame.size, data);

    // process again
    this->process_frame(*newframe);
    return;
  }

  if (frame.is_SDO()) {
    this->process_SDO_frame(static_cast<const SDO_Frame&>(frame));
  }
}

void FrameHandler::process_SDO_frame(const SDO_Frame& frame) {
  // TODO:
  // - check expedited state
  // - alleen responses, geen requests

  // extract index/subindex
  uint16_t index   = *reinterpret_cast<const uint16_t*>(&frame.data[1]);
  uint8_t subindex = *reinterpret_cast<const uint8_t*>(&frame.data[3]);

  ESP_LOGD(TAG, "Frame       : %s", static_cast<std::string>(frame).c_str());
  ESP_LOGD(TAG, "Index       : %04X/%02X", index, subindex);

  if (frame.has_payload()) {
    ESP_LOGD(TAG, "Expedited   : %u", frame.is_expedited());
    ESP_LOGI(TAG, "Payload Size: %u", frame.payload_size());
  } else {
    ESP_LOGD(TAG, "NO PAYLOAD");
    return;
  }

  // look up OD entry
  auto entry = OD.get_entry(index, subindex);
  if (! entry) {
    return;
  }
  ESP_LOGI(TAG, "Entry       : name=%s parameter=%s", entry->name, entry->parameter);
  return;

  // parse data and pass it to message handler
#if 0
  auto value = entry->parse(frame.payload());
  ESP_LOGI(TAG, "Parsed okay");
#endif
  entry->parse(frame.payload());
 // this->on_message(entry->name, entry, entry->parse(frame.payload()));
}

}; // namespace remeha_can
