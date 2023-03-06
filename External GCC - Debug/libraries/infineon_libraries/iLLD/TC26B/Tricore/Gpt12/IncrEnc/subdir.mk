################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gpt12/IncrEnc/IfxGpt12_IncrEnc.c 

OBJS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gpt12/IncrEnc/IfxGpt12_IncrEnc.o 

C_DEPS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gpt12/IncrEnc/IfxGpt12_IncrEnc.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/iLLD/TC26B/Tricore/Gpt12/IncrEnc/%.o: ../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gpt12/IncrEnc/%.c libraries/infineon_libraries/iLLD/TC26B/Tricore/Gpt12/IncrEnc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@E:/Aurix Work Place/TC264_Library/Example/E02_uart_demo/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


