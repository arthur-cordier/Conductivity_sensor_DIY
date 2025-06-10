/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    adc.h
  * @brief   This file contains all the function prototypes for
  *          the adc.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#ifndef __ADC_H__
#define __ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "arm_math.h"

#define FFT_SAMPLE_SIZE 2048
#define SAMPLING_FREQ 30769.0f

extern uint16_t adc4_raw_samples[FFT_SAMPLE_SIZE * 2];  // Données brutes intercalées
extern float32_t adc4_in_f32[FFT_SAMPLE_SIZE];          // Signal d'entrée capteur
extern float32_t adc4_out_f32[FFT_SAMPLE_SIZE];         // Signal de sortie capteur
extern float32_t fft_output_in[FFT_SAMPLE_SIZE];        // FFT signal IN
extern float32_t fft_output_out[FFT_SAMPLE_SIZE];       // FFT signal OUT
extern float32_t fft_amplitude_in[FFT_SAMPLE_SIZE / 2];
extern float32_t fft_amplitude_out[FFT_SAMPLE_SIZE / 2];

extern volatile uint8_t fft_ready;
extern arm_rfft_fast_instance_f32 fft_instance;      // Contexte FFT CMSIS
/* USER CODE END Includes */

extern ADC_HandleTypeDef hadc4;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_ADC4_Init(void);

/* USER CODE BEGIN Prototypes */
float ADC4_ReadVoltage(void);
void ADC_Start(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */

