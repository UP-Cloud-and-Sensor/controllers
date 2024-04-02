# Board Selection

I chose ESP32 as it has Wifi and Bluetooth connection inside the basic chip. And it is widely used for IoT projects: probably for testing we can use up to 3 controllers:
- [x] [AZDelivery ESP-32 with CP2102](https://www.amazon.de/-/en/gp/product/B08BTQ57ZV/ref=ox_sc_saved_title_5?smid=A1X7QLRQH87QA3&th=1)

# Sensors Selection

- [x] [pH sensor with BNC probe](https://www.amazon.de/dp/B0C3WMG2SS?psc=1&ref=ppx_yo2ov_dt_b_product_details)
1. pH level sensor
- [ ] [AZDelivery GY-BME280 Barometric Sensor](https://www.amazon.de/AZDelivery-GY-BME280-Barometric-Sensor-Parent/dp/B07D8T4HP6?ref_=ast_sto_dp&th=1)
1. **Humidity Sensor:**
   - Response Time (T63%): 1NO
   - Accuracy Tolerance: ±3% RH (relative humidity)
2. **Pressure Range:**
   - 300 to 1100hPa (9000 m to 500 m above sea level)
3. **Temperature Sensor:**
   - Operating Range: -40°C to +85°C
   - Full Accuracy: 0°C to +65°C
4. **Digital Interface:**
   - I²C (up to 3.4 MHz)
   - SPI (3 and 4 wire, up to 10 MHz)

- [ ] [AZDelivery Moisture Hygrometer](https://www.amazon.de/AZDelivery-Moisture-Hygrometer-Compatible-Raspberry/dp/B07V6SZYZW?ref_=ast_sto_dp&th=1&psc=1)
1. **Hygrometer Soil Moisture:**
   - Operating Voltage: 5V

- [ ] [AZDelivery Stainless Temperature Sensor](https://www.amazon.de/AZDelivery-Stainless-Temperature-Waterproof-Compatible/dp/B07CZ1G29V?ref_=ast_sto_dp&th=1)
1. **Water Temperature Sensor:**

- [ ] [Smart Board with several sensors included and ESP32](https://www.amazon.de/dp/B08LKVSH2B/ref=sspa_dk_detail_5?pd_rd_i=B08LKRG478&pd_rd_w=PSeTh&content-id=amzn1.sym.ae2317a0-2175-4285-af64-66539858231f&pf_rd_p=ae2317a0-2175-4285-af64-66539858231f&pf_rd_r=YKGWDKHKWBBY2Y28YJJA&pd_rd_wg=v5de3&pd_rd_r=365777c2-f08e-4564-bbe0-4a1c4484b6b8&s=ce-de&sp_csd=d2lkZ2V0TmFtZT1zcF9kZXRhaWw&th=1)
1. Smart board with ESP32 included (low reviews)
2. MQ-2 sensor:
   - Increase conductivity with increased gas concentration.
   - High sensitivity, ideal for domestic gas leak detection, portable gas detector, or measuring flammable gas.
   - Long service life and low costs.
3. Temperature and humidity sensor HDC1080:
   - Accuracy of relative humidity ±2%
   - Temperature accuracy ±0.2°C
   - 14-bit measuring resolution
   - I2C interface (connected to SDA and SCL)

- [ ] [AZDelivery Raindrop Sensor](https://www.amazon.de/-/en/AZDelivery-Raindrop-Sensor-Compatible-Arduino/dp/B07V5QQW9J/ref=pd_sbs_sccl_2_4/258-3489397-5850609?pd_rd_w=POtbk&content-id=amzn1.sym.6c0521be-6c2b-450c-bb72-af8082730381&pf_rd_p=6c0521be-6c2b-450c-bb72-af8082730381&pf_rd_r=CFPP36HR7B7J3PM3Q7FM&pd_rd_wg=RWZgI&pd_rd_r=60050af2-072b-4038-a0ef-f267ee22e4c6&pd_rd_i=B07V5QQW9J&psc=1)
1. **Raindrop Sensor:**

- [ ] [AZDelivery Mini Solar Panel Kit](https://www.amazon.de/-/en/AZDelivery-Polysilicon-Batteries-Encapsulated-Waterproof/dp/B09Z31XGBW/ref=sr_1_2?crid=85PGO1DRAIZC&keywords=sollar%2Bradiation%2Bmodule%2Bi2c&qid=1699225361&s=industrial&sprefix=sollar%2Bradiation%2Bmodule%2Bi2c%2Cindustrial%2C76&sr=1-2&th=1)
1. **Solar Panel:**
   - Could be used as Solar Radiation

- [ ] [AZDelivery MQ-135 Gas Sensor](https://www.amazon.de/AZDelivery-MQ-135-Quality-Compatible-Arduino-Blue/dp/B07CNR9K8P?ref_=ast_sto_dp&th=1)
1. **Air Quality Sensor:**

- [ ] [Wind Sensor](https://www.amazon.de/Surveillance-Transmitter-Housing-Anemometer-Supplies/dp/B0CC339PPP/ref=sr_1_14_sspa?crid=12IXPHB7F8UJT&keywords=tx20%2Ftx23+wind+speed%2Fdirection+sensor&qid=1699226035&sprefix=wind+direction%2Caps%2C125&sr=8-14-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9tdGY&psc=1)
1. **Wind Sensor:**
   - Cheap but almost no information

- [ ] [Water Level Sensor](https://www.amazon.de/-/en/CQRobot-Ocean-Compatible-Irrigation-Agriculture/dp/B07ZMGW3QJ/ref=pd_sbs_sccl_2_2/258-3489397-5850609?pd_rd_w=aWaGF&content-id=amzn1.sym.6c0521be-6c2b-450c-bb72-af8082730381&pf_rd_p=6c0521be-6c2b-450c-bb72-af8082730381&pf_rd_r=4VAPPEG0A39AV8PY7DCT&pd_rd_wg=rJez1&pd_rd_r=229ae184-8183-4b33-bdf2-94b77fd9fe25&pd_rd_i=B07ZMGW3QJ&psc=1)
1. **Water Level Sensor:**

- [x] [Water Quality Sensor (TDS)](https://www.amazon.de/Quality-Analogue-Monitoring-Industrial-Hydroponics/dp/B084P7W91K/ref=sr_1_1_sspa?crid=2RSW9Y4RJVV9L&keywords=tds%2Fec+sensor+arduino&qid=1699227480&s=industrial&sprefix=tds%2Fec+sensor+arduini%2Cindustrial%2C83&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&)


# Other components:

- [ ] [Set of potentiometers](https://www.amazon.de/dp/B0BLC2PYXT?ref=ppx_yo2ov_dt_b_product_details&th=1)
- [ ] [Buffer solutions](https://www.amazon.de/dp/B08JTYR7NZ?ref=ppx_yo2ov_dt_b_product_details&th=1)
- [ ] [Mini Breadboard](https://www.amazon.de/dp/B07KKJSFM1?psc=1&ref=ppx_yo2ov_dt_b_product_details)

# WIFI Hot-spot with LTE

Probably the easiest way is to use a mobile router with SIM card access, as it can connect up to 10 devices, which will probably be sufficient for several sensors on each controller.

> [!IMPORTANT]
> Adjustment regarding the problem with the network inside the container:

- [ ] [Hot-spot](https://www.ebay.de/itm/121890816869) 

- [ ] [Antenna extension](https://www.amazon.com/Cellular-Antenna-Connector-Nighthawk-Hotspots/dp/B0BFL8H33D/ref=sr_1_1_sspa?keywords=ts9+antenna&qid=1702147750&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)

These antennas could be placed outside (near the plans), while the main hot spot will stay inside for the connection with the controllers and other devices.
