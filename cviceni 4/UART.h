
#pragma once
#include <avr/interrupt.h>//preruseni

#ifndef UART_H_
#define UART_H_
#include <stdio.h>

int uart_getchar(FILE *stream);

int uart_putchar(char c, FILE *stream);

void initUART(uint16_t bautrate);

void USART_Transmit(unsigned char data);

unsigned char USART_Receive(void);

char USART_interupt_read();

uint8_t USART_interupt_string_poz();

#endif /* UART_H_ */