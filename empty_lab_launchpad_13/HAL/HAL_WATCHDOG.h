/***********************************************************************************************
* File: BSP_WATCHDOG.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for WATCHDOG peripherals
*
* Purpose :
* HAL-level interface for WATCHDOG peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for WATCHDOG peripherals.
* 
* High-Level Requirements:  
* 
* Low-Level Requirements:   
* 
* Safety Notes: 
* 
* Revision History:
*  Rev      Date           Author       Description
*-------- ------------ ------------- -----------------
*  1.0     DD-MM-YYYY      Name         Initial Version
*
***********************************************************************************************/
#ifndef HAL_WATCHDOG_H
#define HAL_WATCHDOG_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "BSP_WATCHDOG.h"

/****************************************************************************** 
* Include Files 
******************************************************************************/
void watchdog_init(void);
void watchdog_reset(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define WATCHDOG_RESET_TIME (6000U)

#endif /* HAL_WATCHDOG_H */
/****************************************************************************** 
* End of File 
******************************************************************************/
