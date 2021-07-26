/*  Author: Steve Gunn
 * Licence: This work is licensed under the Creative Commons Attribution License.
 *          View this license at http://creativecommons.org/about/licenses/
 *   Notes: F_CPU must be defined to match the clock frequency
 *   Usage: Include in your main file and call init_debug_uart0() from the beginning of main
 *          to initialise redirection of stdout, stderr and stdin to UART0.
 */

#define __ASSERT_USE_STDERR
#include <assert.h>
#include <stdio.h>
#include <avr/io.h>

#define DEBUG_BAUD  9600

int uputchar0(char c, FILE *stream)
{
	if (c == '\n') uputchar0('\r', stream);
	while (!(UCSR0A & _BV(UDRE0)));
	UDR0 = c;
	return c;
}

uint8_t rx()
{
	while(!(UCSR0A & _BV(RXC0)));
	return UDR0;
}

void init_uart(void) { /* 8N1 */
	UBRR0H = (F_CPU/(DEBUG_BAUD*16L)-1) >> 8;
	UBRR0L = (F_CPU/(DEBUG_BAUD*16L)-1);
	//UCSR0A = USE_2X << U2X0;
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);
	UCSR0C = _BV(UCSZ00) | _BV(UCSZ01); 
}



