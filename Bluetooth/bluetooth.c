#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "debug.h"

int main(void){
	
	init_debug_uart0();
	DDRB |= _BV(PB7);
	uint8_t rec = 0;
	while(1){
		rec = ugetchar0();
		if(rec>53) PORTB |= _BV(PB7);
		else if(rec<=53) PORTB &= ~_BV(PB7);
	}
}