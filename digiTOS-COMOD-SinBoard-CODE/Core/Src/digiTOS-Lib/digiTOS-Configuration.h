/*
 * digiTOS-Configuration.h
 *
 *  Created on: 5 ÿíâ. 2019 ã.
 *      Author: Nick Nifontov
 */

#ifndef SRC_DIGITOS_LIB_DIGITOS_CONFIGURATION_H_
#define SRC_DIGITOS_LIB_DIGITOS_CONFIGURATION_H_

#include "stm32f0xx_hal.h"

// ************** CPU Info ************** //
#define ID_UNIQUE_ADDRESS 0x1FFFF7AC
//#define ID_PACKAGE_ADDRESS 0x1FFF7BF0
#define ID_FLASH_ADDRESS 0x1FFFF7CC

//#define TM_ID_GetSignature() (DBGMCU->IDCODE & 0x00000FFF)
//#define TM_ID_GetRevision() ((DBGMCU->IDCODE >> 16) & 0x0000FFFF)
//#define TM_ID_GetPackage() (((*(__IO uint16_t *) (ID_PACKAGE_ADDRESS)) & 0x0700) >> 8)
#define TM_ID_GetFlashSize() (*(__IO uint16_t *) (ID_FLASH_ADDRESS))

#define TM_ID_GetUnique8(x) ((x >= 0 && x < 12) ? (*(__IO uint8_t *) (ID_UNIQUE_ADDRESS + (x))) : 0)
#define TM_ID_GetUnique16(x) ((x >= 0 && x < 6) ? (*(__IO uint16_t *) (ID_UNIQUE_ADDRESS + 2 * (x))) : 0)
#define TM_ID_GetUnique32(x) ((x >= 0 && x < 3) ? (*(__IO uint32_t *) (ID_UNIQUE_ADDRESS + 4 * (x))) : 0)

#define VREFINT_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7BA))


// ************** ÃËÎÁÀËÜÍÛÅ ÍÀÑÒÐÎÉÊÈ ÏÐÎÅÊÒÀ - digiTOS ************** //
#define DC_PROTECTION // protection MAX/MIN DC_FEEDBACK detected
//#define OFF_DC_PROTECTION // protection MAX/MIN DC_FEEDBACK detected
// Stop and then restart after DelaySecBeforeStartAfterDCProtection

#ifdef DC_PROTECTION
	#define DC_PROTECTION_MAX (uint32_t) (3500)
	#define DC_PROTECTION_ROLLBACK (uint32_t) (2500) // gisteresis to roll-back at normal state

	#define DC_PROTECTION_WAVE_CNT 2000 //10sec

	extern int DC_PROTECTION_CNT;
	extern int DC_PROTECTION_CNT_BEFORESTART;
	#define DelaySecBeforeStartAfterDCProtection 30
	extern volatile uint32_t DC_Data;
	extern volatile uint32_t DC_DataCnt;
	extern volatile uint32_t DC_DataAverage;
	extern int DC_BLOCKED;
#endif

#ifndef DC_PROTECTION
	#define DC_BLOCKED 0
#endif


#define AMP_PROTECTION // protection if MAX/MIN AMP detected
//#define OFF_AMP_PROTECTION // protection if MAX/MIN AMP detected
// Stop and then restart after DelaySecBeforeStartAfterAmpProtection

#ifdef AMP_PROTECTION
	#define AMP_PROTECTION_MINMAX_CNT 2000 //10sec

	#define AMP_PROTECTION_MIN (uint16_t) (4*50) //Amp1+...+Amp4
	#define AMP_PROTECTION_MAX (uint16_t) (4*150) //Amp1+...+Amp4

	extern int AMP_PROTECTION_CNT;
	extern int AMP_PROTECTION_CNT_BEFORESTART;
	#define DelaySecBeforeStartAfterAmpProtection 30
	extern int AMP_BLOCKED;
#endif

#ifndef AMP_PROTECTION
	#define AMP_BLOCKED 0
#endif

#define DEBUG_MODE // if TRUE then in UART print text state

#define sBoot_Delay 100   						// LEDs Blink at boot mode (startup)
#define sAC_AC_Delay 1000						// NOP
#define sAC_INV_Delay 1000						// NOP
#define sDEF_Delay 1000							// Default delay  for UART communication period

#define sRST_Delay 500							// delay of signal that send RST (Reset signal)

#define DelaySecBeforeAttemRst 10 				//Delay in seconds before send Reset signal if FAULT MODE
#define DelaySecBeforeStartAfterFault 10 		///Delay in seconds before startup after fault is gone and now is OK


// ************** ADC SECTION ************** //
//#define USE_VREF // NEED to ADC Vref

#ifdef USE_VREF
//#define USE_VREF_FOR_ADC_CORRECTION // ONLY if USE_VREF=TRUE !!!

#define ADC_ChannelCnt 4
// Channel0=		V_OUT				PA1
// Channel1=		C_OUT				PA2
// Channel2=		DC_FEEDBACK			PA5
// Channel3=		VREF_INT
#endif

#ifndef USE_VREF
#define ADC_ChannelCnt 3
// Channel0=		V_OUT				PA1
// Channel1=		C_OUT				PA2
// Channel2=		DC_FEEDBACK			PA5
#endif

extern volatile uint16_t ADC_Data[ADC_ChannelCnt]; // ADC DMA's collected data
extern volatile uint32_t ADC_Cnt[ADC_ChannelCnt];  // count of collected data to calculate average

extern volatile uint32_t V_1;  // Data for Slice 1 of Sinus form
extern volatile uint32_t V_2;  // Data for Slice 2 of Sinus form
extern volatile uint32_t V_3;  // Data for Slice 3 of Sinus form
extern volatile uint32_t V_4;  // Data for Slice 4 of Sinus form

#ifndef USE_VREF
	extern volatile uint32_t V_Cnt[]; // Counts of Slices
#endif

#ifdef USE_VREF
	extern uint32_t VDDA_Actual;
	extern volatile uint32_t V_5;  // VREF Data
	extern volatile uint32_t V_Cnt[5]; // Counts of Slices
#endif



// ************** Sinus Generator SECTION ************** //
#define SinResPSC 1 // Prescaller for 50Hz generator, 24Khz freq
//#define SinResPSC 0  // Prescaller for 50Hz generator, 48Khz freq


// ************** V_OUT SECTION ************** //
#define Linear_V_Out  // V_Out liner from 0V...3.3V
//#define Sinus_V_Out // V_out sinus form, 4 step

#ifdef Sinus_V_Out
	#define V1_etalon 190
	#define V2_etalon 549
	#define V3_etalon 549
	#define V4_etalon 190
#endif

#ifdef Linear_V_Out
	#define V1_etalon 2048
	#define V2_etalon 2048
	#define V3_etalon 2048
	#define V4_etalon 2048
#endif

#define Amp_min (float)0.40 // min value of sinus Amplitude
#define Amp_max (float)1.6 // max value of sinus Amplitude

#define Amp_CoefPlus (float) ((Amp_max-1)/2048) // coef for correction sinus if V_out>Etalon
#define Amp_CoefMinus (float) ((1-Amp_min)/2048) // coef for correction sinus if V_out<Etalon

//#define AMP_CORRECTION_TYPE_IMMIDIATLY // Correct sinus amplitude immediately at next step of generation
#define AMP_CORRECTION_TYPE_STEP // Correct sinus at step algorithms to prevent flicks and realize softstar algorithms

#ifdef AMP_CORRECTION_TYPE_IMMIDIATLY
//NOP
#endif

#define USE_SOFT_START // Enable softstart of sinus generator. Activated ONLY if AMP_CORRECTION_TYPE_STEP=TRUE

#ifdef USE_SOFT_START
	#define SOFT_START_FROM 0.5  // Softstart generate sinus amplitude from SOFT_START_FROM...1.
#endif

#ifdef AMP_CORRECTION_TYPE_STEP //
	#define AMP_WAVE_CNT_CORRECTION 200 // 2sec from Amp_min to Amp_max, 200 wave=2secounds
	#define amp_correction_step (float) ((Amp_max-Amp_min)/AMP_WAVE_CNT_CORRECTION)

	extern float amp1_target;
	extern float amp2_target;
	extern float amp3_target;
	extern float amp4_target;
#endif


// ************** SINUS DATA ************** //
#define SinRes 240
//#define SinRes 480

#define MinSinusData 30
#define MaxSinusData 970

extern volatile float Sine_Amplitude_1;
extern volatile float Sine_Amplitude_2;
extern volatile float Sine_Amplitude_3;
extern volatile float Sine_Amplitude_4;

extern volatile uint16_t sin_data[SinRes];
extern int Sin_Amp_ind[4];

extern volatile uint16_t sin_step;
extern volatile uint8_t sinStatus;

#endif /* SRC_DIGITOS_LIB_DIGITOS_CONFIGURATION_H_ */
