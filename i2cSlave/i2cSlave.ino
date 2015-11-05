/*
2 Arduinos crossed by A4-A4, A5-A5 (i2c)
 And common ground!
 What about 10k pullups on SDA, SCL? 
 */

#include <Wire.h>
uint8_t addressSlave0 = 0x1A; // 7bit address: max 127_DEC, 1111111_BIN
int LED1 = 3;
int LED2 = 4;
int x = 0;
void setup() {
  // Define the LED pin as Output
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(addressSlave0); // 7-bit slave address. Im slave.  
  Wire.onReceive(wireOnReceive_event);
  Serial.begin(9600);
}
void wireOnReceive_event(int countBytes) {
  //x = Wire.read();    // read one character from the I2C
  digitalWrite(LED1, HIGH);      
  Serial.println(countBytes, DEC);
  delay(100);
  digitalWrite(LED1, LOW);
}
void loop() {    

}


void blinkLeds(int x){
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

