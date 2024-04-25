
#include <stdio.h>
#include <avr/io.h>
#include <avr/cpufunc.h>
#include "keyboard.h"
#include "timer.h"

// Definice pin� pro ��dky a sloupce
#define ROWS 4
#define COLS 3

char keys[ROWS][COLS] = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'*', '0', '#'}
};


// Funkce pro inicializaci kl�vesnice
void initkeyboard()
{
	// Nastaven� ��dk� jako v�stupy s pull-up odpory
	DDRD |= (1 << PORTD2) | (1 << PORTD3);
	PORTD |= (1 << PORTD2) | (1 << PORTD3);

	DDRB |= (1 << PORTB3) | (1 << PORTB4);
	PORTB |= (1 << PORTB3) | (1 << PORTB4);
	// Nastaven� sloupc� jako vstupy s pull-up odpory
	DDRC &= ~((1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2));
	PORTC |= (1 << PORTC0) | (1 << PORTC1) | (1 << PORTC2);
}

// Funkce pro �ten� stisknut� kl�vesy
char keyboard_read()
 {
	for (int row = 0; row < ROWS; row++) {
		// Aktivace ��dku
		if (row<2)
		{
			PORTD &= ~(1 << (PORTD2 + row));
		}else
		{
			PORTB &= ~(1 << (PORTB3 + row-2));
		}
		
		delay(1000); // Kr�tk� zpo�d�n� pro stabilitu

		for (int col = 0; col < COLS; col++) 
		{
			// �ten� sloupce
			if (!(PINC & (1 << col))) {
				// Kl�vesa stisknuta
				while(!(PINC&(1<<col)))
				{
					delay(1000);
				}
					
				return keys[row][col];
			}
		}

		if (row<2)
		{
			PORTD |= (1 << (PORTD2 + row));
		}else
		{
			PORTB |= (1 << (PORTB3 + row-2));
		}
		}

	return '\0'; // ��dn� kl�vesa stisknuta
}