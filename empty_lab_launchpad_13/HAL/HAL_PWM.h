/***********************************************************************************************
* File: HAL_PWM.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for PWM peripherals
*
* Purpose :
* HAL-level interface for PWM peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for PWM peripherals.
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
#ifndef HAL_PWM_H
#define HAL_PWM_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <BSP_PWM.h>

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void pwm_set_freq(pwm_channel_t *pwm, uint32_t frequency);
void pwm_init(pwm_channel_t *pwm);
void pwm_set_duty(pwm_channel_t *pwm, float duty);
pwm_channel_t* epwm1_ab_get(void);
pwm_channel_t* epwm2_ab_get(void);
pwm_channel_t* epwm3_ab_get(void);

#endif /* HAL_PWM_H */
/****************************************************************************** 
* End of File 
******************************************************************************/
