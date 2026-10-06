/***********************************************************************************************
* File: BSP_WATCHDOG.c
* Project: 
* Module: Board Support Package (BSP) for WATCHDOG peripherals.
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for WATCHDOG peripherals
*
* Description:
* This file contains board-specific driver functions for WATCHDOG with direct
* interaction to the underlying hardware.
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
* - BSP_WATCHDOG.h 
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
#include "BSP_WATCHDOG.h"

/******************************************************************************
* Macro Definitions
******************************************************************************/
#define EALLOW      __asm(" EALLOW")
#define EDIS        __asm(" EDIS")

/******************************************************************************
* Function     : watchdog_disable 
*
* Purpose      : 
* Disable the watchdog timer.
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
* Requirements :
*
* Notes        : 
*
******************************************************************************/ 
void watchdog_disable(void)
{
    uint16_t temp;
    EALLOW;
    temp= WD->WDCR;
    /* Clear check bits and set required key value for write access */
    temp &= ~WDCR_WDCHK;
    temp |= WDCR_WDCHK_VALUE;
    /* Disable watchdog timer */
    temp |= WDCR_WDDIS; 
    WD->WDCR = temp;
    EDIS;
}

/******************************************************************************
* Function     : watchdog_enable 
*
* Purpose      : 
* Enable watchdog timer.
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
* Requirements :
*
* Notes        : 
*
******************************************************************************/ 
void watchdog_enable(uint32_t timeout_us)
{
    uint32_t ratio = timeout_us/TIMEOUT_US_WITHOUT_PRESCALER;
    uint16_t prescalar;
    uint16_t temp;

	/* Select prescaler for timeout */
    if (ratio <= ratio_2)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_2;
    }
    else if (ratio <= ratio_4)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_4;
    }
    else if (ratio <= ratio_8)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_8;
    }
    else if (ratio <= ratio_16)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_16;
    }
    else if (ratio <= ratio_32)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_32;
    }
    else if (ratio <= ratio_64)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_64;
    }
    else if (ratio <= ratio_128)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_128;
    }
    else if (ratio <= ratio_256)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_256;
    }
    else if (ratio <= ratio_512)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_512;
    }
    else if (ratio <= ratio_1024)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_1024;
    }
    else if (ratio <= ratio_2048)
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_2048;
    }
    else
    {
        prescalar = WDPRECLKDIV_PREDIVCLK_4096;
    }

    EALLOW;
    temp= WD->WDCR;
    temp &= ~WDCR_WDPRECLKDIV_Msk;
    temp |= (prescalar<<WDCR_WDPRECLKDIV_Pos) & WDCR_WDPRECLKDIV_Msk;
    temp &= ~WDCR_WDPS_Msk;
    temp &= ~WDCR_WDCHK;
    temp |= WDCR_WDCHK_VALUE;
    temp &= ~WDCR_WDDIS; 
    WD->WDCR = temp;
    EDIS;
}

/******************************************************************************
* Function     : watchdog_service 
*
* Purpose      : 
* Services the watchdog timer.
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
void watchdog_service(void)
{
    EALLOW;
    WD->WDKEY = WDKEY_UNLOCK;
    WD->WDKEY = WDKEY_RESET;
    EDIS;
}
/*************** End of C File ************************************************/

