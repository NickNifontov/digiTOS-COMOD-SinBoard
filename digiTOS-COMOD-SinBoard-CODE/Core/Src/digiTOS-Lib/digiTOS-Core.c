/*
 * digiTOS-Core.c
 *
 *  Created on: 8 дек. 2018 г.
 *      Author: Nick Nifontov
 */

#include "digiTOS-Core.h"

volatile int UpdateAmp_FLAG=0;

volatile enum fBoardStatus BoardStatus=sBoot;
volatile int DevMode1=0;
volatile int CalibMode=0;

int EEPROM_FLAG=0;
uint16_t EEPROMStoredCnt=EEPROMDelayBeforeNewStore;

char uart_buff[100];
//char cmd_buff[20];
char crc_buff[20];
volatile int huart1_finished_tx = 1;
volatile enum fSinWave SinWave=swStop;
int FaultWaitCnt=0;
int RstCnt=0;

uint32_t EEPROM_DATA[EEPROM_DATA_SIZE]={0,0};
uint32_t EEPROM_CRC=0;

button_struct_t DevModeKey; // button DEV_MODE1
button_struct_t DevModeKey2; // button DEV_MODE2
button_struct_t FaultFlag; // button FAULT_FEEDBACK_Pin
button_struct_t CALIB_V; // button CALIB V_OUT
button_struct_t CALIB_I; // button CALIB I_OUT

button_struct_t CALIB_MODE; // button CALIB CALIB_MODE


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
	sprintf(crc_buff, "@crc@%08X@\r\n",  (unsigned int) crc);
	strcat(uart_buff,crc_buff);

}

void Get_ChipID(void) {
	ClearUART_Buff();


	/* Format unique ID */
	sprintf(uart_buff, "@id@%08X-%08X-%08X",   (unsigned int) TM_ID_GetUnique32(0),
			(unsigned int) TM_ID_GetUnique32(1), (unsigned int) TM_ID_GetUnique32(2));

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


void PrintCurrentState() {
	if (DevMode1!=1) {
		return;
	}
	#ifdef DEBUG_MODE
	ClearUART_Buff();
			/*if(hdma_usart1_rx.State==HAL_DMA_STATE_READY)
	  		{
	  			//cmd_buff[19]=0;
	  			if (strncmp(cmd_buff,"calib",4)>=0) {
	  				strcpy(uart_buff,"SET V_CAL \r\n");
					float V_CAL=(273066/ADC_Data[0]);
					float I_CAL=(273066/ADC_Data[1]);
					StoreEEPROM(V_CAL,I_CAL);

	  			}
	  			memset(cmd_buff, '\0', sizeof(cmd_buff));
	  			HAL_UART_Receive_DMA(&huart1, (uint8_t*) cmd_buff, sizeof(cmd_buff));
	  			hdma_usart1_rx.State=HAL_DMA_STATE_BUSY;
	  			SerialPrintln(0);
	  			return;
	  		}*/
		if ((DC_BLOCKED==1) || (VOUT_BLOCKED==1) || (AMP_BLOCKED==1) || (IOUT_BLOCKED==1)) {
			//V_Out_RawData=ADC_Data[0]*ADC_Data[0];
			//V_Out_Cnt=1;
			CalcAc_V_ByWave();
			CalcAc_I_ByWave();
			CalcDC_Average();
			ResetV_data();
		}

		sprintf(uart_buff,

		#ifdef USE_VREF
				"V=%4u v, I=%4u W, DC=%4u, Vcc=%4u, A1=%03d,  A2=%03d,  A3=%03d,  A4=%03d, A_F=%01d, F=%01d, DC_F=%01d, V_F=%01d, I_F=%01d \r\n",
		#endif

		#ifndef USE_VREF
				"V=%4u v, I=%4u W, DC=%4u, A1=%03d,  A2=%03d,  A3=%03d,  A4=%03d, A_F=%01d, F=%01d, DC_F=%01d, V_F=%01d, I_F=%01d \r\n",
		#endif
								(uint16_t) V_Out,
								(uint16_t) I_Out,
								(uint16_t) ADC_Data[2],
								#ifdef USE_VREF
								(uint16_t) (VDDA_Actual),
								#endif
	      		  				(uint16_t) (100*Sine_Amplitude_1),
	      		  				(uint16_t) (100*Sine_Amplitude_2),
								(uint16_t) (100*Sine_Amplitude_3),
								(uint16_t) (100*Sine_Amplitude_4),
								AMP_BLOCKED,
								(uint16_t) (BoardStatus==sFaultFlag),
								DC_BLOCKED,
								VOUT_BLOCKED,
								IOUT_BLOCKED);
		SerialPrintln(0);

	#endif
}

// EEPROM
void ResetEEPROM() {
	EEPROM_DATA[0]=0;
	EEPROM_DATA[1]=0;
	EEPROM_CRC=0;
}

void CALC_RATIO() {
	/*float fVal=0;
	memcpy(&fVal, &EEPROM_DATA[1],sizeof(fVal));
	I_RATIO=(fVal*(3.3/4096));
	memcpy(&fVal, &EEPROM_DATA[0],sizeof(fVal));
	V_RATIO=(fVal*(3.3/4096));*/

	I_RATIO=(EEPROM_DATA[1]*IV_RATIO);
	V_RATIO=(EEPROM_DATA[0]*IV_RATIO);
}


void USE_DEF_CALIB() {
	//float fVal=132;
	//memcpy(&EEPROM_DATA[0], &fVal,sizeof(uint32_t));

	//fVal=3636;
	//memcpy(&EEPROM_DATA[1], &fVal,sizeof(uint32_t));
	EEPROM_DATA[0]=132;
	EEPROM_DATA[1]=3636;
	CALC_RATIO();
}

void USE_NEW_CALIB() {
	if (EEPROM_CRC==0) {
		USE_DEF_CALIB();
		return;
	}
	CALC_RATIO();
}

//void StoreEEPROM(float V_CAL, float I_CAL) {
void StoreEEPROM(uint32_t V_CAL, uint32_t I_CAL) {
	EEPROM_FLAG=1;
	//
	//memcpy(&EEPROM_DATA[0], &V_CAL,sizeof(uint32_t));
	//memcpy(&EEPROM_DATA[1], &I_CAL,sizeof(uint32_t));
	EEPROM_DATA[0]=V_CAL;
	EEPROM_DATA[1]=I_CAL;
	EEPROM_CRC=TM_CRC_Calculate32((uint32_t *) &EEPROM_DATA, sizeof(EEPROM_DATA), 1);
	EE_Write(0,EEPROM_CRC);
	EE_Write(1,EEPROM_DATA[0]);
	EE_Write(2,EEPROM_DATA[1]);
	//
	EEPROM_FLAG=0;
}

int InitEEPROM() {
	EEPROM_FLAG=1;
	//

	ResetEEPROM();
	EE_Read(0,&EEPROM_CRC);
	EE_Read(1,&EEPROM_DATA[0]);
	EE_Read(2,&EEPROM_DATA[1]);

	uint32_t EEPROM_CRC_tmp=TM_CRC_Calculate32((uint32_t *) &EEPROM_DATA, sizeof(EEPROM_DATA), 1);
	EEPROM_FLAG=0;

	if (EEPROM_CRC_tmp==EEPROM_CRC) {
		return 1;
	} else {
		ResetEEPROM();
		return 0;
	}
}

//Calibration code
void CalibSave() {
						EEPROMStoredCnt=0;
		      			USE_NEW_CALIB();
		      			StoreEEPROM(EEPROM_DATA[0],EEPROM_DATA[1]);
		      			strcpy(uart_buff,"CALIB DONE!\r\n");
		      			SerialPrintln(0);
		      		//}
}

int CalibCmdCheck() {
				button_state_t ICAL_FLAG=buttonUpdate(&CALIB_I);
				button_state_t VCAL_FLAG=buttonUpdate(&CALIB_V);

				if (EEPROMStoredCnt<EEPROMDelayBeforeNewStore) {
					EEPROMStoredCnt++;
					return 0;
				}

				if ( (VCAL_FLAG == isPressed)
	      				  && (ICAL_FLAG != isPressed)){
	      		  		//CALIB_V
						EEPROM_DATA[0]=(VOLTAGE_ETALONE/(IV_RATIO*ADC_Data[0]));
	      		  		//EEPROMStoredCnt=0;
	      		  		CalibSave();
	      		  	    return 1;
	      		  }
	      		  if ( (ICAL_FLAG == isPressed)
	      				  && (VCAL_FLAG != isPressed)){
	      		       //CALIB_I
	      			  	EEPROM_DATA[1]=(POWER_ETALONE/(IV_RATIO*ADC_Data[1]));
						//EEPROMStoredCnt=0;
						CalibSave();
						return 1;
	      		  }

	      		if ( (VCAL_FLAG == isPressed)
	      				&& (ICAL_FLAG == isPressed) ){
	      					USE_DEF_CALIB();
	      					StoreEEPROM(EEPROM_DATA[0],EEPROM_DATA[1]);
	      					//EEPROMStoredCnt=0;
	      					CalibSave();
	      					return 1;
	      		}
	      		return 0;
}


// MATH


/*float map(float value, float istart, float istop, float ostart, float ostop) {
	return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}*/

/*float remap(uint32_t value, uint16_t istart, uint16_t istop, float ostart, float ostop) {
	return (float) (ostart + (ostop - ostart) * ((value - istart) / (istop - istart)));
}*/
