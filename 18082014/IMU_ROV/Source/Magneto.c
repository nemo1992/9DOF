/*
 * Magneto.c
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */


#include "Magneto.h"

void Read_Compass(void)
{
  unsigned char status = 0;
  status = I2C_read_byte(HMC58X3_ADDR, 0x09);

  if( (status & 0x01) ==1)
  {
    I2C_Read_Packet_From_Sensor(rx_temp_buffer,HMC58X3_ADDR,6,0x03);

    // read out the 3 values, 2 bytes each.
    //get the raw data
    // X axis
    sen_data.magnetom_x_raw = (( ((int16_t)rx_temp_buffer[0]) << 8) | rx_temp_buffer[1]);
    // Y axis
    sen_data.magnetom_z_raw = (( ((int16_t)rx_temp_buffer[2]) << 8) | rx_temp_buffer[3]);
    // Z axis
    sen_data.magnetom_y_raw = (( ((int16_t)rx_temp_buffer[4]) << 8) | rx_temp_buffer[5]);

    //Gain = 1090
    sen_data.magnetom_x = -(float)(sen_data.magnetom_x_raw)/1090;
    sen_data.magnetom_y = (float)(sen_data.magnetom_y_raw)/1090;
    sen_data.magnetom_z = -(float)(sen_data.magnetom_z_raw)/1090;

    sen_data.magnetom_x = sen_data.magnetom_x + 0.11;
    sen_data.magnetom_y = sen_data.magnetom_y + 0.035;
    sen_data.magnetom_z = sen_data.magnetom_z - 0.06;

    sen_data.magnetom_x = sen_data.magnetom_x - sen_offset.magnetom_offset[0];
    sen_data.magnetom_y = sen_data.magnetom_y - sen_offset.magnetom_offset[1];
    sen_data.magnetom_z = sen_data.magnetom_z - sen_offset.magnetom_offset[2];


    I2C_write(HMC58X3_ADDR,0x02,0x01);
  }


}






void Compass_Heading(void)
{
  float MAG_X;
  float MAG_Y;
  float cos_roll;
  float sin_roll;
  float cos_pitch;
  float sin_pitch;

  cos_roll = cos(ToRad(Roll_Acc));
  sin_roll = sin(ToRad(Roll_Acc));
  cos_pitch = cos(ToRad(Pitch_Acc));
  sin_pitch = sin(ToRad(Pitch_Acc));

  // Tilt compensated Magnetic field X:
  MAG_X = sen_data.magnetom_x*cos_pitch + sen_data.magnetom_y*sin_roll*sin_pitch + sen_data.magnetom_z*cos_roll*sin_pitch;

  // Tilt compensated Magnetic field Y:
  MAG_Y = sen_data.magnetom_y*cos_roll - sen_data.magnetom_z*sin_roll;

  // Magnetic Heading
  sen_data.magnetom_heading = ToDeg*atan2(-1*MAG_Y,MAG_X);


  //  if(sen_data.magnetom_heading < 0)
  //    sen_data.magnetom_heading += 2 * M_PI;

}



void Calculate_Compass(void)
{
  Uart_Array[2]  = (int) (10*( sen_data.magnetom_heading ));
  Uart_Array[9]  = (int) (1000*( sen_data.magnetom_x ));
  Uart_Array[10] = (int) (1000*( sen_data.magnetom_y ));
  Uart_Array[11] = (int) (1000*( sen_data.magnetom_z ));

}
