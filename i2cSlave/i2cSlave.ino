/*
2 Arduinos crossed by A4-A4, A5-A5 (i2c)
 And common ground!
 What about 10k pullups on SDA, SCL? 
 */

#include <Wire.h>
addressSlave0 = 0x1A; // 7bit address: max 127_DEC, 1111111_BIN
int LED1 = 3;
int LED2 = 4;
int x = 0;
void setup() {
  // Define the LED pin as Output
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); // 7-bit slave address. Im slave.
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
  Serial.println(x, DEC);
}
void loop() {  
  if (x == 0) {
    digitalWrite(LED1, HIGH);    
    digitalWrite(LED2, LOW);   
   delay(100); 
  }
  if (x == 1) {
    digitalWrite(LED1, LOW);    
    digitalWrite(LED2, HIGH);    
  }
  if (x == 2) {
    digitalWrite(LED1, HIGH);    
    digitalWrite(LED2, HIGH);    
  }  
  if (x == 3) {
    digitalWrite(LED1, LOW);    
    digitalWrite(LED2, LOW);    
  }  

}

