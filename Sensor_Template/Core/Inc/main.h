/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern int runner();
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#include "fx_api.h"
#include "fx_system.h"

typedef struct Mode_Settings
{
    uint8_t TX_message_code;
    uint8_t Recovery_mode_frequency;
    uint8_t Recovery_mode_duration;
    uint8_t GNSS_frequency;
    uint8_t SST_frequency;
    uint8_t AP_frequency;
    uint8_t SSW_frequency;
    uint8_t Next_mode;



    uint16_t GNSS_delay;
    uint8_t GNSS_freq_h;
    uint8_t GNSS_TX_code;
    uint8_t GNSS_Hs_TX_code;
    uint8_t spectrum_number;
    uint8_t f_spectre;
    uint8_t next_mode;
    uint8_t mode_duration; // hour

} Mode_Settings;

extern uint8_t flag_acq_ON;
extern uint8_t flag_pause_ON;
extern uint8_t flag_gnss_ON;
extern uint8_t flag_gnss_ON_request;
extern uint8_t flag_gnss_READ_request;
extern uint8_t flag_data_ready;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOE
#define LED_GREEN_Pin GPIO_PIN_6
#define LED_GREEN_GPIO_Port GPIOE
#define BUTTON_Pin GPIO_PIN_13
#define BUTTON_GPIO_Port GPIOC
#define BUTTON_EXTI_IRQn EXTI13_IRQn
#define GPIO_EXT_8_Pin GPIO_PIN_0
#define GPIO_EXT_8_GPIO_Port GPIOC
#define GPIO_EXT_5_Pin GPIO_PIN_8
#define GPIO_EXT_5_GPIO_Port GPIOA
#define USART1_RX_Pin GPIO_PIN_10
#define USART1_RX_GPIO_Port GPIOA
#define SDCARD_DETECT_Pin GPIO_PIN_0
#define SDCARD_DETECT_GPIO_Port GPIOD
#define GPIO_EXT_7_Pin GPIO_PIN_5
#define GPIO_EXT_7_GPIO_Port GPIOD
#define GPIO_EXT_6_Pin GPIO_PIN_6
#define GPIO_EXT_6_GPIO_Port GPIOD
#define I2C_EXT_SCL_Pin GPIO_PIN_6
#define I2C_EXT_SCL_GPIO_Port GPIOB
#define I2C_EXT_SDA_Pin GPIO_PIN_7
#define I2C_EXT_SDA_GPIO_Port GPIOB
#define GPIO_EXT_4_Pin GPIO_PIN_3
#define GPIO_EXT_4_GPIO_Port GPIOH
#define GPIO_EXT_3_Pin GPIO_PIN_8
#define GPIO_EXT_3_GPIO_Port GPIOB
#define GPIO_EXT_2_Pin GPIO_PIN_9
#define GPIO_EXT_2_GPIO_Port GPIOB
#define GPIO_EXT_1_Pin GPIO_PIN_0
#define GPIO_EXT_1_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */
#define FIST_OF_THE_YEAR_TS 1672531200
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
