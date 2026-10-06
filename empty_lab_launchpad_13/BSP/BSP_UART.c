/***********************************************************************************************
* File: BSP_UART.c
* Project: 
* Module: Board Support Package (BSP) for UART peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for UART peripherals
*
* Description:
* This file contains board-specific driver functions for Universal Asynchronous
* Receiver/Transmitter (UART) with direct interaction to the underlying hardware.
*
* High-Level Requirements:  
* 
* Low-Level Requirements:  
* 
* Interfaces: 
* Public: 
* Bsp_Uart_Configure()
* Bsp_Uart_TransmitByte()
*
* Private:  
* 
* Assumptions:  
* 
* Dependencies: 
* - BSP_UART.h 
* - HAL_CLOCK.h
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
#include "BSP_UART.h"
#include "HAL_CLOCK.h"

/******************************************************************************
* Function Definitions
******************************************************************************/
/******************************************************************************
* Function     : Bsp_Uart_Configure 
*
* Purpose      : 
* Configures the peripheral registers for the required UART baud rate and 
* communication parameters.
*
* Inputs       :
* sciBase  –   Pointer to an Uart_Regs_t structure that contains the 
*               register base address of the UART peripheral
* baudRate –   Required UART baud rate
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
void Bsp_Uart_Configure(Uart_Regs_t * sciBase, uint32_t baudRate)
{
    const clock_struct_t *clk = clock_config_get();
    uint32_t brr = clk->lspclk_frequency>>SCI_BRR_DIVIDER_SHIFT;
    brr /= baudRate;
    brr -= 1;

    /* 1 stop bit,  No loopback, No parity,8 char bits, async mode, idle-line protocol*/
    sciBase->SCICCR = SCI_SCICCR_DEFAULT;   

    /* enable TX, RX, internal SCICLK, Disable RX ERR, SLEEP, TXWAKE */
    sciBase->SCICTL1 = SCI_SCICTL1_ENABLE;  

    sciBase->SCIHBAUD  = (uint16_t)((brr>>SCI_BAUD_Pos) & SCI_BAUD_Msk);      
    sciBase->SCILBAUD  = (uint16_t)(brr & SCI_BAUD_Msk);      

    sciBase->SCIFFTX |= SCI_SCIFFTX_EN_VALUE << SCI_SCIFFTX_EN_Pos;
    sciBase->SCIFFTX &= ~(SCI_SCIFFTX_RST_VALUE << SCI_SCIFFTX_RST_Pos);
    sciBase->SCIFFTX |= SCI_SCIFFTX_RST_VALUE << SCI_SCIFFTX_RST_Pos;

    /* Relinquish SCI from Reset*/
    sciBase->SCICTL1 = SCI_SCICTL1_RELEASE;  

}

/******************************************************************************
* Function     : Bsp_Uart_TransmitByte 
*
* Purpose      : 
* Sends a single data byte through the UART peripheral using the configured 
* communication channel.
*
* Inputs       :
* sciBase  –   Pointer to an Uart_Regs_t structure that contains the 
*              register base address of the UART peripheral
* byte     –   Data byte to be transmitted over the UART interface
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
void Bsp_Uart_TransmitByte(Uart_Regs_t * sciBase, char byte)
{
    if (((sciBase->SCIFFTX & SCI_TX_FIFO_LEVEL_Msk) >> SCI_TX_FIFO_LEVEL_Pos) < SCI_TX_FIFO_MAX_LEVEL)
    {
        sciBase->SCITXBUF = byte;
    }
}

/*************** End of C File ************************************************/ 
