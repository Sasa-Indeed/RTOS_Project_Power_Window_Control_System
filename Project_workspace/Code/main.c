/* Kernel includes. */
#include <Window_Controls/window_control.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/* MCAL includes. */
#include "gpio.h"
#include "motors.h"
#include "window_control.h"

/* Flag queues */
QueueHandle_t qLimitUpFlag, qLimitDownFlag, qJamFlag, qLockFlag, qDriverFlag;

/* Semaphores */

/* Passenger semaphore */
xSemaphoreHandle sPassengerUp, sPassengerDown;

/* Driver semaphore */
xSemaphoreHandle sDriverUp, sDriverDown;

/* Jam task semaphore */
xSemaphoreHandle sJam;

/* The HW setup function */
static void prvSetupHardware( void );

/* FreeRTOS tasks */
void vPassengerWindowUpTask(void *pvParameters);
void vPassengerWindowDownTask(void *pvParameters);
void vDriverWindowUpTask(void *pvParameters);
void vDriverWindowDownTask(void *pvParameters);
void vJamClearingTask(void *pvParameters);


/* Testing phase nothing to see*/
int main(void){
    /* Setup the hardware for use with the Tiva C board. */
    IntMasterEnable();
    GPIO_BuiltinButtonsLedsInit();
    HAL_Limit_Switches_Init();
    //HAL_Window_Switches_Init();
    HAL_Jam_Lock_Switches_Init();
     //
    /* Create Tasks here */
    //xTaskCreate(vPeriodicGreenLedTask, "Task 1", 256, NULL, 1, NULL);

    /* Now all the tasks have been started - start the scheduler.

    NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
    The processor MUST be in supervisor mode when vTaskStartScheduler is
    called.  The demo applications included in the FreeRTOS.org download switch
    to supervisor mode prior to main being called.  If you are not using one of
    these demo application projects then ensure Supervisor mode is used here. */
    //vTaskStartScheduler();

    /* Should never reach here!  If you do then there was not enough heap
    available for the idle task to be created. */
    while(1){
    }

}


static void prvSetupHardware( void ){
    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
   // GPIO_BuiltinButtonsLedsInit();
    GPIO_BuiltinButtonsLedsInit();
}

void vPeriodicGreenLedTask(void *pvParameters)
{
    for (;;){
        HAL_TurnOnMotorACLK_WISE();
        vTaskDelay(pdMS_TO_TICKS(1000));
        HAL_TurnOnMotorACCLK_WISE();
        vTaskDelay(pdMS_TO_TICKS(1000));
        HAL_TurnOffMotorA();
        vTaskDelay(pdMS_TO_TICKS(1000));
        HAL_TurnOnMotorBCLK_WISE();
        vTaskDelay(pdMS_TO_TICKS(1000));
        HAL_TurnOnMotorBCCLK_WISE();
        vTaskDelay(pdMS_TO_TICKS(1000));
        HAL_TurnOffMotorB();
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void GPIOA_Handler(void){
    if(GPIO_PORTA_MIS_REG & 0x4){
        GPIO_BlueLedToggle();
        GPIO_PORTA_ICR_REG   |= (1<<2);
    }else if (GPIO_PORTA_MIS_REG & 0x8){
        GPIO_RedLedToggle();
        GPIO_PORTA_ICR_REG   |= (1<<3);
    }

}

void GPIOB_Handler(void){
    if(GPIO_PORTB_MIS_REG & 0x1){
        GPIO_BlueLedToggle();
        GPIO_PORTB_ICR_REG   |= (1<<0);
    }else if (GPIO_PORTB_MIS_REG & 0x2){
        GPIO_RedLedToggle();
        GPIO_PORTB_ICR_REG   |= (1<<1);
    }

}

void GPIOC_Handler(void){
    if(GPIO_PORTC_MIS_REG & 0x10){ // Pin4
        GPIO_BlueLedToggle();
        GPIO_PORTC_ICR_REG   |= (1<<4);
    }else if (GPIO_PORTC_MIS_REG & 0x20){ // Pin5
        GPIO_RedLedToggle();
        GPIO_PORTC_ICR_REG   |= (1<<5);
    }else if (GPIO_PORTC_MIS_REG & 0x40){ // Pin6
        GPIO_GreenLedToggle();
        GPIO_PORTC_ICR_REG   |= (1<<6);
    }else if (GPIO_PORTC_MIS_REG & 0x80){ // Pin7
        GPIO_RedLedToggle();
        GPIO_PORTC_ICR_REG   |= (1<<7);
    }

}
/*-----------------------------------------------------------*/
