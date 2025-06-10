/*
 * sd.c
 *
 *  Created on: Jan 26, 2024
 *      Author: lucas
 */

#include "../../Firmware/Inc/sd.h"

FX_MEDIA FX_SD_card;
FX_FILE file;
#define DRIVER_MEMORY_SIZE 1024 // Size of memory allocated for the driver, adjust as needed
uint8_t driver_memory[DRIVER_MEMORY_SIZE];

uint8_t SD_card_init(){
//	HAL_SD_InitCard(&hsd1);
	hsd1.Instance = SDMMC1;
	hsd1.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
	hsd1.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
	hsd1.Init.BusWide = SDMMC_BUS_WIDE_4B;
	hsd1.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
	hsd1.Init.ClockDiv = 0;
	if (HAL_SD_Init(&hsd1) != HAL_OK)
	{
	Error_Handler();
	}
	uint16_t status = _fxe_media_open(&FX_SD_card, (char*)"SDCARD", fx_stm32_sd_driver, &hsd1, driver_memory, DRIVER_MEMORY_SIZE, sizeof(FX_MEDIA));
	if(status==0) return 1;
	else return 0;
}
void SD_card_unInit(){
	_fxe_file_close(&file);
	_fxe_media_close(&FX_SD_card);
//	HAL_SD_DeInit(&hsd1);
}


void SD_log(char* filename, char* log){
	if(SD_card_init()){
		uint16_t status = _fxe_file_open(&FX_SD_card, &file, filename, FX_OPEN_FOR_WRITE, sizeof(FX_FILE));
		if(status==FX_NOT_FOUND){
			_fxe_file_create(&FX_SD_card, filename);
			_fxe_file_open(&FX_SD_card, &file, filename, FX_OPEN_FOR_WRITE, sizeof(FX_FILE));
		}
		_fxe_file_write(&file, log, strlen(log));
	}
	SD_card_unInit();
}
