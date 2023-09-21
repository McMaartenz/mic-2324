#include <avr/io.h>

#define PIN_LED_0 PINB0
#define PIN_LED_1 PINB1
#define PIN_LED_2 PINB2
#define PIN_LED_3 PINB3

#define PIN_BTN PINC5

int main(void) {
    /* SETUP */
    DDRB |= // Outputs
        (1 << PIN_LED_0) |
        (1 << PIN_LED_1) |
        (1 << PIN_LED_2) |
        (1 << PIN_LED_3);

    DDRC &= ~(1 << PIN_BTN); // Input
    PORTC |= (1 << PIN_BTN); // Enable pull-up

    while (1) {
        const uint8_t state = PINC; // Read state
        const bool pressed = !(state & (1 << PIN_BTN)); // Read button pin

        if (pressed) {
            PORTB &= ~((1 << PIN_LED_1) | (1 << PIN_LED_2)); // Turn off 2, 3
            PORTB |= (1 << PIN_LED_0) | (1 << PIN_LED_3); // Turn on 1, 4
        }
        else {
            PORTB &= ~((1 << PIN_LED_0) | (1 << PIN_LED_3)); // Turn off 1, 4
            PORTB |= (1 << PIN_LED_1) | (1 << PIN_LED_2); // Turn on 2, 3
        }
    }

    return 0;
}
