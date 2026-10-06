/***********************************************************************************************
* File: BSP_MCAN.c
* Project: 
* Module: Board Support Package (BSP) for MCAN peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for MCAN peripherals
*
* Description:
* This file contains board-specific driver functions for Modular Controller Area Network (MCAN) 
* with direct interaction to the underlying hardware.
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
* - BSP_MCAN.h 
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
#include "BSP_MCAN.h"
#include "BSP_CLOCK.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

#define TX_BUFFER_START_ADDRESS       0x500
#define RX_FIFO0_BUFFER_START_ADDRESS 0x100
#define RX_FIFO1_BUFFER_START_ADDRESS 0x20
#define RX_FILTER_LIST_START_ADDRESS  0U

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : mcan_timing_config 
*
* Purpose      : 
* Configures the MCAN peripheral timing parameters to support MCAN bus
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
* Requirements:
*
* Notes        : 
*
******************************************************************************/
void mcan_timing_config(void)
{
    EALLOW;
    /*CPU1SYSCLK selected as MCAN Bit Clock Source*/
    CLKCFG->CLKSRCCTL2 &= ~CLKSRCCTL2_BITS_MCANABCLKSEL_Msk;    
    /* Prescalar of 1 */
    CLKCFG->AUXCLKDIVSEL &= ~AUXCLKDIVSEL_BITS_MCANCLKDIV_Msk;  
    EDIS;
    
    /* Bit rate of 1 Mbps is configured for MCAN Bit clock of 120 MHz*/
    MCANA->NBTP &= ~MCAN_NBTP_NSJW_Msk;
    MCANA->NBTP |= (((uint32_t)MCAN_NSJW_VALUE << MCAN_NBTP_NSJW_Pos) & MCAN_NBTP_NSJW_Msk);

    MCANA->NBTP &= ~MCAN_NBTP_NBRP_Msk;
    MCANA->NBTP |= (((uint32_t)MCAN_NBRP_VALUE << MCAN_NBTP_NBRP_Pos) & MCAN_NBTP_NBRP_Msk);

    MCANA->NBTP &= ~MCAN_NBTP_NTSEG1_Msk;
    MCANA->NBTP |= ((MCAN_NTSEG1_VALUE << MCAN_NBTP_NTSEG1_Pos) & MCAN_NBTP_NTSEG1_Msk);

    MCANA->NBTP &= ~MCAN_NBTP_NTSEG2_Msk;
    MCANA->NBTP |= ((MCAN_NTSEG2_VALUE << MCAN_NBTP_NTSEG2_Pos) & MCAN_NBTP_NTSEG2_Msk);

}

/******************************************************************************
* Function     : mcan_config 
*
* Purpose      : 
* Configures the MCAN peripheral for communication operation.
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
void mcan_config(void)
{
    MCANA->CCCR |= MCAN_CCCR_INIT;
    while ((MCANA->CCCR & MCAN_CCCR_INIT) != MCAN_CCCR_INIT);

    MCANA->CCCR |= MCAN_CCCR_CCE;

    mcan_timing_config();

    MCANA->CCCR &= ~MCAN_CCCR_FDOE;
    MCANA->CCCR &= ~MCAN_CCCR_BRSE;

    /* Tx Queue operation */
    MCANA->TXBC |= MCAN_TXBC_TFQM;    
    MCANA->TXBC &= ~MCAN_TXBC_TFQS_Msk;
    MCANA->TXBC |= (((uint32_t)MCAN_TXBC_FQS_VALUE << MCAN_TXBC_TFQS_Pos) & MCAN_TXBC_TFQS_Msk);

    MCANA->TXBC &= ~MCAN_TXBC_NDTB_Msk;
    MCANA->TXBC |= (((uint32_t)MCAN_TXBC_NDTB_VALUE << MCAN_TXBC_NDTB_Pos) & MCAN_TXBC_NDTB_Msk);        

    /* Tx buffer start address*/
    MCANA->TXBC &= ~MCAN_TXBC_TBSA_Msk;       
    MCANA->TXBC |= (((uint32_t)TX_BUFFER_START_ADDRESS << MCAN_TXBC_TBSA_Pos) & MCAN_TXBC_TBSA_Msk);
    /* 8 byte data field*/
    MCANA->TXESC &= ~MCAN_TXESC_TBDS_Msk;  

    /* Tx buffer start address*/    
    MCANA->RXBC &= ~MCAN_RXBC_RBSA_Msk;   
    MCANA->RXBC |= (((uint32_t)MCAN_RXBC_RBSA_VALUE << MCAN_RXBC_RBSA_Pos) & MCAN_RXBC_RBSA_Msk);
    /* 8 byte data field*/
    MCANA->RXESC &= ~MCAN_RXESC_RBDS_Msk;      

    /* Rx FIFO 0 Size set to 64 */
    MCANA->RXF0C &= ~MCAN_RXF0C_F0S_Msk;
    MCANA->RXF0C |= (((uint32_t)MCAN_RXF0C_F0S_VALUE<< MCAN_RXF0C_F0S_Pos) & MCAN_RXF0C_F0S_Msk);

    /* Rx FIFO 0 Start address config */
    MCANA->RXF0C &= ~MCAN_RXF0C_F0SA_Msk;
    MCANA->RXF0C |= (((uint32_t)RX_FIFO0_BUFFER_START_ADDRESS << MCAN_RXF0C_F0SA_Pos) & MCAN_RXF0C_F0SA_Msk);

    /* Rx FIFO 1 Size set to 10 */
    MCANA->RXF1C &= ~MCAN_RXF1C_F1S_Msk;
    MCANA->RXF1C |= (((uint32_t)MCAN_RXF1C_F1S_VALUE << MCAN_RXF1C_F1S_Pos) & MCAN_RXF1C_F1S_Msk);

    /* Rx FIFO 1 Start address config */
    MCANA->RXF1C &= ~MCAN_RXF1C_F1SA_Msk;
    MCANA->RXF1C |= (((uint32_t)RX_FIFO1_BUFFER_START_ADDRESS << MCAN_RXF1C_F1SA_Pos) & MCAN_RXF0C_F0SA_Msk);

    MCANA->CCCR &= ~MCAN_CCCR_CCE;
    MCANA->CCCR &= ~MCAN_CCCR_INIT;

}

/******************************************************************************
* Function     : mcan_filter_config 
*
* Purpose      : 
* Configures the MCAN peripheral message filtering.
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
void mcan_filter_config(void)
{
    MCANA->CCCR |= MCAN_CCCR_INIT;
    while ((MCANA->CCCR & MCAN_CCCR_INIT) != MCAN_CCCR_INIT);

    MCANA->CCCR |= MCAN_CCCR_CCE;

    /* Do not accept the messages of 11-bit ID*/
    MCANA->GFC |= MCAN_GFC_ANFS_Msk;

    /* Accept the messages in FIFO 1 if 29-bit ID does not match the filter value*/
    MCANA->GFC &= ~MCAN_GFC_ANFE_Msk;
    MCANA->GFC |= (((uint32_t)MCAN_GFC_ANFE_VALUE << MCAN_GFC_ANFE_Pos) & MCAN_GFC_ANFE_Msk);
    
    /* Do not accept the remote frame messages*/
    MCANA->GFC |= MCAN_GFC_RRFE;
    MCANA->GFC |= MCAN_GFC_RRFS;

    /* No. of 29-bit ID filters used is set to 1*/
    MCANA->XIDFC &= ~MCAN_XIDFC_LSE_Msk;
    MCANA->XIDFC |= (((uint32_t)MCAN_XIDFC_LSE_VALUE << MCAN_XIDFC_LSE_Pos) & MCAN_XIDFC_LSE_Msk);

    MCANA->XIDFC &= ~MCAN_XIDFC_FLESA_Msk;
    MCANA->XIDFC |= (((uint32_t)RX_FILTER_LIST_START_ADDRESS << MCAN_XIDFC_FLESA_Pos) & MCAN_XIDFC_FLESA_Msk);

    MCANA->XIDAM |= MCAN_XIDAM_EIDM_Msk;

    MCANA->CCCR &= ~MCAN_CCCR_CCE;
    MCANA->CCCR &= ~MCAN_CCCR_INIT;
}

/******************************************************************************
* Function     : mcan_filter_update 
*
* Purpose      : 
* Updates the MCAN peripheral message filter configuration.
*
* Inputs       :
*  filter   -   Pointer to an mcan_extended_filter_t structure that contains
*               the MCAN filter configuration information
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
void mcan_filter_update(mcan_extended_filter_t * filter)
{
    uint32_t * ptr;
    uint32_t * ptr2 = (uint32_t *)filter;
    uint32_t i;

    /* Loop through extended filter words */
    for (i = 0 ; i < MCAN_EXT_FILTER_WORD_COUNT; i++)
    {
        /* Calculate message RAM address */
        ptr = (uint32_t *)(MCANA_MSG_RAM_BASE + MCAN_STD_WORD_SIZE*(RX_FILTER_LIST_START_ADDRESS + i));
        /* Write data */
        *ptr = ptr2[i];
    }
}

/******************************************************************************
* Function     : mcan_message_send 
*
* Purpose      : 
* Updates the MCAN peripheral message filter configuration.
*
* Inputs       :
*  element  -   Pointer to an mcan_tx_buffer_element_t structure that
*               contains the MCAN transmit message information.
*
* Outputs      :
*  None.
*
* Returns      :
*  uint16_t  -  Status indicating the result of the MCAN message transmission.
*
* Requirements:
*
* Notes        : 
*
******************************************************************************/
uint16_t mcan_message_send(mcan_tx_buffer_element_t * element)
{
    static uint32_t cnt = 0;
    uint32_t * ptr;
    uint32_t * ptr2 = (uint32_t *)element;
    uint32_t i;

    /* Check if current TX buffer is pending (busy) */
    if (MCANA->TXBRP & (BIT_MASK_32 << cnt))
    {
        /* Buffer not available */
        return 0;   
    }

    /* Copy transmit element data into MCAN message RAM */
    for (i = 0 ; i < MCAN_TX_ELEMENT_WORD_COUNT; i++)
    {
        /* Calculate address of TX buffer element in message RAM */
        ptr = (uint32_t *)(MCANA_MSG_RAM_BASE + MCAN_WORD_SIZE_BYTES*(TX_BUFFER_START_ADDRESS + MCAN_TX_ELEMENT_WORD_COUNT*cnt + i));

        /* Write data word to message RAM */
        *ptr = ptr2[i];
    }

    /* Add transmission request for selected buffer */
    MCANA->TXBAR |= ((uint32_t)MCAN_TX_BUFFER_BIT << cnt);
    cnt++;

    /* Wrap around after using all 32 TX buffers */
    if (cnt >= MCAN_TX_BUFFER_COUNT)
    {
        cnt = 0;
    }
    return 1;
}

/******************************************************************************
* Function     : mcan_message_receive 
*
* Purpose      : 
* Receives a message using the MCAN peripheral.
*
* Inputs       :
*  element  -   Pointer to an mcan_rx_buffer_element_t structure that is
*               used to store the received MCAN message information.
*
* Outputs      :
*  None.
*
* Returns      :
*  uint16_t  -  Status indicating whether an MCAN message was successfully received.
*
* Requirements:
*
* Notes        : 
*
******************************************************************************/
uint16_t mcan_message_receive(mcan_rx_buffer_element_t * element)
{
    uint32_t * ptr;
    uint32_t * ptr2 = (uint32_t *)element;
    uint32_t i, pos;
    
    /* Check if there are messages available in RX FIFO 0 */
    if (MCANA->RXF0S & MCAN_RXF0S_F0FL_Msk)
    {
        /* Get index of the next message in FIFO 0 */
        pos = ((MCANA->RXF0S & MCAN_RXF0S_F0GI_Msk)>>MCAN_RXF0S_F0GI_Pos);
        /* Copy received message data from MCAN message RAM */
        for (i = 0 ; i < MCAN_RX_ELEMENT_WORD_COUNT; i++)
        {
            /* Calculate address of RX FIFO element */
            ptr = (uint32_t *)(MCANA_MSG_RAM_BASE + MCAN_WORD_SIZE_BYTES*(RX_FIFO0_BUFFER_START_ADDRESS + MCAN_RX_ELEMENT_WORD_COUNT*pos +i));
            ptr2[i] = *ptr;
        }
        /* Acknowledge the read position in RX FIFO 0 */
        MCANA->RXF0A &= ~MCA_RXF0A_F0AI_Msk;
        MCANA->RXF0A |= ((pos << MCA_RXF0A_F0AI_Pos) & MCA_RXF0A_F0AI_Msk);
        /* Message successfully received */
        return 1;
    }
    /* No message available */
    return 0;
}

/******************************************************************************
* Function     : mcan_tx_element_default 
*
* Purpose      : 
* Initializes the MCAN transmit buffer element with default values.
*
* Inputs       :
*  tx_element - Pointer to an mcan_tx_buffer_element_t structure that
*               will be initialized with default transmit values.
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
void mcan_tx_element_default(mcan_tx_buffer_element_t * tx_element)
{
    tx_element->rtr = 0;   
    tx_element->xtd = 1;   
    tx_element->esi = 0;   
    tx_element->dlc = 8;   
    tx_element->brs = 0;   
    tx_element->fdf = 0;
    tx_element->id  = 0;
    tx_element->bd7 = 0;
    tx_element->bd6 = 0;
    tx_element->bd5 = 0;
    tx_element->bd4 = 0;
    tx_element->bd3 = 0;
    tx_element->bd2 = 0;
    tx_element->bd1 = 0;
    tx_element->bd0 = 0;
}

/*************** End of C File ************************************************/

