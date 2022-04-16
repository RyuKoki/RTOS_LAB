#define F_CPU 16000000UL
#include <xc.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define INIT_TIMER1 (0x0000)

ISR(INT0_vect) {
    // toggle PD5
    PIND |= (1 << PIND5);
}

int main(void) {
    // set up all of I/O
    DDRD &= ~(1 << DDD2); // define PD2 is an INPUT
    DDRD |= (1 << DDD5); // define PD5 is an OUTPUT
    // clear global interrupt
    cli();
    // initialize external interrupt
    // External Interrupt Control A (EICRA)
    // set interrupt CHANGE mode at External Interrupt 0 Sense Control
    EICRA |= (1 << ISC00); 
    // enable INT0 at External Interrupt Mask Register (EIMSK)
    EIMSK |= (1 << INT0);
    // SETTING TIMER / COUNTER 1
    TCNT1 = INIT_TIMER1;
    // Normal Mode 
    TCCR1A = TCCR1C = 0x00;
    // pre-scaler => 8 in clock select
    TCCR1B |= (1 << CS11);
    // set global interrupt enable
    sei();
    // loop for checking interrupt
    while (1) {}
}
