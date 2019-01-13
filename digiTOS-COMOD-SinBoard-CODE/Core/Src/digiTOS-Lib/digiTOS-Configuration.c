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
volatile uint32_t ADC_Data[ADC_ChannelCnt];
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
 int Sin_Amp_ind[4]={179,359,539,719};

 // Sinus table with 600 point Height
 volatile uint16_t sin_data[SinRes] =
{0, 3, 5, 8, 10, 13, 16, 18, 21, 24, 26, 29, 31, 34, 37, 39, 42, 44, 47, 50, 52, 55, 58, 60, 63,
		65, 68, 71, 73, 76, 78, 81, 84, 86, 89, 91, 94, 96, 99, 102, 104, 107, 109, 112, 114, 117,
		120, 122, 125, 127, 130, 132, 135, 138, 140, 143, 145, 148, 150, 153, 155, 158, 160, 163,
		165, 168, 170, 173, 175, 178, 180, 183, 185, 188, 190, 193, 195, 198, 200, 203, 205, 208,
		210, 213, 215, 217, 220, 222, 225, 227, 230, 232, 234, 237, 239, 242, 244, 246, 249, 251,
		254, 256, 258, 261, 263, 265, 268, 270, 272, 275, 277, 279, 282, 284, 286, 289, 291, 293,
		295, 298, 300, 302, 305, 307, 309, 311, 313, 316, 318, 320, 322, 325, 327, 329, 331, 333,
		336, 338, 340, 342, 344, 346, 348, 351, 353, 355, 357, 359, 361, 363, 365, 367, 369, 371,
		374, 376, 378, 380, 382, 384, 386, 388, 390, 392, 394, 396, 398, 400, 401, 403, 405, 407,
		409, 411, 413, 415, 417, 419, 421, 422, 424, 426, 428, 430, 432, 433, 435, 437, 439, 441,
		442, 444, 446, 448, 449, 451, 453, 455, 456, 458, 460, 461, 463, 465, 466, 468, 470, 471,
		473, 474, 476, 478, 479, 481, 482, 484, 485, 487, 488, 490, 491, 493, 494, 496, 497, 499,
		500, 502, 503, 505, 506, 507, 509, 510, 512, 513, 514, 516, 517, 518, 520, 521, 522, 523,
		525, 526, 527, 529, 530, 531, 532, 533, 535, 536, 537, 538, 539, 540, 542, 543, 544, 545,
		546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563,
		564, 565, 566, 566, 567, 568, 569, 570, 571, 571, 572, 573, 574, 575, 575, 576, 577, 577,
		578, 579, 580, 580, 581, 582, 582, 583, 583, 584, 585, 585, 586, 586, 587, 587, 588, 588,
		589, 589, 590, 590, 591, 591, 592, 592, 593, 593, 593, 594, 594, 595, 595, 595, 596, 596,
		596, 596, 597, 597, 597, 597, 598, 598, 598, 598, 599, 599, 599, 599, 599, 599, 599, 600,
		600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600,
		599, 599, 599, 599, 599, 599, 599, 598, 598, 598, 598, 597, 597, 597, 597, 596, 596, 596,
		596, 595, 595, 595, 594, 594, 593, 593, 593, 592, 592, 591, 591, 590, 590, 589, 589, 588,
		588, 587, 587, 586, 586, 585, 585, 584, 583, 583, 582, 582, 581, 580, 580, 579, 578, 577,
		577, 576, 575, 575, 574, 573, 572, 571, 571, 570, 569, 568, 567, 566, 566, 565, 564, 563,
		562, 561, 560, 559, 558, 557, 556, 555, 554, 553, 552, 551, 550, 549, 548, 547, 546, 545,
		544, 543, 542, 540, 539, 538, 537, 536, 535, 533, 532, 531, 530, 529, 527, 526, 525, 523,
		522, 521, 520, 518, 517, 516, 514, 513, 512, 510, 509, 507, 506, 505, 503, 502, 500, 499,
		497, 496, 494, 493, 491, 490, 488, 487, 485, 484, 482, 481, 479, 478, 476, 474, 473, 471,
		470, 468, 466, 465, 463, 461, 460, 458, 456, 455, 453, 451, 449, 448, 446, 444, 442, 441,
		439, 437, 435, 433, 432, 430, 428, 426, 424, 422, 421, 419, 417, 415, 413, 411, 409, 407,
		405, 403, 401, 400, 398, 396, 394, 392, 390, 388, 386, 384, 382, 380, 378, 376, 374, 371,
		369, 367, 365, 363, 361, 359, 357, 355, 353, 351, 348, 346, 344, 342, 340, 338, 336, 333,
		331, 329, 327, 325, 322, 320, 318, 316, 313, 311, 309, 307, 305, 302, 300, 298, 295, 293,
		291, 289, 286, 284, 282, 279, 277, 275, 272, 270, 268, 265, 263, 261, 258, 256, 254, 251,
		249, 246, 244, 242, 239, 237, 234, 232, 230, 227, 225, 222, 220, 217, 215, 213, 210, 208,
		205, 203, 200, 198, 195, 193, 190, 188, 185, 183, 180, 178, 175, 173, 170, 168, 165, 163,
		160, 158, 155, 153, 150, 148, 145, 143, 140, 138, 135, 132, 130, 127, 125, 122, 120, 117,
		114, 112, 109, 107, 104, 102, 99, 96, 94, 91, 89, 86, 84, 81, 78, 76, 73, 71, 68, 65, 63,
		60, 58, 55, 52, 50, 47, 44, 42, 39, 37, 34, 31, 29, 26, 24, 21, 18, 16, 13, 10, 8, 5, 3};


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
