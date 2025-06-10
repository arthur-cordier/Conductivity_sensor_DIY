/*
 * runner.c
 *
 *  Created on: Jan 23, 2024
 *      Author: lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include "runner.h"
#include "main.h"
#include "sd.h"
#include "stm32u5xx_hal.h"

char output[255];

int runner(void){
	SD_log((char*)"log.txt", (char*)"Start\r\n");
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	uint32_t counter = 0;
	printf("Hello World\r\n");
	while(1){
		sprintf(output,"Counter %lu\r\n", counter++);
		SD_log((char*)"log.txt", output);
		printf(output);
		HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		HAL_Delay(1000);
	}
}
