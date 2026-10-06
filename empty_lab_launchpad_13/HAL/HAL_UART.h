/***********************************************************************************************
* File: HAL_UART.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for UART peripherals
*
* Purpose :
* HAL-level interface for UART peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for UART peripherals.
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
#ifndef HAL_UART_H
#define HAL_UART_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "BSP_UART.h"
#include <HAL_GPIO.h>


/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef enum
{
    UART_MSG_FRESH_COUNT = 0,
    UART_MSG_SW_VERSION,
    UART_MSG_INTERNAL_TEMP,
    UART_MSG_MOTOR_TEMP_1,
    UART_MSG_MOTOR_TEMP_2,
    UART_MSG_HS_TEMP_1,
    UART_MSG_HS_TEMP_2,
    UART_MSG_DIE_TEMP,
    UART_MSG_LINE_A_VOLT,
    UART_MSG_LINE_A_CURR,
    UART_MSG_LINE_B_VOLT,
    UART_MSG_LINE_B_CURR,
    UART_MSG_LINE_C_VOLT,
    UART_MSG_LINE_C_CURR,
    UART_MSG_DC_BUS_VOLT,
    UART_MSG_DC_BUS_CURR,
    UART_MSG_VCC_33,
    UART_MSG_DIGITAL_OUT,
    UART_MSG_NETR33A,
    UART_MSG_NETR41A,
    UART_MSG_CAN_ID_0,
    UART_MSG_CAN_ID_1,
    UART_MSG_CAN_ID_2,
    UART_MSG_CAN_ID_3,
    UART_MSG_BOOT_SEL_0,
    UART_MSG_DIGITAL_IN_1,
    UART_MSG_DIGITAL_IN_2,
    UART_MSG_BOOT_SEL_1,
    UART_MSG_INVERTER_EN,
    UART_MSG_FAULT_IN,
    UART_MSG_STATUS_LED,
    UART_MSG_NETR18A,
    UART_MSG_SPIB_DATA_0,
    UART_MSG_SPIB_DATA_1,
    UART_MSG_FSI_RX_BYTE0,
    UART_MSG_FSI_RX_BYTE1,
} Uart_MsgId_t;

typedef struct{
    gpio_peripheral_t txPin;
    gpio_peripheral_t rxPin;
    Uart_Regs_t * sciBase;
    uint32_t baudRate;
} Uart_Config_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void Hal_Uart_MessagePrepare(uint16_t index);
void Hal_Uart_Init(void);
void Hal_Uart_Process(void);
void Hal_Uart_Initiate(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define UART_TX_GPIO_PIN           (29U)
#define UART_TX_GPIO_MUX           (1U)
#define UART_RX_GPIO_PIN           (28U)
#define UART_RX_GPIO_MUX           (1U)
#define UART_BAUD_RATE             (115200U)

#define UART_COMM_VAR_COUNT        (36U)
#define UART_MESSAGE_LENGTH        (16U)

#define SW_VERSION                 (13U)
#define UART_FRESH_COUNT_MAX       (256U)
#define UART_FRESH_COUNT_MIN       (0U)

#define UART_VALUE_OFFSET_INDEX    (10U)
#define UART_DELIMITER_INDEX       (15U)
#define UART_LAST_ELEMENT_OFFSET   (1U)

#define UART_DELIMITER_TAB         '\t'
#define UART_DELIMITER_NEWLINE     '\n'

#define UART_TX_FRAME_LENGTH       (16U)

#define UART_RESET_ENABLE          (1U)
#define UART_RESET_DISABLE         (0U)

#endif /* HAL_UART_H */
/****************************************************************************** 
* End of File 
******************************************************************************/
