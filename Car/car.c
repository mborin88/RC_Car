#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "debug.h"
#define PWM_DUTY_MAX 240

void initMotor(){ //Initialise D0  D1, D2 as ouputs
	DDRA = 0xFF;
	DDRC = 0xFF;
	PORTA = 0x00;
	PORTC = 0x00;

}

void forwardCar(){ 
	PORTA |= _BV(0);
	PORTA &= ~_BV(1);
	PORTA |= _BV(2);
	PORTA &= ~_BV(3);
	
	PORTC |= _BV(0);
	PORTC &= ~_BV(1);
	PORTC |= _BV(6);
	PORTC &= ~_BV(7);

}

void pivotLeft(){ 
	PORTA |= _BV(0);
	PORTA &= ~_BV(1);
	PORTA |= _BV(2);
	PORTA &= ~_BV(3);
	
	PORTC &= ~_BV(0);
	PORTC |= _BV(1);
	PORTC &= ~ _BV(6);
	PORTC |= _BV(7);

}

void pivotRight(){
	PORTA &= ~_BV(0);
	PORTA |= _BV(1);
	PORTA &= ~ _BV(6);
	PORTA |= _BV(7);
	
	PORTC |= _BV(0);
	PORTC &= ~_BV(1);
	PORTC |= _BV(2);
	PORTC &= ~_BV(3);
}

void stopCar(){ 
	PORTA &= ~_BV(0);
	PORTA &= ~_BV(1);
	PORTA &= ~_BV(2);
	PORTA &= ~_BV(3);
	
	PORTC &= ~_BV(0);
	PORTC &= ~_BV(1);
	PORTC &= ~_BV(6);
	PORTC &= ~_BV(7);

}


int main(){
	initMotor();
	init_uart();
	DDRB |= _BV(PB7);
	uint8_t rec = 0;
	while(1){
		rec = rx();
		if(rec==53)forwardCar();
		else if(rec==54) stopCar();
		else if (rec==55) pivotLeft();
		else if (rec==56) pivotRight();
	}
}