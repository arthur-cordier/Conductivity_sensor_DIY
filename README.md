# Conductivity_sensor_DIY

This project provides a **low-tech (<100€), open-source conductivity sensor** based on **inductive conductometry**. It is designed to be simple, accessible, and adaptable for educational, scientific, or environmental monitoring purposes.

## Overview

The sensor uses two coils: one for emitting a sinusoidal signal (10 kHz, 0.5 V) and the other for receiving the induced signal after interaction with water. Signal processing is handled using a microcontroller (STM32), with FFT analysis used to estimate conductivity and salinity.

## Hardware

- 2 copper coils (inductive setup)
- Signal generator via DAC
- Signal acquisition via ADC
- STM32 microcontroller (tested on NUCLEO-U575ZI-Q)
- Temperature sensors (e.g. TMP119)
- Optional EEPROM (e.g. M24M01E)
- AOP
- Resistors

## Software Features

- Sinusoidal signal generation at 10 kHz
- ADC sampling synchronized with a timer
- FFT analysis using CMSIS-DSP
- Calibration using reference solutions
- Real-time conductivity computation and display
- Data output via UART

## Related Links

- STM32CubeIDE project files
- Internship report in French with all the information on the project
