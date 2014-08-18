/*
 * My_Timer.h
 *
 *  Created on: Jul 13, 2014
 *      Author: The Riddler
 */

#ifndef MY_TIMER_H_
#define MY_TIMER_H_

#include "My_Init.h"

extern void Timer0IntHandler(void);
//extern void Timer1IntHandler(void);
extern void Init_Timer(void);
extern void Timer_CyRun(void);
extern void Delay_ms(unsigned long time);
extern void Delay_s(unsigned long time);

#endif /* MY_TIMER_H_ */
