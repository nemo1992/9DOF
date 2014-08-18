/*
 * My_I2C.c
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */


#include "My_I2C.h"


void Init_Accelerometer(void)
{
  I2C_write(ADXL345_ADDR,0x2D,0x08);	//measurement mode
  SysCtlDelay(53333);		// delay 20ms
  I2C_write(ADXL345_ADDR,0x2E,0x80);	//measurement mode
  SysCtlDelay(53333);		// delay 20ms
  I2C_write(ADXL345_ADDR,0x31,0x08);	//data format full resolution
  SysCtlDelay(53333);
}
void Init_Gyro(void)
{
  I2C_write(ITG3200_ADDR,0x3E,0x01);
  SysCtlDelay(53333);
  I2C_write(ITG3200_ADDR,0x15,0x00);
  SysCtlDelay(53333);
  I2C_write(ITG3200_ADDR,0x16,0x1E);
  SysCtlDelay(53333);
  I2C_write(ITG3200_ADDR,0x17,0x01);
  SysCtlDelay(53333);


}

void Init_Compass(void)
{
  I2C_write(HMC58X3_ADDR,0x00,0x78);
  SysCtlDelay(53333);		// delay 20ms
  I2C_write(HMC58X3_ADDR,0x01,0x20);
  SysCtlDelay(53333);
  I2C_write(HMC58X3_ADDR,0x02,0x01);
  SysCtlDelay(53333);

  // calibrate(0); // Use gain 1=default, valid 0-7, 7 not recommended.

  // Single mode conversion was used in calibration, now set continuous mode
  //  I2C_write(HMC58X3_ADDR,HMC58X3_R_MODE,0x00);
  //  SysCtlDelay(53333);

}

void Init_I2C(void)
{
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
  ROM_GPIOPinConfigure(GPIO_PB2_I2C0SCL);
  ROM_GPIOPinConfigure(GPIO_PB3_I2C0SDA);
  ROM_GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);
  GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
  ROM_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
  ROM_GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_3, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_OD);
  ROM_I2CMasterInitExpClk(I2C0_BASE,ROM_SysCtlClockGet(),true);
  SysCtlDelay(500000);
  ROM_I2CMasterEnable(I2C0_BASE);
}

unsigned char I2C_read_byte(unsigned char slave_address, unsigned char reg_address)
{
  unsigned char DATA;
  //DISABLE INTERRUPTS
  //ROM_IntDisable(I2C0_BASE);
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, slave_address, false);
  //BufferIn(reg_address);

  ROM_I2CMasterDataPut(I2C0_BASE, reg_address);
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);

  while(ROM_I2CMasterBusy(I2C0_BASE));
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, slave_address, true);

  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);

  while(ROM_I2CMasterBusy(I2C0_BASE))
  {

  }

  DATA = ROM_I2CMasterDataGet(I2C0_BASE);

  //ENABLE INTERRUPTS

  //ROM_IntEnable(I2C0_BASE);

  return DATA;

}




void I2C_Read_Packet_From_Sensor(int *readData,unsigned char slave_add,int dataLength,unsigned char offset)
{
  unsigned char j;
  //DISABLE INTERRUPTS
  //ROM_IntDisable(I2C0_BASE);
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, slave_add, false);
  //BufferIn(reg_address);
  // SysCtlDelay(53333);
  ROM_I2CMasterDataPut(I2C0_BASE, offset);
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);
  //SysCtlDelay(53333);
  while(ROM_I2CMasterBusy(I2C0_BASE));
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, slave_add, true);
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
  while(ROM_I2CMasterBusy(I2C0_BASE));
  readData[0] = ROM_I2CMasterDataGet(I2C0_BASE);
  if(dataLength>1){
    for(j = 1 ; j < dataLength - 1 ; j++ )
    {
      ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_CONT);
      while(ROM_I2CMasterBusy(I2C0_BASE));
      readData[j] = ROM_I2CMasterDataGet(I2C0_BASE);
    }
    ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
    while(ROM_I2CMasterBusy(I2C0_BASE));
    readData[dataLength-1] = ROM_I2CMasterDataGet(I2C0_BASE);
  }
  //ROM_IntEnable(I2C0_BASE);
  // SysCtlDelay(53333);
}


void I2C_write(unsigned char slave_address,unsigned char reg_address,unsigned char data)
{
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE,slave_address,false);

  ROM_I2CMasterDataPut(I2C0_BASE,reg_address);
  ROM_I2CMasterControl(I2C0_BASE,I2C_MASTER_CMD_BURST_SEND_START);
  while(ROM_I2CMasterBusy(I2C0_BASE));

  //ROM_I2CMasterSlaveAddrSet(I2C0_BASE, slave_address, false);
  ROM_I2CMasterDataPut(I2C0_BASE,data);
  ROM_I2CMasterControl(I2C0_BASE,I2C_MASTER_CMD_BURST_SEND_FINISH);
}


/* Init all IMU sensors  */
void Init_Sensors(void)
{
	Init_Accelerometer();
	Init_Gyro();
	Init_Compass();
}
