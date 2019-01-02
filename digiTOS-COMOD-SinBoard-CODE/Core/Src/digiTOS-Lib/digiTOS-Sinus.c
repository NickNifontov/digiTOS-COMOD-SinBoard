/*
 * digiTOS-Sinus.c
 *
 *  Created on: 31 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#include "digiTOS-Sinus.h"

int Sin_Amp_ind[4]={59,119,179,239};

volatile uint16_t sin_data[SinRes] =
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

volatile uint16_t sin_step=0;
volatile uint8_t sinStatus=0;
volatile float Sine_Amplitude_1=1;
volatile float Sine_Amplitude_2=1;
volatile float Sine_Amplitude_3=1;
volatile float Sine_Amplitude_4=1;

//int Sin_Amp_ind[4]={59=0,119=1,179=2,239=3};

void ResetAmplitude() {
	Sine_Amplitude_4=1;
	Sine_Amplitude_3=1;
	Sine_Amplitude_2=1;
	Sine_Amplitude_1=1;
}

void SetApmlitude(float Value) {
	if (sin_step>Sin_Amp_ind[2]) {
		Sine_Amplitude_4=Value;
		return;
	}
	if (sin_step>Sin_Amp_ind[1]) {
		Sine_Amplitude_3=Value;
		return;
	}
	if (sin_step>Sin_Amp_ind[0]) {
		Sine_Amplitude_2=Value;
		return;
	} else {
		Sine_Amplitude_1=Value;
		return;
	}
}

float GetApmlitude() {
	if (sin_step>Sin_Amp_ind[2]) {
		return Sine_Amplitude_4;
	}
	if (sin_step>Sin_Amp_ind[1]) {
		return Sine_Amplitude_3;
	}
	if (sin_step>Sin_Amp_ind[0]) {
		return Sine_Amplitude_2;
	}
	return Sine_Amplitude_1;
}

uint16_t GetSinus() {
	if (sin_step >= SinRes) {
		sin_step = 0;
	}
	uint16_t fSinusData=sin_data[sin_step];
	float curAmplitude=GetApmlitude();
	if (curAmplitude!=1) {
		fSinusData=(float) (curAmplitude*fSinusData);
	}
	if (fSinusData<MinSinusData) {
		return MinSinusData;
	}
	if (fSinusData<MinSinusData) {
		return MaxSinusData;
	}
	return fSinusData;
}
