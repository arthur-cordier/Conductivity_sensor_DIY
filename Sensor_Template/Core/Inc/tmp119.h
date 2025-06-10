/*
 * tmp119.h
 *
 *  Created on: Mar 6, 2025
 *      Author: arthur
 */

#ifndef TMP119_H
#define TMP119_H

#include "stm32u5xx_hal.h"

HAL_StatusTypeDef ReadTemperature(I2C_HandleTypeDef *hi2c, float *temperature);

#endif // TMP119_H
