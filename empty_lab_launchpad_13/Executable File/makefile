################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./f28003x_codestartbranch.obj" \
"./main.obj" \
"./Application/scheduler.obj" \
"./BSP/BSP_ADC.obj" \
"./BSP/BSP_CAN.obj" \
"./BSP/BSP_CLOCK.obj" \
"./BSP/BSP_DMA.obj" \
"./BSP/BSP_FSI.obj" \
"./BSP/BSP_GPIO.obj" \
"./BSP/BSP_INTERRUPT.obj" \
"./BSP/BSP_MCAN.obj" \
"./BSP/BSP_PWM.obj" \
"./BSP/BSP_SPI.obj" \
"./BSP/BSP_TIMER.obj" \
"./BSP/BSP_UART.obj" \
"./BSP/BSP_WATCHDOG.obj" \
"./HAL/HAL_ADC.obj" \
"./HAL/HAL_CAN.obj" \
"./HAL/HAL_CLOCK.obj" \
"./HAL/HAL_FSI.obj" \
"./HAL/HAL_GPIO.obj" \
"./HAL/HAL_INTERRUPT.obj" \
"./HAL/HAL_MCAN.obj" \
"./HAL/HAL_PWM.obj" \
"./HAL/HAL_SPIA_DRV8350.obj" \
"./HAL/HAL_SPIB_ENCODER.obj" \
"./HAL/HAL_TIMER.obj" \
"./HAL/HAL_UART.obj" \
"./HAL/HAL_WATCHDOG.obj" \
"../28003x_f280034_flash_lnk.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Application/subdir_vars.mk
-include BSP/subdir_vars.mk
-include HAL/subdir_vars.mk
-include subdir_rules.mk
-include Application/subdir_rules.mk
-include BSP/subdir_rules.mk
-include HAL/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
empty_lab_launchpad.out 

EXE_OUTPUTS__QUOTED += \
"empty_lab_launchpad.out" 


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "empty_lab_launchpad.out"

# Tool invocations
empty_lab_launchpad.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --fp_mode=relaxed --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"empty_lab_launchpad.map" --heap_size=0x100 --stack_size=0x200 --warn_sections -i"C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/lib" -i"D:/NEON/motor_controller/Working code/empty_lab_launchpad_13/empty_lab_launchpad_13/Executable File/syscfg" -i"C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/include" --reread_libs --define=_FLASH --diag_wrap=off --display_error_number --xml_link_info="empty_lab_launchpad_linkInfo.xml" --entry_point=code_start --rom_model -o "empty_lab_launchpad.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "f28003x_codestartbranch.obj" "main.obj" "Application\scheduler.obj" "BSP\BSP_ADC.obj" "BSP\BSP_CAN.obj" "BSP\BSP_CLOCK.obj" "BSP\BSP_DMA.obj" "BSP\BSP_FSI.obj" "BSP\BSP_GPIO.obj" "BSP\BSP_INTERRUPT.obj" "BSP\BSP_MCAN.obj" "BSP\BSP_PWM.obj" "BSP\BSP_SPI.obj" "BSP\BSP_TIMER.obj" "BSP\BSP_UART.obj" "BSP\BSP_WATCHDOG.obj" "HAL\HAL_ADC.obj" "HAL\HAL_CAN.obj" "HAL\HAL_CLOCK.obj" "HAL\HAL_FSI.obj" "HAL\HAL_GPIO.obj" "HAL\HAL_INTERRUPT.obj" "HAL\HAL_MCAN.obj" "HAL\HAL_PWM.obj" "HAL\HAL_SPIA_DRV8350.obj" "HAL\HAL_SPIB_ENCODER.obj" "HAL\HAL_TIMER.obj" "HAL\HAL_UART.obj" "HAL\HAL_WATCHDOG.obj" 
	-$(RM) "main.d" "Application\scheduler.d" "BSP\BSP_ADC.d" "BSP\BSP_CAN.d" "BSP\BSP_CLOCK.d" "BSP\BSP_DMA.d" "BSP\BSP_FSI.d" "BSP\BSP_GPIO.d" "BSP\BSP_INTERRUPT.d" "BSP\BSP_MCAN.d" "BSP\BSP_PWM.d" "BSP\BSP_SPI.d" "BSP\BSP_TIMER.d" "BSP\BSP_UART.d" "BSP\BSP_WATCHDOG.d" "HAL\HAL_ADC.d" "HAL\HAL_CAN.d" "HAL\HAL_CLOCK.d" "HAL\HAL_FSI.d" "HAL\HAL_GPIO.d" "HAL\HAL_INTERRUPT.d" "HAL\HAL_MCAN.d" "HAL\HAL_PWM.d" "HAL\HAL_SPIA_DRV8350.d" "HAL\HAL_SPIB_ENCODER.d" "HAL\HAL_TIMER.d" "HAL\HAL_UART.d" "HAL\HAL_WATCHDOG.d" 
	-$(RM) "f28003x_codestartbranch.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

