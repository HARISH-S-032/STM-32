# STM32F401RE Bare-Metal Bit Banging Communication Protocols

A collection of **bare-metal** communication protocol implementations for the **STM32 Nucleo-F401RE**. This project demonstrates how standard communication protocols can be implemented entirely in software using **GPIO bit banging**, without relying on STM32 HAL, LL drivers, or hardware communication peripherals.

## Overview

This repository focuses on understanding the low-level working of communication protocols by directly manipulating STM32 registers and GPIO pins.

The following protocols are implemented:

- UART
- I2C
- SPI
- 1-Wire

## Key Features

- Bare-metal programming using register-level access
- No STM32 HAL
- No LL (Low-Layer) drivers
- No hardware UART, I2C, or SPI peripherals
- Software-generated timing and clock signals
- GPIO-based communication
- Verified using a Logic Analyzer

## Protocol Implementations

### UART
- Software transmitter
- Configurable baud rate
- Start bit generation
- 8-bit data transmission
- Stop bit generation

### I2C
- Master mode
- START and STOP conditions
- ACK/NACK handling
- Read and Write operations
- Clock stretching support (optional)

### SPI
- Master mode
- Manual clock generation
- MOSI/MISO communication
- Manual Chip Select (CS)
- SPI Mode 0

### 1-Wire
- Reset pulse
- Presence pulse detection
- Bit read/write
- Byte read/write

## Development Approach

This project uses:

- Embedded C
- Direct register programming
- GPIO manipulation
- Software delay routines
- Bit-level protocol implementation

No middleware or abstraction layers are used.

## Hardware

- STM32 Nucleo-F401RE
- STM32F401RE (ARM Cortex-M4)
- Logic Analyzer

## Project Structure

```
STM32-BitBanging/
│
├── UART/
├── I2C/
├── SPI/
├── OneWire/
├── Drivers/
└── README.md
```

## Applications

- Embedded Systems Learning
- Bare-Metal Programming
- Communication Protocol Study
- Driver Development
- Firmware Development
- Interview Preparation

## Skills Demonstrated

- Embedded C
- ARM Cortex-M4
- STM32F401RE
- Register-Level Programming
- GPIO Programming
- Bare-Metal Firmware Development
- UART
- I2C
- SPI
- 1-Wire Protocol
- Logic Analyzer Debugging

## Future Improvements

- Software UART Receiver
- Multiple SPI Modes
- Configurable GPIO Mapping
- Timing Optimization
- CRC Support
- Additional Protocol Implementations

## License

MIT License

## Author

**Harish S**

Embedded Systems | Bare-Metal Firmware | PCB Design
