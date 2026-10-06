/***********************************************************************************************
* File: BSP_SPI.c
* Project: 
* Module: Board Support Package (BSP) for SPI peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for SPI peripherals
*
* Description:
* This file contains board-specific driver functions for Serial Peripheral Interface (SPI)
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
* - BSP_SPI.h 
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
#include "BSP_SPI.h"
#include "HAL_CLOCK.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

/******************************************************************************
* Function     : spi_config 
*
* Purpose      : 
* Configures the SPI peripheral registers based on the specified SPI
* configuration parameters.
*
* Inputs       :
*    str   -   Pointer to an spi_struct_t structure that contains the SPI
*              peripheral base address and required configuration
*              parameters such as frequency, clock polarity, and phase.
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
void spi_config(spi_struct_t * str)
{
    SPI_typedef * SPI = str->SPI;

    const clock_struct_t *clk = clock_config_get();
    uint32_t brr = (clk->lspclk_frequency/str->frequency) - 1;
    
    /* Limit BRR to hardware max value*/
    if (brr > SPI_BAUD_MAX_VALUE)
    {
        brr = SPI_BAUD_MAX_VALUE;
    }
    
    EALLOW;
    SPI->SPICCR &= ~SPICCR_BITS_SPISWRESET;

    /* Master mode selected */
    SPI->SPICTL |= SPICTL_BITS_MASTER_SLAVE;       
    /* Transmit enable */
    SPI->SPICTL |= SPICTL_BITS_TALK;               
    SPI->SPICCR &= ~SPICCR_BITS_CLKPOLARITY;        
    SPI->SPICTL &= ~SPICTL_BITS_CLK_PHASE;

    switch (str->clk_scheme)
    {
        default:
        case rising_edge_without_delay:
        {
            SPI->SPICCR &= ~SPICCR_BITS_CLKPOLARITY;        
            SPI->SPICTL &= ~SPICTL_BITS_CLK_PHASE;
        }
        break;
    
        case rising_edge_with_delay:
        {
            SPI->SPICCR &= ~SPICCR_BITS_CLKPOLARITY;        
            SPI->SPICTL |= SPICTL_BITS_CLK_PHASE;
        }
        break;
    
        case falling_edge_without_delay:
        {
            SPI->SPICCR |= SPICCR_BITS_CLKPOLARITY;        
            SPI->SPICTL &= ~SPICTL_BITS_CLK_PHASE;
        }
        break;
    
        case falling_edge_with_delay:
        {
            SPI->SPICCR |= SPICCR_BITS_CLKPOLARITY;        
            SPI->SPICTL |= SPICTL_BITS_CLK_PHASE;
        }
        break;
    }

    SPI->SPICCR &= ~SPICCR_BITS_SPICHAR_Msk;
     /* 8 bit data transfer */
    SPI->SPICCR |= ((((uint32_t)SPICCR_BITS_SPICHAR_VALUE)<<SPICCR_BITS_SPICHAR_Pos) & SPICCR_BITS_SPICHAR_Msk);           

    /* FIFO enhancement enable */
    SPI->SPIFFTX |= SPIFFTX_BITS_SPIFFENA;    
    /* clear flag */      
    SPI->SPIFFTX |= SPIFFTX_BITS_TXFFINTCLR;        
    SPI->SPIFFRX |= SPIFFRX_BITS_RXFFOVFCLR;        
    SPI->SPIFFRX |= SPIFFRX_BITS_RXFFINTCLR;     
    /* Release transmit FIFO from reset */   
    SPI->SPIFFTX |= SPIFFTX_BITS_TXFIFO;            

    SPI->SPIBRR &= ~SPIBRR_BITS_SPI_BIT_RATE_Msk;
    SPI->SPIBRR |= ((brr<<SPIBRR_BITS_SPI_BIT_RATE_Pos) & SPIBRR_BITS_SPI_BIT_RATE_Msk);

    SPI->SPICCR |= SPICCR_BITS_SPISWRESET;

    EDIS;
}

/******************************************************************************
* Function     : spi_send_byte 
*
* Purpose      : 
* Transmits data through the specified SPI peripheral.
*
* Inputs       :
*   SPI    -   Pointer to an SPI_typedef structure that contains the
*              register base address of the SPI peripheral
*   byte   -   Data to be transmitted over the SPI interface
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
void spi_send_byte(SPI_typedef * SPI, uint16_t byte)
{
    if (((SPI->SPIFFTX  & SPIFFTX_BITS_TXFFST_Msk) >> SPIFFTX_BITS_TXFFST_Pos ) < SPI_TX_FIFO_DEPTH)
    {
        /* Write data to transmit buffer */
        SPI->SPITXBUF = byte << SPI_DATA_SHIFT;
    }
}

/******************************************************************************
* Function     : spi_check_new_data 
*
* Purpose      : 
* Checks the SPI peripheral status to determine whether new data is available
* for processing.
*
* Inputs       :
*   SPI    -   Pointer to an SPI_typedef structure that contains the
*              register base address of the SPI peripheral.
*
* Outputs      :
*  None.
*
* Returns      :
*  uint16_t  - Non-zero value if new data is available
*            - Zero if no new data is available
*
* Requirements :
*
* Notes        :
*
******************************************************************************/
uint16_t spi_check_new_data(SPI_typedef * SPI)
{
    return ((SPI->SPIFFRX & SPIFFRX_BITS_RXFFST_Msk) >> SPIFFRX_BITS_RXFFST_Pos);
}

/******************************************************************************
* Function     : spi_receive_byte 
*
* Purpose      : 
* Receives data from the specified SPI peripheral.
*
* Inputs       :
*   SPI    -   Pointer to an SPI_typedef structure that contains the
*              register base address of the SPI peripheral.
*
* Outputs      :
*  None.
*
* Returns      :
*  uint16_t  - Data received from the SPI peripheral.
*
* Requirements :
*
* Notes        :
*
******************************************************************************/
uint16_t spi_receive_byte(SPI_typedef * SPI)
{
    return SPI->SPIRXBUF;
}

/*************** End of C File ************************************************/

