################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FileX/Target/fx_stm32_sd_driver_glue.c 

C_DEPS += \
./FileX/Target/fx_stm32_sd_driver_glue.d 

OBJS += \
./FileX/Target/fx_stm32_sd_driver_glue.o 


# Each subdirectory must supply rules for building sources it contributes
FileX/Target/%.o FileX/Target/%.su FileX/Target/%.cyclo: ../FileX/Target/%.c FileX/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -DSTM32_THREAD_SAFE_STRATEGY=2 -DFX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/CMSIS/Include -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core_A/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/PrivateInclude/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/Include -I../Core/ThreadSafe -I../FileX/App -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Middlewares/ST/filex/common/inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Middlewares/ST/filex/common/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/CMSIS/Include -IC:/Users/Lucas/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-ALGOBUILD/1.4.0/Middlewares/Third_Party/ARM/DSP/Inc -I"C:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/Firmware" -I"C:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/Firmware/Inc" -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/common/inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/arthu/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-ALGOBUILD/1.4.0/Middlewares/Third_Party/ARM/DSP/Inc -IC:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/FileX/Target -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FileX-2f-Target

clean-FileX-2f-Target:
	-$(RM) ./FileX/Target/fx_stm32_sd_driver_glue.cyclo ./FileX/Target/fx_stm32_sd_driver_glue.d ./FileX/Target/fx_stm32_sd_driver_glue.o ./FileX/Target/fx_stm32_sd_driver_glue.su

.PHONY: clean-FileX-2f-Target

