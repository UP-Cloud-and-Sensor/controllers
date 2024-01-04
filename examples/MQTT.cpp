#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Arduino.h>
  
// Update these with your WiFi and MQTT broker details
const char* ssid = "XXX";
const char* password = "xxx";
const char* mqtt_server = "xxx";

const char* timeTopic = "time"; // MQTT topic to publish time data

WiFiClient espClient;
PubSubClient client(espClient);

String getTimeData() {
  // Implement your own logic to get time data
  // For example, you can use the built-in time functions or an NTP client
  // and format the time data as a string.
  // Replace the following line with your actual time retrieval logic.

  return String(millis() / 1000); // Example: Milliseconds since boot as time data
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

void setup() {
  Serial.begin(921600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Get current time
  String timeData = getTimeData();

  // Create a JSON document
  const size_t capacity = JSON_OBJECT_SIZE(1) + 20;
  DynamicJsonDocument doc(capacity);

  // Add time data to the JSON document
  doc["time"] = timeData;

  // Serialize JSON to a String
  String jsonString;
  serializeJson(doc, jsonString);

  // Publish JSON data to MQTT broker
  client.publish(timeTopic, jsonString.c_str());

  delay(1000); // Adjust the delay based on your needs
}

