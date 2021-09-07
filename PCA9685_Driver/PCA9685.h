/**
 * @file PCA9685.h
 * @author Bahadir Yildirim
 * @date 5 Sep 2021
 */
#ifndef PCA9685_DRIVER_PCA9685_H_
#define PCA9685_DRIVER_PCA9685_H_

#include <stdint.h>
/**
 * Included libraries at the below is belong to
 * implementation that runs in eval board. You can
 * delete this and add your own implementation libraries.
 */
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MIMXRT1011.h"

/* HW Values												*/
#define PCA9685_OSC_FREQ							25000000.0

/* Dev Address												*/
#define PCA9685_ADDR_0								0x40U


/* MODE1 Reg Masks											*/
#define PCA9685_MODE1_REG_ALLCALL_MASK				0x01U
#define PCA9685_MODE1_REG_SUB3_MASK					0x02U
#define PCA9685_MODE1_REG_SUB2_MASK					0x04U
#define PCA9685_MODE1_REG_SUB1_MASK					0x08U
#define PCA9685_MODE1_REG_SLEEP_MASK				0x10U
#define PCA9685_MODE1_REG_AI_MASK					0x20U
#define PCA9685_MODE1_REG_EXTCLK_MASK				0x40U
#define PCA9685_MODE1_REG_RESTART_MASK				0x80U

/* MODE2 Reg Masks											*/
#define PCA9685_MODE2_REG_OUTNE_B0_MASK				0x01U
#define PCA9685_MODE2_REG_OUTNE_B1_MASK				0x02U
#define PCA9685_MODE2_REG_OUTDRV_MASK				0x04U
#define PCA9685_MODE2_REG_OCH_MASK					0x08U
#define PCA9685_MODE2_REG_INVRT_MASK				0x10U

/* Reg Addrs 												*/
#define PCA9685_MODE1_REG_ADDR						0x00U
#define PCA9685_MODE2_REG_ADDR						0x01U
#define PAC9685_ALLCALLADDR_REG_ADDR				0x05U
#define PCA9685_PRE_SCALE_REG_ADDR					0xFEU

#define PCA9685_ALL_LED_ON_L_REG_ADDR				0xFAU
#define PCA9685_ALL_LED_ON_H_REG_ADDR				0xFBU
#define PCA9685_ALL_LED_OFF_L_REG_ADDR				0xFCU
#define PCA9685_ALL_LED_OFF_H_REG_ADDR				0xFDU


#define PCA9685_LED0_ON_L_REG_ADDR					0x06U
#define PCA9685_LED0_ON_H_REG_ADDR					0x07U
#define PCA9685_LED0_OFF_L_REG_ADDR					0x08U
#define PCA9685_LED0_OFF_H_REG_ADDR					0x09U

#define PCA9685_LED1_ON_L_REG_ADDR					0x0AU
#define PCA9685_LED1_ON_H_REG_ADDR					0x0BU
#define PCA9685_LED1_OFF_L_REG_ADDR					0x0CU
#define PCA9685_LED1_OFF_H_REG_ADDR					0x0DU

#define PCA9685_LED2_ON_L_REG_ADDR					0x0EU
#define PCA9685_LED2_ON_H_REG_ADDR					0x0FU
#define PCA9685_LED2_OFF_L_REG_ADDR					0x10U
#define PCA9685_LED2_OFF_H_REG_ADDR					0x11U

#define PCA9685_LED3_ON_L_REG_ADDR					0x12U
#define PCA9685_LED3_ON_H_REG_ADDR					0x13U
#define PCA9685_LED3_OFF_L_REG_ADDR					0x14U
#define PCA9685_LED3_OFF_H_REG_ADDR					0x15U

#define PCA9685_LED4_ON_L_REG_ADDR					0x16U
#define PCA9685_LED4_ON_H_REG_ADDR					0x17U
#define PCA9685_LED4_OFF_L_REG_ADDR					0x18U
#define PCA9685_LED4_OFF_H_REG_ADDR					0x19U

#define PCA9685_LED5_ON_L_REG_ADDR					0x1AU
#define PCA9685_LED5_ON_H_REG_ADDR					0x1BU
#define PCA9685_LED5_OFF_L_REG_ADDR					0x1CU
#define PCA9685_LED5_OFF_H_REG_ADDR					0x1DU

#define PCA9685_LED6_ON_L_REG_ADDR					0x1EU
#define PCA9685_LED6_ON_H_REG_ADDR					0x1FU
#define PCA9685_LED6_OFF_L_REG_ADDR					0x20U
#define PCA9685_LED6_OFF_H_REG_ADDR					0x21U

#define PCA9685_LED7_ON_L_REG_ADDR					0x22U
#define PCA9685_LED7_ON_H_REG_ADDR					0x23U
#define PCA9685_LED7_OFF_L_REG_ADDR					0x24U
#define PCA9685_LED7_OFF_H_REG_ADDR					0x25U

#define PCA9685_LED8_ON_L_REG_ADDR					0x26U
#define PCA9685_LED8_ON_H_REG_ADDR					0x27U
#define PCA9685_LED8_OFF_L_REG_ADDR					0x28U
#define PCA9685_LED8_OFF_H_REG_ADDR					0x29U

#define PCA9685_LED9_ON_L_REG_ADDR					0x2AU
#define PCA9685_LED9_ON_H_REG_ADDR					0x2BU
#define PCA9685_LED9_OFF_L_REG_ADDR					0x2CU
#define PCA9685_LED9_OFF_H_REG_ADDR					0x2DU

#define PCA9685_LED10_ON_L_REG_ADDR					0x2EU
#define PCA9685_LED10_ON_H_REG_ADDR					0x2FU
#define PCA9685_LED10_OFF_L_REG_ADDR				0x30U
#define PCA9685_LED10_OFF_H_REG_ADDR				0x31U

#define PCA9685_LED11_ON_L_REG_ADDR					0x32U
#define PCA9685_LED11_ON_H_REG_ADDR					0x33U
#define PCA9685_LED11_OFF_L_REG_ADDR				0x34U
#define PCA9685_LED11_OFF_H_REG_ADDR				0x35U

#define PCA9685_LED12_ON_L_REG_ADDR					0x36U
#define PCA9685_LED12_ON_H_REG_ADDR					0x37U
#define PCA9685_LED12_OFF_L_REG_ADDR				0x38U
#define PCA9685_LED12_OFF_H_REG_ADDR				0x39U

#define PCA9685_LED13_ON_L_REG_ADDR					0x3AU
#define PCA9685_LED13_ON_H_REG_ADDR					0x3BU
#define PCA9685_LED13_OFF_L_REG_ADDR				0x3CU
#define PCA9685_LED13_OFF_H_REG_ADDR				0x3DU

#define PCA9685_LED14_ON_L_REG_ADDR					0x3EU
#define PCA9685_LED14_ON_H_REG_ADDR					0x3FU
#define PCA9685_LED14_OFF_L_REG_ADDR				0x40U
#define PCA9685_LED14_OFF_H_REG_ADDR				0x41U

#define PCA9685_LED15_ON_L_REG_ADDR					0x42U
#define PCA9685_LED15_ON_H_REG_ADDR					0x43U
#define PCA9685_LED15_OFF_L_REG_ADDR				0x44U
#define PCA9685_LED15_OFF_H_REG_ADDR				0x45U

#define PCA9685_MAX_PRE_SCALE_VAL					0x03U
#define PCA9685_MIN_PRE_SCALE_VAL					0x03U

enum{
	PCA9685_LED_OUT_0 = 0,
	PCA9685_LED_OUT_1,
	PCA9685_LED_OUT_2,
	PCA9685_LED_OUT_3,
	PCA9685_LED_OUT_4,
	PCA9685_LED_OUT_5,
	PCA9685_LED_OUT_6,
	PCA9685_LED_OUT_7,
	PCA9685_LED_OUT_8,
	PCA9685_LED_OUT_9,
	PCA9685_LED_OUT_10,
	PCA9685_LED_OUT_11,
	PCA9685_LED_OUT_12,
	PCA9685_LED_OUT_13,
	PCA9685_LED_OUT_14,
	PCA9685_LED_OUT_15,
	PCA9685_NOF_LEDS
};

enum{
	PCA9685_I2C_WIRTE = 0,
	PCA9685_I2C_READ
};

typedef union{
	uint8_t reg;
	struct{
		uint8_t ALLCALL:1;
		uint8_t SUB3:1;
		uint8_t SUB2:1;
		uint8_t SUB1:1;
		uint8_t SLEEP:1;
		uint8_t AI:1;
		uint8_t EXTCLK:1;
		uint8_t RESTART:1;
	};
}PCA9685_MODE1_REG_Handle;

typedef union{
	uint8_t reg;
	struct{
		uint8_t OUTNE:2;
		uint8_t OUTDRV:1;
		uint8_t OCH:1;
		uint8_t INVRT:1;
		uint8_t RVSD:3;
	};
}PCA9685_MODE2_REG_Handle;

typedef struct{
	uint8_t addr;
	uint16_t pwmVals[PCA9685_NOF_LEDS];
	uint16_t pwmFreq;
}PCA9685Handle;

extern PCA9685_MODE1_REG_Handle PCA9685Mode1Reg;
extern PCA9685_MODE2_REG_Handle PCA9685Mode2Reg;

extern PCA9685Handle PCA9685Attr;

extern void PCA9685Init(PCA9685Handle *param, uint8_t devAddr, uint16_t pwmFreq);
extern void PCA9685SetFrequency(PCA9685Handle *param, uint16_t freq);
extern void PCA9685SetChannel(PCA9685Handle *param, uint8_t chNo, uint16_t val);
extern void PCA9685SetChannelsAsBlock(PCA9685Handle *param, uint8_t firstChNo, uint8_t secondChNo);
extern uint16_t PCA9685GetChannelVal(PCA9685Handle *param, uint8_t chNo);


#endif /* PCA9685_DRIVER_PCA9685_H_ */
