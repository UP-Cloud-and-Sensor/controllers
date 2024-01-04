#include <Arduino.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);
  pinMode(35,INPUT);
}

void loop() {
  Serial.println(analogRead(35));
  // float voltage = 5 / adc_resolution * measurings/samples;
  delay(100);
}