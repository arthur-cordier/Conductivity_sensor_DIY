/*
 * sd.h
 *
 *  Created on: Jan 26, 2024
 *      Author: lucas
 */

#ifndef INC_SD_H_
#define INC_SD_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "app_filex.h"
#include "stm32u5xx_hal.h"
#include "main.h"
#include "sdmmc.h"

extern FX_MEDIA FX_SD_card;
extern FX_FILE file;

void SD_log(char* filename, char* log);

#endif /* INC_SD_H_ */
