# 🏠 Arduino-Based Smart Home Automation  
**Relay + Temperature Sensor (DHT11) + Motion Sensor (PIR)**

This project uses an **Arduino Uno** to control home appliances based on **temperature** and **motion detection**:
- 🌡 If the temperature exceeds **30°C**, a **cooling fan** turns on automatically.
- 🚶 If motion is detected, a **light** turns on for **30 seconds**.

---

## ⚙️ Components Required
| Component                  | Quantity |
|----------------------------|----------|
| Arduino Uno                | 1        |
| Relay Module (5V)          | 1        |
| DHT11 Temperature Sensor   | 1        |
| PIR Motion Sensor          | 1        |
| Cooling Fan (AC/DC)        | 1        |
| Light Bulb + Holder        | 1        |
| Jumper Wires               | As needed |
| Breadboard                 | 1        |
| USB Cable                  | 1        |

---

## 🔌 Circuit Diagram

**Connections:**
- **DHT11**
  - VCC → 5V
  - GND → GND
  - DATA → Digital Pin 2
- **PIR Motion Sensor**
  - VCC → 5V
  - GND → GND
  - OUT → Digital Pin 3
- **Relay Module**
  - VCC → 5V
  - GND → GND
  - IN → Digital Pin 4
- **Appliances**
  - Fan → Relay NO & COM
  - Light → Relay NO & COM (or second relay if separate control needed)

> ⚠️ If controlling AC appliances, **be cautious** — use proper insulation and safety measures.
