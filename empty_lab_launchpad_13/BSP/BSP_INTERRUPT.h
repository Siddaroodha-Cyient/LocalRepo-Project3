/***********************************************************************************************
* File    : BSP_INTERRUPT.h
*
* Module  : Board Support Package (BSP) for INTERRUPT peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for INTERRUPT peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for interrupt peripherals.
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
#ifndef BSP_INTERRUPT_H
#define BSP_INTERRUPT_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/

typedef __interrupt void (*PINT)(void);

/* Structure used to access interrupt vector table */ 
typedef struct{
    PINT  PIE1_RESERVED_INT;                          /* Reserved   */
    PINT  PIE2_RESERVED_INT;                          /* Reserved   */
    PINT  PIE3_RESERVED_INT;                          /* Reserved   */
    PINT  PIE4_RESERVED_INT;                          /* Reserved   */
    PINT  PIE5_RESERVED_INT;                          /* Reserved   */
    PINT  PIE6_RESERVED_INT;                          /* Reserved   */
    PINT  PIE7_RESERVED_INT;                          /* Reserved   */
    PINT  PIE8_RESERVED_INT;                          /* Reserved   */
    PINT  PIE9_RESERVED_INT;                          /* Reserved   */
    PINT  PIE10_RESERVED_INT;                         /* Reserved   */
    PINT  PIE11_RESERVED_INT;                         /* Reserved   */
    PINT  PIE12_RESERVED_INT;                         /* Reserved   */
    PINT  PIE13_RESERVED_INT;                         /* Reserved   */
    PINT  TIMER1_INT;                                 /* CPU Timer 1 Interrupt   */
    PINT  TIMER2_INT;                                 /* CPU Timer 2 Interrupt   */
    PINT  DATALOG_INT;                                /* Datalogging Interrupt   */
    PINT  RTOS_INT;                                   /* RTOS Interrupt   */
    PINT  EMU_INT;                                    /* Emulation Interrupt   */
    PINT  NMI_INT;                                    /* Non-Maskable Interrupt   */
    PINT  ILLEGAL_INT;                                /* Illegal Operation Trap   */
    PINT  USER1_INT;                                  /* User Defined Trap 1   */
    PINT  USER2_INT;                                  /* User Defined Trap 2   */
    PINT  USER3_INT;                                  /* User Defined Trap 3   */
    PINT  USER4_INT;                                  /* User Defined Trap 4   */
    PINT  USER5_INT;                                  /* User Defined Trap 5   */
    PINT  USER6_INT;                                  /* User Defined Trap 6   */
    PINT  USER7_INT;                                  /* User Defined Trap 7   */
    PINT  USER8_INT;                                  /* User Defined Trap 8   */
    PINT  USER9_INT;                                  /* User Defined Trap 9   */
    PINT  USER10_INT;                                 /* User Defined Trap 10   */
    PINT  USER11_INT;                                 /* User Defined Trap 11   */
    PINT  USER12_INT;                                 /* User Defined Trap 12   */
    PINT  ADCA1_INT;                                  /* 1.1 - ADCA Interrupt 1   */
    PINT  ADCB1_INT;                                  /* 1.2 - ADCB Interrupt 1   */
    PINT  ADCC1_INT;                                  /* 1.3 - ADCC Interrupt 1   */
    PINT  XINT1_INT;                                  /* 1.4 - XINT1 Interrupt   */
    PINT  XINT2_INT;                                  /* 1.5 - XINT2 Interrupt   */
    PINT  PIE14_RESERVED_INT;                         /* 1.6 - Reserved   */
    PINT  TIMER0_INT;                                 /* 1.7 - Timer 0 Interrupt   */
    PINT  WAKE_INT;                                   /* 1.8 - Standby and Halt Wakeup Interrupt   */
    PINT  EPWM1_TZ_INT;                               /* 2.1 - ePWM1 Trip Zone Interrupt   */
    PINT  EPWM2_TZ_INT;                               /* 2.2 - ePWM2 Trip Zone Interrupt   */
    PINT  EPWM3_TZ_INT;                               /* 2.3 - ePWM3 Trip Zone Interrupt   */
    PINT  EPWM4_TZ_INT;                               /* 2.4 - ePWM4 Trip Zone Interrupt   */
    PINT  EPWM5_TZ_INT;                               /* 2.5 - ePWM5 Trip Zone Interrupt   */
    PINT  EPWM6_TZ_INT;                               /* 2.6 - ePWM6 Trip Zone Interrupt   */
    PINT  EPWM7_TZ_INT;                               /* 2.7 - ePWM7 Trip Zone Interrupt   */
    PINT  EPWM8_TZ_INT;                               /* 2.8 - ePWM8 Trip Zone Interrupt   */
    PINT  EPWM1_INT;                                  /* 3.1 - ePWM1 Interrupt   */
    PINT  EPWM2_INT;                                  /* 3.2 - ePWM2 Interrupt   */
    PINT  EPWM3_INT;                                  /* 3.3 - ePWM3 Interrupt   */
    PINT  EPWM4_INT;                                  /* 3.4 - ePWM4 Interrupt   */
    PINT  EPWM5_INT;                                  /* 3.5 - ePWM5 Interrupt   */
    PINT  EPWM6_INT;                                  /* 3.6 - ePWM6 Interrupt   */
    PINT  EPWM7_INT;                                  /* 3.7 - ePWM7 Interrupt   */
    PINT  EPWM8_INT;                                  /* 3.8 - ePWM8 Interrupt   */
    PINT  ECAP1_INT;                                  /* 4.1 - eCAP1 Interrupt   */
    PINT  ECAP2_INT;                                  /* 4.2 - eCAP2 Interrupt   */
    PINT  ECAP3_INT;                                  /* 4.3 - eCAP3 Interrupt   */
    PINT  ECAP4_INT;                                  /* 4.4 - eCAP4 Interrupt   */
    PINT  ECAP5_INT;                                  /* 4.5 - eCAP5 Interrupt   */
    PINT  ECAP6_INT;                                  /* 4.6 - eCAP6 Interrupt   */
    PINT  ECAP7_INT;                                  /* 4.7 - eCAP7 Interrupt   */
    PINT  PIE15_RESERVED_INT;                         /* 4.8 - Reserved   */
    PINT  EQEP1_INT;                                  /* 5.1 - eQEP1 Interrupt   */
    PINT  EQEP2_INT;                                  /* 5.2 - eQEP2 Interrupt   */
    PINT  PIE16_RESERVED_INT;                         /* 5.3 - Reserved   */
    PINT  PIE17_RESERVED_INT;                         /* 5.4 - Reserved   */
    PINT  PIE18_RESERVED_INT;                         /* 5.5 - Reserved   */
    PINT  PIE19_RESERVED_INT;                         /* 5.6 - Reserved   */
    PINT  PIE20_RESERVED_INT;                         /* 5.7 - Reserved   */
    PINT  PIE21_RESERVED_INT;                         /* 5.8 - Reserved   */
    PINT  SPIA_RX_INT;                                /* 6.1 - SPIA Receive Interrupt   */
    PINT  SPIA_TX_INT;                                /* 6.2 - SPIA Transmit Interrupt   */
    PINT  SPIB_RX_INT;                                /* 6.3 - SPIB Receive Interrupt   */
    PINT  SPIB_TX_INT;                                /* 6.4 - SPIB Transmit Interrupt   */
    PINT  PIE22_RESERVED_INT;                         /* 6.5 - Reserved   */
    PINT  PIE23_RESERVED_INT;                         /* 6.6 - Reserved   */
    PINT  PIE24_RESERVED_INT;                         /* 6.7 - Reserved   */
    PINT  PIE25_RESERVED_INT;                         /* 6.8 - Reserved   */
    PINT  DMA_CH1_INT;                                /* 7.1 - DMA Channel 1 Interrupt   */
    PINT  DMA_CH2_INT;                                /* 7.2 - DMA Channel 2 Interrupt   */
    PINT  DMA_CH3_INT;                                /* 7.3 - DMA Channel 3 Interrupt   */
    PINT  DMA_CH4_INT;                                /* 7.4 - DMA Channel 4 Interrupt   */
    PINT  DMA_CH5_INT;                                /* 7.5 - DMA Channel 5 Interrupt   */
    PINT  DMA_CH6_INT;                                /* 7.6 - DMA Channel 6 Interrupt   */
    PINT  PIE26_RESERVED_INT;                         /* 7.7 - Reserved   */
    PINT  PIE27_RESERVED_INT;                         /* 7.8 - Reserved   */
    PINT  I2CA_INT;                                   /* 8.1 - I2CA Interrupt 1   */
    PINT  I2CA_FIFO_INT;                              /* 8.2 - I2CA Interrupt 2   */
    PINT  PIE28_RESERVED_INT;                         /* 8.3 - Reserved   */
    PINT  PIE29_RESERVED_INT;                         /* 8.4 - Reserved   */
    PINT  PIE30_RESERVED_INT;                         /* 8.5 - Reserved   */
    PINT  PIE31_RESERVED_INT;                         /* 8.6 - Reserved   */
    PINT  PIE32_RESERVED_INT;                         /* 8.7 - Reserved   */
    PINT  PIE33_RESERVED_INT;                         /* 8.8 - Reserved   */
    PINT  SCIA_RX_INT;                                /* 9.1 - SCIA Receive Interrupt   */
    PINT  SCIA_TX_INT;                                /* 9.2 - SCIA Transmit Interrupt   */
    PINT  SCIB_RX_INT;                                /* 9.3 - SCIB Receive Interrupt   */
    PINT  SCIB_TX_INT;                                /* 9.4 - SCIB Transmit Interrupt   */
    PINT  CANA0_INT;                                  /* 9.5 - CANA Interrupt 0   */
    PINT  CANA1_INT;                                  /* 9.6 - CANA Interrupt 1   */
    PINT  CANB0_INT;                                  /* 9.7 - CANB Interrupt 0   */
    PINT  CANB1_INT;                                  /* 9.8 - CANB Interrupt 1   */
    PINT  ADCA_EVT_INT;                               /* 10.1 - ADCA Event Interrupt   */
    PINT  ADCA2_INT;                                  /* 10.2 - ADCA Interrupt 2   */
    PINT  ADCA3_INT;                                  /* 10.3 - ADCA Interrupt 3   */
    PINT  ADCA4_INT;                                  /* 10.4 - ADCA Interrupt 4   */
    PINT  ADCB_EVT_INT;                               /* 10.5 - ADCB Event Interrupt   */
    PINT  ADCB2_INT;                                  /* 10.6 - ADCB Interrupt 2   */
    PINT  ADCB3_INT;                                  /* 10.7 - ADCB Interrupt 3   */
    PINT  ADCB4_INT;                                  /* 10.8 - ADCB Interrupt 4   */
    PINT  CLA1_1_INT;                                 /* 11.1 - CLA1 Interrupt 1   */
    PINT  CLA1_2_INT;                                 /* 11.2 - CLA1 Interrupt 2   */
    PINT  CLA1_3_INT;                                 /* 11.3 - CLA1 Interrupt 3   */
    PINT  CLA1_4_INT;                                 /* 11.4 - CLA1 Interrupt 4   */
    PINT  CLA1_5_INT;                                 /* 11.5 - CLA1 Interrupt 5   */
    PINT  CLA1_6_INT;                                 /* 11.6 - CLA1 Interrupt 6   */
    PINT  CLA1_7_INT;                                 /* 11.7 - CLA1 Interrupt 7   */
    PINT  CLA1_8_INT;                                 /* 11.8 - CLA1 Interrupt 8   */
    PINT  XINT3_INT;                                  /* 12.1 - XINT3 Interrupt   */
    PINT  XINT4_INT;                                  /* 12.2 - XINT4 Interrupt   */
    PINT  XINT5_INT;                                  /* 12.3 - XINT5 Interrupt   */
    PINT  PIE34_RESERVED_INT;                         /* 12.4 - Reserved   */
    PINT  PIE35_RESERVED_INT;                         /* 12.5 - Reserved   */
    PINT  PIE36_RESERVED_INT;                         /* 12.6 - Reserved   */
    PINT  FPU_OVERFLOW_INT;                           /* 12.7 - FPU Overflow Interrupt   */
    PINT  FPU_UNDERFLOW_INT;                          /* 12.8 - FPU Underflow Interrupt   */
    PINT  PIE37_RESERVED_INT;                         /* 1.9 - Reserved   */
    PINT  PIE38_RESERVED_INT;                         /* 1.10 - Reserved   */
    PINT  PIE39_RESERVED_INT;                         /* 1.11 - Reserved   */
    PINT  PIE40_RESERVED_INT;                         /* 1.12 - Reserved   */
    PINT  PIE41_RESERVED_INT;                         /* 1.13 - Reserved   */
    PINT  PIE42_RESERVED_INT;                         /* 1.14 - Reserved   */
    PINT  PIE43_RESERVED_INT;                         /* 1.15 - Reserved   */
    PINT  PIE44_RESERVED_INT;                         /* 1.16 - Reserved   */
    PINT  PIE45_RESERVED_INT;                         /* 2.9 - Reserved   */
    PINT  PIE46_RESERVED_INT;                         /* 2.10 - Reserved   */
    PINT  PIE47_RESERVED_INT;                         /* 2.11 - Reserved   */
    PINT  PIE48_RESERVED_INT;                         /* 2.12 - Reserved   */
    PINT  PIE49_RESERVED_INT;                         /* 2.13 - Reserved   */
    PINT  PIE50_RESERVED_INT;                         /* 2.14 - Reserved   */
    PINT  PIE51_RESERVED_INT;                         /* 2.15 - Reserved   */
    PINT  PIE52_RESERVED_INT;                         /* 2.16 - Reserved   */
    PINT  PIE53_RESERVED_INT;                         /* 3.9 - Reserved   */
    PINT  PIE54_RESERVED_INT;                         /* 3.10 - Reserved   */
    PINT  PIE55_RESERVED_INT;                         /* 3.11 - Reserved   */
    PINT  PIE56_RESERVED_INT;                         /* 3.12 - Reserved   */
    PINT  PIE57_RESERVED_INT;                         /* 3.13 - Reserved   */
    PINT  PIE58_RESERVED_INT;                         /* 3.14 - Reserved   */
    PINT  PIE59_RESERVED_INT;                         /* 3.15 - Reserved   */
    PINT  PIE60_RESERVED_INT;                         /* 3.16 - Reserved   */
    PINT  PIE61_RESERVED_INT;                         /* 4.9 - Reserved   */
    PINT  PIE62_RESERVED_INT;                         /* 4.10 - Reserved   */
    PINT  PIE63_RESERVED_INT;                         /* 4.11 - Reserved   */
    PINT  PIE64_RESERVED_INT;                         /* 4.12 - Reserved   */
    PINT  PIE65_RESERVED_INT;                         /* 4.13 - Reserved   */
    PINT  ECAP6_2_INT;                                /* 4.14 - eCAP6_2 Interrupt   */
    PINT  ECAP7_2_INT;                                /* 4.15 - eCAP7_2 Interrupt   */
    PINT  PIE66_RESERVED_INT;                         /* 4.16 - Reserved   */
    PINT  SD1_INT;                                    /* 5.9 - SD1 Interrupt   */
    PINT  PIE67_RESERVED_INT;                         /* 5.10 - Reserved   */
    PINT  PIE68_RESERVED_INT;                         /* 5.11 - Reserved   */
    PINT  PIE69_RESERVED_INT;                         /* 5.12 - Reserved   */
    PINT  SD1DR1_INT;                                 /* 5.13 - SD1DR1 Interrupt   */
    PINT  SD1DR2_INT;                                 /* 5.14 - SD1DR2 Interrupt   */
    PINT  SD1DR3_INT;                                 /* 5.15 - SD1DR3 Interrupt   */
    PINT  SD1DR4_INT;                                 /* 5.16 - SD1DR4 Interrupt   */
    PINT  PIE70_RESERVED_INT;                         /* 6.9 - Reserved   */
    PINT  PIE71_RESERVED_INT;                         /* 6.10 - Reserved   */
    PINT  PIE72_RESERVED_INT;                         /* 6.11 - Reserved   */
    PINT  PIE73_RESERVED_INT;                         /* 6.12 - Reserved   */
    PINT  PIE74_RESERVED_INT;                         /* 6.13 - Reserved   */
    PINT  PIE75_RESERVED_INT;                         /* 6.14 - Reserved   */
    PINT  PIE76_RESERVED_INT;                         /* 6.15 - Reserved   */
    PINT  PIE77_RESERVED_INT;                         /* 6.16 - Reserved   */
    PINT  PIE78_RESERVED_INT;                         /* 7.9 - Reserved   */
    PINT  PIE79_RESERVED_INT;                         /* 7.10 - Reserved   */
    PINT  PIE80_RESERVED_INT;                         /* 7.11 - Reserved   */
    PINT  PIE81_RESERVED_INT;                         /* 7.12 - Reserved   */
    PINT  PIE82_RESERVED_INT;                         /* 7.13 - Reserved   */
    PINT  PIE83_RESERVED_INT;                         /* 7.14 - Reserved   */
    PINT  CLA1PROMCRC_INT;                            /* 7.15 - CLA1PROMCRC Interrupt   */
    PINT  PIE84_RESERVED_INT;                         /* 7.16 - Reserved   */
    PINT  LINA_0_INT;                                 /* 8.9 - LINA Interrupt0   */
    PINT  LINA_1_INT;                                 /* 8.10 - LINA Interrupt1   */
    PINT  PIE85_RESERVED_INT;                         /* 8.11 - Reserved   */
    PINT  PIE86_RESERVED_INT;                         /* 8.12 - Reserved   */
    PINT  PMBUSA_INT;                                 /* 8.13 - PMBUSA Interrupt   */
    PINT  PIE87_RESERVED_INT;                         /* 8.14 - Reserved   */
    PINT  PIE88_RESERVED_INT;                         /* 8.15 - Reserved   */
    PINT  PIE89_RESERVED_INT;                         /* 8.16 - Reserved   */
    PINT  PIE90_RESERVED_INT;                         /* 9.9 - Reserved   */
    PINT  PIE91_RESERVED_INT;                         /* 9.10 - Reserved   */
    PINT  PIE92_RESERVED_INT;                         /* 9.11 - Reserved   */
    PINT  PIE93_RESERVED_INT;                         /* 9.12 - Reserved   */
    PINT  PIE94_RESERVED_INT;                         /* 9.13 - Reserved   */
    PINT  PIE95_RESERVED_INT;                         /* 9.14 - Reserved   */
    PINT  PIE96_RESERVED_INT;                         /* 9.15 - Reserved   */
    PINT  PIE97_RESERVED_INT;                         /* 9.16 - Reserved   */
    PINT  ADCC_EVT_INT;                               /* 10.9 - ADCC Event Interrupt   */
    PINT  ADCC2_INT;                                  /* 10.10 - ADCC Interrupt 2   */
    PINT  ADCC3_INT;                                  /* 10.11 - ADCC Interrupt 3   */
    PINT  ADCC4_INT;                                  /* 10.12 - ADCC Interrupt 4   */
    PINT  PIE98_RESERVED_INT;                         /* 10.13 - Reserved   */
    PINT  PIE99_RESERVED_INT;                         /* 10.14 - Reserved   */
    PINT  PIE100_RESERVED_INT;                        /* 10.15 - Reserved   */
    PINT  PIE101_RESERVED_INT;                        /* 10.16 - Reserved   */
    PINT  PIE102_RESERVED_INT;                        /* 11.9 - Reserved   */
    PINT  PIE103_RESERVED_INT;                        /* 11.10 - Reserved   */
    PINT  PIE104_RESERVED_INT;                        /* 11.11 - Reserved   */
    PINT  PIE105_RESERVED_INT;                        /* 11.12 - Reserved   */
    PINT  PIE106_RESERVED_INT;                        /* 11.13 - Reserved   */
    PINT  PIE107_RESERVED_INT;                        /* 11.14 - Reserved   */
    PINT  PIE108_RESERVED_INT;                        /* 11.15 - Reserved   */
    PINT  PIE109_RESERVED_INT;                        /* 11.16 - Reserved   */
    PINT  PIE110_RESERVED_INT;                        /* 12.9 - Reserved   */
    PINT  RAM_CORRECTABLE_ERROR_INT;                  /* 12.10 - RAM Correctable Error Interrupt   */
    PINT  FLASH_CORRECTABLE_ERROR_INT;                /* 12.11 - Flash Correctable Error Interrupt   */
    PINT  RAM_ACCESS_VIOLATION_INT;                   /* 12.12 - RAM Access Violation Interrupt   */
    PINT  SYS_PLL_SLIP_INT;                           /* 12.13 - System PLL Slip Interrupt   */
    PINT  PIE111_RESERVED_INT;                        /* 12.14 - Reserved   */
    PINT  CLA_OVERFLOW_INT;                           /* 12.15 - CLA Overflow Interrupt   */
    PINT  CLA_UNDERFLOW_INT;                          /* 12.16 - CLA Underflow Interrupt   */
}  PIE_VECT_TABLE_Typedef;

/* Structure used to access interrupt peripheral data registers */ 
typedef struct {
    uint16_t   PIECTRL;         /* ePIE Control Register                    */
    uint16_t   PIEACK;          /* Interrupt Acknowledge Register           */
    uint16_t   PIEIER1;         /* Interrupt Group 1 Enable Register        */
    uint16_t   PIEIFR1;         /* Interrupt Group 1 Flag Register          */
    uint16_t   PIEIER2;         /* Interrupt Group 2 Enable Register        */
    uint16_t   PIEIFR2;         /* Interrupt Group 2 Flag Register          */
    uint16_t   PIEIER3;         /* Interrupt Group 3 Enable Register        */
    uint16_t   PIEIFR3;         /* Interrupt Group 3 Flag Register          */
    uint16_t   PIEIER4;         /* Interrupt Group 4 Enable Register        */
    uint16_t   PIEIFR4;         /* Interrupt Group 4 Flag Register          */
    uint16_t   PIEIER5;         /* Interrupt Group 5 Enable Register        */
    uint16_t   PIEIFR5;         /* Interrupt Group 5 Flag Register          */
    uint16_t   PIEIER6;         /* Interrupt Group 6 Enable Register        */
    uint16_t   PIEIFR6;         /* Interrupt Group 6 Flag Register          */
    uint16_t   PIEIER7;         /* Interrupt Group 7 Enable Register        */
    uint16_t   PIEIFR7;         /* Interrupt Group 7 Flag Register          */
    uint16_t   PIEIER8;         /* Interrupt Group 8 Enable Register        */
    uint16_t   PIEIFR8;         /* Interrupt Group 8 Flag Register          */
    uint16_t   PIEIER9;         /* Interrupt Group 9 Enable Register        */
    uint16_t   PIEIFR9;         /* Interrupt Group 9 Flag Register          */
    uint16_t   PIEIER10;        /* Interrupt Group 10 Enable Register       */
    uint16_t   PIEIFR10;        /* Interrupt Group 10 Flag Register         */
    uint16_t   PIEIER11;        /* Interrupt Group 11 Enable Register       */
    uint16_t   PIEIFR11;        /* Interrupt Group 11 Flag Register         */
    uint16_t   PIEIER12;        /* Interrupt Group 12 Enable Register       */
    uint16_t   PIEIFR12;        /* Interrupt Group 12 Flag Register         */
} PIE_CTRL_Typedef;


/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void interrupt_vector_table_init(void);
void interrupt_timer2_init(PINT func);
__interrupt void interrupt_default_isr(void);

/****************************************************************************** 
* Core Register Declarations 
******************************************************************************/
extern __cregister volatile uint16_t IFR;
extern __cregister volatile uint16_t IER;

#define IER_BITS_INT1       ((uint16_t)0b0000000000000001)              /* 0 Interrupt 1        */
#define IER_BITS_INT2       ((uint16_t)0b0000000000000010)              /* 1 Interrupt 2        */
#define IER_BITS_INT3       ((uint16_t)0b0000000000000100)              /* 2 Interrupt 3        */
#define IER_BITS_INT4       ((uint16_t)0b0000000000001000)              /* 3 Interrupt 4        */
#define IER_BITS_INT5       ((uint16_t)0b0000000000010000)              /* 4 Interrupt 5        */
#define IER_BITS_INT6       ((uint16_t)0b0000000000100000)              /* 5 Interrupt 6        */
#define IER_BITS_INT7       ((uint16_t)0b0000000001000000)              /* 6 Interrupt 7        */
#define IER_BITS_INT8       ((uint16_t)0b0000000010000000)              /* 7 Interrupt 8        */
#define IER_BITS_INT9       ((uint16_t)0b0000000100000000)              /* 8 Interrupt 9        */
#define IER_BITS_INT10      ((uint16_t)0b0000001000000000)              /* 9 Interrupt 10       */
#define IER_BITS_INT11      ((uint16_t)0b0000010000000000)              /* 10 Interrupt 11      */
#define IER_BITS_INT12      ((uint16_t)0b0000100000000000)              /* 11 Interrupt 12      */
#define IER_BITS_INT13      ((uint16_t)0b0001000000000000)              /* 12 Interrupt 13      */
#define IER_BITS_INT14      ((uint16_t)0b0010000000000000)              /* 13 Interrupt 14      */
#define IER_BITS_DLOGINT    ((uint16_t)0b0100000000000000               /* 14 Interrupt DLOG    */
#define IER_BITS_RTOSINT    ((uint16_t)0b1000000000000000)              /* 15 Interrupt RTOS    */

#define PIECTRL_BITS_ENPIE          ((uint16_t)0b0000000000000001)       /* 0 PIE Enable            */
#define PIECTRL_BITS_PIEVECT_Msk    ((uint16_t)0b1111111111111110)       /* 15:1 PIE Vector Address */

#define PIECTRL_BITS_PIEVECT_Pos    ((uint16_t)1)       /* 15:1 PIE Vector Address      */

#define PIEACK_BITS_ACK1            ((uint16_t)0b0000000000000001)          /* 0 Acknowledge PIE Interrupt Group 1  */
#define PIEACK_BITS_ACK2            ((uint16_t)0b0000000000000010)          /* 1 Acknowledge PIE Interrupt Group 2  */
#define PIEACK_BITS_ACK3            ((uint16_t)0b0000000000000100)          /* 2 Acknowledge PIE Interrupt Group 3  */
#define PIEACK_BITS_ACK4            ((uint16_t)0b0000000000001000)          /* 3 Acknowledge PIE Interrupt Group 4  */
#define PIEACK_BITS_ACK5            ((uint16_t)0b0000000000010000)          /* 4 Acknowledge PIE Interrupt Group 5  */
#define PIEACK_BITS_ACK6            ((uint16_t)0b0000000000100000)          /* 5 Acknowledge PIE Interrupt Group 6  */
#define PIEACK_BITS_ACK7            ((uint16_t)0b0000000001000000)          /* 6 Acknowledge PIE Interrupt Group 7  */
#define PIEACK_BITS_ACK8            ((uint16_t)0b0000000010000000)          /* 7 Acknowledge PIE Interrupt Group 8  */
#define PIEACK_BITS_ACK9            ((uint16_t)0b0000000100000000)          /* 8 Acknowledge PIE Interrupt Group 9  */
#define PIEACK_BITS_ACK10           ((uint16_t)0b0000001000000000)          /* 9 Acknowledge PIE Interrupt Group 10 */
#define PIEACK_BITS_ACK11           ((uint16_t)0b0000010000000000)          /* 10 Acknowledge PIE Interrupt Group 11*/
#define PIEACK_BITS_ACK12           ((uint16_t)0b0000100000000000)          /* 11 Acknowledge PIE Interrupt Group 12*/
#define PIEACK_BITS_rsvd1_Msk       ((uint16_t)0b1111000000000000)          /* 15:12 Reserved                       */

#define PIEIER1_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 1.1      */
#define PIEIER1_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 1.2      */
#define PIEIER1_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 1.3      */
#define PIEIER1_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 1.4      */
#define PIEIER1_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 1.5      */
#define PIEIER1_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 1.6      */
#define PIEIER1_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 1.7      */
#define PIEIER1_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 1.8      */
#define PIEIER1_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 1.9      */
#define PIEIER1_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 1.10     */
#define PIEIER1_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 1.11    */
#define PIEIER1_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 1.12    */
#define PIEIER1_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 1.13    */
#define PIEIER1_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 1.14    */
#define PIEIER1_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 1.15    */
#define PIEIER1_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 1.16    */

#define PIEIFR1_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 1.1    */
#define PIEIFR1_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 1.2    */
#define PIEIFR1_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 1.3    */
#define PIEIFR1_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 1.4    */
#define PIEIFR1_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 1.5    */
#define PIEIFR1_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 1.6    */
#define PIEIFR1_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 1.7    */
#define PIEIFR1_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 1.8    */
#define PIEIFR1_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 1.9    */
#define PIEIFR1_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 1.10   */
#define PIEIFR1_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 1.11  */
#define PIEIFR1_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 1.12  */
#define PIEIFR1_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 1.13  */
#define PIEIFR1_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 1.14  */
#define PIEIFR1_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 1.15  */
#define PIEIFR1_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 1.16  */

#define PIEIER2_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 2.1    */
#define PIEIER2_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 2.2    */
#define PIEIER2_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 2.3    */
#define PIEIER2_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 2.4    */
#define PIEIER2_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 2.5    */
#define PIEIER2_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 2.6    */
#define PIEIER2_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 2.7    */
#define PIEIER2_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 2.8    */
#define PIEIER2_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 2.9    */
#define PIEIER2_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 2.10   */
#define PIEIER2_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 2.11  */
#define PIEIER2_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 2.12  */
#define PIEIER2_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 2.13  */
#define PIEIER2_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 2.14  */
#define PIEIER2_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 2.15  */
#define PIEIER2_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 2.16  */

#define PIEIFR2_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 2.1    */
#define PIEIFR2_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 2.2    */
#define PIEIFR2_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 2.3    */
#define PIEIFR2_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 2.4    */
#define PIEIFR2_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 2.5    */
#define PIEIFR2_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 2.6    */
#define PIEIFR2_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 2.7    */
#define PIEIFR2_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 2.8    */
#define PIEIFR2_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 2.9    */
#define PIEIFR2_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 2.10   */
#define PIEIFR2_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 2.11  */
#define PIEIFR2_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 2.12  */
#define PIEIFR2_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 2.13  */
#define PIEIFR2_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 2.14  */
#define PIEIFR2_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 2.15  */
#define PIEIFR2_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 2.16  */

#define PIEIER3_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 3.1    */
#define PIEIER3_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 3.2    */
#define PIEIER3_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 3.3    */
#define PIEIER3_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 3.4    */
#define PIEIER3_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 3.5    */
#define PIEIER3_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 3.6    */
#define PIEIER3_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 3.7    */
#define PIEIER3_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 3.8    */
#define PIEIER3_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 3.9    */
#define PIEIER3_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 3.10   */
#define PIEIER3_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 3.11  */
#define PIEIER3_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 3.12  */
#define PIEIER3_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 3.13  */
#define PIEIER3_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 3.14  */
#define PIEIER3_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 3.15  */
#define PIEIER3_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 3.16  */

#define PIEIFR3_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 3.1    */
#define PIEIFR3_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 3.2    */
#define PIEIFR3_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 3.3    */
#define PIEIFR3_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 3.4    */
#define PIEIFR3_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 3.5    */
#define PIEIFR3_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 3.6    */
#define PIEIFR3_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 3.7    */
#define PIEIFR3_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 3.8    */
#define PIEIFR3_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 3.9    */
#define PIEIFR3_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 3.10   */
#define PIEIFR3_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 3.11  */
#define PIEIFR3_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 3.12  */
#define PIEIFR3_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 3.13  */
#define PIEIFR3_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 3.14  */
#define PIEIFR3_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 3.15  */
#define PIEIFR3_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 3.16  */

#define PIEIER4_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 4.1    */
#define PIEIER4_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 4.2    */
#define PIEIER4_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 4.3    */
#define PIEIER4_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 4.4    */
#define PIEIER4_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 4.5    */
#define PIEIER4_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 4.6    */
#define PIEIER4_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 4.7    */
#define PIEIER4_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 4.8    */
#define PIEIER4_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 4.9    */
#define PIEIER4_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 4.10   */
#define PIEIER4_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 4.11  */
#define PIEIER4_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 4.12  */
#define PIEIER4_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 4.13  */
#define PIEIER4_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 4.14  */
#define PIEIER4_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 4.15  */
#define PIEIER4_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 4.16  */

#define PIEIFR4_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 4.1    */
#define PIEIFR4_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 4.2    */
#define PIEIFR4_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 4.3    */
#define PIEIFR4_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 4.4    */
#define PIEIFR4_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 4.5    */
#define PIEIFR4_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 4.6    */
#define PIEIFR4_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 4.7    */
#define PIEIFR4_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 4.8    */
#define PIEIFR4_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 4.9    */
#define PIEIFR4_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 4.10   */
#define PIEIFR4_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 4.11  */
#define PIEIFR4_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 4.12  */
#define PIEIFR4_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 4.13  */
#define PIEIFR4_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 4.14  */
#define PIEIFR4_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 4.15  */
#define PIEIFR4_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 4.16  */

#define PIEIER5_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 5.1    */
#define PIEIER5_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 5.2    */
#define PIEIER5_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 5.3    */
#define PIEIER5_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 5.4    */
#define PIEIER5_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 5.5    */
#define PIEIER5_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 5.6    */
#define PIEIER5_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 5.7    */
#define PIEIER5_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 5.8    */
#define PIEIER5_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 5.9    */
#define PIEIER5_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 5.10   */
#define PIEIER5_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 5.11  */
#define PIEIER5_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 5.12  */
#define PIEIER5_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 5.13  */
#define PIEIER5_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 5.14  */
#define PIEIER5_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 5.15  */
#define PIEIER5_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 5.16  */

#define PIEIFR5_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 5.1    */
#define PIEIFR5_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 5.2    */
#define PIEIFR5_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 5.3    */
#define PIEIFR5_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 5.4    */
#define PIEIFR5_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 5.5    */
#define PIEIFR5_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 5.6    */
#define PIEIFR5_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 5.7    */
#define PIEIFR5_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 5.8    */
#define PIEIFR5_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 5.9    */
#define PIEIFR5_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 5.10   */
#define PIEIFR5_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 5.11  */
#define PIEIFR5_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 5.12  */
#define PIEIFR5_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 5.13  */
#define PIEIFR5_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 5.14  */
#define PIEIFR5_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 5.15  */
#define PIEIFR5_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 5.16  */

#define PIEIER6_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 6.1    */
#define PIEIER6_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 6.2    */
#define PIEIER6_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 6.3    */
#define PIEIER6_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 6.4    */
#define PIEIER6_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 6.5    */
#define PIEIER6_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 6.6    */
#define PIEIER6_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 6.7    */
#define PIEIER6_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 6.8    */
#define PIEIER6_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 6.9    */
#define PIEIER6_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 6.10   */
#define PIEIER6_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 6.11  */
#define PIEIER6_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 6.12  */
#define PIEIER6_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 6.13  */
#define PIEIER6_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 6.14  */
#define PIEIER6_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 6.15  */
#define PIEIER6_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 6.16  */

#define PIEIFR6_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 6.1    */
#define PIEIFR6_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 6.2    */
#define PIEIFR6_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 6.3    */
#define PIEIFR6_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 6.4    */
#define PIEIFR6_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 6.5    */
#define PIEIFR6_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 6.6    */
#define PIEIFR6_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 6.7    */
#define PIEIFR6_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 6.8    */
#define PIEIFR6_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 6.9    */
#define PIEIFR6_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 6.10   */
#define PIEIFR6_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 6.11  */
#define PIEIFR6_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 6.12  */
#define PIEIFR6_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 6.13  */
#define PIEIFR6_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 6.14  */
#define PIEIFR6_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 6.15  */
#define PIEIFR6_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 6.16  */

#define PIEIER7_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 7.1    */
#define PIEIER7_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 7.2    */
#define PIEIER7_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 7.3    */
#define PIEIER7_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 7.4    */
#define PIEIER7_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 7.5    */
#define PIEIER7_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 7.6    */
#define PIEIER7_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 7.7    */
#define PIEIER7_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 7.8    */
#define PIEIER7_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 7.9    */
#define PIEIER7_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 7.10   */
#define PIEIER7_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 7.11  */
#define PIEIER7_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 7.12  */
#define PIEIER7_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 7.13  */
#define PIEIER7_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 7.14  */
#define PIEIER7_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 7.15  */
#define PIEIER7_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 7.16  */

#define PIEIFR7_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 7.1    */
#define PIEIFR7_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 7.2    */
#define PIEIFR7_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 7.3    */
#define PIEIFR7_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 7.4    */
#define PIEIFR7_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 7.5    */
#define PIEIFR7_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 7.6    */
#define PIEIFR7_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 7.7    */
#define PIEIFR7_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 7.8    */
#define PIEIFR7_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 7.9    */
#define PIEIFR7_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 7.10   */
#define PIEIFR7_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 7.11  */
#define PIEIFR7_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 7.12  */
#define PIEIFR7_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 7.13  */
#define PIEIFR7_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 7.14  */
#define PIEIFR7_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 7.15  */
#define PIEIFR7_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 7.16  */

#define PIEIER8_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 8.1    */
#define PIEIER8_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 8.2    */
#define PIEIER8_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 8.3    */
#define PIEIER8_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 8.4    */
#define PIEIER8_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 8.5    */
#define PIEIER8_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 8.6    */
#define PIEIER8_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 8.7    */
#define PIEIER8_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 8.8    */
#define PIEIER8_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 8.9    */
#define PIEIER8_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 8.10   */
#define PIEIER8_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 8.11  */
#define PIEIER8_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 8.12  */
#define PIEIER8_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 8.13  */
#define PIEIER8_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 8.14  */
#define PIEIER8_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 8.15  */
#define PIEIER8_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 8.16  */

#define PIEIFR8_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 8.1      */
#define PIEIFR8_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 8.2      */
#define PIEIFR8_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 8.3      */
#define PIEIFR8_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 8.4      */
#define PIEIFR8_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 8.5      */
#define PIEIFR8_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 8.6      */
#define PIEIFR8_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 8.7      */
#define PIEIFR8_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 8.8      */
#define PIEIFR8_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 8.9      */
#define PIEIFR8_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 8.10     */
#define PIEIFR8_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 8.11    */
#define PIEIFR8_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 8.12    */
#define PIEIFR8_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 8.13    */
#define PIEIFR8_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 8.14    */
#define PIEIFR8_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 8.15    */
#define PIEIFR8_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 8.16    */

#define PIEIER9_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 9.1    */
#define PIEIER9_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 9.2    */
#define PIEIER9_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 9.3    */
#define PIEIER9_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 9.4    */
#define PIEIER9_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 9.5    */
#define PIEIER9_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 9.6    */
#define PIEIER9_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 9.7    */
#define PIEIER9_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 9.8    */
#define PIEIER9_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 9.9    */
#define PIEIER9_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 9.10   */
#define PIEIER9_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 9.11  */
#define PIEIER9_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 9.12  */
#define PIEIER9_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 9.13  */
#define PIEIER9_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 9.14  */
#define PIEIER9_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 9.15  */
#define PIEIER9_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 9.16  */

#define PIEIFR9_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 9.1      */
#define PIEIFR9_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 9.2      */
#define PIEIFR9_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 9.3      */
#define PIEIFR9_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 9.4      */
#define PIEIFR9_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 9.5      */
#define PIEIFR9_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 9.6      */
#define PIEIFR9_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 9.7      */
#define PIEIFR9_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 9.8      */
#define PIEIFR9_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 9.9      */
#define PIEIFR9_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 9.10     */
#define PIEIFR9_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 9.11    */
#define PIEIFR9_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 9.12    */
#define PIEIFR9_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 9.13    */
#define PIEIFR9_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 9.14    */
#define PIEIFR9_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 9.15    */
#define PIEIFR9_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 9.16    */

#define PIEIER10_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 10.1    */
#define PIEIER10_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 10.2    */
#define PIEIER10_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 10.3    */
#define PIEIER10_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 10.4    */
#define PIEIER10_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 10.5    */
#define PIEIER10_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 10.6    */
#define PIEIER10_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 10.7    */
#define PIEIER10_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 10.8    */
#define PIEIER10_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 10.9    */
#define PIEIER10_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 10.10   */
#define PIEIER10_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 10.11  */
#define PIEIER10_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 10.12  */
#define PIEIER10_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 10.13  */
#define PIEIER10_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 10.14  */
#define PIEIER10_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 10.15  */
#define PIEIER10_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 10.16  */

#define PIEIFR10_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 10.1      */
#define PIEIFR10_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 10.2      */
#define PIEIFR10_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 10.3      */
#define PIEIFR10_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 10.4      */
#define PIEIFR10_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 10.5      */
#define PIEIFR10_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 10.6      */
#define PIEIFR10_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 10.7      */
#define PIEIFR10_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 10.8      */
#define PIEIFR10_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 10.9      */
#define PIEIFR10_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 10.10     */
#define PIEIFR10_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 10.11    */
#define PIEIFR10_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 10.12    */
#define PIEIFR10_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 10.13    */
#define PIEIFR10_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 10.14    */
#define PIEIFR10_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 10.15    */
#define PIEIFR10_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 10.16    */

#define PIEIER11_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 11.1    */
#define PIEIER11_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 11.2    */
#define PIEIER11_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 11.3    */
#define PIEIER11_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 11.4    */
#define PIEIER11_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 11.5    */
#define PIEIER11_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 11.6    */
#define PIEIER11_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 11.7    */
#define PIEIER11_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 11.8    */
#define PIEIER11_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 11.9    */
#define PIEIER11_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 11.10   */
#define PIEIER11_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 11.11  */
#define PIEIER11_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 11.12  */
#define PIEIER11_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 11.13  */
#define PIEIER11_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 11.14  */
#define PIEIER11_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 11.15  */
#define PIEIER11_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 11.16  */

#define PIEIFR11_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 11.1      */
#define PIEIFR11_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 11.2      */
#define PIEIFR11_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 11.3      */
#define PIEIFR11_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 11.4      */
#define PIEIFR11_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 11.5      */
#define PIEIFR11_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 11.6      */
#define PIEIFR11_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 11.7      */
#define PIEIFR11_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 11.8      */
#define PIEIFR11_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 11.9      */
#define PIEIFR11_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 11.10     */
#define PIEIFR11_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 11.11    */
#define PIEIFR11_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 11.12    */
#define PIEIFR11_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 11.13    */
#define PIEIFR11_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 11.14    */
#define PIEIFR11_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 11.15    */
#define PIEIFR11_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 11.16    */

#define PIEIER12_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Enable for Interrupt 12.1    */
#define PIEIER12_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Enable for Interrupt 12.2    */
#define PIEIER12_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Enable for Interrupt 12.3    */
#define PIEIER12_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Enable for Interrupt 12.4    */
#define PIEIER12_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Enable for Interrupt 12.5    */
#define PIEIER12_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Enable for Interrupt 12.6    */
#define PIEIER12_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Enable for Interrupt 12.7    */
#define PIEIER12_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Enable for Interrupt 12.8    */
#define PIEIER12_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Enable for Interrupt 12.9    */
#define PIEIER12_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Enable for Interrupt 12.10   */
#define PIEIER12_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Enable for Interrupt 12.11  */
#define PIEIER12_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Enable for Interrupt 12.12  */
#define PIEIER12_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Enable for Interrupt 12.13  */
#define PIEIER12_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Enable for Interrupt 12.14  */
#define PIEIER12_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Enable for Interrupt 12.15  */
#define PIEIER12_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Enable for Interrupt 12.16  */

#define PIEIFR12_BITS_INTx1          ((uint16_t)0b0000000000000001)          /* 0 Flag for Interrupt 12.1      */
#define PIEIFR12_BITS_INTx2          ((uint16_t)0b0000000000000010)          /* 1 Flag for Interrupt 12.2      */
#define PIEIFR12_BITS_INTx3          ((uint16_t)0b0000000000000100)          /* 2 Flag for Interrupt 12.3      */
#define PIEIFR12_BITS_INTx4          ((uint16_t)0b0000000000001000)          /* 3 Flag for Interrupt 12.4      */
#define PIEIFR12_BITS_INTx5          ((uint16_t)0b0000000000010000)          /* 4 Flag for Interrupt 12.5      */
#define PIEIFR12_BITS_INTx6          ((uint16_t)0b0000000000100000)          /* 5 Flag for Interrupt 12.6      */
#define PIEIFR12_BITS_INTx7          ((uint16_t)0b0000000001000000)          /* 6 Flag for Interrupt 12.7      */
#define PIEIFR12_BITS_INTx8          ((uint16_t)0b0000000010000000)          /* 7 Flag for Interrupt 12.8      */
#define PIEIFR12_BITS_INTx9          ((uint16_t)0b0000000100000000)          /* 8 Flag for Interrupt 12.9      */
#define PIEIFR12_BITS_INTx10         ((uint16_t)0b0000001000000000)          /* 9 Flag for Interrupt 12.10     */
#define PIEIFR12_BITS_INTx11         ((uint16_t)0b0000010000000000)          /* 10 Flag for Interrupt 12.11    */
#define PIEIFR12_BITS_INTx12         ((uint16_t)0b0000100000000000)          /* 11 Flag for Interrupt 12.12    */
#define PIEIFR12_BITS_INTx13         ((uint16_t)0b0001000000000000)          /* 12 Flag for Interrupt 12.13    */
#define PIEIFR12_BITS_INTx14         ((uint16_t)0b0010000000000000)          /* 13 Flag for Interrupt 12.14    */
#define PIEIFR12_BITS_INTx15         ((uint16_t)0b0100000000000000)          /* 14 Flag for Interrupt 12.15    */
#define PIEIFR12_BITS_INTx16         ((uint16_t)0b1000000000000000)          /* 15 Flag for Interrupt 12.16    */

#define PIE_VECTOR_START_INDEX       (3U)               /* Skip reserved/system interrupt entries */

/* Base addresses of peripheral register structures */
#define PIECTRL_BASE              0x00000CE0U
#define PIEVECTTABLE_BASE         0x00000D00U

/* Pointer to base addresses of peripheral register structures */
#define PIE_CTRL                 ((PIE_CTRL_Typedef *) PIECTRL_BASE)
#define PIEVECTTABLE            ((PIE_VECT_TABLE_Typedef *) PIEVECTTABLE_BASE)

#endif/*BSP_INTERRUPT_H*/

/****************************************************************************** 
* End of File 
******************************************************************************/
