/*
 * digiTOS-Sinus.c
 *
 *  Created on: 31 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#include "digiTOS-Sinus.h"
#include "digiTOS-Core.h"

void ResetAmplitude() {
	#ifdef AMP_CORRECTION_TYPE_IMMIDIATLY
		Sine_Amplitude_4=1;
		Sine_Amplitude_3=1;
		Sine_Amplitude_2=1;
		Sine_Amplitude_1=1;
	#endif

	#ifdef AMP_CORRECTION_TYPE_STEP
		#ifdef USE_SOFT_START
			Sine_Amplitude_4=SOFT_START_FROM;
			Sine_Amplitude_3=SOFT_START_FROM;
			Sine_Amplitude_2=SOFT_START_FROM;
			Sine_Amplitude_1=SOFT_START_FROM;
		#endif

		#ifndef USE_SOFT_START
			Sine_Amplitude_4=1;
			Sine_Amplitude_3=1;
			Sine_Amplitude_2=1;
			Sine_Amplitude_1=1;
		#endif
	#endif
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
		fSinusData=(uint16_t) (curAmplitude*fSinusData);
	}
	if (fSinusData<=MinSinusData) {
		return MinSinusData;
	}
	if (fSinusData>=MaxSinusData) {
		return MaxSinusData;
	}
	return fSinusData;
}
