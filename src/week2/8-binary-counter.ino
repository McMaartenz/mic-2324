#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "HardwareSerial.h"

#define PIN_LED_0 PIND2
#define PIN_LED_1 PIND3
#define PIN_LED_2 PIND4
#define PIN_LED_3 PIND5

#define PIN_RX PIND0
#define PIN_TX PIND1

int main(void) {
    sei();
    Serial.begin(9600);

    /* SETUP */
    DDRD |=
        (1 << PIN_LED_0) |
        (1 << PIN_LED_1) |
        (1 << PIN_LED_2) |
        (1 << PIN_LED_3);

    uint8_t counter = 0;
    while (1) {
        PORTD &= (1 << PIN_TX) | (1 << PIN_RX); // Clear other than RX/TX
        PORTD |= counter << 2; // Skip RX/TX
        
        _delay_ms(48);
        if (++counter > 64) {
            counter = 0;
        }
    }

    return 0;
}
