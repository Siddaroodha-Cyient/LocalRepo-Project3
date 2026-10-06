/***********************************************************************************************
* File    : BSP_UART.h
*
* Module  : Board Support Package (BSP) for UART peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for UART peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for UART peripherals.
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
#ifndef BSP_UART_H
#define BSP_UART_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/

/* Structure used to access SCI peripheral registers */ 
typedef struct{
    volatile uint16_t SCICCR;       /* Communications control register   */
    volatile uint16_t SCICTL1;      /* Control register 1                */
    volatile uint16_t SCIHBAUD;     /* Baud rate (high) register         */
    volatile uint16_t SCILBAUD;     /* Baud rate (low) register          */
    volatile uint16_t SCICTL2;      /* Control register 2                */
    volatile uint16_t SCIRXST;      /* Receive status register           */
    volatile uint16_t SCIRXEMU;     /* Receive emulation buffer register */
    volatile uint16_t SCIRXBUF;     /* Receive data buffer               */
    uint16_t resv1;
    volatile uint16_t SCITXBUF;     /* Transmit data buffer               */
    volatile uint16_t SCIFFTX;      /* FIFO transmit register             */
    volatile uint16_t SCIFFRX;      /* FIFO receive register              */
    volatile uint16_t SCIFFCT;      /* FIFO control register              */
    uint16_t resv2[2];
    volatile uint16_t SCIPRI;       /* SCI priority control               */
} Uart_Regs_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void Bsp_Uart_Configure(Uart_Regs_t * sciBase, uint32_t baud);
void Bsp_Uart_TransmitByte(Uart_Regs_t * sciBase, char byte);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define SCI_BRR_DIVIDER_SHIFT     (3U)       /* Divide clock by 8 */

#define SCI_SCICCR_DEFAULT        (0x0007U)  /* 1 stop, no parity, 8-bit, async */
#define SCI_SCICTL1_ENABLE        (0x0003U)  /* Enable TX, RX */
#define SCI_SCICTL1_RELEASE       (0x0023U)  /* Release from reset */

#define SCI_SCIFFTX_EN_Pos        (14U)      /* FIFO enable bit */
#define SCI_SCIFFTX_RST_Pos       (13U)      /* FIFO reset bit */
#define SCI_SCIFFTX_EN_VALUE      (1U)       /* FIFO enable */
#define SCI_SCIFFTX_RST_VALUE     (1U)       /* FIFO reset */

#define SCI_BAUD_Msk              (0xFFU)    /* 8-bit mask */
#define SCI_BAUD_Pos              (8U) 

#define SCI_TX_FIFO_LEVEL_Msk     (0x1F00U)  /* TX FIFO level bits */
#define SCI_TX_FIFO_LEVEL_Pos     (8U)  
#define SCI_TX_FIFO_MAX_LEVEL     (16U)      /* FIFO size (16 words) */


/* Base addresses of peripheral register structures */
#define SCIA_BASE                 0x00007200U
#define SCIB_BASE                 0x00007210U

/* Pointer to base addresses of peripheral register structures */
#define SCI_A            ((Uart_Regs_t *) SCIA_BASE)
#define SCI_B            ((Uart_Regs_t *) SCIB_BASE)

#endif/*BSP_UART_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
