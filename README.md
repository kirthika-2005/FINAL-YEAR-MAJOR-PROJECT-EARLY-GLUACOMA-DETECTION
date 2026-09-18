# Smart Ophthalmic Monitoring System Using AI for Predictive Intra-Ocular Pressure Assessment and Early Glaucoma Detection

An IoT-enabled smart tonometer prototype designed for intra-ocular pressure (IOP) monitoring, AI-assisted signal analysis, local OLED display, and remote cloud visualization.

## Project Overview

Glaucoma can progress without noticeable early symptoms, making regular IOP monitoring important. The proposed system combines optical sensing, embedded processing, AI-based signal analysis, and IoT connectivity to support portable and remote IOP monitoring.

The project report describes a non-invasive measurement approach in which an air-puff or rebound stimulus produces slight corneal deformation. Optical sensing captures the response, the ESP32 performs embedded processing and communication, and the processed IOP result is shown on an OLED and transmitted to a cloud platform for monitoring.

## Key Features

- Non-contact / non-invasive IOP measurement concept
- Optical sensing of corneal deformation
- ESP32-based embedded controller
- Signal conditioning and noise filtering
- AI/CNN-based IOP prediction concept
- Sensor-drift and motion/noise compensation concept
- 128×64 OLED local display
- Wi-Fi-based IoT communication
- Cloud-based IOP data logging and visualization
- Live pressure graph and remote monitoring
- Abnormal-reading alert concept
- Portable, low-cost prototype design

## System Architecture

```text
Eye / Corneal Response
        │
        ▼
Optical / Spectral Sensor
        │
        ▼
Signal Conditioning + Noise Filtering
        │
        ▼
ESP32 Embedded Controller
        │
        ├──────────────► OLED Display
        │
        ▼
AI / CNN-Based Processing
        │
        ▼
Predicted IOP Value
        │
        ▼
Wi-Fi / IoT Communication
        │
        ▼
Cloud Platform / Dashboard
        │
        ├────────► Data Log
        ├────────► Live Graph
        └────────► Remote Alert / Monitoring
```

## Hardware Mentioned in the Project Report

- ESP32 microcontroller
- AS7265x 18-channel spectral / optical sensor
- Air-puff / rebound mechanism
- MPX5010 pressure sensor
- LM358 signal-conditioning circuit
- ADS1115 external ADC
- 0.96-inch SSD1306 128×64 OLED display
- Push button / control key
- Li-Po / rechargeable power supply
- Wi-Fi communication through ESP32

## Software & Technologies

- Embedded C / Arduino IDE
- Python
- Thonny IDE
- Visual Studio Code
- CNN / Artificial Intelligence
- IoT communication
- ThingSpeak cloud platform
- MQTT / HTTP communication concept

## AI Module

The report describes a CNN-based AI module for analysing processed corneal-deformation/sensor patterns. The stated purpose is to reduce the effect of noise and motion artifacts, compensate for sensor drift, and estimate IOP more reliably.

> **Important:** The repository does not invent or include a CNN training script that was not supplied with the project materials. Add the actual trained model, dataset, preprocessing code, and training notebook only when those project files are available.

## IoT Output

The project includes cloud-side output showing recorded IOP values and a live pressure graph. Example readings visible in the supplied output include values such as 12–19 mmHg.

The cloud output demonstrates:

- Date/time-wise IOP data logging
- Pressure visualization through a live graph
- Remote access to recorded measurements

## Embedded Source Code

`src/esp32_component_test.ino` contains the Arduino/ESP32 component-test sketch supplied in the project report appendix. It tests the OLED display and push button and provides a menu entry for the TCS34725 component test.

This sketch is kept separately as a **hardware/component test**, because it is not the complete AI-based IOP measurement firmware. The complete project architecture described in the report also includes the optical sensor, signal conditioning, AI processing, Wi-Fi/cloud communication, and alert modules.

## Output Screenshots

### Cloud Data Log

![Cloud Data Log](outputs/cloud-data-log.jpeg)

### Live Data Graph

![Live Data Graph](outputs/live-data-graph.jpeg)

### Prototype / OLED Output

![Smart Tonometer Prototype](outputs/smart-tonometer-prototype.jpeg)

## Project Documentation

The `docs/` folder contains the final project report and presentation supplied for this project.

## How to Run the Component Test

1. Install Arduino IDE.
2. Install the required OLED and button libraries used by the sketch.
3. Open `src/esp32_component_test.ino`.
4. Select the appropriate ESP32/Arduino board and COM port.
5. Upload the sketch.
6. Open Serial Monitor at **9600 baud**.
7. Follow the menu shown in the Serial Monitor.

## Project Applications

- Home-based glaucoma monitoring
- Remote and rural healthcare support
- Tele-ophthalmology
- Long-term IOP trend monitoring
- Post-treatment follow-up
- Research and clinical studies

## Project Team

- Gayathri G
- Hemalatha V
- Kirthika P
- Shobana G

**Department:** Electronics and Communication Engineering  
**Institution:** Vidyaa Vikas College of Engineering and Technology, Tiruchengode  
**Academic Year:** 2025–2026

## Note on Medical Use

This repository documents an academic prototype. It is not a clinically validated medical device and its readings should not be used for diagnosis or treatment decisions without appropriate clinical validation and professional supervision.
