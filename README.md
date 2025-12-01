/**
# Evaluación de ciberseguridad de un sistema de IoT basado en Arduino — Repository README

Purpose
-------
This repository contains a curated set of intentionally vulnerable Arduino examples and corresponding mitigations. Its purpose is educational: to help students, developers, and security auditors understand common security issues in Arduino-based IoT systems and to show practical mitigation strategies. The code and examples are related to the essay "Evaluación de ciberseguridad de un sistema de IoT basado en Arduino" written for the Universitat Oberta de Catalunya.

Important notice and responsible use
-----------------------------------
- This repository is intended for learning, research, and secure development training only.
- Do not use any example code to test or attack devices that you do not own or have explicit permission to test.
- If you find a vulnerability in third-party hardware or software, follow responsible disclosure practices and vendor disclosure policies.
- Test examples in a controlled, isolated lab environment (air-gapped or segregated VM/network) to avoid impacting other systems.

Repository structure (overview)
-------------------------------
- /src
    - Contains one example per folder; each folder maps to a section of the essay.
    - Each example demonstrates a specific vulnerability pattern and includes:
        - A concise README for that example
        - Source code (Arduino sketches and helper utilities)
        - A "mitigation" or "fix" variant where applicable
        - Test steps and safety/improbable exploitation guidance (high-level)

Example categories included (non-exhaustive)
--------------------------------------------
The repository demonstrates multiple classes of issues typically seen in Arduino IoT projects:

- Network & Communications
    - Insecure Wi-Fi/BLUETOOTH configuration (hard-coded credentials, weak auth)
    - Plaintext protocols or lack of TLS/DTLS
- Authentication & Authorization
    - No authentication or improper access controls
    - Weak password handling and password reuse
- Firmware & Update
    - Unsigned or unauthenticated OTA firmware updates
    - Lack of secure boot / rollback protection
- Input Validation & Memory Safety
    - Buffer overflows and insufficient input sanitization
    - Use of unsafe string/memory functions
- Information Exposure
    - Hard-coded secrets, indiscriminate serial logging, debug ports left enabled
- Physical & Supply Chain
    - Insecure bootloader access, unprotected debug JTAG/Serial
    - Poor provisioning and secret management
- Operational Security
    - Inadequate logging/monitoring and lack of rate limiting / brute force protections

What each example folder contains
--------------------------------
- README.md — Explains purpose and context of example, hardware/software prerequisites, and test procedure
- vulnerable/ — Code demonstrating the insecure implementation (for study only)
- secure/ — Recommended changes and fixed code (showing mitigation strategies)
- notes.md — Additional context, risks, and references

Prerequisites and safe test environment
--------------------------------------
- Hardware: Arduino Uno, Nano, ESP8266, ESP32, or boards specified per example.
- Software: Arduino IDE / PlatformIO, required libraries specified in example README.
- Connectivity: Use an isolated lab network (segregated AP or private VLAN). For Wi-Fi examples, run on a test SSID; do not expose to public networks.
- Tools: Serial monitor, Wireshark (for educational inspection), optionally a USB-to-Serial adapter for debugging.
- Take care to disable devices' automatic connection to known public networks during tests.

How to run an example (high-level)
----------------------------------
1. Read the README.md inside a specific /src example folder to learn its intent and safety precautions.
2. Set up the target board and confirm the correct board selection & serial port in the Arduino IDE or PlatformIO.
3. Upload the "vulnerable" sketch to exercise the insecure behavior. Observe expected behaviors or logs in an isolated environment.
4. Switch to the "secure" sketch to apply mitigations. Compare behaviors and security posture.
5. Follow any additional example-specific steps for test data or measurement.

Mitigation strategies (best practices)
-------------------------------------
For each class of problem, recommended mitigations include:
- Strong authentication: Avoid hard-coded credentials, use unique per-device credentials, and implement challenge-response or mutual authentication when possible.
- Secure communications: Use TLS/DTLS, certificate validation, and modern cipher suites; validate certificates and avoid skipping verification in production.
- Secure firmware updates: Sign firmware images; implement verification before applying updates; add rollback-safe procedures.
- Input validation: Validate and bound all inputs; avoid unsafe string/memory APIs; prefer safe library functions and static analysis.
- Secrets and storage: Use secure storage primitives (hardware-backed when possible), avoid storing keys in cleartext in firmware or flash.
- Debugging & production hardening: Remove/disable debug ports and logging in production devices; control access to JTAG/Serial.
- Memory safety & code quality: Use compiler protections (stack canaries, ASLR where supported), minimize dynamic memory use, and use static analyzers.
- Operational monitoring: Log securely, monitor for anomalous behavior, implement rate limiting and lockout mechanisms.
- Supply chain: Protect provisioning and signing keys; require developer & vendor controls and attestations.

Reporting issues and contributions
----------------------------------
- Please use the GitHub Issues tracker for bug reports, example clarifications, or suggestions.
- To contribute:
    - Fork the repository.
    - Add or modify an example under /src with a clear README describing problem, demo steps, and fixes.
    - Keep examples self-contained and safe to run in a lab network.
    - Submit a pull request with clear explanation and tests, if applicable.

Caveats and limitations
-----------------------
- Examples are intentionally vulnerable for educational use. They do not reflect the safe baseline you should ship in production.
- This repository does not provide exhaustive security guarantees or step-by-step attack guides. It is meant to illustrate concepts and show defensive patterns.
- Always consult hardware vendor guidance for platform-specific mitigations (secure boot, secure element usage, proprietary secure provisioning).

Academic citation
-----------------
This code repository accompanies:
Evaluación de ciberseguridad de un sistema de IoT basado en Arduino — Universitat Oberta de Catalunya
- This repository can be cited when referencing the practical examples included in the essay.

License and legal
-----------------
- Check the LICENSE file at the repository root for licensing terms and permitted usage.
- Unless otherwise stated, follow the licensing terms provided in the repository.

Contact
-------
- For questions about usage in teaching or research, open an issue in the repo or contact the repository maintainer listed in the project metadata.

*/