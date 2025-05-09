import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor
from esphome.const import CONF_ID
from . import RemehaCANComponent, CONF_REMEHACAN_ID, sensors_for_types

AUTO_LOAD = [ "remeha_can" ]

schema = { cv.GenerateID(CONF_REMEHACAN_ID): cv.use_id(RemehaCANComponent) }

for entry in sensors_for_types('Enum'):
    schema[cv.Optional(entry['name'])] = text_sensor.text_sensor_schema()

CONFIG_SCHEMA = cv.Schema(schema)

async def to_code(config):
    component = await cg.get_variable(config[CONF_REMEHACAN_ID])

    for name, conf in config.items():
        if not isinstance(conf, dict):
            continue
        id = conf[CONF_ID]
        if id and id.type == text_sensor.TextSensor:
            sens = await text_sensor.new_text_sensor(conf)
            cg.add(component.add_text_sensor(name, sens))
            cg.add_define(f'rem_{name}') # enable OD entry in remeha-can-od-data.h
