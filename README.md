# ESP8266 LED Blink — NodeMCU (PlatformIO)

Minimal example to blink the on-board LED on a NodeMCU (ESP-12E) using the esp8266-rtos-sdk and PlatformIO.

Contents
- `platformio.ini` — PlatformIO project configuration
- `src/main.c` — Blink application
- `include/` — optional headers
- `lib/` — optional libraries

Build and upload

1. Build:
```
platformio run --environment nodemcuv2
```
2. Upload:
```
platformio run -e nodemcuv2 -t upload
```
3. Monitor serial (boot messages use 74880 baud; app logs may use 115200):
```
platformio device monitor -e nodemcuv2 -b 115200
```

Notes
- The on-board LED on many NodeMCU modules is connected to GPIO2 and is active-low (0 = LED on).
- If you see garbled boot text, try `-b 74880` to view bootloader messages.
- If the built-in LED does not blink, verify the board variant or test with an external LED on GPIO2.

License
This project is released under the MIT License — see `LICENSE`.
