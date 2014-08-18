/*
 * Gyro.h
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */

#ifndef GYRO_H_
#define GYRO_H_

// IGT-3200 Sensitivity (from datasheet) => 14.375 LSBs//s
// Tested values :
#define Gyro_Gain_X   14.375 //X axis Gyro gain
#define Gyro_Gain_Y   14.375 //Y axis Gyro gain
#define Gyro_Gain_Z   14.375 //Z axis Gyro gain
#define ITG3200_ADDR 0x68 // 7 bit address of the ITG3200

#include "My_Init.h"
#include "My_I2C.h"


extern void Read_Gyro(void);
extern void Calculate_Gyro(void);

#endif /* GYRO_H_ */
