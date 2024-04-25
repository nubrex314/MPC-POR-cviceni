/*
 * helpf.c
 *
 * Created: 15.03.2024 16:30:45
 *  Author: msukd
 */ 

#include <stdio.h>
#include <avr/io.h>

#include "helpf.h"
#include "UART.h"


void string_clear(char *string)
{
	for (int i = 0; i < 16; i++) {
		string[i] = '\0'; // Smazání obsahu øetìzce
	}
}

void printfloat(float in)
{
	int16_t Z=(int)in; // celecisla
	int16_t des=(in-Z)*100;//2 desetine cisla
	if(des<10)
		printf("%d.0%d C",Z ,des);
	else
		printf("%d.%d C",Z ,des);
		
	return;
}

void print_binary(uint16_t num) {
    for (int8_t bit = sizeof(uint16_t)*8-7; bit >= 0; bit--) {
        putchar((num & (1 << bit)) ? '1' : '0');
    }
}

uint16_t ascii_to_number(uint16_t a)
{
	return a-48;
}

