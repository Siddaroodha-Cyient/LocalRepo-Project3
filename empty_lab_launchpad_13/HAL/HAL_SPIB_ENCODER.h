/***********************************************************************************************
* File: HAL_SPIB_ENCODER.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for SPIB ENCODER peripherals
*
* Purpose :
* HAL-level interface for SPIB ENCODER peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for SPIB ENCODER peripherals.
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
#ifndef HAL_SPI_H
#define HAL_SPI_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <BSP_SPI.h>
#include <BSP_GPIO.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef struct{
    spi_struct_t spi_str;
    gpio_peripheral_t simo;
    gpio_peripheral_t somi;
    gpio_peripheral_t clk;
    gpio_out_t ste;
    uint16_t rx_data;
} spi_channel_t;

typedef struct{
    uint16_t position;
    int16_t turns;
    uint16_t reset;
} encoder_data_t;


/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void encoder_spib_init(void);
void encoder_spib_process(void);
void encoder_spib_cs_enable(void);
void encoder_spib_cs_disable(void);
void encoder_spib_reset(void);
void encoder_spib_read_position(encoder_data_t * str);
void encoder_spib_read_turns(encoder_data_t * str);
spi_channel_t* spib_channel_get(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define SPI_COUNTER_MAX        (255U)

#endif /* HAL_SPI_H */
/****************************************************************************** 
* End of File 
******************************************************************************/
