

#include "UART.h"
#include <stdio.h>
#include <avr/io.h>
#include <avr/cpufunc.h>

volatile unsigned char recieve='/0';

int uart_putchar(char c, FILE *stream)
{
	if (c == '\n')
	uart_putchar('\r', stream);
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = c;
	return 0;
}

int uart_getchar(FILE *stream)
{
	return USART_Receive();
}

void initUART(uint16_t bautrate)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(bautrate>>8);
	UBRR0L = (unsigned char)bautrate;
	/*Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	//preru�eni recieve dat
	 UCSR0B |= (1 << RXCIE0);
	
	/* Set frame format: 8data, 2stop bit */
	UCSR0C |=(3<<UCSZ00);
}

void USART_Transmit(unsigned char data)
{
	/* Wait for empty transmit buffer */
	while (!(UCSR0A & (1<<UDRE0)))
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

ISR(USART_RX_vect) {
	recieve=UDR0;
}

unsigned char USART_Receive(void)
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)))
	;
	/* Get and return received data from buffer */
	return UDR0;
}

