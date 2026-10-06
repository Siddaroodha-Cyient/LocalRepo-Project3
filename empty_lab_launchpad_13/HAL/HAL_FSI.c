/***********************************************************************************************
* File: HAL_FSI.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for FSI peripherals
*
* Purpose :
* HAL-level interface for FSI peripherals.
*
* Description:
* This file provides a standardized API for interacting with Fast Serial Interface (FSI), 
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
* - HAL_FSI.h 
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
#include "HAL_FSI.h"


/****************************************************************************** 
* Module Global Definitions
******************************************************************************/
fsi_data_dma_str_t fsi_data_dma_rx;
#pragma DATA_SECTION(fsi_data_dma_rx, "ramgs0")

fsi_data_dma_str_t fsi_data_dma_tx;
#pragma DATA_SECTION(fsi_data_dma_tx, "ramgs0")

uint16_t tag = 0;
#pragma DATA_SECTION(tag, "ramgs0")

fsi_struct_t fsi_struct = {
    .tx = { 
        .clk =  {   .gpio_number = 7, .mux_position = 9 },
        .d0 =   {   .gpio_number = 6, .mux_position = 9 }
    },
    .rx = {
        .clk =  {   .gpio_number = 33, .mux_position = 9 },
        .d0 =   {   .gpio_number = 32, .mux_position = 9 }
    }
};

fsi_dma_struct_t fsi_dma_struct = {
    .tx = { 
        .clk =  {   .gpio_number = 7, .mux_position = 9 },
        .d0 =   {   .gpio_number = 6, .mux_position = 9 }
    },
    .rx = {
        .clk =  {   .gpio_number = 33, .mux_position = 9 },
        .d0 =   {   .gpio_number = 32, .mux_position = 9 }
    },
    .dma_rx = {
        .burst_size = 16,
        .channel_no = 1,
        .trigger_source = 125,
        .src_add = (uint32_t)FSI_RX->RX_BUF_BASE,
        .des_add = (uint32_t)&fsi_data_dma_rx,
    },
    .dma_tx_data = {
        .burst_size = 16,
        .channel_no = 2,
        .trigger_source = 0,
        .src_add = (uint32_t)&fsi_data_dma_tx,
        .des_add = (uint32_t)FSI_TX->TX_BUF_BASE,
    },
    .dma_tx_tag = {
        .burst_size = 1,
        .channel_no = 3,
        .trigger_source = 0,
        .src_add = (uint32_t)&tag,
        .des_add = (uint32_t)&FSI_TX->TX_FRAME_TAG_UDATA,
    },

};


/******************************************************************************
* Function     : fsi_init
*
* Purpose      : 
* Initializes FSI transmitter and receiver.
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
* Configures FSI TX and RX GPIOs, initializes FSI modules, flushes the
* transmit buffer, and sets default transmit data values.
*
******************************************************************************/

void fsi_init(void)
{
    /* Configure GPIO pins for FSI TX and RX (clock and data lines) */
    gpio_peripheral_config(&fsi_struct.tx.clk);
    gpio_peripheral_config(&fsi_struct.tx.d0);
    gpio_peripheral_config(&fsi_struct.rx.clk);
    gpio_peripheral_config(&fsi_struct.rx.d0);

    /* Initialize FSI RX with 10 words */
    fsi_rx_init(FSI_RX_WORD_COUNT);
    /* Initialize FSI TX with target clock (10 MHz) */
    fsi_tx_init(FSI_TX_CLK_FREQUENCY);
    /* Flush TX buffer to start in clean state */
    fsi_tx_flush();

    /* Initialize TX buffer with test pattern data */
    fsi_struct.data_tx.byte_0 = 0;
    fsi_struct.data_tx.byte_1 = 0xAA;
    fsi_struct.data_tx.byte_2 = 0x01;
    fsi_struct.data_tx.byte_3 = 0xFF;
    fsi_struct.data_tx.byte_4 = 0x02;
    fsi_struct.data_tx.byte_5 = 0xFF;
    fsi_struct.data_tx.byte_6 = 0x03;
    fsi_struct.data_tx.byte_7 = 0xFF;
    fsi_struct.data_tx.byte_8 = 0x04;
    fsi_struct.data_tx.byte_9 = 0xFF;
    fsi_struct.data_tx.byte_10 = 0x05;
    fsi_struct.data_tx.byte_11 = 0xFF;
    fsi_struct.data_tx.byte_12 = 0x06;
    fsi_struct.data_tx.byte_13 = 0xFF;
    fsi_struct.data_tx.byte_14 = 0x07;
    fsi_struct.data_tx.byte_15 = 0xFF;
    fsi_struct.data_tx.byte_16 = 0x08;
    fsi_struct.data_tx.byte_17 = 0xFF;
    fsi_struct.data_tx.byte_18 = 0x09;
    fsi_struct.data_tx.byte_19 = 0xFF;
}

/******************************************************************************
* Function     : fsi_dma_init
*
* Purpose      : 
* Initializes FSI modules with DMA support.
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
* Configures FSI TX and RX GPIOs, initializes FSI modules, and sets up
* DMA channels for FSI data transmission and reception.
*
******************************************************************************/
void fsi_dma_init(void)
{
    /* Configure GPIO pins for FSI TX/RX (clock and data lines) */
    gpio_peripheral_config(&fsi_dma_struct.tx.clk);
    gpio_peripheral_config(&fsi_dma_struct.tx.d0);
    gpio_peripheral_config(&fsi_dma_struct.rx.clk);
    gpio_peripheral_config(&fsi_dma_struct.rx.d0);

    /* Initialize FSI RX (16-word frame) and TX clock (10 MHz) */
    fsi_rx_init(FSI_RX_DMA_WORD_COUNT);
    fsi_tx_init(FSI_TX_DMA_FREQ);

    /* Configure DMA channels for FSI RX and TX (data + tag) */
    dma_config(&fsi_dma_struct.dma_rx);
    dma_config(&fsi_dma_struct.dma_tx_data);
    dma_config(&fsi_dma_struct.dma_tx_tag);

    /* Enable DMA for FSI RX and TX paths */
    fsi_rx_dma_enable();
    fsi_tx_dma_enable();
    
    /* Flush TX buffer to ensure clean start */
    fsi_tx_flush();

    /* Initialize TX buffer with test pattern (alternating data and 0xFF) */
    fsi_data_dma_tx.byte_0 = 0;
    fsi_data_dma_tx.byte_1 = 0xAA;
    fsi_data_dma_tx.byte_2 = 0x01;
    fsi_data_dma_tx.byte_3 = 0xFF;
    fsi_data_dma_tx.byte_4 = 0x02;
    fsi_data_dma_tx.byte_5 = 0xFF;
    fsi_data_dma_tx.byte_6 = 0x03;
    fsi_data_dma_tx.byte_7 = 0xFF;
    fsi_data_dma_tx.byte_8 = 0x04;
    fsi_data_dma_tx.byte_9 = 0xFF;
    fsi_data_dma_tx.byte_10 = 0x05;
    fsi_data_dma_tx.byte_11 = 0xFF;
    fsi_data_dma_tx.byte_12 = 0x06;
    fsi_data_dma_tx.byte_13 = 0xFF;
    fsi_data_dma_tx.byte_14 = 0x07;
    fsi_data_dma_tx.byte_15 = 0xFF;
    fsi_data_dma_tx.byte_16 = 0x08;
    fsi_data_dma_tx.byte_17 = 0xFF;
    fsi_data_dma_tx.byte_18 = 0x09;
    fsi_data_dma_tx.byte_19 = 0xFF;

    /* Configure FSI data frame size (16 words) */
    fsi_config_data_frame(FSI_BUFFER_SIZE);
}

/******************************************************************************
* Function     : fsi_send_data
*
* Purpose      : 
* Updates transmit data and sends a data frame using the FSI transmitter.
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

void fsi_send_data(void)
{
    fsi_tx_str_t str;
    fsi_struct.data_tx.byte_0++;

    str.frame_tag = 0;
    str.user_data = 0;
    /* number of words in frame */
    str.no_of_words = FSI_TX_WORD_COUNT;
    /* Select frame type as data frame */
    str.frame_type = fsi_frame_type_data;
    str.data = (uint16_t *)&fsi_struct.data_tx;
    /* Trigger FSI transmission */
    fsi_send(&str);
}

/******************************************************************************
* Function     : fsi_receive_data
*
* Purpose      : 
* Checks for received FSI data frame and retrieves the data.
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
void fsi_receive_data(void)
{
    /* Check if new FSI data frame is received */
    if (fsi_is_data_frame_received() == 0)
    {
        return;
    }
    /* Read received data into RX buffer */
    fsi_receive((uint16_t *)&fsi_struct.data_rx, FSI_RX_WORD_COUNT);
}

/******************************************************************************
* Function     : fsi_dma_send
*
* Purpose      : 
* Triggers DMA transfer for FSI data transmission.
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
void fsi_dma_send(void)
{
    fsi_data_dma_tx.byte_0++;
    fsi_data_dma_tx.byte_1 = fsi_data_dma_rx.byte_1 + 1;
    dma_force_trigger(DMA_CH_2);
    dma_force_trigger(DMA_CH_3);

}

/******************************************************************************
* Function     : fsi_dma_rx_data_get 
*
* Purpose      : 
* Provides read-only access to the FSI DMA RX data structure.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  Pointer to FSI DMA RX data structure (const fsi_data_dma_str_t*).
*
* Requirements : 
*
* Notes        : 
*
******************************************************************************/
fsi_data_dma_str_t* fsi_dma_rx_data_get(void)
{
    return &fsi_data_dma_rx;
}

/*************** End of C File ************************************************/ 


