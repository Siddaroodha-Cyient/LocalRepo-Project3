################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Application/Measurement/%.obj: ../Application/Measurement/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --fp_mode=relaxed --include_path="C:/Users/ss88764/OneDrive - Cyient Ltd/Code_formalization/Code_Folder_Structure/empty_lab_launchpad 9_20260423/empty_lab_launchpad_9_New" --include_path="C:/ti/ccs2040/ccs/tools/compiler/ti-cgt-c2000_22.6.3.LTS/include" --include_path="C:/Users/ss88764/OneDrive - Cyient Ltd/Code_formalization/Code_Folder_Structure/empty_lab_launchpad 9_20260423/empty_lab_launchpad_9_New/HAL" --include_path="C:/Users/ss88764/OneDrive - Cyient Ltd/Code_formalization/Code_Folder_Structure/empty_lab_launchpad 9_20260423/empty_lab_launchpad_9_New/BSP" --include_path="C:/Users/ss88764/OneDrive - Cyient Ltd/Code_formalization/Code_Folder_Structure/empty_lab_launchpad 9_20260423/empty_lab_launchpad_9_New/Application" --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="Application/Measurement/$(basename $(<F)).d_raw" --include_path="C:/Users/ss88764/OneDrive - Cyient Ltd/Code_formalization/Code_Folder_Structure/empty_lab_launchpad 9_20260423/empty_lab_launchpad_9_New/Executable File/syscfg" --obj_directory="Application/Measurement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


