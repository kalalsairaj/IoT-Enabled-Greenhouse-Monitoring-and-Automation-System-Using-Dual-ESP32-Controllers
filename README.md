# IoT-Enabled Greenhouse Monitoring and Automation System Using Dual ESP32 Controllers

## 📌 Project Overview
This project is developed as part of a college submission by **Sairaj Kalal** and **Mohd Ismayeel Shaikh**.  
It focuses on building an **IoT-based greenhouse monitoring and automation system** using **dual ESP32 controllers** for real-time sensing and control.

The system allows efficient monitoring of temperature, humidity, soil moisture, and light intensity inside a greenhouse while automating irrigation and ventilation processes.

---

## 🎯 Objectives
- To monitor critical greenhouse parameters in real-time.
- To automate irrigation and ventilation using ESP32 controllers.
- To enable wireless IoT connectivity for remote monitoring.
- To improve plant growth efficiency and reduce manual intervention.

---

## 🛠️ Hardware & Software Used
- **ESP32 Controllers** (2 units – one for sensing, one for automation)
- DHT11/DHT22 Sensor (Temperature & Humidity)
- Soil Moisture Sensor
- Light Sensor (LDR)
- Relays & Actuators (for fan, water pump, etc.)
- Blynk / MQTT / ThingSpeak (for IoT monitoring)
- Arduino IDE / PlatformIO (for coding)

---

## ⚙️ System Working
1. One ESP32 collects data from sensors (temperature, humidity, soil moisture, light).  
2. Data is transmitted wirelessly to another ESP32 responsible for automation.  
3. Automation ESP32 controls irrigation pumps and fans based on sensor thresholds.  
4. IoT dashboard (Blynk/ThingSpeak/MQTT) allows remote monitoring and manual override.  

---

## 👨‍💻 Team Members
- **Sairaj Kalal**  
- **Mohd Ismayeel Shaikh**

---

## 📂 Repository Contents
- `/code` → Arduino/ESP32 source code  
- `/docs` → Documentation and reports  
- `/images` → Circuit diagrams, screenshots (if available)

---

## 📜 License
This project is open-source under the MIT License.
