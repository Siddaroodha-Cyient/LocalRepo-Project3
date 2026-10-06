/***********************************************************************************************
* File: HAL_ADC.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for ADC peripherals
*
* Purpose :
* HAL-level interface for ADC peripherals.
*
* Description:
* This file provides a standardized API for interacting with Analog‑to‑Digital Converter (ADC), 
* abstracting the specific register-level operations of the underlying MCU. 
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
* - HAL_ADC.h 
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
#include "HAL_ADC.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
adc_channels_t adc_channels = {
    .Line_A_Vol_A2              = {.ADC = ADCA, .channel_number = 2, .soc_number = 0, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.0324207f, .offset = 0.0f},
    .Line_A_Curr_A0             = {.ADC = ADCA, .channel_number = 0, .soc_number = 1, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.0161172f, .offset = 33.0f},
    .HALL_A_A4                  = {.ADC = ADCA, .channel_number = 4, .soc_number = 2, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.8056640625f, .offset = 0.0f},
    .MOTOR_TEMP_1_A6            = {.ADC = ADCA, .channel_number = 6, .soc_number = 3, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.8056640625f, .offset = 0.0f},
    .COM_LVDT_POSITION_A15      = {.ADC = ADCA, .channel_number = 15, .soc_number = 4, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3, .scale = 0.8056640625f, .offset = 0.0f},  /* Pin not available on 100 pin package*/
    .VCC_33_A1                  = {.ADC = ADCA, .channel_number = 1, .soc_number = 5, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.8056640625f, .offset = 0.0f},

    .Line_B_Vol_B2              = {.ADC = ADCB, .channel_number = 2, .soc_number = 0, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.0324207f, .offset = 0.0f},
    .Line_B_Curr_B0             = {.ADC = ADCB, .channel_number = 0, .soc_number = 1, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.0161172f, .offset = 33.0f},   /* Pin not connected to any connector on the launchpad*/
    .HALL_B_B4                  = {.ADC = ADCB, .channel_number = 4, .soc_number = 2, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.8056640625f, .offset = 0.0f},
    .MOTOR_TEMP_2_B5            = {.ADC = ADCB, .channel_number = 5, .soc_number = 3, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.8056640625f, .offset = 0.0f},
    .DC_Bus_V_B3                = {.ADC = ADCB, .channel_number = 3, .soc_number = 4, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.0169189f, .offset = 0.0f},
    .HS_TEMP_1_B1               = {.ADC = ADCB, .channel_number = 1, .soc_number = 5, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.8056640625f, .offset = 0.0f},
    .HS_TEMP_2_B11              = {.ADC = ADCB, .channel_number = 11, .soc_number = 6, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3, .scale = 0.8056640625f, .offset = 0.0f},

    .Line_C_Vol_C2              = {.ADC = ADCC, .channel_number = 2, .soc_number = 0, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.0324207f, .offset = 0.0f},
    .Line_C_Curr_C0             = {.ADC = ADCC, .channel_number = 0, .soc_number = 1, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.0161172f, .offset = 33.0f},
    .HALL_C_C4                  = {.ADC = ADCC, .channel_number = 4, .soc_number = 2, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.8056640625f, .offset = 0.0f},
    .DIE_TEMP_C1                = {.ADC = ADCC, .channel_number = 1, .soc_number = 3, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.8056640625f, .offset = 0.0f},
    .DC_Bus_Current_C3          = {.ADC = ADCC, .channel_number = 3, .soc_number = 4, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3,  .scale = 0.0161172f, .offset = 33.0f},
    .internal_temperature       = {.ADC = ADCC, .channel_number = 12, .soc_number = 5, .trigger = ADCSOCCTL_TRIGSEL_ADCTRIG3, .scale = 0.8056640625f, .offset = 0.0f},
};


/******************************************************************************
* Function     : Hal_GetInternalTemperature
*
* Purpose      : 
* Reads ADC value and computes the corresponding temperature.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  uint16_t - Calculated temperature value.
*
* Requirements :
*
* Notes        : 
* Retrieves ADC result from the configured temperature channel and
* applies slope and offset calibration to compute the temperature.
*
******************************************************************************/
uint16_t Hal_GetInternalTemperature(void)
{
    float temp;
    uint16_t adc_values;
    uint16_t temp_val;
    uint16_t no_of_channels = sizeof(adc_channels)/sizeof(adc_channel_struct_t);

    /* Read calibration parameters from address */
    int16_t slope = (*(int16_t *)((uint32_t)ADC_TEMP_SLOPE_ADDR));
    int16_t offset = (*(int16_t *)((uint32_t)ADC_TEMP_OFFSET_ADDR));

    /* Get ADC value of temperature channel (last channel) */
    adc_values = get_adc_result(((adc_channel_struct_t *)&adc_channels) + no_of_channels - ADC_TEMP_SENSOR_INDEX_OFFSET);

    /* Convert ADC reading to voltage */
    temp = (adc_values)*ADC_REF_VOLTAGE/ADC_SCALING_FACTOR;
    /* calculate the temperature */
    temp_val = (int16_t)(((int32_t)temp - offset)*ADC_RESOLUTION/slope);
    return temp_val;
}

/******************************************************************************
* Function     : adc_get_result
*
* Purpose      : 
* Returns the ADC result value for the corresponding ADC channel.
*
* Inputs       :
*  channel - Pointer to adc_channel_struct_t containing ADC channel details.
*
* Outputs      :
*  None.
*
* Returns      :
*  int16_t - ADC result.
*
* Requirements :
*
* Notes        :
*
******************************************************************************/

int16_t adc_get_result(adc_channel_struct_t *channel)
{
    return channel->result;
}

/******************************************************************************
* Function     : adc_update_channel_data 
*
* Purpose      : 
* Update scaled ADC results for all configured ADC channels
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
void adc_update_channel_data(void)
{
    uint16_t i;
    uint16_t no_of_channels = sizeof(adc_channels) / sizeof(adc_channel_struct_t);
    adc_channel_struct_t *str;

    /* Iterate through all ADC channels defined in adc_channels */
    for (i = 0U; i < no_of_channels; i++)
    {
        /* Get pointer to current ADC channel structure */
        str = ((adc_channel_struct_t *)&adc_channels) + i;

        /* Read raw ADC conversion result */
        str->raw_adc_value = get_adc_result(str);
        str->result = (int16_t)(str->scale * str->raw_adc_value) - str->offset;
    }
}

/******************************************************************************
* Function     : adc_channel_get 
*
* Purpose      : 
* Provides read-only access to the ADC channel structure.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to adc channel structure (const adc_channels_t*).
*
* Requirements: 
*
* Notes        : 
*
******************************************************************************/
adc_channels_t* adc_channel_get(void)
{
    return &adc_channels;
}

/******************************************************************************
* Function     : adc_init 
*
* Purpose      : 
* Initializes the ADC by powering up the ADC and configuring all
* required ADC channels
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
void adc_init(void)
{
    uint16_t i;
    adc_power_up();
    
    for (i = 0; i < sizeof(adc_channels)/sizeof(adc_channel_struct_t); i++)
    {
        adc_config(((adc_channel_struct_t *)&adc_channels) + i);
    }
}

/*************** End of C File ************************************************/ 

