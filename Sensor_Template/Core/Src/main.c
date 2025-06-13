/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "dcache.h"
#include "gpdma.h"
#include "i2c.h"
#include "icache.h"
#include "memorymap.h"
#include "rtc.h"
#include "sdmmc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "app_filex.h"
#include <arm_math.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
#define MAX_VALUES 50
#define VREF 3.3f

float amp_in_list[MAX_VALUES] = {0};
float amp_out_list[MAX_VALUES] = {0};
uint16_t amp_index = 0;

uint16_t adc4_in[FFT_SAMPLE_SIZE];
uint16_t adc4_out[FFT_SAMPLE_SIZE];

volatile uint16_t sin_index = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void SystemPower_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
float Calcul_Salinite(float conductivite, float temperature) {

    float C_standard = 42.914; 				//Conductivité de l'eau de mer standard à 35 PSU, 15°C, pression atmosphérique en mS/cm (STANDART UNESCO)
    float R = conductivite / C_standard; 	// Calcul du ratio de conductivité

    // Coefficients de l'équation
    float a[] = {0.008, -1.1682, 25.3851, -14.0941, 7.0261, -2.7081};
    float b[] = {0.0005, -0.0056, -0.0066, -0.0375, 0.636, -0.144};

    float delta_S = ((temperature - 15) / (1 + 0.0162 * (temperature - 15))) * (b[0] + b[1]*sqrt(R) + b[2]*R + b[3]*pow(R, 1.5) + b[4]*pow(R, 2) +b[5]*pow(R, 2.5)); 	// Correction de température
    float S = (a[0] + a[1]*sqrt(R) + a[2]*R + a[3]*pow(R, 1.5) + a[4]*pow(R, 2) + a[5]*pow(R, 2.5)) + delta_S;  														// Calcul de la salinité

    return S;
}


float Calcul_Conductivite(float U1, float U4) {

    //const float Rs = 75.0f;                  	// Résistance de rétroaction en ohms (valeur mesurée)
    const float Rs = 84.0f;
	const float N1 = 10.0f;						// Nombres de tours sur bobine 1
    const float N4 = 10.0f;						// Nombres de tours sur bobine 2
    const float L = 0.0045f;                   	// Distance entre bobines (en mètres)
    //const float S = 0.00014741;            	    // Surface de contact (section du tube ou passe l'eau) → π*r^2 avec r=6.85mm, S = 147 mm^2
    const float S = 0.000141;

    float I4 = U4 / Rs;                         // Courant (loi d'Ohm)

    float G = (I4 * N1 * N4) / U1;              // Conductance (Siemens)
    float sigma = G * (L / S);                  // Conductivité en S/m

    return sigma * 10.0f;                      // Conversion en mS/cm
}

float AmplitudeToVoltage(float amplitude_fft, uint16_t N, float vref)
{
    float Ak = (2.0f / (float)N) * amplitude_fft;
    float tension = ((Ak * vref ) / 4096.0f) * 2;

    return tension * 2;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
//	UINT status;
//
//  /* MPU Configuration--------------------------------------------------------*/
//  MPU_Config();
//
//  /* Enable I-Cache---------------------------------------------------------*/
//  SCB_EnableICache();
//
//  /* Enable D-Cache---------------------------------------------------------*/
//  SCB_EnableDCache();
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the System Power */
  SystemPower_Config();

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_GPDMA1_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  //MX_ICACHE_Init();
  MX_DAC1_Init();
  MX_TIM2_Init();
  MX_ADC4_Init();
  //MX_DCACHE1_Init();
  //MX_SDMMC1_SD_Init();
  //MX_RTC_Init();
  MX_TIM15_Init();
  /* USER CODE BEGIN 2 */
  printf(" >> Demarrage...\r\n");
  _fx_system_initialize();
  //MX_USB_DEVICE_Init();

  // Initialisation FFT CMSIS
  arm_rfft_fast_init_f32(&fft_instance, FFT_SAMPLE_SIZE);

//  // Démarrage de l'ADC avec interruption
//  ADC_Start();
//  //Démarrage du DAC avec la generation de la table d'une periode de sinusoide
//  DAC_Start();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	    // Phase 1 : génération sinusoïde
	    GenerateSineTable();
	    HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
	    HAL_TIM_Base_Start(&htim15);

	    uint32_t start_tick = HAL_GetTick();
	    uint32_t last_tick = __HAL_TIM_GET_COUNTER(&htim15);
	    uint16_t i = 0;

	    while ((HAL_GetTick() - start_tick) < 1000) // 100 ms = 1000 périodes
	    {
	        uint32_t now = __HAL_TIM_GET_COUNTER(&htim15);
	        if ((now - last_tick) >= 1)
	        {
	            last_tick = now;
	            HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sine_wave[i]);
	            i = (i + 1) % DAC_BUFFER_SIZE;
	        }
	    }

	    // Phase 2 : démarrage acquisition ADC pendant que la sinusoïde continue
	    ADC_Start();

	    i = 0;
	    fft_ready = 0;

	    while (fft_ready == 0)
	    {
	        uint32_t now = __HAL_TIM_GET_COUNTER(&htim15);
	        if ((now - last_tick) >= 1)
	        {
	            last_tick = now;
	            HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sine_wave[i]);
	            i = (i + 1) % DAC_BUFFER_SIZE;
	        }
	    }

	    // Phase 3 : arrêt sinusoïde une fois acquisition DMA terminée
        HAL_DAC_Stop(&hdac1, DAC_CHANNEL_1);
        HAL_TIM_Base_Stop(&htim15);
        HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sine_wave[0]);

        // Phase 4 : traitement FFT
        for (uint16_t i = 0; i < FFT_SAMPLE_SIZE; i++) {
            adc4_in_f32[i] = (float32_t)adc4_raw_samples[2*i];
            adc4_out_f32[i] = (float32_t)adc4_raw_samples[2*i + 1];
        }

        arm_rfft_fast_f32(&fft_instance, adc4_in_f32, fft_output_in, 0);
        arm_rfft_fast_f32(&fft_instance, adc4_out_f32, fft_output_out, 0);

        for (uint16_t i = 0; i < FFT_SAMPLE_SIZE / 2; i++)
        {
            float re_in = fft_output_in[2*i];
            float im_in = fft_output_in[2*i + 1];
            fft_amplitude_in[i] = sqrtf(re_in * re_in + im_in * im_in);

            float re_out = fft_output_out[2*i];
            float im_out = fft_output_out[2*i + 1];
            fft_amplitude_out[i] = sqrtf(re_out*re_out + im_out*im_out);
        }

        // Extraction de l'amplitude à 10 kHz (index 330 si F=30kHz, N=2048)
        float amp_in = fft_amplitude_in[330];
        float amp_out = fft_amplitude_out[330];

        float u1 = AmplitudeToVoltage(amp_in, FFT_SAMPLE_SIZE, VREF);
        float u4 = AmplitudeToVoltage(amp_out, FFT_SAMPLE_SIZE, VREF);
        //printf("U1 = %.4f mV | U4 = %.4f mV\r\n", u1 * 1000.0f, u4 * 1000.0f);

        float cond = Calcul_Conductivite(u1, u4);
        printf("Conductivite = %.3f mS/cm\r\n", cond);

        // Attente entre deux acquisitions
        HAL_Delay(500); // attente avant prochaine mesure
   }
   /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI
                              |RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_0;
  RCC_OscInitStruct.LSIDiv = RCC_LSI_DIV1;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLMBOOST = RCC_PLLMBOOST_DIV4;
  RCC_OscInitStruct.PLL.PLLM = 3;
  RCC_OscInitStruct.PLL.PLLN = 16;
  RCC_OscInitStruct.PLL.PLLP = 3;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLLVCIRANGE_1;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK3;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Power Configuration
  * @retval None
  */
static void SystemPower_Config(void)
{
  PWR_PVDTypeDef sConfigPVD = {0};

  /*
   * PVD Configuration
   */
  sConfigPVD.PVDLevel = PWR_PVDLEVEL_6;
  sConfigPVD.Mode = PWR_PVD_MODE_NORMAL;
  HAL_PWR_ConfigPVD(&sConfigPVD);

  /*
   * Enable the PVD Output
   */
  HAL_PWR_EnablePVD();

  /*
   * Switch to SMPS regulator instead of LDO
   */
  if (HAL_PWREx_ConfigSupply(PWR_SMPS_SUPPLY) != HAL_OK)
  {
    Error_Handler();
  }
/* USER CODE BEGIN PWR */
/* USER CODE END PWR */
}

/* USER CODE BEGIN 4 */
int _write(int file, char *ptr, int len)
{
  (void)file;
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++)
  {
//    ITM_SendChar(*ptr++);
    HAL_UART_Transmit(&huart1, (uint8_t *)ptr++, 1, 100);
  }
  return len;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
	  NVIC_SystemReset();
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
