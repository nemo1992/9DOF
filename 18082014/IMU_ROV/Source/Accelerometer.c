/*
 * Accelerometer.c
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */


#include "Accelerometer.h"


void Read_Accelerometer(void)
{
  unsigned char status = 0;
  status = I2C_read_byte(ADXL345_ADDR, 0x30);

  if( ((status>>7) & 0x01) == 1 )
  {
    I2C_Read_Packet_From_Sensor(rx_temp_buffer,ADXL345_ADDR,6,0x32);
    /******************************** Read raw data *****************************/

    // X axis
    sen_data.accel_x_raw = ( ((int16_t)rx_temp_buffer[1]) << 8) | rx_temp_buffer[0];
    // Y axis
    sen_data.accel_y_raw = ( ((int16_t)rx_temp_buffer[3]) << 8) | rx_temp_buffer[2];
    // Z axis
    sen_data.accel_z_raw = ( ((int16_t)rx_temp_buffer[5]) << 8) | rx_temp_buffer[4];

    /***************************** Subtract the offset **************************/
    sen_data.accel_x = sen_data.accel_x_raw - sen_offset.accel_offset[0];
    sen_data.accel_y = sen_data.accel_y_raw - sen_offset.accel_offset[1];
    sen_data.accel_z = sen_data.accel_z_raw - sen_offset.accel_offset[2];

    /************************** Change the sign if needed ***********************/
    sen_data.accel_x *= 1* SENSOR_SIGN[3];
    sen_data.accel_y *= -1* SENSOR_SIGN[4];
    sen_data.accel_z *= 1* SENSOR_SIGN[5];

    sen_data.accel_x = sen_data.accel_x/256;
    sen_data.accel_y = sen_data.accel_y/256;
    sen_data.accel_z = sen_data.accel_z/256;

//    sen_data.accel_x = sen_data.accel_x - sen_offset.accel_offset[0];
//    sen_data.accel_y = sen_data.accel_y - sen_offset.accel_offset[1];
//    sen_data.accel_z = sen_data.accel_z - sen_offset.accel_offset[2];
  }
}



void Calculate_Acc(void)
{
  Roll_Acc =   ToDeg*atan2(sen_data.accel_y,sen_data.accel_z);
  Pitch_Acc =  ToDeg*atan2(sen_data.accel_x,sen_data.accel_z);
  Uart_Array[0] = (int) Roll_Acc*10;
  Uart_Array[1] = (int) Pitch_Acc*10;
  Uart_Array[6] = (int) (1000*( sen_data.accel_x ));
  Uart_Array[7] = (int) (1000*( sen_data.accel_y ));
  Uart_Array[8] = (int) (1000*( sen_data.accel_z ));
}
