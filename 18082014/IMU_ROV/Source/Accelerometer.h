/*
 * Accelerometer.h
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#define ADXL345_ADDR 0x53


#include "My_Init.h"
#include "My_I2C.h"



extern void Read_Accelerometer(void);
extern void Calculate_Acc(void);

#endif /* ACCELEROMETER_H_ */
