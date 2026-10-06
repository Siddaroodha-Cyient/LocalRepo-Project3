/***********************************************************************************************
* File    : BSP_MCAN.h
*
* Module  : Board Support Package (BSP) for MCAN peripherals 
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for MCAN peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for MCAN peripherals.
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
#ifndef BSP_MCAN_H
#define BSP_MCAN_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>
#include "BSP_GPIO.h"

/****************************************************************************** 
* Type Definitions 
******************************************************************************/
typedef uint32_t bp_32 __attribute__((byte_peripheral));

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/

/* Structure used to access MCAN subsystem peripheral registers */ 
typedef struct{
    bp_32 PID;                            /* 0h MCAN Subsystem Revision Register                        */
    bp_32 CTRL;                           /* 2h MCAN Subsystem Control Register                         */
    bp_32 STAT;                           /* 4h MCAN Subsystem Status Register                          */
    bp_32 ICS;                            /* 6h MCAN Subsystem Interrupt Clear Shadow Register          */
    bp_32 IRS;                            /* 8h MCAN Subsystem Interrupt Raw Satus Register             */
    bp_32 IECS;                           /* Ah MCAN Subsystem Interrupt Enable Clear Shadow Register   */
    bp_32 IE;                             /* Ch MCAN Subsystem Interrupt Enable Register                */
    bp_32 IES;                            /* Eh MCAN Subsystem Interrupt Enable Status                  */
    bp_32 EOI;                            /* 10h MCAN Subsystem End of Interrupt                        */
    bp_32 EXT_TS_PRESCALER;               /* 12h MCAN Subsystem External Timestamp Prescaler 0          */
    bp_32 EXT_TS_UNSERVICED_INTR_CNTR;    /* 14h MCAN Subsystem External Timestamp Unserviced Interrupts Counter */
} MCANSS_Typedef;

/* Structure used to access MCAN peripheral registers */ 
typedef struct{
    bp_32 CREL;         /* 0h MCAN Core Release Register */
    bp_32 ENDN;         /* 2h MCAN Endian Register */
    uint32_t resv1[2];
    bp_32 DBTP;         /* 6h MCAN Data Bit Timing and Prescaler Register*/
    bp_32 TEST;         /* 8h MCAN Test Register */
    bp_32 RWD;          /* Ah MCAN RAM Watchdog */
    bp_32 CCCR;         /* Ch MCAN CC Control Register */
    bp_32 NBTP;         /* Eh MCAN Nominal Bit Timing and Prescaler Register */
    bp_32 TSCC;         /* 10h MCAN Timestamp Counter Configuration */
    bp_32 TSCV;         /* 12h MCAN Timestamp Counter Value */
    bp_32 TOCC;         /* 14h MCAN Timeout Counter Configuration */
    bp_32 TOCV;         /* 16h MCAN Timeout Counter Value */
    uint32_t resv2[8];
    bp_32 ECR;          /* 20h MCAN Error Counter Register */
    bp_32 PSR;          /* 22h MCAN Protocol Status Register */
    bp_32 TDCR;         /* 24h MCAN Transmitter Delay Compensation Register*/
    uint32_t resv3[2];
    bp_32 IR;           /* 28h MCAN Interrupt Register */
    bp_32 IE;           /* 2Ah MCAN Interrupt Enable */
    bp_32 ILS;          /* 2Ch MCAN Interrupt Line Select */
    bp_32 ILE;          /* 2Eh MCAN Interrupt Line Enable */
    uint32_t resv4[16];
    bp_32 GFC;          /* 40h MCAN Global Filter Configuration */
    bp_32 SIDFC;        /* 42h MCAN Standard ID Filter Configuration */
    bp_32 XIDFC;        /* 44h MCAN Extended ID Filter Configuration */
    uint32_t resv5[2];
    bp_32 XIDAM;        /* 48h MCAN Extended ID and Mask */
    bp_32 HPMS;         /* 4Ah MCAN High Priority Message Status */
    bp_32 NDAT1;        /* 4Ch MCAN New Data 1 */
    bp_32 NDAT2;        /* 4Eh MCAN New Data 2 */
    bp_32 RXF0C;        /* 50h MCAN Rx FIFO 0 Configuration */
    bp_32 RXF0S;        /* 52h MCAN Rx FIFO 0 Status */
    bp_32 RXF0A;        /* 54h MCAN Rx FIFO 0 Acknowledge */
    bp_32 RXBC;         /* 56h MCAN Rx Buffer Configuration */
    bp_32 RXF1C;        /* 58h MCAN Rx FIFO 1 Configuration */
    bp_32 RXF1S;        /* 5Ah MCAN Rx FIFO 1 Status */
    bp_32 RXF1A;        /* 5Ch MCAN Rx FIFO 1 Acknowledge */
    bp_32 RXESC;        /* 5Eh MCAN Rx Buffer / FIFO Element Size Configuration*/
    bp_32 TXBC;         /* 60h MCAN Tx Buffer Configuration */
    bp_32 TXFQS;        /* 62h MCAN Tx FIFO / Queue Status */
    bp_32 TXESC;        /* 64h MCAN Tx Buffer Element Size Configuration */
    bp_32 TXBRP;        /* 66h MCAN Tx Buffer Request Pending */
    bp_32 TXBAR;        /* 68h MCAN Tx Buffer Add Request */
    bp_32 TXBCR;        /* 6Ah MCAN Tx Buffer Cancellation Request */
    bp_32 TXBTO;        /* 6Ch MCAN Tx Buffer Transmission Occurred */
    bp_32 TXBCF;        /* 6Eh MCAN Tx Buffer Cancellation Finished */
    bp_32 TXBTIE;       /* 70h MCAN Tx Buffer Transmission Interrupt Enable*/
    bp_32 TXBCIE;       /* 72h MCAN Tx Buffer Cancellation Finished Interrupt Enable*/
    uint32_t resv6[4];
    bp_32 TXEFC;        /* 78h MCAN Tx Event FIFO Configuration */
    bp_32 TXEFS;        /* 7Ah MCAN Tx Event FIFO Status */
    bp_32 TXEFA;        /* 7Ch MCAN Tx Event FIFO Acknowledge */
} MCAN_Typedef;

/* Structure used to access MCAN error peripheral registers */ 
typedef struct{
    bp_32 _REV;                   /* 0h MCAN Error Aggregator Revision Register */
    uint32_t resv1[2];
    bp_32 VECTOR;                /* 4h MCAN ECC Vector Register */
    bp_32 STAT;                  /* 6h MCAN Error Misc Status */
    bp_32 WRAP_REV;              /* 8h MCAN ECC Wrapper Revision Register */
    bp_32 CTRL;                  /* Ah MCAN ECC Control */
    bp_32 ERR_CTRL1;             /* Ch MCAN ECC Error Control 1 Register */
    bp_32 ERR_CTRL2;             /* Eh MCAN ECC Error Control 2 Register */
    bp_32 ERR_STAT1;             /* 10h MCAN ECC Error Status 1 Register */
    bp_32 ERR_STAT2;             /* 12h MCAN ECC Error Status 2 Register */
    bp_32 ERR_STAT3;             /* 14h MCAN ECC Error Status 3 Register */
    uint32_t resv2[8];
    bp_32 SEC_EOI;               /* 1Eh MCAN Single Error Corrected End of Interrupt Register*/
    bp_32 SEC_STATUS;            /* 20h MCAN Single Error Corrected Interrupt Status Register*/
    uint32_t resv3[30];
    bp_32 SEC_ENABLE_SET;        /* 40h MCAN Single Error Corrected Interrupt Enable Set Register*/
    uint32_t resv4[30];
    bp_32 SEC_ENABLE_CLR;        /* 60h MCAN Single Error Corrected Interrupt Enable Clear Register*/
    uint32_t resv5[60];
    bp_32 DED_EOI;               /* 9Eh MCAN Double Error Detected End of Interrupt Register*/
    bp_32 DED_STATUS;            /* A0h MCAN Double Error Detected Interrupt Status Register*/
    uint32_t resv6[30];
    bp_32 DED_ENABLE_SET;        /* C0h MCAN Double Error Detected Interrupt Enable Set Register*/
    uint32_t resv7[30];
    bp_32 DED_ENABLE_CLR;        /* E0h MCAN Double Error Detected Interrupt Enable Clear Register*/
    uint32_t resv8[30];
    bp_32 AGGR_ENABLE_SET;       /* 100h MCAN Error Aggregator Enable Set Register */
    bp_32 AGGR_ENABLE_CLR;       /* 102h MCAN Error Aggregator Enable Clear Register*/
    bp_32 AGGR_STATUS_SET;       /* 104h MCAN Error Aggregator Status Set Register */
    bp_32 AGGR_STATUS_CLR;       /* 106h MCAN Error Aggregator Status Clear Register*/
} MCAN_ERROR_Typedef;


/* Structure used to access MCAN tx buffer bits */ 
typedef struct{
    uint32_t id:29;
    uint32_t rtr:1;
    uint32_t xtd:1;
    uint32_t esi:1;
    uint32_t resv1:16;
    uint32_t dlc:4;
    uint32_t brs:1;
    uint32_t fdf:1;
    uint32_t resv2:1;
    uint32_t efc:1;
    uint32_t mm:8;
    uint32_t bd0:8;
    uint32_t bd1:8;
    uint32_t bd2:8;
    uint32_t bd3:8;
    uint32_t bd4:8;
    uint32_t bd5:8;
    uint32_t bd6:8;
    uint32_t bd7:8;
} mcan_tx_buffer_element_t;

/* Structure used to access MCAN rx buffer bits */ 
typedef struct{
    uint32_t id:29;
    uint32_t rtr:1;
    uint32_t xtd:1;
    uint32_t esi:1;
    uint32_t rxts:16;
    uint32_t dlc:4;
    uint32_t brs:1;
    uint32_t fdf:1;
    uint32_t resv2:2;
    uint32_t fidx:7;
    uint32_t anmf:1;
    uint32_t bd0:8;
    uint32_t bd1:8;
    uint32_t bd2:8;
    uint32_t bd3:8;
    uint32_t bd4:8;
    uint32_t bd5:8;
    uint32_t bd6:8;
    uint32_t bd7:8;
} mcan_rx_buffer_element_t;

/* Structure used to access MCAN extended frame filter bits */ 
typedef struct{
    uint32_t efid1:29;
    uint32_t efec:3;
    uint32_t efid2:29;
    uint32_t res:1;
    uint32_t eft:2;
} mcan_extended_filter_t;

typedef struct{
    gpio_peripheral_t tx;
    gpio_peripheral_t rx;
} mcan_struct_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void mcan_timing_config(void);
void mcan_config(void);
void mcan_filter_config(void);
void mcan_filter_update(mcan_extended_filter_t * filter);
uint16_t mcan_message_send(mcan_tx_buffer_element_t * element);
uint16_t mcan_message_receive(mcan_rx_buffer_element_t * element);
void mcan_tx_element_default(mcan_tx_buffer_element_t * tx_element);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define MCAN_CCCR_INIT          ((uint32_t)0x00000001)      /* 0 Initialization*/
#define MCAN_CCCR_CCE           ((uint32_t)0x00000002)      /* 1 Configuration Change Enable*/
#define MCAN_CCCR_TEST          ((uint32_t)0x00000080)      /* 7  Test Mode Enable */
#define MCAN_CCCR_FDOE          ((uint32_t)0x00000100)      /* 8 Flexible Datarate Operation Enable*/
#define MCAN_CCCR_BRSE          ((uint32_t)0x00000200)      /* 9 Bit Rate Switch Enable*/
#define MCAN_CCCR_NISO          ((uint32_t)0x00008000)      /* 15 Non ISO Operation*/

#define MCAN_NBTP_NSJW_Msk      ((uint32_t)0xFE000000)      /* Nominal (Re)Synchronization Jump Width */
#define MCAN_NBTP_NBRP_Msk      ((uint32_t)0x01FF0000)      /* Nominal Bit Rate Prescaler */
#define MCAN_NBTP_NTSEG1_Msk    ((uint32_t)0x0000FF00)      /* Nominal Time Segment Before Sample Point */
#define MCAN_NBTP_NTSEG2_Msk    ((uint32_t)0x0000007F)      /* Nominal Time Segment After Sample Point */

#define MCAN_NBTP_NSJW_Pos      ((uint32_t)0x19)      /* Nominal (Re)Synchronization Jump Width */
#define MCAN_NBTP_NBRP_Pos      ((uint32_t)0x10)      /* Nominal Bit Rate Prescaler */
#define MCAN_NBTP_NTSEG1_Pos    ((uint32_t)0x08)      /* Nominal Time Segment Before Sample Point */
#define MCAN_NBTP_NTSEG2_Pos    ((uint32_t)0x00)      /* Nominal Time Segment After Sample Point */

#define MCAN_NSJW_VALUE          (3U)    /* SJW value       */
#define MCAN_NBRP_VALUE          (5U)    /* Prescaler value */
#define MCAN_NTSEG1_VALUE        (10U)   /* TSEG1 value     */
#define MCAN_NTSEG2_VALUE        (7U)    /* TSEG2 value     */

#define MCAN_TEST_LBCK          ((uint32_t)0x00000010)      /* 4 Loop Back Mode */

#define MCAN_RXBC_RBSA_Msk      ((uint32_t)0x0000FFFE)      /* 15:2 Rx Buffers Start Address */
#define MCAN_RXBC_RBSA_Pos      ((uint32_t)0x02)            /* 15:2 Rx Buffers Start Address */
#define MCAN_RXBC_RBSA_VALUE    (0x20U)                     /* RX buffer start address */

#define MCAN_RXESC_RBDS_Msk     ((uint32_t)0x00000700)      /* 10:8 Rx Buffer Data Field Size*/
#define MCAN_RXESC_F1DS_Msk     ((uint32_t)0x00000070)      /* 6:4 Rx FIFO 1 Data Data Field Size*/
#define MCAN_RXESC_F0DS_Msk     ((uint32_t)0x00000007)      /* 2:0 Rx FIFO 0 Data Data Field Size*/
#define MCAN_RXESC_RBDS_Pos     ((uint32_t)0x08)            /* 10:8 Rx Buffer Data Field Size*/
#define MCAN_RXESC_F1DS_Pos     ((uint32_t)0x04)            /* 6:4 Rx FIFO 1 Data Data Field Size*/
#define MCAN_RXESC_F0DS_Pos     ((uint32_t)0x00)            /* 2:0 Rx FIFO 0 Data Data Field Size*/

#define MCAN_RXF0C_F0S_Msk      ((uint32_t)0x007F0000)      /* 22:16 Rx FIFO 0 Size*/
#define MCAN_RXF0C_F0SA_Msk     ((uint32_t)0x0000FFFE)      /*  15:2 Rx FIFO 0 Start Address*/

#define MCAN_RXF0C_F0S_Pos      ((uint32_t)0x10)            /* 22:16 Rx FIFO 0 Size*/
#define MCAN_RXF0C_F0SA_Pos     ((uint32_t)0x02)            /*  15:2 Rx FIFO 0 Start Address*/

#define MCAN_RXF0C_F0S_VALUE    (64U)                       /* RX FIFO0 size */

#define MCAN_RXF0S_RF0L         ((uint32_t)0x02000000)      /* 25*/
#define MCAN_RXF0S_F0F          ((uint32_t)0x01000000)      /* 24*/
#define MCAN_RXF0S_F0PI_Msk     ((uint32_t)0x003F0000)      /* 21:16*/
#define MCAN_RXF0S_F0GI_Msk     ((uint32_t)0x00003F00)      /* 13:8*/
#define MCAN_RXF0S_F0FL_Msk     ((uint32_t)0x0000007F)      /* 6:0*/

#define MCAN_RXF0S_F0PI_Pos     ((uint32_t)0x10)            /* 21:16*/
#define MCAN_RXF0S_F0GI_Pos     ((uint32_t)0x08)            /* 13:8*/
#define MCAN_RXF0S_F0FL_Pos     ((uint32_t)0x00)            /* 6:0*/

#define MCA_RXF0A_F0AI_Msk      ((uint32_t)0x0000003F)      /* 5:0*/
#define MCA_RXF0A_F0AI_Pos      ((uint32_t)0x00)            /* 5:0*/

#define MCAN_RXF1C_F1S_Msk      ((uint32_t)0x007F0000)      /* 22:16 Rx FIFO 0 Size*/
#define MCAN_RXF1C_F1SA_Msk     ((uint32_t)0x0000FFFE)      /*  15:2 Rx FIFO 0 Start Address*/

#define MCAN_RXF1C_F1S_Pos      ((uint32_t)0x10)            /* 22:16 Rx FIFO 0 Size*/
#define MCAN_RXF1C_F1SA_Pos     ((uint32_t)0x02)            /*  15:2 Rx FIFO 0 Start Address*/

#define MCAN_RXF1C_F1S_VALUE    (10U)                       /* RX FIFO1 size */

#define MCAN_RXF1S_RF1L         ((uint32_t)0x02000000)      /* 25*/
#define MCAN_RXF1S_F1F          ((uint32_t)0x01000000)      /* 24*/
#define MCAN_RXF1S_F1PI_Msk     ((uint32_t)0x003F0000)      /* 21:16*/
#define MCAN_RXF1S_F1GI_Msk     ((uint32_t)0x00003F00)      /* 13:8*/
#define MCAN_RXF1S_F1FL_Msk     ((uint32_t)0x0000007F)      /* 6:0*/

#define MCAN_RXF1S_F1PI_Pos     ((uint32_t)0x10)            /* 21:16*/
#define MCAN_RXF1S_F1GI_Pos     ((uint32_t)0x08)            /* 13:8*/
#define MCAN_RXF1S_F1FL_Pos     ((uint32_t)0x00)            /* 6:0*/

#define MCA_RXF1A_F1AI_Msk      ((uint32_t)0x0000003F)      /* 5:0*/
#define MCA_RXF1A_F1AI_Pos      ((uint32_t)0x00)            /* 5:0*/

#define MCAN_TXBC_TFQM          ((uint32_t)0x40000000)      /* 30 Tx FIFO/Queue Mode */
#define MCAN_TXBC_TFQS_Msk      ((uint32_t)0x3F000000)      /* 29:24 Transmit FIFO/Queue Size */
#define MCAN_TXBC_NDTB_Msk      ((uint32_t)0x003F0000)      /* 21:16 Number of Dedicated Transmit Buffers */
#define MCAN_TXBC_TBSA_Msk      ((uint32_t)0x0000FFFE)      /* 15:2 Tx Buffers Start Address */

#define MCAN_TXBC_TFQS_Pos      ((uint32_t)0x18)            /* 29:24 Transmit FIFO/Queue Size */
#define MCAN_TXBC_NDTB_Pos      ((uint32_t)0x10)            /* 21:16 Number of Dedicated Transmit Buffers */
#define MCAN_TXBC_TBSA_Pos      ((uint32_t)0x02)            /* 15:2 Tx Buffers Start Address */

#define MCAN_TXBC_NDTB_VALUE    (50U)                       /* TX buffer count (0x32) */
#define MCAN_TXBC_FQS_VALUE     (0U)                        /* TX FIFO/queue size */

#define MCAN_TXESC_TBDS_Msk     ((uint32_t)0x00000007)      /* 2:0 Tx Buffer Data Field Size*/
#define MCAN_TXESC_TBDS_Pos     ((uint32_t)0x00)            /* 2:0 Tx Buffer Data Field Size*/

#define MCAN_TXFQS_TFFL_Msk     ((uint32_t)0x0000003F)      /* 5:0 Tx FIFO Free Level */
#define MCAN_TXFQS_TFGI_Msk     ((uint32_t)0x00001F00)      /* 12:8  Tx FIFO Get Index */
#define MCAN_TXFQS_TFQP_Msk     ((uint32_t)0x001F0000)      /* 20:16 Tx FIFO/Queue Put Index */
#define MCAN_TXFQS_TFQF         ((uint32_t)0x00200000)      /* 21 Tx FIFO/Queue Full*/

#define MCAN_TXFQS_TFFL_Pos     ((uint32_t)0x00)            /* 5:0 Tx FIFO Free Level */
#define MCAN_TXFQS_TFGI_Pos     ((uint32_t)0x08)            /* 12:8  Tx FIFO Get Index */
#define MCAN_TXFQS_TFQP_Pos     ((uint32_t)0x10)            /* 20:16 Tx FIFO/Queue Put Index */

#define MCAN_GFC_RRFE           ((uint32_t)0x00000001)      /* 0 Reject Remote Frames Extended*/
#define MCAN_GFC_RRFS           ((uint32_t)0x00000002)      /* 1 Reject Remote Frames Standard*/
#define MCAN_GFC_ANFE_Msk       ((uint32_t)0x0000000C)      /* 3:2 Accept Non-matching Frames Extended*/
#define MCAN_GFC_ANFS_Msk       ((uint32_t)0x00000030)      /* 5:4 Accept Non-matching Frames Standard*/
#define MCAN_GFC_ANFE_Pos       ((uint32_t)0x02)            /* 3:2 Accept Non-matching Frames Extended*/
#define MCAN_GFC_ANFS_Pos       ((uint32_t)0x04)            /* 5:4 Accept Non-matching Frames Standard*/

#define MCAN_GFC_ANFE_VALUE     (1U)                        /* Store non-matching extended frames in FIFO0 */

#define MCAN_XIDFC_FLESA_Msk    ((uint32_t)0x0000FFFE)      /* 15:2 Filter List Extended Start Address*/
#define MCAN_XIDFC_LSE_Msk      ((uint32_t)0x007F0000)      /* 22:16 List Size Extended*/

#define MCAN_XIDFC_FLESA_Pos    ((uint32_t)0x02)            /* 15:2 Filter List Extended Start Address*/
#define MCAN_XIDFC_LSE_Pos      ((uint32_t)0x10)            /* 22:16 List Size Extended*/
#define MCAN_XIDAM_EIDM_Msk     ((uint32_t)0x1FFFFFFF)      /* 28:0 Extended ID Mask*/

#define MCAN_XIDFC_LSE_VALUE    (1U)                        /* Number of extended ID filters */

#define MCAN_STD_WORD_SIZE            (4U)                  /* Word size in bytes       */
#define MCAN_EXT_FILTER_WORD_COUNT    (2U)                  /* Words per extended filter */

#define BIT_MASK_32                   (1U)                  /* 32-bit bit mask base */
#define MCAN_WORD_SIZE_BYTES          (4U)                  /* Word size in bytes   */
#define MCAN_TX_ELEMENT_WORD_COUNT    (4U)                  /* Words per TX element */
#define MCAN_TX_BUFFER_BIT            (1U)                  /* TX buffer bit mask   */
#define MCAN_TX_BUFFER_COUNT          (32U)                 /* Number of TX buffers */
#define MCAN_RX_ELEMENT_WORD_COUNT    (4U)                  /* Words per RX element */


/* Base addresses of peripheral register structures */
#define MCANA_DRIVER_BASE         0x00058000U
#define MCANA_MSG_RAM_BASE        0x00058000U
#define MCANASS_BASE              0x0005C400U
#define MCANA_BASE                0x0005C600U
#define MCANA_ERROR_BASE          0x0005C800U

/* Pointer to base addresses of peripheral register structures */
#define MCANASS                     ((MCANSS_Typedef *)  MCANASS_BASE)
#define MCANA                       ((MCAN_Typedef *)  MCANA_BASE)
#define MCANA_ERROR                 ((MCAN_ERROR_Typedef *)  MCANA_ERROR_BASE)

#endif/*BSP_MCAN_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
