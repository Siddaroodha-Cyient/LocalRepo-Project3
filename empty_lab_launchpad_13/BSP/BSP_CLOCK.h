/***********************************************************************************************
* File    : BSP_CLOCK.h
*
* Module  : Board Support Package (BSP) for CLOCK peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for CLOCK peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for CLOCK peripherals.
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
#ifndef BSP_CLOCK_H
#define BSP_CLOCK_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/

/* Structure used to access CPU peripheral data registers */ 
typedef struct{
    volatile uint32_t CPUSYSLOCK1;          /* 0h - Lock bit for CPUSYS registers */
    volatile uint32_t CPUSYSLOCK2;          /* 2h - Lock bit for CPUSYS registers */
    uint16_t resv1[6];
    volatile uint32_t PIEVERRADDR;          /* Ah  - PIE Vector Fetch Error Address register */
    uint16_t resv2[22];
    volatile uint32_t PCLKCR0;              /* 22h - Peripheral Clock Gating Registers       */
    uint16_t resv3[2];
    volatile uint32_t PCLKCR2;              /* 26h - Peripheral Clock Gating Register - ETPWM */
    volatile uint32_t PCLKCR3;              /* 28h - Peripheral Clock Gating Register - ECAP  */
    volatile uint32_t PCLKCR4;              /* 2Ah - Peripheral Clock Gating Register - EQEP  */
    uint16_t resv4[2];
    volatile uint32_t PCLKCR6;              /* 2Eh - Peripheral Clock Gating Register - SDFM */
    volatile uint32_t PCLKCR7;              /* 30h - Peripheral Clock Gating Register - SCI  */
    volatile uint32_t PCLKCR8;              /* 32h - Peripheral Clock Gating Register - SPI  */
    volatile uint32_t PCLKCR9;              /* 34h - Peripheral Clock Gating Register - I2C  */
    volatile uint32_t PCLKCR10;             /* 36h - Peripheral Clock Gating Register - CAN  */
    uint16_t resv5[4];
    volatile uint32_t PCLKCR13;             /* 3Ch - Peripheral Clock Gating Register - ADC   */
    volatile uint32_t PCLKCR14;             /* 3Eh - Peripheral Clock Gating Register - CMPSS */
    uint16_t resv6[2];
    volatile uint32_t PCLKCR16;             /* 42h - Peripheral Clock Gating Register Buf_DAC */
    volatile uint32_t PCLKCR17;             /* 44h - Peripheral Clock Gating Register - CLB   */
    volatile uint32_t PCLKCR18;             /* 46h - Peripheral Clock Gating Register - FSI   */
    volatile uint32_t PCLKCR19;             /* 48h - Peripheral Clock Gating Register - LIN   */
    volatile uint32_t PCLKCR20;             /* 4Ah - Peripheral Clock Gating Register - PMBUS */
    volatile uint32_t PCLKCR21;             /* 4Ch - Peripheral Clock Gating Register - DCC   */
    uint16_t resv7[6];
    volatile uint32_t PCLKCR25;             /* 54h - Peripheral Clock Gating Register - HIC */
    volatile uint32_t PCLKCR26;             /* 56h - Peripheral Clock Gating Register - AES */
    volatile uint32_t PCLKCR27;             /* 58h - Peripheral Clock Gating Register - EPG */
    uint16_t resv8[22];
    volatile uint32_t SIMRESET;             /* 70h - Simulated Reset Register */
    uint16_t resv9[4];
    volatile uint32_t LPMCR;                /* 76h - LPM Control Register */
    volatile uint32_t GPIOLPMSEL0;          /* 78h - GPIO LPM Wakeup select registers */
    volatile uint32_t GPIOLPMSEL1;          /* 7Ah - GPIO LPM Wakeup select registers */
    volatile uint32_t TMR2CLKCTL;           /* 7Ch - Timer2 Clock Measurement functionality control register */
    volatile uint32_t RESCCLR;              /* 7Eh - Reset Cause Clear Register */
    volatile uint32_t RESC;                 /* 80h - Reset Cause register       */
    uint16_t resv10[22];
    volatile uint32_t MCANWAKESTATUS;       /* 98h - MCAN Wake Status Register       */
    volatile uint32_t MCANWAKESTATUSCLR;    /* 9Ah - MCAN Wake Status Clear Register */
    volatile uint32_t CLKSTOPREQ;           /* 9Ch - Peripheral Clock Stop Request Register     */
    volatile uint32_t CLKSTOPACK;           /* 9Eh - Peripheral Clock Stop Ackonwledge Register */
} CPU_SYS_TypeDef;

/* Structure used to access CLOCK peripheral data registers */ 
typedef struct{
    uint16_t resv1[2];
    volatile uint32_t CLKCFGLOCK1;      /* 2h Lock bit for CLKCFG registers   */
    uint16_t resv2[4];
    volatile uint32_t CLKSRCCTL1;       /* 8h Clock Source Control register-1 */
    volatile uint32_t CLKSRCCTL2;       /* Ah Clock Source Control register-2 */
    volatile uint32_t CLKSRCCTL3;       /* Ch Clock Source Control register-3 */
    volatile uint32_t SYSPLLCTL1;       /* Eh  SYSPLL Control register-1      */
    uint16_t resv3[4];
    volatile uint32_t SYSPLLMULT;       /* 14h  SYSPLL Multiplier register    */
    volatile uint32_t SYSPLLSTS;        /* 16h  SYSPLL Status register        */
    uint16_t resv4[10];
    volatile uint32_t SYSCLKDIVSEL;     /* 22h  System Clock Divider Select register    */
    volatile uint32_t AUXCLKDIVSEL;     /* 24h  Auxillary Clock Divider Select register */
    uint16_t resv5[2];
    volatile uint32_t XCLKOUTDIVSEL;    /* 28h  XCLKOUT Divider Select register  */
    volatile uint32_t CLBCLKCTL;        /* 2Ah  CLB Clocking Control Register    */
    volatile uint32_t LOSPCP;           /* 2Ch  Low Speed Clock Source Prescalar */
    volatile uint32_t MCDCR;            /* 2Eh  Missing Clock Detect Control Register */
    volatile uint32_t X1CNT;            /* 30h  10-bit Counter on X1 Clock */
    volatile uint32_t XTALCR;           /* 32h  XTAL Control Register      */
    volatile uint32_t XTALCR2;          /* 3Ah  XTAL Control Register for pad init */
    volatile uint32_t CLKFAILCFG;       /* 3Ch  Clock Fail cause Configuration     */
} CLK_CFG_Typedef;

/* Structure used to store MCU clock frequencies */ 
typedef struct{
    uint32_t oscclk_frequency;
    uint32_t pllrawclk_frequency;
    uint32_t pllsysclk_frequency;
    uint32_t lspclk_frequency;
} clock_struct_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void clock_peripheral_enable(void);
void clock_pll_config(clock_struct_t * clk);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define XTALCR_BITS_OSCOFF              ((uint32_t)0x00000001)
#define XTALCR_BITS_SE                  ((uint32_t)0x00000002)

#define X1CNT_BITS_X1CNT_Msk            ((uint32_t)0x000007FF)
#define X1CNT_BITS_CLR                  ((uint32_t)0x00010000)

#define CLKSRCCTL1_BITS_OSCCLKSRCSEL_Msk    ((uint32_t)0x00000003)      /* 1:0 OSCCLK Source Select Bit      */
#define CLKSRCCTL1_BITS_rsvd1_Msk           ((uint32_t)0x00000004)      /* 2 Reserved                        */
#define CLKSRCCTL1_BITS_INTOSC2OFF          ((uint32_t)0x00000008)      /* 3 Internal Oscillator 2 Off Bit   */
#define CLKSRCCTL1_BITS_WDHALTI             ((uint32_t)0x00000020)      /* 5 Watchdog HALT Mode Ignore Bit   */

#define CLKSRCCTL1_BITS_OSCCLKSRCSEL_Pos    ((uint32_t)0x00)            /* 1:0 OSCCLK Source Select Bit      */

#define CLKSRCCTL2_BITS_MCANABCLKSEL_Msk    ((uint32_t)0x00000C00)      /* 11:10 MCAN Bit Clock Source Select Bit */
#define CLKSRCCTL2_BITS_MCANABCLKSEL_Pos    ((uint32_t)0x0A)            /* 11:10 MCAN Bit Clock Source Select Bit */

#define CLKSRCCTL2_BITS_CANABCLKSEL_Msk     ((uint32_t)0x0000000C)      /* 3:2 CAN Bit Clock Source Select Bit */
#define CLKSRCCTL2_BITS_CANABCLKSEL_Pos     ((uint32_t)0x02)            /* 3:2 CAN Bit Clock Source Select Bit */

#define SYSPLLCTL1_BITS_PLLEN               ((uint32_t)0x00000001)      /* 0 SYSPLL enable/disable bit                          */
#define SYSPLLCTL1_BITS_PLLCLKEN            ((uint32_t)0x00000002)      /* 1 SYSPLL bypassed or included in the PLLSYSCLK path  */

#define SYSCLKDIVSEL_BITS_PLLSYSCLKDIV_Msk  ((uint32_t)0x0000003F)      /* 5:0 PLLSYSCLK Divide Select  */
#define SYSCLKDIVSEL_BITS_rsvd1_Msk         ((uint32_t)0x0000FFC0)      /* 15:6 Reserved                */
#define SYSCLKDIVSEL_BITS_rsvd2_Msk         ((uint32_t)0xFFFF0000)      /* 31:16 Reserved               */

#define SYSCLKDIVSEL_BITS_PLLSYSCLKDIV_Pos  ((uint32_t)0x00)            /* 5:0 PLLSYSCLK Divide Select  */

#define SYSPLLMULT_BITS_IMULT_Msk       ((uint32_t)0x0000007F)          /* 6:0 SYSPLL Integer Multiplier    */
#define SYSPLLMULT_BITS_rsvd1_Msk       ((uint32_t)0x00000080)          /* 7 Reserved                       */
#define SYSPLLMULT_BITS_FMULT_Msk       ((uint32_t)0x00000300)          /* 9:8 SYSPLL Fractional Multiplier */
#define SYSPLLMULT_BITS_rsvd2_Msk       ((uint32_t)0x0000FC00)          /* 15:10 Reserved                   */
#define SYSPLLMULT_BITS_rsvd3_Msk       ((uint32_t)0xFFFF0000)          /* 31:16 Reserved                   */

#define SYSPLLMULT_BITS_IMULT_Pos       ((uint32_t)0x00)                /* 6:0 SYSPLL Integer Multiplier    */
#define SYSPLLMULT_BITS_FMULT_Pos       ((uint32_t)0x08)                /* 9:8 SYSPLL Fractional Multiplier */

#define SYSPLLSTS_BITS_LOCKS        ((uint32_t)0x00000001)          /* 0 SYSPLL Lock Status Bit     */
#define SYSPLLSTS_BITS_SLIPS        ((uint32_t)0x00000002)          /* 1 SYSPLL Slip Status Bit     */
#define SYSPLLSTS_BITS_rsvd1_Msk    ((uint32_t)0x0000FFFC)          /* 15:2 Reserved                */
#define SYSPLLSTS_BITS_rsvd2_Msk    ((uint32_t)0xFFFF0000)          /* 31:16 Reserved               */

#define AUXCLKDIVSEL_BITS_MCANCLKDIV_Msk    ((uint32_t)0x00001F00)  /* 12:8 */    
#define AUXCLKDIVSEL_BITS_MCANCLKDIV_Pos    ((uint32_t)0x08)        /* 12:8 */

#define PCLKCR0_BITS_CLA1           ((uint32_t)0x00000001)          /* 0 CLA1 Clock Enable Bit       */
#define PCLKCR0_BITS_DMA            ((uint32_t)0x00000004)          /* 2 DMA Clock Enable bit        */
#define PCLKCR0_BITS_CPUTIMER0      ((uint32_t)0x00000008)          /* 3 CPUTIMER0 Clock Enable bit  */
#define PCLKCR0_BITS_CPUTIMER1      ((uint32_t)0x00000010)          /* 4 CPUTIMER1 Clock Enable bit  */
#define PCLKCR0_BITS_CPUTIMER2      ((uint32_t)0x00000020)          /* 5 CPUTIMER2 Clock Enable bit  */
#define PCLKCR0_BITS_CPUBGCRC       ((uint32_t)0x00002000)          /* 13 CPUBGCRC Clock Enable Bit  */
#define PCLKCR0_BITS_CLA1BGCRC      ((uint32_t)0x00004000)          /* 14 CLA1BGCRC Clock Enable Bit */
#define PCLKCR0_BITS_HRCAL          ((uint32_t)0x00010000)          /* 16 HRCAL Clock Enable Bit     */
#define PCLKCR0_BITS_TBCLKSYNC      ((uint32_t)0x00040000)          /* 18 EPWM Time Base Clock sync  */
#define PCLKCR0_BITS_ERAD           ((uint32_t)0x01000000)          /* 24 ERAD Clock Enable Bit      */

#define PCLKCR2_BITS_EPWM1          ((uint32_t)0x00000001)          /* 0 EPWM1 Clock Enable bit */
#define PCLKCR2_BITS_EPWM2          ((uint32_t)0x00000002)          /* 1 EPWM2 Clock Enable bit */
#define PCLKCR2_BITS_EPWM3          ((uint32_t)0x00000004)          /* 2 EPWM3 Clock Enable bit */
#define PCLKCR2_BITS_EPWM4          ((uint32_t)0x00000008)          /* 3 EPWM4 Clock Enable bit */
#define PCLKCR2_BITS_EPWM5          ((uint32_t)0x00000010)          /* 4 EPWM5 Clock Enable bit */
#define PCLKCR2_BITS_EPWM6          ((uint32_t)0x00000020)          /* 5 EPWM6 Clock Enable bit */
#define PCLKCR2_BITS_EPWM7          ((uint32_t)0x00000040)          /* 6 EPWM7 Clock Enable bit */
#define PCLKCR2_BITS_EPWM8          ((uint32_t)0x00000080)          /* 7 EPWM8 Clock Enable bit */

#define PCLKCR3_BITS_ECAP1          ((uint32_t)0x00000001)          /* 0 ECAP1 Clock Enable bit */
#define PCLKCR3_BITS_ECAP2          ((uint32_t)0x00000002)          /* 1 ECAP2 Clock Enable bit */
#define PCLKCR3_BITS_ECAP3          ((uint32_t)0x00000004)          /* 2 ECAP3 Clock Enable bit */

#define PCLKCR4_BITS_EQEP1          ((uint32_t)0x00000001)          /* 0 EQEP1 Clock Enable bit */
#define PCLKCR4_BITS_EQEP2          ((uint32_t)0x00000002)          /* 1 EQEP2 Clock Enable bit */

#define PCLKCR6_BITS_SD1            ((uint32_t)0x00000001)          /* 0 SD1 Clock Enable bit */
#define PCLKCR6_BITS_SD2            ((uint32_t)0x00000002)          /* 1 SD2 Clock Enable bit */

#define PCLKCR7_BITS_SCI_A          ((uint32_t)0x00000001)          /* 0 SCI_A Clock Enable bit */
#define PCLKCR7_BITS_SCI_B          ((uint32_t)0x00000002)          /* 1 SCI_B Clock Enable bit */

#define PCLKCR8_BITS_SPI_A          ((uint32_t)0x00000001)          /* 0 SPI_A Clock Enable bit */
#define PCLKCR8_BITS_SPI_B          ((uint32_t)0x00000002)          /* 1 SPI_B Clock Enable bit */

#define PCLKCR9_BITS_I2C_A          ((uint32_t)0x00000001)          /* 0 I2C_A Clock Enable bit */
#define PCLKCR9_BITS_I2C_B          ((uint32_t)0x00000002)          /* 1 I2C_B Clock Enable bit */

#define PCLKCR10_BITS_CAN_A         ((uint32_t)0x00000001)          /* 0 CAN_A Clock Enable bit   */
#define PCLKCR10_BITS_MCAN_A        ((uint32_t)0x00000010)          /* 4  MCAN_A Clock Enable bit */

#define PCLKCR13_BITS_ADC_A         ((uint32_t)0x00000001)           /* 0 ADC_A Clock Enable bit */
#define PCLKCR13_BITS_ADC_B         ((uint32_t)0x00000002)           /* 1 ADC_B Clock Enable bit */
#define PCLKCR13_BITS_ADC_C         ((uint32_t)0x00000004)           /* 2 ADC_C Clock Enable bit */

#define PCLKCR14_BITS_CMPSS1        ((uint32_t)0x00000001)           /* 0 CMPSS1 Clock Enable bit */
#define PCLKCR14_BITS_CMPSS2        ((uint32_t)0x00000002)           /* 1 CMPSS2 Clock Enable bit */
#define PCLKCR14_BITS_CMPSS3        ((uint32_t)0x00000004)           /* 2 CMPSS3 Clock Enable bit */
#define PCLKCR14_BITS_CMPSS4        ((uint32_t)0x00000008)           /* 3 CMPSS4 Clock Enable bit */

#define PCLKCR16_BITS_DAC_A         ((uint32_t)0x00010000)           /* 16 Buffered_DAC_A Clock Enable Bit */
#define PCLKCR16_BITS_DAC_B         ((uint32_t)0x00020000)           /* 17 Buffered_DAC_B Clock Enable Bit */

#define PCLKCR18_BITS_FSITX_A       ((uint32_t)0x00000001)           /* 0 FSITX_A Clock Enable bit  */
#define PCLKCR18_BITS_FSIRX_A       ((uint32_t)0x00000002)           /* 1 FSIRX_A Clock Enable bit  */

#define XTAL_STARTUP_LOOP_COUNT     (10000U)                         /* Software delay loop */
#define CLK_SRC_XTAL                (1U)                             /* Clock source = XTAL */
#define PLL_LOCK_COUNT              (5U)
#define SYSCLK_DIV_VALUE            (1U)                             /* devide by 2         */
#define LSPCLK_DIVIDER_VALUE        (2U)                           

/* Base addresses of peripheral register structures */
#define CLKCFG_BASE               0x0005D200U
#define CPUSYS_BASE               0x0005D300U

/* Pointer to base addresses of peripheral register structures */
#define CPUSYS              ((CPU_SYS_TypeDef *) CPUSYS_BASE)
#define CLKCFG              ((CLK_CFG_Typedef *) CLKCFG_BASE)


#endif/*BSP_CLOCK_H*/

/****************************************************************************** 
* End of File 
******************************************************************************/
