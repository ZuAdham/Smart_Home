# 🏠 Smart Home Project  

## 📌 Overview  
Welcome to the **Smart Home Project**!  
This project enhances home safety and comfort through the integration of two sub-systems:  
1. **Fire Emergency System**  
2. **Smart Room Temperature Control System**  

By leveraging sensors, actuators, and an ATmega32 microcontroller (ECU), the system provides a complete solution for fire detection, extinguishing, and smart temperature management.  

---

## 🔥 Fire Emergency System  

The Fire Emergency System is designed to detect fire incidents and take immediate action to mitigate the risk.  

### Components  
- **Flame Sensor** → Detects the presence of fire  
- **Smoke Sensor** → Detects the presence of smoke  
- **Water Pump** → Activates to extinguish the fire  
- **Buzzer** → Sounds an alarm to alert occupants  

### Functionality  
1. **Fire Detection**: Flame and smoke sensors continuously monitor the environment.  
2. **Interrupt Signal**: When fire or smoke is detected, the sensors send interrupt signals to the ECU.  
3. **Emergency Response**: The ECU processes the signals and activates the water pump.  
4. **Fire Extinguishing**: The pump continues until no fire/smoke is detected.  
5. **Alarm Activation**: The buzzer alerts occupants simultaneously.  

---

## 🌡️ Smart Room Temperature Control  

The Smart Room Temperature Control System ensures a comfortable environment by adjusting fan speed dynamically.  

### Components  
- **Temperature Sensor (LM35)** → Measures the current room temperature  
- **Fan (DC Motor)** → Adjusts its speed based on temperature  

### Functionality  
1. **Monitoring**: The LM35 continuously measures temperature.  
2. **Speed Control**: The ECU increases fan speed as temperature rises, maintaining comfort.  

---

## 🔧 Components Overview  
- **ATmega32 Microcontroller (ECU)** → Processes sensor signals and controls actuators  
- **Flame Sensor** → Detects fire  
- **Smoke Sensor** → Detects smoke  
- **Water Pump** → Sprays water when fire is detected  
- **Buzzer** → Provides audible alarm  
- **Temperature Sensor (LM35)** → Monitors temperature  
- **Fan (DC Motor)** → Adjusts speed according to temperature  

---

## ⚙️ Installation & Setup  

### Hardware Connections  
- Connect flame + smoke sensors → input pins on ATmega32  
- Connect water pump + buzzer → output pins  
- Connect temperature sensor → input pin  
- Connect fan → output pin  

### Software Configuration  
- Load the provided firmware onto ATmega32  
- Calibrate sensor values in the firmware  

### Testing  
- Simulate a fire scenario → confirm flame/smoke detection, pump, and buzzer  
- Adjust room temperature → verify fan speed response  

---

## 🚀 Usage  
- **Fire Emergency System** → Runs automatically, no user action required  
- **Smart Room Temperature Control** → Automatically adjusts fan speed  

---

## 🛠️ Maintenance  
- Regularly test flame/smoke sensors and water pump  
- Calibrate the temperature sensor periodically  
- Ensure fan and buzzer remain operational  

---

## 🐞 Troubleshooting  

**If the fire system doesn’t activate:**  
- Check sensor → ECU connections  
- Verify water pump + buzzer wiring and power  

**If the fan doesn’t adjust speed:**  
- Confirm temperature sensor wiring  
- Check fan control logic in firmware  

---
