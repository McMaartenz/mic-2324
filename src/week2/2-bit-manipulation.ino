/*! 
 *  Bitmanipulatie 2
 *  Bepaal of het een hoofd- of kleine letter is
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <HardwareSerial.h>

/*! \brief Check if given char is uppercase
 *  \param x Char to check
 *  \return Whether x is uppercase
 */
bool is_upper(char x);

/*! \brief Check if given char is lowercase
 *  \param x Char to check
 *  \return Whether x is lowercase
 */
bool is_lower(char x);

//! Strings
const char* messages[] = {
  " is not in the alphabet",
  " is uppercase",
  " is lowercase",
};

int main(void) {
  sei();
  Serial.begin(9600);
  
  while (1) {  
    if (!Serial.available()) {
      continue;
    }
    
    const char x = Serial.read();
    
    const int result = is_upper(x) | (is_lower(x) << 1);
    const char* message = messages[result];
    
    Serial.print(x);
    Serial.println(message);
  }
  
  return 0;
}

bool is_upper(char x) {
    return x >= 'A' && x <= 'Z';
}

bool is_lower(char x) {
    return x >= 'a' && x <= 'z';
}
