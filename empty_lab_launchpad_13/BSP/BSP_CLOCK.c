/***********************************************************************************************
* File: BSP_CLOCK.c
* Project: 
* Module: Board Support Package (BSP) for CLOCK peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for CLOCK peripherals
*
* Description:
* This file contains board-specific driver functions for CLOCK with direct
* interaction to the underlying hardware.
*
* High-Level Requirements:  
* 
* Low-Level Requirements:  
* 
* Interfaces: 
* Public: 
* 
* Private:  
* 
* Assumptions:  
* 
* Dependencies: 
* - BSP_CLOCK.h 
* 
* Safety Notes: 
* 
* Verification Notes: 
* 
* Revision History:
*  Rev      Date           Author       Description
*-------- ------------ ------------- -----------------
*  1.0     DD-MM-YYYY      Name         Initial Version
*
***********************************************************************************************/
/******************************************************************************
* Include Files
******************************************************************************/
#include "BSP_CLOCK.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

/******************************************************************************
* Function Definitions
******************************************************************************/

/******************************************************************************
* Function     : clock_peripheral_enable 
*
* Purpose      : 
* Enables the clock for ADC, SPI, SCI, MCAN, CAN, FSI, DMA and PWM peripherals  
* by updating the corresponding clock control registers.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  None.
*
* Requirements :
*
* Notes        :
*
******************************************************************************/

void clock_peripheral_enable(void)
{
    EALLOW;

    /* Enable ePWM modules (PWM generation units) */
    CPUSYS->PCLKCR2 |= PCLKCR2_BITS_EPWM1;
    CPUSYS->PCLKCR2 |= PCLKCR2_BITS_EPWM2;
    CPUSYS->PCLKCR2 |= PCLKCR2_BITS_EPWM3;

    /* Enable SCI-A peripheral (UART communication) */
    CPUSYS->PCLKCR7 |= PCLKCR7_BITS_SCI_A;

    /* Enable SPI modules (serial peripheral interface) */
    CPUSYS->PCLKCR8 |= PCLKCR8_BITS_SPI_A;
    CPUSYS->PCLKCR8 |= PCLKCR8_BITS_SPI_B;

    /* Enable ADC modules (analog-to-digital converters) */
    CPUSYS->PCLKCR13 |= PCLKCR13_BITS_ADC_A;
    CPUSYS->PCLKCR13 |= PCLKCR13_BITS_ADC_B;
    CPUSYS->PCLKCR13 |= PCLKCR13_BITS_ADC_C;

    /* Enable CAN/MCAN communication modules */
    CPUSYS->PCLKCR10 |= PCLKCR10_BITS_MCAN_A;
    CPUSYS->PCLKCR10 |= PCLKCR10_BITS_CAN_A;

    /* Enable FSI modules (fast serial interface TX/RX) */
    CPUSYS->PCLKCR18 |= PCLKCR18_BITS_FSIRX_A;
    CPUSYS->PCLKCR18 |= PCLKCR18_BITS_FSITX_A;

    /* Enable DMA controller */
    CPUSYS->PCLKCR0 |= PCLKCR0_BITS_DMA;

    /* Enable time-base clock synchronization */
    CPUSYS->PCLKCR0 |= PCLKCR0_BITS_TBCLKSYNC;

    EDIS;
}


/******************************************************************************
* Function     : clock_pll_config 
*
* Purpose      : 
* Configures the Phase-Locked Loop (PLL) peripheral registers to generate
* the required system clock frequencies.
*
* Inputs       :
*  clk - Pointer to clock_struct_t containing clock configuration parameters.
*
* Outputs      :
*  None.
*
* Returns      :
*  None.
*
* Requirements :
*
* Notes        :
*
******************************************************************************/
void clock_pll_config(clock_struct_t * clk)
{
    uint32_t i;
    uint32_t imult = clk->pllrawclk_frequency/clk->oscclk_frequency;
    int16_t l_u16PllLockCount;

    EALLOW;
    /* Turn on XTALOSC */
    CLKCFG->XTALCR &= ~XTALCR_BITS_OSCOFF;
    CLKCFG->XTALCR &= ~XTALCR_BITS_SE;

    /* Instruction is bound to encroach on 251( 250+1=251 NOP instructions) instruction cycles */
    __asm(" RPT #250 || NOP \n RPT #50 || NOP");
    
    for (i = 0; i < XTAL_STARTUP_LOOP_COUNT; i++);
    {
        /* Delay loop */
    }
    while (CLKCFG->X1CNT & X1CNT_BITS_X1CNT_Msk != X1CNT_BITS_X1CNT_Msk);

    /* Clk Src = XTAL */
    CLKCFG->CLKSRCCTL1 &= ~CLKSRCCTL1_BITS_OSCCLKSRCSEL_Msk;
    CLKCFG->CLKSRCCTL1 |= (((uint32_t)CLK_SRC_XTAL<<CLKSRCCTL1_BITS_OSCCLKSRCSEL_Pos) & CLKSRCCTL1_BITS_OSCCLKSRCSEL_Msk);

    /* Bypass PLL */
    CLKCFG->SYSPLLCTL1 &= ~SYSPLLCTL1_BITS_PLLCLKEN;

    /* Delay of at least 120 OSCCLK cycles required post PLL bypass */
    {
        /* Instruction is bound to encroach on 121( 120+1=121 NOP instructions) instruction cycles */
        __asm(" RPT #120 || NOP");
    }

    /* System clock divider - /1 */
    CLKCFG->SYSCLKDIVSEL &= ~SYSCLKDIVSEL_BITS_PLLSYSCLKDIV_Msk;

    /* Lock PLL five times */
    for (l_u16PllLockCount=0;l_u16PllLockCount<PLL_LOCK_COUNT;l_u16PllLockCount++)
    {
        CLKCFG->SYSPLLCTL1 &= ~SYSPLLCTL1_BITS_PLLEN;

        /* IMULT - 10, FMULT - 0
         * NOTE: FMULT and IMULT fields must be written at the same time for correct PLL operation */
        CLKCFG->SYSPLLMULT = ((uint32_t)imult<<SYSPLLMULT_BITS_IMULT_Pos);
        /* Wait until PLL locks */
        while((CLKCFG->SYSPLLSTS & SYSPLLSTS_BITS_LOCKS) == (uint32_t)0)
        {
        }
    }
    /* System clock divider - /2 */
    CLKCFG->SYSCLKDIVSEL |= (((uint32_t)SYSCLK_DIV_VALUE<<SYSCLKDIVSEL_BITS_PLLSYSCLKDIV_Pos) & SYSCLKDIVSEL_BITS_PLLSYSCLKDIV_Msk);

    /* Enable PLLSYSCLK is fed from system PLL clock */
    CLKCFG->SYSPLLCTL1 |= SYSPLLCTL1_BITS_PLLCLKEN;

    CLKCFG->LOSPCP = (clk->pllsysclk_frequency/clk->lspclk_frequency)/LSPCLK_DIVIDER_VALUE;
    {
        /* Instruction is bound to encroach on 21( 20+1=21 NOP instructions) instruction cycles */
        __asm(" RPT #20 || NOP");
    }

    EDIS;
}

/*************** End of C File ************************************************/
