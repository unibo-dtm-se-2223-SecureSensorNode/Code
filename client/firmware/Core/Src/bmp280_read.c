#include "bmp280_read.h"

HAL_StatusTypeDef BMP280_ReadTemperatureAndPressure(I2C_HandleTypeDef *hi2c, int32_t *temperature, uint32_t *pressure)
{
    uint8_t data[6];
    HAL_StatusTypeDef status;

    // Read raw pressure and temperature (6 bytes starting at register 0xF7)
    status = HAL_I2C_Mem_Read(hi2c, 0xEC, 0xF7, I2C_MEMADD_SIZE_8BIT, data, 6, HAL_MAX_DELAY);
    if (status != HAL_OK) {
        return status;
    }

    // Combine bytes into raw values
    int32_t adc_P = ((int32_t)data[0] << 12) | ((int32_t)data[1] << 4) | (data[2] >> 4);
    int32_t adc_T = ((int32_t)data[3] << 12) | ((int32_t)data[4] << 4) | (data[5] >> 4);

    // Very basic, uncalibrated conversion — for demo only
    *temperature = adc_T / 100;
    *pressure = adc_P / 100;

    return HAL_OK;
}
