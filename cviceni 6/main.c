/*
 * cviceni_6.c
 *
 * Created: 13.03.2024 12:22:57
 * Author : skapak martin
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "timer.h"
#include "ADC.h"
#include "LCD.h"
#include "encoder.h"
#include "keyboard.h"
#include "UART.h"
#include "helpf.h"

FILE LCDout = FDEV_SETUP_STREAM(LCD_putchar, NULL,_FDEV_SETUP_WRITE);

int main(void)
{
	Inittime();
	init_encoder();
//	initkeyboard();
	initLCD();
//	initUART(25);
	sei();
	
	stdout = &LCDout;
	/* ukol 2
	char key;
	char string[16];
	uint8_t counter=0;
 	string_clear(string);
	 */
    /* Replace with your application code */
    while (1) 
    {
		
		//ukol1
		int enco=enco_read();
		LCD_set_cursor(0,0);
		if(enco<0)
		{
			printf("%d                ",enco);
		}else
			printf(" %d               ",enco);
		
		LCD_set_cursor(1,0);
		printf("%d",readbutton());
		

		/*ukol 2
		LCD_set_cursor(0,counter);
		key=keyboard_read();
		if (key=='#'||counter==17)
		{
			for (int i = 0; i < counter; i++) {
				char tmp=string[i];
				USART_Transmit(tmp);
			}
			string_clear(string);
			LCD_clear_row(0);
			counter=0;
		}else if(key=='*')
		{
			string_clear(string);
			LCD_clear_row(0);
			counter=0;
		}else if (key!='\0')
		{
			printf("%c",key);
			string[counter]=key;
			counter++;
		}
		
		LCD_set_cursor(1,USART_interupt_string_poz());
		
		printf("%c",USART_interupt_read());
		*/
		}
}

