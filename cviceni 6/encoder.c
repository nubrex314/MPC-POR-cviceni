
#include <stdio.h>
#include <avr/io.h>
#include <avr/cpufunc.h>
#include "encoder.h"
#include "timer.h"
#include "LCD.h"

volatile int encoderCount = 0;
volatile int buttonPressCount = 0;
volatile uint8_t D2_old	 = 0;
volatile uint8_t D3_old = 0;

void init_encoder() {
	// Nastaven� pull-up rezistor� na pinech D2, D3 a B3
	PORTD |= (1 << PORTD2) | (1 << PORTD3);
	PORTB |= (1 << PORTB3);
// Nastaven� pin� jako vstupy
	DDRD &= ~((1 << PORTD2) | (1 << PORTD3));
	DDRB &= ~(1 << PORTB3);
	
	// Povolen� extern�ch p�eru�en� 
	PCICR = (1 << PCIE0)|(1 << PCIE2);
	// Povolen� p�eru�en� pro konkr�tn� piny
	PCMSK2 = (1 << PCINT18)|(1 << PCINT19);
	PCMSK0 |= (1 << PCINT3);
}

ISR(PCINT2_vect)
{
	//zakazani preruseni
	PCICR &= ~(1 << PCIE2); 
	
	if (D2_old == 0 && (PIND & (1 << PORTD2)) == 4) 
	{
	if ( (PIND & (1 << PORTD3)) == 8)
	encoderCount++;
	} 
	if (D3_old == 0 && (PIND & (1 << PORTD3)) == 8) 
	{
	if ((PIND & (1 << PORTD2)) == 4)
	encoderCount--;
	} 
	D2_old = (PIND & (1 << PORTD2));
	D3_old = (PIND & (1 << PORTD3));
	delay(1500);
	//povoleni preruseni
	PCICR |= (1 << PCIE2); 
}

// P�eru�en� pro tla��tko
ISR(PCINT0_vect) {
	buttonPressCount++;
	//zakmity
		while(!(PINB&(1<<PINB3)))
	delay(150);
}

int readbutton(void)
{
	return buttonPressCount/2;
}

int enco_read()
{
	return encoderCount;
}
