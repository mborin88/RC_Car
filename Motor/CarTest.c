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

void forwardCar(){ //Initialise D0  D1, D2 as ouputs
	PORTA |= _BV(0);
	PORTA &= ~_BV(1);
	PORTA |= _BV(2);
	PORTA &= ~_BV(3);
	
	PORTC |= _BV(0);
	PORTC &= ~_BV(1);
	PORTC |= _BV(2);
	PORTC &= ~_BV(3);

}

void stopCar(){ //Initialise D0  D1, D2 as ouputs
	PORTA &= ~_BV(0);
	PORTA &= ~_BV(1);
	PORTA &= ~_BV(2);
	PORTA &= ~_BV(3);
	
	PORTC &= ~_BV(0);
	PORTC &= ~_BV(1);
	PORTC &= ~_BV(2);
	PORTC &= ~_BV(3);

}


int main(){
	initMotor();
	while(1){
		forwardCar(); 
	}
}