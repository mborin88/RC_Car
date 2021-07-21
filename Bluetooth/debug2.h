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
}

void USART_Transmit(char tx)
{
    //venter på tom transmitter buffer
    while(!(UCSR0A &(1<<UDRE0)));
    //putter data ind i buffer og sender data
    UDR0=tx;
    
}

char USART_Receive(void)
{
    //venter på at data bliver modtaget
    while(!(UCSR0A & (1<<RXC0)));
    //hent og retuner modtaget data fra bufferen
    return UDR0;
    
}

//transmitter en string
void USART_Send_String(char *ptr)
{
    //kalder transmitfunktionen for hver byte i ptr
    while(*ptr !=0x00)
    {USART_Transmit(*ptr);
    ptr++;}
    
}

 

 

 

char ptr[]="Hej med dig!"; //string der skal sendes

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