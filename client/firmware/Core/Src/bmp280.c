/**
 * @file bmp280.c
 * @brief Custom driver for BMP280 sensor (I2C interface) - Implementation file
 * 
 * This file implements basic initialization and data reading from the BMP280
 * sensor using STM32 HAL I2C functions.
 * 
 * Author: Massimiliano Pupillo
 */

#include "bmp280.h"

/**
 * @brief Initializes the BMP280 sensor
 * @param hi2c Pointer to I2C handle
 */
void BMP280_Init(I2C_HandleTypeDef *hi2c)
{
    // Example: write 0x3F to register 0xF4 to set normal mode, 1x oversampling
    uint8_t config[2] = {0xF4, 0x3F};
    HAL_I2C_Master_Transmit(hi2c, BMP280_I2C_ADDR, config, 2, HAL_MAX_DELAY);
}

/**
 * @brief Reads temperature from the BMP280 sensor
 * @param hi2c Pointer to I2C handle
 * @return Temperature in Celsius (approximate, no calibration)
 */
float BMP280_ReadTemperature(I2C_HandleTypeDef *hi2c)
{
    uint8_t reg = 0xFA;  // Temperature MSB register
    uint8_t data[3];
    HAL_I2C_Master_Transmit(hi2c, BMP280_I2C_ADDR, &reg, 1, HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(hi2c, BMP280_I2C_ADDR, data, 3, HAL_MAX_DELAY);

    // Combine raw data (20-bit unsigned value)
    int32_t raw_temp = ((int32_t)data[0] << 12) | ((int32_t)data[1] << 4) | (data[2] >> 4);

    // Return dummy value (no calibration yet)
    return (float)raw_temp / 5120.0f;
}
