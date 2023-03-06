################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Std/IfxFce.c 

OBJS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Std/IfxFce.o 

C_DEPS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Std/IfxFce.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Std/%.o: ../libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Std/%.c libraries/infineon_libraries/iLLD/TC26B/Tricore/Fce/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@E:/Aurix Work Place/TC264_Library/Example/E02_uart_demo/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


