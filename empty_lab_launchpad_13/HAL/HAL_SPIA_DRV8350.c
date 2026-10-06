/***********************************************************************************************
* File: HAL_SPIA_DRV8350.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for SPIA DRV8350 peripherals.
*
* Purpose :
* HAL-level interface for SPIA DRV8350 peripherals.
*
* Description:
* This file provides a standardized API for interacting with SPIA DRV8350, abstracting the specific
* register-level operations of the underlying MCU. 
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
* - HAL_SPIA_DRV8350.h 
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
#include "HAL_SPIA_DRV8350.h"
#include "HAL_GPIO.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
spi_channel_t drv8350_spi = {
    .spi_str = {
        .SPI = SPIA,    .frequency  = 1000000,   .clk_scheme = rising_edge_without_delay,
    },
    .simo = {   .gpio_number = 8,  .mux_position = 7},
    .somi = {   .gpio_number = 10,  .mux_position = 7},
    .clk =  {   .gpio_number = 12,  .mux_position = 11},
    .ste = {    .gpio_number = 41, .out_level = 1},
};

drv8350_registers_t drv8350_registers;


/******************************************************************************
* Function     : drv8350_spia_cs_enable
*
* Purpose      : 
* Enables the SPIA chip select signal for DRV8350.
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
void drv8350_spia_cs_enable(void)
{
    drv8350_spi.ste.out_level = GPIO_OUTPUT_LOW;
    gpio_out_update(&drv8350_spi.ste);
}

/******************************************************************************
* Function     : drv8350_spia_cs_disable
*
* Purpose      : 
* Disables the SPIA chip select signal for DRV8350.
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
void drv8350_spia_cs_disable(void)
{
    drv8350_spi.ste.out_level = GPIO_OUTPUT_HIGH;
    gpio_out_update(&drv8350_spi.ste);
}


/******************************************************************************
* Function     : drv8350_spia_read_register
*
* Purpose      : 
* Reads a register value from the DRV8350 device over SPIA.
*
* Inputs       :
*  address - Register address to be read from the DRV8350.
*
* Outputs      :
*  None.
*
* Returns      :
*  uint16_t - Register value read from the specified address.
*
* Requirements :
*
* Notes        :
*
******************************************************************************/

uint16_t drv8350_spia_read_register(drv8350_register_address_t address)
{
    uint16_t out = DRV8350_READ_CMD_BIT;
    uint16_t in = 0;
    out |= (address & DRV8350_ADDR_MASK)<<DRV8350_ADDR_SHIFT;

    /* Enable chip select (start SPI transaction) */
    drv8350_spia_cs_enable();

    /* Send command byte */
    spi_send_byte(drv8350_spi.spi_str.SPI, out);
    /* Wait for first response byte */
    while(!spi_check_new_data(drv8350_spi.spi_str.SPI));
    in |= (spi_receive_byte(drv8350_spi.spi_str.SPI) & SPI_DATA_MASK)<<SPI_HIGH_BYTE_SHIFT;

    spi_send_byte(drv8350_spi.spi_str.SPI, 0);
    while(!spi_check_new_data(drv8350_spi.spi_str.SPI));
    in |= (spi_receive_byte(drv8350_spi.spi_str.SPI) & SPI_DATA_MASK);

    /* Disable chip select (end SPI transaction) */
    drv8350_spia_cs_disable();
    return in;
}


/******************************************************************************
* Function     : drv8350_spia_write_register
*
* Purpose      : 
* Writes data to a register of the DRV8350 device over SPIA.
*
* Inputs       :
*  data    - Data to be written to the register.
*  address - Register address where the data is to be written.
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
void drv8350_spia_write_register(uint16_t data, drv8350_register_address_t address)
{
    uint16_t out = DRV8350_WRITE_CMD_BIT;
    /* Prepare write command (MSB = 0 + address + upper data bits) */
    out |= (address & DRV8350_ADDR_MASK)<<DRV8350_ADDR_SHIFT;
    out |= (data>>SPI_HIGH_BYTE_SHIFT) & DRV8350_DATA_HIGH_MASK;

    /* Enable chip select (start SPI transaction) */
    drv8350_spia_cs_enable();

    /* Send command */
    spi_send_byte(drv8350_spi.spi_str.SPI, out);
    /* Wait for response */
    while(!spi_check_new_data(drv8350_spi.spi_str.SPI));
    spi_receive_byte(drv8350_spi.spi_str.SPI);

    /* Prepare lower 8 bits of data */
    out = data & DRV8350_DATA_LOW_MASK;

    /* Send lower data byte */
    spi_send_byte(drv8350_spi.spi_str.SPI, out);
    /* Wait for response */
    while(!spi_check_new_data(drv8350_spi.spi_str.SPI));
    spi_receive_byte(drv8350_spi.spi_str.SPI);

    /* Disable chip select (end SPI transaction) */
    drv8350_spia_cs_disable();
}


/******************************************************************************
* Function     : drv8350_spia_read_all
*
* Purpose      : 
* Reads all status registers from the DRV8350 device over SPIA.
*
* Inputs       :
*  registers - Pointer to drv8350_registers_t structure containing
*              DRV8350 register details, where the read values will be stored.
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
void drv8350_spia_read_all(drv8350_registers_t * registers)
{
    uint16_t reg_data;
    *((uint16_t *)&registers->fault_status_1) = drv8350_spia_read_register(drv8350_address_fault_status_1);
    reg_data= *((uint16_t *)&registers->fault_status_1);
    *((uint16_t *)&registers->vgs_status_2) = drv8350_spia_read_register(drv8350_address_vgs_status_2);
    *((uint16_t *)&registers->driver_control) = drv8350_spia_read_register(drv8350_address_driver_control);
    *((uint16_t *)&registers->gate_drive_hs) = drv8350_spia_read_register(drv8350_address_gate_drive_hs);
    *((uint16_t *)&registers->gate_drive_ls) = drv8350_spia_read_register(drv8350_address_gate_drive_ls);
    *((uint16_t *)&registers->ocp_control) = drv8350_spia_read_register(drv8350_address_ocp_control);
}

/******************************************************************************
* Function     : drv8350_spia_write_all
*
* Purpose      : 
* Writes all configuration registers to the DRV8350 device over SPIA.
*
* Inputs       :
*  registers - Pointer to drv8350_registers_t structure that contains the
*              register information to be written.
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
* Writes multiple DRV8350 registers sequentially using SPI based on
* the values provided in the structure.
*
******************************************************************************/
void drv8350_spia_write_all(drv8350_registers_t * registers)
{
    drv8350_spia_write_register(*((uint16_t *)&registers->driver_control), drv8350_address_driver_control);
    drv8350_spia_write_register(*((uint16_t *)&registers->gate_drive_hs), drv8350_address_gate_drive_hs);
    drv8350_spia_write_register(*((uint16_t *)&registers->gate_drive_ls), drv8350_address_gate_drive_ls);
    drv8350_spia_write_register(*((uint16_t *)&registers->ocp_control), drv8350_address_ocp_control);
}

/******************************************************************************
* Function     : drv8350_spia_init
*
* Purpose      : 
* Initializes the DRV8350 device and associated SPIA interface.
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
* Configures SPI-related GPIOs, initializes the SPI module, and reads
* initial register values from the DRV8350 device.
*
******************************************************************************/

void drv8350_spia_init(void)
{
    /* Configure SPI GPIO pins (CLK, MOSI, MISO) */
    gpio_peripheral_config(&drv8350_spi.clk);
    gpio_peripheral_config(&drv8350_spi.simo);
    gpio_peripheral_config(&drv8350_spi.somi);

    /* Configure chip select (STE) as GPIO output */
    gpio_out_config(&drv8350_spi.ste);

    /* Initialize SPI peripheral */
    spi_config(&drv8350_spi.spi_str);

    /* Read current DRV8350 register values */
    drv8350_spia_read_all(&drv8350_registers);

    drv8350_registers.fault_status_1.vds_ha=1;
    drv8350_registers.driver_control.dis_gdf=1;
    drv8350_registers.driver_control.brake=1;
    drv8350_registers.gate_drive_hs.idriven_hs=11,
    drv8350_registers.gate_drive_hs.idrivep_hs=11;
    drv8350_registers.gate_drive_ls.idriven_ls=12;
    drv8350_registers.gate_drive_ls.idrivep_ls=12;
    drv8350_registers.ocp_control.vds_lvl=1;
    drv8350_registers.ocp_control.dead_time=0;
    /* Write configuration to DRV8350 registers */
    drv8350_spia_write_all(&drv8350_registers);

    /* Re-read registers to verify written configuration */
    drv8350_spia_read_all(&drv8350_registers);
}

/*************** End of C File ************************************************/



