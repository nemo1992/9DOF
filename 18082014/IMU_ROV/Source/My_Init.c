/*
 * My_Init.c
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */

#include "My_Init.h"

float x_scale,y_scale,z_scale = 0;
char flag = 's';
int i = 0;
float Roll_Acc = 0;
float Pitch_Acc = 0;
char Size_Send_DMA_1 = 73;
char Size_Send_DMA_0 = 4;
volatile  _Bool Timer_interrupt_flag = false;
volatile  _Bool Timer_interrupt_flag_2 = false;
volatile  _Bool Timer_interrupt_flag_3 = false;
volatile  _Bool Timer_interrupt_flag_4 = false;
int Uart_Array[12];

float Uart_Temp[11] = {0,0,0,0,0,0,0,0,0,0,0};
char Uart_Send[73];
char Uart_Send_0[4] = {0,0,0,0};
float v[3] = {0,0,0};
float offset[3];
float theta = 0;
float K = 0;
long SENSOR_SIGN[9] = { 1,1,1,1,1,1,1,1,1};
int rx_temp_buffer[10];
char temp = 0;
char temp2 = 0;
char temp3 = 1;
char temp4 = 0;
char temp5 = 0;
char temp6 = 0;
float time = 1;
double time_1[3];

struct s_sensor_data sen_data = {0,0,0, // Gyro Raw x,y,z
		0,0,0, // Accelerometer Raw x,y,z
		0,0,0, // Magnetometer Raw x,y,z

		// Corrected based on calibration values
		0,0,0, // Gyro x,y,z
		0,0,0, // Accelerometer x,y,z
		0,0,0, // Magnetometer x,y,z
		0}; // Magnetometer heading

struct s_sensor_offsets sen_offset = {{0,0,0},//{-71,19,-8}, // Gyro offset
		{0,0,0}, // Accelerometer offset
		{0,0,0}, // Magnetometer offset
		0, // Magnetometer XY Theta
		0, // Magnetometer XY Scale
		0, // Magnetometer YZ Theta
		0,
		{0,0,0},
};// Magnetometer YZ Scale




void Init_FPU(void)
{
	ROM_FPULazyStackingEnable();
	ROM_FPUEnable();
	ROM_FPUStackingEnable();
}

void Init_MCU(void)
{
	// Set the clocking to run directly from the crystal.
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
			SYSCTL_XTAL_16MHZ);


}



void My_Init(void)
{
	Init_MCU();
	Init_FPU();
}
