/***********************************************************************************************
* File    : BSP_WATCHDOG.h
*
* Module  : Board Support Package (BSP) for WATCHDOG peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for WATCHDOG peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for WATCHDOG peripherals.
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
#ifndef BSP_WATCHDOG_H
#define BSP_WATCHDOG_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef struct {
    uint16_t resv1[34];
    uint16_t SCSR;       /* 22h System Control & Status Register */
    uint16_t WDCNTR;     /* 23h Watchdog Counter Register */
    uint16_t resv2;
    uint16_t WDKEY;      /* 25h Watchdog Reset Key Register */
    uint16_t resv3[3];
    uint16_t WDCR;       /* 29h Watchdog Control Register */
    uint16_t WDWCR;      /* 2Ah Watchdog Windowed Control Register */
} WD_Typedef;

typedef enum {
    ratio_2 = 2,
    ratio_4 = 4,
    ratio_8 = 8,
    ratio_16 = 16,
    ratio_32 = 32,
    ratio_64 = 64,
    ratio_128 = 128,
    ratio_256 = 256,
    ratio_512 = 512,
    ratio_1024 = 1024,
    ratio_2048 = 2048,

}watchdog_prescaler_ratio_t;

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define WDCR_WDPRECLKDIV_Msk        ((uint16_t)0x0F00)
#define WDCR_WDPRECLKDIV_Pos        ((uint16_t)8)
#define WDCR_WDFLAG                 ((uint16_t)0x0080)
#define WDCR_WDDIS                  ((uint16_t)0x0040)
#define WDCR_WDCHK                  ((uint16_t)0x0038)
#define WDCR_WDPS_Msk               ((uint16_t)0x0007)
#define WDCR_WDPS_Pos               ((uint16_t)0)

#define WDCR_WDCHK_VALUE            ((uint16_t)0x0028)

#define WDPRECLKDIV_PREDIVCLK_2     ((uint16_t)0x8)
#define WDPRECLKDIV_PREDIVCLK_4     ((uint16_t)0x9)
#define WDPRECLKDIV_PREDIVCLK_8     ((uint16_t)0xA)
#define WDPRECLKDIV_PREDIVCLK_16    ((uint16_t)0xB)
#define WDPRECLKDIV_PREDIVCLK_32    ((uint16_t)0xC)
#define WDPRECLKDIV_PREDIVCLK_64    ((uint16_t)0xD)
#define WDPRECLKDIV_PREDIVCLK_128   ((uint16_t)0xE)
#define WDPRECLKDIV_PREDIVCLK_256   ((uint16_t)0xF)
#define WDPRECLKDIV_PREDIVCLK_512   ((uint16_t)0x0)
#define WDPRECLKDIV_PREDIVCLK_1024  ((uint16_t)0x1)
#define WDPRECLKDIV_PREDIVCLK_2048  ((uint16_t)0x2)
#define WDPRECLKDIV_PREDIVCLK_4096  ((uint16_t)0x3)

#define WD_BASE         0x00007000U

#define WD              ((WD_Typedef *)WD_BASE)

#define WDKEY_UNLOCK                  (0x55)
#define WDKEY_RESET                   (0xAA)
#define TIMEOUT_US_WITHOUT_PRESCALER  (25.6f)

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void watchdog_disable(void);
void watchdog_enable(uint32_t timeout_us);
void watchdog_service(void);

#endif/*BSP_WATCHDOG_H*/
/****************************************************************************** 
* End of File 
******************************************************************************/
