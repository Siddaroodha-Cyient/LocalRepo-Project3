/***********************************************************************************************
* File: BSP_GPIO.c
* Project: 
* Module: Board Support Package (BSP) for GPIO peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for GPIO peripherals
*
* Description:
* This file contains board-specific driver functions for General Purpose Input/Output (GPIO) pins 
* with direct interaction to the underlying hardware.
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
* - BSP_GPIO.h 
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
#include "BSP_GPIO.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : gpio_out_update 
*
* Purpose      : 
* Updates the voltage of a GPIO output pin.
*
* Inputs       :
*   signal  –   pointer to a 'gpio_out_t' structure that contains the information 
*               of gpio pin number and desired output level
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
void gpio_out_update(gpio_out_t * signal)
{
    uint32_t pos = signal->gpio_number;
    if (pos < 32)
    {
        if (signal->out_level)
        {
            GPIODATA->GPASET |= ((uint32_t)GPxSET_GPIOy_Msk<<pos);
        }
        else
        {
            GPIODATA->GPACLEAR |=  ((uint32_t)GPxCLEAR_GPIOy_Msk<<pos);
        }
    }
    else if (pos < 64)
    {
        pos -= 32;
        if (signal->out_level)
        {
            GPIODATA->GPBSET |= ((uint32_t)GPxSET_GPIOy_Msk<<pos);
        }
        else
        {
            GPIODATA->GPBCLEAR |=  ((uint32_t)GPxCLEAR_GPIOy_Msk<<pos);
        }
    }
}

/******************************************************************************
* Function     : gpio_in_read
*
* Purpose      : 
* Reads the input level of the specified GPIO pin.
*
* Inputs       :
*  gpio_number - GPIO pin number to be read.
*
* Outputs      :
*  None.
*
* Returns      :
*  uint16_t - Returns 1 if the GPIO input is high, otherwise 0.
*
* Requirements :
*
* Notes        :
*
******************************************************************************/
uint16_t gpio_in_read(uint16_t gpio_number)
{
    uint32_t pos;
    uint16_t level = 0U;

    pos = gpio_number;

    if (pos < WORD_SIZE)
    {
        if (GPIODATA->GPADAT & ((uint32_t)GPxDAT_Msk << pos))
        {
            level = GPIO_PIN_H;
        }
        else
        {
            level = GPIO_PIN_L;
        }
    }
    else if (pos < LONG_WORD_SIZE)
    {
        pos -= WORD_SIZE;

        if (GPIODATA->GPBDAT & ((uint32_t)GPxDAT_Msk << pos))
        {
            level = GPIO_PIN_H;
        }
        else
        {
            level = GPIO_PIN_L;
        }
    }
    else
    {
        level = GPIO_PIN_L;
    }
    return level;
}


/******************************************************************************
* Function     : gpio_peripheral_config 
*
* Purpose      : 
* Configures a GPIO pin for an alternate function mode.
*
* Inputs       :
*   signal  –   Pointer to a 'gpio_peripheral_t' structure that contains the 
*               information of gpio pin number and and mux position.
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
void gpio_peripheral_config(gpio_peripheral_t * signal)
{
    uint32_t pos = signal->gpio_number;
    uint16_t gmux = (signal->mux_position>>GPxMUX_GPIOy_POS) & GPxMUX_GPIOy_Msk;
    uint16_t mux = signal->mux_position & GPxMUX_GPIOy_Msk;
    EALLOW;
    if (signal->gpio_number == GPIO20 || signal->gpio_number == GPIO21)
    {
        GPIOCTRL->GPAAMSEL &= ~((uint32_t)GPAAMSEL_GPIOy_Msk<<signal->gpio_number);
    }

    if (pos < WORD_SIZE)
    {
        if (pos < HALF_WORD_SIZE)
        {
            GPIOCTRL->GPAMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAGMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAGMUX1 |= ((uint32_t)gmux<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAMUX1 |= ((uint32_t)mux<<(pos*GPxMUX_GPIOy_SIZE));
        }
        else
        {
            GPIOCTRL->GPAMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAGMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAGMUX2 |= ((uint32_t)gmux<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAMUX2 |= ((uint32_t)mux<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
        }
    }
    else if (pos < LONG_WORD_SIZE)
    {
        pos -= WORD_SIZE;
        if (pos < HALF_WORD_SIZE)
        {
            GPIOCTRL->GPBMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBGMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBGMUX1 |= ((uint32_t)gmux<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBMUX1 |= ((uint32_t)mux<<(pos*GPxMUX_GPIOy_SIZE));
        }
        else
        {
            GPIOCTRL->GPBMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBGMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBGMUX2 |= ((uint32_t)gmux<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBMUX2 |= ((uint32_t)mux<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
        }
    }
    EDIS;

}

/******************************************************************************
* Function     : gpio_out_config 
*
* Purpose      : 
* Configures a gpio pin as an output pin.
*
* Inputs       :
*   signal  –   Pointer to a 'gpio_out_t' structure that contains the 
*               information of gpio pin number.
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
void gpio_out_config(gpio_out_t * signal)
{
    
    uint32_t pos = signal->gpio_number;
    gpio_out_update(signal);
    
    EALLOW;
    if (signal->gpio_number == GPIO20 || signal->gpio_number == GPIO21)
    {
        GPIOCTRL->GPAAMSEL &= ((uint32_t)GPAAMSEL_GPIOy_Msk<<signal->gpio_number);
    }

    if (pos < WORD_SIZE)
    {
        GPIOCTRL->GPAPUD |= ((uint32_t)GPxPUD_GPIOy_Msk<<pos);
        GPIOCTRL->GPADIR |= ((uint32_t)GPxDIR_GPIOy_Msk<<pos);

        if (pos < HALF_WORD_SIZE)
        {
            GPIOCTRL->GPAMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAGMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
        }
        else
        {
            GPIOCTRL->GPAMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAGMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
        }

    }
    else if (pos < LONG_WORD_SIZE)
    {
        pos -= WORD_SIZE;

        GPIOCTRL->GPBPUD |= ((uint32_t)GPxPUD_GPIOy_Msk<<pos);
        GPIOCTRL->GPBDIR |= ((uint32_t)GPxDIR_GPIOy_Msk<<pos);

        if (pos < HALF_WORD_SIZE)
        {
            GPIOCTRL->GPBMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBGMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
        }
        else
        {
            GPIOCTRL->GPBMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBGMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
        }
    }
    EDIS;

}

/******************************************************************************
* Function     : gpio_in_config 
*
* Purpose      : 
* Configures a gpio pin as an input pin.
*
* Inputs       :
*   signal  –   Pointer to a 'gpio_in_t' structure that contains the 
*               information of gpio pin number.
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
void gpio_in_config(gpio_in_t * signal)
{
    uint32_t pos = signal->gpio_number;

    EALLOW;
    if (signal->gpio_number == GPIO22 || signal->gpio_number == GPIO23)
    {
        GPIOCTRL->GPAAMSEL &= ~((uint32_t)GPAAMSEL_GPIOy_Msk<<signal->gpio_number);
    }

    if (pos < WORD_SIZE)
    {
        GPIOCTRL->GPAPUD &= ~((uint32_t)GPxPUD_GPIOy_Msk<<pos);
        GPIOCTRL->GPADIR &= ~((uint32_t)GPxDIR_GPIOy_Msk<<pos);

        if (pos < HALF_WORD_SIZE)
        {
            GPIOCTRL->GPAQSEL1 &= ~ ((uint32_t)GPxQSEL_GPIOy_Msk<<(pos*GPxQSEL_GPIOy_SIZE));
            GPIOCTRL->GPAMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAGMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
        }
        else
        {
            GPIOCTRL->GPAQSEL1 &= ~((uint32_t)GPxQSEL_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxQSEL_GPIOy_SIZE));
            GPIOCTRL->GPAMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPAGMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
        }
    }
    else if (pos < LONG_WORD_SIZE)
    {
        pos -= WORD_SIZE;

        GPIOCTRL->GPBPUD &= ~((uint32_t)GPxPUD_GPIOy_Msk<<pos);
        GPIOCTRL->GPBDIR &= ~((uint32_t)GPxDIR_GPIOy_Msk<<pos);

        if (pos < HALF_WORD_SIZE)
        {
            GPIOCTRL->GPBQSEL1 &= ~ ((uint32_t)GPxQSEL_GPIOy_Msk<<(pos*GPxQSEL_GPIOy_SIZE));
            GPIOCTRL->GPBMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBGMUX1 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<(pos*GPxMUX_GPIOy_SIZE));
        }
        else
        {
            GPIOCTRL->GPBQSEL1 &= ~((uint32_t)GPxQSEL_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxQSEL_GPIOy_SIZE));
            GPIOCTRL->GPBMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
            GPIOCTRL->GPBGMUX2 &= ~((uint32_t)GPxMUX_GPIOy_Msk<<((pos - HALF_WORD_SIZE)*GPxMUX_GPIOy_SIZE));
        }
    }
    EDIS;

}

/*************** End of C File ************************************************/ 

