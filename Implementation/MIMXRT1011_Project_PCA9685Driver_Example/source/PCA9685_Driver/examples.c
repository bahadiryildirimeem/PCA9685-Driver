/*
 * examples.c
 *
 *  Created on: 30 Ağu 2021
 *      Author: Bahadir
 */

#include "PCA9685.h"
#include "examples.h"

PCA9685Handle examplesAttr = {
		.addr = PCA9685_EXAMPLE_ADDR,
		.pwmVals = {0},
		.pwmFreq = 1000
};

pca9685EffectHandle knightRiderAttr = {
		.ledNo = 15,
		.pwmVal = PCA9685_EXAMPLE_KNIGHT_BRIGHTNESS,
		.transition = 0,
		.direction = 1,
};

pca9685EffectHandle fadingEffectAttr = {
		.ledNo = PCA9685_EXAMPLE_FADING_FIRST_CH,
		.pwmVal = 0,
		.transition = 0,
		.direction = 1
};

void PCA9685KnightRiderInit(void)
{
	PCA9685Init(&examplesAttr, PCA9685_EXAMPLE_ADDR, 1000);
	PCA9685SetChannelsAsBlock(&examplesAttr, 0, 15);
}

void PCA9685KnightRiderRun(void)
{
	if(knightRiderAttr.ledNo == 15 || knightRiderAttr.ledNo == 255)
	{
		knightRiderAttr.direction *= -1;
	}
	PCA9685SetChannel(&examplesAttr, knightRiderAttr.ledNo, 0);
	knightRiderAttr.ledNo += knightRiderAttr.direction;
	PCA9685SetChannel(&examplesAttr, knightRiderAttr.ledNo, knightRiderAttr.pwmVal);
}

void PCA9685BlockWriteInit(void)
{
	PCA9685Init(&examplesAttr, PCA9685_EXAMPLE_ADDR, 1000);
	PCA9685SetChannelsAsBlock(&examplesAttr, 0, 15);
}

void PCA9685BlockWriteRun(void)
{
	uint8_t i = 0;
	for(i = PCA9685_EXAMPLE_BLOCK_WRITE_FIRST_CH; i < PCA9685_EXAMPLE_BLOCK_WRITE_SECOND_CH; i++)
	{
		examplesAttr.pwmVals[i] = PCA9685_EXAMPLE_BLOCK_WRITE_PWM_VAL;
	}
		PCA9685SetChannelsAsBlock(&examplesAttr, PCA9685_EXAMPLE_BLOCK_WRITE_FIRST_CH, PCA9685_EXAMPLE_BLOCK_WRITE_SECOND_CH);
}

void PCA9685FadingEffectInit(void)
{
	PCA9685Init(&examplesAttr, PCA9685_EXAMPLE_ADDR, 1000);
	PCA9685SetChannelsAsBlock(&examplesAttr, 0, 15);
}

void PCA9685FadingEffectRun(void)
{
	fadingEffectAttr.pwmVal += PCA9685_EXAMPLE_FADING_STEP * fadingEffectAttr.direction;
	if(fadingEffectAttr.pwmVal < 0)
	{
		examplesAttr.pwmVals[fadingEffectAttr.ledNo] = 0;
		fadingEffectAttr.ledNo++;
		if(fadingEffectAttr.ledNo > PCA9685_EXAMPLE_FADING_SECOND_CH)
		{
			fadingEffectAttr.ledNo = PCA9685_EXAMPLE_FADING_FIRST_CH;
		}
		fadingEffectAttr.direction = 1;
	}
	else if(fadingEffectAttr.pwmVal > 4095)
	{
		fadingEffectAttr.pwmVal = 4095;
		fadingEffectAttr.direction = -1;
	}
	examplesAttr.pwmVals[fadingEffectAttr.ledNo] = fadingEffectAttr.pwmVal;
	PCA9685SetChannelsAsBlock(&examplesAttr, PCA9685_EXAMPLE_FADING_FIRST_CH, PCA9685_EXAMPLE_FADING_SECOND_CH);
}

examplesFuncHandle examplesInit[NOF_EXAMPLES] = {
		PCA9685KnightRiderInit,
		PCA9685BlockWriteInit,
		PCA9685FadingEffectInit
};

examplesFuncHandle examplesRun[NOF_EXAMPLES] = {
		PCA9685KnightRiderRun,
		PCA9685BlockWriteRun,
		PCA9685FadingEffectRun
};

