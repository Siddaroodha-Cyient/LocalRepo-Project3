/***********************************************************************************************
* File: HAL_CAN.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for CAN peripherals
*
* Purpose :
* HAL-level interface for CAN peripherals.
*
* Description:
* This file provides a standardized API for interacting with CAN, abstracting the specific
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
* - HAL_CAN.h 
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
#include "HAL_CAN.h"
#include "HAL_UART.h"

/******************************************************************************
* Module Global Definitions
******************************************************************************/
/* CAN Configuration*/
can_struct_t can_struct = {
#ifndef _LAUNCHPAD_
    .tx = { .gpio_number = 31, .mux_position = 1 },
    .rx = { .gpio_number = 30, .mux_position = 1 },
#else
    .tx = { .gpio_number = 4, .mux_position = 6 },
    .rx = { .gpio_number = 5, .mux_position = 6 },
#endif
};

can_tx_rx_str_t can_rx_str;

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : can_telemetry 
*
* Purpose      : 
* Prepares and transmits application telemetry data over the CAN interface.
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
void can_telemetry(void)
{
    static uint32_t cnt = 0;
    can_tx_rx_str_t str;

    str.id = CAN_MESSAGE_ID_VALUE;
    str.data_b.Data_7 = 0;
    str.data_b.Data_6 = 0;
    str.data_b.Data_5 = 0;
    str.data_b.Data_4 = SW_VERSION;
    str.data_a.Data_3 = 0;
    str.data_a.Data_2 = 0;
    str.data_a.Data_1 = 0;
    str.data_a.Data_0 = cnt;
    str.message_number = MESSAGE_NUMBER_TX_TELEMETRY;
    can_message_send(&str);

    cnt++;
    if (cnt >= CAN_COUNTER_MAX)
    {
        cnt = 0;
    }
}

/******************************************************************************
* Function     : can_process 
*
* Purpose      : 
* Checks for a received message. If the message matches the configured
* filter, the message ID is incremented and retransmitted.
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
void can_process(void)
{
    if (can_message_receive(&can_rx_str))
    {
        if (can_rx_str.message_number == MESSAGE_NUMBER_RX_FILTER)
        {
            can_rx_str.message_number = MESSAGE_NUMBER_TX_ECHO;
            can_rx_str.id++;
            can_message_send(&can_rx_str);
        }
    }
}


/******************************************************************************
* Function     : can_init 
*
* Purpose      : 
* Initializes CAN peripheral and configures GPIO pins.
*
* Inputs       :
*  can   - Pointer to can_struct_t containing CAN configuration,
*          including TX and RX pin details.
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
* Configures TX and RX GPIOs and initializes the CAN module.
*
******************************************************************************/
void can_init(void)
{
    gpio_peripheral_config(&can_struct.tx);
    gpio_peripheral_config(&can_struct.rx);
    can_config();
}
/*************** End of C File ************************************************/ 
