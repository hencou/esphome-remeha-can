# Remeha CAN component for ESPhome

This component can be used to interact with the CAN bus that is exposed through the service port of modern Remeha boilers/heat pumps.

For now, it's a passive component, only logging the data that gets published on the bus. Eventually, the goal is to provide an ESPhome interface that can be used through Home Assistant to read and control your Remeha boiler, fully local.

## Hardware requirements

Although the component should work with any CAN bus implementation for ESPhome, I've only tested this with the [`esp32_can`](https://esphome.io/components/canbus/esp32_can) component.

Since ESP32s already have a CAN controller onboard, the only additional hardware required besides the ESP32 is a CAN transceiver. I'm using a SN65HVD230 bought on Aliexpress ([here](https://nl.aliexpress.com/item/1005008322059982.html)) for less than €2.

## Connecting to the boiler

Remeha boilers have a service port that is accessible through an RJ12 jack.

Please consult the manual of your boiler to see where exactly it's located. My boiler (Elga Ace All-in-One) has two service ports: one inside the boiler, towards the bottom next to the yellow lid, and one on the underside of the device, on the right. I'm using the former.

As for pinout, I'm using [this schema](https://github.com/ronbuist/remeha-can-interface/wiki/01-%E2%80%90-Hardware#pinout) from @ronbuist, although it seems that for my boiler I had to swap CAN H and CAN L to get it working.

**NOTE**: although I expect the service port to be well isolated electrically, there's a chance that you may damage your boiler if you're not careful. You can also damage your ESP32 and/or your transceiver if you connect it to the wrong pins. MAKE SURE YOU KNOW WHAT YOU'RE DOING.

## Usage

See the [ESPhome example file](esphome-example.yaml).

At the moment, the setting `log_frames` should be set to `True`, otherwise the component doesn't do anything useful. Using `log_frames` will dump all CAN frames as INFO log messages to the serial console. You can use the parser provided by [this project](https://github.com/robertklep/remeha-canopen-parser) to parse the data logged by the device.

A Python script `log-to-frame.py` is included to convert the log format to the format required by the parser:
```
esphome run esphome-example.yaml | python3 log-to-frame.py | python3 /path/to/remeha-canopen-parser/remeha-parser.py
```
