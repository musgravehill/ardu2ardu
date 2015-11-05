/*
2 Arduinos crossed by A4-A4, A5-A5 (i2c)
And common ground!
What about 10k pullups on SDA, SCL? 
*/

#include <Wire.h>
int x = 0;
void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); 
}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  x++; // Increment x
  if (x > 3) x = 0; // `reset x once it gets 6
  delay(500);
}
