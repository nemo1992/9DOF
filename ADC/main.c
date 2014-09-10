#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/adc.h"
#include "driverlib/interrupt.h"

uint32_t ADCResult;
uint32_t ADC;
int32_t IRResult;

bool ADCFlag;

void ConfigSystem(void)
{
	// Configure System Clock at 20MHz, using PLL
	SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
}

void ADCIsr(void)
{
	ADCIntClear(ADC0_BASE, 3);	//Clear Interrupt Flag
	ADCSequenceDataGet(ADC0_BASE, 3, &ADCResult);	//Get ADC result
	ADCFlag = true;
}

void ConfigADC(void)
{
	//Configure pin for ADC
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);	//Enable Peripheral Port
	GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);	//ADC pin: PE3

	//Configure ADC module
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);		//Enable Module ADC0
	//Configure the hardware oversampling for the ADC - 4 conversions at once
	ADCHardwareOversampleConfigure(ADC0_BASE, 64);
	//Processor ADC trigger
	ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_END | ADC_CTL_CH0 | ADC_CTL_IE);
	ADCSequenceEnable(ADC0_BASE, 3);		//Enable ADC
	ADCIntRegister(ADC0_BASE, 3, &ADCIsr);	//Set interrupt handler
	ADCIntEnable(ADC0_BASE, 3);		//Enable ADC Interrupt
}





void main(void)
{
	ConfigSystem();
	ConfigADC();


	IntMasterEnable();	//Enable Global Interrupt

	while(1)
	{
		SysCtlDelay(SysCtlClockGet() / 1000);		//Delay 3ms
		ADCProcessorTrigger(ADC0_BASE, 3);			//Start conversion
		while(!ADCFlag);		//Wait until complete conversion
		ADC = ADCResult;
	}
}

