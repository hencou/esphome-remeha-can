import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from esphome.components.canbus import CanbusComponent

CODEOWNERS   = [ "@robertklep" ]
#DEPENDENCIES = [ "canbus" ]
AUTO_LOAD    = ["sensor", "text_sensor"]

RemehaCANNS        = cg.esphome_ns.namespace("remeha_can")
RemehaCANComponent = RemehaCANNS.class_("RemehaCAN", cg.Component)

CONF_REMEHACAN_ID  = "remeha_can_id"

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID():                            cv.declare_id(RemehaCANComponent),
    cv.GenerateID('canbus_id'):                 cv.use_id(CanbusComponent),
    cv.Required('node_id'):                     cv.All(cv.int_, cv.Range(min=10, max=127)),
    cv.Optional('log_frames', default = False): cv.boolean
})

async def to_code(config):
    component = cg.new_Pvariable(config[CONF_ID], config['node_id'])
    canbus = await cg.get_variable(config['canbus_id'])
    cg.add(component.set_canbus(canbus))
    cg.add(component.set_log_frames(config['log_frames']))

    # required for some C++ features
    cg.add_build_flag("-std=c++17")
