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

// ************** V_OUT SECTION ************** //
volatile uint16_t ADC_Data[ADC_ChannelCnt];
volatile uint32_t ADC_Cnt[ADC_ChannelCnt];

volatile uint32_t V_1=V1_etalon;
volatile uint32_t V_2=V2_etalon;
volatile uint32_t V_3=V3_etalon;
volatile uint32_t V_4=V4_etalon;

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
 int Sin_Amp_ind[4]={59,119,179,239};

 // Sinus table with 1000 point Height
 /*volatile uint16_t sin_data[SinRes] =
 {0, 13, 26, 39, 52, 65, 78, 92, 105, 118, 131, 143, 156, 169, 182, 195, 208, 221, 233, 246, 259, 271, 284,
 		297, 309, 321, 334, 346, 358, 371, 383, 395, 407, 419, 431, 442, 454, 466, 477, 489, 500, 511, 522,
 		534, 545, 556, 566, 577, 588, 598, 609, 619, 629, 639, 649, 659, 669, 679, 688, 698, 707, 716, 725,
 		734, 743, 752, 760, 769, 777, 785, 793, 801, 809, 817, 824, 831, 839, 846, 853, 859, 866, 872, 879,
 		885, 891, 897, 903, 908, 914, 919, 924, 929, 934, 938, 943, 947, 951, 955, 959, 962, 966, 969, 972,
 		975, 978, 981, 983, 986, 988, 990, 991, 993, 995, 996, 997, 998, 999, 999, 1000, 1000, 1000, 1000,
 		1000, 999, 999, 998, 997, 996, 995, 993, 991, 990, 988, 986, 983, 981, 978, 975, 972, 969, 966, 962,
 		959, 955, 951, 947, 943, 938, 934, 929, 924, 919, 914, 908, 903, 897, 891, 885, 879, 872, 866, 859,
 		853, 846, 839, 831, 824, 817, 809, 801, 793, 785, 777, 769, 760, 752, 743, 734, 725, 716, 707, 698,
 		688, 679, 669, 659, 649, 639, 629, 619, 609, 598, 588, 577, 566, 556, 545, 534, 522, 511, 500, 489,
 		477, 466, 454, 442, 431, 419, 407, 395, 383, 371, 358, 346, 334, 321, 309, 297, 284, 271, 259, 246,
 		233, 221, 208, 195, 182, 169, 156, 143, 131, 118, 105, 92, 78, 65, 52, 39, 26, 13};
 */

 // Sinus table with 600 point Height
 volatile uint16_t sin_data[SinRes] =
 {0, 8, 16, 24, 31, 39, 47, 55, 63, 71, 78, 86, 94, 102, 109, 117, 125, 132, 140, 148, 155, 163, 170, 178, 185,
 193, 200, 208, 215, 222, 230, 237, 244, 251, 258, 265, 272, 279, 286, 293, 300, 307, 313, 320, 327, 333, 340,
 346, 353, 359, 365, 371, 378, 384, 390, 396, 401, 407, 413, 419, 424, 430, 435, 441, 446, 451, 456, 461, 466,
 471, 476, 481, 485, 490, 494, 499, 503, 507, 512, 516, 520, 523, 527, 531, 535, 538, 542, 545, 548, 551, 554,
 557, 560, 563, 566, 568, 571, 573, 575, 577, 580, 582, 583, 585, 587, 588, 590, 591, 593, 594, 595, 596, 597,
 597, 598, 599, 599, 600, 600, 600, 600, 600, 600, 600, 599, 599, 598, 597, 597, 596, 595, 594, 593, 591, 590,
 588, 587, 585, 583, 582, 580, 577, 575, 573, 571, 568, 566, 563, 560, 557, 554, 551, 548, 545, 542, 538, 535,
 531, 527, 523, 520, 516, 512, 507, 503, 499, 494, 490, 485, 481, 476, 471, 466, 461, 456, 451, 446, 441, 435,
 430, 424, 419, 413, 407, 401, 396, 390, 384, 378, 371, 365, 359, 353, 346, 340, 333, 327, 320, 313, 307, 300,
 293, 286, 279, 272, 265, 258, 251, 244, 237, 230, 222, 215, 208, 200, 193, 185, 178, 170, 163, 155, 148, 140,
 132, 125, 117, 109, 102, 94, 86, 78, 71, 63, 55, 47, 39, 31, 24, 16, 8};


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
