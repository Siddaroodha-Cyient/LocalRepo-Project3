/***********************************************************************************************
* File    : BSP_ADC.h
*
* Module  : Board Support Package (BSP) for ADC peripherals
*
* Purpose :
* Driver-level interface of Board Support Package (BSP) for ADC peripherals
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Board Support Package (BSP) module for ADC peripherals.
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
#ifndef BSP_ADC_H
#define BSP_ADC_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include <stdint.h>

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/

/* Structure used to access ADC peripheral registers */ 
typedef struct {
    uint16_t ADCCTL1;           /* ADC Control 1 Register,                          Address offset: 0x00        */
    uint16_t ADCCTL2;           /* ADC Control 2 Register,                          Address offset: 0x01        */
    uint16_t ADCBURSTCTL;       /* ADC Burst Control Register,                      Address offset: 0x02        */
    uint16_t ADCINTFLG;         /* ADC Interrupt Flag Register,                     Address offset: 0x03        */
    uint16_t ADCINTFLGCLR;      /* ADC Interrupt Flag Clear Register,               Address offset: 0x04        */
    uint16_t ADCINTOVF;         /* ADC Interrupt Overflow Register,                 Address offset: 0x05        */
    uint16_t ADCINTOVFCLR;      /* ADC Interrupt Overflow Clear Register,           Address offset: 0x06        */
    uint16_t ADCINTSEL1N2;      /* ADC Interrupt 1 and 2 Selection Register,        Address offset: 0x07        */
    uint16_t ADCINTSEL3N4;      /* ADC Interrupt 3 and 4 Selection Register,        Address offset: 0x08        */
    uint16_t ADCSOCPRICTL;      /* ADC SOC Priority Control Register,               Address offset: 0x09        */
    uint16_t ADCINTSOCSEL1;     /* ADC Interrupt SOC Selection 1 Register,          Address offset: 0x0A        */
    uint16_t ADCINTSOCSEL2;     /* ADC Interrupt SOC Selection 2 Register,          Address offset: 0x0B        */
    uint16_t ADCSOCFLG1;        /* ADC SOC Flag 1 Register,                         Address offset: 0x0C        */
    uint16_t ADCSOCFRC1;        /* ADC SOC Force 1 Register,                        Address offset: 0x0D        */
    uint16_t ADCSOCOVF1;        /* ADC SOC Overflow 1 Register,                     Address offset: 0x0E        */
    uint16_t ADCSOCOVFCLR1;     /* ADC SOC Overflow Clear 1 Register,               Address offset: 0x0F        */
    uint32_t ADCSOC0CTL;        /* ADC SOC0 Control Register,                       Address offset: 0x10 - 0x11 */
    uint32_t ADCSOC1CTL;        /* ADC SOC1 Control Register,                       Address offset: 0x12 - 0x13 */
    uint32_t ADCSOC2CTL;        /* ADC SOC2 Control Register,                       Address offset: 0x14 - 0x15 */
    uint32_t ADCSOC3CTL;        /* ADC SOC3 Control Register,                       Address offset: 0x16 - 0x17 */
    uint32_t ADCSOC4CTL;        /* ADC SOC4 Control Register,                       Address offset: 0x18 - 0x19 */
    uint32_t ADCSOC5CTL;        /* ADC SOC5 Control Register,                       Address offset: 0x1A - 0x1B */
    uint32_t ADCSOC6CTL;        /* ADC SOC6 Control Register,                       Address offset: 0x1C - 0x1D */
    uint32_t ADCSOC7CTL;        /* ADC SOC7 Control Register,                       Address offset: 0x1E - 0x1F */
    uint32_t ADCSOC8CTL;        /* ADC SOC8 Control Register,                       Address offset: 0x20 - 0x21 */
    uint32_t ADCSOC9CTL;        /* ADC SOC9 Control Register,                       Address offset: 0x22 - 0x23 */
    uint32_t ADCSOC10CTL;       /* ADC SOC10 Control Register,                      Address offset: 0x24 - 0x25 */
    uint32_t ADCSOC11CTL;       /* ADC SOC11 Control Register,                      Address offset: 0x26 - 0x27 */
    uint32_t ADCSOC12CTL;       /* ADC SOC12 Control Register,                      Address offset: 0x28 - 0x29 */
    uint32_t ADCSOC13CTL;       /* ADC SOC13 Control Register,                      Address offset: 0x2A - 0x2B */
    uint32_t ADCSOC14CTL;       /* ADC SOC14 Control Register,                      Address offset: 0x2C - 0x2D */
    uint32_t ADCSOC15CTL;       /* ADC SOC15 Control Register,                      Address offset: 0x2E - 0x2F */
    uint16_t ADCEVTSTAT;        /* ADC Event Status Register,                       Address offset: 0x30        */
    uint16_t ADC_rsvd1;         /* Reserved,                                        Address offset: 0x31        */
    uint16_t ADCEVTCLR;         /* ADC Event Clear Register,                        Address offset: 0x32        */
    uint16_t ADC_rsvd2;         /* Reserved,                                        Address offset: 0x33        */
    uint16_t ADCEVTSEL;         /* ADC Event Selection Register,                    Address offset: 0x34        */
    uint16_t ADC_rsvd3;         /* Reserved,                                        Address offset: 0x35        */
    uint16_t ADCEVTINTSEL;      /* ADC Event Interrupt Selection Register,          Address offset: 0x36        */
    uint16_t ADC_rsvd4;         /* Reserved,                                        Address offset: 0x37        */
    uint16_t ADCOSDETECT;       /* ADC Open and Shorts Detect Register,             Address offset: 0x38        */
    uint16_t ADCCOUNTER;        /* ADC Counter Register,                            Address offset: 0x39        */
    uint16_t ADCREV;            /* ADC Revision Register,                           Address offset: 0x3A        */
    uint16_t ADCOFFTRIM;        /* ADC Offset Trim Register,                        Address offset: 0x3B        */
    uint16_t ADC_rsvd5S[4];     /* Reserved,                                        Address offset: 0x3C - 0x3F */
    uint16_t ADCPPB1CONFIG;     /* ADC PPB1 Config Register,                        Address offset: 0x40        */
    uint16_t ADCPPB1STAMP;      /* ADC PPB1 Sample Delay Time Stamp Register,       Address offset: 0x41        */
    uint16_t ADCPPB1OFFCAL;     /* ADC PPB1 Offset Calibration Register,            Address offset: 0x42        */
    uint16_t ADCPPB1OFFREF;     /* ADC PPB1 Offset Reference Register,              Address offset: 0x43        */
    uint32_t ADCPPB1TRIPHI;     /* ADC PPB1 Trip High Register,                     Address offset: 0x44 - 0x45 */
    uint32_t ADCPPB1TRIPLO;     /* ADC PPB1 Trip Low/Trigger Time Stamp Register,   Address offset: 0x46 - 0x47 */
    uint16_t ADCPPB2CONFIG;     /* ADC PPB2 Config Register,                        Address offset: 0x48        */
    uint16_t ADCPPB2STAMP;      /* ADC PPB2 Sample Delay Time Stamp Register,       Address offset: 0x49        */
    uint16_t ADCPPB2OFFCAL;     /* ADC PPB2 Offset Calibration Register,            Address offset: 0x4A        */
    uint16_t ADCPPB2OFFREF;     /* ADC PPB2 Offset Reference Register,              Address offset: 0x4B        */
    uint32_t ADCPPB2TRIPHI;     /* ADC PPB2 Trip High Register,                     Address offset: 0x4C - 0x4D */
    uint32_t ADCPPB2TRIPLO;     /* ADC PPB2 Trip Low/Trigger Time Stamp Register,   Address offset: 0x4E - 0x4F */
    uint16_t ADCPPB3CONFIG;     /* ADC PPB3 Config Register,                        Address offset: 0x50        */
    uint16_t ADCPPB3STAMP;      /* ADC PPB3 Sample Delay Time Stamp Register,       Address offset: 0x51        */
    uint16_t ADCPPB3OFFCAL;     /* ADC PPB3 Offset Calibration Register,            Address offset: 0x52        */
    uint16_t ADCPPB3OFFREF;     /* ADC PPB3 Offset Reference Register,              Address offset: 0x53        */
    uint32_t ADCPPB3TRIPHI;     /* ADC PPB3 Trip High Register,                     Address offset: 0x54 - 0x55 */
    uint32_t ADCPPB3TRIPLO;     /* ADC PPB3 Trip Low/Trigger Time Stamp Register,   Address offset: 0x56 - 0x57 */
    uint16_t ADCPPB4CONFIG;     /* ADC PPB4 Config Register,                        Address offset: 0x58        */
    uint16_t ADCPPB4STAMP;      /* ADC PPB4 Sample Delay Time Stamp Register,       Address offset: 0x59        */
    uint16_t ADCPPB4OFFCAL;     /* ADC PPB4 Offset Calibration Register,            Address offset: 0x5A        */
    uint16_t ADCPPB4OFFREF;     /* ADC PPB4 Offset Reference Register,              Address offset: 0x5B        */
    uint32_t ADCPPB4TRIPHI;     /* ADC PPB4 Trip High Register,                     Address offset: 0x5C - 0x5D */
    uint32_t ADCPPB4TRIPLO;     /* ADC PPB4 Trip Low/Trigger Time Stamp Register,   Address offset: 0x5E - 0x5F */
    uint16_t ADC_rsvd6S[15];    /* Reserved,                                        Address offset: 0x60 - 0x6E */
    uint16_t ADCINTCYCLE;       /* ADC Early Interrupt Generation Cycle             Address offset: 0x6F        */
    uint16_t ADC_rsvd7S[2];     /* Reserved,                                        Address offset: 0x70 - 0x71 */
    uint32_t ADCINLTRIM2;       /* ADC Linearity Trim 2 Register,                   Address offset: 0x72 - 0x73 */
    uint32_t ADCINLTRIM3;       /* ADC Linearity Trim 3 Register,                   Address offset: 0x74 - 0x75 */
    uint16_t ADC_rsvd8S[6];     /* Reserved,                                        Address offset: 0x76 - 0x7B */
} ADC_Typedef;

/* Structure used to access ADC result registers */ 
typedef struct {
    uint16_t ADCRESULT0;                   /* ADC Result 0 Register                             */
    uint16_t ADCRESULT1;                   /* ADC Result 1 Register                             */
    uint16_t ADCRESULT2;                   /* ADC Result 2 Register                             */
    uint16_t ADCRESULT3;                   /* ADC Result 3 Register                             */
    uint16_t ADCRESULT4;                   /* ADC Result 4 Register                             */
    uint16_t ADCRESULT5;                   /* ADC Result 5 Register                             */
    uint16_t ADCRESULT6;                   /* ADC Result 6 Register                             */
    uint16_t ADCRESULT7;                   /* ADC Result 7 Register                             */
    uint16_t ADCRESULT8;                   /* ADC Result 8 Register                             */
    uint16_t ADCRESULT9;                   /* ADC Result 9 Register                             */
    uint16_t ADCRESULT10;                  /* ADC Result 10 Register                            */
    uint16_t ADCRESULT11;                  /* ADC Result 11 Register                            */
    uint16_t ADCRESULT12;                  /* ADC Result 12 Register                            */
    uint16_t ADCRESULT13;                  /* ADC Result 13 Register                            */
    uint16_t ADCRESULT14;                  /* ADC Result 14 Register                            */
    uint16_t ADCRESULT15;                  /* ADC Result 15 Register                            */
    uint32_t ADCPPB1RESULT;                /* ADC Post Processing Block 1 Result Register       */
    uint32_t ADCPPB2RESULT;                /* ADC Post Processing Block 2 Result Register       */
    uint32_t ADCPPB3RESULT;                /* ADC Post Processing Block 3 Result Register       */
    uint32_t ADCPPB4RESULT;                /* ADC Post Processing Block 4 Result Register       */
} ADC_RESULT_Typedef;

/* Structure used to access Analog subsystem peripheral registers */ 
typedef struct {
    uint16_t resv1[74];
    uint32_t INTERNALTESTCTL;    /*4Ah - INTERNALTEST Node Control Register */
    uint16_t resv2[18];
    uint32_t CONFIGLOCK;         /*5Eh - Lock Register for all the config registers. */
    uint16_t TSNSCTL;            /*60h - Temperature Sensor Control Register         */
    uint16_t resv3[7];
    uint16_t ANAREFCTL;          /*68h - Analog Reference Control Register */
    uint16_t resv4[7];
    uint16_t VMONCTL;            /*70h - Voltage Monitor Control Register  */
    uint16_t resv5[17];
    uint32_t CMPHPMXSEL;         /*82h - Bits to select one of the many sources on CompHP inputs */
    uint32_t CMPLPMXSEL;         /*84h - Bits to select one of the many sources on CompLP inputs */
    uint16_t CMPHNMXSEL;         /*86h - Bits to select one of the many sources on CompHN inputs */
    uint16_t CMPLNMXSEL;         /*87h - Bits to select one of the many sources on CompLN inputs */
    uint32_t ADCDACLOOPBACK;     /*88h - Enabble loopback from DAC to ADCs*/
    uint16_t resv6[4];
    uint32_t LOCK;               /*8Eh - Lock Register */
    uint16_t resv7[114];
    uint32_t AGPIOCTRLA;         /*102h - AGPIO Control Register */
} ANALOG_SUBSYS_Typedef;

/* Structure used to store states of an ADC channel*/ 
typedef struct{
    ADC_Typedef * ADC;
    uint16_t channel_number;
    uint16_t soc_number;
    uint16_t raw_adc_value;
    uint16_t trigger;
    uint16_t result;
    float scale;
    float offset;
} adc_channel_struct_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void adc_config(adc_channel_struct_t * str);
uint16_t get_adc_result(adc_channel_struct_t * str);
void adc_power_up(void);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define ADCSOCCTL_TRIGSEL_ADCTRIG3  0x03
#define INVALID_ADC_VAL 5000

#define ADCCTL1_BITS_rsvd1_Msk          ((uint16_t)0b0000000000000011)          /* 1:0 Reserved                     */
#define ADCCTL1_BITS_INTPULSEPOS        ((uint16_t)0b0000000000000100)          /* 2 ADC Interrupt Pulse Position   */
#define ADCCTL1_BITS_rsvd2_Msk          ((uint16_t)0b0000000001111000)          /* 6:3 Reserved                     */
#define ADCCTL1_BITS_ADCPWDNZ           ((uint16_t)0b0000000010000000)          /* 7 ADC Power Down                 */
#define ADCCTL1_BITS_ADCBSYCHN_Msk      ((uint16_t)0b0000111100000000)          /* 11:8 ADC Busy Channel            */
#define ADCCTL1_BITS_rsvd3              ((uint16_t)0b0001000000000000)          /* 12 Reserved                      */
#define ADCCTL1_BITS_ADCBSY             ((uint16_t)0b0010000000000000)          /* 13 ADC Busy                      */
#define ADCCTL1_BITS_rsvd4_Msk          ((uint16_t)0b1100000000000000)          /* 15:14 Reserved                   */

#define ADCCTL1_BITS_ADCBSYCHN_Pos      ((uint16_t)8)          /* 11:8 ADC Busy Channel            */

#define ADCCTL2_BITS_PRESCALE_Msk       ((uint16_t)0b0000000000001111)          /* 3:0 ADC Clock Prescaler      */
#define ADCCTL2_BITS_rsvd1_Msk          ((uint16_t)0b0000000000110000)          /* 5:4 Reserved                 */
#define ADCCTL2_BITS_RESOLUTION         ((uint16_t)0b0000000001000000)          /* 6 SOC Conversion Resolution  */
#define ADCCTL2_BITS_SIGNALMODE         ((uint16_t)0b0000000010000000)          /* 7 SOC Signaling Mode         */
#define ADCCTL2_BITS_rsvd2_Msk          ((uint16_t)0b0001111100000000)          /* 12:8 Reserved                */
#define ADCCTL2_BITS_rsvd3_Msk          ((uint16_t)0b1110000000000000)          /* 15:13 Reserved               */

#define ADCCTL2_BITS_PRESCALE_Pos       ((uint16_t)0)                           /* 3:0 ADC Clock Prescaler      */

#define ADCCTL2_PRESCALE_VALUE          ((uint16_t)2)                                    /* ADC clock prescaler          */

#define ADCSOCCTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC0 Acquisition Prescale     */
#define ADCSOCCTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOCCTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC0 Channel Select         */
#define ADCSOCCTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOCCTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC0 Trigger Source Select  */
#define ADCSOCCTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOCCTL_BITS_ACQPS_Pos          ((uint32_t)0)          /* 8:0 SOC0 Acquisition Prescale     */
#define ADCSOCCTL_BITS_CHSEL_Pos          ((uint32_t)15)         /* 18:15 SOC0 Channel Select         */
#define ADCSOCCTL_BITS_TRIGSEL_Pos        ((uint32_t)20)         /* 24:20 SOC0 Trigger Source Select  */

#define ADCSOC0CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC0 Acquisition Prescale     */
#define ADCSOC0CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC0CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC0 Channel Select         */
#define ADCSOC0CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC0CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC0 Trigger Source Select  */
#define ADCSOC0CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC0CTL_BITS_ACQPS_Pos          ((uint32_t)0)          /* 8:0 SOC0 Acquisition Prescale     */
#define ADCSOC0CTL_BITS_CHSEL_Pos          ((uint32_t)15)         /* 18:15 SOC0 Channel Select         */
#define ADCSOC0CTL_BITS_TRIGSEL_Pos        ((uint32_t)20)         /* 24:20 SOC0 Trigger Source Select  */

#define ADCSOC1CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC1 Acquisition Prescale     */
#define ADCSOC1CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC1CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC1 Channel Select         */
#define ADCSOC1CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC1CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC1 Trigger Source Select  */
#define ADCSOC1CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC1CTL_BITS_ACQPS_Pos          ((uint32_t)0)          /* 8:0 SOC1 Acquisition Prescale     */
#define ADCSOC1CTL_BITS_CHSEL_Pos          ((uint32_t)15)         /* 18:15 SOC1 Channel Select         */
#define ADCSOC1CTL_BITS_TRIGSEL_Pos        ((uint32_t)20)         /* 24:20 SOC1 Trigger Source Select  */

#define ADCSOC2CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC2 Acquisition Prescale     */
#define ADCSOC2CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC2CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC2 Channel Select         */
#define ADCSOC2CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC2CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC2 Trigger Source Select  */
#define ADCSOC2CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC2CTL_BITS_ACQPS_Pos          ((uint32_t)0)          /* 8:0 SOC2 Acquisition Prescale     */
#define ADCSOC2CTL_BITS_CHSEL_Pos          ((uint32_t)15)         /* 18:15 SOC2 Channel Select         */
#define ADCSOC2CTL_BITS_TRIGSEL_Pos        ((uint32_t)20)         /* 24:20 SOC2 Trigger Source Select  */

#define ADCSOC3CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC3 Acquisition Prescale     */
#define ADCSOC3CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC3CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC3 Channel Select         */
#define ADCSOC3CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC3CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC3 Trigger Source Select  */
#define ADCSOC3CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC3CTL_BITS_ACQPS_Pos          ((uint32_t)0)          /* 8:0 SOC3 Acquisition Prescale     */
#define ADCSOC3CTL_BITS_CHSEL_Pos          ((uint32_t)15)         /* 18:15 SOC3 Channel Select         */
#define ADCSOC3CTL_BITS_TRIGSEL_Pos        ((uint32_t)20)         /* 24:20 SOC3 Trigger Source Select  */

#define ADCSOC4CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC4 Acquisition Prescale     */
#define ADCSOC4CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC4CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC4 Channel Select         */
#define ADCSOC4CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC4CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC4 Trigger Source Select  */
#define ADCSOC4CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC4CTL_BITS_ACQPS_Pos          ((uint32_t)0)          /* 8:0 SOC4 Acquisition Prescale     */
#define ADCSOC4CTL_BITS_CHSEL_Pos          ((uint32_t)15)         /* 18:15 SOC4 Channel Select         */
#define ADCSOC4CTL_BITS_TRIGSEL_Pos        ((uint32_t)20)         /* 24:20 SOC4 Trigger Source Select  */

#define ADCSOC5CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC5 Acquisition Prescale     */
#define ADCSOC5CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC5CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC5 Channel Select         */
#define ADCSOC5CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC5CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC5 Trigger Source Select  */
#define ADCSOC5CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC6CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC6 Acquisition Prescale     */
#define ADCSOC6CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC6CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC6 Channel Select         */
#define ADCSOC6CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC6CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC6 Trigger Source Select  */
#define ADCSOC6CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC7CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC7 Acquisition Prescale     */
#define ADCSOC7CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC7CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC7 Channel Select         */
#define ADCSOC7CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC7CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC7 Trigger Source Select  */
#define ADCSOC7CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC8CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC8 Acquisition Prescale     */
#define ADCSOC8CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC8CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC8 Channel Select         */
#define ADCSOC8CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC8CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC8 Trigger Source Select  */
#define ADCSOC8CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC9CTL_BITS_ACQPS_Msk          ((uint32_t)0x000001FF)          /* 8:0 SOC9 Acquisition Prescale     */
#define ADCSOC9CTL_BITS_rsvd1_Msk          ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC9CTL_BITS_CHSEL_Msk          ((uint32_t)0x00078000)          /* 18:15 SOC9 Channel Select         */
#define ADCSOC9CTL_BITS_rsvd2              ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC9CTL_BITS_TRIGSEL_Msk        ((uint32_t)0x01F00000)          /* 24:20 SOC9 Trigger Source Select  */
#define ADCSOC9CTL_BITS_rsvd3_Msk          ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC10CTL_BITS_ACQPS_Msk         ((uint32_t)0x000001FF)          /* 8:0 SOC10 Acquisition Prescale    */
#define ADCSOC10CTL_BITS_rsvd1_Msk         ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC10CTL_BITS_CHSEL_Msk         ((uint32_t)0x00078000)          /* 18:15 SOC10 Channel Select        */
#define ADCSOC10CTL_BITS_rsvd2             ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC10CTL_BITS_TRIGSEL_Msk       ((uint32_t)0x01F00000)          /* 24:20 SOC10 Trigger Source Select */
#define ADCSOC10CTL_BITS_rsvd3_Msk         ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC10CTL_BITS_ACQPS_Pos          ((uint32_t)0)          /* 8:0 SOC10 Acquisition Prescale     */
#define ADCSOC10CTL_BITS_CHSEL_Pos          ((uint32_t)15)         /* 18:15 SOC10 Channel Select         */
#define ADCSOC10CTL_BITS_TRIGSEL_Pos        ((uint32_t)20)         /* 24:20 SOC10 Trigger Source Select  */

#define ADCSOC11CTL_BITS_ACQPS_Msk         ((uint32_t)0x000001FF)          /* 8:0 SOC11 Acquisition Prescale    */
#define ADCSOC11CTL_BITS_rsvd1_Msk         ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC11CTL_BITS_CHSEL_Msk         ((uint32_t)0x00078000)          /* 18:15 SOC11 Channel Select        */
#define ADCSOC11CTL_BITS_rsvd2             ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC11CTL_BITS_TRIGSEL_Msk       ((uint32_t)0x01F00000)          /* 24:20 SOC11 Trigger Source Select */
#define ADCSOC11CTL_BITS_rsvd3_Msk         ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC11CTL_BITS_ACQPS_Pos          ((uint32_t)0)          /* 8:0 SOC11 Acquisition Prescale     */
#define ADCSOC11CTL_BITS_CHSEL_Pos          ((uint32_t)15)         /* 18:15 SOC11 Channel Select         */
#define ADCSOC11CTL_BITS_TRIGSEL_Pos        ((uint32_t)20)         /* 24:20 SOC11 Trigger Source Select  */

#define ADCSOC12CTL_BITS_ACQPS_Msk         ((uint32_t)0x000001FF)          /* 8:0 SOC12 Acquisition Prescale    */
#define ADCSOC12CTL_BITS_rsvd1_Msk         ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC12CTL_BITS_CHSEL_Msk         ((uint32_t)0x00078000)          /* 18:15 SOC12 Channel Select        */
#define ADCSOC12CTL_BITS_rsvd2             ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC12CTL_BITS_TRIGSEL_Msk       ((uint32_t)0x01F00000)          /* 24:20 SOC12 Trigger Source Select */
#define ADCSOC12CTL_BITS_rsvd3_Msk         ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC12CTL_BITS_ACQPS_Pos          ((uint32_t)0)          /* 8:0 SOC12 Acquisition Prescale     */
#define ADCSOC12CTL_BITS_CHSEL_Pos          ((uint32_t)15)         /* 18:15 SOC12 Channel Select         */
#define ADCSOC12CTL_BITS_TRIGSEL_Pos        ((uint32_t)20)         /* 24:20 SOC12 Trigger Source Select  */

#define ADCSOC13CTL_BITS_ACQPS_Msk         ((uint32_t)0x000001FF)          /* 8:0 SOC13 Acquisition Prescale    */
#define ADCSOC13CTL_BITS_rsvd1_Msk         ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC13CTL_BITS_CHSEL_Msk         ((uint32_t)0x00078000)          /* 18:15 SOC13 Channel Select        */
#define ADCSOC13CTL_BITS_rsvd2             ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC13CTL_BITS_TRIGSEL_Msk       ((uint32_t)0x01F00000)          /* 24:20 SOC13 Trigger Source Select */
#define ADCSOC13CTL_BITS_rsvd3_Msk         ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC14CTL_BITS_ACQPS_Msk         ((uint32_t)0x000001FF)          /* 8:0 SOC14 Acquisition Prescale    */
#define ADCSOC14CTL_BITS_rsvd1_Msk         ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC14CTL_BITS_CHSEL_Msk         ((uint32_t)0x00078000)          /* 18:15 SOC14 Channel Select        */
#define ADCSOC14CTL_BITS_rsvd2             ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC14CTL_BITS_TRIGSEL_Msk       ((uint32_t)0x01F00000)          /* 24:20 SOC14 Trigger Source Select */
#define ADCSOC14CTL_BITS_rsvd3_Msk         ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCSOC15CTL_BITS_ACQPS_Msk         ((uint32_t)0x000001FF)          /* 8:0 SOC15 Acquisition Prescale    */
#define ADCSOC15CTL_BITS_rsvd1_Msk         ((uint32_t)0x00007E00)          /* 14:9 Reserved                     */
#define ADCSOC15CTL_BITS_CHSEL_Msk         ((uint32_t)0x00078000)          /* 18:15 SOC15 Channel Select        */
#define ADCSOC15CTL_BITS_rsvd2             ((uint32_t)0x00080000)          /* 19 Reserved                       */
#define ADCSOC15CTL_BITS_TRIGSEL_Msk       ((uint32_t)0x01F00000)          /* 24:20 SOC15 Trigger Source Select */
#define ADCSOC15CTL_BITS_rsvd3_Msk         ((uint32_t)0xFE000000)          /* 31:25 Reserved                    */

#define ADCINTSEL1N2_BITS_INT1SEL_Msk      ((uint16_t)0b0000000000001111)  /* 3:0 ADCINT1 EOC Source Select         */
#define ADCINTSEL1N2_BITS_rsvd1            ((uint16_t)0b0000000000010000)  /* 4 Reserved                            */
#define ADCINTSEL1N2_BITS_INT1E            ((uint16_t)0b0000000000100000)  /* 5 ADCINT1 Interrupt Enable            */
#define ADCINTSEL1N2_BITS_INT1CONT         ((uint16_t)0b0000000001000000)  /* 6 ADCINT1 Continue to Interrupt Mode  */
#define ADCINTSEL1N2_BITS_rsvd2            ((uint16_t)0b0000000010000000)  /* 7 Reserved                            */
#define ADCINTSEL1N2_BITS_INT2SEL_Msk      ((uint16_t)0b0000111100000000)  /* 11:8 ADCINT2 EOC Source Select        */
#define ADCINTSEL1N2_BITS_rsvd3            ((uint16_t)0b0001000000000000)  /* 12 Reserved                           */
#define ADCINTSEL1N2_BITS_INT2E            ((uint16_t)0b0010000000000000)  /* 13 ADCINT2 Interrupt Enable           */
#define ADCINTSEL1N2_BITS_INT2CONT         ((uint16_t)0b0100000000000000)  /* 14 ADCINT2 Continue to Interrupt Mode */
#define ADCINTSEL1N2_BITS_rsvd4            ((uint16_t)0b1000000000000000)  /* 15 Reserved                           */

#define ADCINTSEL1N2_BITS_INT1SEL_Pos      ((uint16_t)0)        /* 3:0 ADCINT1 EOC Source Select           */
#define ADCINTSEL1N2_BITS_INT2SEL_Pos      ((uint16_t)8)        /* 11:8 ADCINT2 EOC Source Select          */

#define ADCINTFLGCLR_BITS_ADCINT1          ((uint16_t)0b0000000000000001)        /* 0 ADC Interrupt 1 Flag Clear    */
#define ADCINTFLGCLR_BITS_ADCINT2          ((uint16_t)0b0000000000000010)        /* 1 ADC Interrupt 2 Flag Clear    */
#define ADCINTFLGCLR_BITS_ADCINT3          ((uint16_t)0b0000000000000100)        /* 2 ADC Interrupt 3 Flag Clear    */
#define ADCINTFLGCLR_BITS_ADCINT4          ((uint16_t)0b0000000000001000)        /* 3 ADC Interrupt 4 Flag Clear    */
#define ADCINTFLGCLR_BITS_rsvd1_Msk        ((uint16_t)0b1111111111110000)        /* 15:4 Reserved                   */

#define ADC_STARTUP_DELAY_COUNT            (100000U)     /* Delay loop count */

#define ADC_OFFSET_TRIM_ADDR_A             (0x7016CU)    /* ADCA trim address */      
#define ADC_OFFSET_TRIM_ADDR_B             (0x7016DU)    /* ADCB trim address */
#define ADC_OFFSET_TRIM_ADDR_C             (0x7016EU)    /* ADCC trim address */

#define ADC_OFFSET_TRIM_Msk                (0x00FFU)
#define ONE_BYTE_BIT_SIZE                (8U)    


#define ANALOG_REF_INTERNAL_3V3            (0U)          /* Internal reference = 3.3V */
#define TEMP_SENSOR_ENABLE                 (1U)          /* Enable temperature sensor */

/* Base addresses of peripheral register structures */
#define ADCARESULT_BASE           0x00000B00U
#define ADCBRESULT_BASE           0x00000B20U
#define ADCCRESULT_BASE           0x00000B40U
#define ADCA_BASE                 0x00007400U
#define ADCB_BASE                 0x00007480U
#define ADCC_BASE                 0x00007500U

#define ANALOGSUBSYS_BASE         0x0005D700U

/* Pointer to base addresses of peripheral register structures */
#define ADCA                    ((ADC_Typedef *) ADCA_BASE)
#define ADCB                    ((ADC_Typedef *) ADCB_BASE)
#define ADCC                    ((ADC_Typedef *) ADCC_BASE)
#define ADCARESULT              ((ADC_RESULT_Typedef *) ADCARESULT_BASE)
#define ADCBRESULT              ((ADC_RESULT_Typedef *) ADCBRESULT_BASE)
#define ADCCRESULT              ((ADC_RESULT_Typedef *) ADCCRESULT_BASE)
#define ANALOGSUBSYS            ((ANALOG_SUBSYS_Typedef *) ANALOGSUBSYS_BASE)

#endif/*BSP_ADC_H*/

/****************************************************************************** 
* End of File 
******************************************************************************/
