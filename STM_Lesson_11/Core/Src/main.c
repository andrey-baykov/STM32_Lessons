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


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SEG_A_0 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0)
#define SEG_A_1 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1)
#define SEG_B_0 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0)
#define SEG_B_1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1)
#define SEG_C_0 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0)
#define SEG_C_1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1)
#define SEG_D_0 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0)
#define SEG_D_1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1)
#define SEG_E_0 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 0)
#define SEG_E_1 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, 1)
#define SEG_F_0 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0)
#define SEG_F_1 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1)
#define SEG_G_0 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0)
#define SEG_G_1 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1)

#define RAZR_1_OFF  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 1)
#define RAZR_1_ON   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, 0)
#define RAZR_2_OFF  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1)
#define RAZR_2_ON   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0)
#define RAZR_3_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1)
#define RAZR_3_ON   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0)
#define RAZR_4_OFF  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1)
#define RAZR_4_ON   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0)

#define TIME_DELAY 1000

volatile uint8_t count = 0;
int num_4, num_3, num_2, num_1 = 0;

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim6;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM6_Init(void);
/* USER CODE BEGIN PFP */
void showNumber(char num);
void showFullNumber(int num);
void showFloatNumber(float num);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim)
{

	if (++count > 4) count = 1;

	if(count == 4)
	{
		showNumber(num_4);
		RAZR_1_OFF;
		RAZR_2_OFF;
		RAZR_3_OFF;
		RAZR_4_ON;

	}

	if(count == 3)
	{
		showNumber(num_3);
		RAZR_1_OFF;
		RAZR_2_OFF;
		RAZR_3_ON;
		RAZR_4_OFF;
	}
	if(count == 2)
	{
		showNumber(num_2);
		RAZR_1_OFF;
		RAZR_2_ON;
		RAZR_3_OFF;
		RAZR_4_OFF;
	}
	if(count == 1)
	{
		showNumber(num_1);
		RAZR_1_ON;
		RAZR_2_OFF;
		RAZR_3_OFF;
		RAZR_4_OFF;
	}
//		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_0);

}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */
 HAL_TIM_Base_Start_IT(&htim6);
//  showNumber(1);

//  RAZR_3_ON;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

//	  if (__HAL_TIM_GET_COUNTER(&htim6) == 4000)
//	  {
//		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
//	  }
//	  if (__HAL_TIM_GET_COUNTER(&htim6) == 7999)
//	  {
//		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
//	  }

	  showFloatNumber(0.88999);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 999;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 30;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);

  /*Configure GPIO pin : PC0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB3 PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA8 PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void showNumber(char num)
{
	switch (num) {
	case 0: SEG_A_1; SEG_B_1; SEG_C_1; SEG_D_1; SEG_E_1; SEG_F_1; SEG_G_0; break;
	case 1:	SEG_A_0; SEG_B_1; SEG_C_1; SEG_D_0; SEG_E_0; SEG_F_0; SEG_G_0; break;
	case 2:	SEG_A_1; SEG_B_1; SEG_C_0; SEG_D_1;	SEG_E_1; SEG_F_0; SEG_G_1; break;
	case 3:	SEG_A_1; SEG_B_1; SEG_C_1; SEG_D_1;	SEG_E_0; SEG_F_0; SEG_G_1; break;
	case 4:	SEG_A_0; SEG_B_1; SEG_C_1; SEG_D_0; SEG_E_0; SEG_F_1; SEG_G_1; break;
	case 5:	SEG_A_1; SEG_B_0; SEG_C_1; SEG_D_1; SEG_E_0; SEG_F_1; SEG_G_1; break;
	case 6: SEG_A_1; SEG_B_0; SEG_C_1; SEG_D_1; SEG_E_1; SEG_F_1; SEG_G_1; break;
	case 7: SEG_A_1; SEG_B_1; SEG_C_1; SEG_D_0; SEG_E_0; SEG_F_0; SEG_G_0; break;
	case 8: SEG_A_1; SEG_B_1; SEG_C_1; SEG_D_1; SEG_E_1; SEG_F_1; SEG_G_1; break;
	case 9: SEG_A_1; SEG_B_1; SEG_C_1; SEG_D_1; SEG_E_0; SEG_F_1; SEG_G_1; break;
	default: SEG_A_1; SEG_B_0; SEG_C_0; SEG_D_1; SEG_E_1; SEG_F_1; SEG_G_1;
	}
}

void showFullNumber(int num)
{
/*
 * Function split integer number to 4 digits
 */
	num_4 = num / 1000;
	num_3 = num % 1000 / 100;
	num_2 = num % 100 /10;
	num_1 = num % 10;

}

void showFloatNumber(float num)
{
/*
 * Function split float number to 4 digits
 */


	// TODO Add DOT to show correct number. Current display is not support dots.

	if (num >= 1000)
	{
		num *= 1;
	}
	else if (num >= 100 && num < 1000)
	{
		num *= 10;
	}
	else if (num >= 10 && num < 100)
	{
		num *= 100;
	}
	else if (num >= 0 && num < 10)
	{
		num *= 1000;
	}

	int num_int = lrint(num);  // Function to math round value


	num_4 = num_int / 1000;
	num_3 = num_int % 1000 / 100;
	num_2 = num_int % 100 /10;
	num_1 = num_int % 10;

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
