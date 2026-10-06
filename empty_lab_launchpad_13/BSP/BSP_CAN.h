/***********************************************************************************************
* File    : BSP_CAN.h
*
* Module  : Board Support Package (BSP) for CAN peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for CAN peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for CAN peripherals.
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
#ifndef BSP_CAN_H
#define BSP_CAN_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "BSP_MCAN.h"

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef struct {
    bp_32   CAN_CTL;               /* CAN Control Register                  */
    bp_32   CAN_ES;                /* Error and Status Register             */
    bp_32   CAN_ERRC;              /* Error Counter Register                */
    bp_32   CAN_BTR;               /* Bit Timing Register                   */
    bp_32   CAN_INT;               /* Interrupt Register                    */
    bp_32   CAN_TEST;              /* Test Register                         */
    uint32_t rsvd1[2];             /* Reserved */
    bp_32   CAN_PERR;              /* CAN Parity Error Code Register        */
    uint32_t rsvd2[16];            /* Reserved */
    bp_32   CAN_RAM_INIT;          /* CAN RAM Initialization Register       */
    uint32_t rsvd3[6];             /* Reserved */
    bp_32   CAN_GLB_INT_EN;        /* CAN Global Interrupt Enable Registe   */
    bp_32   CAN_GLB_INT_FLG;       /* CAN Global Interrupt Flag Register    */
    bp_32   CAN_GLB_INT_CLR;       /* CAN Global Interrupt Clear Register   */
    uint32_t rsvd4[18];            /* Reserved */
    bp_32   CAN_ABOTR;             /* Auto-Bus-On Time Register             */
    bp_32   CAN_TXRQ_X;            /* CAN Transmission Request Register     */
    bp_32   CAN_TXRQ_21;           /* CAN Transmission Request 2_1 Register */
    uint32_t rsvd5[6];             /* Reserved */
    bp_32   CAN_NDAT_X;            /* CAN New Data Register                 */
    bp_32   CAN_NDAT_21;           /* CAN New Data 2_1 Register             */
    uint32_t rsvd6[6];             /* Reserved */
    bp_32   CAN_IPEN_X;            /* CAN Interrupt Pending Register        */
    bp_32   CAN_IPEN_21;           /* CAN Interrupt Pending 2_1 Register    */
    uint32_t rsvd7[6];             /* Reserved */
    bp_32   CAN_MVAL_X;            /* CAN Message Valid Register            */
    bp_32   CAN_MVAL_21;           /* CAN Message Valid 2_1 Register        */
    uint32_t rsvd8[8];             /* Reserved */
    bp_32   CAN_IP_MUX21;          /* CAN Interrupt Multiplexer 2_1 Register*/
    uint32_t rsvd9[18];            /* Reserved */
    bp_32   CAN_IF1CMD;            /* IF1 Command Register                  */
    bp_32   CAN_IF1MSK;            /* IF1 Mask Register                     */
    bp_32   CAN_IF1ARB;            /* IF1 Arbitration Register              */
    bp_32   CAN_IF1MCTL;           /* IF1 Message Control Register          */
    bp_32   CAN_IF1DATA;           /* IF1 Data A Register                   */
    bp_32   CAN_IF1DATB;           /* IF1 Data B Register                   */
    uint32_t rsvd10[4];            /* Reserved */
    bp_32   CAN_IF2CMD;            /* IF2 Command Register                  */
    bp_32   CAN_IF2MSK;            /* IF2 Mask Register */
    bp_32   CAN_IF2ARB;            /* IF2 Arbitration Register              */
    bp_32   CAN_IF2MCTL;           /* IF2 Message Control Register          */
    bp_32   CAN_IF2DATA;           /* IF2 Data A Register                   */
    bp_32   CAN_IF2DATB;           /* IF2 Data B Register                   */
    uint32_t rsvd11[4];            /* Reserved*/
    bp_32   CAN_IF3OBS;            /* IF3 Observation Register              */
    bp_32   CAN_IF3MSK;            /* IF3 Mask Register*/
    bp_32   CAN_IF3ARB;            /* IF3 Arbitration Register              */
    bp_32   CAN_IF3MCTL;           /* IF3 Message Control Register          */
    bp_32   CAN_IF3DATA;           /* IF3 Data A Register                   */
    bp_32   CAN_IF3DATB;           /* IF3 Data B Register                   */
    uint32_t rsvd12[4];            /* Reserved*/
    bp_32   CAN_IF3UPD;            /* IF3 Update Enable Register            */
} CAN_REGS_Typedef;

typedef struct{
    uint32_t Data_4:8;
    uint32_t Data_5:8;
    uint32_t Data_6:8;
    uint32_t Data_7:8;
}  CAN_IFDATB_t;

typedef struct{
    uint32_t Data_0:8;
    uint32_t Data_1:8;
    uint32_t Data_2:8;
    uint32_t Data_3:8;
}  CAN_IFDATA_t;

typedef struct{
    uint32_t DLC:4;
    uint32_t rsvd1:3;
    uint32_t EoB:1;
    uint32_t TxRqst:1;
    uint32_t RmtEn:1;
    uint32_t RxIE:1;
    uint32_t TxIE:1;
    uint32_t UMask:1;
    uint32_t IntPnd:1;
    uint32_t MsgLst:1;
    uint32_t NewDat:1;
    uint32_t rsvd2:16;
} CAN_IFMCTL_t;

typedef struct{
    uint32_t ID:29;
    uint32_t Dir:1;
    uint32_t Xtd:1;
    uint32_t MsgVal:1;
} CAN_IFARB_t;

typedef struct{
    uint32_t Msk:29;
    uint32_t rsvd:1;
    uint32_t MDir:1;
    uint32_t MXtd:1;
} CAN_IFMSK_t;

typedef struct{
    uint32_t msg_num:8;
    uint32_t rsvd1:6;
    uint32_t DMAactive:1;
    uint32_t Busy:1;
    uint32_t DATA_B:1;
    uint32_t DATA_A:1;
    uint32_t TXRQST:1;
    uint32_t ClrIntPnd:1;
    uint32_t Control:1;
    uint32_t Arb:1;
    uint32_t Mask:1;
    uint32_t DIR:1;
    uint32_t rsvd2:8;
} CAN_IFCMD_t;

typedef struct{
    uint32_t id;
    CAN_IFDATA_t data_a;
    CAN_IFDATB_t data_b;
    uint32_t message_number;
} can_tx_rx_str_t;

typedef struct{
    gpio_peripheral_t tx;
    gpio_peripheral_t rx;
} can_struct_t;

typedef enum{
    no_msg_received = 0,
    msg_received =1,
} can_message_receive_status_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void can_timing_config(void);
void can_config_rx(void);
void can_config_rx_filter(uint32_t id);
void can_message_send(can_tx_rx_str_t * str);
uint16_t can_message_receive(can_tx_rx_str_t * str);
void can_config(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define MESSAGE_NUMBER_RX_FILTER        1
#define MESSAGE_NUMBER_RX_ALL           2
#define MESSAGE_NUMBER_TX_ECHO          3
#define MESSAGE_NUMBER_TX_TELEMETRY     4

#define CAN_TEST_LBACK          ((uint32_t)0x00000010)      /* 4 */
    
#define CAN_CTL_INIT            ((uint32_t)0x00000001)      /* 0 */ 
#define CAN_CTL_CCE             ((uint32_t)0x00000040)      /* 6 */ 
#define CAN_CTL_ABO             ((uint32_t)0x00000200)      /* 9 */ 
#define CAN_CTL_TEST            ((uint32_t)0x00000080)      /* 7 */ 

#define CAN_BTR_BRPE_Msk        ((uint32_t)0x000F0000)      /* Baud Rate Prescaler Extension        */
#define CAN_BTR_TSEG2_Msk       ((uint32_t)0x00007000)      /* Time segment after the sample point  */
#define CAN_BTR_TSEG1_Msk       ((uint32_t)0x00000F00)      /* Time segment before the sample point */
#define CAN_BTR_SJW_Msk         ((uint32_t)0x000000C0)      /* Synchronization Jump Width           */
#define CAN_BTR_BRP_Msk         ((uint32_t)0x0000003F)      /* Baud Rate Prescaler                  */

#define CAN_BTR_BRPE_Pos        ((uint32_t)16)              /* Baud Rate Prescaler Extension        */
#define CAN_BTR_TSEG2_Pos       ((uint32_t)12)              /* Time segment after the sample point  */
#define CAN_BTR_TSEG1_Pos       ((uint32_t)8)               /* Time segment before the sample point */
#define CAN_BTR_SJW_Pos         ((uint32_t)6)               /* Synchronization Jump Width           */
#define CAN_BTR_BRP_Pos         ((uint32_t)0)               /* Baud Rate Prescaler                  */

#define CAN_BTR_SJW_VALUE       (3U)                        /* Sync Jump Width */
#define CAN_BTR_BRPE_VALUE      (5U)                        /* Baud rate prescaler */
#define CAN_BTR_TSEG1_VALUE     (10U)                       /* Time segment 1 */
#define CAN_BTR_TSEG2_VALUE     (7U)                        /* Time segment 2 */

#define MESSAGE_NUMBER_1        (0x01)                    

#define CAN_IFMCTL_EOB          ((uint32_t)0x00000080)
#define CAN_IFMCTL_TXRQST       ((uint32_t)0x00000100)
#define CAN_IFMCTL_RMTEN        ((uint32_t)0x00000200)
#define CAN_IFMCTL_RXIE         ((uint32_t)0x00000400)
#define CAN_IFMCTL_TXIE         ((uint32_t)0x00000800)
#define CAN_IFMCTL_UMASK        ((uint32_t)0x00001000)
#define CAN_IFMCTL_INTPND       ((uint32_t)0x00002000)
#define CAN_IFMCTL_MSGLST       ((uint32_t)0x00004000)
#define CAN_IFMCTL_NEWDAT       ((uint32_t)0x00008000)
#define CAN_IFMCTL_DLC_Msk      ((uint32_t)0x0000000F)

#define CAN_IFMCTL_DLC_Pos      ((uint32_t)00)

#define CAN_IFMCTL_DLC_VALUE    (8U)

#define CAN_IFMCMD_DIR          ((uint32_t)0x00800000)
#define CAN_IFMCMD_MASK         ((uint32_t)0x00400000)
#define CAN_IFMCMD_ARB          ((uint32_t)0x00200000)
#define CAN_IFMCMD_CONTROL      ((uint32_t)0x00100000)
#define CAN_IFMCMD_CLRINTPND    ((uint32_t)0x00080000)
#define CAN_IFMCMD_TXRQST       ((uint32_t)0x00040000)
#define CAN_IFMCMD_DATA_A       ((uint32_t)0x00020000)
#define CAN_IFMCMD_DATA_B       ((uint32_t)0x00010000)
#define CAN_IFMCMD_BUSY         ((uint32_t)0x00008000)

#define CAN_IFMCMD_MSG_NUM_Msk  ((uint32_t)0x000000FF)
#define CAN_IFMCMD_MSG_NUM_Pos  ((uint32_t)0)

#define CAN_IFMSK_MXTD          ((uint32_t)0x80000000)
#define CAN_IFMSK_MDIR          ((uint32_t)0x40000000)

#define CAN_IFMSK_MSK_Msk       ((uint32_t)0x1FFFFFFF)
#define CAN_IFMSK_MSK_Pos       ((uint32_t)0)

#define CAN_IFARB_ID_Msk        ((uint32_t)0x1FFFFFFF)
#define CAN_IFARB_ID_Pos        ((uint32_t)0)

#define CAN_IFARB_DIR           ((uint32_t)0x20000000)
#define CAN_IFARB_XTD           ((uint32_t)0x40000000)
#define CAN_IFARB_MSGVAL        ((uint32_t)0x80000000)

#define CANA_BASE           0x00048000
#define CAN                 ((CAN_REGS_Typedef *)CANA_BASE)

#endif/*BSP_CAN_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
