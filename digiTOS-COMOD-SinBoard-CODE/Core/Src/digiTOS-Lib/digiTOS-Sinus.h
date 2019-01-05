/*
 * digiTOS-Sinus.h
 *
 *  Created on: 31 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#ifndef SRC_DIGITOS_LIB_DIGITOS_SINUS_H_
#define SRC_DIGITOS_LIB_DIGITOS_SINUS_H_

#include "digiTOS-Core.h"

#include <stdio.h>
#include <string.h>
#include <stdint.h>

uint16_t GetSinus();
void ResetAmplitude(); // call only at Generator start

#endif /* SRC_DIGITOS_LIB_DIGITOS_SINUS_H_ */
