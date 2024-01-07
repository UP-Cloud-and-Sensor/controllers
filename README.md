# Controllers
Code for ESP32 microcontroller for measuring TDS and pH level and transfering data via MQTT

# Navigation
- [Setup](#setup)
- [Usage](#usage)
- [Features](#features)
- [Reference](#reference)
- [Tutorials](./tutorials/README.md)

# Setup

Current setup includes ESP32 microcontroller, TDS and pH level sensors for wiring check the tutorials page
![ESP32-microcontroller](./images/ESP32-38-PIN.jpg)
![pH level connector](./images/bnc-ph.jpg)
![ESP32-microcontroller](./images/tds.jpg)

# Usage

1) define all variables in secret.h (localy)
2) upload **main.cpp** script to ESP32 - by conecting it to micro-usb port and pushing **BOOT** button
3) connect ESP32 to power - by USB or by battery

# Features

ESP32 after connection to WiFi and MQTT broker will send data in JSON format:

- tag - identification of the device
- time - seconds since launch
- T - temperature [in future]
- TDS - value of particles in the water
- pH - acidity of water

# Reference

![TDS scale](./images/TDS_scale.jpg)
![pH scale](./images/pH_scale.jpg)

