/***********************************************************************************************
* File: BSP_INTERRUPT.c
* Project: 
* Module: Board Support Package (BSP) for INTERRUPT peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for INTERRUPT peripherals
*
* Description:
* This file contains board-specific driver functions for interrupt with direct
* interaction to the underlying hardware.
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
* - BSP_INTERRUPT.h 
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
#include "BSP_INTERRUPT.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")
#define DINT        __asm(" setc INTM")
#define EINT        __asm(" clrc INTM")

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : interrupt_vector_table_init 
*
* Purpose      : 
* Initializes the interrupt vector table by configuring the default interrupt
* service routine.
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
void interrupt_vector_table_init(void)
{
    uint16_t i;
    PINT * vector = (PINT *)PIEVECTTABLE;

    /* Initialize all interrupt vectors with default ISR (start from index 3 as first entries are reserved/system interrupts)*/
    for (i = PIE_VECTOR_START_INDEX; i < sizeof(PIEVECTTABLE)/sizeof(PINT); i++)
    {
        *(vector+i) = &interrupt_default_isr;
    }

}

/******************************************************************************
* Function     : interrupt_timer2_init 
*
* Purpose      : 
* Initializes the interrupt configuration for Timer 2.
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
void interrupt_timer2_init(PINT func)
{
    EALLOW;   
    /* Disable global interrupts */
    DINT;    

    /* Enable PIE (Peripheral Interrupt Expansion) block */
    PIE_CTRL->PIECTRL |= PIECTRL_BITS_ENPIE;
    /* Assign user-defined ISR function to TIMER2 interrupt vector */
    PIEVECTTABLE->TIMER2_INT = func;
    /* Enable CPU interrupt group*/
    IER |= IER_BITS_INT14;
    
    /* Enable global interrupts */
    EINT;     
    EDIS;     
}

/*************** End of C File ************************************************/ 

