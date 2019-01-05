/*
 * digiTOS-ADC.h
 *
 *  Created on: 31 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#ifndef SRC_DIGITOS_LIB_DIGITOS_ADC_H_
#define SRC_DIGITOS_LIB_DIGITOS_ADC_H_

#include "digiTOS-Core.h"
#include "digiTOS-Sinus.h"
#include "adc.h"
#include "stm32f0xx_it.h"

//******* ADC *********//
//extern uint32_t adc_cnt1;
void StartADC();
//******* ADC *********//

//******* AMPLITUDE **********//
void ResetV_data();
void UpdateAmplitudeByV();
void CheckV_Feedback();
//******* AMPLITUDE **********//


//******* TEMP **********//
//Temperature sensor raw value at 30 degrees C, VDDA=3.3V
//#define TEMP30_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7B8))
//Temperature sensor raw value at 110 degrees C, VDDA=3.3V
//#define TEMP110_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7C2))
//Internal voltage reference raw value at 30 degrees C, VDDA=3.3V
//#define VREFINT_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7BA))

//extern char temp_buffer[50];

//int32_t GetCPU_Temp();
//******* TEMP **********//

#endif /* SRC_DIGITOS_LIB_DIGITOS_ADC_H_ */
