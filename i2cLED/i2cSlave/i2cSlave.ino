/*
2 Arduinos crossed by A4-A4, A5-A5 (i2c)
 And common ground!
 What about 10k pullups on SDA, SCL? 
 */

#include <Wire.h>
const uint8_t addressSlave0 = 0x1A; // 7bit address: max 127_DEC, 1111111_BIN
const uint8_t ledPin1 = 3; 
const uint8_t ledPin2 = 4;


void setup() {  
  Wire.begin(addressSlave0); // 7-bit slave address. Im slave.  
  Wire.onReceive(wireOnReceive_event); //when Master send data to me  
  
  Serial.begin(9600);

  pinMode(ledPin1, OUTPUT); 
  pinMode(ledPin2, OUTPUT);   
}

void wireOnReceive_event(int countBytes) {
  byte currByte;  
  while(Wire.available()){
    currByte = Wire.read(); //read 1 byte
    Serial.println(currByte, BIN);
  }
  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  
  // 11 10 01 00 => led2_led1 is 0\1
  
  if(currByte & 0b01){
    digitalWrite(ledPin1, HIGH);
  }
  if(currByte & 0b10){
    digitalWrite(ledPin2, HIGH);
  } 
  
  
}

void loop() {    

}






