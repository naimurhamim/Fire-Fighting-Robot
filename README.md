<div align="center">

# 🔥 Fire Fighting Robot

![Robotics](https://img.shields.io/badge/Robotics-Fire%20Fighter-red?style=for-the-badge)
![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![NodeMCU](https://img.shields.io/badge/NodeMCU-ESP8266-blue?style=for-the-badge)
![IoT](https://img.shields.io/badge/IoT-Autonomous-orange?style=for-the-badge)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**An autonomous robot that detects fire using sensors, navigates toward it, extinguishes it — and alerts the user's mobile phone in real time.**

</div>

---

## 📖 About

The **Fire Fighting Robot** is an IoT-powered autonomous robot designed to detect and extinguish fires without human intervention. Using flame sensors, the robot navigates toward the source of fire, activates a water pump to extinguish it, and simultaneously sends a real-time alert to the user's mobile phone via NodeMCU (ESP8266) WiFi module.

This project combines embedded systems, robotics, and IoT connectivity to create a practical fire safety solution for homes, warehouses, and industrial environments.

---

## ⚙️ How It Works

```
[Flame Sensors (Left / Center / Right)]
          │
          ▼
      [Arduino Uno]  ──── Serial ────  [NodeMCU ESP8266]
          │                                    │
    ┌─────┼─────┐                        [WiFi Alert 📱]
    │           │                       (User's Phone)
[DC Motors]  [Water Pump]
(Navigate)   (Extinguish)
```

**Step-by-step flow:**
1. Flame sensors scan left, center, and right for fire
2. Arduino detects which direction fire is detected
3. Motors steer the robot toward the flame
4. Water pump activates to extinguish the fire
5. NodeMCU sends WiFi notification to the user's mobile

---

## ✨ Features

| Feature | Description |
|---|---|
| 🔥 **Fire Detection** | Three flame sensors for left/center/right coverage |
| 🤖 **Autonomous Navigation** | Robot steers itself toward the fire source |
| 💧 **Auto Extinguishing** | Water pump activates to put out the fire |
| 📱 **Mobile Alert** | NodeMCU sends real-time WiFi alert to phone |
| 🌐 **IoT Connected** | ESP8266 for wireless communication |
| ⚡ **Fast Response** | Real-time sensor processing with minimal delay |

---

## 🧰 Hardware Components

| Component | Quantity | Purpose |
|---|---|---|
| **Arduino Uno** | 1 | Main microcontroller |
| **NodeMCU ESP8266** | 1 | WiFi & mobile alert |
| **Flame Sensor Module** | 3 | Fire detection (L/C/R) |
| **DC Motors** | 2 | Robot movement |
| **L298N Motor Driver** | 1 | Motor speed & direction control |
| **Mini Water Pump** | 1 | Fire extinguishing |
| **Relay Module** | 1 | Pump control |
| **Robot Chassis** | 1 | Physical frame with wheels |
| **Water Container** | 1 | Water reservoir |
| **Battery Pack** | 1 | Power supply |
| **Jumper Wires** | — | Circuit connections |

---

## 🗂️ Repository Contents

```
Fire-Fighting-Robot/
│
├── arduino_code/                          # Arduino source code
│   └── fire_robot.ino                     # Main robot control code
├── NodeMCU_code/                          # NodeMCU WiFi alert code
│   └── nodemcu_alert.ino
│
├── Fire fighting project report.pdf      # Full project report
├── Hardware test video.mp4               # Hardware demo
├── Software test video.mp4               # Software/simulation test
├── Project Code.docx                     # Code documentation
└── LICENSE
```

📄 **[View Full Project Report](Fire%20fighting%20porject%20report%20.pdf)**  
🎥 **[Watch Hardware Demo](Hardware%20test%20video.mp4)**  
🖥️ **[Watch Software Test](Software%20test%20video.mp4)**

---

## 🛠️ Setup & Upload

### Arduino Code
1. Open `arduino_code/` folder in **Arduino IDE**
2. Select **Board:** Arduino Uno
3. Connect Arduino via USB and select correct **Port**
4. Click **Upload** ▶️

### NodeMCU Code
1. Open `NodeMCU_code/` folder in **Arduino IDE**
2. Install **ESP8266 board** in Board Manager
3. Enter your **WiFi SSID** and **Password** in the code
4. Select **Board:** NodeMCU 1.0 (ESP-12E Module)
5. Click **Upload** ▶️

---

## 📐 Navigation Logic

| Sensor Reading | Robot Action |
|---|---|
| Center flame detected | Move forward toward fire |
| Left flame detected | Turn left |
| Right flame detected | Turn right |
| All sensors detect fire | Stop & activate pump |
| No flame detected | Patrol / standby |

---

## 🔮 Future Improvements

- [ ] Camera integration for visual fire detection
- [ ] Larger water tank with refill sensor
- [ ] GPS tracking for outdoor deployment
- [ ] Multi-robot swarm coordination
- [ ] Smoke and gas sensor integration
- [ ] Emergency services auto-call via GSM module

---

## 📄 License

Licensed under the **MIT License** — see [LICENSE](LICENSE) for details.

---

## 👨‍💻 Author

**MD Naimur Rashid**  
Department of Internet of Things and Robotics Engineering  
University of Frontier Technology, Bangladesh (UFTB)

[![GitHub](https://img.shields.io/badge/GitHub-naimurhamim-181717?style=for-the-badge&logo=github)](https://github.com/naimurhamim)

---

<div align="center">
  <i>⭐ Star this repo if you find this fire safety robot useful!</i>
</div>
