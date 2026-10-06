/***********************************************************************************************
* File: HAL_SPIB_ENCODER.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for SPI peripherals
*
* Purpose :
* HAL-level interface for SPI peripherals.
*
* Description:
* This file provides a standardized API for interacting with Serial Peripheral Interface (SPI), 
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
* - HAL_SPIB_ENCODER.h 
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
#include "HAL_SPIB_ENCODER.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
spi_channel_t spi_channel_b = {
    .spi_str = {
        .SPI = SPIB,    .frequency  = 2000000,   .clk_scheme = rising_edge_with_delay,
    },
    .simo = {   .gpio_number = 24,  .mux_position = 6},
    .somi = {   .gpio_number = 16,  .mux_position = 14},
    .clk =  {   .gpio_number = 22,  .mux_position = 6},
    .ste =  {   .gpio_number = 40,  .out_level = 1},
};

encoder_data_t encoder_data;

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : encoder_spib_process
*
* Purpose      :
* Processes the encoder over SPIB. Performs reset if requested; otherwise reads 
* encoder turns data.
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
void encoder_spib_process(void)
{
    #if 0
    static uint16_t cnt = 0;
    /* Check if new data is received and read it */
    spi_send_byte(spi_channel_b.spi_str.SPI, cnt);
    
    /* Check if new data is received and read it */
    if (spi_check_new_data(spi_channel_b.spi_str.SPI))
    {
        spi_channel_b.rx_data = spi_receive_byte(spi_channel_b.spi_str.SPI);
    }
    cnt++;
    if (cnt > SPI_COUNTER_MAX)
    {
        cnt = 0;
    }
    #endif
    if (encoder_data.reset)
    {
        encoder_data.reset = 0;
        encoder_spib_reset();
    }    
    else
    {
        encoder_spib_read_turns(&encoder_data);
    }
}

/******************************************************************************
* Function     : encoder_spib_cs_enable
*
* Purpose      : 
* Enables the SPIB chip select signal for Encoder.
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
void encoder_spib_cs_enable(void)
{
    spi_channel_b.ste.out_level = 0;
    gpio_out_update(&spi_channel_b.ste);
}

/******************************************************************************
* Function     : encoder_spib_cs_disable
*
* Purpose      : 
* Disables the SPIB chip select signal for Encoder.
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
void encoder_spib_cs_disable(void)
{
    spi_channel_b.ste.out_level = 1;
    gpio_out_update(&spi_channel_b.ste);
}

/******************************************************************************
* Function     : encoder_spib_reset
*
* Purpose      : 
* Resets the encoder by sending a command sequence over SPIB.
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
void encoder_spib_reset(void)
{
    encoder_spib_cs_enable();
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #60 || NOP");          
    spi_send_byte(spi_channel_b.spi_str.SPI, 0x00);
    while(!spi_check_new_data(spi_channel_b.spi_str.SPI));
    spi_receive_byte(spi_channel_b.spi_str.SPI);
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #60 || NOP");          
    spi_send_byte(spi_channel_b.spi_str.SPI, 0x60);
    while(!spi_check_new_data(spi_channel_b.spi_str.SPI));
    spi_receive_byte(spi_channel_b.spi_str.SPI);
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #120 || NOP");          
    encoder_spib_cs_disable();
}

/******************************************************************************
* Function     : encoder_spib_read_position
*
* Purpose      : Reads encoder position data over SPIB.
* 
* Inputs       :
*  str - Pointer to encoder_data_t structure to store position data.
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
void encoder_spib_read_position(encoder_data_t * str)
{
    uint16_t pos[2];
    encoder_spib_cs_enable();
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #60 || NOP");          
    spi_send_byte(spi_channel_b.spi_str.SPI, 0x00);
    while(!spi_check_new_data(spi_channel_b.spi_str.SPI));
    pos[0] = spi_receive_byte(spi_channel_b.spi_str.SPI);
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #60 || NOP");          
    spi_send_byte(spi_channel_b.spi_str.SPI, 0x00);
    while(!spi_check_new_data(spi_channel_b.spi_str.SPI));
    pos[1] = spi_receive_byte(spi_channel_b.spi_str.SPI);
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #120 || NOP");          
    encoder_spib_cs_disable();
    str->position = ((pos[0] & 0x3F)<<8) | (pos[1] & 0xFF);
}

/******************************************************************************
* Function     : encoder_spib_read_turns
*
* Purpose      : Reads encoder turns data over SPIB.
* 
* Inputs       :
*  str - Pointer to encoder_data_t structure to store turns data.
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
void encoder_spib_read_turns(encoder_data_t * str)
{
    uint16_t turns_raw;
    uint16_t temp[2];
    encoder_spib_cs_enable();
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #60 || NOP");          
    spi_send_byte(spi_channel_b.spi_str.SPI, 0x00);
    while(!spi_check_new_data(spi_channel_b.spi_str.SPI));
    temp[0] = spi_receive_byte(spi_channel_b.spi_str.SPI);
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #60 || NOP");          
    spi_send_byte(spi_channel_b.spi_str.SPI, 0xA0);
    while(!spi_check_new_data(spi_channel_b.spi_str.SPI));
    temp[1] = spi_receive_byte(spi_channel_b.spi_str.SPI);
    str->position = ((temp[0] & 0x3F)<<8) | (temp[1] & 0xFF);

    __asm(" RPT #240 || NOP");          
    __asm(" RPT #60 || NOP");          
    spi_send_byte(spi_channel_b.spi_str.SPI, 0x00);
    while(!spi_check_new_data(spi_channel_b.spi_str.SPI));
    temp[0] = spi_receive_byte(spi_channel_b.spi_str.SPI);
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #60 || NOP");          
    spi_send_byte(spi_channel_b.spi_str.SPI, 0x00);
    while(!spi_check_new_data(spi_channel_b.spi_str.SPI));
    temp[1] = spi_receive_byte(spi_channel_b.spi_str.SPI);
    __asm(" RPT #240 || NOP");          
    __asm(" RPT #120 || NOP");          
    encoder_spib_cs_disable();
    turns_raw = ((temp[0] & 0x3F)<<8) | (temp[1] & 0xFF);
    str->turns = turns_raw;
    if (str->turns > 0x1FFF)
    {
        str->turns = str->turns - 0x4000;
    }
}

/******************************************************************************
* Function     : spib_channel_get 
*
* Purpose      : 
* Provides access to the SPIB channel structure.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to SPIB channel structure (spi_channel_t*).
*
* Requirements: 
*
* Notes        : 
*
******************************************************************************/
spi_channel_t* spib_channel_get(void)
{
    return &spi_channel_b;
}

/******************************************************************************
* Function     : encoder_spib_init 
*
* Purpose      : 
* Initializes SPIB interface and configures GPIOs for encoder communication.
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
void encoder_spib_init(void)
{
    /* Configure GPIO pins for SPI (clock, MOSI, MISO signals) */
    gpio_out_config(&spi_channel_b.ste);
    gpio_peripheral_config(&spi_channel_b.clk);
    gpio_peripheral_config(&spi_channel_b.simo);
    gpio_peripheral_config(&spi_channel_b.somi);

    /* Configure the SPI peripheral*/
    spi_config(&spi_channel_b.spi_str);
}

/*************** End of C File ************************************************/

