/***********************************************************************************************
* File: BSP_TIMER.c
* Project: 
* Module: Board Support Package (BSP) for CPUTIMER peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for CPUTIMER peripherals
*
* Description:
* This file contains board-specific driver functions for CPUTIMER with direct
* interaction to the underlying hardware.
*
* High-Level Requirements:  
* 
* Low-Level Requirements:  
* 
* Interfaces: 
* Public: 
* Bsp_Timer_Stop()
* Bsp_Timer_Start()
* Bsp_Timer_InterruptEnable()
* Bsp_Timer_InterruptDisable()
* Bsp_Timer_InterruptFlagClear()
* Bsp_Timer_Config()
*
* Private:  
* 
* Assumptions:  
* 
* Dependencies: 
* - BSP_TIMER.h 
* - HAL_CLOCK.h
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
#include "BSP_TIMER.h"
#include "HAL_CLOCK.h"
#include "BSP_COMMON.h"

/******************************************************************************
* Function Definitions
******************************************************************************/

/******************************************************************************
* Function     : Bsp_Timer_Stop 
*
* Purpose      : 
* Stops the counter for a CPU timer.
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
void Bsp_Timer_Stop(Timer_Regs_t * timerBase)
{
    timerBase->TCR |= TIMER_TCR_BITS_TSS;
}

/******************************************************************************
* Function     : Bsp_Timer_Start 
*
* Purpose      : 
* Starts the counter for a CPU timer.
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
* Requirements:
*
* Notes        : 
*
******************************************************************************/ 
void Bsp_Timer_Start(Timer_Regs_t * timerBase)
{
    timerBase->TCR &= ~TIMER_TCR_BITS_TSS;
}

/******************************************************************************
* Function     : Bsp_Timer_InterruptEnable 
*
* Purpose      : 
* Enables the interrupt for a CPU timer.
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
* Requirements:
*
* Notes        : 
*
******************************************************************************/ 
void Bsp_Timer_InterruptEnable(Timer_Regs_t * timerBase)
{
    timerBase->TCR |= TIMER_TCR_BITS_TIE;
}

/******************************************************************************
* Function     : Bsp_Timer_InterruptDisable 
*
* Purpose      : 
* Disables the interrupt for a CPU timer.
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
* Requirements:
*
* Notes        : 
*
******************************************************************************/ 
void Bsp_Timer_InterruptDisable(Timer_Regs_t * timerBase)
{
    timerBase->TCR &= ~TIMER_TCR_BITS_TIE;
}


/******************************************************************************
* Function     : Bsp_Timer_InterruptFlagClear 
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
* Requirements:
*
* Notes        : 
*
******************************************************************************/  
void Bsp_Timer_InterruptFlagClear(Timer_Regs_t * timerBase)
{
    timerBase->TCR |= TIMER_TCR_BITS_TIF;
}

/******************************************************************************
* Function     : Bsp_Timer_Config 
*
* Purpose      : 
* Configures the peripheral register for the required timer frequency.
*
* Inputs       :
*  config  –   Pointer to a 'Timer_Config_t' structure that contains the 
*              information of CPU timer base address and the required frequency
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
void Bsp_Timer_Config(Timer_Config_t * config)
{
    const clock_struct_t *clk = clock_config_get();
    Timer_Regs_t * timerBase = config->timerBase;
    /* Calculate timer period based on system clock and desired frequency */
    uint32_t prd = (clk->pllsysclk_frequency/config->frequency) - 1;

    /* Stop timer before reconfiguration */
    Bsp_Timer_Stop(timerBase);

    timerBase->PRD = prd;
    timerBase->TPRH &= ~TIMER_TPRH_BITS_TDDRH_Msk;
    timerBase->TPR  &= ~TIMER_TPR_BITS_TDDR_Msk;

    /* Reload timer with new period*/
    timerBase->TCR |= TIMER_TCR_BITS_TRB;
}

/*************** End of C File ************************************************/ 

