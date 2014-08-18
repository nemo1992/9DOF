#include "Gyro.h"
#include "Accelerometer.h"
#include "Magneto.h"
#include "My_Timer.h"
#include "My_UART.h"
#include "My_DMA.h"
#include "My_I2C.h"

#include "Kalman_Sim.h"

int value= 0;

#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
}
#endif

int data[3];

void UARTPutn(uint32_t UART_Base, int Num)
{

			unsigned int temp = 1;
				int NumTemp;
				NumTemp = Num;
				if (Num == 0)
				{
					UARTCharPut(UART_Base, 48);

				}
				else
				{
					if (Num < 0)
					{
						UARTCharPut(UART_Base, '-');

						Num *= -1;
					}
					while (NumTemp)
					{
						NumTemp /= 10;
						temp *= 10;
					}
					temp /= 10;
					while (temp)
					{
						UARTCharPut(UART_Base,(Num / temp) % 10 + 48);

						temp /= 10;
					}
				}
}

void UART0IntHandler(void)
{
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 2);
	value= 255;
	unsigned long ulStatus;
		ulStatus = UARTIntStatus(UART0_BASE, true); //get interrupt status
		UARTIntClear(UART0_BASE, ulStatus); //clear the asserted interrupts
		if((UARTCharsAvail(UART0_BASE))&&(UARTCharGet(UART0_BASE)=='.')) //loop while there are chars
		{
			/*
						float fl = 19.999;
						char array[6];
						int val = (int)fl;
						if(val < 0)
						{
							array[0]= 255;
							val = -val;
						}
						else
						{
							array[0]=0;
							val = val;
						}

						array[1]=val&0x00FF;
						array[2]=(unsigned char)(val/256);
				*/
			/*
						float fl = 19.999;
						char array[9];

						int raw[3];
						raw[0]= data[0];
						raw[1]= data[1];
						raw[2]= data[2];

						int i;
						for(i=0;i<3;i++)
						{
							if(raw[i] < 0)
								{
									array[0+3*i]= 255;
									raw[i] = -raw[i];
								}
							else
								{
								    array[0+3*i]=0;
								    raw[i] = raw[i];
								}
									array[1+3*i]=raw[i]&0x00FF;
									array[2+3*i]=(unsigned char)(raw[i]/256);
						}
						UARTCharPut(UART0_BASE,array[0]);
						UARTCharPut(UART0_BASE,',');
						UARTCharPut(UART0_BASE,array[1]);
						UARTCharPut(UART0_BASE,',');
						UARTCharPut(UART0_BASE,array[2]);
						UARTCharPut(UART0_BASE,',');
						UARTCharPut(UART0_BASE,array[3]);
						UARTCharPut(UART0_BASE,',');
						UARTCharPut(UART0_BASE,array[4]);
						UARTCharPut(UART0_BASE,',');
						UARTCharPut(UART0_BASE,array[5]);
						UARTCharPut(UART0_BASE,',');
						UARTCharPut(UART0_BASE,array[6]);
						UARTCharPut(UART0_BASE,',');
						UARTCharPut(UART0_BASE,array[7]);
						UARTCharPut(UART0_BASE,',');
						UARTCharPut(UART0_BASE,array[8]);
						*/
			int raw[3];
			raw[0]= data[0];
			raw[1]= data[1];
			raw[2]= data[2];


			UARTCharPut(UART0_BASE,'I');
			UARTCharPut(UART0_BASE,',');
			UARTPutn(UART0_BASE,raw[0]);//send data 1
			UARTCharPut(UART0_BASE,',');
			UARTPutn(UART0_BASE,raw[1]);//send data 1
			UARTCharPut(UART0_BASE,',');
			UARTPutn(UART0_BASE,raw[2]);//send data 1
			UARTCharPut(UART0_BASE,',');
			UARTCharPut(UART0_BASE,'U');
}
		value= 0;
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
}

int main(void)
{
  My_Init();
  Init_Timer();
  Init_I2C();
  Init_Sensors();
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    /////////////////////////////////
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
  		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  		GPIOPinConfigure(GPIO_PA0_U0RX);
  		GPIOPinConfigure(GPIO_PA1_U0TX);
  		GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
  		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); //enable GPIO port for LED
  		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2); //enable pin for LED PF2
  		UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,
  				(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
  		IntMasterEnable(); //enable processor interrupts
  		IntEnable(INT_UART0); //enable the UART interrupt
  		UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT); //only enable RX and TX interrupts
/////////////////////////////////
  Kalman_Sim_initialize();

  while(1)
  {
    Read_Accelerometer();
    Calculate_Acc();
    Read_Compass();
    Compass_Heading();
    Calculate_Compass();
    Read_Gyro();
    Calculate_Gyro();

    fgyro[0]    = sen_data.gyro_x;
    fgyro[1]	= sen_data.gyro_y;
    fgyro[2]	= sen_data.gyro_z;

    facc[0]     = sen_data.accel_x;
    facc[1]	= sen_data.accel_y;
    facc[2]	= sen_data.accel_z;

    fmag[0]     = sen_data.magnetom_x;
    fmag[1]	= sen_data.magnetom_y;
    fmag[2]	= sen_data.magnetom_z;


    Kalman_Sim_step();

    data[0]=Out1[0];
    data[1]=Out1[1];
    data[2]=Out1[2];



      Timer_CyRun();

  }
}
