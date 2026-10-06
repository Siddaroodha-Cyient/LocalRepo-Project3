/***********************************************************************************************
* File: Scheduler.c
* Project: 
* Module: Application – Scheduler.
*
* Purpose :
* Implements application-level task scheduling and execution control.
*
* Description:
* This file implements the application-level scheduler responsible for coordinating and
* executing periodic and event-driven application tasks based on scheduler timing.
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
#include "scheduler.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
uint32_t scheduler_counter = 0;
uint16_t temperature=0;

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : timer_isr 
*
* Purpose      : 
* Handles the timer interrupt event by clearing the timer interrupt flag 
* and triggers scheduler processing based on the configured timer frequency.
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
* Requirements:
*
* Notes        : 
*
******************************************************************************/
__interrupt void timer_isr(void)
{
    const Timer_Config_t *timer = Hal_Timer_ConfigGet();

    Hal_Timer_ClearInterruptFlag(timer->timerBase);
    scheduler_process(timer->frequency);
}

/******************************************************************************
* Function     : scheduler_process
*
* Purpose      : 
* Executes scheduler tasks on each timer tick and triggers periodic
* application functions based on the configured frequency.
*
* Inputs       :
* frequency  - Base scheduler frequency used for periodic task execution
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
void scheduler_process(uint32_t frequency)
{
    /* Increment scheduler tick counter */
    scheduler_counter++;
    
    /* service the watchdog */
    watchdog_reset();

    /* Update input GPIO states */
    read_gpio_inp();

    /* Process UART communication */
    Hal_Uart_Process();

    /* Update ADC channel data */
    adc_update_channel_data();

    /* Process SPI communication */
    encoder_spib_process();

#ifndef _LAUNCHPAD_
    /* Process CAN and MCAN communication */
    can_process();
    mcan_process();
#endif

    /* Execute 1 Hz task */
    if (scheduler_counter % frequency == 0)
    {
        scheduler_1Hz();
    }

    /* Execute 10 Hz task */
    if (scheduler_counter % (frequency / 10) == 0)
    {
        scheduler_10Hz();
    }
}

/******************************************************************************
* Function     : scheduler_1Hz 
*
* Purpose      : 
* Executes application tasks that are scheduled to run at a 1 Hz rate.
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
* Requirements:
*
* Notes        :
*
******************************************************************************/
void scheduler_1Hz(void)
{
    //update_gpio_out();
    Hal_Uart_Initiate();
    fsi_dma_send();
}

/******************************************************************************
* Function     : scheduler_10Hz 
*
* Purpose      : 
* Executes application tasks that are scheduled to run at a 10 Hz rate.
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
* Requirements:
*
* Notes        :
*
******************************************************************************/
void scheduler_10Hz(void)
{
    mcan_telemetry();
    can_telemetry();
}
/*************** End of C File ************************************************/ 
