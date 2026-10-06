/*************************************************************************************************
* File    : main.c
*
* Module  : 
*
* Purpose :
* This file contains the main entry point of the system. It is responsible for initializing
* system-level components including clock, interrupts, peripherals, and the scheduler,
* and for starting the main execution loop.
*
* High-Level Requirements:  
* 
* Low-Level Requirements:  
* 
* Interfaces: 
* Public: 
* 
* Private:  
* 
* Assumptions:  
* 
* Dependencies: 
* - scheduler.h 
* 
* Safety Notes: 
* 
* Verification Notes: 
* 
* Revision History:
*  Rev      Date           Author       Description
*-------- ------------ ------------- -----------------
*  1.0     DD-MM-YYYY      Name         Initial Version
*
***********************************************************************************************/
/******************************************************************************
* Include Files
******************************************************************************/
#include "HAL_CLOCK.h"
#include "HAL_INTERRUPT.h"
#include <HAL_PWM.h>
#include <HAL_TIMER.h>
#include "HAL_INTERRUPT.h"
#include <HAL_UART.h>
#include <HAL_CAN.h>
#include <HAL_SPIB_ENCODER.h>
#include <HAL_MCAN.h>
#include <HAL_ADC.h>
#include <HAL_GPIO.h>
#include <HAL_FSI.h>
#include <HAL_SPIA_DRV8350.h>
#include <HAL_WATCHDOG.h>

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : main 
*
* Purpose      : 
* Serves as the system entry point after startup initialization. This function
* performs system-level initialization by invoking clock, interrupt, peripheral,
* and scheduler initialization routines, and then enters the main execution loop.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  None.
*
* Requirements :
*
* Notes        : 
*
******************************************************************************/
void main(void)
{
    /* Initialize system clock (PLL and oscillator configuration) */
    clock_init();

    /* Initialize interrupt controller */
    interrupt_init();

#ifndef _LAUNCHPAD_
    /* Initialize PWM modules */
    pwm_init(epwm1_ab_get());
    pwm_init(epwm2_ab_get());
    pwm_init(epwm3_ab_get());
#endif

    /* Initialize general-purpose GPIOs */
    gpio_init();

    /* Initialize UART communication interface */
    Hal_Uart_Init();

    /* Initialize ADC and configure channels */
    adc_init();

#ifndef _LAUNCHPAD_
    /* Initialize CAN and MCAN communication modules */
    can_init();
    mcan_init();
#endif

    /* Initialize SPI interface */
    encoder_spib_init();

    /* Initialize FSI with DMA support */
    fsi_dma_init();

    /* Initialize DRV8350 driver */
    drv8350_spia_init();

    /* Initialize CPU timers */
    Hal_Timer_Init();

    /* Initialize Watchdog*/
    watchdog_init();
    
    /* Main loop */
    while(1)
    {
        /* Application loop */
    }
}
/*************** End of C File ************************************************/ 


