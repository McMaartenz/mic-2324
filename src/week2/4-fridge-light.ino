/*!
 * Fridge Light
 * schrijf een I/O pin programma in C
 */

#include <avr/io.h>

#define PIN_BTN PINB0
#define PIN_LED PINC4

int main(void) {    
    /* SETUP */
    DDRC |= (1 << PIN_LED); // Set OUTPUT
    DDRB &= ~(1 << PIN_BTN); // Set INPUT

    PORTB |= (1 << PIN_BTN); // Enable pull-up

    uint8_t state;
    while (1) {
        state = PINB;

        const bool opened = state & (1 << PIN_BTN);
        if (opened) {
            PORTC |= 1 << PIN_LED; // Turn on
        }
        else {
            PORTC &= ~(1 << PIN_LED); // Turn off
        }
    }

    return 0;
}
