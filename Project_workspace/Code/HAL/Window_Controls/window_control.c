/*
 * window_switch.c
 *
 *  Created on: 3 May 2024
 *      Author: Ahmed
 */

#include <Window_Controls/window_control.h>

#define NULL 0

void HAL_windowInit(void){
    pin_config_t config;

    MCAL_GPIO_Init(DRIVER_WINDOW_PORT_NUMBER);
    MCAL_GPIO_Init(PASSENGER_WINDOW_PORT_NUMBER);
    MCAL_GPIO_Init(WINDOW_LOCK_SWITCH_PORT_NUMBER);

    /* For driver window up switch */
    config.pinNumber   = DRIVER_WINDOW_UP_SWITCH_PIN;
    config.direction   = MCAL_GPIO_DIRECTION_INPUT;
    config.outputMode  = MCAL_GPIO_OUTPUT_MODE_PULL_UP;
    config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
    config.alterFunc   = MCAL_GPIO_ALTERFUNC_NONE;
    MCAL_GPIO_Pin_Init(DRIVER_WINDOW_PORT, &config);

    /* For driver window down switch */
    config.pinNumber = DRIVER_WINDOW_DOWN_SWITCH_PIN;
    MCAL_GPIO_Pin_Init(DRIVER_WINDOW_PORT, &config);

    /* For passenger window up switch */
    config.pinNumber   = PASSENGER_WINDOW_UP_SWITCH_PIN;
    config.direction   = MCAL_GPIO_DIRECTION_INPUT;
    config.outputMode  = MCAL_GPIO_OUTPUT_MODE_PULL_UP;
    config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
    config.alterFunc   = MCAL_GPIO_ALTERFUNC_NONE;
    MCAL_GPIO_Pin_Init(PASSENGER_WINDOW_PORT, &config);

    /* For passenger window down switch */
    config.pinNumber = PASSENGER_WINDOW_DOWN_SWITCH_PIN;
    MCAL_GPIO_Pin_Init(PASSENGER_WINDOW_PORT, &config);

    /* For lock switch */
    config.pinNumber   = WINDOW_LOCK_SWITCH_PIN;
    MCAL_GPIO_Pin_Init(WINDOW_LOCK_SWITCH_PORT, &config);
}

uint8 GPIO_LockSWGetState(void){
    uint8 state = 0;
    MCAL_GPIO_ReadPin(WINDOW_LOCK_SWITCH_PORT, WINDOW_LOCK_SWITCH_PIN, &state);
    return state;
}

void read_swt(uint8 * swt, uint8 button_number){
  *swt = 0;
  uint8 state = 0;

  struct switches{
      vuint32_ptr PORTx;
      uint8 PINx;
  }switches1;


  switch(button_number){
  case DRIVER_WINDOW_UP_SWITCH :
      switches1.PORTx = DRIVER_WINDOW_PORT;
      switches1.PINx = DRIVER_WINDOW_UP_SWITCH_PIN;
      break;

  case DRIVER_WINDOW_DOWN_SWITCH :
      switches1.PORTx = DRIVER_WINDOW_PORT;
      switches1.PINx = DRIVER_WINDOW_DOWN_SWITCH_PIN;
      break;

  case PASSENGER_WINDOW_UP_SWITCH :
      switches1.PORTx = PASSENGER_WINDOW_PORT;
      switches1.PINx = PASSENGER_WINDOW_UP_SWITCH_PIN;
      break;

  default :
      switches1.PORTx = PASSENGER_WINDOW_PORT;
      switches1.PINx = PASSENGER_WINDOW_DOWN_SWITCH_PIN;
  }


  do{
    MCAL_GPIO_ReadPin(switches1.PORTx, switches1.PINx, &state);
    *swt |= !state;
  }while(!state);

}

