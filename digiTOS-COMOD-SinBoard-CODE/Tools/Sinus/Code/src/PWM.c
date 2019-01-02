/************************************************** Library ************************************************************************************/

#include "PWM.h"

/************************************************* Use functions *******************************************************************************/

void PWM_50Hz_Init (void){
	
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;													// enable clock for TIM1
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;                       	// enable clock for port A
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;                       	// enable clock for port B
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;													// enable clock for alternative gpio
	
/************************************** Setting PA10 ************************************************/
	
	GPIOA->CRH 	&= ~GPIO_CRH_CNF10;															// setting out alternative push-pull for PWM1_CH1
	GPIOA->CRH 	|= GPIO_CRH_CNF10_1;
	
	GPIOA->CRH	&= ~GPIO_CRH_MODE10;
	GPIOA->CRH	|= GPIO_CRH_MODE10;															// gpio speed 50 MHz
		
/************************************** Setting PB15 ************************************************/
	
	GPIOB->CRH 	&= ~GPIO_CRH_CNF15;															// setting complementary for PWM1_CH3N
	GPIOB->CRH 	|= GPIO_CRH_CNF15_1;
	
	GPIOB->CRH	&= ~GPIO_CRH_MODE15;
	GPIOB->CRH	|= GPIO_CRH_MODE15;															// gpio speed 50 MHz
	
/******************************** Config PWM channel ***********************************************/

	TIM1->PSC = 480-1;																									// div for clock: F = SYSCLK / [PSC + 1]
	TIM1->ARR = 1000;																										// count to 1000
	TIM1->CR1 &= ~TIM_CR1_CKD;																					// div for dead-time: Tdts = 1/Fosc = 41.6 ns
	TIM1->CCR3 = 500;																										// duty cycle 50%
	
	TIM1->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3NE;   										// enable PWM complementary out to PB15 and to PA10
	TIM1->CCER &= ~TIM_CCER_CC3NP; 																			// active high level: 0 - high, 1 - low
	
	TIM1->CCMR2 &= ~TIM_CCMR2_OC3M;
	TIM1->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1;									// positiv PWM1_CH3 and PWM1_CH3N
	
	TIM1->BDTR &= ~TIM_BDTR_DTG;																				// clear register
	TIM1->BDTR |= TIM_BDTR_DTG_2 | TIM_BDTR_DTG_1 | TIM_BDTR_DTG_0;			// value dead-time: = 31*Tdts = 32*41,6ns = 1.29us 

	TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_AOE;													// enable generation output and dead-time
	
/***************************************************************************************************/

	TIM1->CR1 &= ~TIM_CR1_DIR;																					// count up: 0 - up, 1 - down
	TIM1->CR1 &= ~TIM_CR1_CMS;																					// aligned on the front signal: 00 - front; 01, 10, 11 - center	
	TIM1->CR1 |= TIM_CR1_CEN;																						// start count
	
}

void PWM_Sinus_Init (void){
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;													// enable clock for TIM2
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;                       	// enable clock for port A
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;													// enable clock for alternative gpio

/************************************** Setting PA0 ************************************************/
	
	GPIOA->CRL 	&= ~GPIO_CRL_CNF0;															// setting out alternative push-pull for PWM1_CH1
	GPIOA->CRL 	|= GPIO_CRL_CNF0_1;
	
	GPIOA->CRL	&= ~GPIO_CRL_MODE0;
	GPIOA->CRL	|= GPIO_CRL_MODE0;															// gpio speed 50 MHz

/************************************** Setting PA1 ************************************************/
	
	GPIOA->CRL 	&= ~GPIO_CRL_CNF1;															// setting out alternative push-pull for PWM1_CH1
	GPIOA->CRL 	|= GPIO_CRL_CNF1_1;
	
	GPIOA->CRL	&= ~GPIO_CRL_MODE1;
	GPIOA->CRL	|= GPIO_CRL_MODE1;															// gpio speed 50 MHz

/******************************** Config PWM channel ***********************************************/
	
	TIM2->PSC = 0;																																								// div for clock: F = SYSCLK / [PSC + 1]
	TIM2->ARR = 1000;																																							// count to 1000
	TIM2->CCR1 = 0;																																								// duty cycle 0%
	TIM1->CCR2 = 0;																																								// duty cycle 0%
	
	TIM2->CCER |= TIM_CCER_CC1E;   																																// enable PWM out to PA8
	TIM2->CCER &= ~TIM_CCER_CC1P; 																																// active high level: 0 - high, 1 - low
	
	TIM2->CCER |= TIM_CCER_CC2E;   																																// enable PWM complementary out to PA9
	TIM2->CCER &= ~TIM_CCER_CC1P; 																																// active high level: 0 - high, 1 - low
	
	TIM2->CCMR1 &= ~(TIM_CCMR1_OC1M | TIM_CCMR1_OC2M);
	TIM2->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1;			// positiv PWM1_CH1 and PWM1_CH2  

/***************************************************************************************************/

	TIM2->CR1 &= ~TIM_CR1_DIR;														// count up: 0 - up, 1 - down
	TIM2->CR1 &= ~TIM_CR1_CMS;														// aligned on the front signal: 00 - front; 01, 10, 11 - center
	TIM2->CR1 |= TIM_CR1_CEN;															// start count
	
}

void TIM6_step_init (void){
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;										// enable clock for basic TIM6
	
	TIM6->PSC = 1-1;																			// div, frequency 24 kHz
  TIM6->ARR = 1000; 																		// count to 1000
  TIM6->DIER |= TIM_DIER_UIE; 													// enable interrupt for timer
  TIM6->CR1 |= TIM_CR1_CEN; 														// start count
  NVIC_EnableIRQ(TIM6_DAC_IRQn); 												// enable interrupt TIM6_DAC_IRQn
	
}

void PWM_sin_start (void){
	
	PWM_50Hz_Init();
	PWM_Sinus_Init();
	TIM6_step_init();
	
}


