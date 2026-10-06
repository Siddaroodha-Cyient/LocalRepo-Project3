/***********************************************************************************************
* File: HAL_TIMER.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for CPUTIMER peripherals
*
* Purpose :
* HAL-level interface for CPUTIMER peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for CPUTIMER peripherals.
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
#ifndef HAL_TIMER_H
#define HAL_TIMER_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "BSP_TIMER.h"

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void Hal_Timer_Init(void);
void Hal_Timer_ClearInterruptFlag(Timer_Regs_t *timerBase);
const Timer_Config_t* Hal_Timer_ConfigGet(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define TIMER_FREQUENCY           (500U)

#endif/*HAL_TIMER_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
