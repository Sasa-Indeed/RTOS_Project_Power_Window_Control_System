/*
 * motors.h
 *
 *  Created on: 3 May 2024
 *      Author: Ahmed
 */

#ifndef HAL_MOTORS_MOTORS_H_
#define HAL_MOTORS_MOTORS_H_

#include "gpio.h"


//MotorA
#define MOTORA_PORT                               GPIOE
#define MOTORA_PORT_NUMBER                        PORTE
#define MOTORA_PIN_CLK_WISE_PIN                       PIN_4     // CLK_WISE  stands for clockwise
#define MOTORA_PIN_CCLK_WISE_PIN                      PIN_5     // CCLK_WISE stands for counterclockwise

//MotorB
#define MOTORB_PORT                               GPIOB
#define MOTORB_PORT_NUMBER                        PORTB
#define MOTORB_PIN_CLK_WISE_PIN                       PIN_0     // CLK_WISE  stands for clockwise
#define MOTORB_PIN_CCLK_WISE_PIN                      PIN_1     // CCLK_WISE stands for counterclockwise

void HAL_MotorsInit(void);

void HAL_TurnOnMotorACLK_WISE(void);
void HAL_TurnOnMotorACCLK_WISE(void);
void HAL_TurnOffMotorA(void);
void HAL_TurnOnMotorBCLK_WISE(void);
void HAL_TurnOnMotorBCCLK_WISE(void);
void HAL_TurnOffMotorB(void);


#endif /* HAL_MOTORS_MOTORS_H_ */