import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID
from . import RemehaCANComponent, CONF_REMEHACAN_ID
import json
import os

path = os.path.dirname(__file__)
with open(os.path.join(path, 'object-dictionary.json')) as fh:
    od = json.load(fh)

AUTO_LOAD = [ "remeha_can" ]

schema = { cv.GenerateID(CONF_REMEHACAN_ID): cv.use_id(RemehaCANComponent) }

for entry in od.values():
    if entry['type'] not in [ 'U8', 'U16', 'U32', 'I8', 'I16', 'I32' ]:
        continue
    schema[cv.Optional(entry['name'])] = sensor.sensor_schema(
        unit_of_measurement = entry.get('unit', ''),
        accuracy_decimals   = 2,
    )

CONFIG_SCHEMA = cv.Schema(schema)

async def to_code(config):
    component = await cg.get_variable(config[CONF_REMEHACAN_ID])

    for name, conf in config.items():
        if not isinstance(conf, dict):
            continue
        id = conf[CONF_ID]
        if id and id.type == sensor.Sensor:
            sens = await sensor.new_sensor(conf)
            cg.add(component.add_sensor(name, sens))
