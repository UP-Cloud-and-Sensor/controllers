#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Arduino.h>
#include "secret.h"

#define PhSensorPin 32
#define TSensorPin 33
#define TdsSensorPin 34
#define VREF 3.3              // analog reference voltage(Volt) of the ADC
#define SCOUNT  30            // sum of sample point
// #define VCC 5.0
float adc_resolution = 4096.0;

int analogBufferPH[SCOUNT];     // store the analog value in the array, read from ADC
int analogBufferTDS[SCOUNT];
int analogBufferT[SCOUNT];
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0;
int copyIndex = 0;

float phValue = 7.0;
float averageVoltage = 0;
float tdsValue = 0;
float temperature = 25;       // current temperature for compensation

WiFiClient espClient;
PubSubClient client(espClient);

String getTimeData() {
  // Implement your own logic to get time data
  // For example, you can use the built-in time functions or an NTP client
  // and format the time data as a string.
  // Replace the following line with your actual time retrieval logic.
  return String(millis() / 1000); // Example: Milliseconds since boot as time data
}

// median filtering algorithm
int getMedianNum(int bArray[], int iFilterLen){
  int bTab[iFilterLen];
  for (byte i = 0; i<iFilterLen; i++)
  bTab[i] = bArray[i];
  int i, j, bTemp;
  for (j = 0; j < iFilterLen - 1; j++) {
    for (i = 0; i < iFilterLen - j - 1; i++) {
      if (bTab[i] > bTab[i + 1]) {
        bTemp = bTab[i];
        bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
      }
    }
  }
  if ((iFilterLen & 1) > 0){
    bTemp = bTab[(iFilterLen - 1) / 2];
  }
  else {
    bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
  }
  return bTemp;
}

void setup_wifi() {
  delay(10);
  // Connect to Wi-Fi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

float calcPH (float voltage) {
    return 7 + ((2.5 - voltage) * 2.8);
}

float calcTDS (float voltage) {
  return (133.42*voltage*voltage*voltage - 255.86*voltage*voltage + 857.39*voltage)*0.5;
}

void setup() {
  Serial.begin(921600);
  pinMode(PhSensorPin,INPUT);
  pinMode(TSensorPin,INPUT);
  pinMode(TdsSensorPin,INPUT);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  static unsigned long analogSampleTimepoint = millis();
  if(millis()-analogSampleTimepoint > 40U){     //every 40 milliseconds,read the analog value from the ADC
    analogSampleTimepoint = millis();
    analogBufferTDS[analogBufferIndex] = analogRead(TdsSensorPin);    //read the analog value and store into the buffer
    analogBufferPH[analogBufferIndex] = analogRead(PhSensorPin);
    analogBufferT[analogBufferIndex] = analogRead(TSensorPin);
    analogBufferIndex++;
    if(analogBufferIndex == SCOUNT){ 
      analogBufferIndex = 0;
    }
  }   
  
  static unsigned long printTimepoint = millis();
  if(millis()-printTimepoint > 800U){
    printTimepoint = millis();
    averageVoltage = getMedianNum(analogBufferTDS,SCOUNT) * (float)VREF / adc_resolution; 
    float compensationCoefficient = 1.0+0.02*(temperature-25.0);
    float compensationVoltage=averageVoltage/compensationCoefficient;
    tdsValue = calcTDS(compensationVoltage);
    // for(copyIndex=0; copyIndex<SCOUNT; copyIndex++){
    //   analogBufferTemp[copyIndex] = analogBufferTDS[copyIndex];
    // }
    averageVoltage = getMedianNum(analogBufferPH,SCOUNT) * (float)VREF / adc_resolution; 
    phValue = calcPH(averageVoltage);
    // Serial.print("TDS Value:");
    // Serial.print(tdsValue,0);
    // Serial.println("ppm");
    // Serial.print("pH Value:");
    // Serial.println(phValue,0);
  }
  // Get current local time
  String timeData = getTimeData();

  // Create a JSON document
  const size_t capacity = JSON_OBJECT_SIZE(5) + 100;
  DynamicJsonDocument doc(capacity);

  // Add time data to the JSON document
  doc["tag"] = "UP_1";
  doc["time"] = timeData;
  doc["pH"] = phValue;
  doc["TDS"] = tdsValue;
  doc["T"] = 25.0;

  // Serialize JSON to a String
  String jsonString;
  serializeJson(doc, jsonString);

  // Publish JSON data to MQTT broker
  static unsigned long sendTimepoint = millis();
  if(millis()-sendTimepoint > 5000U){
    sendTimepoint = millis();
    client.publish(dataTopic, jsonString.c_str());
    Serial.print("TDS Value:");
    Serial.print(tdsValue,0);
    Serial.println("ppm");
    Serial.print("pH Value:");
    Serial.println(phValue,0);
  }
  delay(1000); // Adjust the delay based on your needs
}

