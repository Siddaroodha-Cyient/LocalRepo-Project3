/***********************************************************************************************
* File: Scheduler.h
* Project: 
* Module: Application – Scheduler.
*
* Purpose :
* Implements application-level task scheduling and execution control.
*
* Description:
* This header defines data types, macros, and function prototypes used by the application-level
* scheduler for managing periodic task execution.
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
#ifndef scheduler_H
#define scheduler_H 

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "HAL_CLOCK.h"
#include "HAL_INTERRUPT.h"
#include <HAL_PWM.h>
#include <HAL_TIMER.h>
#include "HAL_INTERRUPT.h"
#include <HAL_UART.h>
#include <HAL_CAN.h>
#include <HAL_SPIB_ENCODER.h>
#include <HAL_MCAN.h>
#include <HAL_ADC.h>
#include <HAL_GPIO.h>
#include <HAL_FSI.h>
#include <HAL_WATCHDOG.h>
#include <stdint.h>

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void scheduler_1Hz(void);
void scheduler_10Hz(void);
void scheduler_isr(uint32_t frequency);
void scheduler_process(uint32_t frequency);

#endif /* scheduler_H */
/****************************************************************************** 
* End of File 
******************************************************************************/
