/***********************************************************************************************
* File: HAL_UART.c
* Project: 
* Module: Hardware Abstraction Layer (HAL) for UART peripherals
*
* Purpose :
* HAL-level interface for UART peripherals.
*
* Description:
* This file provides a standardized API for interacting with UART, abstracting the specific
* register-level operations of the underlying MCU. 
*
* 
* High-Level Requirements:  
* 
* Low-Level Requirements:  
* 
* Interfaces: 
* Public: 
* Hal_Uart_MessagePrepare()
* Hal_Uart_Init()
* Hal_Uart_Process()
* Hal_Uart_Initiate()
*
* Private:  
* 
* Assumptions:  
* 
* Dependencies: 
* - HAL_UART.h 
* - HAL_SPIB_ENCODER.h 
* - HAL_ADC.h 
* - HAL_FSI.h 
* - stdio.h 
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
#include "HAL_UART.h"
#include <HAL_SPIB_ENCODER.h>
#include <HAL_ADC.h>
#include <HAL_FSI.h>
#include <stdio.h>

/******************************************************************************
* Module Global Definitions
******************************************************************************/
/* UART configuration details */
Uart_Config_t uart_config = {
    .sciBase = SCI_A,
    .txPin = { .gpio_number = UART_TX_GPIO_PIN, .mux_position = UART_TX_GPIO_MUX },
    .rxPin = { .gpio_number = UART_RX_GPIO_PIN, .mux_position = UART_RX_GPIO_MUX },
    .baudRate = UART_BAUD_RATE,
};

uint16_t uartCommResetFlag = 0;

/* output message format*/
char uartTxMessages[UART_COMM_VAR_COUNT][UART_MESSAGE_LENGTH] = {
    {"Fr. count:      "},
    {"SW ver.  :      "},
    {"CPU temp :      "},
    {"motor t1 :      "},
    {"motor t2 :      "},
    {"HS temp1 :      "},
    {"HS temp2 :      "},
    {"DIE temp :      "},
    {"L vol A  :      "},
    {"L cur A  :      "},
    {"L vol B  :      "},
    {"L cur B  :      "},
    {"L vol C  :      "},
    {"L cur C  :      "},
    {"DC vol   :      "},
    {"DC cur   :      "},
    {"VCC 3.3  :      "},
    {"DigitalOU:      "},
    {"NetR33A_1:      "},
    {"NetR41A_1:      "},
    {"CN_ID_O_P:      "},
    {"CN_ID_1_P:      "},
    {"CN_ID_2_P:      "},
    {"CN_ID_3_P:      "},
    {"BOOT_SL_0:      "},
    {"DG_IN_1_P:      "},
    {"DG_IN_2_P:      "},
    {"BOOT_SL_1:      "},
    {"INVERT_EN:      "},
    {"FLT_IN_A :      "},
    {"STAT_LEDA:      "},
    {"NetR18A_1:      "},
    {"SPIA_RX  :      "},
    {"SPIB_RX  :      "},
    {"FSI_RX_B1:      "},
    {"FSI_RX_B2:      "},
};

/******************************************************************************
* Function Definitions
******************************************************************************/

/******************************************************************************
* Function     : Hal_Uart_MessagePrepare 
*
* Purpose      : 
* Prepares UART message data for the specified index.
*
* Inputs       :
*  index   -    Identifier used to select the telemetry message to prepare.
*
* Outputs      :
*  None.
*
* Returns      :
*  None.
*
* Returns      :
*  None.
*
* Requirements : 
*
* Note         :
*
******************************************************************************/
void Hal_Uart_MessagePrepare(uint16_t index)
{
    static uint16_t count = 0;
    int16_t value;
    /* Pointer to GPIO output channel configuration */
    gpio_out_channels_t *gpio_out_channel = gpio_out_channel_get();
    /* Pointer to GPIO input channel configuration */
    const gpio_in_channels_t *gpio_in_channel = gpio_in_channel_get();
    /* Pointer to ADC channel configuration */
    adc_channels_t *adc_channel = adc_channel_get();
    /* Pointer to SPIB channel configuration */
    spi_channel_t *spib_channel = spib_channel_get();
    /* Pointer to FSI DMA received data structure */
    fsi_data_dma_str_t *fsi_dma_rx_data = fsi_dma_rx_data_get();

    switch (index)
    {
        case UART_MSG_FRESH_COUNT:
        {
            value = count;
            count++;
            if (count >= UART_FRESH_COUNT_MAX)
            {
                count = UART_FRESH_COUNT_MIN;
            }
            break;
        }
        case UART_MSG_SW_VERSION:
        {
            value = SW_VERSION;
            break;
        }
        case UART_MSG_INTERNAL_TEMP:
        {
            value = Hal_GetInternalTemperature();
            break;
        }
        case UART_MSG_MOTOR_TEMP_1:
        {
            value = adc_channel->MOTOR_TEMP_1_A6.result;
            break;
        }
        case UART_MSG_MOTOR_TEMP_2:
        {
            value = adc_channel->MOTOR_TEMP_2_B5.result;
            break;
        }
        case UART_MSG_HS_TEMP_1:
        {
            value = adc_channel->HS_TEMP_1_B1.result;
            break;
        }
        case UART_MSG_HS_TEMP_2:
        {
            value = adc_channel->HS_TEMP_2_B11.result;
            break;
        }
        case UART_MSG_DIE_TEMP:
        {
            value = adc_channel->DIE_TEMP_C1.result;
            break;
        }
        case UART_MSG_LINE_A_VOLT:
        {
            value = adc_channel->Line_A_Vol_A2.result;
            break;
        }
        case UART_MSG_LINE_A_CURR:
        {
            value = adc_channel->Line_A_Curr_A0.result;
            break;
        }
        case UART_MSG_LINE_B_VOLT:
        {
            value = adc_channel->Line_B_Vol_B2.result;
            break;
        }
        case UART_MSG_LINE_B_CURR:
        {
            value = adc_channel->Line_B_Curr_B0.result;
            break;
        }
        case UART_MSG_LINE_C_VOLT:
        {
            value = adc_channel->Line_C_Vol_C2.result;
            break;
        }
        case UART_MSG_LINE_C_CURR:
        {
            value = adc_channel->Line_C_Curr_C0.result;
            break;
        }
        case UART_MSG_DC_BUS_VOLT:
        {
            value = adc_channel->DC_Bus_V_B3.result;
            break;
        }
        case UART_MSG_DC_BUS_CURR:
        {
            value = adc_channel->DC_Bus_Current_C3.result;
            break;
        }
        case UART_MSG_VCC_33:
        {
            value = adc_channel->VCC_33_A1.result;
            break;
        }
        case UART_MSG_DIGITAL_OUT:
        {
            value = gpio_out_channel->DigitalOUT.out_level;
            break;
        }
        case UART_MSG_NETR33A:
        {
            value = gpio_out_channel->NetR33A_1.out_level;
            break;
        }
        case UART_MSG_NETR41A:
        {
            value = gpio_in_channel->NetR41A_1.in_level;
            break;
        }
        case UART_MSG_CAN_ID_0:
        {
            value = gpio_in_channel->CAN_ID_0_PIN.in_level; 
            break;
        }
        case UART_MSG_CAN_ID_1:
        {
            value = gpio_in_channel->CAN_ID_1_PIN.in_level; 
            break;
        }
        case UART_MSG_CAN_ID_2:
        {
            value = gpio_in_channel->CAN_ID_2_PIN.in_level; 
            break;
        }
        case UART_MSG_CAN_ID_3:
        {
            value = gpio_in_channel->CAN_ID_3_PIN.in_level; 
            break;
        }
        case UART_MSG_BOOT_SEL_0:
        {
            value = gpio_in_channel->BOOT_SEL_0.in_level; 
            break;
        }
        case UART_MSG_DIGITAL_IN_1:
        {
            value = gpio_in_channel->DIGITAL_IN_1_PIN.in_level; 
            break;
        }
        case UART_MSG_DIGITAL_IN_2:
        {
            value = gpio_in_channel->DIGITAL_IN_2_PIN.in_level; 
            break;
        }
        case UART_MSG_BOOT_SEL_1:
        {
            value = gpio_in_channel->BOOT_SEL_1.in_level; 
            break;
        }
        case UART_MSG_INVERTER_EN:
        {
            value = gpio_out_channel->INVERTER_EN.out_level; 
            break;
        }
        case UART_MSG_FAULT_IN:
        {
            value = gpio_in_channel->FAULT_IN_PINA.in_level; 
            break;
        }
        case UART_MSG_STATUS_LED:
        {
            value = gpio_out_channel->STATUS_LEDA.out_level; 
            break;
        }
        case UART_MSG_NETR18A:
        {
            value = gpio_out_channel->NetR18A_1.out_level; 
            break;
        }
        case UART_MSG_SPIB_DATA_0:
        {
            value = spib_channel->rx_data; 
            break;
        }
        case UART_MSG_SPIB_DATA_1:
        {
            value = spib_channel->rx_data; 
            break;
        }
        case UART_MSG_FSI_RX_BYTE0:
        {
            value = fsi_dma_rx_data->byte_0; 
            break;
        }
        case UART_MSG_FSI_RX_BYTE1:
        {
            value = fsi_dma_rx_data->byte_1; 
            break;
        }
        default:
        {
            break;
        }
    }

    if (index < UART_COMM_VAR_COUNT)
    {
        sprintf(&uartTxMessages[index][UART_VALUE_OFFSET_INDEX], "%5d", value);
        uartTxMessages[index][UART_DELIMITER_INDEX] = UART_DELIMITER_TAB;
        if (index == (UART_COMM_VAR_COUNT-UART_LAST_ELEMENT_OFFSET))
        {
            uartTxMessages[index][UART_DELIMITER_INDEX] = UART_DELIMITER_NEWLINE;
        }
    }
}

/******************************************************************************
* Function     : Hal_Uart_Process
*
* Purpose      :
* Processes data transmission over the UART interface.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  None.
*
* Returns      :
*  None.
*
* Requirements : 
* 
* Note         :
*
******************************************************************************/
void Hal_Uart_Process(void)
{
    static uint16_t i = 0, j;
    
    /* Reset communication sequence if reset flag is set */
    if (uartCommResetFlag)
    {
        uartCommResetFlag = UART_RESET_DISABLE;
        i = 0;
    }
    /* Process only within valid number of variables */
    if (i < UART_COMM_VAR_COUNT)
    {
        /* Prepare message content for current index */
        Hal_Uart_MessagePrepare(i);

        /* Transmit 16 bytes of prepared message */
        for (j = 0; j < UART_TX_FRAME_LENGTH; j++)
        {
            Bsp_Uart_TransmitByte(uart_config.sciBase, uartTxMessages[i][j]);
        }
        /* Move to next variable */
        i++;
    }
}

/******************************************************************************
* Function     : Hal_Uart_Init 
*
* Purpose      : 
* Initializes the UART interface required for communication.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  None.
*
* Returns      :
*  None.
*
* Requirements : 
*
* Note         :
*
******************************************************************************/
void Hal_Uart_Init(void)
{
    Bsp_Uart_Configure(uart_config.sciBase, uart_config.baudRate);
    gpio_peripheral_config(&uart_config.txPin);
    gpio_peripheral_config(&uart_config.rxPin);
}

/******************************************************************************
* Function     : Hal_Uart_Initiate 
*
* Purpose      : 
* Initiates communication over the UART interface.
*
* Inputs       :
*  None.
*
* Outputs      :
*  None.
*
* Returns      :
*  None.
*
* Returns      :
*  None.
*
* Requirements : 
*
* Note         :
*
******************************************************************************/
void Hal_Uart_Initiate(void)
{
    uartCommResetFlag = UART_RESET_ENABLE;
}
/*************** End of C File ************************************************/

