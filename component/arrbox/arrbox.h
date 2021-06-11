#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include <PZEM004Tv30.h>

namespace esphome {
namespace arrbox {

class ARRBOX : public PollingComponent {
 public:
  //Channel A
  void set_voltageA_sensor(sensor::Sensor *voltage_sensor) { voltageA_sensor_ = voltage_sensor; }
  void set_currentA_sensor(sensor::Sensor *current_sensor) { currentA_sensor_ = current_sensor; }
  void set_powerA_sensor(sensor::Sensor *power_sensor) { powerA_sensor_ = power_sensor; }
  void set_energyA_sensor(sensor::Sensor *energy_sensor) { energyA_sensor_ = energy_sensor; }
  void set_frequencyA_sensor(sensor::Sensor *frequency_sensor) { frequencyA_sensor_ = frequency_sensor; }
  void set_power_factorA_sensor(sensor::Sensor *power_factor_sensor) { power_factorA_sensor_ = power_factor_sensor; }

  //Channel B
  void set_voltageB_sensor(sensor::Sensor *voltage_sensor) { voltageB_sensor_ = voltage_sensor; }
  void set_currentB_sensor(sensor::Sensor *current_sensor) { currentB_sensor_ = current_sensor; }
  void set_powerB_sensor(sensor::Sensor *power_sensor) { powerB_sensor_ = power_sensor; }
  void set_energyB_sensor(sensor::Sensor *energy_sensor) { energyB_sensor_ = energy_sensor; }
  void set_frequencyB_sensor(sensor::Sensor *frequency_sensor) { frequencyB_sensor_ = frequency_sensor; }
  void set_power_factorB_sensor(sensor::Sensor *power_factor_sensor) { power_factorB_sensor_ = power_factor_sensor; }

  void update() override;
  void setup() override;

  //void on_modbus_data(const std::vector<uint8_t> &data) override;

  void dump_config() override;

 protected:
  //Channel A
  sensor::Sensor *voltageA_sensor_;
  sensor::Sensor *currentA_sensor_;
  sensor::Sensor *powerA_sensor_;
  sensor::Sensor *energyA_sensor_;
  sensor::Sensor *frequencyA_sensor_;
  sensor::Sensor *power_factorA_sensor_;

  //Channel B
  sensor::Sensor *voltageB_sensor_;
  sensor::Sensor *currentB_sensor_;
  sensor::Sensor *powerB_sensor_;
  sensor::Sensor *energyB_sensor_;
  sensor::Sensor *frequencyB_sensor_;
  sensor::Sensor *power_factorB_sensor_;

};

}  // namespace arrbox
}  // namespace esphome