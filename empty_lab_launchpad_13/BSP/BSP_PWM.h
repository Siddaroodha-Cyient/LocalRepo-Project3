/***********************************************************************************************
* File    : BSP_PWM.h
*
* Module  : Board Support Package (BSP) for PWM peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for PWM peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for PWM peripherals.
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
#ifndef BSP_PWM_H
#define BSP_PWM_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>
#include "BSP_GPIO.h"

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
/* Structure used to access EPWM peripheral registers */ 
typedef struct{
    uint16_t    TBCTL;              /* Time Base Control Register,                                              Address offset: 0x00        */
    uint16_t    TBCTL2;             /* Time Base Control Register 2,                                            Address offset: 0x01        */
    uint16_t    EPWM_rsvd1S[2];     /* Reserved,                                                                Address offset: 0x02 - 0x03 */
    uint16_t    TBCTR;              /* Time Base Counter Register,                                              Address offset: 0x04        */
    uint16_t    TBSTS;              /* Time Base Status Register,                                               Address offset: 0x05        */
    uint16_t    EPWM_rsvd2S[2];     /* Reserved,                                                                Address offset: 0x06 - 0x07 */
    uint16_t    CMPCTL;             /* Counter Compare Control Register,                                        Address offset: 0x08        */
    uint16_t    CMPCTL2;            /* Counter Compare Control Register 2,                                      Address offset: 0x09        */
    uint16_t    EPWM_rsvd3S[2];     /* Reserved,                                                                Address offset: 0x0A - 0x0B */
    uint16_t    DBCTL;              /* Dead-Band Generator Control Register,                                    Address offset: 0x0C        */
    uint16_t    DBCTL2;             /* Dead-Band Generator Control Register 2,                                  Address offset: 0x0D        */
    uint16_t    EPWM_rsvd4S[2];     /* Reserved,                                                                Address offset: 0x0E - 0x0F */
    uint16_t    AQCTL;              /* Action Qualifier Control Register,                                       Address offset: 0x10        */
    uint16_t    AQTSRCSEL;          /* Action Qualifier Trigger Event Source Select Register,                   Address offset: 0x11        */
    uint16_t    EPWM_rsvd5S[2];     /* Reserved,                                                                Address offset: 0x12 - 0x13 */
    uint16_t    PCCTL;              /* PWM Chopper Control Register,                                            Address offset: 0x14        */
    uint16_t    EPWM_rsvd6S[3];     /* Reserved,                                                                Address offset: 0x15 - 0x17 */
    uint16_t    VCAPCTL;            /* Valley Capture Control Register,                                         Address offset: 0x18        */
    uint16_t    VCNTCFG;            /* Valley Counter Config Register,                                          Address offset: 0x19        */
    uint16_t    EPWM_rsvd7S[6];     /* Reserved,                                                                Address offset: 0x1A - 0x1F */
    uint16_t    HRCNFG;             /* HRPWM Configuration Register,                                            Address offset: 0x20        */
    uint16_t    HRPWR;              /* HRPWM Power Register,                                                    Address offset: 0x21        */
    uint16_t    EPWM_rsvd8S[4];     /* Reserved,                                                                Address offset: 0x22 - 0x25 */
    uint16_t    HRMSTEP;            /* HRPWM MEP Step Register,                                                 Address offset: 0x26        */
    uint16_t    HRCNFG2;            /* HRPWM Configuration 2 Register,                                          Address offset: 0x27        */
    uint16_t    EPWM_rsvd9S[5];     /* Reserved,                                                                Address offset: 0x28 - 0x2C */
    uint16_t    HRPCTL;             /* High Resolution Period Control Register,                                 Address offset: 0x2D        */
    uint16_t    TRREM;              /* HRPWM High Resolution Remainder Register,                                Address offset: 0x2E        */
    uint16_t    EPWM_rsvd10S[5];    /* Reserved,                                                                Address offset: 0x2F - 0x33 */
    uint16_t    GLDCTL;             /* Global PWM Load Control Register,                                        Address offset: 0x34        */
    uint16_t    GLDCFG;             /* Global PWM Load Config Register,                                         Address offset: 0x35        */
    uint16_t    EPWM_rsvd11S[2];    /* Reserved,                                                                Address offset: 0x36 - 0x37 */
    uint32_t    EPWMXLINK;          /* EPWMx Link Register,                                                     Address offset: 0x38 - 0x39 */
    uint16_t    EPWM_rsvd12S[6];    /* Reserved,                                                                Address offset: 0x3A - 0x3F */
    uint16_t    AQCTLA;             /* Action Qualifier Control Register For Output A,                          Address offset: 0x40        */
    uint16_t    AQCTLA2;            /* Additional Action Qualifier Control Register For Output A,               Address offset: 0x41        */
    uint16_t    AQCTLB;             /* Action Qualifier Control Register For Output B,                          Address offset: 0x42        */
    uint16_t    AQCTLB2;            /* Additional Action Qualifier Control Register For Output B,               Address offset: 0x43        */
    uint16_t    EPWM_rsvd13S[3];    /* Reserved,                                                                Address offset: 0x44 - 0x46 */
    uint16_t    AQSFRC;             /* Action Qualifier Software Force Register,                                Address offset: 0x47        */
    uint16_t    EPWM_rsvd14;        /* Reserved,                                                                Address offset: 0x48        */
    uint16_t    AQCSFRC;            /* Action Qualifier Continuous S/W Force Register,                          Address offset: 0x49        */
    uint16_t    EPWM_rsvd15S[6];    /* Reserved,                                                                Address offset: 0x4A - 0x4F */
    uint16_t    DBREDHR;            /* Dead-Band Generator Rising Edge Delay High Resolution Mirror Register,   Address offset: 0x50        */
    uint16_t    DBRED;              /* Dead-Band Generator Rising Edge Delay High Resolution Mirror Register,   Address offset: 0x51        */
    uint16_t    DBFEDHR;            /* Dead-Band Generator Falling Edge Delay High Resolution Register,         Address offset: 0x52        */
    uint16_t    DBFED;              /* Dead-Band Generator Falling Edge Delay Count Register,                   Address offset: 0x53        */
    uint16_t    EPWM_rsvd16S[12];   /* Reserved,                                                                Address offset: 0x54 - 0x5F */
    uint32_t    TBPHS;              /* Time Base Phase High,                                                    Address offset: 0x60 - 0x61 */
    uint16_t    TBPRDHR;            /* Time Base Period High Resolution Register,                               Address offset: 0x62        */
    uint16_t    TBPRD;              /* Time Base Period Register,                                               Address offset: 0x63        */
    uint16_t    EPWM_rsvd17S[6];    /* Reserved,                                                                Address offset: 0x64 - 0x69 */
    uint32_t    CMPA;               /* Counter Compare A Register,                                              Address offset: 0x6A - 0x6B */
    uint32_t    CMPB;               /* Compare B Register,                                                      Address offset: 0x6C - 0x6D */
    uint16_t    EPWM_rsvd18;        /* Reserved,                                                                Address offset: 0x6E        */
    uint16_t    CMPC;               /* Counter Compare C Register,                                              Address offset: 0x6F        */
    uint16_t    EPWM_rsvd19;        /* Reserved,                                                                Address offset: 0x70        */
    uint16_t    CMPD;               /* Counter Compare D Register,                                              Address offset: 0x71        */
    uint16_t    EPWM_rsvd20S[2];    /* Reserved,                                                                Address offset: 0x72 - 0x73 */
    uint16_t    GLDCTL2;            /* Global PWM Load Control Register 2,                                      Address offset: 0x74        */
    uint16_t    EPWM_rsvd21S[2];    /* Reserved,                                                                Address offset: 0x75 - 0x76 */
    uint16_t    SWVDELVAL;          /* Software Valley Mode Delay Register,                                     Address offset: 0x77        */
    uint16_t    EPWM_rsvd22S[8];    /* Reserved,                                                                Address offset: 0x78 - 0x7F */
    uint16_t    TZSEL;              /* Trip Zone Select Register,                                               Address offset: 0x80        */
    uint16_t    EPWM_rsvd23;        /* Reserved,                                                                Address offset: 0x81        */
    uint16_t    TZDCSEL;            /* Trip Zone Digital Comparator Select Register,                            Address offset: 0x82        */
    uint16_t    EPWM_rsvd24;        /* Reserved,                                                                Address offset: 0x83        */
    uint16_t    TZCTL;              /* Trip Zone Control Register,                                              Address offset: 0x84        */
    uint16_t    TZCTL2;             /* Additional Trip Zone Control Register,                                   Address offset: 0x85        */
    uint16_t    TZCTLDCA;           /* Trip Zone Control Register Digital Compare A,                            Address offset: 0x86        */
    uint16_t    TZCTLDCB;           /* Trip Zone Control Register Digital Compare B,                            Address offset: 0x87        */
    uint16_t    EPWM_rsvd25S[5];    /* Reserved,                                                                Address offset: 0x88 - 0x8C */
    uint16_t    TZEINT;             /* Trip Zone Enable Interrupt Register,                                     Address offset: 0x8D        */
    uint16_t    EPWM_rsvd26S[5];    /* Reserved,                                                                Address offset: 0x8E - 0x92 */
    uint16_t    TZFLG;              /* Trip Zone Flag Register,                                                 Address offset: 0x93        */
    uint16_t    TZCBCFLG;           /* Trip Zone CBC Flag Register,                                             Address offset: 0x94        */
    uint16_t    TZOSTFLG;           /* Trip Zone OST Flag Register,                                             Address offset: 0x95        */
    uint16_t    EPWM_rsvd27;        /* Reserved,                                                                Address offset: 0x96        */
    uint16_t    TZCLR;              /* Trip Zone Clear Register,                                                Address offset: 0x97        */
    uint16_t    TZCBCCLR;           /* Trip Zone CBC Clear Register,                                            Address offset: 0x98        */
    uint16_t    TZOSTCLR;           /* Trip Zone OST Clear Register,                                            Address offset: 0x99        */
    uint16_t    EPWM_rsvd28;        /* Reserved,                                                                Address offset: 0x9A        */
    uint16_t    TZFRC;              /* Trip Zone Force Register,                                                Address offset: 0x9B        */
    uint16_t    EPWM_rsvd29S[8];    /* Reserved,                                                                Address offset: 0x9C - 0x93 */
    uint16_t    ETSEL;              /* Event Trigger Selection Register,                                        Address offset: 0xA4        */
    uint16_t    EPWM_rsvd30;        /* Reserved,                                                                Address offset: 0xA5        */
    uint16_t    ETPS;               /* Event Trigger Pre-Scale Register,                                        Address offset: 0xA6        */
    uint16_t    EPWM_rsvd31;        /* Reserved,                                                                Address offset: 0xA7        */
    uint16_t    ETFLG;              /* Event Trigger Flag Register,                                             Address offset: 0xA8        */
    uint16_t    EPWM_rsvd32;        /* Reserved,                                                                Address offset: 0xA9        */
    uint16_t    ETCLR;              /* Event Trigger Clear Register,                                            Address offset: 0xAA        */
    uint16_t    EPWM_rsvd33;        /* Reserved,                                                                Address offset: 0xAB        */
    uint16_t    ETFRC;              /* Event Trigger Force Register,                                            Address offset: 0xAC        */
    uint16_t    EPWM_rsvd34;        /* Reserved,                                                                Address offset: 0xAD        */
    uint16_t    ETINTPS;            /* Event-Trigger Interrupt Pre-Scale Register,                              Address offset: 0xAE        */
    uint16_t    EPWM_rsvd35;        /* Reserved,                                                                Address offset: 0xAF        */
    uint16_t    ETSOCPS;            /* Event-Trigger SOC Pre-Scale Register,                                    Address offset: 0xB0        */
    uint16_t    EPWM_rsvd36;        /* Reserved,                                                                Address offset: 0xB1        */
    uint16_t    ETCNTINITCTL;       /* Event-Trigger Counter Initialization Control Register,                   Address offset: 0xB2        */
    uint16_t    EPWM_rsvd37;        /* Reserved,                                                                Address offset: 0xB3        */
    uint16_t    ETCNTINIT;          /* Event-Trigger Counter Initialization Register,                           Address offset: 0xB4        */
    uint16_t    EPWM_rsvd38S[11];   /* Reserved,                                                                Address offset: 0xB5 - 0xBF */
    uint16_t    DCTRIPSEL;          /* Digital Compare Trip Select Register,                                    Address offset: 0xC0        */
    uint16_t    EPWM_rsvd39S[2];    /* Reserved,                                                                Address offset: 0xC1 - 0xC2 */
    uint16_t    DCACTL;             /* Digital Compare A Control Register,                                      Address offset: 0xC3        */
    uint16_t    DCBCTL;             /* Digital Compare B Control Register,                                      Address offset: 0xC4        */
    uint16_t    EPWM_rsvd40S[2];    /* Reserved,                                                                Address offset: 0xC5 - 0xC6 */
    uint16_t    DCFCTL;             /* Digital Compare Filter Control Register,                                 Address offset: 0xC7        */
    uint16_t    DCCAPCTL;           /* Digital Compare Capture Control Register,                                Address offset: 0xC8        */
    uint16_t    DCFOFFSET;          /* Digital Compare Filter Offset Register,                                  Address offset: 0xC9        */
    uint16_t    DCFOFFSETCNT;       /* Digital Compare Filter Offset Counter Register,                          Address offset: 0xCA        */
    uint16_t    DCFWINDOW;          /* Digital Compare Filter Window Register,                                  Address offset: 0xCB        */
    uint16_t    DCFWINDOWCNT;       /* Digital Compare Filter Window Counter Register,                          Address offset: 0xCC        */
    uint16_t    EPWM_rsvd41S[2];    /* Reserved,                                                                Address offset: 0xCD - 0xCE */
    uint16_t    DCCAP;              /* Digital Compare Counter Capture Register,                                Address offset: 0xCF        */
    uint16_t    EPWM_rsvd42S[2];    /* Reserved,                                                                Address offset: 0xD0 - 0xD1 */
    uint16_t    DCAHTRIPSEL;        /* Digital Compare AH Trip Select,                                          Address offset: 0xD2        */
    uint16_t    DCALTRIPSEL;        /* Digital Compare AL Trip Select,                                          Address offset: 0xD3        */
    uint16_t    DCBHTRIPSEL;        /* Digital Compare BH Trip Select,                                          Address offset: 0xD4        */
    uint16_t    DCBLTRIPSEL;        /* Digital Compare BL Trip Select,                                          Address offset: 0xD5        */
    uint16_t    EPWM_rsvd43S[39];   /* Reserved,                                                                Address offset: 0xD6 - 0xFC */
    uint16_t    HWVDELVAL;          /* Hardware Valley Mode Delay Register,                                     Address offset: 0xFD        */
    uint16_t    VCNTVAL;            /* Hardware Valley Counter Register,                                        Address offset: 0xFE        */
} EPWM_Typedef;


/* Structure used to store states of an EPWM channel*/ 
typedef struct{
    gpio_peripheral_t top;
    gpio_peripheral_t bottom;
    EPWM_Typedef * EPWM;
    float duty;
    uint32_t frequency;
} pwm_channel_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void pwm_config(EPWM_Typedef * EPWM);
void pwm_duty_update(EPWM_Typedef * EPWM, float duty);
void pwm_disable_channel(EPWM_Typedef * EPWM);
void pwm_enable_channel(EPWM_Typedef * EPWM);
void pwm_freq_update(EPWM_Typedef * EPWM, uint32_t frequency);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/

#define TBCTL_BITS_CTRMODE_Msk      ((uint16_t)0b0000000000000011U)     /* 1:0 Counter Mode                 */
#define TBCTL_BITS_PHSEN_Msk        ((uint16_t)0b0000000000000100U)     /* 2 Phase Load Enable              */
#define TBCTL_BITS_PRDLD_Msk        ((uint16_t)0b0000000000001000U)     /* 3 Active Period Load             */
#define TBCTL_BITS_SYNCOSEL_Msk     ((uint16_t)0b0000000000110000U)     /* 5:4 Sync Output Select           */
#define TBCTL_BITS_SWFSYNC_Msk      ((uint16_t)0b0000000001000000U)     /* 6 Software Force Sync Pulse      */
#define TBCTL_BITS_HSPCLKDIV_Msk    ((uint16_t)0b0000001110000000U)     /* 9:7 High Speed TBCLK Pre-scaler  */
#define TBCTL_BITS_CLKDIV_Msk       ((uint16_t)0b0001110000000000U)     /* 12:10 Time Base Clock Pre-scaler */
#define TBCTL_BITS_PHSDIR_Msk       ((uint16_t)0b0010000000000000U)     /* 13 Phase Direction Bit           */
#define TBCTL_BITS_FREE_SOFT_Msk    ((uint16_t)0b1100000000000000U)     /* 15:14 Emulation Mode Bits        */

#define TBCTL_BITS_CTRMODE_Pos      ((uint16_t)0U)      /* 1:0 Counter Mode                 */
#define TBCTL_BITS_SYNCOSEL_Pos     ((uint16_t)4U)      /* 5:4 Sync Output Select           */
#define TBCTL_BITS_HSPCLKDIV_Pos    ((uint16_t)7U)      /* 9:7 High Speed TBCLK Pre-scaler  */
#define TBCTL_BITS_CLKDIV_pos       ((uint16_t)10U)     /* 12:10 Time Base Clock Pre-scaler */
#define TBCTL_BITS_FREE_SOFT_Pos    ((uint16_t)14U)     /* 15:14 Emulation Mode Bits        */

#define CMPCTL_BITS_LOADAMODE_Msk   ((uint16_t)0b0000000000000011U)     /* 1:0 Active Compare A Load                    */
#define CMPCTL_BITS_LOADBMODE_Msk   ((uint16_t)0b0000000000001100U)     /* 3:2 Active Compare B Load                    */
#define CMPCTL_BITS_SHDWAMODE       ((uint16_t)0b0000000000010000U)     /* 4 Compare A Register Block Operating Mode    */
#define CMPCTL_BITS_rsvd1           ((uint16_t)0b0000000000100000U)     /* 5 Reserved                                   */
#define CMPCTL_BITS_SHDWBMODE       ((uint16_t)0b0000000001000000U)     /* 6 Compare B Register Block Operating Mode    */
#define CMPCTL_BITS_rsvd2           ((uint16_t)0b0000000010000000U)     /* 7 Reserved                                   */
#define CMPCTL_BITS_SHDWAFULL       ((uint16_t)0b0000000100000000U)     /* 8 Compare A Shadow Register Full Status      */
#define CMPCTL_BITS_SHDWBFULL       ((uint16_t)0b0000001000000000U)     /* 9 Compare B Shadow Register Full Status      */
#define CMPCTL_BITS_LOADASYNC_Msk   ((uint16_t)0b0000110000000000U)     /* 11:10 Active Compare A Load on SYNC          */
#define CMPCTL_BITS_LOADBSYNC_Msk   ((uint16_t)0b0011000000000000U)     /* 13:12 Active Compare B Load on SYNC          */
#define CMPCTL_BITS_rsvd3_Msk       ((uint16_t)0b1100000000000000U)     /* 15:14 Reserved                               */

#define ETSEL_BITS_INTSEL_Msk       ((uint16_t)0b0000000000000111U)     /* 2:0 EPWMxINTn Select                 */
#define ETSEL_BITS_INTEN            ((uint16_t)0b0000000000001000U)     /* 3 EPWMxINTn Enable                   */
#define ETSEL_BITS_SOCASELCMP       ((uint16_t)0b0000000000010000U)     /* 4 EPWMxSOCA Compare Select           */
#define ETSEL_BITS_SOCBSELCMP       ((uint16_t)0b0000000000100000U)     /* 5 EPWMxSOCB Compare Select           */
#define ETSEL_BITS_INTSELCMP        ((uint16_t)0b0000000001000000U)     /* 6 EPWMxINT Compare Select            */
#define ETSEL_BITS_rsvd1            ((uint16_t)0b0000000010000000U)     /* 7 Reserved                           */
#define ETSEL_BITS_SOCASEL_Msk      ((uint16_t)0b0000011100000000U)     /* 10:8 Start of Conversion A Select    */
#define ETSEL_BITS_SOCAEN           ((uint16_t)0b0000100000000000U)     /* 11 Start of Conversion A Enable      */
#define ETSEL_BITS_SOCBSEL_Msk      ((uint16_t)0b0111000000000000U)     /* 14:12 Start of Conversion B Select   */
#define ETSEL_BITS_SOCBEN           ((uint16_t)0b1000000000000000U)     /* 15 Start of Conversion B Enable      */

#define TBPHS_BITS_TBPHSHR_Msk      ((uint32_t)0x0000FFFFU)     /* 15:0 Extension Register for HRPWM Phase (8-bitsU)    */
#define TBPHS_BITS_TBPHS_Msk        ((uint32_t)0xFFFF0000U)     /* 31:16 Phase Offset Register                          */

#define TBPHS_BITS_TBPHS_Pos        ((uint32_t)16)     /* 31:16 Phase Offset Register                          */

#define TBCTL_BITS_CTRMODE_Msk      ((uint16_t)0b0000000000000011U)     /* 1:0 Counter Mode                 */
#define TBCTL_BITS_PHSEN            ((uint16_t)0b0000000000000100U)     /* 2 Phase Load Enable              */
#define TBCTL_BITS_PRDLD            ((uint16_t)0b0000000000001000U)     /* 3 Active Period Load             */
#define TBCTL_BITS_SYNCOSEL_Msk     ((uint16_t)0b0000000000110000U)     /* 5:4 Sync Output Select           */
#define TBCTL_BITS_SWFSYNC          ((uint16_t)0b0000000001000000U)     /* 6 Software Force Sync Pulse      */
#define TBCTL_BITS_HSPCLKDIV_Msk    ((uint16_t)0b0000001110000000U)     /* 9:7 High Speed TBCLK Pre-scaler  */
#define TBCTL_BITS_CLKDIV_Msk       ((uint16_t)0b0001110000000000U)     /* 12:10 Time Base Clock Pre-scaler */
#define TBCTL_BITS_PHSDIR           ((uint16_t)0b0010000000000000U)     /* 13 Phase Direction Bit           */
#define TBCTL_BITS_FREE_SOFT_Msk    ((uint16_t)0b1100000000000000U)     /* 15:14 Emulation Mode Bits        */

#define CMPA_BITS_CMPAHR_Msk        ((uint32_t)0x0000FFFFU)     /* 15:0 Compare A HRPWM Extension Register  */
#define CMPA_BITS_CMPA_Msk          ((uint32_t)0xFFFF0000U)     /* 31:16 Compare A Register                 */

#define CMPA_BITS_CMPA_Pos          ((uint16_t)16U)     /* 31:16 Compare A Register                 */

#define AQCTLA_BITS_ZRO_Msk         ((uint16_t)0b0000000000000011U)     /* 1:0 Action Counter = Zero                */
#define AQCTLA_BITS_PRD_Msk         ((uint16_t)0b0000000000001100U)     /* 3:2 Action Counter = Period              */
#define AQCTLA_BITS_CAU_Msk         ((uint16_t)0b0000000000110000U)     /* 5:4 Action Counter = Compare A Up        */
#define AQCTLA_BITS_CAD_Msk         ((uint16_t)0b0000000011000000U)     /* 7:6 Action Counter = Compare A Down      */
#define AQCTLA_BITS_CBU_Msk         ((uint16_t)0b0000001100000000U)     /* 9:8 Action Counter = Compare B Up        */
#define AQCTLA_BITS_CBD_Msk         ((uint16_t)0b0000110000000000U)     /* 11:10 Action Counter = Compare B Down    */
#define AQCTLA_BITS_rsvd1_Msk       ((uint16_t)0b1111000000000000U)     /* 15:12 Reserved                           */

#define AQCTLA_BITS_ZRO_Pos         ((uint16_t)0U)      /* 1:0 Action Counter = Zero                */
#define AQCTLA_BITS_PRD_Pos         ((uint16_t)2U)      /* 3:2 Action Counter = Period              */
#define AQCTLA_BITS_CAU_Pos         ((uint16_t)4U)      /* 5:4 Action Counter = Compare A Up        */
#define AQCTLA_BITS_CAD_Pos         ((uint16_t)6U)      /* 7:6 Action Counter = Compare A Down      */
#define AQCTLA_BITS_CBU_Pos         ((uint16_t)8U)      /* 9:8 Action Counter = Compare B Up        */
#define AQCTLA_BITS_CBD_Pos         ((uint16_t)10U)     /* 11:10 Action Counter = Compare B Down    */

#define ETSEL_BITS_INTSEL_Msk       ((uint16_t)0b0000000000000111U)     /* 2:0 EPWMxINTn Select                 */
#define ETSEL_BITS_INTEN            ((uint16_t)0b0000000000001000U)     /* 3 EPWMxINTn Enable                   */
#define ETSEL_BITS_SOCASELCMP       ((uint16_t)0b0000000000010000U)     /* 4 EPWMxSOCA Compare Select           */
#define ETSEL_BITS_SOCBSELCMP       ((uint16_t)0b0000000000100000U)     /* 5 EPWMxSOCB Compare Select           */
#define ETSEL_BITS_INTSELCMP        ((uint16_t)0b0000000001000000U)     /* 6 EPWMxINT Compare Select            */
#define ETSEL_BITS_rsvd1            ((uint16_t)0b0000000010000000U)     /* 7 Reserved                           */
#define ETSEL_BITS_SOCASEL_Msk      ((uint16_t)0b0000011100000000U)     /* 10:8 Start of Conversion A Select    */
#define ETSEL_BITS_SOCAEN           ((uint16_t)0b0000100000000000U)     /* 11 Start of Conversion A Enable      */
#define ETSEL_BITS_SOCBSEL_Msk      ((uint16_t)0b0111000000000000U)     /* 14:12 Start of Conversion B Select   */
#define ETSEL_BITS_SOCBEN           ((uint16_t)0b1000000000000000U)     /* 15 Start of Conversion B Enable      */

#define ETSEL_BITS_INTSEL_Pos       ((uint16_t)0U)      /* 2:0 EPWMxINTn Select                 */
#define ETSEL_BITS_SOCASEL_Pos      ((uint16_t)8U)      /* 10:8 Start of Conversion A Select    */
#define ETSEL_BITS_SOCBSEL_Pos      ((uint16_t)12U)     /* 14:12 Start of Conversion B Select   */

#define ETPS_BITS_INTPRD_Msk        ((uint16_t)0b0000000000000011U)     /* 1:0 EPWMxINTn Period Select              */
#define ETPS_BITS_INTCNT_Msk        ((uint16_t)0b0000000000001100U)     /* 3:2 EPWMxINTn Counter Register           */
#define ETPS_BITS_INTPSSEL          ((uint16_t)0b0000000000010000U)     /* 4 EPWMxINTn Pre-Scale Selection Bits     */
#define ETPS_BITS_SOCPSSEL          ((uint16_t)0b0000000000100000U)     /* 5 EPWMxSOC A/B  Pre-Scale Selection Bits */
#define ETPS_BITS_rsvd1_Msk         ((uint16_t)0b0000000011000000U)     /* 7:6 Reserved                             */
#define ETPS_BITS_SOCAPRD_Msk       ((uint16_t)0b0000001100000000U)     /* 9:8 EPWMxSOCA Period Select              */
#define ETPS_BITS_SOCACNT_Msk       ((uint16_t)0b0000110000000000U)     /* 11:10 EPWMxSOCA Counter Register         */
#define ETPS_BITS_SOCBPRD_Msk       ((uint16_t)0b0011000000000000U)     /* 13:12 EPWMxSOCB Period Select            */
#define ETPS_BITS_SOCBCNT_Msk       ((uint16_t)0b1100000000000000U)     /* 15:14 EPWMxSOCB Counter                  */

#define ETPS_BITS_INTPRD_Pos        ((uint16_t)0U)      /* 1:0 EPWMxINTn Period Select              */
#define ETPS_BITS_INTCNT_Pos        ((uint16_t)2U)      /* 3:2 EPWMxINTn Counter Register           */
#define ETPS_BITS_SOCAPRD_Pos       ((uint16_t)8U)      /* 9:8 EPWMxSOCA Period Select              */
#define ETPS_BITS_SOCACNT_Pos       ((uint16_t)10U)     /* 11:10 EPWMxSOCA Counter Register         */
#define ETPS_BITS_SOCBPRD_Pos       ((uint16_t)12U)     /* 13:12 EPWMxSOCB Period Select            */
#define ETPS_BITS_SOCBCNT_Pos       ((uint16_t)14U)     /* 15:14 EPWMxSOCB Counter                  */

#define ETFLG_BITS_INT              ((uint16_t)0b0000000000000001U)     /* 0 EPWMxINTn Flag     */
#define ETFLG_BITS_rsvd1            ((uint16_t)0b0000000000000010U)     /* 1 Reserved           */
#define ETFLG_BITS_SOCA             ((uint16_t)0b0000000000000100U)     /* 2 EPWMxSOCA Flag     */
#define ETFLG_BITS_SOCB             ((uint16_t)0b0000000000001000U)     /* 3 EPWMxSOCB Flag     */
#define ETFLG_BITS_rsvd2_Msk        ((uint16_t)0b1111111111110000U)     /* 15:4 Reserved        */

#define ETINTPS_BITS_INTPRD2_Msk    ((uint16_t)0b0000000000001111U)     /* 3:0 EPWMxINTn Period Select      */
#define ETINTPS_BITS_INTCNT2_Msk    ((uint16_t)0b0000000011110000U)     /* 7:4 EPWMxINTn Counter Register   */
#define ETINTPS_BITS_rsvd1_Msk      ((uint16_t)0b1111111100000000U)     /* 15:8 Reserved                    */

#define ETSOCPS_BITS_SOCAPRD2_Msk   ((uint16_t)0b0000000000001111U)     /* 3:0 EPWMxSOCA Period Select      */
#define ETSOCPS_BITS_SOCACNT2_Msk   ((uint16_t)0b0000000011110000U)     /* 7:4 EPWMxSOCA Counter Register   */
#define ETSOCPS_BITS_SOCBPRD2_Msk   ((uint16_t)0b0000111100000000U)     /* 11:8 EPWMxSOCB Period Select     */
#define ETSOCPS_BITS_SOCBCNT2_Msk   ((uint16_t)0b1111000000000000U)     /* 15:12 EPWMxSOCB Counter Register */

#define DBCTL_BITS_OUT_MODE_Msk     ((uint16_t)0b0000000000000011U)     /* 1:0 Dead Band Output Mode Control        */
#define DBCTL_BITS_POLSEL_Msk       ((uint16_t)0b0000000000001100U)     /* 3:2 Polarity Select Control              */
#define DBCTL_BITS_IN_MODE_Msk      ((uint16_t)0b0000000000110000U)     /* 5:4 Dead Band Input Select Mode Control  */
#define DBCTL_BITS_LOADREDMODE_Msk  ((uint16_t)0b0000000011000000U)     /* 7:6 Active DBRED Load Mode               */
#define DBCTL_BITS_LOADFEDMODE_Msk  ((uint16_t)0b0000001100000000U)     /* 9:8 Active DBFED Load Mode               */
#define DBCTL_BITS_SHDWDBREDMODE    ((uint16_t)0b0000010000000000U)     /* 10 DBRED Block Operating Mode            */
#define DBCTL_BITS_SHDWDBFEDMODE    ((uint16_t)0b0000100000000000U)     /* 11 DBFED Block Operating Mode            */
#define DBCTL_BITS_OUTSWAP_Msk      ((uint16_t)0b0011000000000000U)     /* 13:12 Dead Band Output Swap Control      */
#define DBCTL_BITS_DEDB_MODE        ((uint16_t)0b0100000000000000U)     /* 14 Dead Band Dual-Edge B Mode Control    */
#define DBCTL_BITS_HALFCYCLE        ((uint16_t)0b1000000000000000U)     /* 15 Half Cycle Clocking Enable            */

#define DBCTL_BITS_OUT_MODE_Pos     ((uint16_t)0U)      /* 1:0 Dead Band Output Mode Control        */
#define DBCTL_BITS_POLSEL_Pos       ((uint16_t)2U)      /* 3:2 Polarity Select Control              */
#define DBCTL_BITS_IN_MODE_Pos      ((uint16_t)4U)      /* 5:4 Dead Band Input Select Mode Control  */
#define DBCTL_BITS_LOADREDMODE_Pos  ((uint16_t)6U)      /* 7:6 Active DBRED Load Mode               */
#define DBCTL_BITS_LOADFEDMODE_Pos  ((uint16_t)8U)      /* 9:8 Active DBFED Load Mode               */
#define DBCTL_BITS_OUTSWAP_Pos      ((uint16_t)12U)     /* 13:12 Dead Band Output Swap Control      */

#define DBRED_BITS_DBRED_Msk        ((uint16_t)0b0011111111111111U)     /* 13:0 Rising edge delay value     */
#define DBRED_BITS_rsvd1_Msk        ((uint16_t)0b1100000000000000U)     /* 15:14 Reserved                   */

#define DBFED_BITS_DBFED_Msk        ((uint16_t)0b0011111111111111U)     /* 13:0 Falling edge delay value    */
#define DBFED_BITS_rsvd1_Msk        ((uint16_t)0b1100000000000000U)     /* 15:14 Reserved                   */

#define TZCTL_BITS_TZA_Msk          ((uint16_t)0b0000000000000011U)     /* 1:0 TZ1 to TZ6 Trip Action On EPWMxA     */
#define TZCTL_BITS_TZB_Msk          ((uint16_t)0b0000000000001100U)     /* 3:2 TZ1 to TZ6 Trip Action On EPWMxB     */
#define TZCTL_BITS_DCAEVT1_Msk      ((uint16_t)0b0000000000110000U)     /* 5:4 EPWMxA action on DCAEVT1             */
#define TZCTL_BITS_DCAEVT2_Msk      ((uint16_t)0b0000000011000000U)     /* 7:6 EPWMxA action on DCAEVT2             */
#define TZCTL_BITS_DCBEVT1_Msk      ((uint16_t)0b0000001100000000U)     /* 9:8 EPWMxB action on DCBEVT1             */
#define TZCTL_BITS_DCBEVT2_Msk      ((uint16_t)0b0000110000000000U)     /* 11:10 EPWMxB action on DCBEVT2           */
#define TZCTL_BITS_rsvd1_Msk        ((uint16_t)0b1111000000000000U)     /* 15:12 Reserved                           */

#define TZCTL_BITS_TZA_Pos          ((uint16_t)0U)      /* 1:0 TZ1 to TZ6 Trip Action On EPWMxA     */
#define TZCTL_BITS_TZB_Pos          ((uint16_t)2U)      /* 3:2 TZ1 to TZ6 Trip Action On EPWMxB     */
#define TZCTL_BITS_DCAEVT1_Pos      ((uint16_t)4U)      /* 5:4 EPWMxA action on DCAEVT1             */
#define TZCTL_BITS_DCAEVT2_Pos      ((uint16_t)6U)      /* 7:6 EPWMxA action on DCAEVT2             */
#define TZCTL_BITS_DCBEVT1_Pos      ((uint16_t)8U)      /* 9:8 EPWMxB action on DCBEVT1             */
#define TZCTL_BITS_DCBEVT2_Pos      ((uint16_t)10U)     /* 11:10 EPWMxB action on DCBEVT2           */

#define ETCLR_BITS_INT          ((uint16_t)0b0000000000000001U)         /* 0 EPWMxINTn Clear    */
#define ETCLR_BITS_rsvd1        ((uint16_t)0b0000000000000010U)         /* 1 Reserved           */
#define ETCLR_BITS_SOCA         ((uint16_t)0b0000000000000100U)         /* 2 EPWMxSOCA Clear    */
#define ETCLR_BITS_SOCB         ((uint16_t)0b0000000000001000U)         /* 3 EPWMxSOCB Clear    */
#define ETCLR_BITS_rsvd2_Msk    ((uint16_t)0b1111111111110000U)         /* 15:4 Reserved        */

#define TZFRC_BITS_rsvd1        ((uint16_t)0b0000000000000001U)         /* 0 Reserved                               */
#define TZFRC_BITS_CBC          ((uint16_t)0b0000000000000010U)         /* 1 Force Trip Zones Cycle By Cycle Event  */
#define TZFRC_BITS_OST          ((uint16_t)0b0000000000000100U)         /* 2 Force Trip Zones One Shot Event        */
#define TZFRC_BITS_DCAEVT1      ((uint16_t)0b0000000000001000U)         /* 3 Force Digital Compare A Event 1        */
#define TZFRC_BITS_DCAEVT2      ((uint16_t)0b0000000000010000U)         /* 4 Force Digital Compare A Event 2        */
#define TZFRC_BITS_DCBEVT1      ((uint16_t)0b0000000000100000U)         /* 5 Force Digital Compare B Event 1        */
#define TZFRC_BITS_DCBEVT2      ((uint16_t)0b0000000001000000U)         /* 6 Force Digital Compare B Event 2        */
#define rsvd2_Msk               ((uint16_t)0b1111111110000000U)         /* 15:7 Reserved                            */


#define TZCLR_BITS_INT          ((uint16_t)0b0000000000000001U)         /* 0 Global Interrupt Clear Flag            */
#define TZCLR_BITS_CBC          ((uint16_t)0b0000000000000010U)         /* 1 Cycle-By-Cycle Flag Clear              */
#define TZCLR_BITS_OST          ((uint16_t)0b0000000000000100U)         /* 2 One-Shot Flag Clear                    */
#define TZCLR_BITS_DCAEVT1      ((uint16_t)0b0000000000001000U)         /* 3 DCAVET1 Flag Clear                     */
#define TZCLR_BITS_DCAEVT2      ((uint16_t)0b0000000000010000U)         /* 4 DCAEVT2 Flag Clear                     */
#define TZCLR_BITS_DCBEVT1      ((uint16_t)0b0000000000100000U)         /* 5 DCBEVT1 Flag Clear                     */
#define TZCLR_BITS_DCBEVT2      ((uint16_t)0b0000000001000000U)         /* 6 DCBEVT2 Flag Clear                     */
#define TZCLR_BITS_rsvd1_Msk    ((uint16_t)0b0011111110000000U)         /* 13:7 Reserved                            */
#define TZCLR_BITS_CBCPULSE_Msk ((uint16_t)0b1100000000000000U)         /* 15:14 Clear Pulse for CBC Trip Latch     */

#define TBCTL_BITS_CTRMODE_VALUE ((uint16_t)0b10)                       /* 1:0 Counter Mode  (up-down)              */
#define AQCTLA_BITS_CAU_VALUE    ((uint16_t)0b01)   
#define AQCTLA_BITS_CAD_VALUE    ((uint16_t)0b10) 

#define DBCTL_BITS_OUT_MODE_VALUE  ((uint16_t)0b11) 
#define DBCTL_BITS_POLSEL_VALUE    ((uint16_t)0b10) 
#define DBCTL_BITS_IN_MODE_VALUE   ((uint16_t)0b00) 

#define TZCTL_BITS_TZA_VALUE     ((uint16_t)0b10)
#define TZCTL_BITS_TZB_VALUE     ((uint16_t)0b10)

#define EPWM_DEADBAND_COUNT         (18U)                              /* Dead time in TBCLK cycles (~150ns) */
#define EPWM_UPDOWN_COUNT_DIVIDER   (2U)

/* Base addresses of peripheral register structures */
#define EPWM1_BASE                0x00004000U
#define EPWM2_BASE                0x00004100U
#define EPWM3_BASE                0x00004200U
#define EPWM4_BASE                0x00004300U
#define EPWM5_BASE                0x00004400U
#define EPWM6_BASE                0x00004500U
#define EPWM7_BASE                0x00004600U
#define EPWM8_BASE                0x00004700U

/* Pointer to base addresses of peripheral register structures */
#define EPWM1            ((EPWM_Typedef *) EPWM1_BASE)
#define EPWM2            ((EPWM_Typedef *) EPWM2_BASE)
#define EPWM3            ((EPWM_Typedef *) EPWM3_BASE)
#define EPWM4            ((EPWM_Typedef *) EPWM4_BASE)
#define EPWM5            ((EPWM_Typedef *) EPWM5_BASE)
#define EPWM6            ((EPWM_Typedef *) EPWM6_BASE)
#define EPWM7            ((EPWM_Typedef *) EPWM7_BASE)
#define EPWM8            ((EPWM_Typedef *) EPWM8_BASE)

#endif/*BSP_PWM_H*/

/****************************************************************************** 
* End of File 
******************************************************************************/
