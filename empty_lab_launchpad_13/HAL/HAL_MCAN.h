/***********************************************************************************************
* File: HAL_MCAN.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for MCAN peripherals
*
* Purpose :
* HAL-level interface for MCAN peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for MCAN peripherals.
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
#ifndef HAL_MCAN_H
#define HAL_MCAN_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "BSP_MCAN.h"

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void mcan_telemetry(void);
void mcan_retransmit(mcan_rx_buffer_element_t * rx);
void mcan_process(void);
void mcan_init(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define MCAN_MESSAGE_ID_VALUE      (0xAAU)     /* Message identifi   */
#define MCAN_DATA_PATTERN_VALUE    (0b10101)   /* Data pattern       */
#define MCAN_COUNTER_MAX           (256U)      /* Counter limit      */

#endif /*_HAL_CAN_H*/

/****************************************************************************** 
* End of File 
******************************************************************************/
