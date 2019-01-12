/*
 * digiTOS-Configuration.c
 *
 *  Created on: 5 ˇÌ‚. 2019 „.
 *      Author: Nick Nifontov
 */

#include "digiTOS-Configuration.h"

// ************** √ÀŒ¡¿À‹Õ€≈ Õ¿—“–Œ… » œ–Œ≈ “¿ - digiTOS ************** //
#ifdef AMP_PROTECTION
	int AMP_PROTECTION_CNT=0;
	int AMP_BLOCKED=0;
	int AMP_PROTECTION_CNT_BEFORESTART=0;
#endif

#ifdef VOUT_PROTECTION
	int VOUT_PROTECTION_CNT=0;
	int VOUT_PROTECTION_CNT_BEFORESTART=0;
	int VOUT_BLOCKED=0;
#endif

#ifdef IOUT_PROTECTION
 int IOUT_PROTECTION_CNT=0;
 int IOUT_PROTECTION_CNT_BEFORESTART=0;
 int IOUT_BLOCKED=0;
#endif

#ifdef DC_PROTECTION
	int DC_PROTECTION_CNT=0;
	int DC_PROTECTION_CNT_BEFORESTART=0;
	volatile uint32_t DC_Data=0;
	volatile uint32_t DC_DataCnt=0;
	volatile uint32_t DC_DataAverage=0;
	int DC_BLOCKED=0;
#endif

// ************** V_OUT SECTION ************** //
volatile uint16_t ADC_Data[ADC_ChannelCnt];
volatile uint32_t ADC_Cnt[ADC_ChannelCnt];

volatile uint32_t V_1=V1_etalon;
volatile uint32_t V_2=V2_etalon;
volatile uint32_t V_3=V3_etalon;
volatile uint32_t V_4=V4_etalon;

// I_OUT
volatile uint32_t I_Out=0;
volatile uint32_t I_Out_Cnt=1;
volatile uint64_t I_Out_RawData=0;

#ifdef Detect_ZeroI_Point
	volatile uint32_t ZeroI_point=StartIZeroPoint;
	volatile float I_RATIO=1;
#endif


#ifndef Detect_ZeroI_Point
	volatile float I_RATIO=(3636*IV_RATIO);
#endif
//


// V_OUT
volatile uint32_t V_Out=0;
volatile uint32_t V_Out_Cnt=1;
volatile uint64_t V_Out_RawData=0;

#ifdef Detect_ZeroV_Point
	volatile uint32_t ZeroV_point=StartVZeroPoint;
	volatile float V_RATIO=1;
#endif

#ifndef Detect_ZeroV_Point
	volatile float V_RATIO=(132*IV_RATIO);
#endif
//


#ifdef USE_VREF
	volatile uint32_t V_5=1500; // VREF
	uint32_t VDDA_Actual;
	volatile uint32_t V_Cnt[5]={1,1,1,1,1};
#endif

#ifndef USE_VREF
	volatile uint32_t V_Cnt[4]={1,1,1,1};
#endif

#ifdef AMP_CORRECTION_TYPE_STEP
 float amp1_correction_step=0;
 float amp2_correction_step=0;
 float amp3_correction_step=0;
 float amp4_correction_step=0;

 float amp1_target=1;
 float amp2_target=1;
 float amp3_target=1;
 float amp4_target=1;
#endif

 // ************** SINUS DATA ************** //
 int Sin_Amp_ind[4]={89,179,279,359};

 // Sinus table with 600 point Height
 volatile uint16_t sin_data[SinRes] =
{0, 5, 10, 16, 21, 26, 31, 37, 42, 47, 52, 58, 63, 68, 73, 78, 84, 89, 94, 99, 104, 109, 114,
		120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195, 200,
		205, 210, 215, 220, 225, 230, 234, 239, 244, 249, 254, 258, 263, 268, 272, 277, 282,
		286, 291, 295, 300, 305, 309, 313, 318, 322, 327, 331, 336, 340, 344, 348, 353, 357,
		361, 365, 369, 374, 378, 382, 386, 390, 394, 398, 401, 405, 409, 413, 417, 421, 424,
		428, 432, 435, 439, 442, 446, 449, 453, 456, 460, 463, 466, 470, 473, 476, 479, 482,
		485, 488, 491, 494, 497, 500, 503, 506, 509, 512, 514, 517, 520, 522, 525, 527, 530,
		532, 535, 537, 539, 542, 544, 546, 548, 550, 552, 554, 556, 558, 560, 562, 564, 566,
		567, 569, 571, 572, 574, 575, 577, 578, 580, 581, 582, 583, 585, 586, 587, 588, 589,
		590, 591, 592, 593, 593, 594, 595, 596, 596, 597, 597, 598, 598, 599, 599, 599, 599,
		600, 600, 600, 600, 600, 600, 600, 600, 600, 599, 599, 599, 599, 598, 598, 597, 597,
		596, 596, 595, 594, 593, 593, 592, 591, 590, 589, 588, 587, 586, 585, 583, 582, 581,
		580, 578, 577, 575, 574, 572, 571, 569, 567, 566, 564, 562, 560, 558, 556, 554, 552,
		550, 548, 546, 544, 542, 539, 537, 535, 532, 530, 527, 525, 522, 520, 517, 514, 512,
		509, 506, 503, 500, 497, 494, 491, 488, 485, 482, 479, 476, 473, 470, 466, 463, 460,
		456, 453, 449, 446, 442, 439, 435, 432, 428, 424, 421, 417, 413, 409, 405, 401, 398,
		394, 390, 386, 382, 378, 374, 369, 365, 361, 357, 353, 348, 344, 340, 336, 331, 327,
		322, 318, 313, 309, 305, 300, 295, 291, 286, 282, 277, 272, 268, 263, 258, 254, 249,
		244, 239, 234, 230, 225, 220, 215, 210, 205, 200, 195, 190, 185, 180, 175, 170, 165,
		160, 155, 150, 145, 140, 135, 130, 125, 120, 114, 109, 104, 99, 94, 89, 84, 78, 73,
		68, 63, 58, 52, 47, 42, 37, 31, 26, 21, 16, 10, 5};


 volatile uint16_t sin_step=0;
 volatile uint8_t sinStatus=0;


#ifdef AMP_CORRECTION_TYPE_STEP // AKA SOFTSTART
	volatile float Sine_Amplitude_1=Amp_min;
	volatile float Sine_Amplitude_2=Amp_min;
	volatile float Sine_Amplitude_3=Amp_min;
	volatile float Sine_Amplitude_4=Amp_min;
#endif

#ifdef AMP_CORRECTION_TYPE_IMMIDIATLY // AKA SOFTSTART
	volatile float Sine_Amplitude_1=1;
	volatile float Sine_Amplitude_2=1;
	volatile float Sine_Amplitude_3=1;
	volatile float Sine_Amplitude_4=1;
#endif
