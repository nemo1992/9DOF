/*
 * My_Init.h
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */

#ifndef MY_INIT_H_
#define MY_INIT_H_

#define ToRad(x) x*0.01745329252  // *pi/180
#define ToDeg 57.2957795131  // *180/pi
#define M_PI 	 3.141592654

#include "stdbool.h"
#include "stdint.h"
#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "hw_uart.h"
#include "debug.h"
#include "fpu.h"
#include "gpio.h"
#include "interrupt.h"
#include "pin_map.h"
#include "rom.h"
#include "sysctl.h"
#include "i2c.h"
#include "fpu.h"
#include "udma.h"
#include "uart.h"
#include "stdio.h"
#include "math.h"
#include "stdint.h"
#include "timer.h"

extern struct s_sensor_data sen_data ;
extern struct s_sensor_offsets sen_offset ;


struct s_sensor_data
{
  //raw data is uncorrected and corresponds to the
  //true sensor axis, not the redefined platform orientation
  int16_t gyro_x_raw;
  int16_t gyro_y_raw;
  int16_t gyro_z_raw;
  int16_t accel_x_raw;
  int16_t accel_y_raw;
  int16_t accel_z_raw;
  int16_t magnetom_x_raw;
  int16_t magnetom_y_raw;
  int16_t magnetom_z_raw;

  //This data has been corrected based on the calibration values
  float gyro_x;
  float gyro_y;
  float gyro_z;
  float accel_x;
  float accel_y;
  float accel_z;
  float magnetom_x;
  float magnetom_y;
  float magnetom_z;
  float magnetom_heading;
};

struct s_sensor_offsets
{
  float gyro_offset[3];
  float accel_offset[3];
  float magnetom_offset[3];
  float magnetom_XY_Theta;
  float magnetom_XY_Scale;
  float magnetom_YZ_Theta;
  float magnetom_YZ_Scale;
  float out_offset[3];
};

extern long SENSOR_SIGN[9];
extern int rx_temp_buffer[10];



extern  float x_scale,y_scale,z_scale;
extern	int i;
extern  char flag;
extern	float Roll_Acc;
extern	float Pitch_Acc;
extern	char Size_Send_DMA_1;
extern  char Size_Send_DMA_0;
extern	volatile  _Bool Timer_interrupt_flag;
extern	volatile  _Bool Timer_interrupt_flag_2;
extern  volatile  _Bool Timer_interrupt_flag_3;
extern  volatile  _Bool Timer_interrupt_flag_4;
extern  int Uart_Array[12];
extern  float Uart_Temp[11];
extern  char Uart_Send[73];
extern  char Uart_Send_0[4];
extern  float v[3];
extern  float offset[3];
extern  float theta;
extern  float K;
extern  char temp;
extern  char temp2;
extern  char temp3;
extern  char temp4;
extern  float time;
extern  double time_1[3];
extern  char temp5;
extern  char temp6;

extern void My_Init(void);
extern void Init_FPU(void);

#endif /* MY_INIT_H_ */
