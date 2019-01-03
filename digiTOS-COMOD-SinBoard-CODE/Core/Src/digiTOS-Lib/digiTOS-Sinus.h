/*
 * digiTOS-Sinus.h
 *
 *  Created on: 31 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#ifndef SRC_DIGITOS_LIB_DIGITOS_SINUS_H_
#define SRC_DIGITOS_LIB_DIGITOS_SINUS_H_

#define SinRes 240
//#define SinRes 480

#define MinSinusData 30
#define MaxSinusData 970

#include "stm32f0xx_hal.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>

extern volatile float Sine_Amplitude_1;
extern volatile float Sine_Amplitude_2;
extern volatile float Sine_Amplitude_3;
extern volatile float Sine_Amplitude_4;

extern volatile uint16_t sin_data[SinRes];
extern int Sin_Amp_ind[4];

extern volatile uint16_t sin_step;
extern volatile uint8_t sinStatus;

uint16_t GetSinus();
void ResetAmplitude();

#endif /* SRC_DIGITOS_LIB_DIGITOS_SINUS_H_ */
