################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/%.obj: ../MCAL/UART/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"D:/ASU/4-Senior1/ti/ccs1270/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/HAL/Motors" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/HAL/Window_Controls" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/Common" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/MCAL" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/MCAL/GPIO" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/HAL" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/MCAL/UART" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/MCAL/GPTM" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/FreeRTOS/Source/include" --include_path="D:/ASU/4-Senior1/Spring 24/CSE411 Real Time Embedded Systems/Project/Project/Power_Window_Controls/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="D:/ASU/4-Senior1/ti/ccs1270/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="MCAL/UART/$(basename $(<F)).d_raw" --obj_directory="MCAL/UART" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


