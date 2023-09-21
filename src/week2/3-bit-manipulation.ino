/*! 
 *  Bitmanipulatie 3
 *  Set en reset bits in een byte
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <HardwareSerial.h>

int main(void) {
  sei();
  Serial.begin(9600);
  
  const char a = 'a';
  Serial.println(a);
  
  char b = a;  
  b |= (1 << 1);
  b &= ~(1 << 0);
  
  Serial.println(b);
  
  //! Opgave A
  char n = b;
  n |= (1 << 2) | (1 << 3);
  
  Serial.println(n);
  
  //! Opgave B
  char h = n;
  h &= ~((1 << 1) | (1 << 2));
  
  Serial.println(h);
  
  Serial.flush();
  return 0;
}
