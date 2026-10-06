/***********************************************************************************************
* File: HAL_WATCHDOG.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for WATCHDOG peripherals
*
* Purpose :
* HAL-level interface for CPU WATCHDOG peripherals.
*
* Description:
* This file provides a standardized API for interacting with WATCHDOG, abstracting the specific
* register-level operations of the underlying MCU. 
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
* - HAL_WATCHDOG.h 
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
#include "HAL_WATCHDOG.h"

/******************************************************************************
* Function Definitions
******************************************************************************/

/******************************************************************************
* Function     : watchdog_init 
*
* Purpose      : 
* Initializes and enables the watchdog timer with the configured reset timeout.
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
* Returns      :
*  None.
*
* Requirements : 
*
* Note         :
*
******************************************************************************/
void watchdog_init(void)
{
    watchdog_enable(WATCHDOG_RESET_TIME);
}

/******************************************************************************
* Function     : watchdog_reset 
*
* Purpose      : 
* Services the watchdog timer.
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
* Returns      :
*  None.
*
* Requirements : 
*
* Note         :
*
******************************************************************************/
void watchdog_reset(void)
{
    watchdog_service();
}
/*************** End of C File ************************************************/

