/***********************************************************************************************
* File    : BSP_FSI.h
*
* Module  : Board Support Package (BSP) for FSI peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for FSI peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for FSI peripherals.
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
#ifndef BSP_FSI_H
#define BSP_FSI_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <BSP_CLOCK.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef struct{
    uint16_t TX_MASTER_CTRL;         /* 0h Transmit main control register  */
    uint16_t resv1;
    uint16_t TX_CLK_CTRL;            /* 2h Transmit clock control register */
    uint16_t resv2;
    uint16_t TX_OPER_CTRL_LO;        /* 4h Transmit operation control register low  */
    uint16_t TX_OPER_CTRL_HI;        /* 5h Transmit operation control register high */
    uint16_t TX_FRAME_CTRL;          /* 6h Transmit frame control register          */
    uint16_t TX_FRAME_TAG_UDATA;     /* 7h Transmit frame tag and user data register        */
    uint16_t TX_BUF_PTR_LOAD;        /* 8h Transmit buffer pointer control load register    */
    uint16_t TX_BUF_PTR_STS;         /* 9h Transmit buffer pointer control status register  */
    uint16_t TX_PING_CTRL;           /* Ah Transmit ping control register   */
    uint16_t TX_PING_TAG;            /* Bh Transmit ping tag register       */
    uint32_t TX_PING_TO_REF;         /* Ch Transmit ping timeout counter reference      */
    uint32_t TX_PING_TO_CNT;         /* Eh Transmit ping timeout current count          */
    uint16_t TX_INT_CTRL;            /* 10h Transmit interrupt event control register   */
    uint16_t TX_DMA_CTRL;            /* 11h Transmit DMA event control register         */
    uint16_t TX_LOCK_CTRL;           /* 12h Transmit lock control register              */
    uint16_t resv3;
    uint16_t TX_EVT_STS;             /* 14h Transmit event and error status flag register   */
    uint16_t resv4;
    uint16_t TX_EVT_CLR;             /* 16h Transmit event and error clear register EALLOW  */
    uint16_t TX_EVT_FRC;             /* 17h Transmit event and error flag force register    */
    uint16_t TX_USER_CRC;            /* 18h Transmit user-defined CRC register              */
    uint16_t resv5[7];
    uint32_t TX_ECC_DATA;            /* 20h Transmit ECC data register  */
    uint16_t TX_ECC_VAL;             /* 22h Transmit ECC value register */
    uint16_t resv6;
    uint16_t TX_DLYLINE_CTRL;        /* 24h Transmit delay Line control register */
    uint16_t resv7[27];
    uint16_t TX_BUF_BASE[16];
} FSI_TX_REGS_Typedef;

typedef struct{
    uint16_t RX_MASTER_CTRL;             /* 0h Receive main control register        */
    uint16_t resv1[3];
    uint16_t RX_OPER_CTRL;               /* 4h Receive operation control register   */
    uint16_t resv2;
    uint16_t RX_FRAME_INFO;              /* 6h Receive frame control register       */
    uint16_t RX_FRAME_TAG_UDATA;         /* 7h Receive frame tag and user data register */
    uint16_t RX_DMA_CTRL;                /* 8h Receive DMA event control register       */
    uint16_t resv3;
    uint16_t RX_EVT_STS;                 /* Ah Receive event and error status flag register */
    uint16_t RX_CRC_INFO;                /* Bh Receive CRC info of received and computed CRC*/
    uint16_t RX_EVT_CLR;                 /* Ch Receive event and error clear register       */
    uint16_t RX_EVT_FRC;                 /* Dh Receive event and error flag force register  */
    uint16_t RX_BUF_PTR_LOAD;            /* Eh Receive buffer pointer load register         */
    uint16_t RX_BUF_PTR_STS;             /* Fh Receive buffer pointer status register       */
    uint16_t RX_FRAME_WD_CTRL;           /* 10h Receive frame watchdog control register     */
    uint16_t resv4;
    uint32_t RX_FRAME_WD_REF;            /* 12h Receive frame watchdog counter reference    */
    uint32_t RX_FRAME_WD_CNT;            /* 14h Receive frame watchdog current count        */
    uint16_t RX_PING_WD_CTRL;            /* 16h Receive ping watchdog control register      */
    uint16_t RX_PING_TAG;                /* 17h Receive ping tag register                   */
    uint32_t RX_PING_WD_REF;             /* 18h Receive ping watchdog counter reference     */
    uint32_t RX_PING_WD_CNT;             /* 1Ah Receive pingwatchdog current count          */
    uint16_t RX_INT1_CTRL;               /* 1Ch Receive interrupt control register for RX_INT1 */
    uint16_t RX_INT2_CTRL;               /* 1Dh Receive interrupt control register for RX_INT2 */
    uint16_t RX_LOCK_CTRL;               /* 1Eh Receive lock control register */
    uint16_t resv5;
    uint32_t RX_ECC_DATA;                /* 20h Receive ECC data register   */
    uint16_t RX_ECC_VAL;                 /* 22h Receive ECC value register  */
    uint16_t resv6;
    uint32_t RX_ECC_SEC_DATA;            /* 24h Receive ECC corrected data register */
    uint16_t RX_ECC_LOG;                 /* 26h Receive ECC log and status register */
    uint16_t resv7;
    uint16_t RX_FRAME_TAG_CMP;           /* 28h Receive frame tag compare register  */
    uint16_t RX_PING_TAG_CMP;            /* 29h Receive ping tag compare register   */
    uint16_t resv8[2];
    uint32_t RX_TRIG_CTRL_0;             /* 2Ch Receive Trigger Control register 0  */
    uint32_t RX_TRIG_WIDTH_0;            /* 2Eh Receive Trigger Wdith register 0    */
    uint16_t RX_DLYLINE_CTRL;            /* 30h Receive delay line control register */
    uint16_t resv9;
    uint32_t RX_TRIG_CTRL_1;             /* 32h Receive Trigger Control register 1  */
    uint32_t RX_TRIG_CTRL_2;             /* 34h Receive Trigger Control register 2  */
    uint32_t RX_TRIG_CTRL_3;             /* 36h Receive Trigger Control register 3  */
    uint32_t RX_VIS_1;                   /* 38h Receive debug visibility register 1 */
    uint16_t RX_UDATA_FILTER;            /* 3Ah Receive User Data Filter Control register */
    uint16_t resv10[5];
    uint16_t RX_BUF_BASE[16];
} FSI_RX_REGS_Typedef;

typedef enum{
    fsi_frame_type_ping,
    fsi_frame_type_data,
    fsi_frame_type_error,
} fsi_frame_type_t;

typedef struct{
    uint16_t * data;
    uint16_t user_data:8;
    uint16_t frame_tag:4;
    uint16_t no_of_words;
    fsi_frame_type_t frame_type;
} fsi_tx_str_t;

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define FSITXA_BASE             0x00006600
#define FSIRXA_BASE             0x00006680

#define FSI_TX            ((FSI_TX_REGS_Typedef *) FSITXA_BASE)
#define FSI_RX            ((FSI_RX_REGS_Typedef *) FSIRXA_BASE)

#define TX_CLK_CTRL_CLK_RST                 ((uint32_t)0x00000001)      /* 0    */
#define TX_CLK_CTRL_CLK_EN                  ((uint32_t)0x00000002)      /* 1    */
#define TX_CLK_CTRL_PRESCALE_VAL_Msk        ((uint32_t)0x000003FC)      /* 2:9  */
#define TX_CLK_CTRL_PRESCALE_VAL_Pos        ((uint32_t)2)               /* 2:9  */

#define TX_OPER_CTRL_LO_SEL_PLLCLK          ((uint32_t)0x00000100)      /* 8    */
#define TX_OPER_CTRL_LO_START_MODE_Msk      ((uint32_t)0x00000038)      /* 3:5  */
#define TX_OPER_CTRL_LO_START_MODE_Pos      ((uint32_t)3)               /* 3:5  */

#define TX_FRAME_CTRL_FRAME_TYPE_Msk        ((uint32_t)0x0000000F)      /* 0:3  */
#define TX_FRAME_CTRL_FRAME_TYPE_Pos        ((uint32_t)0)               /* 0:3  */

#define TX_FRAME_CTRL_N_WORDS_Msk           ((uint32_t)0x000000F0)      /* 4:7  */
#define TX_FRAME_CTRL_N_WORDS_Pos           ((uint32_t)4)               /* 4:7  */

#define TX_FRAME_CTRL_START                 ((uint32_t)0x00008000)      /* 15   */

#define TX_FRAME_TAG_UDATA_FRAME_TAG_Msk    ((uint32_t)0x0000000F)      /* 0:3  */
#define TX_FRAME_TAG_UDATA_FRAME_TAG_Pos    ((uint32_t)0)               /* 0:3  */

#define TX_FRAME_TAG_UDATA_USER_DATA_Msk    ((uint32_t)0x0000FF00)      /* 8:15 */
#define TX_FRAME_TAG_UDATA_USER_DATA_Pos    ((uint32_t)4)               /* 8:15 */

#define RX_OPER_CTRL_N_WORDS_Msk            ((uint32_t)0x00000078)      /* 3:6  */
#define RX_OPER_CTRL_N_WORDS_Pos            ((uint32_t)3)               /* 3:6  */

#define RX_EVT_STS_DATA_FRAME               ((uint16_t)0x0800)          /* 11   */
#define RX_EVT_CLR_DATA_FRAME               ((uint16_t)0x0800)          /* 11   */

#define TX_DMA_CTRL_DMA_EVT_EN              ((uint16_t)0x0001)          /* 0    */
#define RX_DMA_CTRL_DMA_EVT_EN              ((uint16_t)0x0001)          /* 0    */

#define FRAME_TYPE_PING             ((uint16_t)0b0000)
#define FRAME_TYPE_DATA_1_WORD      ((uint16_t)0b0100)
#define FRAME_TYPE_DATA_2_WORD      ((uint16_t)0b0101)
#define FRAME_TYPE_DATA_4_WORD      ((uint16_t)0b0110)
#define FRAME_TYPE_DATA_6_WORD      ((uint16_t)0b0111)
#define FRAME_TYPE_DATA_N_WORD      ((uint16_t)0b0011)
#define FRAME_TYPE_ERROR            ((uint16_t)0b1111)

#define FSI_TX_MASTER_CTRL_START     (0xA501U)
#define FSI_TX_MASTER_CTRL_CLEAR     (0xA500U)
#define FSI_TX_STARTUP_DELAY_COUNT   (4U)

#define FSI_RX_MASTER_CTRL_START     (0xA501U)
#define FSI_RX_MASTER_CTRL_CLEAR     (0xA500U)
#define FSI_RX_STARTUP_DELAY_COUNT   (4U)


#define FSI_TX_MASTER_CTRL_FLUSH     (0xA502U)                            /* Flush/reset TX */
#define FSI_TX_MASTER_CTRL_CLEAR     (0xA500U)                            /* Normal/reset state */
#define FSI_TX_FLUSH_DELAY_COUNT     (40U)

#define TX_OPER_CTRL_LO_START_MODE_VALUE   (2U)                           /* Start on frame control */
#define FSI_FRAME_WORD_COUNT_MASK          (0x0F)                        /* 4-bit field (max 16 words) */
#define FSI_TX_BUFFER_SIZE                 (16U)
#define FSI_RX_BUFFER_SIZE                 (16U)

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void fsi_tx_init(uint32_t frequency);
void fsi_rx_init(uint16_t no_of_words);
void fsi_send(fsi_tx_str_t * str);
void fsi_tx_flush(void);
uint16_t fsi_is_data_frame_received(void);
void fsi_receive(uint16_t * data, uint16_t no_of_words);
void fsi_rx_dma_enable(void);
void fsi_tx_dma_enable(void);
void fsi_config_data_frame(uint16_t no_of_words);

#endif/*BSP_FSI_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/

