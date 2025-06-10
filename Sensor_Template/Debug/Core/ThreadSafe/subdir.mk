################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ThreadSafe/newlib_lock_glue.c 

C_DEPS += \
./Core/ThreadSafe/newlib_lock_glue.d 

OBJS += \
./Core/ThreadSafe/newlib_lock_glue.o 


# Each subdirectory must supply rules for building sources it contributes
Core/ThreadSafe/%.o Core/ThreadSafe/%.su Core/ThreadSafe/%.cyclo: ../Core/ThreadSafe/%.c Core/ThreadSafe/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U575xx -DSTM32_THREAD_SAFE_STRATEGY=2 -DFX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Drivers/CMSIS/Include -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core_A/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/PrivateInclude/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/Include/ -IC:/Users/lucas/STM32Cube/Repository//Packs/ARM/CMSIS/5.9.0/CMSIS/DSP/Include -I../Core/ThreadSafe -I../FileX/App -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Middlewares/ST/filex/common/inc -IC:/Users/lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.4.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Middlewares/ST/filex/common/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/Lucas/STM32Cube/Repository/STM32Cube_FW_U5_V1.6.0/Drivers/CMSIS/Include -IC:/Users/Lucas/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-ALGOBUILD/1.4.0/Middlewares/Third_Party/ARM/DSP/Inc -I"C:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/Firmware" -I"C:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/Firmware/Inc" -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Device/ST/STM32U5xx/Include -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/common/inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Middlewares/ST/filex/ports/generic/inc -IC:/Users/arthu/STM32Cube/Repository/STM32Cube_FW_U5_V1.7.0/Drivers/CMSIS/Include -IC:/Users/arthu/STM32Cube/Repository//Packs/STMicroelectronics/X-CUBE-ALGOBUILD/1.4.0/Middlewares/Third_Party/ARM/DSP/Inc -IC:/Users/arthu/STM32CubeIDE/MELODI_Template/MELODI_Template/FileX/Target -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ThreadSafe

clean-Core-2f-ThreadSafe:
	-$(RM) ./Core/ThreadSafe/newlib_lock_glue.cyclo ./Core/ThreadSafe/newlib_lock_glue.d ./Core/ThreadSafe/newlib_lock_glue.o ./Core/ThreadSafe/newlib_lock_glue.su

.PHONY: clean-Core-2f-ThreadSafe

