/*
 * cviceni-7.c
 *
 * Created: 20.03.2024 12:36:13
 * Author : msukd
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "timer.h"
#include "UART.h"
#include "RTC.h"
#include "TWI.h"
#include "ADC.h"
#include "LCD.h"

#include "helpf.h"

//#include "EEPROM.h"
volatile uint8_t gen = 0;

ISR(PCINT0_vect) {
	gen++;
	//zakmity
}



FILE LCDout = FDEV_SETUP_STREAM(LCD_putchar, NULL,_FDEV_SETUP_WRITE);
FILE UARTout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);


	uint8_t seconds = 1;
	uint8_t minutes = 5;
	uint8_t hours = 1;
	uint8_t days = 3;
	uint8_t months = 2;
	uint8_t year = 1;
		
		
int main(void)
{	
	uint8_t poz_uart=0;
	uint8_t poz_uart_string=0;
	initADC();
	initLCD();
	initUART(25);
	initTWI(100000);
	Inittime();
	sei();
	stdout = &LCDout;
	delay(10000);

	
	fprintf(&UARTout,"piste pouze cisla");
	USART_Transmit(0x0A);
	fprintf(&UARTout,"cas:");
	while (1)
	{
		
		poz_uart_string=USART_interupt_string_poz();
		if(poz_uart==poz_uart_string)
		{
			switch (poz_uart) {
				case 4:
					//sec des
					seconds= ascii_to_number(USART_interupt_read())*10;
				break;
				case 5:
					//sec jed
					seconds= ascii_to_number(USART_interupt_read())+seconds;
					USART_Transmit(0x0A);
					fprintf(&UARTout,"datum:");
				break;
				case 2:
					//min des
					minutes= ascii_to_number(USART_interupt_read())*10;
				break;
				case 3:
					//min jed
					minutes= ascii_to_number(USART_interupt_read())+ minutes;
					USART_Transmit(0x3A);
					break;
				case 0:
				//hod des
				hours= ascii_to_number(USART_interupt_read())*10;
				break;
				case 1:
				//hod jed
				hours= ascii_to_number(USART_interupt_read())+hours;
				USART_Transmit(0x3A);
				break;
				case 6:
				//dny des
				days= ascii_to_number(USART_interupt_read())*10;
				break;
				case 7:
				//dny jed
				days= ascii_to_number(USART_interupt_read())+ days;
				USART_Transmit(0x3A);//dvojtecka
				break;
				case 8:
				//mes des
				months= ascii_to_number(USART_interupt_read())*10;
				break;
				case 9:
				//mes jed
				months= ascii_to_number(USART_interupt_read())+ months;
				USART_Transmit(0x3A);//dvojtecka
				break;
				case 10:
				//rok des
				year= ascii_to_number(USART_interupt_read())*10;
				break;
				case 11:
				//rok jed
				year= ascii_to_number(USART_interupt_read())+ year;
				break;
				default:
				break;
			}
			poz_uart++;
		}
		if (poz_uart>11)
		{
			break;
		}
		}
		rtc_set_sec(seconds);
		rtc_set_min(minutes);
		rtc_set_hour(hours);
		rtc_set_days(days);
		rtc_set_months(months);
		rtc_set_year(year);
				
		rtc_start_count();
		rtc_start_gen();
		// Povolen externch peruen pro PCINT0 (pin B3 pro tlatko)
		PCICR |= (1 << PCIE0);
		// Povolen peruen pro konkrtn pin (B3)
		PCMSK0 |= (1 << PCINT3);
		
    /* Replace with your application code */
    while (1) 
    {		
		if(gen>1)
		{
		seconds = rtc_read_sec();
		minutes = rtc_read_min();
		hours = rtc_read_hours();
		days = rtc_read_days();
		months = rtc_read_months();
		year = rtc_read_year();
	
		LCD_set_cursor(0,0);
		printf("Cas:   %2.0d:%2.0d:%2.0d",hours,minutes, seconds);
		LCD_set_cursor(1,0);
		printf("Datum: %2.0d.%2.0d.%2.0d",days, months, year);
		gen=0;
		fprintf(&UARTout,"clock");
		}

    }
}

