# CanSat Project

## Overview

This project involves a CanSat (a satellite simulation) using an Arduino Nano and various sensors and modules. The system collects environmental data such as temperature, pressure, and distance, and transmits this data using a radio module. The project demonstrates the integration of multiple sensors and data communication.

## Components and Sensors

- **Arduino Nano:** Microcontroller board for managing sensors and data processing.
- **DS18B20 Temperature Sensor:** Measures ambient temperature.
- **BMP280 Pressure Sensor:** Measures atmospheric pressure.
- **HYSR505 Sonar Sensor:** Measures distance to an object.
- **RF24 Radio Transmitter & Receiver:** Transmits and receives data wirelessly.
- **5V LiPo Battery:** Powers the Arduino and sensors.
- **Voltage Converter:** Ensures the correct voltage for components.
- **Jumper Wires:** Used for connecting components.

## Circuit Diagram

Circuit diagram including all details attached in CanSat-Project.pdf

## Installation and Setup

1. **Install Arduino IDE:**
   - Download and install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).

2. **Install Libraries:**
   - Open the Arduino IDE and go to `Sketch > Include Library > Manage Libraries...`.
   - Install the following libraries:
     - `OneWire`
     - `DallasTemperature`
     - `Adafruit BMP280`
     - `RF24`

3. **Upload the Code:**
   - Connect your Arduino Nano to your computer using a USB cable.
   - Open the Arduino IDE and paste the code from `project.ino` into a new sketch.
   - Select the correct board and port from `Tools > Board` and `Tools > Port`.
   - Click the upload button to compile and upload the code to the Arduino Nano.

## Code Overview

The provided code integrates the following functionalities:

- **Temperature Measurement:** Reads temperature data from the DS18B20 sensor.
- **Pressure Measurement:** Reads pressure data from the BMP280 sensor.
- **Distance Measurement:** Reads distance data from the HYSR505 sonar sensor.
- **Data Transmission:** Sends the collected data using the RF24 radio module.
- **Serial Monitor Output:** Prints sensor data to the Serial Monitor for real-time monitoring.

## Running the Project

After uploading the code to the Arduino Nano, the system will begin collecting data from the sensors and transmitting it wirelessly. You can monitor the data using a compatible RF24 receiver or by observing the Serial Monitor output.
