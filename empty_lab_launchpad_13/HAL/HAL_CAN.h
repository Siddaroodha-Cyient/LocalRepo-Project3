/***********************************************************************************************
* File: HAL_CAN.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for CAN peripherals
*
* Purpose :
* HAL-level interface for CAN peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for CAN peripherals.
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
#ifndef HAL_CAN_H
#define HAL_CAN_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "BSP_CAN.h"

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void can_telemetry(void);
void can_process(void);
void can_init(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define CAN_MESSAGE_ID_VALUE        (0xAAU)   /* CAN message ID */
#define CAN_COUNTER_MAX             (256U)    /* Counter max (8-bit rollover) */

#endif /*HAL_CAN_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
