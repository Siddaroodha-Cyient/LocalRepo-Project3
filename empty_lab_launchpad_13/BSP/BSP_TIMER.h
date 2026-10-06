/***********************************************************************************************
* File    : BSP_TIMER.h
*
* Module  : Board Support Package (BSP) for CPUTIMER peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for CPUTIMER peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for CPUTIMER peripherals.
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
#ifndef BSP_TIMER_H
#define BSP_TIMER_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/

/* Structure used to access CPUTIMER peripheral registers */ 
typedef struct{
    uint32_t TIM;           /* CPU-Timer, Counter Register,         Address offset: 0x00 - 0x01 */
    uint32_t PRD;           /* CPU-Timer, Period Register,          Address offset: 0x02 - 0x03 */
    uint16_t TCR;           /* CPU-Timer, Control Register,         Address offset: 0x04        */
    uint16_t resv1;
    uint16_t TPR;           /* CPU-Timer, Prescale Register,        Address offset: 0x06        */
    uint16_t TPRH;          /* CPU-Timer, Prescale Register High,   Address offset: 0x07        */
} Timer_Regs_t;

/* Structure used to store states of an CPUTIMER channel*/ 
typedef struct{
    Timer_Regs_t * timerBase;
    uint32_t frequency;
} Timer_Config_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void Bsp_Timer_Stop(Timer_Regs_t * timerBase);
void Bsp_Timer_Start(Timer_Regs_t * timerBase);
void Bsp_Timer_InterruptEnable(Timer_Regs_t * timerBase);
void Bsp_Timer_InterruptDisable(Timer_Regs_t * timerBase);
void Bsp_Timer_InterruptFlagClear(Timer_Regs_t * timerBase);
void Bsp_Timer_Config(Timer_Config_t * config);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define TIMER_TPRH_BITS_TDDRH_Msk     ((uint32_t)0x00FF)      /* 7:0            */
#define TIMER_TPRH_BITS_PSCH_Msk      ((uint32_t)0xFF00)      /* 15:8           */

#define TIMER_TPR_BITS_TDDR_Msk       ((uint32_t)0x00FF)      /* 7:0            */
#define TIMER_TPR_BITS_PSC_Msk        ((uint32_t)0xFF00)      /* 15:8           */

#define TIMER_TCR_BITS_TSS            ((uint32_t)0x0010)      /* 4 CPU-Timer stop status bit   */
#define TIMER_TCR_BITS_TRB            ((uint32_t)0x0020)      /* 5 Timer reload */
#define TIMER_TCR_BITS_SOFT           ((uint32_t)0x0400)      /* 10             */
#define TIMER_TCR_BITS_FREE           ((uint32_t)0x0800)      /* 11             */
#define TIMER_TCR_BITS_TIE            ((uint32_t)0x4000)      /* 14 CPU-Timer Interrupt Enable  */
#define TIMER_TCR_BITS_TIF            ((uint32_t)0x8000)      /* 15 CPU-Timer Overflow Flag     */

/* Base addresses of peripheral register structures */
#define TIMER_0_BASE            0x00000C00U
#define TIMER_1_BASE            0x00000C08U
#define TIMER_2_BASE            0x00000C10U

/* Pointer to base addresses of peripheral register structures */
#define TIMER_2            ((Timer_Regs_t *)  TIMER_2_BASE)

#endif/*BSP_TIMER_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
