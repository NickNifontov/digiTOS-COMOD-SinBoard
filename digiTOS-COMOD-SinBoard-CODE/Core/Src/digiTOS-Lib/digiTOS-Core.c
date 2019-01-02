/*
 * digiTOS-Core.c
 *
 *  Created on: 8 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#include "digiTOS-Core.h"

volatile enum fBoardStatus BoardStatus=sBoot;
volatile int DevMode1=0;

char uart_buff[100];
char crc_buff[20];
volatile int huart1_finished_tx = 1;
volatile enum fSinWave SinWave=swStop;
int FaultWaitCnt=0;
int RstCnt=0;

button_struct_t DevModeKey; // button DEV_MODE1
button_struct_t DevModeKey2; // button DEV_MODE2
button_struct_t FaultFlag; // button FAULT_FEEDBACK_Pin

uint32_t TM_CRC_Calculate8(uint8_t* arr, uint32_t count, uint8_t reset) {
	uint32_t cnt;

	/* Reset CRC data register if necessary */
	if (reset) {
		/* Reset generator */
		CRC->CR = CRC_CR_RESET;
	}

	/* Calculate number of 32-bit blocks */
	cnt = count >> 2;

	/* Calculate */
	while (cnt--) {
		/* Set new value */
		CRC->DR = *(uint32_t *)arr;

		/* Increase by 4 */
		arr += 4;
	}

	/* Calculate remaining data as 8-bit */
	cnt = count % 4;

	/* Calculate */
	while (cnt--) {
		/* Set new value */
		*((uint8_t *)&CRC->DR) = *arr++;
	}

	/* Return data */
	return CRC->DR;
}

uint32_t TM_CRC_Calculate16(uint16_t* arr, uint32_t count, uint8_t reset) {
	uint32_t cnt;

	/* Reset CRC data register if necessary */
	if (reset) {
		/* Reset generator */
		CRC->CR = CRC_CR_RESET;
	}

	/* Calculate number of 32-bit blocks */
	cnt = count >> 1;

	/* Calculate */
	while (cnt--) {
		/* Set new value */
		CRC->DR = *(uint32_t *)arr;

		/* Increase by 2 */
		arr += 2;
	}

	/* Calculate remaining data as 8-bit */
	cnt = count % 4;

	/* Calculate */
	while (cnt--) {
		/* Set new value */
		*((uint8_t *)&CRC->DR) = *arr++;
	}

	/* Return data */
	return CRC->DR;
}

uint32_t TM_CRC_Calculate32(uint32_t* arr, uint32_t count, uint8_t reset) {
	/* Reset CRC data register if necessary */
	if (reset) {
		/* Reset generator */
		CRC->CR = CRC_CR_RESET;
	}

	/* Calculate CRC */
	while (count--) {
		/* Set new value */
		CRC->DR = *arr++;
	}

	/* Return data */
	return CRC->DR;
}

/*uint16_t crc16Update(uint16_t crc, uint8_t a)
{
  int iii;
  crc ^= a;
  for (iii = 0; iii < 8; ++iii)  {
    if (crc & 1)
      crc = (crc >> 1) ^ 0xA001;
    else
      crc = (crc >> 1);
  }
  return crc;
}

uint32_t Get_CRC(uint8_t * p, uint16_t len) {
	  uint32_t res= ~0;
	  for (uint16_t i_index = 0; i_index < len - 2; ++i_index)
		 res = crc16Update( res, *p++);
	  return res;
}*/

void AddUART_Header() {
	ClearUART_Buff();
	strcat(uart_buff,"@data@");
}

void AddUART_CRC() {
	memset(crc_buff, '\0', sizeof(crc_buff));
	//uint32_t crc=Get_CRC((uint8_t *) &uart_buff, sizeof(uart_buff));
	uint32_t crc=TM_CRC_Calculate8((uint8_t *) &uart_buff, sizeof(uart_buff), 1);
	sprintf(crc_buff, "@crc@%08X@\r\n",  crc);
	strcat(uart_buff,crc_buff);

}

void Get_ChipID(void) {
	ClearUART_Buff();


	/* Format unique ID */
	sprintf(uart_buff, "@id@%08X-%08X-%08X",   TM_ID_GetUnique32(0),
			 TM_ID_GetUnique32(1), TM_ID_GetUnique32(2));

	AddUART_CRC();
}

/*void Get_Signature(void) {
	uart_buff[0]=0;


    // Format device signature
    sprintf(uart_buff, "Device signature: %04X", TM_ID_GetSignature());
    strcat(uart_buff,"\r\n");

}

void Get_Revision(void) {
	uart_buff[0]=0;

    // Format revision
    sprintf(uart_buff, "Revision: %04X", TM_ID_GetRevision());
    strcat(uart_buff,"\r\n");

}

void Get_Package(void) {
	uart_buff[0]=0;

    // Format package
    sprintf(uart_buff, "Package: %04X", TM_ID_GetPackage());
    strcat(uart_buff,"\r\n");

}*/

void Get_FlashSize(void) {
	ClearUART_Buff();

    /* Format flash size */
    sprintf(uart_buff, "@flash_size@%02d", TM_ID_GetFlashSize());

    AddUART_CRC();
}

void Get_Version(void) {
	ClearUART_Buff();

	strcat(uart_buff,"@version@");

    strcat(uart_buff,__DATE__);

    AddUART_CRC();
}

void SerialPrintln(int WaitForTX) {

	huart1_finished_tx = 0;
	while (HAL_UART_Transmit_DMA(&huart1, (uint8_t*) uart_buff, sizeof(uart_buff)-1) == HAL_BUSY);
	if (WaitForTX) {
		WaitForUART_TX();
	}
}

void ClearUART_Buff() {
	memset(uart_buff, '\0', sizeof(uart_buff));
}

void WaitForUART_TX() {
	while (!huart1_finished_tx);
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)  // change USART instance
    {
    	huart1_finished_tx = 1;
    	ClearUART_Buff();
    }
}

void ResetWDG() {
	 HAL_IWDG_Refresh(&hiwdg);
	 //IWDG->KR = 0x0000AAAAU;
}
