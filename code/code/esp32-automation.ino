#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ==== Wi-Fi Settings ====
const char* ssid = "V2029";
const char* password = "15092004";

// ==== MQTT Settings ====
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

// ==== LCD ====
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ==== Pump LED ====
#define PUMP_LED 25
#define SOIL_THRESHOLD 1500
#define TEMP_THRESHOLD 30.0

void callback(char* topic, byte* message, unsigned int length) {
  String msg;
  for (int i = 0; i < length; i++) {
    msg += (char)message[i];
  }

  int commaIndex = msg.indexOf(',');
  float temp = msg.substring(0, commaIndex).toFloat();
  int soil = msg.substring(commaIndex + 1).toInt();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: " + String(temp) + "C");
  lcd.setCursor(0,1);
  lcd.print("Soil: " + String(soil));

  if (soil < SOIL_THRESHOLD || temp > TEMP_THRESHOLD) {
    digitalWrite(PUMP_LED, HIGH);
  } else {
    digitalWrite(PUMP_LED, LOW);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(PUMP_LED, OUTPUT);
  lcd.init();
  lcd.backlight();

  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.println("ESP32-B Ready");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32-Display")) {
      Serial.println("MQTT connected");
      client.subscribe("greenhouse/data");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 2s");
      delay(2000);
    }
  }
}
