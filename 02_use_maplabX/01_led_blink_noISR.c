#define F_CPU 16000000UL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
void main(void) {
    DDRB |= (1 << 5); // PB5 pin as output
    while(1) {
        PORTB |= (1<<5);  // output high to PB5 pin
       _delay_ms(100);
        PORTB &= ~(1<<5); // output low to PB5 pin
       _delay_ms(100);
    }
    return;
}
