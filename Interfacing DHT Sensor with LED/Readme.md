# 🌡️ Temperature Monitoring with Raspberry Pi / BeagleBone and LED Alert System

## 🧩 Problem Statement

Understand the connectivity of a Raspberry Pi or BeagleBone board with a temperature sensor. Develop an application to read environmental temperature and generate alerts using LEDs when a specified threshold is crossed.

---

## 🎯 Objective

- 🔌 Interface a temperature sensor with Raspberry Pi / BeagleBone.
- 📊 Continuously monitor and read temperature data.
- 🚨 Trigger an LED alert if temperature exceeds a defined threshold.

---

## 🛠️ Hardware Requirements

- 🖥️ Raspberry Pi (any model) or BeagleBone Black
- 🌡️ Temperature Sensor (e.g., DHT11, DS18B20)
- 💡 LED(s)
- 🧰 Resistors (e.g., 220Ω)
- 🔗 Breadboard and jumper wires
- 🔋 Power supply or USB cable

---

## 💻 Software Requirements

- 🐍 Python 3
- 📦 Required Python Libraries:
  - `Adafruit_DHT` – for DHT sensor readings
  - `RPi.GPIO` – for controlling GPIO pins on Raspberry Pi
  - `Adafruit_BBIO.GPIO` – if using BeagleBone
- 🖥️ Any Python IDE or text editor

---

## 🔍 How It Works

1. The sensor reads the surrounding temperature.
2. The microcontroller processes this data using Python code.
3. If the temperature rises above a set threshold (e.g., 30°C), an LED turns ON as an alert.
4. If below the threshold, the LED remains OFF.

---

## 📝 Notes

- Make sure the sensor is connected to the correct GPIO pin.
- Use a pull-up resistor if required by the sensor's specifications.
- The same concept can be extended with buzzers or multiple LEDs for advanced alerts.

---

## 📄 License

This project is open-source and intended for educational use. 🚀
