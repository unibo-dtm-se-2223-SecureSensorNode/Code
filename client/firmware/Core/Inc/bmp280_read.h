#ifndef __BMP280_READ_H
#define __BMP280_READ_H

#include "stm32f4xx_hal.h"

HAL_StatusTypeDef BMP280_ReadTemperatureAndPressure(I2C_HandleTypeDef *hi2c, int32_t *temperature, uint32_t *pressure);

#endif /* __BMP280_READ_H */
