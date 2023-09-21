#include <avr/io.h>
#include <util/delay.h>

#define PIN_LED_0 PIND2
#define PIN_LED_1 PIND3
#define PIN_LED_2 PIND4
#define PIN_LED_3 PIND5
#define PIN_LED_4 PIND6

#define PINS_A_ENABLE PINC4
#define PINS_B_ENABLE PINC5

#define dsp_ms(number, ms, pin) display(number,pin);_delay_ms(ms);display_clear();_delay_ms(2);
#define adsp_ms(number, ms) dsp_ms(number,ms,PINS_A_ENABLE)
#define bdsp_ms(number, ms) dsp_ms(number,ms,PINS_B_ENABLE)

void display_a(uint8_t number);
void display_b(uint8_t number);

int main(void) {
    /* SETUP */
    DDRD |=
        (1 << PIN_LED_0) |
        (1 << PIN_LED_1) |
        (1 << PIN_LED_2) |
        (1 << PIN_LED_3) |
        (1 << PIN_LED_4);

    DDRC |= (1 << PINS_A_ENABLE) | (1 << PINS_B_ENABLE);

    while (1) {
        adsp_ms(0b00000, 100);
        adsp_ms(0b00001, 100);
        adsp_ms(0b00011, 100);
        adsp_ms(0b00111, 100);
        adsp_ms(0b01111, 100);
        adsp_ms(0b11111, 100);

        bdsp_ms(0b00000, 100);
        bdsp_ms(0b10000, 100);
        bdsp_ms(0b11000, 100);
        bdsp_ms(0b11100, 100);
        bdsp_ms(0b11110, 100);
        bdsp_ms(0b11111, 100);
    }

    return 0;
}

void display(uint8_t number, uint8_t pin) {
    PORTD |= number << 2;
    PORTC &= ~((1 << PINS_A_ENABLE) | (1 << PINS_B_ENABLE));
    PORTC |= (1 << pin);
}

void display_clear() {
    PORTD &= 0x03; // Preserve RX/TX
}

void display_a(uint8_t number) {
    display(number, PINS_A_ENABLE);
}

void display_b(uint8_t number) {
    display(number, PINS_B_ENABLE);
}
