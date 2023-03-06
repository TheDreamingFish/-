################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.c \
../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.c \
../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.c \
../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.c 

OBJS += \
./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.o \
./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.o \
./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.o \
./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.o 

C_DEPS += \
./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerDcc.d \
./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGhs.d \
./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerGnuc.d \
./libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/%.o: ../libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/%.c libraries/infineon_libraries/Infra/Platform/Tricore/Compilers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@E:/Aurix Work Place/TC264_Library/Example/E02_uart_demo/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


