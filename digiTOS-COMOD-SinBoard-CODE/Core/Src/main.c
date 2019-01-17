/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2019 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "crc.h"
#include "dma.h"
#include "iwdg.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "digiTOS-Lib/digiTOS-Generator.h"
#include "digiTOS-Lib/digiTOS-Core.h"
#include "digiTOS-Lib/digiTOS-Sinus.h"
#include "digiTOS-Lib/digiTOS-ADC.h"
#include <stdio.h>
#include <string.h>
#include "stm32_hal_legacy.h"

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc1)
{
	CheckV_Feedback();
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

	#ifdef DEBUG_MODE
		// Disable IWDG if core is halted
	    //DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_IWDG_STOP;

		//__HAL_RCC_DBGMCU_CLK_ENABLE();
				//DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_WWDG_STOP;
				//DBGMCU->APB2FZ = 0xFFFFFFFF;
				//DBGMCU->APB1FZ = 0xFFFFFFFF;
				//DBGMCU->CR |=DBGMCU_CR_DBG_STOP;
			DBGMCU->CR |=DBGMCU_CR_DBG_TIM1_STOP;
				DBGMCU->CR |=DBGMCU_CR_DBG_TIM3_STOP;
		__HAL_DBGMCU_FREEZE_IWDG();
	#endif

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
  MX_DMA_Init();
  MX_CRC_Init();
  MX_IWDG_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
  	// NEW IWDG
    DigiTOS_IWDG_Init(DigiTOS_IWDG_Timeout_8s);
    ResetWDG();

    //Init ADC, start DMA
    //and prepare all data
    StartADC();
    /*
while(1){
    ResetWDG();
}

*/
    SinWave=swNOP;


    ResetWDG();

    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_SET);


    HAL_TIM_Base_Start(&htim2);
    HAL_TIM_Base_Start_IT(&htim2);

    BoardStatus=sBoot;
    TIM2->ARR=sBoot_Delay;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
      ResetWDG();

      buttonInit(&CALIB_V, CALIB_V_GPIO_Port, CALIB_V_Pin, GPIO_PIN_RESET, 4000, 10000);
      buttonInit(&CALIB_I, CALIB_I_GPIO_Port, CALIB_I_Pin, GPIO_PIN_RESET, 4000, 10000);
      buttonInit(&CALIB_MODE, CALIB_MODE_GPIO_Port, CALIB_MODE_Pin, GPIO_PIN_RESET, 30, 2000);

      buttonInit(&DevModeKey, DEV_MODE1_GPIO_Port, DEV_MODE1_Pin, GPIO_PIN_RESET, 30, 2000);
      buttonInit(&DevModeKey2, DEV_MODE2_GPIO_Port, DEV_MODE2_Pin, GPIO_PIN_RESET, 30, 1000);
      buttonInit(&FaultFlag, FAULT_FEEDBACK_GPIO_Port, FAULT_FEEDBACK_Pin, GPIO_PIN_RESET, 30, 1000);
      buttonUpdate(&DevModeKey);
      buttonUpdate(&DevModeKey2);
      buttonUpdate(&FaultFlag);
      buttonUpdate(&CALIB_V);
      buttonUpdate(&CALIB_I);
      buttonUpdate(&CALIB_MODE);

      HAL_Delay(500);

      // Init EEPROM and read data
                 if (InitEEPROM()==0) {
               	  strcpy(uart_buff,"NO EEPROM\r\n");
               	  USE_DEF_CALIB();
               	  //EEPROM_DATA[0]=250;
               	  //StoreEEPROM(132,3636);
               	  SerialPrintln(1);
                 } else {
              	  USE_NEW_CALIB();
               	  strcpy(uart_buff,"OK EEPROM\r\n");
               	  SerialPrintln(1);
                 }


      Get_Version();
      SerialPrintln(1);


      Get_ChipID();
      SerialPrintln(1);

      Get_FlashSize();
      SerialPrintln(1);


      ClearUART_Buff();

      // Check for Calib Mode
      if(buttonUpdate(&CALIB_MODE) == isPressed){
    	  strcpy(uart_buff,"CALIB MODE ENABLED\r\n");
    	  SerialPrintln(1);
    	  CalibMode=1;
      } else {
    	  CalibMode=0;
      }

      buttonUpdate(&FaultFlag);
      if(buttonUpdate(&DevModeKey) == isPressed){
    	strcpy(uart_buff,"DEV MODE - wait\r\n");
    	SerialPrintln(1);
    	ResetWDG();
        HAL_Delay(500);
    	//if(buttonUpdate(&DevModeKey) == isPressedLong){
    	if(buttonUpdate(&DevModeKey) == isPressed){
    		//HAL_TIM_Base_Start_IT(&htim16);
    		strcpy(uart_buff,"DEV MODE - confirmed\r\n");
    	    SerialPrintln(1);
    		DevMode1=1;
    	}
      }

        strcpy(uart_buff,"Start Loop\r\n");
        SerialPrintln(1);

        strcpy(uart_buff,"NOP\r\n");
                   SerialPrintln(1);

      	BoardStatus=sGEN;

      	strcpy(uart_buff,"NOP\r\n");
      	           SerialPrintln(1);

      	TIM2->ARR=sDEF_Delay;

      	strcpy(uart_buff,"NOP\r\n");
      	           SerialPrintln(1);

        //Start loop
          HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin,GPIO_PIN_RESET);
          HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin,GPIO_PIN_RESET);
          HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin,GPIO_PIN_RESET);
          HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_RESET);

          // Start PWM Sinus
          //SinWave=swStart;

           buttonUpdate(&FaultFlag);
           buttonUpdate(&DevModeKey2);
           HAL_Delay(500);
           if(buttonUpdate(&DevModeKey2) == isPressedLong){
        	   strcpy(uart_buff,"Start GENERATOR\r\n");
        	   SerialPrintln(1);
        	   //PWM_50Hz_ON();
        	   //PWM_Sinus_ON();
           }

           strcpy(uart_buff,"NOP\r\n");
           SerialPrintln(1);

           buttonUpdate(&FaultFlag);
           TIM4->PSC=SinResPSC;

           HAL_TIM_Base_Start(&htim4);
           HAL_TIM_Base_Start_IT(&htim4);

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  //if (CheckV_FLAG==1) {
		//  CheckV_FLAG=2;//busy Flag
		  //CheckV_Feedback();
		//  CheckV_FLAG=0; // clear Flag
		  //continue;
	  //}
	  //
	  if (UpdateAmp_FLAG==1) {
	//	  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin,GPIO_PIN_RESET);
	  			UpdateAmp_FLAG=2;//busy Flag
	  			UpdateAmplitudeByV();
	  			UpdateAmp_FLAG=0; // clear Flag
	 // 	  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin,GPIO_PIN_SET);
	  			//continue;
	  }
//	  GEN_FLAG=1;
//#pragma GCC push_options
//#pragma GCC optimize ("-O0")

//your code
	  volatile uint32_t tmp =HAL_GetTick();
	  tmp=tmp %4307;
	    if(tmp %4307>2149){
			 GEN_FLAG=1;//	    	  SinWave=swStart;
	    }
	    else{
	    	GEN_FLAG=0;// SinWave=swStop;
	    }
//#pragma GCC pop_options

/*
	  //
	  if ((buttonUpdate(&FaultFlag) == isPressed) || (buttonUpdate(&FaultFlag) == isPressedLong)) {
		  Fault_FLAG=1;
	  } else {
		  Fault_FLAG=0;
	  }
	  //
	  if  (buttonUpdate(&DevModeKey2) == isPressed) {
		  GEN_FLAG=1;
	  } else {
		  GEN_FLAG=0;
	  }

	  //
	  if (Print_FLAG==1) {
		  PrintCurrentState();
		  Print_FLAG=0;
	  }
*/
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
