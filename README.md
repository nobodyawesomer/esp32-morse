# Morse Project

A simple Morse encoder/decoder application using the ESP-IDF framework, for running on an ESP32-C3-DevKitC-1. Relies on the onboard addressable LED for outputting Morse signals, and an external input button or physical Morse key for input, hooked up to GPIO 10 by default. More project configuration is available with ESP-IDF's SDK Menuconfig GUI.

## Usage

Before project configuration and build, be sure to set the correct chip target using `idf.py set-target <chip_name>`.

### Hardware Required

- A development board with an addressable LED (RGB ftw!) such as the ESP32C3-DevKitC or ESP32S3-DevKitC.
- A button or Morse/Telegraph key.
- A USB cable to connect the Serial connection to your development environment.

### Configure the Project

Open the project configuration menu (`idf.py menuconfig`).

See the `Application Configuration` menu section for all configuration of the application itself.

### Build and Flash

Run `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type `Ctrl-]`.)

The application should start blinking with "CQ CQ HELLO R" and then you should be able to start inputting morse signals. You'll be able to see the inputted character in the serial monitor console.
