/*
2 Arduinos crossed by A4-A4, A5-A5 (i2c)
 And common ground!
 What about 10k pullups on SDA, SCL? 
 */

#define DEBUG 

#include <Wire.h>
uint8_t addressSlave0 = 0x1A; // 7bit address: max 127_DEC, 1111111_BIN

void setup() {
  // Start the I2C Bus as Slave on address 9
  Wire.begin(addressSlave0); // 7-bit slave address. Im slave.  
  Wire.onReceive(wireOnReceive_event);

#ifdef DEBUG   
  Serial.begin(9600);
#endif  
}

void wireOnReceive_event(int countBytes) {
#ifdef DEBUG 
  Serial.print("countBytes=");
  Serial.print(countBytes, DEC);
  Serial.print("\r\n");
#endif 

  byte currByte;  
  while(Wire.available()){
    currByte = Wire.read(); //read 1 byte

#ifdef DEBUG 
    Serial.println(currByte, DEC);
#endif 
  }

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






