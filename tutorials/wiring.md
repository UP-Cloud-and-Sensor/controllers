# Wiring tutorial

The whole system could be described in this wiring diagram [[frizing file](./data/esp32_system.fzz)]:

![system](./images/esp32_system_bb.png)

Main board of the microcontroller:
![ESP32-microcontroller](./images/system_esp32/esp32_controller.jpg)

## setup pH
- VCC - 5V
- GND - GND
- GND - GND
- PO  - G32
- TO  - G33

![pH level connector](./images/system_esp32/sensors_pH.jpg)

As the cutoff voltage of the ADC in ESP32 is 3.3V, so it requires an extension board to collect the data

![extension board](./images/system_esp32/extension_board.jpg)

Regulated by potentiometers to calibrate the output voltage

### connect the pH probe

![TDS probe](./images/system_esp32/pH%20probe.jpg)

For calibration follow the tutorial:
[calibration](https://cimpleo.com/blog/arduino-ph-meter-using-ph-4502c/)

And check the coefficients of linear function using buffer solutions.

## setup TDS
- RED    - 3.3V
- BLACK  - GND
- YELLOW - G34

![board TDS](./images/system_esp32/sensors_TDS.jpg)

### connect the TDS probe

![TDS probe](./images/system_esp32/TDS%20probe.jpg)


