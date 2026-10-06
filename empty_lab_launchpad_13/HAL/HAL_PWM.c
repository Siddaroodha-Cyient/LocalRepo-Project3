/***********************************************************************************************
* File: HAL_PWM.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for PWM peripherals
*
* Purpose :
* HAL-level interface for PWM peripherals.
*
* Description:
* This file provides a standardized API for interacting with PWM, abstracting the specific
* register-level operations of the underlying MCU. 
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
* - HAL_PWM.h 
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
#include "HAL_PWM.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
pwm_channel_t EPWM1_AB     = { 
    .EPWM       = EPWM1,
    .top        = { .gpio_number = 0,   .mux_position = 1   },
    .bottom     = { .gpio_number = 1,   .mux_position = 1   },
    .frequency  = 20000,
    .duty       = 0.8,
};

pwm_channel_t EPWM2_AB     = { 
    .EPWM       = EPWM2,
    .top        = { .gpio_number = 2,   .mux_position = 1   },
    .bottom     = { .gpio_number = 3,   .mux_position = 1   },
    .frequency  = 20000,
    .duty       = 0.6,
};

pwm_channel_t EPWM3_AB     = { 
    .EPWM       = EPWM3,
    .top        = { .gpio_number = 4,   .mux_position = 1   },
    .bottom     = { .gpio_number = 5,   .mux_position = 1   },
    .frequency  = 20000,
    .duty       = 0.4,
};

/******************************************************************************
* Function Definitions
******************************************************************************/

/******************************************************************************
* Function     : pwm_init
*
* Purpose      : 
* Initializes the PWM channel with configured frequency and duty cycle.
*
* Inputs       :
*  pwm - Pointer to pwm_channel_t that contains the PWM configuration parameters.
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
void pwm_init(pwm_channel_t *pwm)
{
    /* Configure GPIOs */
    gpio_peripheral_config(&pwm->top);
    gpio_peripheral_config(&pwm->bottom);
    /* Configure PWM */
    pwm_set_freq(pwm, pwm->frequency);
    pwm_config(pwm->EPWM);
    pwm_set_duty(pwm, pwm->duty);
    /* Enable PWM */
    pwm_enable_channel(pwm->EPWM);
}

/******************************************************************************
* Function     : pwm_set_duty
*
* Purpose      : 
* Updates the duty cycle of the specified PWM channel.
*
* Inputs       :
*  pwm  - Pointer to pwm_channel_t structure tht contains PWM channel information.
*  duty - Duty cycle value to be set.
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
void pwm_set_duty(pwm_channel_t *pwm, float duty)
{
    pwm_duty_update(pwm->EPWM, duty);
}

/******************************************************************************
* Function     : pwm_set_freq
*
* Purpose      : 
* Updates the frequency of the specified PWM channel.
*
* Inputs       :
*  pwm       - Pointer to pwm_channel_t structure that contains PWM channel
               information.
*  frequency - Frequency value to be set.
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
void pwm_set_freq(pwm_channel_t *pwm, uint32_t frequency)
{
    pwm_freq_update(pwm->EPWM, frequency);
}

/******************************************************************************
* Function     : epwm1_ab_get 
*
* Purpose      : 
* Provides access to EPWM1_AB channel configuration.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to EPWM1_AB channel structure (pwm_channel_t*).
*
* Requirements: 
*
* Notes        : 
*
******************************************************************************/
pwm_channel_t* epwm1_ab_get(void)
{
    return &EPWM1_AB;
}

/******************************************************************************
* Function     : epwm2_ab_get 
*
* Purpose      : 
* Provides access to EPWM2_AB channel configuration.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to EPWM2_AB channel structure (pwm_channel_t*).
*
* Requirements: 
*
* Notes        : 
*
******************************************************************************/
pwm_channel_t* epwm2_ab_get(void)
{
    return &EPWM2_AB;
}

/******************************************************************************
* Function     : epwm3_ab_get 
*
* Purpose      : 
* Provides access to EPWM3_AB channel configuration.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to EPWM3_AB channel structure (pwm_channel_t*).
*
* Requirements: 
*
* Notes        : 
*
******************************************************************************/
pwm_channel_t* epwm3_ab_get(void)
{
    return &EPWM3_AB;
}

/*************** End of C File ************************************************/
