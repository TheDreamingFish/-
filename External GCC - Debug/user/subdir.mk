################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../user/cpu0_main.c \
../user/cpu1_main.c \
../user/isr.c 

OBJS += \
./user/cpu0_main.o \
./user/cpu1_main.o \
./user/isr.o 

C_DEPS += \
./user/cpu0_main.d \
./user/cpu1_main.d \
./user/isr.d 


# Each subdirectory must supply rules for building sources it contributes
user/%.o: ../user/%.c user/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@E:/Aurix Work Place/TC264_Library/Example/E02_uart_demo/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


