#include <Arduino.h>

#define PhSensorPin 27
#define TSensorPin 26

int samples = 30;
float adc_resolution = 1024.0;

void setup()
{
    Serial.begin(921600);
    pinMode(PhSensorPin,INPUT);
    pinMode(TSensorPin,INPUT);
    Serial.println("pH Sense");
}

float ph (float voltage) {
    return 7 + ((2.5 - voltage) * 2.8);
}

void loop()
{
    int measurings=0;

    for (int i = 0; i < samples; i++)
    {
        measurings += analogRead(PhSensorPin);
        delay(10);

    }

    float voltage = 5 / adc_resolution * measurings/samples;
    Serial.print("pH= ");
    Serial.println(ph(voltage));
    delay(1000);
}