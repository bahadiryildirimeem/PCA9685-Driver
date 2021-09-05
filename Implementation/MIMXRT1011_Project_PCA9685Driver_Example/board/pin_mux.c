/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: MIMXRT1011xxxxx
package_id: MIMXRT1011CAE4A
mcu_data: ksdk2_0
processor_version: 9.0.1
pin_labels:
- {pin_num: '1', pin_signal: GPIO_11, label: ledCikis, identifier: ledCikis}
- {pin_num: '11', pin_signal: GPIO_02, label: PCA9685_SCL, identifier: PCA9685_SCL}
- {pin_num: '12', pin_signal: GPIO_01, label: PCA9685_SCL, identifier: PCA9685_SCL;PCA9685_SDA}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '1', peripheral: GPIO1, signal: 'gpiomux_io, 11', pin_signal: GPIO_11, direction: OUTPUT}
  - {pin_num: '11', peripheral: LPI2C1, signal: SCL, pin_signal: GPIO_02, slew_rate: Fast, software_input_on: Enable, open_drain: Enable, pull_up_down_config: Pull_Up_22K_Ohm}
  - {pin_num: '12', peripheral: LPI2C1, signal: SDA, pin_signal: GPIO_01, identifier: PCA9685_SDA, slew_rate: Fast, software_input_on: Enable, open_drain: Enable,
    pull_up_down_config: Pull_Up_22K_Ohm}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);           

  /* GPIO configuration of ledCikis on GPIO_11 (pin 1) */
  gpio_pin_config_t ledCikis_config = {
      .direction = kGPIO_DigitalOutput,
      .outputLogic = 0U,
      .interruptMode = kGPIO_NoIntmode
  };
  /* Initialize GPIO functionality on GPIO_11 (pin 1) */
  GPIO_PinInit(GPIO1, 11U, &ledCikis_config);

  IOMUXC_SetPinMux(IOMUXC_GPIO_01_LPI2C1_SDA, 1U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_02_LPI2C1_SCL, 1U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_11_GPIOMUX_IO11, 0U); 
  IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 &
    (~(BOARD_INITPINS_IOMUXC_GPR_GPR26_GPIO_SEL_MASK))) 
      | IOMUXC_GPR_GPR26_GPIO_SEL(0x00U)      
    );
  IOMUXC_SetPinConfig(IOMUXC_GPIO_01_LPI2C1_SDA, 0xD8A1U); 
  IOMUXC_SetPinConfig(IOMUXC_GPIO_02_LPI2C1_SCL, 0xD8A1U); 
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/