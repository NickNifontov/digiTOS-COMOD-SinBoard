/*
 * digiTOS-Generator.h
 *
 *  Created on: 30 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#ifndef SRC_DIGITOS_LIB_DIGITOS_GENERATOR_H_
#define SRC_DIGITOS_LIB_DIGITOS_GENERATOR_H_

#include "stm32f0xx_hal.h"

#define SinResPSC 1
//#define SinResPSC 0


//-------------------- 50Hz ----------------------------------//
////////////////////// DEAD TIME - BEGIN //////////////////////
void Set50HzDeadTimeNS(void);
////////////////////// DEAD TIME - END //////////////////////



////////////////////// SIGNAL INVERSE - BEGIN //////////////////////
void SetNormalSignal(void);
void SetInverseSignal(void);
////////////////////// SIGNAL INVERSEE - END //////////////////////



////////////////////// IDLE STATE - BEGIN //////////////////////
void Idle_SET(void);
void Idle_RESET(void);
////////////////////// IDLE STAT - END //////////////////////



////////////////////// INIT GENERATOR 50Hz - BEGIN //////////////////////
void PWM_50Hz_Init (void);
////////////////////// INIT GENERATOR 50Hz - END //////////////////////



////////////////////// CONTROL 50Hz - BEGIN //////////////////////
void PWM_50Hz_OUTEN(void);
void PWM_50Hz_OUTDIS(void);
void PWM_50Hz_START(void);
void PWM_50Hz_STOP(void);
void PWM_50Hz_ON(void);
void PWM_50Hz_OFF(void);
//static void timer1_update_irq_enable(void);
////////////////////// CONTROL 50Hz - END //////////////////////


//-------------------- PWM LOW ----------------------------------//
////////////////////// INIT GENERATOR PWM LOW - BEGIN //////////////////////
void PWM_Sinus_Init (void);
////////////////////// INIT GENERATOR PWM LOW - END //////////////////////



////////////////////// PWM LOW - BEGIN //////////////////////
void PWM_Sinus_START(void);
void PWM_Sinus_STOP(void);
void PWM_Sinus_OUTEN(void);
void PWM_Sinus_OUTDIS(void);
void PWM_Sinus_ON(void);
void PWM_Sinus_OFF(void);
////////////////////// PWM LOW - END //////////////////////

#endif /* SRC_DIGITOS_LIB_DIGITOS_GENERATOR_H_ */
