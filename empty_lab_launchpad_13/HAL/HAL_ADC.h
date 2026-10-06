/***********************************************************************************************
* File: HAL_ADC.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for ADC peripherals
*
* Purpose :
* HAL-level interface for ADC peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for ADC peripherals.
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
#ifndef HAL_ADC_H
#define HAL_ADC_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <BSP_ADC.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef struct{
    adc_channel_struct_t Line_A_Vol_A2;
    adc_channel_struct_t Line_A_Curr_A0;
    adc_channel_struct_t HALL_A_A4;
    adc_channel_struct_t MOTOR_TEMP_1_A6;
    adc_channel_struct_t COM_LVDT_POSITION_A15; 
    adc_channel_struct_t VCC_33_A1;
    adc_channel_struct_t Line_B_Vol_B2; 
    adc_channel_struct_t Line_B_Curr_B0;        
    adc_channel_struct_t HALL_B_B4;      
    adc_channel_struct_t MOTOR_TEMP_2_B5;
    adc_channel_struct_t DC_Bus_V_B3;    
    adc_channel_struct_t HS_TEMP_1_B1;   
    adc_channel_struct_t HS_TEMP_2_B11;  
    adc_channel_struct_t Line_C_Vol_C2;   
    adc_channel_struct_t Line_C_Curr_C0;   
    adc_channel_struct_t HALL_C_C4;        
    adc_channel_struct_t DIE_TEMP_C1;      
    adc_channel_struct_t DC_Bus_Current_C3;
    adc_channel_struct_t internal_temperature;
} adc_channels_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
int16_t adc_get_result(adc_channel_struct_t *channel);
uint16_t Hal_GetInternalTemperature(void);
void adc_update_channel_data(void);
void adc_init(void);
adc_channels_t* adc_channel_get(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/

#define ADC_TEMP_SLOPE_ADDR           (0x701CAU) /*  temperature slope       */
#define ADC_TEMP_OFFSET_ADDR          (0x701CBU) /*  temperature offset      */
#define ADC_REF_VOLTAGE               (3.3F)     /* Internal reference voltage  */
#define ADC_SCALING_FACTOR            (2.5F)     /* ADC scaling factor          */
#define ADC_RESOLUTION                (4096U)    /* 12-bit ADC scale            */
#define ADC_TEMP_SENSOR_INDEX_OFFSET  (1U)       /* Last channel offset */
#endif/*HAL_ADC_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
