/**
 * @file PCA9685.h
 * @author Bahadir Yildirim
 * @date 5 Sep 2021
 * @brief This module helps you to use PCA9685 easily. It was written
 * as object oriented C approximation programming. So you can manage/create
 * multiple PCA9685s. To creating a device, create PCA9685Handle type struct
 * and call PCA9685Init() function. There's no need extra configuration.\n\n
 * NOTE: All PC9685s' configuration registers are same registers. If
 * you want to configure every PCA9685 individually you need to change handle
 * structure and init function.\n
 * When you found a debug please inform me.\n
 * @see https://github.com/bahadiryildirimeem
 *  You can access implementation videos below links.\n
 *  Knight Rider: \n
 *  @see https://youtu.be/QMra_3z97tY
 *  Fading Effect:\n
 *  @see https://youtu.be/ZSCXXIH56JU
 *
 */



#include "PCA9685.h"

/**
 * @brief Assigning initial values to configuration registers.
 */
PCA9685_MODE1_REG_Handle PCA9685Mode1Reg = {
		.reg = 0};

PCA9685_MODE2_REG_Handle PCA9685Mode2Reg = {
		.reg = 0};

/**
 * @brief Creating PCA9685 device.
 */
PCA9685Handle PCA9685Attr;


/** @brief Writes register values of PCA9685 over I2C interface. Please
 * don't you forget to change I2C interface to your I2C interface.
 *  @param PCA9685 handle structure.
 *  @param Register address of PCA9685
 *  @param Pointer of register value.
 *  @param Register byte size.
 *  @return Void.
 */
void PCA9685I2CWrite(PCA9685Handle *param, uint8_t regAddr, uint8_t *data, uint16_t dataLen)
{
	LPI2C_MasterStart(LPI2C1, param->addr, PCA9685_I2C_WIRTE);
	LPI2C_MasterSend(LPI2C1, &regAddr, 1);
	LPI2C_MasterSend(LPI2C1, data, dataLen);
	LPI2C_MasterStop(LPI2C1);
}

/** @brief Reads register values of PCA9685 over I2C interface. Please
 * don't you forget to change I2C interface to your I2C interface.
 *  @param PCA9685 handle structure.
 *  @param Register address of PCA9685
 *  @param Pointer of buffer that gets value of register .
 *  @param Register byte size.
 *  @return Void.
 */
void PCA9685I2CRead(PCA9685Handle *param, uint8_t regAddr, uint8_t *buff, uint16_t buffLength)
{
	// Asking register value
	LPI2C_MasterStart(LPI2C1, param->addr, PCA9685_I2C_WIRTE);
	LPI2C_MasterSend(LPI2C1, &regAddr, 1);
	LPI2C_MasterStop(LPI2C1);
	// Reading register
	LPI2C_MasterStart(LPI2C1, param->addr, PCA9685_I2C_READ); // adres belirlenir.
	LPI2C_MasterReceive(LPI2C1, buff, buffLength);
	LPI2C_MasterStop(LPI2C1);
}

/** @brief Writes one byte register values to PCA9685.
 *  @param PCA9685 handle structure.
 *  @param Register address of PCA9685
 *  @param Pointer of register value.
 *  @return Void.
 */
void PCA9685Write8BitReg(PCA9685Handle *param, uint8_t regAddr, uint8_t *regVal)
{
	PCA9685I2CWrite(param, regAddr, regVal, 1);
}

/** @brief Writes two bytes register values to PCA9685.
 *  @param PCA9685 handle structure.
 *  @param Register address of PCA9685
 *  @param Pointer of register value.
 *  @return Void.
 */
void PCA9685Write16BitReg(PCA9685Handle *param, uint8_t regAddr, uint8_t *regVal)
{
	PCA9685I2CWrite(param, regAddr, regVal, 2);
}

/** @brief Writes registers' values to PCA9685. This function helps to
 * write registers in same writing sequence so it improves loop time.
 *  @param PCA9685 handle structure.
 *  @param First register address of data block.
 *  @param Pointer of register value.
 *  @param Register byte size.
 *  @return Void.
 */
void PCA9685WriteDataBlock(PCA9685Handle *param, uint8_t regAddr, uint8_t *data, uint16_t length)
{
	PCA9685I2CWrite(param, regAddr, data, length);
}

/** @brief Reads one byte register value.
 *  @param PCA9685 handle structure.
 *  @param Register address of PCA9685
 *  @param Pointer of buffer that gets value of register .
 *  @return Void.
 */
void PCA9685Read8BitReg(PCA9685Handle *param, uint8_t regAddr, uint8_t *buff)
{
	PCA9685I2CRead(param, regAddr, buff, 1);
}

/** @brief Reads two bytes register value.
 *  @param PCA9685 handle structure.
 *  @param Register address of PCA9685
 *  @param Pointer of buffer that gets value of register .
 *  @return Void.
 */
void PCA9685Read16BitReg(PCA9685Handle *param, uint8_t regAddr, uint16_t *buff)
{
	uint8_t temp[2];
	PCA9685I2CRead(param, regAddr, &temp[0], 2);
	*buff = (temp[0] & 0xFF) | (temp[1]<<8 & 0xFF00);
}

/** @brief Reads register values. This function helps to
 * read registers in same reading sequence so it improves loop time.
 *  @param PCA9685 handle structure.
 *  @param Register address of PCA9685
 *  @param Pointer of buffer that gets value of register .
 *  @param Register byte size.
 *  @return Void.
 */
void PCA9685ReadDataBlock(PCA9685Handle *param, uint8_t regAddr, uint8_t *buff, uint8_t length)
{
	PCA9685I2CRead(param, regAddr, buff, length);
}

/** @brief Initialize the PCA9685 device.
 *  @param PCA9685 handle structure.
 *  @param Device address of PCA9685
 *  @param Initial PWM frequence.
 *  @return Void.
 */
void PCA9685Init(PCA9685Handle *param, uint8_t devAddr, uint16_t pwmFreq)
{
	param->addr = devAddr;

	PCA9685Mode1Reg.reg = 0;
	PCA9685Mode1Reg.AI = 1;

	PCA9685Mode2Reg.INVRT = 0;
	PCA9685Mode2Reg.OUTDRV = 1;

	PCA9685Write8BitReg(param, PCA9685_MODE1_REG_ADDR, &PCA9685Mode1Reg.reg);
	PCA9685Write8BitReg(param, PCA9685_MODE2_REG_ADDR, &PCA9685Mode2Reg.reg);

	PCA9685SetFrequency(param, pwmFreq);
}

/** @brief Sets channel's PWM value.
 *  @param PCA9685 handle structure.
 *  @param Channel no.
 *  @param PWM value of channel that passed as chNo.
 *  @return Void.
 */
void PCA9685SetChannel(PCA9685Handle *param, uint8_t chNo, uint16_t val)
{
	if(chNo >= PCA9685_NOF_LEDS)
	{
		return;
	}

	uint8_t temp[4] = {0};
	temp[2] = val;
	temp[3] = val>>8;

	PCA9685WriteDataBlock(param, PCA9685_LED0_ON_L_REG_ADDR + chNo * 4, &temp[0], sizeof(temp));

	param->pwmVals[chNo] = val;
}

/** @brief Sets channels to PWM values at the same data writing sequence.
 * so it improves loop time. You should be assign new PWM values to pwmVals
 * array before the call this function.
 *  @param PCA9685 handle structure.
 *  @param First channel no.
 *  @param Second channel no.
 *  @return Void.
 */
void PCA9685SetChannelsAsBlock(PCA9685Handle *param, uint8_t firstChNo, uint8_t secondChNo)
{
	if(secondChNo < firstChNo)
	{
		return;
	}
	else if(secondChNo >= PCA9685_NOF_LEDS)
	{
		return;
	}
	else
	{
	}

	uint8_t i = 0; //firstChNo;
	uint8_t temp[4 * PCA9685_NOF_LEDS];
	uint8_t chBaseAddr = 0; //i * 4 + PCA9685_LED0_ON_L_REG_ADDR;
	uint16_t j = 0;

	for(i = firstChNo; i <= secondChNo; i++)
	{
		chBaseAddr = i * 4 + PCA9685_LED0_ON_L_REG_ADDR;

		temp[j] = 0;
		temp[j + 1] = 0;
		temp[j + 2] = param->pwmVals[i];
		temp[j + 3] = param->pwmVals[i] >> 8;
		j += 4;
	}
	PCA9685WriteDataBlock(param, firstChNo * 4 + PCA9685_LED0_ON_L_REG_ADDR, &temp[0], j);
}

/** @brief Gets channel value.
 *  @param PCA9685 handle structure.
 *  @param Channel no.
 *  @return Channel value.
 */
uint16_t PCA9685GetChannelVal(PCA9685Handle *param, uint8_t chNo)
{
	if(chNo > PCA9685_NOF_LEDS)
	{
		return 0;
	}

	uint16_t ret = 0;

	PCA9685Read16BitReg(param, chNo * 4 + PCA9685_LED0_OFF_L_REG_ADDR, &ret);

	return ret;
}

/** @brief Sets PWM frequency to PCA9685. The frequency
 * setting interval is between 24Hz and 1526Hz.
 *  @param PCA9685 handle structure.
 *  @param Frequency value.
 *  @return void.
 */
void PCA9685SetFrequency(PCA9685Handle *param, uint16_t freq)
{
	if((freq > 1526) || (freq < 24))
	{
		return;
	}
	float tempFreq = freq;
	float temp = (PCA9685_OSC_FREQ / (4096.0 * tempFreq)) - 1.0;
	float temp2 = temp - ((uint16_t)temp);
	uint16_t regVal;
	if(temp2 > 0.51)
	{
		regVal = temp + 1;
	}
	else
	{
		regVal = temp;
	}

	PCA9685Mode1Reg.SLEEP = 1;
	PCA9685Write8BitReg(param, PCA9685_MODE1_REG_ADDR, &PCA9685Mode1Reg.reg);
	param->pwmFreq = freq;
	PCA9685Write8BitReg(param, PCA9685_PRE_SCALE_REG_ADDR, &regVal);
	PCA9685Mode1Reg.SLEEP = 0;
	PCA9685Write8BitReg(param, PCA9685_MODE1_REG_ADDR, &PCA9685Mode1Reg.reg);
}
