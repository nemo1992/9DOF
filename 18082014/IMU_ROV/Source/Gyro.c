/*
 * Gyro.c
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */


#include "Gyro.h"


void Read_Gyro()
{
  unsigned char status = 0;
  status = I2C_read_byte(ITG3200_ADDR, 0x1A);

  if( (status & 0x01) ==1)
  {
    I2C_Read_Packet_From_Sensor(rx_temp_buffer,ITG3200_ADDR,6,0x1D);

    //get the raw data
    // X axis
    sen_data.gyro_x_raw = (( ((int16_t)rx_temp_buffer[0]) << 8) | rx_temp_buffer[1]);
    // Y axis
    sen_data.gyro_y_raw = (( ((int16_t)rx_temp_buffer[2]) << 8) | rx_temp_buffer[3]);
    // Z axis
    sen_data.gyro_z_raw = (( ((int16_t)rx_temp_buffer[4]) << 8) | rx_temp_buffer[5]);



    //subtract the offset
    sen_data.gyro_x = sen_data.gyro_x_raw - sen_offset.gyro_offset[0];    // X axis
    sen_data.gyro_y = sen_data.gyro_y_raw - sen_offset.gyro_offset[1];    // Y axis
    sen_data.gyro_z = sen_data.gyro_z_raw - sen_offset.gyro_offset[2];    // Z axis

    sen_data.gyro_x =  -(sen_data.gyro_x)/Gyro_Gain_X;
    sen_data.gyro_y =  (sen_data.gyro_y)/Gyro_Gain_X;
    sen_data.gyro_z =  -(sen_data.gyro_z)/Gyro_Gain_X;

    //change the sign if needed

    sen_data.gyro_x = sen_data.gyro_x - sen_offset.gyro_offset[0];
    sen_data.gyro_y = sen_data.gyro_y - sen_offset.gyro_offset[1];
    sen_data.gyro_z = sen_data.gyro_z - sen_offset.gyro_offset[2];
  }
}



void Calculate_Gyro(void)
{
  sen_data.gyro_x = (ToRad( sen_data.gyro_x ));
  sen_data.gyro_y = (ToRad( sen_data.gyro_y ));
  sen_data.gyro_z = (ToRad( sen_data.gyro_z ));

  Uart_Array[3] = (int) (1000*( sen_data.gyro_x ));
  Uart_Array[4] = (int) (1000*( sen_data.gyro_y ));
  Uart_Array[5] = (int) (1000*( sen_data.gyro_z ));

}
