/***********************************************************************************************
* File: HAL_MCAN.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for MCAN peripherals
*
* Purpose :
* HAL-level interface for MCAN peripherals.
*
* Description:
* This file provides a standardized API for interacting with Modular Controller Area Network (MCAN),
*  abstracting the specific register-level operations of the underlying MCU. 
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
* - HAL_MCAN.h 
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
#include "HAL_MCAN.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
/* MCAN Configuration*/
mcan_struct_t mcan_struct = {
#ifndef _LAUNCHPAD_
    .tx = { .gpio_number = 13, .mux_position = 3 },
    .rx = { .gpio_number = 39, .mux_position = 6 },
#else
    .tx = { .gpio_number = 4, .mux_position = 3 },
    .rx = { .gpio_number = 5, .mux_position = 5 },
#endif
};

mcan_extended_filter_t filter_struct = { 
    .efid1 = 100,      /* CAN ID of Only 100 will be received in FIFO 0, others in FIFO 1  */     
    .efid2 = 100,
    .efec  = 1,
    .eft   = 1,
};

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : mcan_telemetry 
*
* Purpose      : 
* Prepares and transmits application telemetry data over the MCAN interface.
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
void mcan_telemetry(void)
{
    /* Counter to track transmitted messages */
    static uint32_t cnt = 0;   
    mcan_tx_buffer_element_t tx_element;

    /* Initialize transmit buffer with default configuration */
    mcan_tx_element_default(&tx_element);

    /* Set message identifier */
    tx_element.id = MCAN_MESSAGE_ID_VALUE;

    /* Set predefined data pattern */
    tx_element.bd4 = MCAN_DATA_PATTERN_VALUE;

    /* Insert counter value into payload */
    tx_element.bd0 = cnt;

    /* Send MCAN message */
    mcan_message_send(&tx_element);
    cnt++;
    
    /* Reset counter after reaching 256 */
    if (cnt >= MCAN_COUNTER_MAX)
    {
        cnt = 0;
    }
}

/******************************************************************************
* Function     : mcan_retransmit 
*
* Purpose      : 
* Prepares and retransmits an MCAN message.
*
* Inputs       :
*  rx     -     Pointer to an mcan_rx_buffer_element_t structure that contains
*               the received MCAN message information to be retransmitted.
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
void mcan_retransmit(mcan_rx_buffer_element_t * rx)
{
    mcan_tx_buffer_element_t tx_element;

    /* Initialize transmit buffer with default values */
    mcan_tx_element_default(&tx_element);

    /* Modify message ID (increment received ID by 1) */
    tx_element.id = rx->id + 1;

    /* Copy received payload data to transmit buffer */
    tx_element.bd7 = rx->bd7;
    tx_element.bd6 = rx->bd6;
    tx_element.bd5 = rx->bd5;
    tx_element.bd4 = rx->bd4;
    tx_element.bd3 = rx->bd3;
    tx_element.bd2 = rx->bd2;
    tx_element.bd1 = rx->bd1;
    tx_element.bd0 = rx->bd0;

    /* Send MCAN message */
    mcan_message_send(&tx_element);
}

/******************************************************************************
* Function     : mcan_process 
*
* Purpose      : 
* Checks for a new message in FIFO 0. If a message is available, it is
* retransmitted after incrementing the message ID.
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

void mcan_process(void)
{
    mcan_rx_buffer_element_t rx_element;
    /* check for new message in FIFO 0*/
    if (mcan_message_receive(&rx_element))     
    {  
        /* if available, re transmit after increment the ID by one*/
        mcan_retransmit(&rx_element);   
    }         

}


/******************************************************************************
* Function     : mcan_init 
*
* Purpose      : 
* Initializes MCAN peripheral and configures filters.
*
* Inputs       :
*  mcan   - Pointer to mcan_struct_t containing MCAN configuration,
*           including TX and RX pin details.
*  filter - Pointer to mcan_extended_filter_t structure for filter configuration.
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
* Configures TX and RX GPIOs, initializes MCAN module, and updates the
* message filter settings.
*
******************************************************************************/

void mcan_init(void)
{
    gpio_peripheral_config(&mcan_struct.tx);
    gpio_peripheral_config(&mcan_struct.rx);
    mcan_config();
    mcan_filter_config();
    mcan_filter_update(&filter_struct);
}
/*************** End of C File ************************************************/ 



