/***********************************************************************************************
* File: HAL_GPIO.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for GPIO peripherals
*
* Purpose :
* HAL-level interface for GPIO peripherals.
*
* Description:
* This file provides a standardized API for interacting with General Purpose Input/Output (GPIO),
* abstracting the specific register-level operations of the underlying MCU. 
*
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
* - HAL_GPIO.h 
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
#include "HAL_GPIO.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
gpio_in_channels_t gpio_in_channels = {
    .NetR41A_1         = { .gpio_number = 17,  .debounce_cycles = 3  },
    .CAN_ID_0_PIN      = { .gpio_number = 25,  .debounce_cycles = 3  },
    .CAN_ID_1_PIN      = { .gpio_number = 26,  .debounce_cycles = 3  },
    .CAN_ID_2_PIN      = { .gpio_number = 27,  .debounce_cycles = 3  },
    .CAN_ID_3_PIN      = { .gpio_number = 43,  .debounce_cycles = 3  },  
    .BOOT_SEL_0        = { .gpio_number = 42,  .debounce_cycles = 3  }, 
    .DIGITAL_IN_1_PIN  = { .gpio_number = 40,  .debounce_cycles = 3  },
    .DIGITAL_IN_2_PIN  = { .gpio_number = 41,  .debounce_cycles = 3  },
    .BOOT_SEL_1        = { .gpio_number = 44,  .debounce_cycles = 3  },
    .FAULT_IN_PINA     = { .gpio_number = 9,   .debounce_cycles = 3  },
};

gpio_out_channels_t gpio_out_channels = {
    .DigitalOUT   = { .gpio_number = 46,  .out_level = 0  }, 
    .NetR33A_1    = { .gpio_number = 11,  .out_level = 0  },
    .INVERTER_EN  = { .gpio_number = 45,  .out_level = 1  }, 
    .STATUS_LEDA  = { .gpio_number = 34,  .out_level = 0  },
    .NetR18A_1    = { .gpio_number = 6,   .out_level = 0  },
};

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : update_gpio_out 
*
* Purpose      : 
* Updates the state of GPIO output pins.
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
* Requirements: 
*
* Notes        : 
*
******************************************************************************/
#if 1
void update_gpio_out(void)
{
    int i;
    static uint16_t output = 0;
    gpio_out_t * channel = (gpio_out_t *)&gpio_out_channels;

    if (output == GPIO_OUTPUT_LOW)
    {
        output = GPIO_OUTPUT_HIGH;
    }
    else
    {
        output = GPIO_OUTPUT_LOW;
    }

    for (i = 0; i < sizeof(gpio_out_channels_t)/sizeof(gpio_out_t); i++)
    {
        (channel+i)->out_level = output;
        gpio_out_update(channel+i);
    }

}
#else
void update_gpio_out(uint16_t gpio_number, uint16_t out_val )
{
    gpio_out_t * channel = (gpio_out_t *)&gpio_out_channels;
    channel->gpio_number   = gpio_number;
    channel->out_level  = out_val;
    gpio_out_update(channel);
}
#endif


/******************************************************************************
* Function     : gpio_in_debounce
*
* Purpose      : 
* Applies debounce logic to the input GPIO signal.
*
* Inputs       :
*  signal - Pointer to gpio_in_t structure containing GPIO input
*           configuration and debounce parameters.
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

void gpio_in_debounce(gpio_in_t *signal)
{
    uint16_t raw_level;

    /* Read current raw GPIO input level */
    raw_level = gpio_in_read(signal->gpio_number);

    /* Check if current sample matches previous raw level */
    if (raw_level == signal->prev_raw_level)
    {
        /* Increment debounce counter until threshold is reached */
        if (signal->debounce_cnt < signal->debounce_cycles)
        {
            signal->debounce_cnt++;
        }
        /* Update debounced output once signal is stable */
        if (signal->debounce_cnt >= signal->debounce_cycles)
        {
            signal->in_level = raw_level;
        }
    }
    else
    {
        /* Detected change: update previous raw level */
        signal->prev_raw_level = raw_level;
        /* Reset debounce counter */
        signal->debounce_cnt = 1U;
    }
}

/******************************************************************************
* Function     : read_gpio_inp 
*
* Purpose      : 
* Reads and updates all configured GPIO input signals.
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
* Side Effects : TBD
*
* Assumptions  : TBD
*
******************************************************************************/
#if 1
void read_gpio_inp(void)
{
    int i;
    for (i = 0; i < sizeof(gpio_in_channels_t)/sizeof(gpio_in_t); i++)
    {
        gpio_in_debounce(((gpio_in_t *)&gpio_in_channels) + i);
    }

}
#else 
void read_gpio_inp(uint16_t gpio_number )
{
    gpio_in_t * channel  = (gpio_in_t *)&gpio_in_channels;
    channel->gpio_number = gpio_number;
    gpio_in_debounce(channel);
}
#endif

/******************************************************************************
* Function     : gpio_out_channel_get 
*
* Purpose      : 
* Provides access to the GPIO output channel structure.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to gpio output channel structure.
*
* Requirements : 
*
* Notes        : 
*
******************************************************************************/
gpio_out_channels_t* gpio_out_channel_get(void)
{
    return &gpio_out_channels;
}

/******************************************************************************
* Function     : gpio_in_channel_get 
*
* Purpose      : 
* Provides read-only access to the GPIO input channel structure.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to gpio input channel structure (const gpio_in_channels_t*).
*
* Requirements : 
*
* Notes        : 
*
******************************************************************************/
const gpio_in_channels_t* gpio_in_channel_get(void)
{
    return &gpio_in_channels;
}
/******************************************************************************
* Function     : gpio_init
*
* Purpose      : 
* Initializes all configured GPIO input and output channels.
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

void gpio_init(void)
{
    int i,j;
    for (i = 0; i < sizeof(gpio_out_channels_t)/sizeof(gpio_out_t); i++)
    {
        gpio_out_config(((gpio_out_t *)&gpio_out_channels) + i);
    }
    for (j = 0; j< sizeof(gpio_in_channels_t)/sizeof(gpio_in_t); j++)
    {
        gpio_in_config(((gpio_in_t *)&gpio_in_channels) + j);
    }
}
/*************** End of C File ************************************************/ 

