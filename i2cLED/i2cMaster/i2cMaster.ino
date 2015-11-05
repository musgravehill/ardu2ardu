/*
2 Arduinos crossed by A4-A4, A5-A5 (i2c)
 And common ground!
 What about 10k pullups on SDA, SCL?  
 */

#include <Wire.h>
uint8_t addressSlave0 = 0x1A; // 7bit address: max 127_DEC, 1111111_BIN

void setup() {  
  Wire.begin(); //address=null => Im Master on line
}

void loop() {
  //sendBytesToSlave
  byte slavePinsState = random(0,4); // 0b00 .. 0b11  //[0..4)
  byte dataBytes[] = { slavePinsState };
  uint8_t dataSize = sizeof(dataBytes);
  sendBytesToSlave(addressSlave0, dataBytes, dataSize);
  delay(100);
}

void sendBytesToSlave(uint8_t addressSlave, const byte* dataBytes, size_t dataSize){
  byte dataByte;
  Wire.beginTransmission(addressSlave); // 7-bit slave address.
  Wire.write(dataBytes, dataSize);
  Wire.endTransmission(); //stop transmitting
}













