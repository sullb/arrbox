#include "arrbox.h"
#include "esphome/core/log.h"
#include <PZEM004Tv30.h>

namespace esphome {
namespace arrbox {

static const char *TAG = "arrbox";
PZEM004Tv30 pzemA(D1,D2);  // (RX,TX) connect to TX,RX of PZEM
PZEM004Tv30 pzemB(D3,D4);  // (RX,TX) connect to TX,RX of PZEM2

void ARRBOX::setup() {
  Serial.begin(115200);
  //pzemA.search();
  //pzemB.search();
  pzemA.resetEnergy();
  pzemB.resetEnergy();
}
//void ARRBOX::update() { this->send(PZEM_CMD_READ_IN_REGISTERS, 0, PZEM_REGISTER_COUNT); }
void ARRBOX::update() { 
  float voltageA,currentA,pfA,frequencyA,powerA,energyA;
  float voltageB,currentB,pfB,frequencyB,powerB,energyB;  

  voltageA = pzemA.voltage();
  currentA = pzemA.current();
  powerA = pzemA.power();
  energyA = pzemA.energy();
  frequencyA = pzemA.frequency();
  pfA = pzemA.pf();
  ESP_LOGD(TAG, "PZEM-A AC: V=%.1f V, I=%.3f A, P=%.1f W, E=%.1f Wh, F=%.1f Hz, PF=%.2f", voltageA, currentA, powerA, energyA, frequencyA, pfA);
  if (this->voltageA_sensor_ != nullptr)
    this->voltageA_sensor_->publish_state(voltageA);
  if (this->currentA_sensor_ != nullptr)
    this->currentA_sensor_->publish_state(currentA);
  if (this->powerA_sensor_ != nullptr)
    this->powerA_sensor_->publish_state(powerA);
  if (this->energyA_sensor_ != nullptr)
    this->energyA_sensor_->publish_state(energyA);
  if (this->frequencyA_sensor_ != nullptr)
    this->frequencyA_sensor_->publish_state(frequencyA);
  if (this->power_factorA_sensor_ != nullptr)
    this->power_factorA_sensor_->publish_state(pfA);

  voltageB = pzemB.voltage();
  currentB = pzemB.current();
  powerB = pzemB.power();
  energyB = pzemB.energy();
  frequencyB = pzemB.frequency();
  pfB = pzemB.pf();
  ESP_LOGD(TAG, "PZEM-B AC: V=%.1f V, I=%.3f A, P=%.1f W, E=%.1f Wh, F=%.1f Hz, PF=%.2f", voltageB, currentB, powerB, energyB, frequencyB, pfB);
  if (this->voltageB_sensor_ != nullptr)
    this->voltageB_sensor_->publish_state(voltageB);
  if (this->currentB_sensor_ != nullptr)
    this->currentB_sensor_->publish_state(currentB);
  if (this->powerB_sensor_ != nullptr)
    this->powerB_sensor_->publish_state(powerB);
  if (this->energyB_sensor_ != nullptr)
    this->energyB_sensor_->publish_state(energyB);
  if (this->frequencyB_sensor_ != nullptr)
    this->frequencyB_sensor_->publish_state(frequencyB);
  if (this->power_factorB_sensor_ != nullptr)
    this->power_factorB_sensor_->publish_state(pfB);
 }

void ARRBOX::dump_config() {
  ESP_LOGCONFIG(TAG, "PZEMAC A:");
  LOG_SENSOR("", "Voltage", this->voltageA_sensor_);
  LOG_SENSOR("", "Current", this->currentA_sensor_);
  LOG_SENSOR("", "Power", this->powerA_sensor_);
  LOG_SENSOR("", "Energy", this->energyA_sensor_);
  LOG_SENSOR("", "Frequency", this->frequencyA_sensor_);
  LOG_SENSOR("", "Power Factor", this->power_factorA_sensor_);

  ESP_LOGCONFIG(TAG, "PZEMAC B:");
  LOG_SENSOR("", "Voltage", this->voltageB_sensor_);
  LOG_SENSOR("", "Current", this->currentB_sensor_);
  LOG_SENSOR("", "Power", this->powerB_sensor_);
  LOG_SENSOR("", "Energy", this->energyB_sensor_);
  LOG_SENSOR("", "Frequency", this->frequencyB_sensor_);
  LOG_SENSOR("", "Power Factor", this->power_factorB_sensor_);
}

}  // namespace arrbox
}  // namespace esphome