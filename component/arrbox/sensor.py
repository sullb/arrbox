import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, modbus
from esphome.const import (
    CONF_ID,
    DEVICE_CLASS_EMPTY,
    DEVICE_CLASS_POWER_FACTOR,
    DEVICE_CLASS_VOLTAGE,
    DEVICE_CLASS_CURRENT,
    DEVICE_CLASS_POWER,
    DEVICE_CLASS_ENERGY,
    ICON_EMPTY,
    ICON_CURRENT_AC,
    UNIT_HERTZ,
    UNIT_VOLT,
    UNIT_AMPERE,
    UNIT_WATT,
    UNIT_EMPTY,
    UNIT_WATT_HOURS,
)

CONF_VOLTAGEA = "voltagea"
CONF_CURRENTA = "currenta"
CONF_POWERA = "powera"
CONF_ENERGYA = "energya"
CONF_FREQUENCYA = "frequencya"
CONF_POWER_FACTORA = "power_factora"

CONF_VOLTAGEB = "voltageb"
CONF_CURRENTB = "currentb"
CONF_POWERB = "powerb"
CONF_ENERGYB = "energyb"
CONF_FREQUENCYB = "frequencyb"
CONF_POWER_FACTORB = "power_factorb"


arrbox_ns = cg.esphome_ns.namespace("arrbox")
ARRBOX = arrbox_ns.class_("ARRBOX", cg.PollingComponent)

CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(ARRBOX),
            cv.Optional(CONF_VOLTAGEA): sensor.sensor_schema(
                UNIT_VOLT, ICON_EMPTY, 1, DEVICE_CLASS_VOLTAGE
            ),
            cv.Optional(CONF_CURRENTA): sensor.sensor_schema(
                UNIT_AMPERE, ICON_EMPTY, 3, DEVICE_CLASS_CURRENT
            ),
            cv.Optional(CONF_POWERA): sensor.sensor_schema(
                UNIT_WATT, ICON_EMPTY, 2, DEVICE_CLASS_POWER
            ),
            cv.Optional(CONF_ENERGYA): sensor.sensor_schema(
                UNIT_WATT_HOURS, ICON_EMPTY, 0, DEVICE_CLASS_ENERGY
            ),
            cv.Optional(CONF_FREQUENCYA): sensor.sensor_schema(
                UNIT_HERTZ, ICON_CURRENT_AC, 1, DEVICE_CLASS_EMPTY
            ),
            cv.Optional(CONF_POWER_FACTORA): sensor.sensor_schema(
                UNIT_EMPTY, ICON_EMPTY, 2, DEVICE_CLASS_POWER_FACTOR
            ),
            cv.Optional(CONF_VOLTAGEB): sensor.sensor_schema(
                UNIT_VOLT, ICON_EMPTY, 1, DEVICE_CLASS_VOLTAGE
            ),
            cv.Optional(CONF_CURRENTB): sensor.sensor_schema(
                UNIT_AMPERE, ICON_EMPTY, 3, DEVICE_CLASS_CURRENT
            ),
            cv.Optional(CONF_POWERB): sensor.sensor_schema(
                UNIT_WATT, ICON_EMPTY, 2, DEVICE_CLASS_POWER
            ),
            cv.Optional(CONF_ENERGYB): sensor.sensor_schema(
                UNIT_WATT_HOURS, ICON_EMPTY, 0, DEVICE_CLASS_ENERGY
            ),
            cv.Optional(CONF_FREQUENCYB): sensor.sensor_schema(
                UNIT_HERTZ, ICON_CURRENT_AC, 1, DEVICE_CLASS_EMPTY
            ),
            cv.Optional(CONF_POWER_FACTORB): sensor.sensor_schema(
                UNIT_EMPTY, ICON_EMPTY, 2, DEVICE_CLASS_POWER_FACTOR
            ),
        }
    )
    .extend(cv.polling_component_schema("60s"))
)


def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    #yield modbus.register_modbus_device(var, config)

    if CONF_VOLTAGEA in config:
        conf = config[CONF_VOLTAGEA]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_voltageA_sensor(sens))
    if CONF_CURRENTA in config:
        conf = config[CONF_CURRENTA]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_currentA_sensor(sens))
    if CONF_POWERA in config:
        conf = config[CONF_POWERA]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_powerA_sensor(sens))
    if CONF_ENERGYA in config:
        conf = config[CONF_ENERGYA]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energyA_sensor(sens))
    if CONF_FREQUENCYA in config:
        conf = config[CONF_FREQUENCYA]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_frequencyA_sensor(sens))
    if CONF_POWER_FACTORA in config:
        conf = config[CONF_POWER_FACTORA]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_factorA_sensor(sens))

    if CONF_VOLTAGEB in config:
        conf = config[CONF_VOLTAGEB]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_voltageB_sensor(sens))
    if CONF_CURRENTB in config:
        conf = config[CONF_CURRENTB]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_currentB_sensor(sens))
    if CONF_POWERB in config:
        conf = config[CONF_POWERB]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_powerB_sensor(sens))
    if CONF_ENERGYB in config:
        conf = config[CONF_ENERGYB]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_energyB_sensor(sens))
    if CONF_FREQUENCYB in config:
        conf = config[CONF_FREQUENCYB]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_frequencyB_sensor(sens))
    if CONF_POWER_FACTORB in config:
        conf = config[CONF_POWER_FACTORB]
        sens = yield sensor.new_sensor(conf)
        cg.add(var.set_power_factorB_sensor(sens))
