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


//Passenger Controls
#define PASSENGER_WINDOW_PORT                            GPIOC
#define PASSENGER_WINDOW_PORT_NUMBER                     PORTC
#define PASSENGER_WINDOW_UP_SWITCH_PIN                   PIN_6
#define PASSENGER_WINDOW_DOWN_SWITCH_PIN                 PIN_7

//Other Controls
#define WINDOW_LOCK_SWITCH_PORT                          GPIOB
#define WINDOW_LOCK_SWITCH_PORT_NUMBER                   PORTB
#define WINDOW_LOCK_SWITCH_PIN                           PIN_3

#define WINDOW_JAM_SWITCH_PORT                           GPIOB
#define WINDOW_JAM_SWITCH_PORT_NUMBER                    PORTB
#define WINDOW_JAM_SWITCH_PIN                            PIN_0

//Limit Switches
#define WINDOW_LIMIT_SWITCH_PORT                         GPIOA
#define WINDOW_LIMIT_SWITCH_PORT_NUMBER                  PORTA
#define WINDOW_LIMIT_UP_SWITCH_PIN                       PIN_2
#define WINDOW_LIMIT_DOWN_SWITCH_PIN                     PIN_3


//@ref  Buttons numbers
#define DRIVER_WINDOW_UP_SWITCH                     1
#define DRIVER_WINDOW_DOWN_SWITCH                   2
#define PASSENGER_WINDOW_UP_SWITCH                  3
#define PASSENGER_WINDOW_DOWN_SWITCH                4
#define WINDOW_LOCK_SWITCH                          5


#define GPIO_PORTC_INTERRUPT_ENBALE                 NVIC_EN0_REG         |= 0x00000004
#define GPIO_PORTC_INTERRUPT_DISABLE                NVIC_EN0_REG         &= ~0x00000004


/* First parameter is output of the pin
 * Second parameter which button to read must be from @ref Buttons numbers
 * !!!WARNING DO NOT USE THIS FUNCTION WITH THE LOCK WINDOW THE CODE WILL BE STUCK AT A INIFINTE LOOP!!! */
void read_swt(uint8 * swt, uint8 button_number);


uint8 read_SWT(vuint32_ptr PORTx, uint8 PINx);


void HAL_Limit_Switches_Init(void);
void HAL_Window_Switches_Init(void);
void HAL_Jam_Lock_Switches_Init(void);

#endif /* HAL_WINDOW_CONTROLS_WINDOW_CONTROL_H_ */
