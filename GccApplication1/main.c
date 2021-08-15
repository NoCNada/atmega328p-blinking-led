/*
 * GccApplication1.c
 *
 * Created: 11/8/2021 15:44:50
 * Author : Lauta
 */ 

#include <avr/io.h>
#define F_CPU	16000000L
#include <util/delay.h>
#include <avr/interrupt.h>



void initPort();
void initTimers();

//bandera

//


//Global variables
 volatile uint8_t timeOut250msAprox;
uint8_t flagByte;
//.

// interrupciones
ISR(TIMER0_OVF_vect){
	timeOut250msAprox--;
	if(!timeOut250msAprox){
		timeOut250msAprox = 25;
		//(1 << PORTB5 1) desplazado por B5 es igual a 00100000
		if(PORTB & (1 << PORTB5)) //desplazo al numero 1 cinco veces para que aparezca en la posicion 5
			PORTB &= ~(1 << PORTB5); //~ (1 << PORTB5) = 11011111 hago cero el bit 5 de PORTB5
		else
			PORTB |= (1 << PORTB5);
		}
}

//.

// 
void initPort(){
    //Configuro Pin del LED como salida (PB5 Arduino uno)
    DDRB = (1 << DDB5);
    
    PORTB |= (1 << PORTB5);

}

void initTimers(){
	TCCR0A = 0x00;
	TIFR0 = TIFR0;
	TIMSK0 = (1 << TOIE0);
	TCCR0B = 0x05;
	
}

int main(void)
{
	timeOut250msAprox = 15;    
	initPort();
	initTimers();
	

	sei(); // pongo en 1 el bit 7 del Status

//	timeOut250msAprox = 15;
	/* Replace with your application code */
    while (1) 
    {

//bidou xddd
//		while(!(flagByte & 0x01)){
//			flagByte &= ~0x01;
			//if(TIFR0 & (1 << TOV0)){
				//TIFR0 |= (1 << TOV0);
				//timeOut250msAprox--;
			//}
	//	}

		//_delay_ms(250);
    }
}

