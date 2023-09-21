#include <avr/io.h>
#include <util/delay.h>

#define ARR_LEN 9

int main(void) {
    int8_t chars[ARR_LEN] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };

    /* SETUP */
    DDRB = 0xFF; // All output

    while (1) {
        for (uint64_t i = 0; i < ARR_LEN; i++) {
            PORTB = chars[i];
            _delay_ms(2000);
        }
    }

    /* Observed pattern
    
        1100
        1101
        1110
        1111
        0000
        0001
        0010
        0011
        0100
        1100
        1101
    
    */

    return 0;
}
