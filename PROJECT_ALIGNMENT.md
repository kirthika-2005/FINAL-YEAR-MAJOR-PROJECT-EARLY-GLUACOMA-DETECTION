# Project-to-GitHub Alignment

This repository was organized from the supplied final-year project report, presentation, Arduino appendix code, and output screenshots.

## What the report says the complete system contains

- Optical/spectral sensing of corneal deformation
- Air-puff or rebound measurement mechanism
- Signal conditioning and noise filtering
- ESP32 embedded processing and Wi-Fi
- AI/CNN-based processing and IOP prediction
- OLED display
- Cloud storage and visualization
- Mobile/web monitoring and abnormal-reading alerts

## What is actually included as executable source here

The supplied appendix source is a component-test Arduino sketch. It provides menu-based tests for the OLED and push button and lists the TCS34725 sensor test without implementing the sensor test.

Therefore the repository intentionally does **not** claim that this one sketch is the complete AI/IoT firmware. This keeps the GitHub project technically honest while still documenting the full system architecture described in the report.

## Output evidence included

The supplied screenshots show:

1. Cloud data logging with timestamped `Eye_Pressure` values.
2. A live pressure graph.
3. The physical prototype with OLED output showing IOP and status.

## Recommended future source additions

When the original project files are available, add them under separate folders:

```text
src/
  esp32_main_firmware.ino
  sensor_acquisition.ino
  oled_display.ino
  wifi_cloud.ino

ai/
  preprocessing.py
  train_cnn.py
  predict_iop.py
  model/

data/
  README.md
```

Only add these files when they represent the actual project implementation; do not create placeholder code and present it as the original project.
