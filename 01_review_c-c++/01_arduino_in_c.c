#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect) {
	// toggle PD5
	PIND |= (1 << PIND5);
}

int main(void) {
	// set up all of I/O
	DDRD &= ~(1 << DDD2); // define PD2 is an INPUT
	DDRD |= (1 << DDD5); // define PD5 is an OUTPUT
	// initialize external interrupt
	// External Interrupt Control A (EICRA)
	// set interrupt CHANGE mode at External Interrupt 0 Sense Control
	EICRA |= (1 << ISC00);  
	// enable INT0 at External Interrupt Mask Register (EIMSK)
	EIMSK |= (1 << INT0);
	// set global interrupt enable
	sei();
	// loop for checking interrupt
	while (1);
}
