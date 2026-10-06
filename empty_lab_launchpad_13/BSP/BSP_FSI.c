/***********************************************************************************************
* File: BSP_FSI.c
* Project: 
* Module: Board Support Package (BSP) for FSI peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for FSI peripherals
*
* Description:
* This file contains board-specific driver functions for Fast Serial Interface (FSI) with direct
* interaction to the underlying hardware.
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
* - BSP_FSI.h 
* - HAL_CLOCK.h 
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
#include "BSP_FSI.h"
#include "HAL_CLOCK.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : fsi_tx_init
*
* Purpose      : 
* Initializes the FSI transmitter module.
*
* Inputs       :
*  frequency - Desired FSI transmit clock frequency.
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
void fsi_tx_init(uint32_t frequency)
{
    uint16_t i;
    uint32_t prescalar;
    const clock_struct_t *clk = clock_config_get();
    
    prescalar = clk->pllsysclk_frequency/frequency;
    
    EALLOW;
    FSI_TX->TX_CLK_CTRL |= TX_CLK_CTRL_CLK_RST;
    FSI_TX->TX_CLK_CTRL &= ~TX_CLK_CTRL_CLK_EN;

    FSI_TX->TX_OPER_CTRL_LO |= TX_OPER_CTRL_LO_SEL_PLLCLK;

    /*  10 MHz clock frequency */
    FSI_TX->TX_CLK_CTRL &= ~TX_CLK_CTRL_PRESCALE_VAL_Msk;
    FSI_TX->TX_CLK_CTRL |= ((prescalar << TX_CLK_CTRL_PRESCALE_VAL_Pos) & TX_CLK_CTRL_PRESCALE_VAL_Msk);

    FSI_TX->TX_CLK_CTRL |= TX_CLK_CTRL_CLK_EN;
    FSI_TX->TX_CLK_CTRL &= ~TX_CLK_CTRL_CLK_RST;
    
    /* Configure RX master control (start/config sequence) */
    FSI_TX->TX_MASTER_CTRL = FSI_TX_MASTER_CTRL_START;
    for (i = 0; i < FSI_TX_STARTUP_DELAY_COUNT; i++)
    {
        /* No operation */ 
    }
    /* Clear/start RX operation */
    FSI_TX->TX_MASTER_CTRL = FSI_TX_MASTER_CTRL_CLEAR;
    EDIS;
}

/******************************************************************************
* Function     : fsi_tx_init
*
* Purpose      : 
* Initializes the FSI transmitter module.
*
* Inputs       :
*  frequency - Desired FSI transmit clock frequency.
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
void fsi_rx_init(uint16_t no_of_words)
{
    uint16_t i;
    if (no_of_words == 0)
    {
        return;
    }
    no_of_words -= 1;
    EALLOW;

    /* Configure number of words to be received */
    FSI_RX->RX_OPER_CTRL &= RX_OPER_CTRL_N_WORDS_Msk;
    FSI_RX->RX_OPER_CTRL |= ((no_of_words << RX_OPER_CTRL_N_WORDS_Pos) & RX_OPER_CTRL_N_WORDS_Msk);

    /* Configure RX master control (start/config sequence) */
    FSI_RX->RX_MASTER_CTRL = FSI_RX_MASTER_CTRL_START;
    
    for (i = 0; i < FSI_RX_STARTUP_DELAY_COUNT; i++);
    {
        /* No operation */ 
    }
    /* Clear/start RX operation */
    FSI_RX->RX_MASTER_CTRL = FSI_RX_MASTER_CTRL_CLEAR;

    EDIS;
}


/******************************************************************************
* Function     : fsi_tx_dma_enable
*
* Purpose      : 
* Enables DMA support for FSI transmitter.
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
void fsi_tx_dma_enable(void)
{
    EALLOW;

    /* Enable DMA event generation for FSI TX */
    FSI_TX->TX_DMA_CTRL |= TX_DMA_CTRL_DMA_EVT_EN;
    /* Clear start mode field */
    FSI_TX->TX_OPER_CTRL_LO &= ~TX_OPER_CTRL_LO_START_MODE_Msk;
    /* Configure start mode (trigger mode selection) */
    FSI_TX->TX_OPER_CTRL_LO |= (((uint32_t)TX_OPER_CTRL_LO_START_MODE_VALUE<<TX_OPER_CTRL_LO_START_MODE_Pos) & TX_OPER_CTRL_LO_START_MODE_Msk);
    EDIS;
}

/******************************************************************************
* Function     : fsi_rx_dma_enable
*
* Purpose      : 
* Enables DMA support for FSI receiver.
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
void fsi_rx_dma_enable(void)
{
    EALLOW;
    FSI_RX->RX_DMA_CTRL |= RX_DMA_CTRL_DMA_EVT_EN;
    EDIS;
}

/******************************************************************************
* Function     : fsi_tx_flush
*
* Purpose      : 
* Flushes the FSI transmitter buffer.
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
void fsi_tx_flush(void)
{
    uint16_t i;
    EALLOW;
    FSI_TX->TX_MASTER_CTRL = FSI_TX_MASTER_CTRL_FLUSH;

    for (i = 0; i < FSI_TX_FLUSH_DELAY_COUNT; i++)
    {
        /* No operation */ 
    }
    FSI_TX->TX_MASTER_CTRL = FSI_TX_MASTER_CTRL_CLEAR;
    EDIS;
}

/******************************************************************************
* Function     : fsi_config_data_frame
*
* Purpose      : 
* Configures the FSI data frame type and word length.
*
* Inputs       :
*  no_of_words - Number of words to be configured in the data frame.
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
void fsi_config_data_frame(uint16_t no_of_words)
{
    if (no_of_words == 0)
    {
        return;
    }
    /* Configure frame type as data frame */
    FSI_TX->TX_FRAME_CTRL &= ~TX_FRAME_CTRL_FRAME_TYPE_Msk;
    FSI_TX->TX_FRAME_CTRL |= ((FRAME_TYPE_DATA_N_WORD << TX_FRAME_CTRL_FRAME_TYPE_Pos) & TX_FRAME_CTRL_FRAME_TYPE_Msk);
    no_of_words -= 1;

    /* Limit number of words to 4-bit field */
    no_of_words &= FSI_FRAME_WORD_COUNT_MASK;
    
    /* Configure number of words in frame */
    FSI_TX->TX_FRAME_CTRL &= ~TX_FRAME_CTRL_N_WORDS_Msk;
    FSI_TX->TX_FRAME_CTRL |= (((no_of_words) << TX_FRAME_CTRL_N_WORDS_Pos) & TX_FRAME_CTRL_N_WORDS_Msk);
}

/******************************************************************************
* Function     : fsi_send
*
* Purpose      : 
* Sends an FSI frame based on the configured frame type.
*
* Inputs       :
*  str - Pointer to fsi_tx_str_t structurethat contains the  frame 
*        configuration and data.
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
void fsi_send(fsi_tx_str_t * str)
{
    static uint16_t index = 0;
    uint16_t cnt;
    
    /* Select frame type */
    switch(str->frame_type)
    {
        case fsi_frame_type_ping:
        {
            /* Configure PING frame */
            FSI_TX->TX_FRAME_CTRL &= ~TX_FRAME_CTRL_FRAME_TYPE_Msk;
            FSI_TX->TX_FRAME_CTRL |= ((FRAME_TYPE_PING << TX_FRAME_CTRL_FRAME_TYPE_Pos) & TX_FRAME_CTRL_FRAME_TYPE_Msk);
            break;
        }
        case fsi_frame_type_data:
        {
            /* Validate number of words */
            if (str->no_of_words == 0)
            {
                return;
            }
            /* Configure data frame parameters */
            fsi_config_data_frame(str->no_of_words);
            /* Load TX buffer with data */
            for (cnt = 0; cnt <= str->no_of_words; cnt++)
            {
                FSI_TX->TX_BUF_BASE[index] = str->data[cnt];
                index = index + 1;
                if (index>= FSI_TX_BUFFER_SIZE)
                {
                    index = 0;
                }
            }
            break;
        }
        case fsi_frame_type_error:
        {
            /* Configure ERROR frame */
            FSI_TX->TX_FRAME_CTRL &= ~TX_FRAME_CTRL_FRAME_TYPE_Msk;
            FSI_TX->TX_FRAME_CTRL |= ((FRAME_TYPE_ERROR << TX_FRAME_CTRL_FRAME_TYPE_Pos) & TX_FRAME_CTRL_FRAME_TYPE_Msk);
            break;
        }
    }

    /* Configure frame tag */
    FSI_TX->TX_FRAME_TAG_UDATA &= ~TX_FRAME_TAG_UDATA_FRAME_TAG_Msk;
    FSI_TX->TX_FRAME_TAG_UDATA |= (((uint16_t)str->frame_tag << TX_FRAME_TAG_UDATA_FRAME_TAG_Pos) & TX_FRAME_TAG_UDATA_FRAME_TAG_Msk);

    /* Configure user data field */
    FSI_TX->TX_FRAME_TAG_UDATA &= ~TX_FRAME_TAG_UDATA_USER_DATA_Msk;
    FSI_TX->TX_FRAME_TAG_UDATA |= (((uint16_t)str->user_data << TX_FRAME_TAG_UDATA_USER_DATA_Pos) & TX_FRAME_TAG_UDATA_USER_DATA_Msk);

    /* Trigger frame transmission */
    FSI_TX->TX_FRAME_CTRL |= TX_FRAME_CTRL_START;
}


/******************************************************************************
* Function     : fsi_is_data_frame_received
*
* Purpose      : 
* Checks whether a data frame is received by the FSI receiver.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  uint16_t - Returns 1 if a data frame is received, otherwise 0.
*
* Requirements :
*
* Notes        :
*
******************************************************************************/

uint16_t fsi_is_data_frame_received(void)
{
    if (FSI_RX->RX_EVT_STS & RX_EVT_STS_DATA_FRAME)
    {
        return 1;
    }
    return 0;
}

/******************************************************************************
* Function     : fsi_receive
*
* Purpose      : 
* Receives data from FSI RX buffer.
*
* Inputs       :
*  data        - Pointer to buffer where received data will be stored.
*  no_of_words - Number of words to be received.
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
void fsi_receive(uint16_t * data, uint16_t no_of_words)
{
    static uint16_t index = 0;
    uint16_t cnt;

    /* Read received data words from RX buffer */
    for (cnt = 0; cnt < no_of_words; cnt++)
    {
        /* Copy data from RX buffer */
        data[cnt] = FSI_RX->RX_BUF_BASE[index];
        index = index + 1;
        if (index>= FSI_RX_BUFFER_SIZE)
        {
            index = 0;
        }
    }
    EALLOW;
    /* Clear data frame receive event flag */
    FSI_RX->RX_EVT_CLR |= RX_EVT_CLR_DATA_FRAME;
    EDIS;
}
/*************** End of C File ************************************************/ 

