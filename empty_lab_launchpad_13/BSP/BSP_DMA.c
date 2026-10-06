/***********************************************************************************************
* File: BSP_DMA.c
* Project: 
* Module: Board Support Package (BSP) for DMA peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for DMA peripherals
*
* Description:
* This file contains board-specific driver functions for Direct Memory Access (DMA) with direct
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
* - BSP_DMA.h 
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
#include "BSP_DMA.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : dma_force_trigger
*
* Purpose      : 
* Forces a DMA trigger event for the specified DMA channel.
*
* Inputs       :
*  channel_number - DMA channel number for which the trigger is to be forced.
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
void dma_force_trigger(uint16_t channel_number)
{
    EALLOW;

    switch (channel_number)
    {
        case channel_1:
        {
            /* Channel 1 Force Peripheral Event Trigger */
            DMA_CH1->CONTROL |= DMA_CONTROL_PERINTFRC_BIT;  
            break;
        }
        case channel_2:
        {
            /* Channel 2 Force Peripheral Event Trigger */
            DMA_CH2->CONTROL |= DMA_CONTROL_PERINTFRC_BIT;
            break;
        }
        case channel_3:
        {
            /* Channel 3 Force Peripheral Event Trigger */
            DMA_CH3->CONTROL |= DMA_CONTROL_PERINTFRC_BIT;
            break;
        }
        case channel_4:
        {
            /* Channel 4 Force Peripheral Event Trigger */
            DMA_CH4->CONTROL |= DMA_CONTROL_PERINTFRC_BIT;
            break;
        }
        case channel_5:
        {
            /* Channel 5 Force Peripheral Event Trigger */
            DMA_CH5->CONTROL |= DMA_CONTROL_PERINTFRC_BIT;
            break;
        }
        case channel_6:
        {
            /* Channel 6 Force Peripheral Event Trigger */
            DMA_CH6->CONTROL |= DMA_CONTROL_PERINTFRC_BIT;
            break;
        }
        default:
        {
            break;
        }
    }
    EDIS;
}


/******************************************************************************
* Function     : dma_config
*
* Purpose      : 
* Configures the DMA channel based on the provided configuration structure.
*
* Inputs       :
*  str - Pointer to dma_str_t structure that contains the DMA configuration 
*        parameters including channel number.
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
void dma_config(dma_str_t * str)
{
    DMA_CH_Typedef * DMA_CH;

    switch (str->channel_no)
    {
        case channel_1:
        {
            DMA_CH = DMA_CH1;
            break;
        }
        case channel_2:
        {
            DMA_CH = DMA_CH2;
            break;
        }
        case channel_3:
        {
            DMA_CH = DMA_CH3;
            break;
        }
        case channel_4:
        {
            DMA_CH = DMA_CH4;
            break;
        }
        case channel_5:
        {
            DMA_CH = DMA_CH5;
            break;
        }
        case channel_6:
        {
            DMA_CH = DMA_CH6;
            break;
        }
        default:
        {
            break;
        }
    }

    EALLOW;
    /* Channel Soft Reset */
    DMA_CH->CONTROL |= DMA_CONTROL_SOFTRESET_BIT;
    /* 16-bit data transfer size */
    DMA_CH->MODE &= ~ DMA_MODE_DATASIZE_BIT;  
    /* Continuous Mode */     
    DMA_CH->MODE |= DMA_MODE_CONTINUOUS_BIT;   
    /* Peripheral event trigger enabled */    
    DMA_CH->MODE |= DMA_MODE_PERINTE_BIT;  
    /* Peripheral Event Trigger Source Select */         
    DMA_CH->MODE |= ((str->channel_no)<<DMA_MODE_PERINTSEL_Pos);         
    /* burst size of 16-bit words */
    DMA_CH->BURST_SIZE = str->burst_size - 1;        

    /* Add 1 to the source address after each word in a burst */
    DMA_CH->SRC_BURST_STEP = DMA_SRC_BURST_STEP_VALUE; 

    /* Add 1 to the destination address after each word in a burst */ 
    DMA_CH->DST_BURST_STEP = DMA_DST_BURST_STEP_VALUE;    

    /* transfer size of 1 in bursts */
    DMA_CH->TRANSFER_SIZE = DMA_TRANSFER_SIZE_VALUE;

    /* no change in the source address after a burst completes*/
    DMA_CH->SRC_TRANSFER_STEP = DMA_SRC_TRANSFER_STEP_VALUE;     

    /* no change in the destination address after a burst completes */
    DMA_CH->DST_TRANSFER_STEP = DMA_DST_TRANSFER_STEP_VALUE;    

    /* the number of bursts to transfer before the source address wraps around to the beginning address*/
    DMA_CH->SRC_WRAP_SIZE = DMA_SRC_WRAP_SIZE_VALUE;
    /* change in the source beginning address when the wrap counter reaches zero */
    DMA_CH->SRC_WRAP_STEP = DMA_SRC_WRAP_STEP_VALUE;
    /* number of bursts to transfer before the destination address wraps around to the beginning address*/
    DMA_CH->DST_WRAP_SIZE = DMA_DST_WRAP_SIZE_VALUE;
    /* change in the destination beginning address when the wrap counter reaches zero*/
    DMA_CH->DST_WRAP_STEP = DMA_DST_WRAP_STEP_VALUE;

    DMA_CH->SRC_BEG_ADDR_SHADOW = str->src_add;
    DMA_CH->SRC_ADDR_SHADOW = str->src_add;
    DMA_CH->DST_BEG_ADDR_SHADOW = str->des_add;        
    DMA_CH->DST_ADDR_SHADOW = str->des_add;

    if (str->channel_no <= 4)
    {
        DMA_CLA_SRC_SEL->DMACHSRCSEL1 &= ~((uint32_t)DMACHSRCSEL_CH_Msk<<(DMACHSRCSEL_CH_BIT_SIZE*(str->channel_no-DMACHSRCSEL1_CH_OFFSET)));
        DMA_CLA_SRC_SEL->DMACHSRCSEL1 |= ((uint32_t)(str->trigger_source & DMACHSRCSEL_CH_Msk)<<(DMACHSRCSEL_CH_BIT_SIZE*(str->channel_no-DMACHSRCSEL1_CH_OFFSET)));
    }
    else 
    {
        DMA_CLA_SRC_SEL->DMACHSRCSEL2 &= ~((uint32_t)DMACHSRCSEL_CH_Msk<<(DMACHSRCSEL_CH_BIT_SIZE*(str->channel_no-DMACHSRCSEL2_CH_OFFSET)));
        DMA_CLA_SRC_SEL->DMACHSRCSEL2 |= ((uint32_t)(str->trigger_source & DMACHSRCSEL_CH_Msk)<<(DMACHSRCSEL_CH_BIT_SIZE*(str->channel_no-DMACHSRCSEL2_CH_OFFSET)));
    }
    /* enable the DMA channel */
    DMA_CH->CONTROL |= DMA_CONTROL_RUN_BIT; 

    EDIS;
}

/*************** End of C File ************************************************/ 

