/*
 * digiTOS-Core.h
 *
 *  Created on: 8 ���. 2018 �.
 *      Author: Nick Nifontov
 */

#ifndef DIGITOS_CORE_H_
#define DIGITOS_CORE_H_

#include "digiTOS-Configuration.h"
#include "digiTOS-ADC.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "iwdg.h"

#include "digiTOS-IWDG.h"
#include "stm32f0xx_hal_buttons.h"

#include "eeprom.h"


// GLOBAL
extern volatile int UpdateAmp_FLAG;

// EEPROM
extern int EEPROM_FLAG;
int InitEEPROM();
//void StoreEEPROM(float V_CAL, float I_CAL);
void StoreEEPROM(uint32_t V_CAL, uint32_t I_CAL);
#define EEPROM_DATA_SIZE 2
extern uint32_t EEPROM_DATA[EEPROM_DATA_SIZE];
extern uint32_t EEPROM_CRC;
extern uint16_t EEPROMStoredCnt;
int CalibCmdCheck();

#define EEPROMDelayBeforeNewStore 10
// VCC Calib
// I Calib
// CRC
//

void USE_DEF_CALIB();
void USE_NEW_CALIB();

extern int FaultWaitCnt;
extern int RstCnt;

enum fBoardStatus {sBoot, sGEN, sUnknown, sFaultFlag};
enum fSinWave {swStop, swStart, swGEN, swNOP};

extern button_struct_t DevModeKey; // button DEV_MODE1
extern button_struct_t DevModeKey2; // button DEV_MODE2
extern button_struct_t FaultFlag; // button FAULT_FEEDBACK_Pin

extern button_struct_t CALIB_V; // button CALIB V_OUT
extern button_struct_t CALIB_I; // button CALIB I_OUT

extern button_struct_t CALIB_MODE; // button CALIB CALIB_MODE

extern volatile enum fBoardStatus BoardStatus;
extern char uart_buff[100];
//extern char cmd_buff[20];
extern volatile int huart1_finished_tx;
extern volatile int DevMode1;
extern volatile int CalibMode;
extern volatile enum fSinWave SinWave;

void Get_ChipID(void);
void Get_FlashSize(void);
void Get_Version(void);

void ResetWDG();

void InitUART_RX();

//void Get_Package(void);
//void Get_Revision(void);
//void Get_Signature(void);

void SerialPrintln(int WaitForTX);
void ClearUART_Buff();
void WaitForUART_TX();

void CheckUART_Command();

void PrintCurrentState();

// Math
//float map(float value, float istart, float istop, float ostart, float ostop);
//float remap(uint32_t value, uint16_t istart, uint16_t istop, float ostart, float ostop);

#endif /* DIGITOS_CORE_H_ */
