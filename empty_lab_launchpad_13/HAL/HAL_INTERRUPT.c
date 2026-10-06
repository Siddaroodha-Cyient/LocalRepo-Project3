/***********************************************************************************************
* File: HAL_INTERRUPRT.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for INTERRUPRT peripherals
*
* Purpose :
* HAL-level interface for INTERRUPRT peripherals.
*
* Description:
* This file provides a standardized API for configuring and handling interrupt functionality, 
* abstracting the specific register-level operations of the underlying MCU.
*
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
* - HAL_INTERRUPT.h 
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
#include "HAL_INTERRUPT.h"

/******************************************************************************
* Function Definitions
******************************************************************************/

/******************************************************************************
* Function     : interrupt_default_isr 
*
* Purpose      : 
* Serves as the default interrupt service routine for unhandled or unexpected
* interrupts.
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
__interrupt void interrupt_default_isr(void)
{
    
    /* Debug trap: halt CPU when unexpected interrupt occurs */
    __asm(" ESTOP0");

    /* Infinite loop to prevent further execution */
    while (1)
    {

    }
}

/******************************************************************************
* Function     : interrupt_init 
*
* Purpose      : 
* Initializes the interrupt subsystem by setting up the interrupt vector table.
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
void interrupt_init(void)
{
    /* Initialize interrupt vector table */
    interrupt_vector_table_init();
    /* Initialize Timer2 interrupt configuration */
    interrupt_timer2_init(&timer_isr);
}
/*************** End of C File ************************************************/
