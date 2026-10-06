/***********************************************************************************************
* File: HAL_TIMER.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for CPUTIMER peripherals
*
* Purpose :
* HAL-level interface for CPUTIMER peripherals.
*
* Description:
* This file provides a standardized API for interacting with CPUTIMER, abstracting the specific
* register-level operations of the underlying MCU. 
*
* 
* High-Level Requirements:  
* 
* Low-Level Requirements:  
* 
* Interfaces: 
* Public: 
* Hal_Timer_ClearInterruptFlag()
* Hal_Timer_ConfigGet()
* Hal_Timer_Init()
*
* Private:
* None  
* 
* Assumptions:  
* 
* Dependencies: 
* - HAL_TIMER.h 
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
#include "HAL_TIMER.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
static Timer_Config_t timer2_config = {
    .timerBase = TIMER_2,
    .frequency = TIMER_FREQUENCY,
};

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : Hal_Timer_ClearInterruptFlag 
*
* Purpose      : 
* Clears the interrupt flag for a CPU timer.
*
* Inputs       :
* timerBase –  pointer to a 'Timer_Regs_t' structure that contains the 
*              register base address of the CPU TIMER peripheral.
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
void Hal_Timer_ClearInterruptFlag(Timer_Regs_t *timerBase)
{
    Bsp_Timer_InterruptFlagClear(timerBase);
}

/******************************************************************************
* Function     : Hal_Timer_ConfigGet 
*
* Purpose      : 
* Provides read-only access to the timer 2 configuration structure.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to timer 2 configuration structure (const Timer_Config_t*).
*
* Requirements : 
*
* Notes        : 
*
******************************************************************************/
const Timer_Config_t* Hal_Timer_ConfigGet(void)
{
    return &timer2_config;
}

/******************************************************************************
* Function     : Hal_Timer_Init 
*
* Purpose      : 
* Initializes the timer used by the application scheduler to generate periodic
* timing interrupts required for task scheduling.
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
void Hal_Timer_Init(void)
{
    /* Configure Timer2 */
    Bsp_Timer_Config(&timer2_config);
    /* Enable Timer2 interrupt */
    Bsp_Timer_InterruptEnable(timer2_config.timerBase);
    /* Start Timer2 counting */
    Bsp_Timer_Start(timer2_config.timerBase);
}
/*************** End of C File ************************************************/ 

