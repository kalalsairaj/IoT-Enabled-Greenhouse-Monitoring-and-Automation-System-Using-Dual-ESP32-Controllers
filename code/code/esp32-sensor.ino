#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"


// ==== Wi-Fi Settings (replace before use) ====
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";


// ==== MQTT Settings ====
const char* mqtt_server = "test.mosquitto.org"; // or your broker IP


WiFiClient espClient;
PubSubClient client(espClient);


// ==== DHT Settings ====
#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);


// ==== Soil Sensor ====
#define SOIL_PIN 34 // Analog input


void setup() {
Serial.begin(115200);


WiFi.begin(ssid, password);
Serial.print("Connecting to Wi-Fi");
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("
WiFi connected");


client.setServer(mqtt_server, 1883);
dht.begin();
}


void loop() {
if (!client.connected()) {
reconnect();
}
client.loop();


// Read sensors
float temp = dht.readTemperature();
int rawSoil = analogRead(SOIL_PIN);
int soilValue = 4095 - rawSoil; // invert: wet=low, dry=high


// Create payload
String payload = String(temp) + "," + String(soilValue);


// Publish
client.publish("greenhouse/data", payload.c_str());
Serial.println("Sent: " + payload);


delay(5000); // every 5s
}


void reconnect() {
while (!client.connected()) {
Serial.println("Connecting to MQTT...");
if (client.connect("ESP32-Sensor")) {
Serial.println("MQTT connected");
} else {
Serial.print("Failed, rc=");
Serial.print(client.state());
Serial.println(" retrying in 2s");
delay(2000);
}
}
}
