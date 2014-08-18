################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/include" --include_path="C:/Users/The Riddler/workspace_v6_0/IMU_ROV/Source" --include_path="C:/Users/The Riddler/workspace_v6_0/IMU_ROV/Matlab" --include_path="C:/ti/TivaWare_C_Series-1.0/utils" --include_path="C:/ti/TivaWare_C_Series-1.0" --include_path="C:/ti/TivaWare_C_Series-1.0/driverlib" --include_path="C:/ti/TivaWare_C_Series-1.0/inc" -g --define=ccs="ccs" --define=PART_TM4C1233H6PM --define=TARGET_IS_BLIZZARD_RA1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

tm4c123gh6pm_startup_ccs.obj: ../tm4c123gh6pm_startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/include" --include_path="C:/Users/The Riddler/workspace_v6_0/IMU_ROV/Source" --include_path="C:/Users/The Riddler/workspace_v6_0/IMU_ROV/Matlab" --include_path="C:/ti/TivaWare_C_Series-1.0/utils" --include_path="C:/ti/TivaWare_C_Series-1.0" --include_path="C:/ti/TivaWare_C_Series-1.0/driverlib" --include_path="C:/ti/TivaWare_C_Series-1.0/inc" -g --define=ccs="ccs" --define=PART_TM4C1233H6PM --define=TARGET_IS_BLIZZARD_RA1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="tm4c123gh6pm_startup_ccs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uartstdio.obj: ../uartstdio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/include" --include_path="C:/Users/The Riddler/workspace_v6_0/IMU_ROV/Source" --include_path="C:/Users/The Riddler/workspace_v6_0/IMU_ROV/Matlab" --include_path="C:/ti/TivaWare_C_Series-1.0/utils" --include_path="C:/ti/TivaWare_C_Series-1.0" --include_path="C:/ti/TivaWare_C_Series-1.0/driverlib" --include_path="C:/ti/TivaWare_C_Series-1.0/inc" -g --define=ccs="ccs" --define=PART_TM4C1233H6PM --define=TARGET_IS_BLIZZARD_RA1 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="uartstdio.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


