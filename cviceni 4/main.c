/*
 * blindproject.c
 *
 * Created: 27.02.2024 16:47:36
 * Author : msukd
 */ 
#include <stdio.h>
#include <avr/io.h>
#include "UART.h"
#include "ADC.h"
#include "timer.h"

#define Mask_led (0b0010000)

FILE UARTout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);

int main(void)
{
    /* Replace with your application code */
	sei();
	DDRB=Mask_led;
	initUART(25);
	initADC();
	Inittime();
	stdout = &UARTout;
    while (1) 
    {
		interaptDelay(500000);
		printfloat(ADC_normtemp(ADC_read(1)));

		printf("%d \n",ADC_read(1));
		
    }
}

