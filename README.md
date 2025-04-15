# 🌱 Smart Plant Watering System

A **Smart Plant Watering System** built using Arduino, designed to automate plant care by monitoring soil moisture levels and activating a water pump when the soil gets too dry. The system helps maintain healthy plant growth while conserving water using real-time sensors and an LCD display.

---

## 📦 Project Overview

This system reads soil moisture through a sensor and displays the status on an LCD. If moisture falls below a threshold, the water pump is activated and monitored using a water flow sensor. It turns off once sufficient water has been delivered.

---

## 🧰 Components Used

| Component               | Quantity |
|------------------------|----------|
| Arduino UNO            | 1        |
| Soil Moisture Sensor   | 1        |
| LCD (I2C 16x2)         | 1        |
| 5V Relay Module        | 1        |
| Mini Water Pump + Pipe | 1        |
| Water Flow Sensor      | 1        |
| Jumper Wires           | As needed |
| 9V Battery/Power Source| 1        |

---

## 💡 Features

- Real-time monitoring of soil moisture
- Automated plant watering using a relay and pump
- Water flow tracking to avoid overwatering
- LCD feedback on moisture level and water flow
- Energy-efficient and easy to deploy

---

## 🧪 Working Principle

1. **Soil Moisture Sensor**: Continuously reads moisture levels.
2. **LCD Display**: Shows the system status (Moisture level and Pump state).
3. **Relay Control**: Activates the pump based on moisture threshold.
4. **Water Flow Sensor**: Measures the amount of water being dispensed.
5. **Threshold Logic**:
   - Moisture > 950 → Water Pump ON (Low Moisture)
   - Moisture between 300–950 → Moisture is Medium
   - Moisture < 300 → Moisture is High (No watering needed)

---

## 🧾 Code Summary

- `analogRead(A0)` → Reads soil moisture
- `analogRead(A1)` → Reads water flow
- `digitalWrite(2, LOW)` → Turns ON pump
- LCD shows:
  - `"WaterPump ON/OFF"`
  - `"Moisture: high/mid/low"`
  - `"Flow: <value> mL/s"`

---

## 🚀 How to Run

1. **Unzip the `.rar` file provided** or clone the repository.
2. **Open the Arduino IDE.**
3. **Install the LiquidCrystal_I2C library** (if not already installed).
4. **Upload the `smart_plant.ino` sketch** to your Arduino UNO.
5. **Connect components as per the wiring diagram.**
6. **Power the setup via USB or 9V battery.**
7. **Observe the LCD for system status and plant watering actions.**

---

## 📁 Project Structure

```
Smart-PlantWatering-System/
├── public/                   # Optional if web-based
├── smart_plant.ino          # Arduino code
├── wiring_diagram.png       
├── Smart-PlantWatering-System.rar  # Archived version of the project
└── README.md
```

---

## 📊 LCD Output States

| Moisture Reading | LCD Line 1       | LCD Line 2           | Action          |
|------------------|------------------|-----------------------|------------------|
| > 950            | `WaterPump ON`   | `Moisture: low`       | Pump activates   |
| 300 - 950        | `WaterPump OFF`  | `Moisture: mid`       | No action        |
| < 300            | `WaterPump OFF`  | `Moisture: high`      | No action        |

---

## 🎯 Future Improvements

- Add Wi-Fi module for remote monitoring
- Log moisture and flow data to a cloud platform
- Add temperature/humidity sensors for environmental awareness
- Mobile app integration using Bluetooth
