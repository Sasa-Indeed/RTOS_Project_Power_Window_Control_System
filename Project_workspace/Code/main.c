/* Kernel includes. */
#include <Window_Controls/window_control.h>
#include "FreeRTOS.h"
#include "task.h"

/* MCAL includes. */
#include "gpio.h"
#include "motors.h"

/* The HW setup function */
static void prvSetupHardware( void );

/* FreeRTOS tasks */
void vPeriodicGreenLedTask(void *pvParameters);
void vPeriodicRedLedTask(void *pvParameters);

/* Testing phase nothing to see*/
int main(void){
    uint8 swt = 0;
    /* Setup the hardware for use with the Tiva C board. */
    prvSetupHardware();

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
        read_swt(&swt, DRIVER_WINDOW_DOWN_SWITCH);
        if (swt == HIGH) {
            GPIO_BlueLedToggle();
        }
    }

}


static void prvSetupHardware( void ){
    /* Place here any needed HW initialization such as GPIO, UART, etc.  */
   // GPIO_BuiltinButtonsLedsInit();
    HAL_windowInit();
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


/*-----------------------------------------------------------*/
