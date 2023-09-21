#include <avr/io.h>

int main(void) {
    /* SETUP */
    DDRB = 0xFF; // All output

    PORTB = 0xAA; // 0b10101010

_restart:
    for (uint64_t i = 0; i < 200; i++) {
        PORTB ^= 0xFF; // Toggle all bits
    }
    goto _restart;
}
