################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_gpio.c \
../drivers/fsl_lpi2c.c 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_gpio.o \
./drivers/fsl_lpi2c.o 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_gpio.d \
./drivers/fsl_lpi2c.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MIMXRT1011CAE4A -DCPU_MIMXRT1011CAE4A_cm7 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\Bahadir\Documents\MCUXpressoIDE_11.3.0_5222\workSpace2\MIMXRT1011_Project_PCA9685Driver_Example\drivers" -I"C:\Users\Bahadir\Documents\MCUXpressoIDE_11.3.0_5222\workSpace2\MIMXRT1011_Project_PCA9685Driver_Example\CMSIS" -I"C:\Users\Bahadir\Documents\MCUXpressoIDE_11.3.0_5222\workSpace2\MIMXRT1011_Project_PCA9685Driver_Example\device" -I"C:\Users\Bahadir\Documents\MCUXpressoIDE_11.3.0_5222\workSpace2\MIMXRT1011_Project_PCA9685Driver_Example\drivers" -I"C:\Users\Bahadir\Documents\MCUXpressoIDE_11.3.0_5222\workSpace2\MIMXRT1011_Project_PCA9685Driver_Example\CMSIS" -I"C:\Users\Bahadir\Documents\MCUXpressoIDE_11.3.0_5222\workSpace2\MIMXRT1011_Project_PCA9685Driver_Example\device" -I"C:\Users\Bahadir\Documents\MCUXpressoIDE_11.3.0_5222\workSpace2\MIMXRT1011_Project_PCA9685Driver_Example\board" -I"C:\Users\Bahadir\Documents\MCUXpressoIDE_11.3.0_5222\workSpace2\MIMXRT1011_Project_PCA9685Driver_Example\source" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


