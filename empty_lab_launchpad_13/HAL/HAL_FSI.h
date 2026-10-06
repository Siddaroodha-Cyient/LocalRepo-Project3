/***********************************************************************************************
* File: HAL_FSI.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for FSI peripherals
*
* Purpose :
* HAL-level interface for FSI peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for FSI peripherals.
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
#ifndef HAL_FSI_H
#define HAL_FSI_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "BSP_FSI.h"
#include "BSP_GPIO.h"
#include <BSP_DMA.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef struct{
    gpio_peripheral_t clk;
    gpio_peripheral_t d0;
} fsi_gpio_t;

typedef struct{
    uint16_t byte_0:8;
    uint16_t byte_1:8;
    uint16_t byte_2:8;
    uint16_t byte_3:8;
    uint16_t byte_4:8;
    uint16_t byte_5:8;
    uint16_t byte_6:8;
    uint16_t byte_7:8;
    uint16_t byte_8:8;
    uint16_t byte_9:8;
    uint16_t byte_10:8;
    uint16_t byte_11:8;
    uint16_t byte_12:8;
    uint16_t byte_13:8;
    uint16_t byte_14:8;
    uint16_t byte_15:8;
    uint16_t byte_16:8;
    uint16_t byte_17:8;
    uint16_t byte_18:8;
    uint16_t byte_19:8;
} fsi_data_str_t;

typedef struct{
    uint16_t byte_0:8;
    uint16_t byte_1:8;
    uint16_t byte_2:8;
    uint16_t byte_3:8;
    uint16_t byte_4:8;
    uint16_t byte_5:8;
    uint16_t byte_6:8;
    uint16_t byte_7:8;
    uint16_t byte_8:8;
    uint16_t byte_9:8;
    uint16_t byte_10:8;
    uint16_t byte_11:8;
    uint16_t byte_12:8;
    uint16_t byte_13:8;
    uint16_t byte_14:8;
    uint16_t byte_15:8;
    uint16_t byte_16:8;
    uint16_t byte_17:8;
    uint16_t byte_18:8;
    uint16_t byte_19:8;
    uint16_t resv[6];
} fsi_data_dma_str_t;

typedef struct{
    fsi_gpio_t tx;
    fsi_gpio_t rx;
    fsi_data_str_t data_tx;
    fsi_data_str_t data_rx;
} fsi_struct_t;

typedef struct{
    fsi_gpio_t tx;
    fsi_gpio_t rx;
    dma_str_t dma_rx;
    dma_str_t dma_tx_data;
    dma_str_t dma_tx_tag;
} fsi_dma_struct_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void fsi_init(void);
void fsi_send_data(void);
void fsi_receive_data(void);
void fsi_dma_init(void);
void fsi_dma_send(void);
fsi_data_dma_str_t* fsi_dma_rx_data_get(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define FSI_RX_WORD_COUNT             (10U)         /* Number of RX words */
#define FSI_TX_WORD_COUNT             (10U)         /* Number of TX words */
#define FSI_TX_CLK_FREQUENCY          (10000000U)   /* TX clock = 10 MHz */

#define FSI_RX_DMA_WORD_COUNT         (16U)         /* RX frame size (words) */
#define FSI_TX_DMA_FREQ               (10000000U)   /* TX clock frequency (10 MHz) */
#define FSI_BUFFER_SIZE               (16U)         /* FSI FIFO size */

#define DMA_CH_2     (2U)  /* for data*/
#define DMA_CH_3     (3U)  /*for initiating FSI transfer*/

#endif/*HAL_FSI_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
