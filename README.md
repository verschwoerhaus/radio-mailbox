# Mailbox sensor
ATtiny84 + RFM95 as letterbox sensor as described here: [ct.de/y7yx](https://ct.de/y7yx)

Forked from [jamct/radio-mailbox](https://github.com/jamct/radio-mailbox). Modified for use with PlatformIO, automatic sensor calibration on startup (instead of hardcoding a threshold) and AA power supply (for longer battery life time).

* **[00_circuit_diagram](/00_circuit_diagram)** KiCAD schematics
* **[02_serial](/02_serial)** Small sketch to test sensor (printing values to serial)
* **[03_lora_test](/03_lora_test)** Sketch to test RFM95W LoRaWAN module (sending battery voltage every 32 seconds)
* **[04_sensor_ready](/04_sensor_ready)** Sketch to use in production
* **[99_case](/99_case)** STL files for 3d printed case


## Wiring
**When using PlatformIO, make sure you are using the ALTERNATIVE PINOUT!** A good pinout diagram for ATTiny84 can be found here: <https://raw.githubusercontent.com/SpenceKonde/ATTinyCore/master/avr/extras/Pinout_x4.jpg>

Circuit diagram:

![Circuit diagram](/00_circuit_diagram/briefkastensensor.png)


