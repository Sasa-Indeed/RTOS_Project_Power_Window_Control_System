/*
 * motors.c
 *
 *  Created on: 3 May 2024
 *      Author: Ahmed
 */
#include "motors.h"

void HAL_MotorsInit(void){

    MCAL_GPIO_Init(MOTORA_PORT_NUMBER);
    MCAL_GPIO_Init(MOTORB_PORT_NUMBER);

    pin_config_t config;


    config.pinNumber = MOTORA_PIN_CLK_WISE_PIN;
    config.direction = MCAL_GPIO_DIRECTION_OUTPUT;
    config.outputMode = MCAL_GPIO_OUTPUT_MODE_NONE;
    config.outputSpeed = MCAL_GPIO_OUTPUT_SPEED_NONE;
    config.alterFunc = MCAL_GPIO_ALTERFUNC_NONE;
    MCAL_GPIO_Pin_Init(MOTORA_PORT, &config);

    config.pinNumber = MOTORA_PIN_CCLK_WISE_PIN;
    MCAL_GPIO_Pin_Init(MOTORA_PORT, &config);

    config.pinNumber = MOTORB_PIN_CLK_WISE_PIN;
    MCAL_GPIO_Pin_Init(MOTORB_PORT, &config);

    config.pinNumber = MOTORB_PIN_CCLK_WISE_PIN;
    MCAL_GPIO_Pin_Init(MOTORB_PORT, &config);
}


void HAL_TurnOnMotorACLK_WISE(void){
    MCAL_GPIO_WritePin(MOTORA_PORT, MOTORA_PIN_CCLK_WISE_PIN, LOW);
    MCAL_GPIO_WritePin(MOTORA_PORT, MOTORA_PIN_CLK_WISE_PIN, HIGH);
}

void HAL_TurnOnMotorACCLK_WISE(void){
    MCAL_GPIO_WritePin(MOTORA_PORT, MOTORA_PIN_CLK_WISE_PIN, LOW);
    MCAL_GPIO_WritePin(MOTORA_PORT, MOTORA_PIN_CCLK_WISE_PIN, HIGH);
}

void HAL_TurnOffMotorA(void){
    MCAL_GPIO_WritePin(MOTORA_PORT, MOTORA_PIN_CLK_WISE_PIN, LOW);
    MCAL_GPIO_WritePin(MOTORA_PORT, MOTORA_PIN_CCLK_WISE_PIN, LOW);
}

void HAL_TurnOnMotorBCLK_WISE(void){
    MCAL_GPIO_WritePin(MOTORB_PORT, MOTORB_PIN_CCLK_WISE_PIN, LOW);
    MCAL_GPIO_WritePin(MOTORB_PORT, MOTORB_PIN_CLK_WISE_PIN, HIGH);
}

void HAL_TurnOnMotorBCCLK_WISE(void){
    MCAL_GPIO_WritePin(MOTORB_PORT, MOTORB_PIN_CLK_WISE_PIN, LOW);
    MCAL_GPIO_WritePin(MOTORB_PORT, MOTORB_PIN_CCLK_WISE_PIN, HIGH);
}


void HAL_TurnOffMotorB(void){
    MCAL_GPIO_WritePin(MOTORB_PORT, MOTORB_PIN_CLK_WISE_PIN, LOW);
    MCAL_GPIO_WritePin(MOTORB_PORT, MOTORB_PIN_CCLK_WISE_PIN, LOW);
}

