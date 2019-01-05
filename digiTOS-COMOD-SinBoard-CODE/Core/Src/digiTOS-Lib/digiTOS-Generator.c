/*
 * digiTOS-Generator.c
 *
 *  Created on: 30 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#include "digiTOS-Generator.h"
#include "digiTOS-Sinus.h"
#include "digiTOS-ADC.h"
#include "digiTOS-Configuration.h"
#include "tim.h"


////////////////////// DEAD TIME - BEGIN //////////////////////
//const int FOSC=48; // 48000 Hz
//const long FTICK=10000; // 1 per 48000 Hz
//#define MIN_DEADTIME (unsigned long) (FTICK/FOSC);
//#define MAX_DEADTIME (unsigned long) (255*MIN_DEADTIME);

//#define DeadTime1X 					1 // Dead time base value 1/Fosc=1/48000=20.8ns
//#define DeadTime2X 					1 //41,6ns
//#define DeadTime4X					1 //83,2ns
//#define DeadTime8X 					1 //166,4ns
//#define DeadTime16X 				1 //332,8ns
//#define DeadTime32X 				1 //665,6ns
//#define DeadTime64X 				1 //1331,2ns
//#define DeadTime128X 				1 //2662,4ns
void Set50HzDeadTimeNS(void) {

		// Tdts = Tck_int //
	    TIM1->CR1 &= ~TIM_CR1_CKD;
	    TIM1->BDTR &= ~TIM_BDTR_DTG;

	    //TIM1->BDTR  |= TIM_BDTR_DTG_7;//128x //2662,4ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_6;//64x //1331,2ns
	    //TIM1->BDTR  |= TIM_BDTR_DTG_5;//32x //665,6ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_4;//16x //332,8ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_3;//8x //166,4ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_2;//4x //83,2ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_1;//2x  //41,6ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_0;//1x // Dead time base value 1/Fosc=1/48000=20.8ns
}
////////////////////// DEAD TIME - END //////////////////////


////////////////////// SIGNAL INVERSE - BEGIN //////////////////////
void SetNormalSignal(void) {
		TIM1->CCER |= TIM_CCER_CC3NP; // active high level: 0 - high, 1 - low
		TIM1->CCER |= TIM_CCER_CC3P; // active high level: 0 - high, 1 - low
}

void SetInverseSignal(void) {
		TIM1->CCER &= ~TIM_CCER_CC3NP; // active high level: 0 - high, 1 - low
		TIM1->CCER &= ~TIM_CCER_CC3P; // active high level: 0 - high, 1 - low
}
////////////////////// SIGNAL INVERSE - END //////////////////////

////////////////////// IDLE STATE - BEGIN //////////////////////
void Idle_SET(void) {
	    /* output idle state HIGHT */
		TIM1->CR2 |= TIM_CR2_OIS3;
		TIM1->CR2 |= TIM_CR2_OIS3N;
}

void Idle_RESET(void) {
	    /* output idle state LOW */
		TIM1->CR2 &= ~TIM_CR2_OIS3;
		TIM1->CR2 &= ~TIM_CR2_OIS3N;
}
////////////////////// IDLE STAT - END //////////////////////


////////////////////// INIT GENERATOR 50Hz - BEGIN //////////////////////
void PWM_50Hz_Init (void) {
	//RCC->APB2ENR |= RCC_APB2ENR_TIM16EN; // enable clock for TIM1
	//RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // enable clock for port A
	//RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // enable clock for port B
	//RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; // enable clock for alternative gpio

	/****************************** Setting PA10 **************************************/

	//GPIOA->CRH 	&= ~GPIO_CRH_CNF10; // setting out alternative push-pull for PWM
	//GPIOA->CRH 	|= GPIO_CRH_CNF10_1;

	//GPIOA->CRH	&= ~GPIO_CRH_MODE10;
	//GPIOA->CRH	|= GPIO_CRH_MODE10; // gpio speed 50 MHz

	/***************************** Setting PB15 ***************************************/

	//GPIOB->CRH 	&= ~GPIO_CRH_CNF15; // setting complementary for CH3N
	//GPIOB->CRH 	|= GPIO_CRH_CNF15_1;

	//GPIOB->CRH	&= ~GPIO_CRH_MODE15;
	//GPIOB->CRH	|= GPIO_CRH_MODE15; // gpio speed 50 MHz

	/************************** Config PWM channel ************************************/

	TIM1->PSC = 960-1; // div for clock: F = SYSCLK / [PSC + 1]
	TIM1->ARR = 1000; // count to 1000
	TIM1->CCR3 = 500; // duty cycle 50%
	TIM1->CR1 &= ~TIM_CR1_DIR; // count up: 0 - up, 1 - down
    TIM1->CR1 &= ~TIM_CR1_CMS; // aligned on the front signal

    TIM1->CCMR2 &= ~TIM_CCMR2_OC3M;
    TIM1->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1; // positiv PWM

	/* Enable channel outputs */
	TIM1->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3NE; // enable PWM complementary out

	SetNormalSignal(); // NORMAL or INVERSE
	Idle_SET(); // se idle state /* output idle state HIGHT */

	Set50HzDeadTimeNS(); // 1976 ns

	//ch50HZ_OUTEN(); // OUTPUT ENABLE
	//ch50HZ_START(); // start CNT

}
////////////////////// INIT GENERATOR 50Hz - END //////////////////////


////////////////////// CONTROL 50Hz - BEGIN //////////////////////
void PWM_50Hz_START(void)
{
	//TIM1->CNT = 0;
	TIM1->CCR3=500;
	/* Enable channel outputs */
		TIM1->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3NE; // enable PWM complementary out

		SetNormalSignal(); // NORMAL or INVERSE
		Idle_SET(); // se idle state /* output idle state HIGHT */

		Set50HzDeadTimeNS(); // 1976 ns

	TIM1->DIER |= TIM_DIER_UIE;
	TIM1->CR1 |= TIM_CR1_CEN;

	ResetV_data();
	UpdateAmplitudeByV();
}

void PWM_50Hz_STOP(void)
{
	//TIM1->CNT = 0;
	TIM1->SR&=~TIM_SR_UIF; // clear update flag

	TIM1->DIER &= ~TIM_DIER_UIE; // stop interrupt
	TIM1->CR1 &= (uint16_t)~TIM_CR1_CEN; // stop cnt

	//TIM1->CR1 &= ~TIM_CR1_CKD; // off dead time
	//TIM1->BDTR &= ~TIM_BDTR_DTG;

	TIM1->CR2 |= TIM_CR2_OIS3N; // revert level
	TIM1->CR2 &= ~TIM_CR2_OIS3;

	TIM1->CCER |= TIM_CCER_CC3P; // active high level: 0 - high, 1 - low
	TIM1->CCER &= ~TIM_CCER_CC3NP; // active high level: 0 - high, 1 - low

	TIM1->CCR3=0;

}

void PWM_50Hz_OUTEN(void)
{
	TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_AOE; // enable generation output
	//HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
}

void PWM_50Hz_OUTDIS(void)
{
    TIM1->BDTR &= ~TIM_BDTR_MOE;
    TIM1->BDTR &= ~TIM_BDTR_AOE;
    //HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_3);
}

void PWM_50Hz_ON(void){
	PWM_50Hz_OUTEN(); // OUTPUT ENABLE
	PWM_50Hz_START(); // start CNT
}

void PWM_50Hz_OFF(void){
	PWM_50Hz_OUTDIS(); // OUTPUT ENABLE
	PWM_50Hz_STOP(); // start CNT
}
////////////////////// CONTROL 50Hz - END //////////////////////


////////////////////// INIT GENERATOR PWM LOW - BEGIN //////////////////////
void PWM_Sinus_START(void)
{
	sin_step=0;
	//TIM1->CNT = 0;
	TIM3->CCR1=0;
	TIM3->CCR2=0;

	//TIM3->CCER |= TIM_CCER_CC1E; // enable PWM out to PA8
	//TIM3->CCER |= TIM_CCER_CC1P;

	//TIM3->CCER |= TIM_CCER_CC2E; // enable PWM complementary out to PA9
	//TIM3->CCER |= TIM_CCER_CC2P;

	TIM3->DIER |= TIM_DIER_UIE;
	TIM3->CR1 |= TIM_CR1_CEN;

	ResetAmplitude();
}

void PWM_Sinus_STOP(void)
{
	//TIM1->CNT = 0;
	TIM3->SR&=~TIM_SR_UIF; // clear update flag

	TIM3->DIER &= ~TIM_DIER_UIE; // stop interrupt
	TIM3->CR1 &= (uint16_t)~TIM_CR1_CEN; // stop cnt

	TIM3->CCR1=0;
	TIM3->CCR2=0;
}

void PWM_Sinus_OUTEN(void)
{
	TIM3->BDTR |= TIM_BDTR_MOE | TIM_BDTR_AOE; // enable generation output

	//HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
	//HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
}

void PWM_Sinus_OUTDIS(void)
{
    TIM3->BDTR &= ~TIM_BDTR_MOE;
    TIM3->BDTR &= ~TIM_BDTR_AOE;

    //HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_1);
    //HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_2);
}

void PWM_Sinus_ON(void) {
	PWM_Sinus_OUTEN(); // OUTPUT ENABLE
	PWM_Sinus_START(); // start CNT
}

void PWM_Sinus_OFF(void){
	PWM_Sinus_OUTDIS(); // OUTPUT ENABLE
	PWM_Sinus_STOP(); // start CNT
}

void PWM_Sinus_Init (void) {
	//RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // enable clock for TIM2
	//RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // enable clock for port A
	//RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; // enable clock for alternative gpio

	/****************************** Setting PA0 ***************************************/

	//GPIOA->CRL 	&= ~GPIO_CRL_CNF0; // setting out alternative push-pull for PWM1_CH1
	//GPIOA->CRL 	|= GPIO_CRL_CNF0_1;

	//GPIOA->CRL	&= ~GPIO_CRL_MODE0;
	//GPIOA->CRL	|= GPIO_CRL_MODE0; // gpio speed 50 MHz
	/****************************** Setting PA1 ***************************************/

	//GPIOA->CRL 	&= ~GPIO_CRL_CNF1; // setting out alternative push-pull for PWM1_CH1
	//GPIOA->CRL 	|= GPIO_CRL_CNF1_1;

	//GPIOA->CRL	&= ~GPIO_CRL_MODE1;
	//GPIOA->CRL	|= GPIO_CRL_MODE1; // gpio speed 50 MHz

	/*************************** Config PWM channel ***********************************/
		TIM3->PSC = SinResPSC; // div for clock: F = SYSCLK / [PSC + 1]
		TIM3->ARR = 1000; // count to 1000
		TIM3->CCR1 = 0; // duty cycle 0%
		TIM3->CCR2 = 0; // duty cycle 0%

			TIM3->CCER |= TIM_CCER_CC1E; // enable PWM out to PA8
			//TIM3->CCER &= ~TIM_CCER_CC1P; // active high level: 0 - high, 1 - low
			TIM3->CCER |= TIM_CCER_CC1P;

			TIM3->CCER |= TIM_CCER_CC2E; // enable PWM complementary out to PA9
			//TIM3->CCER &= ~TIM_CCER_CC2P; // active high level: 0 - high, 1 - low
			TIM3->CCER |= TIM_CCER_CC2P;

		// se idle state
		TIM3->CR2 |= TIM_CR2_OIS1;
		TIM3->CR2 |= TIM_CR2_OIS2;

		TIM3->CCMR1 &= ~(TIM_CCMR1_OC1M | TIM_CCMR1_OC2M);
		TIM3->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 |
		 TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1; // positiv PWM1_CH1 and PWM1_CH2

		/*******************************************************************************/

		TIM3->CR1 &= ~TIM_CR1_DIR; // count up: 0 - up, 1 - down
		TIM3->CR1 &= ~TIM_CR1_CMS; // aligned on the front signal: 00 - front; 01, 10, 11 - center

}
////////////////////// INIT GENERATOR PWM LOW - END //////////////////////

