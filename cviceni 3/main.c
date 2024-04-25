/*
 * GccApplication1.c
 *
 * Created: 14.02.2024 12:37:25
 * Author : msukd00
 */ 

#include <avr/io.h>
#include <avr/cpufunc.h>
#include "timer.h"

#define Mask_led (0b0010000)

int main(void)
{

	DDRB=Mask_led; //led vystup
    while (1) 
    {
		delay(1000000);
			PORTB|=Mask_led;
		delay(1000000);
			PORTB &=~Mask_led; 
		interaptDelay(1000000);
			PORTB|=Mask_led;
		interaptDelay(1000000);
			PORTB &=~Mask_led;
		busyDelay(1000000);
			PORTB|=Mask_led;
		busyDelay(1000000);
			PORTB &=~Mask_led;
    }
}



