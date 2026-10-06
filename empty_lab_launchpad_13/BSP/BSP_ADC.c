/***********************************************************************************************
* File: BSP_ADC.c
* Project: 
* Module: Board Support Package (BSP) for ADC peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for ADC peripherals
*
* Description:
* This file contains board-specific driver functions for Analog‑to‑Digital Converter (ADC) with 
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
* - BSP_ADC.h 
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
#include "BSP_ADC.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

#define AQCTLA 99

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : adc_power_up 
*
* Purpose      : 
* Powers up and initializes the ADC peripheral for operation.
*
* Inputs       :
* None.
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
void adc_power_up(void)
{
    uint32_t delay;
    uint16_t * offset;

    EALLOW;
    /* Configure ADC clock prescaler */
    ADCA->ADCCTL2 &= ~ADCCTL2_BITS_PRESCALE_Msk;
    ADCA->ADCCTL2 |= ADCCTL2_PRESCALE_VALUE<<ADCCTL2_BITS_PRESCALE_Pos;       

    ADCB->ADCCTL2 &= ~ADCCTL2_BITS_PRESCALE_Msk;
    ADCB->ADCCTL2 |= ADCCTL2_PRESCALE_VALUE<<ADCCTL2_BITS_PRESCALE_Pos;       
    
    ADCC->ADCCTL2 &= ~ADCCTL2_BITS_PRESCALE_Msk;
    ADCC->ADCCTL2 |= ADCCTL2_PRESCALE_VALUE<<ADCCTL2_BITS_PRESCALE_Pos;       
    
    /* Power up ADC modules */
    ADCA->ADCCTL1 |= ADCCTL1_BITS_ADCPWDNZ;
    ADCB->ADCCTL1 |= ADCCTL1_BITS_ADCPWDNZ;
    ADCC->ADCCTL1 |= ADCCTL1_BITS_ADCPWDNZ;
    
    /* Allow ADC analog circuitry to stabilize */
    for (delay = 0; delay < ADC_STARTUP_DELAY_COUNT; delay++);
    {
        /* Delay loop */
    }
    /* Load ADCA offset trim */
    offset = (uint16_t *)((uint32_t)ADC_OFFSET_TRIM_ADDR_A);
    ADCA->ADCOFFTRIM &= ~ADC_OFFSET_TRIM_Msk;
    ADCA->ADCOFFTRIM |= ((*offset)>>ONE_BYTE_BIT_SIZE) & ADC_OFFSET_TRIM_Msk;

    /* Load ADCB offset trim */
    offset = (uint16_t *)((uint32_t)ADC_OFFSET_TRIM_ADDR_B);
    ADCB->ADCOFFTRIM &= ~ADC_OFFSET_TRIM_Msk;
    ADCB->ADCOFFTRIM |= ((*offset)>>ONE_BYTE_BIT_SIZE) & ADC_OFFSET_TRIM_Msk;
    
    /* Load ADCC offset trim */
    offset = (uint16_t *)((uint32_t)ADC_OFFSET_TRIM_ADDR_C);
    ADCC->ADCOFFTRIM &= ~ADC_OFFSET_TRIM_Msk;
    ADCC->ADCOFFTRIM |= ((*offset)>>ONE_BYTE_BIT_SIZE) & ADC_OFFSET_TRIM_Msk;

    /* internal reference mode with reference of 3.3v*/
    ANALOGSUBSYS->ANAREFCTL = ANALOG_REF_INTERNAL_3V3; 
    /* temperature sensing enabled*/
    ANALOGSUBSYS->TSNSCTL |= TEMP_SENSOR_ENABLE;     
    EDIS;
}

/******************************************************************************
* Function     : adc_config 
*
* Purpose      : 
* Configures the ADC channels for the required conversion operation.
*
* Inputs       :
*   str    -   Pointer to an adc_channel_struct_t structure that contains
*              the ADC module configuration, channel number, SOC number,
*              and trigger source details
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
void adc_config(adc_channel_struct_t * str)
{
    uint32_t * ADCSOCCTL = &str->ADC->ADCSOC0CTL;
    ADCSOCCTL += str->soc_number;

    EALLOW;
    /* Clear existing configuration */
    *ADCSOCCTL &= ~ADCSOCCTL_BITS_TRIGSEL_Msk;
    *ADCSOCCTL &= ~ADCSOCCTL_BITS_CHSEL_Msk;
    *ADCSOCCTL &= ~ADCSOCCTL_BITS_ACQPS_Msk;

    /* Configure trigger source */
    *ADCSOCCTL |= (((uint32_t)str->trigger)<<ADCSOCCTL_BITS_TRIGSEL_Pos) & ADCSOC0CTL_BITS_TRIGSEL_Msk;
    /* Configure ADC channel */
    *ADCSOCCTL |= (((uint32_t)str->channel_number)<<ADCSOCCTL_BITS_CHSEL_Pos) & ADCSOCCTL_BITS_CHSEL_Msk;
    /* Configure acquisition window */
    *ADCSOCCTL |= (AQCTLA<<ADCSOCCTL_BITS_ACQPS_Pos) & ADCSOCCTL_BITS_ACQPS_Msk;

    EDIS;

}

/******************************************************************************
* Function     : get_adc_result 
*
* Purpose      : 
* Updates the ADC conversion result associated with the configured ADC channel.
*
* Inputs       :
*   str    -   Pointer to an adc_channel_struct_t structure that contains
*              ADC channel configuration and storage for the conversion
*              result
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
uint16_t get_adc_result(adc_channel_struct_t * str)
{
    uint16_t * ADCRESULT;
    uint16_t adc_result;

    /* Select ADC result base register */
    if (str->ADC == ADCA)
    {
        ADCRESULT = &ADCARESULT->ADCRESULT0;
    }
    else if (str->ADC == ADCB)
    {
        ADCRESULT = &ADCBRESULT->ADCRESULT0;
    }
    else if (str->ADC == ADCC)
    {
        ADCRESULT = &ADCCRESULT->ADCRESULT0;
    }
    else
    {
        return INVALID_ADC_VAL;
    }
    /* Move to required SOC result */
    ADCRESULT += str->soc_number;
    /* Read ADC result */
    str->raw_adc_value = (*ADCRESULT);
    adc_result = str->raw_adc_value;
    /* Return ADC value */
    return adc_result;
}
/*************** End of C File ************************************************/ 



