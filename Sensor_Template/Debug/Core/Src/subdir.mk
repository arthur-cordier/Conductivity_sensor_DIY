################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc.c \
../Core/Src/dac.c \
../Core/Src/dcache.c \
../Core/Src/gpdma.c \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/icache.c \
../Core/Src/m24m01e.c \
../Core/Src/main.c \
../Core/Src/memorymap.c \
../Core/Src/rtc.c \
../Core/Src/sdmmc.c \
../Core/Src/stm32u5xx_hal_msp.c \
../Core/Src/stm32u5xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32u5xx.c \
../Core/Src/tim.c \
../Core/Src/tmp119.c \
../Core/Src/usart.c 

C_DEPS += \
./Core/Src/adc.d \
./Core/Src/dac.d \
./Core/Src/dcache.d \
./Core/Src/gpdma.d \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/icache.d \
./Core/Src/m24m01e.d \
./Core/Src/main.d \
./Core/Src/memorymap.d \
./Core/Src/rtc.d \
./Core/Src/sdmmc.d \
./Core/Src/stm32u5xx_hal_msp.d \
./Core/Src/stm32u5xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32u5xx.d \
./Core/Src/tim.d \
./Core/Src/tmp119.d \
./Core/Src/usart.d 

OBJS += \
./Core/Src/adc.o \
./Core/Src/dac.o \
./Core/Src/dcache.o \
./Core/Src/gpdma.o \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/icache.o \
./Core/Src/m24m01e.o \
./Core/Src/main.o \
./Core/Src/memorymap.o \
./Core/Src/rtc.o \
./Core/Src/sdmmc.o \
./Core/Src/stm32u5xx_hal_msp.o \
./Core/Src/stm32u5xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32u5xx.o \
./Core/Src/tim.o \
./Core/Src/tmp119.o \
./Core/Src/usart.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -DSTM32_THREAD_SAFE_STRATEGY=2 -DFX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/CMSIS/Include -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core_A/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/PrivateInclude/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/Include -I../Core/ThreadSafe -I../FileX/App -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Middlewares/ST/filex/common/inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Middlewares/ST/filex/common/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/CMSIS/Include -IC:/Users/Lucas/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-ALGOBUILD/1.4.0/Middlewares/Third_Party/ARM/DSP/Inc -I"C:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/Firmware" -I"C:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/Firmware/Inc" -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/common/inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/arthu/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-ALGOBUILD/1.4.0/Middlewares/Third_Party/ARM/DSP/Inc -IC:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/FileX/Target -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/adc.cyclo ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/dac.cyclo ./Core/Src/dac.d ./Core/Src/dac.o ./Core/Src/dac.su ./Core/Src/dcache.cyclo ./Core/Src/dcache.d ./Core/Src/dcache.o ./Core/Src/dcache.su ./Core/Src/gpdma.cyclo ./Core/Src/gpdma.d ./Core/Src/gpdma.o ./Core/Src/gpdma.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.cyclo ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/icache.cyclo ./Core/Src/icache.d ./Core/Src/icache.o ./Core/Src/icache.su ./Core/Src/m24m01e.cyclo ./Core/Src/m24m01e.d ./Core/Src/m24m01e.o ./Core/Src/m24m01e.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/memorymap.cyclo ./Core/Src/memorymap.d ./Core/Src/memorymap.o ./Core/Src/memorymap.su ./Core/Src/rtc.cyclo ./Core/Src/rtc.d ./Core/Src/rtc.o ./Core/Src/rtc.su ./Core/Src/sdmmc.cyclo ./Core/Src/sdmmc.d ./Core/Src/sdmmc.o ./Core/Src/sdmmc.su ./Core/Src/stm32u5xx_hal_msp.cyclo ./Core/Src/stm32u5xx_hal_msp.d ./Core/Src/stm32u5xx_hal_msp.o ./Core/Src/stm32u5xx_hal_msp.su ./Core/Src/stm32u5xx_it.cyclo ./Core/Src/stm32u5xx_it.d ./Core/Src/stm32u5xx_it.o ./Core/Src/stm32u5xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32u5xx.cyclo ./Core/Src/system_stm32u5xx.d ./Core/Src/system_stm32u5xx.o ./Core/Src/system_stm32u5xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/tmp119.cyclo ./Core/Src/tmp119.d ./Core/Src/tmp119.o ./Core/Src/tmp119.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

