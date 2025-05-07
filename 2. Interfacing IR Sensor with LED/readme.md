# 🚦 IR Sensor Obstacle Detection with LED 🚧

This simple Arduino project uses an **IR sensor** to detect obstacles and turns an **LED** on or off based on the detection. It’s perfect for beginners learning about sensors and digital input/output! 😃

---

## 🔧 Components Used

- 🟢 **IR Sensor** (Digital output)  
- 🔴 **LED**  
- 🟩 **Arduino Board** (e.g., Uno, Nano)  
- 🧵 Jumper Wires  
- 🔌 USB Cable for uploading code  

---

## 🔌 Circuit Connections

| Component         | Arduino Pin |
|------------------|--------------|
| IR Sensor Output  | D2           |
| LED Anode (+)     | D13          |
| LED Cathode (-)   | GND          |

> **Note:** Use a resistor (~220Ω) with the LED to prevent damage. 🛡️

---

## 🧠 How It Works

1. The **IR sensor** sends out infrared light and checks for reflection.  
2. If it detects an obstacle (IR reflection is received), it sends **LOW (0)**.  
3. The Arduino reads this and **turns ON the LED**.  
4. If no obstacle is detected, sensor sends **HIGH (1)**, and the **LED is OFF**.  

---

## 🎯 Output Behavior

| IR Sensor State | LED State | Meaning                  |
|----------------|-----------|---------------------------|
| HIGH (1)       | OFF       | No obstacle detected 🙌   |
| LOW (0)        | ON        | Obstacle detected 🧱       |

---

## 📦 Applications

- 🤖 Obstacle detection in robots  
- 🚗 Parking assistant systems  
- 🛡️ Security systems  
- 🚪 Automatic doors  

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---
