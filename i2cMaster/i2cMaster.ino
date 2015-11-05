/*
2 Arduinos crossed by A4-A4, A5-A5 (i2c)
 And common ground!
 What about 10k pullups on SDA, SCL? 
 
 begin()
 begin(address)
 requestFrom(address, count)
 beginTransmission(address)
 endTransmission()
 send()
 available()
 receive()
 onReceive(handler)
 onRequest(handler)
 
 */

#include <Wire.h>
uint8_t addressSlave0 = 0x1A; // 7bit address: max 127_DEC, 1111111_BIN

void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); //address=null => Im Master on line
  Serial.begin(9600);  
}

void loop() {

  //sendBytesToSlave
  byte dataBytes[] = { 
    0b11111111, 0b00000000, 0b11110000, 0b00001111         };
  uint8_t dataSize = sizeof(dataBytes);
  sendBytesToSlave(addressSlave0, dataBytes, dataSize);
  delay(1000);

}

//MAX 32 bytes due to buffer size in source ||& hardware limit
void sendBytesToSlave(uint8_t addressSlave, const byte* dataBytes, size_t dataSize){
  byte dataByte;
  Wire.beginTransmission(addressSlave); // 7-bit slave address.
  Wire.write(dataBytes, dataSize);
  /*for(uint8_t i=0; i < dataSize; i++){
   dataByte = dataBytes[i];
   Wire.write(dataByte);  //send 1 byte to slave
   //Serial.println(dataByte, BIN);
   } */  
  Wire.endTransmission(); //stop transmitting
}





