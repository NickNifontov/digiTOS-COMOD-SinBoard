/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f0xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
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
#include "stm32f0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "digiTOS-Lib/digiTOS-Core.h"
#include "digiTOS-Lib/digiTOS-Generator.h"
#include "digiTOS-Lib/digiTOS-Sinus.h"
#include "digiTOS-Lib/digiTOS-ADC.h"
#include "usart.h"
#include "iwdg.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc;
extern ADC_HandleTypeDef hadc;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim14;
extern TIM_HandleTypeDef htim16;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles Flash global interrupt.
  */
void FLASH_IRQHandler(void)
{
  /* USER CODE BEGIN FLASH_IRQn 0 */

  /* USER CODE END FLASH_IRQn 0 */
  HAL_FLASH_IRQHandler();
  /* USER CODE BEGIN FLASH_IRQn 1 */

  /* USER CODE END FLASH_IRQn 1 */
}

/**
  * @brief This function handles RCC global interrupt.
  */
void RCC_IRQHandler(void)
{
  /* USER CODE BEGIN RCC_IRQn 0 */

  /* USER CODE END RCC_IRQn 0 */
  /* USER CODE BEGIN RCC_IRQn 1 */

  /* USER CODE END RCC_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 2 and 3 interrupts.
  */
void DMA1_Channel2_3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 0 */

  /* USER CODE END DMA1_Channel2_3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc);
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
  /* USER CODE BEGIN DMA1_Channel2_3_IRQn 1 */

  /* USER CODE END DMA1_Channel2_3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 4 and 5 interrupts.
  */
void DMA1_Channel4_5_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel4_5_IRQn 0 */

  /* USER CODE END DMA1_Channel4_5_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_tx);
  /* USER CODE BEGIN DMA1_Channel4_5_IRQn 1 */

  /* USER CODE END DMA1_Channel4_5_IRQn 1 */
}

/**
  * @brief This function handles ADC interrupt.
  */
void ADC1_IRQHandler(void)
{
  /* USER CODE BEGIN ADC1_IRQn 0 */

  /* USER CODE END ADC1_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc);
  /* USER CODE BEGIN ADC1_IRQn 1 */

  /* USER CODE END ADC1_IRQn 1 */
}

/**
  * @brief This function handles TIM1 break, update, trigger and commutation interrupts.
  */
void TIM1_BRK_UP_TRG_COM_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_UP_TRG_COM_IRQn 0 */

  /* USER CODE END TIM1_BRK_UP_TRG_COM_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_BRK_UP_TRG_COM_IRQn 1 */

  __HAL_TIM_CLEAR_FLAG(&htim1, TIM_FLAG_UPDATE);

  sin_step=0;sinStatus=0;TIM3->CCR2=0;TIM3->CCR1=0;

  if (SinWave==swStart) {
	  SinWave=swGEN;
	  TIM1->CCR3=500;
  }


  /* USER CODE END TIM1_BRK_UP_TRG_COM_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  __HAL_TIM_CLEAR_FLAG(&htim3, TIM_FLAG_UPDATE);

	if ((SinWave==swStop) || (SinWave==swStart) || (SinWave==swNOP))  {
 		TIM3->CCR2=0;
 		TIM3->CCR1=0;
 		//TIM1->CCR3=0;
 		sin_step=0;
 	      }

	if (SinWave==swNOP) {return;}

   	if (SinWave==swStart)  {
   		SinWave=swGEN;
   	}

  if  ((TIM1->CNT==0) || (TIM1->CNT==500)) {
	  	  //TIM3->CCR2=0;
	  	  //TIM3->CCR1=0;
	  	  sin_step=0;
	      //UpdateAmplitudeByV();
	      return;
  }

   if  (TIM1->CNT>=500) { sinStatus=1;}
   if  (TIM1->CNT<500) { sinStatus=0;}

   if (sinStatus==0) {
	   TIM3->CCR2=0;
	   TIM3->CCR1=GetSinus();
	   //TIM3->CCR2=0;
   }
   if (sinStatus==1) {
	   TIM3->CCR1=0;
	   TIM3->CCR2=GetSinus();
   }

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM14 global interrupt.
  */
void TIM14_IRQHandler(void)
{
  /* USER CODE BEGIN TIM14_IRQn 0 */

  /* USER CODE END TIM14_IRQn 0 */
  HAL_TIM_IRQHandler(&htim14);
  /* USER CODE BEGIN TIM14_IRQn 1 */

  __HAL_TIM_CLEAR_FLAG(&htim14, TIM_FLAG_UPDATE);


  if ((buttonUpdate(&FaultFlag) == isPressed) || (buttonUpdate(&FaultFlag) == isPressedLong)) {
	  BoardStatus=sFaultFlag;
	  FaultWaitCnt=0;
		  if (SinWave!=swGEN) {
			  SinWave=swGEN;
		  } else {
			  return;
		  }
  } else {
	  //BoardStatus=sGEN;
  }

	#ifdef AMP_PROTECTION
  	  if ((SinWave==swNOP) && (BoardStatus == sGEN) && (AMP_BLOCKED==0)) {
	#endif
	#ifndef AMP_PROTECTION
  	  if ((SinWave==swNOP) && (BoardStatus == sGEN)) {
	#endif
  	  sin_step=0;
  	  	  if  (buttonUpdate(&DevModeKey2) == isPressedLong) {
    		SinWave=swStart;
    		TIM3->CCR2=0;
    		 		TIM3->CCR1=0;
    		 		TIM1->CCR3=0;
    		 		sin_step=0;
    		PWM_50Hz_ON();
    		PWM_Sinus_ON();
    		return;
    	  }
      }

  if (SinWave==swGEN) {
				#ifdef AMP_PROTECTION
			  	  	  if (  (BoardStatus == sFaultFlag) || (buttonUpdate(&DevModeKey2) == isReleased) || (AMP_BLOCKED==1) ) {
				#endif
				#ifndef AMP_PROTECTION
			  	  	  if ( (BoardStatus == sFaultFlag) || (buttonUpdate(&DevModeKey2) == isReleased) ) {
				#endif
		  SinWave=swNOP;
		  TIM3->CCR2=0;
		   		TIM3->CCR1=0;
		   		TIM1->CCR3=0;
		   		sin_step=0;
		  PWM_50Hz_OFF();
		  PWM_Sinus_OFF();
		  return;
	  }
  }

  	  	  	  if  (sin_step==0) {
  	  	  		  	 UpdateAmplitudeByV();
  	  	  	  }

  	  	  	  CheckV_Feedback();
  	  	  	  sin_step++;




  	    	/*if (sin_step >= SinRes) {
  	    		sin_step = 0;
  	    	}*/


  /* USER CODE END TIM14_IRQn 1 */
}

/**
  * @brief This function handles TIM16 global interrupt.
  */
void TIM16_IRQHandler(void)
{
  /* USER CODE BEGIN TIM16_IRQn 0 */

  /* USER CODE END TIM16_IRQn 0 */
  HAL_TIM_IRQHandler(&htim16);
  /* USER CODE BEGIN TIM16_IRQn 1 */

  __HAL_TIM_CLEAR_FLAG(&htim16, TIM_FLAG_UPDATE);

    	// Reset IWDG
      ResetWDG();

        //
        switch(BoardStatus) {
      	  case sBoot:
      	  case sUnknown:
      	  	  //TIM3->ARR=sBoot_Delay;
      	  	  HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
      	  	  HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
      	  	  HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
      	  	  HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);

      	  	  // when boot check faultflag
      	  	  buttonUpdate(&FaultFlag);
      		  break;
      	  case sGEN:
      		  //TIM3->ARR=sDEF_INV_Delay;
      		  	  if (DevMode1==1) {
      		  		  //SerialPrintln(0);
      		  		  //ClearUART_Buff();

      		  		  ClearUART_Buff();
      		  		  //sprintf(uart_buff,"%4u \r\n",ADC_Data[0]);
      		  		  PrintCurrentState();
      		  		  SerialPrintln(0);
      		  	  }
				#ifdef AMP_PROTECTION
      		  	  if (AMP_BLOCKED==1) {
      		  		AMP_PROTECTION_CNT_BEFORESTART++;
      		  		if (AMP_PROTECTION_CNT_BEFORESTART>=DelaySecBeforeStartAfterAmpProtection) {
      		  			AMP_PROTECTION_CNT_BEFORESTART=0;
      		  			AMP_BLOCKED=0;
      		  			AMP_PROTECTION_CNT=0;
      		  		}
      		  	  }
				#endif
    		  break;
      	  case sFaultFlag:
					if ((buttonUpdate(&FaultFlag) == isPressed) || (buttonUpdate(&FaultFlag) == isPressedLong)
						//	|| (RstCnt<=DelaySecBeforeAttemRst)
							) {
						RstCnt++;
						if (RstCnt==DelaySecBeforeAttemRst) {
							RstCnt=0;
							HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin,GPIO_PIN_SET);
							TIM16->ARR=sRST_Delay;
						} else {
							HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin,GPIO_PIN_RESET);
							TIM16->ARR=sDEF_Delay;
						}
						HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
						BoardStatus=sFaultFlag;
						SinWave=swNOP;
						FaultWaitCnt=0;
					  } else {
						  SinWave=swNOP;
						  RstCnt=0;
						  FaultWaitCnt++;
						  if (FaultWaitCnt>=DelaySecBeforeStartAfterFault) {
							  HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin,GPIO_PIN_RESET);
							  BoardStatus=sGEN;
						  } else {
							  BoardStatus=sFaultFlag;
							  HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
						  }
					  }
      		  	  break;
        }

  /* USER CODE END TIM16_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */


  /* USER CODE END USART1_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
