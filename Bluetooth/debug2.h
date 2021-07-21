/*
 * USART.c
 *
 * Created: 10/9/2019 8:59:47 PM
 * Author : Morten
 */ 


#include <stdio.h>
#include <avr/io.h>
#define fosc 16000000
#include <util/delay.h>
#include <avr/interrupt.h>
#define BAUD 19200
#define MYUBRR 103
//((fosc/8)/BAUD)-1

 

void USART_init(unsigned int ubrr)
{
    //full duplex
    UCSR0A=(1<<U2X0);
    //enable receiver and transmitter
    UCSR0B|=(1<<RXEN0)|(1<<TXEN0);
    //set frame format: 8 data bit og 1 stop bit
    UCSR0C|=(1<<UCSZ10)|(1<<UCSZ11);
    //set BAUD rate UBRR 103 for 19200.
    UBRR0H=(unsigned char)(ubrr>>8);
    UBRR0L=(unsigned char)ubrr;
	
	UBRR0H = (F_CPU/(DEBUG_BAUD*16L)-1) >> 8;
	UBRR0L = (F_CPU/(DEBUG_BAUD*16L)-1);
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);
	UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
	
	UCSR0B|=(1<<RXEN0);
}

void USART_Transmit(char tx)
{
    //waiting for empty transmitter buffer
    while(!(UCSR0A &(1<<UDRE0)));
    //puts data into buffer and sends data
    UDR0=tx;
    
}

uint8_t USART_Receive(void)
{
    //waiting for data to be received
    while(!(UCSR0A & (1<<RXC0)));
    //retrieve and return received data from the buffer
    return UDR0;
    
}

int main(void)
{
           
        
    USART_init(MYUBRR);
    //USART_init(103);
    
    
    while (1) 
    {
    USART_Send_String(ptr);

    _delay_ms(5000);
    
        
    }
}