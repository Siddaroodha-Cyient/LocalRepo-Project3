/***********************************************************************************************
* File: HAL_GPIO.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for GPIO peripherals
*
* Purpose :
* HAL-level interface for GPIO peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for GPIO peripherals.
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
#ifndef HAL_GPIO_H
#define HAL_GPIO_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <BSP_GPIO.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef struct{
    gpio_out_t DigitalOUT;
    gpio_out_t NetR33A_1;
    gpio_out_t INVERTER_EN;
    gpio_out_t STATUS_LEDA;
    gpio_out_t NetR18A_1;
} gpio_out_channels_t;

typedef struct{
    gpio_in_t NetR41A_1;
    gpio_in_t CAN_ID_0_PIN;
    gpio_in_t CAN_ID_1_PIN;
    gpio_in_t CAN_ID_2_PIN;
    gpio_in_t CAN_ID_3_PIN;
    gpio_in_t BOOT_SEL_0;
    gpio_in_t DIGITAL_IN_1_PIN;
    gpio_in_t DIGITAL_IN_2_PIN;
    gpio_in_t BOOT_SEL_1;
    gpio_in_t FAULT_IN_PINA;
} gpio_in_channels_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void read_gpio_inp(void);
void update_gpio_out(void);
void gpio_init(void);
void gpio_in_debounce(gpio_in_t *signal);
gpio_out_channels_t* gpio_out_channel_get(void);
const gpio_in_channels_t* gpio_in_channel_get(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define GPIO_OUTPUT_LOW          (0U)
#define GPIO_OUTPUT_HIGH         (1U)


#endif /* HAL_GPIO_H */
/****************************************************************************** 
* End of File 
******************************************************************************/
