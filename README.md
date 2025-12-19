# Universitat Oberta de Catalunya. Máster en Ciberseguridad y Privacidad. Evaluación de ciberseguridad de un sistema de IoT basado en Arduino — Examples

This repository contains small, mostly self-contained Arduino examples used for teaching and demonstration in the accompanying essay. Examples illustrate common mistakes (insecure storage, unsafe memory operations, hard-coded credentials, basic crypto, serial communication patterns, bootloader code, etc.). Use them only for learning and in isolated test environments.

Quick summary
-------------
- Purpose: educational examples to demonstrate insecure patterns and their safer alternatives.
- Safety: run examples only on devices you own and inside isolated lab networks. Do not use these examples to attack or probe third-party systems.

How to use these examples
------------------------
- Arduino IDE: open the .cpp/.c file from the desired `src/codigo*` folder and upload to your board.
- PlatformIO: examples are provided as source files inside `/src`. To build with PlatformIO, create a project per example (or copy the example file to `src/main.cpp`) and run `pio run` and `pio run -t upload`.
- Serial monitor: use `pio device monitor -b <baud>` or the Arduino Serial Monitor to view output.

Contents (per `src/codigo*` folder)
----------------------------------
- `codigo1` — `out_of_buffer.cpp`: Demonstrates a classic stack buffer overflow using `strcpy` into a too-small buffer.
- `codigo2` — `wifi_password_available.cpp`: Shows hard-coded Wi‑Fi credentials and insecure connection handling.
- `codigo3` — `escribir_codigo_eeprom.cpp`: Writes a password string into EEPROM (persistent secret storage example).
- `codigo4` — `leer_codigo_eeprom.cpp`: Reads and prints EEPROM-stored password to serial (exposure of stored secrets).
- `codigo5` — `single_key_value.cpp`: Stores a secret in a `String` variable (illustrates in-memory/flash exposure and unsafe use of `String`).
- `codigo6` — `arduino_isp.cpp`: The ArduinoISP programmer sketch (official example for using an Arduino as an ISP programmer).
- `codigo7` — `blink_two_seconds.cpp`: Simple Blink example (2s interval) — baseline hardware test.
- `codigo8` — `blink_500_miliseconds.cpp`: Simple Blink example (500 ms interval).
- `codigo9` — `serial_writer.cpp`: Periodically composes and sends serial messages (producer example).
- `codigo10` — `serial_reader.cpp`: Reads serial input and prints received lines (consumer example).
- `codigo11` — `serial_observer.cpp`: Uses `SoftwareSerial` to listen on two ports and print messages (multi-port observer example).
- `codigo12` — `keys_generator.cpp`: Uses `micro-ecc` to generate a keypair, sign a message and verify the signature (demonstrates basic crypto on constrained devices).
- `codigo13` — `optiboot.c` (+ `pin_defs.h`, `stk500.h`): Optiboot bootloader source (advanced/bootloader-level code, not an Arduino sketch).

Recommended next steps
----------------------
- Pick an example folder and open its main `.cpp`/`.c` file to read intent and safety notes.
- Run examples only in isolated lab networks and with test boards.
- If you want, I can:
  - extract each example into a separate PlatformIO project for easier building, or
  - add short README.md files inside each `src/codigo*` folder summarizing purpose, expected serial output, and build/upload steps.

License and contact
-------------------
See the repository `LICENSE` file for licensing terms. For questions or contributions, open an issue or submit a pull request.

