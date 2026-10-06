/***********************************************************************************************
* File: HAL_CLOCK.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for CLOCK peripherals
*
* Purpose :
* HAL-level interface for CLOCK peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for CLOCK peripherals.
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
#ifndef HAL_CLOCK_H
#define HAL_CLOCK_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "BSP_CLOCK.h"

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void clock_init(void);
const clock_struct_t* clock_config_get(void);

#endif/*HAL_CLOCK_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/

