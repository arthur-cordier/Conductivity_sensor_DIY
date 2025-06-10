################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/common/drivers/fx_stm32_sd_driver.c 

C_DEPS += \
./Middlewares/FileX/SD\ interface/fx_stm32_sd_driver.d 

OBJS += \
./Middlewares/FileX/SD\ interface/fx_stm32_sd_driver.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FileX/SD\ interface/fx_stm32_sd_driver.o: C:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/common/drivers/fx_stm32_sd_driver.c Middlewares/FileX/SD\ interface/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -DSTM32_THREAD_SAFE_STRATEGY=2 -DFX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/CMSIS/Include -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core_A/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/PrivateInclude/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/Include -I../Core/ThreadSafe -I../FileX/App -I../FileX/Target -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Middlewares/ST/filex/common/inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Middlewares/ST/filex/common/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/CMSIS/Include -IC:/Users/Lucas/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-ALGOBUILD/1.4.0/Middlewares/Third_Party/ARM/DSP/Inc -I"C:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/Firmware" -I"C:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/Firmware/Inc" -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/common/inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/arthu/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-ALGOBUILD/1.4.0/Middlewares/Third_Party/ARM/DSP/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/FileX/SD interface/fx_stm32_sd_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-FileX-2f-SD-20-interface

clean-Middlewares-2f-FileX-2f-SD-20-interface:
	-$(RM) ./Middlewares/FileX/SD\ interface/fx_stm32_sd_driver.cyclo ./Middlewares/FileX/SD\ interface/fx_stm32_sd_driver.d ./Middlewares/FileX/SD\ interface/fx_stm32_sd_driver.o ./Middlewares/FileX/SD\ interface/fx_stm32_sd_driver.su

.PHONY: clean-Middlewares-2f-FileX-2f-SD-20-interface

