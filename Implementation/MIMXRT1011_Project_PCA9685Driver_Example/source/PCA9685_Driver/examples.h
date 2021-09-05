/*
 * examples.h
 *
 *  Created on: 30 Ağu 2021
 *      Author: Bahadir
 */

#ifndef PCA9685_DRIVER_EXAMPLES_H_
#define PCA9685_DRIVER_EXAMPLES_H_

#define PCA9685_EXAMPLE_ADDR					0X40U

/* Knight Rider */
#define PCA9685_EXAMPLE_KNIGHT_BRIGHTNESS 		0x0FFFU

/* Block Write */
#define PCA9685_EXAMPLE_BLOCK_WRITE_FIRST_CH	4U
#define PCA9685_EXAMPLE_BLOCK_WRITE_SECOND_CH	9U
#define PCA9685_EXAMPLE_BLOCK_WRITE_PWM_VAL		1500U

/* Fading Effect */
#define PCA9685_EXAMPLE_FADING_FIRST_CH			4U
#define PCA9685_EXAMPLE_FADING_SECOND_CH		10U
#define PCA9685_EXAMPLE_FADING_STEP				100U



enum{
	EXAMPLE_KNIGHT_RIDER = 0,
	EXAMPLE_BLOCK_WRITE,
	EXAMPLE_FADING_EFFECT,
	NOF_EXAMPLES
};

//PCA9685Handle examplesAttr;

typedef struct{
	uint8_t ledNo;
	int8_t direction;
	int16_t pwmVal;
	uint16_t transition;
}pca9685EffectHandle;

typedef void (*examplesFuncHandle)(void);


//pca9685EffectHandle knightRiderAttr;
//pca9685EffectHandle fadingEffectAttr;

extern examplesFuncHandle examplesInit[NOF_EXAMPLES];
extern examplesFuncHandle examplesRun[NOF_EXAMPLES];

#endif /* PCA9685_DRIVER_EXAMPLES_H_ */
