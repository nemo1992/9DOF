################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./Matlab/rt_nonfinite.obj" \
"./Matlab/rt_atan232_snf.obj" \
"./Matlab/rtGetNaN.obj" \
"./Matlab/rtGetInf.obj" \
"./Matlab/Kalman_Sim_data.obj" \
"./Matlab/Kalman_Sim.obj" \
"./Source/My_Timer.obj" \
"./Source/My_Init.obj" \
"./Source/My_I2C.obj" \
"./Source/Magneto.obj" \
"./Source/Gyro.obj" \
"./Source/Accelerometer.obj" \
"./uartstdio.obj" \
"./tm4c123gh6pm_startup_ccs.obj" \
"./main.obj" \
"../tm4c123gh6pm.cmd" \
-l"libc.a" \
-l"C:\ti\TivaWare_C_Series-1.0\driverlib\ccs\Debug\driverlib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Source/subdir_vars.mk
-include Matlab/subdir_vars.mk
-include subdir_rules.mk
-include Source/subdir_rules.mk
-include Matlab/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
IMU_ROV.out \

EXE_OUTPUTS__QUOTED += \
"IMU_ROV.out" \

BIN_OUTPUTS += \
IMU_ROV.hex \

BIN_OUTPUTS__QUOTED += \
"IMU_ROV.hex" \


# All Target
all: IMU_ROV.out

# Tool invocations
IMU_ROV.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -g --define=ccs="ccs" --define=PART_TM4C1233H6PM --define=TARGET_IS_BLIZZARD_RA1 --display_error_number --diag_warning=225 --diag_wrap=off -z -m"IMU_ROV.map" --heap_size=0 --stack_size=512 -i"E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/lib" -i"E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="IMU_ROV_linkInfo.xml" --rom_model -o "IMU_ROV.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

IMU_ROV.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"E:/Install/ti/ccsv6/tools/compiler/arm_5.1.5/bin/armhex"  -o "IMU_ROV.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "main.pp" "tm4c123gh6pm_startup_ccs.pp" "uartstdio.pp" "Source\Accelerometer.pp" "Source\Gyro.pp" "Source\Magneto.pp" "Source\My_I2C.pp" "Source\My_Init.pp" "Source\My_Timer.pp" "Matlab\Kalman_Sim.pp" "Matlab\Kalman_Sim_data.pp" "Matlab\rtGetInf.pp" "Matlab\rtGetNaN.pp" "Matlab\rt_atan232_snf.pp" "Matlab\rt_nonfinite.pp" 
	-$(RM) "main.obj" "tm4c123gh6pm_startup_ccs.obj" "uartstdio.obj" "Source\Accelerometer.obj" "Source\Gyro.obj" "Source\Magneto.obj" "Source\My_I2C.obj" "Source\My_Init.obj" "Source\My_Timer.obj" "Matlab\Kalman_Sim.obj" "Matlab\Kalman_Sim_data.obj" "Matlab\rtGetInf.obj" "Matlab\rtGetNaN.obj" "Matlab\rt_atan232_snf.obj" "Matlab\rt_nonfinite.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

