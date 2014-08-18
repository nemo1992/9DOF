/*
 * My_I2C.h
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */

#ifndef MY_I2C_H_
#define MY_I2C_H_

#include "My_Init.h"
#include "Gyro.h"
#include "Accelerometer.h"
#include "Magneto.h"

extern void Init_I2C(void);
extern unsigned char I2C_read_byte(unsigned char slave_address, unsigned char reg_address);
extern void I2C_Read_Packet_From_Sensor(int *readData,unsigned char slave_add,int dataLength,unsigned char offset);
extern void I2C_write(unsigned char slave_address,unsigned char reg_address,unsigned char data);
extern void Init_Sensors(void);

#endif /* MY_I2C_H_ */
