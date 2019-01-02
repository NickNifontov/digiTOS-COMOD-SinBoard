/*
 * digiTOS-Core.h
 *
 *  Created on: 8 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#ifndef DIGITOS_CORE_H_
#define DIGITOS_CORE_H_

#include "stm32f0xx_hal.h"

//***** DEFINES - BEGIN *****//
#define Linear_V_Out  // V_Out liner from 0V...3.3V
//#define Sinus_V_Out // V_out sinus form

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

#define ADC_ChannelCnt 3

#define Amp_min 0.8
#define Amp_max 1.2
#define Amp_Coef 0.00009765625 //(float) (0.2/V_base)

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

#define sBoot_Delay 100
#define sAC_AC_Delay 1000
#define sAC_INV_Delay 1000
#define sDEF_Delay 1000
#define sRST_Delay 500

#define DelaySecBeforeAttemRst 10 //DelaySecBeforeStartAfterFault
#define DelaySecBeforeStartAfterFault 10 //DelaySecBeforeStartAfterFault
//***** DEFINES - END *****//

#include "usart.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "iwdg.h"

#include "stm32f0xx_hal_buttons.h"

extern int FaultWaitCnt;
extern int RstCnt;

enum fBoardStatus {sBoot, sGEN, sUnknown, sFaultFlag};
enum fSinWave {swStop, swStart, swGEN, swNOP};

extern button_struct_t DevModeKey; // button DEV_MODE1
extern button_struct_t DevModeKey2; // button DEV_MODE2
extern button_struct_t FaultFlag; // button FAULT_FEEDBACK_Pin

extern volatile enum fBoardStatus BoardStatus;
extern char uart_buff[100];
extern volatile int huart1_finished_tx;
extern volatile int DevMode1;
extern volatile enum fSinWave SinWave;

void Get_ChipID(void);
void Get_FlashSize(void);
void Get_Version(void);

void ResetWDG();

//void Get_Package(void);
//void Get_Revision(void);
//void Get_Signature(void);

void SerialPrintln(int WaitForTX);
void ClearUART_Buff();
void WaitForUART_TX();


#endif /* DIGITOS_CORE_H_ */
