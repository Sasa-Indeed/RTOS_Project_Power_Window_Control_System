################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
targetConfigs/%.obj: ../targetConfigs/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ASU/4-Senior1/ti/ccs1270/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code" --include_path="D:/ASU/4-Senior1/Fall 23/CSE211 Introduction to Embedded Systems/Tivaware" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/Common" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/MCAL" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/HAL" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/HAL/Motors" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/HAL/Window_Controls" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/MCAL/GPIO" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/MCAL/UART" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/MCAL/GPTM" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/FreeRTOS/Source/include" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project_workspace/Code/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="D:/ASU/4-Senior1/ti/ccs1270/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="targetConfigs/$(basename $(<F)).d_raw" --obj_directory="targetConfigs" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

