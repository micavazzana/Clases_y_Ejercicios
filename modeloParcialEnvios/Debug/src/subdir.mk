################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Envio.c \
../src/Inputs.c \
../src/LinkedList.c \
../src/Validations.c \
../src/modeloParcialEnvios.c 

OBJS += \
./src/Controller.o \
./src/Envio.o \
./src/Inputs.o \
./src/LinkedList.o \
./src/Validations.o \
./src/modeloParcialEnvios.o 

C_DEPS += \
./src/Controller.d \
./src/Envio.d \
./src/Inputs.d \
./src/LinkedList.d \
./src/Validations.d \
./src/modeloParcialEnvios.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


