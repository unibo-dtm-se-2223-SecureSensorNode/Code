/**
 * @file bmp280.h
 * @brief Custom driver for BMP280 sensor (I2C interface) - Header file
 * 
 * This file declares the initialization and readout functions for the BMP280
 * environmental sensor, using STM32 HAL and I2C.
 * 
 * Author: Massimiliano Pupillo
 */

#ifndef __BMP280_H
#define __BMP280_H

#include "main.h"

// I2C address of the BMP280 (can vary by module wiring)
#define BMP280_I2C_ADDR  0x76 << 1  // Shifted left for HAL compatibility

// Function declarations
void BMP280_Init(I2C_HandleTypeDef *hi2c);
float BMP280_ReadTemperature(I2C_HandleTypeDef *hi2c);
float BMP280_ReadPressure(I2C_HandleTypeDef *hi2c);

#endif
