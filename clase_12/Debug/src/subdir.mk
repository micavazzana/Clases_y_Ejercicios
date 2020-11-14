################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Alumno.c \
../src/clase_12.c \
../src/inputs.c \
../src/nac.c 

OBJS += \
./src/Alumno.o \
./src/clase_12.o \
./src/inputs.o \
./src/nac.o 

C_DEPS += \
./src/Alumno.d \
./src/clase_12.d \
./src/inputs.d \
./src/nac.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


