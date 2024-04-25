
#include <stdio.h>
#include <avr/io.h>
#include "ADC.h"
#include "timer.h"
#include "LCD.h"
#define Mask_led (0b0010000)

FILE LCDout = FDEV_SETUP_STREAM(LCD_putchar, NULL,_FDEV_SETUP_WRITE);

int main(void)
{
	
	initLCD();
	Inittime();
	initADC();
	sei();
	stdout = &LCDout;
    /* Replace with your application code */
    while (1) 
    {
	LCD_set_cursor(0,0);
	printf("Btn:");
	print_binary(LCD_button());
	LCD_set_cursor(1,0);
	LCD_Button_adc_value(LCD_button());
    }
}

