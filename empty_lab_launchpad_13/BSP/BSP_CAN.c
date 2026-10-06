/***********************************************************************************************
* File: BSP_CAN.c
* Project: 
* Module: Board Support Package (BSP) for CAN peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for CAN peripherals
*
* Description:
* This file contains board-specific driver functions for Controller Area Network (CAN)
*  with direct interaction to the underlying hardware.
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
* - BSP_CAN.h 
* - BSP_CLOCK.h 
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
#include "BSP_CAN.h"
#include "BSP_CLOCK.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

#define CAN_RX_MSG_ID     100
/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : can_timing_config 
*
* Purpose      : 
* Configures the CAN peripheral timing parameters to support CAN bus
* operation.
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
void can_timing_config(void)
{
     /*PERx.SYSCLK selected as CAN Bit Clock Source*/
    CLKCFG->CLKSRCCTL2 &= ~CLKSRCCTL2_BITS_CANABCLKSEL_Msk;   

    /* Bit rate of 1 Mbps is configured for CAN Bit clock of 120 MHz*/
    CAN->CAN_BTR &= ~CAN_BTR_SJW_Msk;
    CAN->CAN_BTR |= (((uint32_t)CAN_BTR_SJW_VALUE << CAN_BTR_SJW_Pos) & CAN_BTR_SJW_Msk);

    CAN->CAN_BTR &= ~CAN_BTR_BRPE_Msk;
    CAN->CAN_BTR &= ~CAN_BTR_BRP_Msk;
    CAN->CAN_BTR |= (((uint32_t)CAN_BTR_BRPE_VALUE << CAN_BTR_BRP_Pos) & CAN_BTR_BRP_Msk);

    CAN->CAN_BTR &= ~CAN_BTR_TSEG1_Msk;
    CAN->CAN_BTR |= (((uint32_t)CAN_BTR_TSEG1_VALUE << CAN_BTR_TSEG1_Pos) & CAN_BTR_TSEG1_Msk);

    CAN->CAN_BTR &= ~CAN_BTR_TSEG2_Msk;
    CAN->CAN_BTR |= (((uint32_t)CAN_BTR_TSEG2_VALUE << CAN_BTR_TSEG2_Pos) & CAN_BTR_TSEG2_Msk);
}

/******************************************************************************
* Function     : can_config_rx 
*
* Purpose      : 
* Configures the CAN peripheral for message reception.
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
void can_config_rx(void)
{
    uint32_t ifcmd = 0;
    uint32_t ifarb = 0;

    /* Configure arbitration: extended frame and valid message object */
    ifarb |= CAN_IFARB_XTD;
    ifarb |= CAN_IFARB_MSGVAL;
    CAN->CAN_IF1ARB = ifarb;

    CAN->CAN_IF1MSK = CAN_IFMSK_MXTD;

    /* Enable mask usage and configure control (DLC + end of buffer) */
    CAN->CAN_IF1MCTL |= CAN_IFMCTL_UMASK;
    CAN->CAN_IF1MCTL |= CAN_IFMCTL_EOB;
    CAN->CAN_IF1MCTL &= ~CAN_IFMCTL_DLC_Msk;
    CAN->CAN_IF1MCTL |= (((uint32_t)CAN_IFMCTL_DLC_VALUE <<CAN_IFMCTL_DLC_Pos) & CAN_IFMCTL_DLC_Msk);

    ifcmd |= CAN_IFMCMD_DIR;
    ifcmd |= CAN_IFMCMD_ARB;
    ifcmd |= CAN_IFMCMD_MASK;
    ifcmd |= CAN_IFMCMD_CONTROL;
    ifcmd |= ((((uint32_t)MESSAGE_NUMBER_RX_ALL)<< CAN_IFMCMD_MSG_NUM_Pos) & CAN_IFMCMD_MSG_NUM_Msk);
    CAN->CAN_IF1CMD = ifcmd;
    /* Wait until IF1 transfer is complete */
    while (CAN->CAN_IF1CMD & CAN_IFMCMD_BUSY);

}

/******************************************************************************
* Function     : can_config_rx_filter 
*
* Purpose      : 
* Configures the CAN peripheral receive filter for the specified identifier.
*
* Inputs       :
*  id    -      CAN message identifier used for receive filtering.
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
void can_config_rx_filter(uint32_t id)
{
    uint32_t ifcmd = 0;
    uint32_t ifarb = 0;
    
    /* Configure arbitration: extended ID + valid message */
    ifarb |= CAN_IFARB_XTD;
    ifarb |= CAN_IFARB_MSGVAL;
    ifarb |= ((id << CAN_IFARB_ID_Pos) & CAN_IFARB_ID_Msk);
    CAN->CAN_IF1ARB = ifarb;

    /* Configure mask for ID and extended frame matching */
    CAN->CAN_IF1MSK = CAN_IFMSK_MXTD | CAN_IFMSK_MSK_Msk;

    /* Enable mask usage and set DLC */
    CAN->CAN_IF1MCTL |= CAN_IFMCTL_UMASK;
    CAN->CAN_IF1MCTL |= CAN_IFMCTL_EOB;
    CAN->CAN_IF1MCTL &= ~CAN_IFMCTL_DLC_Msk;
    CAN->CAN_IF1MCTL |= (((uint32_t)CAN_IFMCTL_DLC_VALUE <<CAN_IFMCTL_DLC_Pos) & CAN_IFMCTL_DLC_Msk);

    /* Prepare IF command for writing mask, arbitration, and control */
    ifcmd |= CAN_IFMCMD_DIR;
    ifcmd |= CAN_IFMCMD_ARB;
    ifcmd |= CAN_IFMCMD_MASK;
    ifcmd |= CAN_IFMCMD_CONTROL;
    ifcmd |= ((((uint32_t)MESSAGE_NUMBER_RX_FILTER)<< CAN_IFMCMD_MSG_NUM_Pos) & CAN_IFMCMD_MSG_NUM_Msk);
    CAN->CAN_IF1CMD = ifcmd;
    
    /* Wait until transfer to message RAM is complete */
    while (CAN->CAN_IF1CMD & CAN_IFMCMD_BUSY);

}

/******************************************************************************
* Function     : can_message_send 
*
* Purpose      : 
* Sends a CAN message using the configured CAN peripheral.
*
* Inputs       :
*  str      -   Pointer to a can_tx_rx_str_t structure that contains the
*               CAN message identifier, message data, and message number.
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
void can_message_send(can_tx_rx_str_t * str)
{
    uint32_t ifcmd = 0;
    uint32_t ifarb = 0;
    CAN->CAN_IF1MCTL |= CAN_IFMCTL_EOB;
    CAN->CAN_IF1MCTL &= ~CAN_IFMCTL_DLC_Msk;
    CAN->CAN_IF1MCTL |= (((uint32_t)CAN_IFMCTL_DLC_VALUE<<CAN_IFMCTL_DLC_Pos) & CAN_IFMCTL_DLC_Msk);

    ifarb |= CAN_IFARB_DIR;
    ifarb |= CAN_IFARB_XTD;
    ifarb |= CAN_IFARB_MSGVAL;
    ifarb |= str->id;
    CAN->CAN_IF1ARB = ifarb;
    CAN->CAN_IF1DATA = *((uint32_t *)&str->data_a);
    CAN->CAN_IF1DATB = *((uint32_t *)&str->data_b);

    ifcmd |= CAN_IFMCMD_DIR;
    ifcmd |= CAN_IFMCMD_ARB;
    ifcmd |= CAN_IFMCMD_CONTROL;
    ifcmd |= CAN_IFMCMD_TXRQST;
    ifcmd |= CAN_IFMCMD_DATA_A;
    ifcmd |= CAN_IFMCMD_DATA_B;
    ifcmd |= (((str->message_number)<< CAN_IFMCMD_MSG_NUM_Pos) & CAN_IFMCMD_MSG_NUM_Msk);
    CAN->CAN_IF1CMD = ifcmd;

    while (CAN->CAN_IF1CMD & CAN_IFMCMD_BUSY);
}

/******************************************************************************
* Function     : can_message_receive 
*
* Purpose      : 
* Receives a CAN message using the configured CAN peripheral.
*
* Inputs       :
*  str      -   Pointer to a can_tx_rx_str_t structure that is used to store
*               the received CAN message identifier, data, and message
*               number information
*
* Outputs      :
*  None.
*
* Returns      :
*  uint16_t  -  Status indicating whether a CAN message was received.
*
* Requirements :
*
* Notes        :
*
******************************************************************************/
uint16_t can_message_receive(can_tx_rx_str_t * str)
{
    uint32_t ifcmd;
    uint32_t message_number;
    message_number = CAN->CAN_NDAT_21;

    /* Initialize message number */
    str->message_number = 1;
    
    /* Check if message_number is non-zero */
    if (message_number)
    {
        /* Find position of first set bit (LSB) */
        while ((message_number & MESSAGE_NUMBER_1) != MESSAGE_NUMBER_1)
        {
            str->message_number++;
            message_number = message_number >> 1;
        }
        ifcmd = 0;
        /* Enable mask transfer */
        ifcmd |= CAN_IFMCMD_MASK;
        /* Enable arbitration transfer */
        ifcmd |= CAN_IFMCMD_ARB;
        /* Enable control transfer */
        ifcmd |= CAN_IFMCMD_CONTROL;
        /* Enable transmission request */
        ifcmd |= CAN_IFMCMD_TXRQST;
        /* Enable data A transfer */
        ifcmd |= CAN_IFMCMD_DATA_A;
        /* Enable data B transfer */
        ifcmd |= CAN_IFMCMD_DATA_B;
        /* Set message object number */
        ifcmd |= (((str->message_number)<< CAN_IFMCMD_MSG_NUM_Pos) & CAN_IFMCMD_MSG_NUM_Msk);
        CAN->CAN_IF1CMD = ifcmd;
        /* Wait until IF1 command is processed */
        while (CAN->CAN_IF1CMD & CAN_IFMCMD_BUSY);

        /* Read message ID from arbitration register */
        str->id = CAN->CAN_IF1ARB & CAN_IFARB_ID_Msk;
        /* Read Data A */
        *((uint32_t *)&str->data_a) = CAN->CAN_IF1DATA;
        /* Read Data B */
        *((uint32_t *)&str->data_b) = CAN->CAN_IF1DATB;
        /* Return success */
        return msg_received;
    }
    /* Return 0 if no message */
    return no_msg_received;
}

/******************************************************************************
* Function     : can_config 
*
* Purpose      : 
* Configures the CAN peripheral for communication operation.
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
void can_config(void)
{
    EALLOW;

    /* Set CAN module to initialization mode */
    CAN->CAN_CTL |= CAN_CTL_INIT;
    /* Allow configuration changes (bit timing, filters) */
    CAN->CAN_CTL |= CAN_CTL_CCE;
    /* Enable automatic bus-on recovery after bus-off */
    CAN->CAN_CTL |= CAN_CTL_ABO;
    /* Configure CAN bit timing parameters */
    can_timing_config();
    /* Configure CAN receive message objects */
    can_config_rx();
    /* Configure CAN receive filter with specified ID */
    can_config_rx_filter(CAN_RX_MSG_ID);
    /* Disable configuration change access */
    CAN->CAN_CTL &= ~CAN_CTL_CCE;
    /* Exit initialization mode and start CAN operation */
    CAN->CAN_CTL &= ~CAN_CTL_INIT;

    EDIS;
}
/*************** End of C File ************************************************/ 
