################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.c \
../libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.c \
../libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.c \
../libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.c 

OBJS += \
./libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.o \
./libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.o \
./libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.o \
./libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.o 

C_DEPS += \
./libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.d \
./libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_Pos.d \
./libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.d \
./libraries/infineon_libraries/Service/CpuGeneric/StdIf/IfxStdIf_Timer.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/Service/CpuGeneric/StdIf/%.o: ../libraries/infineon_libraries/Service/CpuGeneric/StdIf/%.c libraries/infineon_libraries/Service/CpuGeneric/StdIf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@E:/Aurix Work Place/TC264_Library/Example/E02_uart_demo/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


