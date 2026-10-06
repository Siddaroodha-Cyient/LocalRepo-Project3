/***********************************************************************************************
* File: HAL_SPIA_DRV8350.h
* Project: 
* Module: Hardware Abstraction Layer (HAL) for SPIA DRV8350 peripherals
*
* Purpose :
* HAL-level interface for SPIA DRV8350 peripherals.
*
* Description:
* This header defines constants, data types, structures, and function prototypes used
* by Hardware Abstraction Layer (HAL) for SPIA DRV8350 peripherals.
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
#ifndef HAL_SPIA_DRV8350_H
#define HAL_SPIA_DRV8350_H

/****************************************************************************** 
* Include Files 
******************************************************************************/
#include "HAL_SPIB_ENCODER.h"

/****************************************************************************** 
* Structure Definitions 
******************************************************************************/
typedef enum{
    drv8350_address_fault_status_1  = 0,
    drv8350_address_vgs_status_2    = 1,
    drv8350_address_driver_control  = 2,
    drv8350_address_gate_drive_hs   = 3,
    drv8350_address_gate_drive_ls   = 4,
    drv8350_address_ocp_control     = 5,
} drv8350_register_address_t;

typedef struct{
    uint16_t vds_lc:1;
    uint16_t vds_hc:1;
    uint16_t vds_lb:1;
    uint16_t vds_hb:1;
    uint16_t vds_la:1;
    uint16_t vds_ha:1;
    uint16_t otsd:1;
    uint16_t uvlo:1;
    uint16_t gdf:1;
    uint16_t vds_ocp:1;
    uint16_t fault:1;
    uint16_t resv:5;
} fault_status_1_t;

typedef struct{
    uint16_t vgs_lc:1;
    uint16_t vgs_hc:1;
    uint16_t vgs_lb:1;
    uint16_t vgs_hb:1;
    uint16_t vgs_la:1;
    uint16_t vgs_ha:1;
    uint16_t gduv:1;
    uint16_t otw:1;
    uint16_t sc_oc:1;
    uint16_t sb_oc:1;
    uint16_t sa_oc:1;
    uint16_t resv:5;
} vgs_status_2_t;

typedef struct{
    uint16_t clr_flt:1;
    uint16_t brake:1;
    uint16_t coast:1;
    uint16_t pwm_dir:1;
    uint16_t pwm_com:1;
    uint16_t pwm_mode:2;
    uint16_t otw_rep:1;
    uint16_t dis_gdf:1;
    uint16_t dis_gduv:1;
    uint16_t ocp_act:1;
    uint16_t resv:5;
} driver_control_t;

typedef struct{
    uint16_t idriven_hs:4;
    uint16_t idrivep_hs:4;
    uint16_t lock:3;
    uint16_t resv:5;
} gate_drive_hs_t;

typedef struct{
    uint16_t idriven_ls:4;
    uint16_t idrivep_ls:4;
    uint16_t tdrive:2;
    uint16_t cbc:1;
    uint16_t resv:5;
} gate_drive_ls_t;

typedef struct{
    uint16_t vds_lvl:4;
    uint16_t ocp_deg:2;
    uint16_t ocp_mode:2;
    uint16_t dead_time:2;
    uint16_t tretry:1;
    uint16_t resv:5;
} ocp_control_t;

typedef struct{
    fault_status_1_t fault_status_1;
    vgs_status_2_t vgs_status_2;
    driver_control_t driver_control;
    gate_drive_hs_t gate_drive_hs;
    gate_drive_ls_t gate_drive_ls;
    ocp_control_t ocp_control;
} drv8350_registers_t;

/****************************************************************************** 
* Public Function Prototypes 
******************************************************************************/
void drv8350_spia_init(void);
void drv8350_spia_cs_enable(void);
void drv8350_spia_cs_disable(void);
uint16_t drv8350_spia_read_register(drv8350_register_address_t address);
void drv8350_spia_write_register(uint16_t data, drv8350_register_address_t address);
void drv8350_spia_read_all(drv8350_registers_t * registers);
void drv8350_spia_write_all(drv8350_registers_t * registers);

/****************************************************************************** 
* Macro Definitions 
******************************************************************************/
#define DRV8350_READ_CMD_BIT      (0x80U)   /* Read command (MSB = 1) */
#define DRV8350_ADDR_MASK         (0xFU)   /* 4-bit register address */
#define DRV8350_ADDR_SHIFT        (3U)      /* Address position */

#define SPI_DATA_MASK             (0xFFU)   /* 8-bit data mask */
#define SPI_HIGH_BYTE_SHIFT       (8U)      /* High byte alignment */

#define DRV8350_WRITE_CMD_BIT     (0x00U)   /* Write command (MSB = 0) */    

#define DRV8350_DATA_HIGH_MASK    (0x0007U) /* Upper 3 bits of data */
#define DRV8350_DATA_LOW_MASK     (0x00FFU) /* Lower 8 bits of data */

#endif/*HAL_SPIA_DRV8350*/
/****************************************************************************** 
* End of File 
******************************************************************************/
