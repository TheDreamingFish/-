################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/zf_common/zf_common_clock.c \
../libraries/zf_common/zf_common_debug.c \
../libraries/zf_common/zf_common_fifo.c \
../libraries/zf_common/zf_common_font.c \
../libraries/zf_common/zf_common_function.c \
../libraries/zf_common/zf_common_interrupt.c 

OBJS += \
./libraries/zf_common/zf_common_clock.o \
./libraries/zf_common/zf_common_debug.o \
./libraries/zf_common/zf_common_fifo.o \
./libraries/zf_common/zf_common_font.o \
./libraries/zf_common/zf_common_function.o \
./libraries/zf_common/zf_common_interrupt.o 

C_DEPS += \
./libraries/zf_common/zf_common_clock.d \
./libraries/zf_common/zf_common_debug.d \
./libraries/zf_common/zf_common_fifo.d \
./libraries/zf_common/zf_common_font.d \
./libraries/zf_common/zf_common_function.d \
./libraries/zf_common/zf_common_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/zf_common/%.o: ../libraries/zf_common/%.c libraries/zf_common/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@E:/Aurix Work Place/TC264_Library/Example/E02_uart_demo/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


