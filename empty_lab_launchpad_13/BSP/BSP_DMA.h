/***********************************************************************************************
* File    : BSP_DMA.h
*
* Module  : Board Support Package (BSP) for DMA peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for DMA peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for DMA peripherals.
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
#ifndef BSP_DMA_H
#define BSP_DMA_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef enum{
    channel_1 = 1,
    channel_2 = 2,
    channel_3 = 3,
    channel_4 = 4,
    channel_5 = 5,
    channel_6 = 6,

}dma_channel_number_t;

typedef struct{
    uint16_t DMACTRL;            /* 0h DMA Control Register   */
    uint16_t DEBUGCTRL;          /* 1h Debug Control Register */
    uint16_t resv1[2];
    uint16_t PRIORITYCTRL1;      /* 4h Priority Control 1 Register */
    uint16_t resv2;
    uint16_t PRIORITYSTAT;       /* 6h Priority Status Register    */
} DMA_Typedef;

typedef struct{
    uint16_t MODE;                   /* 0h Mode Register                      */
    uint16_t CONTROL;                /* 1h Control Register                   */
    uint16_t BURST_SIZE;             /* 2h Burst Size Register                */
    uint16_t BURST_COUNT;            /* 3h Burst Count Register               */
    uint16_t SRC_BURST_STEP;         /* 4h Source Burst Step Register         */
    uint16_t DST_BURST_STEP;         /* 5h Destination Burst Step Register    */
    uint16_t TRANSFER_SIZE;          /* 6h Transfer Size Register             */
    uint16_t TRANSFER_COUNT;         /* 7h Transfer Count Register            */
    uint16_t SRC_TRANSFER_STEP;      /* 8h Source Transfer Step Register      */
    uint16_t DST_TRANSFER_STEP;      /* 9h Destination Transfer Step Register */
    uint16_t SRC_WRAP_SIZE;          /* Ah Source Wrap Size Register          */
    uint16_t SRC_WRAP_COUNT;         /* Bh Source Wrap Count Register         */
    uint16_t SRC_WRAP_STEP;          /* Ch Source Wrap Step Register          */
    uint16_t DST_WRAP_SIZE;          /* Dh Destination Wrap Size Register     */
    uint16_t DST_WRAP_COUNT;         /* Eh Destination Wrap Count Register    */
    uint16_t DST_WRAP_STEP;          /* Fh Destination Wrap Step Register     */
    uint32_t SRC_BEG_ADDR_SHADOW;    /* 10h Source Begin Address Shadow Register */
    uint32_t SRC_ADDR_SHADOW;        /* 12h Source Address Shadow Register       */
    uint32_t SRC_BEG_ADDR_ACTIVE;    /* 14h Source Begin Address Active Register */
    uint32_t SRC_ADDR_ACTIVE;        /* 16h Source Address Active Register       */
    uint32_t DST_BEG_ADDR_SHADOW;    /* 18h Destination Begin Address Shadow Register   */
    uint32_t DST_ADDR_SHADOW;        /* 1Ah Destination Address Shadow Register         */
    uint32_t DST_BEG_ADDR_ACTIVE;    /* 1Ch Destination Begin Address Active Register   */
    uint32_t DST_ADDR_ACTIVE;        /* 1Eh Destination Address Active Register         */
} DMA_CH_Typedef;

typedef struct{
    uint32_t CLA1TASKSRCSELLOCK;         /* 0h  CLA1 Task Trigger Source Select Lock Register  */
    uint32_t resv1;
    uint32_t DMACHSRCSELLOCK;            /* 4h  DMA Channel Triger Source Select Lock Register */
    uint32_t CLA1TASKSRCSEL1;            /* 6h  CLA1 Task Trigger Source Select Register-1 */
    uint32_t CLA1TASKSRCSEL2;            /* 8h  CLA1 Task Trigger Source Select Register-2 */
    uint32_t resv2[6];
    uint32_t DMACHSRCSEL1;               /* 16h  DMA Channel Trigger Source Select Register-1 */
    uint32_t DMACHSRCSEL2;               /* 18h  DMA Channel Trigger Source Select Register-2 */
} DMA_CLA_SRC_SEL_Typedef;

typedef struct{
    uint32_t src_add;
    uint32_t des_add;
    uint16_t channel_no;
    uint16_t burst_size;
    uint16_t trigger_source;
} dma_str_t;

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define DMA_BASE                    0x00001000
#define DMA_CH1_BASE                0x00001020
#define DMA_CH2_BASE                0x00001040
#define DMA_CH3_BASE                0x00001060
#define DMA_CH4_BASE                0x00001080
#define DMA_CH5_BASE                0x000010A0
#define DMA_CH6_BASE                0x000010C0
#define DMACLASRCSEL_BASE           0x00007980

#define DMA                 ((DMA_Typedef *) DMA_BASE)
#define DMA_CH1             ((DMA_CH_Typedef *) DMA_CH1_BASE)
#define DMA_CH2             ((DMA_CH_Typedef *) DMA_CH2_BASE)
#define DMA_CH3             ((DMA_CH_Typedef *) DMA_CH3_BASE)
#define DMA_CH4             ((DMA_CH_Typedef *) DMA_CH4_BASE)
#define DMA_CH5             ((DMA_CH_Typedef *) DMA_CH5_BASE)
#define DMA_CH6             ((DMA_CH_Typedef *) DMA_CH6_BASE)
#define DMA_CLA_SRC_SEL     ((DMA_CLA_SRC_SEL_Typedef *) DMACLASRCSEL_BASE)

#define DMA_CONTROL_PERINTFRC_BIT   (1U << 3)   /* PERINTFRC: Force DMA trigger */
#define DMA_CONTROL_SOFTRESET_BIT   (1U << 2)   /* Reset DMA channel */
#define DMA_CONTROL_RUN_BIT         (1U << 0)   /* Run DMA channel */

#define DMA_MODE_DATASIZE_BIT       (1U << 14)  /* 0:16-bit, 1:32-bit */
#define DMA_MODE_CONTINUOUS_BIT     (1U << 11)  /* Continuous transfer mode */
#define DMA_MODE_PERINTE_BIT        (1U << 8)   /* Enable peripheral trigger */
#define DMA_MODE_PERINTSEL_Pos      (0U)        /* Legacy channel field position */ 

#define DMA_SRC_BURST_STEP_VALUE    (1U)
#define DMA_DST_BURST_STEP_VALUE    (1U)
#define DMA_TRANSFER_SIZE_VALUE     (0U)
#define DMA_SRC_TRANSFER_STEP_VALUE (0U)
#define DMA_DST_TRANSFER_STEP_VALUE (0U)
#define DMA_SRC_WRAP_SIZE_VALUE     (0U)
#define DMA_SRC_WRAP_STEP_VALUE     (0U)
#define DMA_DST_WRAP_SIZE_VALUE     (0U)
#define DMA_DST_WRAP_STEP_VALUE     (0U)

#define DMACHSRCSEL_CH_Msk         (0xFF)
#define DMACHSRCSEL_CH_BIT_SIZE    (8U)
#define DMACHSRCSEL1_CH_OFFSET     (1U)
#define DMACHSRCSEL2_CH_OFFSET     (5U)


/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void dma_force_trigger(uint16_t channel_number);
void dma_config(dma_str_t * str);

#endif /*BSP_DMA_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
