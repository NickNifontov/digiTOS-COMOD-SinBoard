// Independent watchdog timer for STM32Fxxx MCUs
#ifndef DigiTOS_IWDG_H
#define DigiTOS_IWDG_H 100

#include "stm32f0xx.h"

/**
 * @brief Watchdog timeout settings
 */
typedef enum {
	DigiTOS_IWDG_Timeout_5ms = 0x00,   /*!< System reset called every 5ms */
	DigiTOS_IWDG_Timeout_10ms = 0x01,  /*!< System reset called every 10ms */
	DigiTOS_IWDG_Timeout_15ms = 0x02,  /*!< System reset called every 15ms */
	DigiTOS_IWDG_Timeout_30ms = 0x03,  /*!< System reset called every 30ms */
	DigiTOS_IWDG_Timeout_60ms = 0x04,  /*!< System reset called every 60ms */
	DigiTOS_IWDG_Timeout_120ms = 0x05, /*!< System reset called every 120ms */
	DigiTOS_IWDG_Timeout_250ms = 0x06, /*!< System reset called every 250ms */
	DigiTOS_IWDG_Timeout_500ms = 0x07, /*!< System reset called every 500ms */
	DigiTOS_IWDG_Timeout_1s = 0x08,    /*!< System reset called every 1s */
	DigiTOS_IWDG_Timeout_2s = 0x09,    /*!< System reset called every 2s */
	DigiTOS_IWDG_Timeout_4s = 0x0A,    /*!< System reset called every 4s */
	DigiTOS_IWDG_Timeout_8s = 0x0B,    /*!< System reset called every 8s */
	DigiTOS_IWDG_Timeout_16s = 0x0C,   /*!< System reset called every 16s */
	DigiTOS_IWDG_Timeout_32s = 0x0D    /*!< System reset called every 32s. This is maximum value allowed with IWDG timer */
} DigiTOS_IWDG_Timeout_t;


/*
Initialize Watchdog timer. After you initialize it, you can't disable it unless reset occur.
Timeout value when watchdog reset happen if not reset by user. This parameter can be a value of @ref TM_IWDG_Timeout_t enumeration
 */

uint8_t DigiTOS_IWDG_Init(DigiTOS_IWDG_Timeout_t timeout);


#endif

