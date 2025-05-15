#include "bmp280_read.h"

HAL_StatusTypeDef BMP280_ReadTemperatureAndPressure(I2C_HandleTypeDef *hi2c, int32_t *temperature, uint32_t *pressure)
{
    uint8_t data[6];
    HAL_StatusTypeDef status;

    // BMP280 register 0xF7 holds pressure and temperature raw data (6 bytes)
    status = HAL_I2C_Mem_Read(hi2c, 0xEC, 0xF7, I2C_MEMADD_SIZE_8BIT, data, 6, HAL_MAX_DELAY);

    if (status != HAL_OK)
        return status;

    // Pressure (20-bit)
    *pressure = ((uint32_t)data[0] << 12) | ((uint32_t)data[1] << 4) | (data[2] >> 4);

    // Temperature (20-bit)
    *temperature = ((int32_t)data[3] << 12) | ((int32_t)data[4] << 4) | (data[5] >> 4);

    return HAL_OK;
}
