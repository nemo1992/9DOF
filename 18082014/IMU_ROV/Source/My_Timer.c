/*
 * My_Timer.c
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */


#include "My_Timer.h"

#include "Kalman_Sim.h"

void Timer0IntHandler(void)
{
  //
  // Clear the timer interrupt.
  //
  ROM_IntMasterDisable();
  ROM_TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
  Timer_interrupt_flag = true;
  ROM_TimerLoadSet(TIMER0_BASE, TIMER_A,(long)(ROM_SysCtlClockGet()*time));
  ROM_TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
  ROM_TimerEnable(TIMER0_BASE, TIMER_A);
  ROM_IntMasterEnable();

}

void Timer1IntHandler(void)
{
  //
  // Clear the timer interrupt.
  //
  ROM_IntMasterDisable();
  ROM_TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
  Timer_interrupt_flag_2 = true;
  ROM_TimerLoadSet(TIMER1_BASE, TIMER_A,(long)(time_1[0]));
  // ROM_TimerIntDisable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
  //ROM_TimerDisable(TIMER1_BASE, TIMER_A);
  ROM_IntMasterEnable();

}



void Init_Timer(void)
{
  // Enable the peripherals used by this example.
  //
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);

  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);

  // Configure the two 32-bit periodic timers.
  //
  ROM_TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
  ROM_TimerLoadSet(TIMER0_BASE, TIMER_A, ROM_SysCtlClockGet()*2);

  ROM_TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC);
  ROM_TimerLoadSet(TIMER1_BASE, TIMER_A, (long)(ROM_SysCtlClockGet()*time_1[0]));


  //
  // Setup the interrupts for the timer timeouts.
  //
  ROM_IntEnable(INT_TIMER0A);
  ROM_TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
  //

  ROM_TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);

  //
  // Enable the timers.
  //
  ROM_IntMasterEnable();        // Enable processor interrupts.
  ROM_TimerEnable(TIMER0_BASE, TIMER_A);

}


void Timer_CyRun(void)
{
  if(time == 1)
  {
    if(Timer_interrupt_flag == true)
    {
      temp ++;
      if(temp == 2)
      {
        sen_offset.out_offset[0] = Out1[0];
        sen_offset.out_offset[1] = Out1[1];
        sen_offset.out_offset[2] = Out1[2];

        offset[0] = sen_offset.out_offset[0];
        offset[1] = sen_offset.out_offset[1];
        offset[2] = sen_offset.out_offset[2];

      }
      Timer_interrupt_flag = false;
    }
  }
  else
  {
    while(Timer_interrupt_flag == false){};
    Timer_interrupt_flag = false;



  }
  if(temp == 2)
  {
    ROM_GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,(int)Out2*0xff);
    time = 0.01; //0.05|0.02|0.01
  }
}

void Delay_s(unsigned long time)
{
  unsigned long count = 0;

  for( count = 0; count < time; count++ )
  {
    ROM_SysCtlDelay(ROM_SysCtlClockGet()/3);
  }

}

void Delay_ms(unsigned long time)
{
  unsigned long count = 0;

  for( count = 0; count < time; count++ )
  {
    ROM_SysCtlDelay(ROM_SysCtlClockGet()/(1000*3));
  }

}
