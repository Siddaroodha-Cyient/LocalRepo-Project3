/***********************************************************************************************
* File: HAL_CLOCK.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for CLOCK peripheral.
*
* Purpose :
* HAL-level interface for CLOCK peripheral.
*
* Description:
* This file provides a standardized API for interacting with CLOCK, abstracting the
* specific register-level operations of the underlying MCU. 
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
#include "HAL_CLOCK.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
static clock_struct_t clock_struct = {
#ifndef _LAUNCHPAD_
    .oscclk_frequency       = 12000000,
#else
    .oscclk_frequency       = 20000000,
#endif      
    .pllrawclk_frequency    = 240000000,
    .pllsysclk_frequency    = 120000000,
    .lspclk_frequency       = 120000000,
};

/******************************************************************************
* Function     : clock_config_get 
*
* Purpose      : 
* Provides read-only access to system clock configuration structue.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to clock configuration structure (const clock_struct_t*).
*
* Requirements : 
*
* Notes        : 
*
******************************************************************************/

const clock_struct_t* clock_config_get(void)
{
    return &clock_struct;
}


/******************************************************************************
* Function     : clock_init 
*
* Purpose      : 
* Initializes the system clock by configuring the Phase-Locked Loop (PLL) and
* enabling clocks for required peripheral
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
void clock_init(void)
{
    clock_pll_config( (clock_struct_t *)&clock_struct);
    clock_peripheral_enable();
}
/*************** End of C File ************************************************/
