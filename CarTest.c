#include <stdio.h>
#include <avr/io.h>
#define PWM_DUTY_MAX 240

void initMotor(){ //Initialise D0  D1, D2 as ouputs
	DDRD |= _BV(0); //Load 1
	DDRD |= _BV(1);	//Load 2
	DDRD |= _BV(2);	//Load 3
	
	PORTD &= ~_BV(0);	//Initialise D0 off
	PORTD |= _BV(1);	//Initialise D1 off
	PORTD &= ~_BV(2);	//Initialise D2 off
}

int main(){
	while(1){
		initMotor();
	}
}