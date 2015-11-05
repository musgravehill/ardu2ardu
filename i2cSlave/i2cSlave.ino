/*
2 Arduinos crossed by A4-A4, A5-A5 (i2c)
And common ground!
What about 10k pullups on SDA, SCL? 
*/

#include <Wire.h>
int LED1 = 3;
int LED2 = 4;
int x = 0;
void setup() {
  // Define the LED pin as Output
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
  Serial.println(x, DEC);
}
void loop() {  
  if (x == '0') {
    digitalWrite(LED1, 1);    
    digitalWrite(LED2, 0);    
  }
  if (x == '1') {
    digitalWrite(LED1, 0);    
    digitalWrite(LED2, 1);    
  }
  if (x == '2') {
    digitalWrite(LED1, 1);    
    digitalWrite(LED2, 1);    
  }  
  
}
