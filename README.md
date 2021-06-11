# arrbox
Will only be useful to 2 people at the moment.

```yaml
external_components:
  - source:
      type: git
      url: https://github.com/sullb/arrbox
      ref: master
    components: [ arrbox ]
    refresh: 10 minutes

esphome:
  name: meterbox
  platform: ESP8266
  board: nodemcu
  libraries:
    - EspSoftwareSerial@6.8.5
    - PZEM-004T-v30

wifi:
  ssid: "ssidofyourchoice"
  password: "reallysecurepassword"

  # Enable fallback hotspot (captive portal) in case wifi connection fails
  ap:
    ssid: "Meterbox Fallback Hotspot"
    password: "reallysecurepassword"

captive_portal:

# Enable logging
logger:

# Enable Home Assistant API
api:
  password: "reallysecurepassword"

ota:
  password: "reallysecurepassword"

web_server:

sensor:
  - platform: wifi_signal
    name: "Meterbox Wifi"
    update_interval: 60s
  - platform: arrbox
    currenta:
      name: "CHA Current"
    voltagea:
      name: "CHA Voltage"
    energya:
      name: "CHA Energy"
    powera:
      name: "CHA Power"
    frequencya:
      name: "CHA Frequency"
    power_factora:
      name: "CHA Power Factor"
    currentb:
      name: "CHB Current"
    voltageb:
      name: "CHB Voltage"
    energyb:
      name: "CHB Energy"
    powerb:
      name: "CHB Power"
    frequencyb:
      name: "CHB Frequency"
    power_factorb:
      name: "CHB Power Factor"
    update_interval: 10s
```