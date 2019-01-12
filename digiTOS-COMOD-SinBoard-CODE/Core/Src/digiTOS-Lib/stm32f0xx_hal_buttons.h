 /*
 ===============================================================================
 Button driver: header file
 ===============================================================================
 * @date    27-Feb-2016
 * @author  Domen Jurkovic
  
 */
#ifndef __BUTTONS_H
#define __BUTTONS_H

#include "stm32f1xx_hal.h"


/* If BUTTON_CubeMX defined, button library uses CubeMX assigned GPIO pins. 
In this case, parameters passed to buttonInit() should match the defines in mxconstant.h */
#define	BUTTON_CubeMX

//#ifdef BUTTON_CubeMX
	//#include "mxconstants.h"
   // #include "main.h"
//#endif

typedef enum{
	noEvent,
	stateChanged,
	isPressed,
	isPressedLong,
	isReleased
} button_state_t;

typedef enum{
	button_on,
	button_off
} _phy_state_t;

typedef struct{
	//gpio
	uint32_t GPIO_Pin;
	GPIO_TypeDef* GPIO_Port;
	GPIO_PinState active_state;	// depends on pull up/down resistor: GPIO_PIN_RESET or GPIO_PIN_SET
	
	button_state_t _state;		// could be set to noEvent on case we are waiting for key to be released.
	uint32_t debounce_time;
	uint32_t long_press_time;
	uint8_t short_press_handled;
	uint8_t long_press_handled;
	
	uint8_t _state_changed;
	_phy_state_t _previous_state;
	uint32_t _on_press_time;
} button_struct_t;

void buttonInit(button_struct_t *button_struct, GPIO_TypeDef* GPIO_Port, uint32_t GPIO_Pin, GPIO_PinState active_state, uint32_t debounce_time, uint32_t long_press_time);
button_state_t buttonUpdate(button_struct_t *button_struct);

uint8_t buttonSinglePress(button_struct_t *button_struct);
uint8_t buttonSingleLongPress(button_struct_t *button_struct);

/**********************************************************/
/*	PRIVATE FUNCTIONS */
/**********************************************************/
_phy_state_t _button_state(button_struct_t *button_struct);



#endif /* __BUTTONS_H */
