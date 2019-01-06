/*
 * digiTOS-Core.h
 *
 *  Created on: 8 дек. 2018 г.
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

#include "stm32f0xx_hal_buttons.h"

#include "eeprom.h"
// EEPROM
extern int EEPROM_FLAG;
int InitEEPROM();
void StoreEEPROM(float V_CAL, float I_CAL);
#define EEPROM_DATA_SIZE 2
extern uint32_t EEPROM_DATA[EEPROM_DATA_SIZE];
extern uint32_t EEPROM_CRC;
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

extern volatile enum fBoardStatus BoardStatus;
extern char uart_buff[100];
//extern char cmd_buff[20];
extern volatile int huart1_finished_tx;
extern volatile int DevMode1;
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
