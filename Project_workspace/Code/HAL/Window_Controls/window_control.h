/*
 * window_switch.h
 *
 *  Created on: 3 May 2024
 *      Author: Ahmed
 */

#ifndef HAL_WINDOW_CONTROLS_WINDOW_CONTROL_H_
#define HAL_WINDOW_CONTROLS_WINDOW_CONTROL_H_

#include "gpio.h"

//Driver Controls
#define DRIVER_WINDOW_PORT                               GPIOC
#define DRIVER_WINDOW_PORT_NUMBER                        PORTC
#define DRIVER_WINDOW_UP_SWITCH_PIN                      PIN_4
#define DRIVER_WINDOW_DOWN_SWITCH_PIN                    PIN_5
#define WINDOW_LOCK_SWITCH_PORT                          GPIOB
#define WINDOW_LOCK_SWITCH_PORT_NUMBER                   PORTB
#define WINDOW_LOCK_SWITCH_PIN                           PIN_3


//Passenger Controls
#define PASSENGER_WINDOW_PORT                            GPIOC
#define PASSENGER_WINDOW_PORT_NUMBER                     PORTC
#define PASSENGER_WINDOW_UP_SWITCH_PIN                   PIN_6
#define PASSENGER_WINDOW_DOWN_SWITCH_PIN                 PIN_7



//@ref  Buttons numbers
#define DRIVER_WINDOW_UP_SWITCH                     1
#define DRIVER_WINDOW_DOWN_SWITCH                   2
#define PASSENGER_WINDOW_UP_SWITCH                  3
#define PASSENGER_WINDOW_DOWN_SWITCH                4
#define WINDOW_LOCK_SWITCH                          5


void HAL_windowInit(void);

uint8 GPIO_LockSWGetState(void);

/* First parameter is output of the pin
 * Second parameter which button to read must be from @ref Buttons numbers */
void read_swt(uint8 * swt, uint8 button_number);


#endif /* HAL_WINDOW_CONTROLS_WINDOW_CONTROL_H_ */
