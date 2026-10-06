################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
HAL/%.obj: ../HAL/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --fp_mode=relaxed --include_path="D:/NEON/motor_controller/Working code/empty_lab_launchpad_13/empty_lab_launchpad_13" --include_path="C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/include" --include_path="D:/NEON/motor_controller/Working code/empty_lab_launchpad_13/empty_lab_launchpad_13/HAL" --include_path="D:/NEON/motor_controller/Working code/empty_lab_launchpad_13/empty_lab_launchpad_13/BSP" --include_path="D:/NEON/motor_controller/Working code/empty_lab_launchpad_13/empty_lab_launchpad_13/Application" --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="HAL/$(basename $(<F)).d_raw" --include_path="D:/NEON/motor_controller/Working code/empty_lab_launchpad_13/empty_lab_launchpad_13/Executable File/syscfg" --obj_directory="HAL" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


