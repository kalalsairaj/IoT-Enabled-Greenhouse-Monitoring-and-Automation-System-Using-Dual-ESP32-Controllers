# IoT-Enabled Greenhouse Monitoring and Automation System Using Dual ESP32 Controllers


## 📌 Project Overview
This project is developed as part of a college submission by **Sairaj Kalal** and **Mohd Ismayeel Shaikh**.
It implements an **IoT greenhouse monitoring and automation system** using **two ESP32 controllers**—one for sensing and publishing data, and one for display/control.


---


## 🎯 Objectives
- Monitor temperature, humidity, and soil moisture in real‑time.
- Automate irrigation/ventilation based on thresholds.
- Enable remote monitoring via MQTT/IoT dashboard.


---


## 🛠️ Hardware & Software
- 2× **ESP32**
- **DHT22** (Temp & Humidity)
- **Soil Moisture** sensor (analog)
- **LCD 16×2 I2C** (0x27 address typical)
- **Relay / Pump / Fan** (or LED for demo)
- **MQTT broker** (e.g., `test.mosquitto.org`)
- **Arduino IDE** + libraries: PubSubClient, DHT sensor, LiquidCrystal I2C


---


## ⚙️ Architecture (2‑Node)
1. **ESP32‑A (Sensor Node)** reads DHT22 & soil sensor and publishes `temp,soil` to topic `greenhouse/data`.
2. **ESP32‑B (Automation/Display Node)** subscribes to `greenhouse/data`, shows values on LCD, and toggles pump/fan via relay.


---


## 📂 Repo Map
- `code/esp32-sensor.ino` – publishes sensor data (ESP32‑A)
- `code/esp32-automation.ino` – subscribes & controls pump/LCD (ESP32‑B)
- `docs/` – report or notes (optional)
- `images/` – circuit or screenshots (optional)


---


## 👨‍💻 Authors
- **Sairaj Kalal**
- **Mohd Ismayeel Shaikh**


---


## 🔒 Note on Secrets
Replace Wi‑Fi SSID/password placeholders in the `.ino` files before flashing. **Do not commit real passwords** to public repos.


---


## 📜 License
This project is open‑source under the **MIT License** (see `LICENSE`).
