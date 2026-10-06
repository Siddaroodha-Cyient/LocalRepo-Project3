/***********************************************************************************************
* File: BSP_PWM.c
* Project: 
* Module: Board Support Package (BSP) for PWM peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for PWM peripherals.
*
* Description:
* This file contains board-specific driver functions for Pulse Width Modulation (PWM) with 
* direct interaction to the underlying hardware.
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
* - BSP_PWM.h 
* - HAL_CLOCK.h 
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
#include "BSP_PWM.h"
#include "HAL_CLOCK.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : pwm_duty_update 
*
* Purpose      : 
* Updates the peripheral registers for the required PWM duty cycle.
*
* Inputs       :
*     EPWM  –   Pointer to an EPWM_Typedef structure that contains the 
*               register base address of the PWM peripheral Channel
*     duty  –   Required PWM duty cycle value
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
void pwm_duty_update(EPWM_Typedef * EPWM, float duty)
{
    EPWM->CMPA = ((uint32_t)((EPWM->TBPRD)*duty))<<CMPA_BITS_CMPA_Pos;
}

/******************************************************************************
* Function     : pwm_freq_update 
*
* Purpose      : 
* Updates the peripheral registers for the required PWM frequency.
*
* Inputs       :
*   EPWM    –   Pointer to an EPWM_Typedef structure that contains the 
*               register base address of the PWM peripheral Channel
*  frequency –   Required PWM frequency value
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
void pwm_freq_update(EPWM_Typedef * EPWM, uint32_t frequency)
{
    uint16_t tbprd;
    const clock_struct_t *clk = clock_config_get();
    /* Calculate PWM period based on system clock and desired frequency */
    tbprd = clk->pllsysclk_frequency/frequency/EPWM_UPDOWN_COUNT_DIVIDER;
    /* Period register */
    EPWM->TBPRD = tbprd;
}

/******************************************************************************
* Function     : pwm_disable_channel 
*
* Purpose      : 
* Disables the specified PWM channel by updating the corresponding peripheral 
* registers.
*
* Inputs       :
*     EPWM  –   Pointer to an EPWM_Typedef structure that contains the 
*               register base address of the PWM peripheral Channel
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
void pwm_disable_channel(EPWM_Typedef * EPWM)
{
    EALLOW;
    EPWM->TZFRC |= TZFRC_BITS_OST;
    EDIS;
}

/******************************************************************************
* Function     : pwm_enable_channel 
*
* Purpose      : 
* Enables the specified PWM channel by updating the corresponding peripheral 
* registers.
*
* Inputs       :
*     EPWM  –   Pointer to an EPWM_Typedef structure that contains the 
*               register base address of the PWM peripheral Channel
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
void pwm_enable_channel(EPWM_Typedef * EPWM)
{
    EALLOW;
    EPWM->TZCLR |= TZCLR_BITS_OST;
    EDIS;
}

/******************************************************************************
* Function     : pwm_config 
*
* Purpose      : 
* Configures the peripheral registers for the specified PWM channel and
* the required PWM frequency
*
* Inputs       :
*   EPWM    –   Pointer to an EPWM_Typedef structure that contains the 
*               register base address of the PWM peripheral Channel
*   frequency – Required PWM output frequency
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
void pwm_config(EPWM_Typedef * EPWM)
{
    /* Phase of PWM carrier - 0 */
    EPWM->TBPHS = (uint32_t)0;

    /* Clear counter register    */
    EPWM->TBCTR = (uint16_t)0;

    /* PWM carrier - up down counter */
    EPWM->TBCTL &= ~TBCTL_BITS_CTRMODE_Msk;
    EPWM->TBCTL |= (((uint16_t)TBCTL_BITS_CTRMODE_VALUE<<TBCTL_BITS_CTRMODE_Pos) & TBCTL_BITS_CTRMODE_Msk);

    /* TBCLK = EPWMCLK / (HSPCLKDIV x CLKDIV) */
    /* HSPCLKDIV - /1  */
    EPWM->TBCTL &= ~TBCTL_BITS_HSPCLKDIV_Msk;

    /* CLKDIV - /1  */
    EPWM->TBCTL &= ~TBCTL_BITS_CLKDIV_Msk;

    EPWM->AQCTLA = (uint16_t)0;
    EPWM->AQCTLA |= (((uint16_t)AQCTLA_BITS_CAU_VALUE<<AQCTLA_BITS_CAU_Pos) & AQCTLA_BITS_CAU_Msk);
    EPWM->AQCTLA |= (((uint16_t)AQCTLA_BITS_CAD_VALUE<<AQCTLA_BITS_CAD_Pos) & AQCTLA_BITS_CAD_Msk);

    /* Set the Dead-Band Generator Control Register */
    EPWM->DBCTL = (uint16_t)0;
    EPWM->DBCTL |= (((uint16_t)DBCTL_BITS_OUT_MODE_VALUE<<DBCTL_BITS_OUT_MODE_Pos) & DBCTL_BITS_OUT_MODE_Msk);
    EPWM->DBCTL |= (((uint16_t)DBCTL_BITS_POLSEL_VALUE<<DBCTL_BITS_POLSEL_Pos) & DBCTL_BITS_POLSEL_Msk);
    EPWM->DBCTL |= (((uint16_t)DBCTL_BITS_IN_MODE_VALUE<<DBCTL_BITS_IN_MODE_Pos) & DBCTL_BITS_IN_MODE_Msk);

    /* Dead time of 150 ns (rising and falling edge delay)*/
    EPWM->DBRED = EPWM_DEADBAND_COUNT;
    EPWM->DBFED = EPWM_DEADBAND_COUNT;

    EALLOW;

    EPWM->TZCTL &= ~TZCTL_BITS_TZA_Msk;
    EPWM->TZCTL |= (((uint16_t)TZCTL_BITS_TZA_VALUE<<TZCTL_BITS_TZA_Pos) & TZCTL_BITS_TZA_Msk);

    EPWM->TZCTL &= ~TZCTL_BITS_TZB_Msk;
    EPWM->TZCTL |= (((uint16_t)TZCTL_BITS_TZB_VALUE<<TZCTL_BITS_TZB_Pos) & TZCTL_BITS_TZB_Msk);

    EDIS;
}

/*************** End of C File ************************************************/ 
