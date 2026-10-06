/***********************************************************************************************
* File: HAL_INTERRUPT.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for INTERRUPT peripherals
*
* Purpose :
* HAL-level interface for INTERRUPT peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for INTERRUPT peripherals.
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
#ifndef HAL_INTERRUPT_H
#define HAL_INTERRUPT_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "BSP_INTERRUPT.h"

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void interrupt_init(void);
__interrupt void timer_isr(void);

#endif/*HAL_INTERRUPT_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
