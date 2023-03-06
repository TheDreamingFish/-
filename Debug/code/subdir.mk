################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/AD_Capture.c \
../code/Control.c \
../code/Drv8701e.c \
../code/Else.c \
../code/Encoder.c 

COMPILED_SRCS += \
./code/AD_Capture.src \
./code/Control.src \
./code/Drv8701e.src \
./code/Else.src \
./code/Encoder.src 

C_DEPS += \
./code/AD_Capture.d \
./code/Control.d \
./code/Drv8701e.d \
./code/Else.d \
./code/Encoder.d 

OBJS += \
./code/AD_Capture.o \
./code/Control.o \
./code/Drv8701e.o \
./code/Else.o \
./code/Encoder.o 


# Each subdirectory must supply rules for building sources it contributes
code/%.src: ../code/%.c code/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc26xb "-fE:/Aurix Work Place3/CAR_BUNNY/Debug/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/code\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

code/%.o: ./code/%.src code/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-code

clean-code:
	-$(RM) ./code/AD_Capture.d ./code/AD_Capture.o ./code/AD_Capture.src ./code/Control.d ./code/Control.o ./code/Control.src ./code/Drv8701e.d ./code/Drv8701e.o ./code/Drv8701e.src ./code/Else.d ./code/Else.o ./code/Else.src ./code/Encoder.d ./code/Encoder.o ./code/Encoder.src

.PHONY: clean-code

