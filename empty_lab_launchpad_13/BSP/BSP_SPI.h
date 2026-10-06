/***********************************************************************************************
* File    : BSP_SPI.h
*
* Module  : Board Support Package (BSP) for SPI peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for SPI peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for SPI peripherals.
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
#ifndef BSP_SPI_H
#define BSP_SPI_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/

/* Structure used to access SPI peripheral registers */ 
typedef struct{
    uint16_t SPICCR;                /* SPI Configuration Control Register,  Address offset: 0x00        */
    uint16_t SPICTL;                /* SPI Operation Control Register,      Address offset: 0x01        */
    uint16_t SPISTS;                /* SPI Status Register,                 Address offset: 0x02        */
    uint16_t rsvd1;                 /* Reserved,                            Address offset: 0x03        */
    uint16_t SPIBRR;                /* SPI Baud Rate Register,              Address offset: 0x04        */
    uint16_t rsvd2;                 /* Reserved,                            Address offset: 0x05        */
    uint16_t SPIRXEMU;              /* SPI Emulation Buffer Register,       Address offset: 0x06        */
    uint16_t SPIRXBUF;              /* SPI Serial Input Buffer Register,    Address offset: 0x07        */
    uint16_t SPITXBUF;              /* SPI Serial Output Buffer Register,   Address offset: 0x08        */
    uint16_t SPIDAT;                /* SPI Serial Data Register,            Address offset: 0x09        */
    uint16_t SPIFFTX;               /* SPI FIFO Transmit Register,          Address offset: 0x0A        */
    uint16_t SPIFFRX;               /* SPI FIFO Receive Register,           Address offset: 0x0B        */
    uint16_t SPIFFCT;               /* SPI FIFO Control Register,           Address offset: 0x0C        */
    uint16_t rsvd3[2];              /* Reserved,                            Address offset: 0x0D - 0x0E */
    uint16_t SPIPRI;                /* SPI Priority Control Register,       Address offset: 0x0F        */
} SPI_typedef;

typedef enum{
    rising_edge_without_delay   = 0,
    rising_edge_with_delay      = 1,
    falling_edge_without_delay  = 2,
    falling_edge_with_delay     = 3,
} spiclk_scheme_t;

typedef struct{
    SPI_typedef * SPI;
    uint32_t frequency;
    spiclk_scheme_t clk_scheme;
} spi_struct_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void spi_config(spi_struct_t * str);
void spi_send_byte(SPI_typedef * SPI, uint16_t byte);
uint16_t spi_check_new_data(SPI_typedef * SPI);
uint16_t spi_receive_byte(SPI_typedef * SPI);


/****************************************************************************** 
* Macro Definitions 
******************************************************************************/

#define SPICCR_BITS_SPICHAR_Msk         ((uint16_t)0b0000000000001111)    /* 3:0 Character Length Control */
#define SPICCR_BITS_SPILBK              ((uint16_t)0b0000000000010000)    /* 4 SPI Loopback               */
#define SPICCR_BITS_HS_MODE             ((uint16_t)0b0000000000100000)    /* 5 High Speed mode control    */
#define SPICCR_BITS_CLKPOLARITY         ((uint16_t)0b0000000001000000)    /* 6 Shift Clock Polarity       */
#define SPICCR_BITS_SPISWRESET          ((uint16_t)0b0000000010000000)    /* 7 SPI Software Reset         */
#define SPICCR_BITS_rsvd1_Msk           ((uint16_t)0b1111111100000000)    /* 15:8 Reserved                */

#define SPICCR_BITS_SPICHAR_Pos         ((uint16_t)0)                     /* 3:0 Character Length Control */

#define SPICTL_BITS_SPIINTENA           ((uint16_t)0b0000000000000001)    /* 0 SPI Interupt Enable            */
#define SPICTL_BITS_TALK                ((uint16_t)0b0000000000000010)    /* 1 Master/Slave Transmit Enable   */
#define SPICTL_BITS_MASTER_SLAVE        ((uint16_t)0b0000000000000100)    /* 2 SPI Network Mode Control       */
#define SPICTL_BITS_CLK_PHASE           ((uint16_t)0b0000000000001000)    /* 3 SPI Clock Phase                */
#define SPICTL_BITS_OVERRUNINTENA       ((uint16_t)0b0000000000010000)    /* 4 Overrun Interrupt Enable       */
#define SPICTL_BITS_rsvd1_Msk           ((uint16_t)0b1111111111100000)    /* 15:5 Reserved                    */


#define SPISTS_BITS_rsvd1_Msk           ((uint16_t)0b0000000000011111)    /* 4:0 Reserved                     */
#define SPISTS_BITS_BUFFULL_FLAG        ((uint16_t)0b0000000000100000)    /* 5 SPI Transmit Buffer Full Flag  */
#define SPISTS_BITS_INT_FLAG            ((uint16_t)0b0000000001000000)    /* 6 SPI Interrupt Flag             */
#define SPISTS_BITS_OVERRUN_FLAG        ((uint16_t)0b0000000010000000)    /* 7 SPI Receiver Overrun Flag      */
#define SPISTS_BITS_rsvd2_Msk           ((uint16_t)0b1111111100000000)    /* 15:8 Reserved                    */


#define SPIBRR_BITS_SPI_BIT_RATE_Msk    ((uint16_t)0b0000000001111111)    /* 6:0 SPI Bit Rate Control     */
#define SPIBRR_BITS_rsvd1_Msk           ((uint16_t)0b1111111110000000)    /* 15:7 Reserved                */

#define SPIBRR_BITS_SPI_BIT_RATE_Pos    ((uint16_t)0)    /* 6:0 SPI Bit Rate Control     */

#define SPIFFTX_BITS_TXFFIL_Msk          ((uint16_t)0b0000000000011111)    /* 4:0 TXFIFO Interrupt Level  */
#define SPIFFTX_BITS_TXFFIENA            ((uint16_t)0b0000000000100000)    /* 5 TXFIFO Interrupt Enable   */
#define SPIFFTX_BITS_TXFFINTCLR          ((uint16_t)0b0000000001000000)    /* 6 TXFIFO Interrupt Clear    */
#define SPIFFTX_BITS_TXFFINT             ((uint16_t)0b0000000010000000)    /* 7 TXFIFO Interrupt Flag     */
#define SPIFFTX_BITS_TXFFST_Msk          ((uint16_t)0b0001111100000000)    /* 12:8 Transmit FIFO Status   */
#define SPIFFTX_BITS_TXFIFO              ((uint16_t)0b0010000000000000)    /* 13 TXFIFO Reset             */
#define SPIFFTX_BITS_SPIFFENA            ((uint16_t)0b0100000000000000)    /* 14 FIFO Enhancements Enable */
#define SPIFFTX_BITS_SPIRST              ((uint16_t)0b1000000000000000)    /* 15 SPI Reset                */

#define SPIFFTX_BITS_TXFFST_Pos          ((uint16_t)8)    /* 12:8 Transmit FIFO Status   */

#define SPIFFRX_BITS_RXFFIL_Msk          ((uint16_t)0b0000000000011111)    /* 4:0 RXFIFO Interrupt Level      */
#define SPIFFRX_BITS_RXFFIENA            ((uint16_t)0b0000000000100000)    /* 5 RXFIFO Interrupt Enable       */
#define SPIFFRX_BITS_RXFFINTCLR          ((uint16_t)0b0000000001000000)    /* 6 RXFIFO Interupt Clear         */
#define SPIFFRX_BITS_RXFFINT             ((uint16_t)0b0000000010000000)    /* 7 RXFIFO Interrupt Flag         */
#define SPIFFRX_BITS_RXFFST_Msk          ((uint16_t)0b0001111100000000)    /* 12:8 Receive FIFO Status        */
#define SPIFFRX_BITS_RXFIFORESET         ((uint16_t)0b0010000000000000)    /* 13 RXFIFO Reset                 */
#define SPIFFRX_BITS_RXFFOVFCLR          ((uint16_t)0b0100000000000000)    /* 14 Receive FIFO Overflow Clear  */
#define SPIFFRX_BITS_RXFFOVF             ((uint16_t)0b1000000000000000)    /* 15 Receive FIFO Overflow Flag   */

#define SPIFFRX_BITS_RXFFST_Pos          ((uint16_t)8)    /* 12:8 Receive FIFO Status        */

#define SPIPRI_BITS_TRIWIRE             ((uint16_t)0b0000000000000001)    /* 0 3-wire mode select bit     */
#define SPIPRI_BITS_STEINV              ((uint16_t)0b0000000000000010)    /* 1 SPISTE inversion bit       */
#define SPIPRI_BITS_rsvd1_Msk           ((uint16_t)0b0000000000001100)    /* 3:2 Reserved                 */
#define SPIPRI_BITS_FREE                ((uint16_t)0b0000000000010000)    /* 4 Free emulation mode        */
#define SPIPRI_BITS_SOFT                ((uint16_t)0b0000000000100000)    /* 5 Soft emulation mode        */
#define SPIPRI_BITS_rsvd2               ((uint16_t)0b0000000001000000)    /* 6 Reserved                   */
#define SPIPRI_BITS_rsvd3_Msk           ((uint16_t)0b1111111110000000)    /* 15:7 Reserved                */


#define SPI_BAUD_MAX_VALUE              (127U)                            /* Max BRR value                */
#define SPICCR_BITS_SPICHAR_VALUE       (7U)
#define SPI_TX_FIFO_DEPTH               (16U)
#define SPI_DATA_SHIFT                  (8U)
/* Base addresses of peripheral register structures */
#define SPIA_BASE                 0x00006100U
#define SPIB_BASE                 0x00006110U

/* Pointer to base addresses of peripheral register structures */
#define SPIA            ((SPI_typedef *) SPIA_BASE)
#define SPIB            ((SPI_typedef *) SPIB_BASE)

#endif/*BSP_SPI_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
