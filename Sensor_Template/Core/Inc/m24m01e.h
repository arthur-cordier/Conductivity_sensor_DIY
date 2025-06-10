/*
 * m24m01e.h
 *
 *  Created on: Mar 6, 2025
 *      Author: arthur
 */

#ifndef M24M01E_H
#define M24M01E_H

#include "stm32u5xx_hal.h"
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

HAL_StatusTypeDef M24M01E_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef M24M01E_WriteSalinity(I2C_HandleTypeDef *hi2c, float salinity);
HAL_StatusTypeDef M24M01E_ReadSalinity(I2C_HandleTypeDef *hi2c, uint16_t index, float *salinity);
HAL_StatusTypeDef M24M01E_Clear(I2C_HandleTypeDef *hi2c);
void M24M01E_PrintAll(I2C_HandleTypeDef *hi2c);

#endif // M24M01E_H
