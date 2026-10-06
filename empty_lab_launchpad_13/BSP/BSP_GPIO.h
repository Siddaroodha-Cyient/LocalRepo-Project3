/***********************************************************************************************
* File    : BSP_GPIO.h
*
* Module  : Board Support Package (BSP) for GPIO peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for GPIO peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for GPIO peripherals.
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
#ifndef BSP_GPIO_H
#define BSP_GPIO_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/

/* Structure used to access GPIO peripheral data registers */ 
typedef struct{
    uint32_t   GPADAT;         /* GPIO A Data Register (GPIO0 to 31),              Address offset: 0x00 - 0x01 */
    uint32_t   GPASET;         /* GPIO A Data Set Register (GPIO0 to 31),          Address offset: 0x02 - 0x03 */
    uint32_t   GPACLEAR;       /* GPIO A Data Clear Register (GPIO0 to 31),        Address offset: 0x04 - 0x05 */
    uint32_t   GPATOGGLE;      /* GPIO A Data Toggle Register (GPIO0 to 31),       Address offset: 0x06 - 0x07 */
    uint32_t   GPBDAT;         /* GPIO B Data Register (GPIO32 to 63),             Address offset: 0x08 - 0x09 */
    uint32_t   GPBSET;         /* GPIO B Data Set Register (GPIO32 to 63),         Address offset: 0x0A - 0x0B */
    uint32_t   GPBCLEAR;       /* GPIO B Data Clear Register (GPIO32 to 63),       Address offset: 0x0C - 0x0D */
    uint32_t   GPBTOGGLE;      /* GPIO B Data Toggle Register (GPIO32 to 63),      Address offset: 0x0E - 0x0F */
    uint16_t   GPIO_DATA_rsvd[40]; /* reserved                                    Address offset: 0x10 - 0x37  */
    uint32_t   GPHDAT;         /* GPIO B Data Register (GPIO32 to 63),             Address offset: 0x38 - 0x39 */
} GPIO_DATA_Typedef;

/* Structure used to access GPIO peripheral control registers */ 
typedef struct{
    uint32_t    GPACTRL;                /* GPIO A Qualification Sampling Period Control (GPIO0 to 31),      Address offset: 0x00 - 0x01 */
    uint32_t    GPAQSEL1;               /* GPIO A Qualifier Select 1 Register (GPIO0 to 15),                Address offset: 0x02 - 0x03 */
    uint32_t    GPAQSEL2;               /* GPIO A Qualifier Select 2 Register (GPIO16 to 31),               Address offset: 0x04 - 0x05 */
    uint32_t    GPAMUX1;                /* GPIO A Mux 1 Register (GPIO0 to 15),                             Address offset: 0x06 - 0x07 */
    uint32_t    GPAMUX2;                /* GPIO A Mux 2 Register (GPIO16 to 31),                            Address offset: 0x08 - 0x09 */
    uint32_t    GPADIR;                 /* GPIO A Direction Register (GPIO0 to 31),                         Address offset: 0x0A - 0x0B */
    uint32_t    GPAPUD;                 /* GPIO A Pull Up Disable Register (GPIO0 to 31),                   Address offset: 0x0C - 0x0D */
    uint16_t    GPIO_CTRL_rsvd1[2];     /* Reserved,                                                        Address offset: 0x0E - 0x0F */
    uint32_t    GPAINV;                 /* GPIO A Input Polarity Invert Registers (GPIO0 to 31),            Address offset: 0x10 - 0x11 */
    uint32_t    GPAODR;                 /* GPIO A Open Drain Output Register (GPIO0 to GPIO31),             Address offset: 0x12 - 0x13 */
    uint32_t    GPAAMSEL;               /* GPIO A Analog Mode Select (GPIO0 to GPIO31),                     Address offset: 0x14 - 0x15 */
    uint16_t    GPIO_CTRL_rsvd2[10];    /* Reserved,                                                        Address offset: 0x16 - 0x1F */
    uint32_t    GPAGMUX1;               /* GPIO A Peripheral Group Mux (GPIO0 to 15),                       Address offset: 0x20 - 0x21 */
    uint32_t    GPAGMUX2;               /* GPIO A Peripheral Group Mux (GPIO16 to 31),                      Address offset: 0x22 - 0x23 */
    uint16_t    GPIO_CTRL_rsvd3[4];     /* Reserved,                                                        Address offset: 0x24 - 0x27 */
    uint32_t    GPACSEL1;               /* GPIO A Core Select Register (GPIO0 to 7),                        Address offset: 0x28 - 0x29 */
    uint32_t    GPACSEL2;               /* GPIO A Core Select Register (GPIO8 to 15),                       Address offset: 0x2A - 0x2B */
    uint32_t    GPACSEL3;               /* GPIO A Core Select Register (GPIO16 to 23),                      Address offset: 0x2C - 0x2D */
    uint32_t    GPACSEL4;               /* GPIO A Core Select Register (GPIO24 to 31),                      Address offset: 0x2E - 0x2F */
    uint16_t    GPIO_CTRL_rsvd4[12];    /* Reserved,                                                        Address offset: 0x30 - 0x3B */
    uint32_t    GPALOCK;                /* GPIO A Lock Configuration Register (GPIO0 to 31),                Address offset: 0x3C - 0x3D */
    uint32_t    GPACR;                  /* GPIO A Lock Commit Register (GPIO0 to 31),                       Address offset: 0x3E - 0x3F */
    uint32_t    GPBCTRL;                /* GPIO B Qualification Sampling Period Control (GPIO32 to 63),     Address offset: 0x40 - 0x41 */
    uint32_t    GPBQSEL1;               /* GPIO B Qualifier Select 1 Register (GPIO32 to 47),               Address offset: 0x42 - 0x43 */
    uint32_t    GPBQSEL2;               /* GPIO B Qualifier Select 2 Register (GPIO48 to 63),               Address offset: 0x44 - 0x45 */
    uint32_t    GPBMUX1;                /* GPIO B Mux 1 Register (GPIO32 to 47),                            Address offset: 0x46 - 0x47 */
    uint32_t    GPBMUX2;                /* GPIO B Mux 2 Register (GPIO48 to 63),                            Address offset: 0x48 - 0x49 */
    uint32_t    GPBDIR;                 /* GPIO B Direction Register (GPIO32 to 63),                        Address offset: 0x4A - 0x4B */
    uint32_t    GPBPUD;                 /* GPIO B Pull Up Disable Register (GPIO32 to 63),                  Address offset: 0x4C - 0x4D */
    uint16_t    GPIO_CTRL_rsvd5[2];     /* Reserved,                                                        Address offset: 0x4E - 0x4F */
    uint32_t    GPBINV;                 /* GPIO B Input Polarity Invert Registers (GPIO32 to 63),           Address offset: 0x50 - 0x51 */
    uint32_t    GPBODR;                 /* GPIO B Open Drain Output Register (GPIO32 to GPIO63),            Address offset: 0x52 - 0x53 */
    uint16_t    GPIO_CTRL_rsvd6[12];    /* Reserved,                                                        Address offset: 0x54 - 0x5F */
    uint32_t    GPBGMUX1;               /* GPIO B Peripheral Group Mux (GPIO32 to 47),                      Address offset: 0x60 - 0x61 */
    uint32_t    GPBGMUX2;               /* GPIO B Peripheral Group Mux (GPIO48 to 63),                      Address offset: 0x62 - 0x63 */
    uint16_t    GPIO_CTRL_rsvd7[4];     /* Reserved,                                                        Address offset: 0x64 - 0x67 */
    uint32_t    GPBCSEL1;               /* GPIO B Core Select Register (GPIO32 to 39),                      Address offset: 0x68 - 0x69 */
    uint32_t    GPBCSEL2;               /* GPIO B Core Select Register (GPIO40 to 47),                      Address offset: 0x6A - 0x6B */
    uint32_t    GPBCSEL3;               /* GPIO B Core Select Register (GPIO48 to 55),                      Address offset: 0x6C - 0x6D */
    uint32_t    GPBCSEL4;               /* GPIO B Core Select Register (GPIO56 to 63),                      Address offset: 0x6E - 0x6F */
    uint16_t    GPIO_CTRL_rsvd8[12];    /* Reserved,                                                        Address offset: 0x70 - 0x7B */
    uint32_t    GPBLOCK;                /* GPIO B Lock Configuration Register (GPIO32 to 63),               Address offset: 0x7C - 0x7D */
    uint32_t    GPBCR;                  /* GPIO B Lock Commit Register (GPIO32 to 63),                      Address offset: 0x7E - 0x7F */
    uint16_t    GPIO_CTRL_rsvd9[320];   /* Reserved,                                                        Address offset: 0x80 - 0x1BF  */
    uint32_t    GPHCTRL;                /* GPIO H Qualification Sampling Period Control (GPIO224 to 255),   Address offset: 0x1C0 - 0x1C1 */
    uint32_t    GPHQSEL1;               /* GPIO H Qualifier Select 1 Register (GPIO224 to 255),             Address offset: 0x1C2 - 0x1C3 */
    uint32_t    GPHQSEL2;               /* GPIO H Qualifier Select 2 Register (GPIO224 to 255),             Address offset: 0x1C4 - 0x1C5 */
    uint16_t    GPIO_CTRL_rsvd10[6];    /* Reserved,                                                        Address offset: 0x1C6 - 0x1CB */
    uint32_t    GPHPUD;                 /* GPIO H Pull Up Disable Register (GPIO224 to 255),                Address offset: 0x1CC - 0x1CD */
    uint16_t    GPIO_CTRL_rsvd11[2];    /* Reserved,                                                        Address offset: 0x1CE - 0x1CF */
    uint32_t    GPHINV;                 /* GPIO H Input Polarity Invert Registers (GPIO224 to 255),         Address offset: 0x1D0 - 0x1D1 */
    uint16_t    GPIO_CTRL_rsvd12[2];    /* Reserved,                                                        Address offset: 0x1D2 - 0x1D3 */
    uint32_t    GPHAMSEL;               /* GPIO H Analog Mode Select register (GPIO224 to 255),             Address offset: 0x1D4 - 0x1D5 */
    uint16_t    GPIO_CTRL_rsvd13[38];   /* Reserved,                                                        Address offset: 0x1D6 - 0x1FB */
    uint32_t    GPHLOCK;                /* GPIO H Lock Configuration Register (GPIO224 to 255),             Address offset: 0x1FC - 0x1FD */
    uint32_t    GPHCR;                  /* GPIO H Lock Commit Register (GPIO224 to 255),                    Address offset: 0x1FE - 0x1FF */
} GPIO_CTRL_Typedef;

/* Structure used to store states of GPIO output pin */ 
typedef struct{
    uint16_t gpio_number;
    uint16_t out_level;
} gpio_out_t;

/* Structure used to store states of GPIO input pin */ 
typedef struct{
    uint16_t gpio_number;
    uint16_t prev_raw_level;   /* Last raw GPIO value    */
    uint16_t in_level;         /* Debounced stable value */
    uint16_t debounce_cnt;     /* Current debounce counter     */
    uint16_t debounce_cycles;  /* Configurable debounce cycles */

} gpio_in_t;

/* Structure used to store states of GPIO pin used as peripheral pin*/ 
typedef struct{
    uint16_t gpio_number;
    uint16_t mux_position;
} gpio_peripheral_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void gpio_out_update(gpio_out_t * signal);
uint16_t gpio_in_read(uint16_t gpio_number);
void gpio_out_config(gpio_out_t * signal);
void gpio_in_config(gpio_in_t * signal);
void gpio_peripheral_config(gpio_peripheral_t * signal);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
/* Base addresses of peripheral register structures */
#define GPIOCTRL_BASE             0x00007C00U
#define GPIODATA_BASE             0x00007F00U

#define GPxMUX_GPIOy_Msk          3U     
#define GPxMUX_GPIOy_POS          2U
#define GPxPUD_GPIOy_Msk          1U
#define GPxDIR_GPIOy_Msk          1U
#define GPAAMSEL_GPIOy_Msk        1U
#define GPxMUX_GPIOy_SIZE         2U
#define GPxQSEL_GPIOy_Msk         2U
#define GPxQSEL_GPIOy_SIZE        2U

#define GPxDAT_Msk                1U
#define GPxSET_GPIOy_Msk          1U
#define GPxCLEAR_GPIOy_Msk        1U


#define GPIO20                    20U
#define GPIO21                    21U
#define GPIO22                    22U
#define GPIO23                    23U

#define GPIO_PIN_H                1U
#define GPIO_PIN_L                0U

#define HALF_WORD_SIZE            16U
#define WORD_SIZE                 32U
#define LONG_WORD_SIZE            64U

/* Pointer to base addresses of peripheral register structures */
#define GPIODATA            ((GPIO_DATA_Typedef *) GPIODATA_BASE)
#define GPIOCTRL            ((GPIO_CTRL_Typedef *) GPIOCTRL_BASE)

#endif /*BSP_GPIO_H*/

/****************************************************************************** 
* End of File 
******************************************************************************/
