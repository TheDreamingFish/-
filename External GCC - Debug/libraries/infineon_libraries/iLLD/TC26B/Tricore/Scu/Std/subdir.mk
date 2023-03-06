################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/IfxScuCcu.c \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/IfxScuEru.c \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/IfxScuWdt.c 

OBJS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/IfxScuCcu.o \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/IfxScuEru.o \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/IfxScuWdt.o 

C_DEPS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/IfxScuCcu.d \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/IfxScuEru.d \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/IfxScuWdt.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/%.o: ../libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/%.c libraries/infineon_libraries/iLLD/TC26B/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@E:/Aurix Work Place/TC264_Library/Example/E02_uart_demo/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


