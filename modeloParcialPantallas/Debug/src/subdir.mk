################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Contratacion.c \
../src/Pantalla.c \
../src/inputs.c \
../src/modeloParcialPantallas.c 

OBJS += \
./src/Contratacion.o \
./src/Pantalla.o \
./src/inputs.o \
./src/modeloParcialPantallas.o 

C_DEPS += \
./src/Contratacion.d \
./src/Pantalla.d \
./src/inputs.d \
./src/modeloParcialPantallas.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


