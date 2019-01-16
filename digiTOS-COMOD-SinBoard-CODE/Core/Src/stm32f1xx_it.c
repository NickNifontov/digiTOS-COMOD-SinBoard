/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
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
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "stm32f103xb.h"
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
extern DMA_HandleTypeDef hdma_adc1;
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */ 
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
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
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
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles PVD interrupt through EXTI line 16.
  */
void PVD_IRQHandler(void)
{
  /* USER CODE BEGIN PVD_IRQn 0 */

  /* USER CODE END PVD_IRQn 0 */
  HAL_PWR_PVD_IRQHandler();
  /* USER CODE BEGIN PVD_IRQn 1 */

  /* USER CODE END PVD_IRQn 1 */
}

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
  * @brief This function handles DMA1 channel1 global interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

  /* USER CODE END DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc1);
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel4 global interrupt.
  */
void DMA1_Channel4_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel4_IRQn 0 */

  /* USER CODE END DMA1_Channel4_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_tx);
  /* USER CODE BEGIN DMA1_Channel4_IRQn 1 */

  /* USER CODE END DMA1_Channel4_IRQn 1 */
}

/**
  * @brief This function handles ADC1 and ADC2 global interrupts.
  */
void ADC1_2_IRQHandler(void)
{
  /* USER CODE BEGIN ADC1_2_IRQn 0 */

  /* USER CODE END ADC1_2_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc1);
  /* USER CODE BEGIN ADC1_2_IRQn 1 */

  /* USER CODE END ADC1_2_IRQn 1 */
}

/**
  * @brief This function handles TIM1 break interrupt.
  */
void TIM1_BRK_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_IRQn 0 */

	TIM3->CNT=0;

  /* USER CODE END TIM1_BRK_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_BRK_IRQn 1 */

  __HAL_TIM_CLEAR_FLAG(&htim1, TIM_FLAG_UPDATE);

  //sin_step=0;

  //sinStatus=0;TempBuffer_Flag=0;ReadTempValue();

  //TIM3->CCR2=0;TIM3->CCR1=0;

  if (SinWave==swStart) {
	  SinWave=swGEN;
	  TIM1->CCR3=500;
  }

  /* USER CODE END TIM1_BRK_IRQn 1 */
}

/**
  * @brief This function handles TIM1 update interrupt.
  */
void TIM1_UP_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_IRQn 0 */

  /* USER CODE END TIM1_UP_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_IRQn 1 */

  __HAL_TIM_CLEAR_FLAG(&htim1, TIM_FLAG_UPDATE);

  /*if  ((TIM1->CNT>=0) && (TIM1->CNT<=499)  && (sinStatus==1) ){
       	  	sinStatus=0;
       	  	sin_step=0;
       	  	TIM3->CCR2=0;
       	  	if (UpdateAmp_FLAG==0) {
       	  		UpdateAmp_FLAG=1;
       	    }
       	  	return;
   }

  if  ((TIM1->CNT>=500) && (sinStatus==0) ){
        	  	sinStatus=1;
        	  	sin_step=0;
        	  	TIM3->CCR1=0;
        	  	if (UpdateAmp_FLAG==0) {
        	  		UpdateAmp_FLAG=1;
        	    }
        	  	return;
    }*/


          	  	sinStatus=0;
          	  	sin_step=0;
          	  	TIM3->CCR1=0;
          	    TIM3->CCR2=0;
          	  	if (UpdateAmp_FLAG==0) {
          	  		UpdateAmp_FLAG=1;
          	    }

  /* USER CODE END TIM1_UP_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_UPDATE);

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
        		  // Check Calibration code here
        		  if (CalibMode == 1) {
        			  if (CalibCmdCheck()==1) {
        				  return;
        			  }
        		  }

        		  	//PrintCurrentState();
        		  	if (Print_FLAG==0) {
        		  		Print_FLAG=1;
        		  	}

  				#ifdef AMP_PROTECTION
        		  	  if (AMP_BLOCKED==1) {
        		  		AMP_PROTECTION_CNT_BEFORESTART++;
        		  		if (AMP_PROTECTION_CNT_BEFORESTART>=DelaySecBeforeStartAfterAmpProtection) {
        		  			AMP_PROTECTION_CNT_BEFORESTART=0;
        		  			AMP_BLOCKED=0;
        		  			AMP_PROTECTION_CNT=0;
							#ifdef AMP_CORRECTION_TYPE_STEP
        		  				SetSoftstart();
							#endif
        		  		}
        		  	  }
  				#endif

  				#ifdef VOUT_PROTECTION
        		  	  if (VOUT_BLOCKED==1) {
        		  		VOUT_PROTECTION_CNT_BEFORESTART++;
        		  		if (VOUT_PROTECTION_CNT_BEFORESTART>=DelaySecBeforeStartAfterVOUTProtection) {
        		  			VOUT_PROTECTION_CNT_BEFORESTART=0;
        		  			VOUT_BLOCKED=0;
        		  			VOUT_PROTECTION_CNT=0;
							#ifdef AMP_CORRECTION_TYPE_STEP
									SetSoftstart();
							#endif
        		  		}
        		  	  }
  				#endif

  				#ifdef IOUT_PROTECTION
        		  	  if (IOUT_BLOCKED==1) {
        		  		IOUT_PROTECTION_CNT_BEFORESTART++;
        		  		if (IOUT_PROTECTION_CNT_BEFORESTART>=DelaySecBeforeStartAfterIOUTProtection) {
        		  			IOUT_PROTECTION_CNT_BEFORESTART=0;
        		  			IOUT_BLOCKED=0;
        		  			IOUT_PROTECTION_CNT=0;
							#ifdef AMP_CORRECTION_TYPE_STEP
									SetSoftstart();
							#endif
        		  		}
        		  	  }
  				#endif

  				#ifdef DC_PROTECTION
        		  	  if (DC_BLOCKED==1) {
  					  if (DC_DataAverage<DC_PROTECTION_ROLLBACK) {
  						DC_PROTECTION_CNT_BEFORESTART++;
  						if (DC_PROTECTION_CNT_BEFORESTART>=DelaySecBeforeStartAfterDCProtection) {
  							DC_PROTECTION_CNT_BEFORESTART=0;
  							DC_BLOCKED=0;
  							DC_PROTECTION_CNT=0;
							#ifdef AMP_CORRECTION_TYPE_STEP
									SetSoftstart();
							#endif

  						}
  					  } else {
  						  DC_PROTECTION_CNT_BEFORESTART=0;
  					  }
        		  	  }
  				#endif

        		  	//if ((DC_BLOCKED==1) || (VOUT_BLOCKED==1) || (AMP_BLOCKED==1)) {
        		  	//	CalcAc_V_ByWave();
        		  	//}
      		  break;
        	  case sFaultFlag:
        		  	  //PrintCurrentState();
        		      if (Print_FLAG==0) {
        		    	  Print_FLAG=1;
        		      }
  					if ((buttonUpdate(&FaultFlag) == isPressed) || (buttonUpdate(&FaultFlag) == isPressedLong)
  						//	|| (RstCnt<=DelaySecBeforeAttemRst)
  							) {
  						RstCnt++;
  						if (RstCnt==DelaySecBeforeAttemRst) {
  							RstCnt=0;
  							HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin,GPIO_PIN_SET);
  							TIM2->ARR=sRST_Delay;
  						} else {
  							HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin,GPIO_PIN_RESET);
  							TIM2->ARR=sDEF_Delay;
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


  /* USER CODE END TIM2_IRQn 1 */
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

     		if  ((TIM1->CNT>=498) && (sinStatus==0) ){
     					if  (TIM1->CNT>=500)
     						sinStatus=1;/////////
     					//sinStatus=1;
     		      	  	sin_step=0;
     		      	  	TIM3->CCR1=0;
     		      	  	TIM3->CCR2=0;
     		      	  	ReadTempValue();
     		      	  	if (UpdateAmp_FLAG==0) {
     		      	  		UpdateAmp_FLAG=1;
     		      	    }
     		  }

     		 if  ((TIM1->CNT>=998) && (sinStatus==1) ){
     			 	 	 	sinStatus=0;
     			      		sin_step=0;
     			      		TIM3->CCR1=0;
     			      		TIM3->CCR2=0;
     			      		ReadTempValue();
     			      	   	if (UpdateAmp_FLAG==0) {
     			      	    	UpdateAmp_FLAG=1;
     			      	    }
     			      	   	return;
     	}


      	if (sinStatus==0) {
      		   TIM3->CCR2=0;
      		   TIM3->CCR1=GetSinus();
      	   }

      	   if (sinStatus==1) {
      		   TIM3->CCR1=0;
      		   TIM3->CCR2=GetSinus();
      	   }

      	 sin_step++;

      	   	   	   	   	  //if (CheckV_FLAG==0) {
      	    	  	  	//	CheckV_FLAG=1;
      	    	  	  	  //}



  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  __HAL_TIM_CLEAR_FLAG(&htim4, TIM_FLAG_UPDATE);


    if (Fault_FLAG==1) {
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


    	  if ((SinWave==swNOP) && (BoardStatus == sGEN) && (AMP_BLOCKED==0)
    			  && (DC_BLOCKED==0) && (VOUT_BLOCKED==0)  && (IOUT_BLOCKED==0) && (EEPROM_FLAG==0)) {
    	  sin_step=0;
    	  	  if  (GEN_FLAG==1) {
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
  				if (  (BoardStatus == sFaultFlag) || (GEN_FLAG==0)
  						|| (AMP_BLOCKED==1)  || (DC_BLOCKED==1) || (VOUT_BLOCKED==1)  || (IOUT_BLOCKED==1)) {
  				//#ifndef AMP_PROTECTION
  			  	//  	  if ( (BoardStatus == sFaultFlag) || (buttonUpdate(&DevModeKey2) == isReleased) ) {
  				//#endif
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

    	  	  	  //if  (sin_step==0) {
    	  	  	  //	 UpdateAmplitudeByV();
    	  	  	  //}

    	  	  	  //CheckV_Feedback();
    	  	  	  //if (CheckV_FLAG==0) {
    	  	  	//	CheckV_FLAG=1;
    	  	  	 // }
    	  	  	  //sin_step++;




    	    	/*if (sin_step >= SinRes) {
    	    		sin_step = 0;
    	    	}*/


  /* USER CODE END TIM4_IRQn 1 */
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
