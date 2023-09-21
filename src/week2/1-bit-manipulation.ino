/*! 
 *  Bitmanipulatie 1
 *  Toggle de letters van hoofd naar klein
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <HardwareSerial.h>

//! Distance between upper/lowercase
constexpr int CaseDifference = 'a' - 'A';

/*! \brief Convert the casing of the char
 *  \param x Char to convert
 *  \return Converted char
 */
char convert_casing(char x);

int main(void) {
  sei();
  Serial.begin(9600);
  
  while (1) {  
    if (!Serial.available()) {
      continue;
    }
    
      const char x = Serial.read();
      const char y = convert_casing(x);
      
      Serial.print(y);
  }
  
  return 0;
}

char convert_casing(char x) {
  if (x >= 'A' && x <= 'Z') {
      return x + CaseDifference;
  }
  
  if (x >= 'a' && x <= 'z') {
      return x - CaseDifference;
  }
  
  return x;
}
