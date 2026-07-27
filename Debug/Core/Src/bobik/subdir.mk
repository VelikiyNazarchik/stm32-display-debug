################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/bobik/bobik.cpp \
../Core/Src/bobik/log.cpp 

OBJS += \
./Core/Src/bobik/bobik.o \
./Core/Src/bobik/log.o 

CPP_DEPS += \
./Core/Src/bobik/bobik.d \
./Core/Src/bobik/log.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/bobik/%.o Core/Src/bobik/%.su Core/Src/bobik/%.cyclo: ../Core/Src/bobik/%.cpp Core/Src/bobik/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H562xx -c -I../Core/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc -I../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-bobik

clean-Core-2f-Src-2f-bobik:
	-$(RM) ./Core/Src/bobik/bobik.cyclo ./Core/Src/bobik/bobik.d ./Core/Src/bobik/bobik.o ./Core/Src/bobik/bobik.su ./Core/Src/bobik/log.cyclo ./Core/Src/bobik/log.d ./Core/Src/bobik/log.o ./Core/Src/bobik/log.su

.PHONY: clean-Core-2f-Src-2f-bobik

