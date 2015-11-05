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

#define DEBUG

#include <Wire.h>
uint8_t addressSlave0 = 0x1A; // 7bit address: max 127_DEC, 1111111_BIN

void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); //address=null => Im Master on line

#ifdef DEBUG 
  Serial.begin(9600);
#endif

}

void loop() {

  //sendBytesToSlave
  byte dataBytes[] = { 
    0b11111111, 0b00000000, 0b11110000, 0b00001111       };
  uint8_t dataSize = sizeof(dataBytes);
  //sendBytesToSlave(addressSlave0, dataBytes, dataSize);
  delay(2000);

  //Master wants to get bytes from a slave
  uint8_t countBytesMustBe = 2;
  byte* bytesFromSlave = requestBytesFromSlave(addressSlave0, countBytesMustBe);
  Serial.println(*bytesFromSlave, BIN);
  Serial.println(*(++bytesFromSlave), BIN);
  delay(2000);


}
//Master wants to get bytes from a slave
byte* requestBytesFromSlave(uint8_t addressSlave, uint8_t countBytesMustBe){  
  uint8_t countBytesReceived;  
  Wire.beginTransmission(addressSlave); // 7-bit slave address.
  countBytesReceived = Wire.requestFrom(addressSlave, countBytesMustBe);
  byte dataBytes[countBytesReceived];
  
  //if we get required quantity of bytes
  if(countBytesReceived == countBytesMustBe){
    uint8_t i =0;
    while(Wire.available()){
      dataBytes[i++] = Wire.read(); //read 1 byte
    }
  }
  
  Wire.endTransmission();

#ifdef DEBUG 
  Serial.print("countBytesReceived=");
  Serial.print(countBytesReceived, DEC);
  Serial.print("\r\n");
#endif 
  return dataBytes;
}

//MAX 32 bytes due to buffer size in source ||& hardware limit
void sendBytesToSlave(uint8_t addressSlave, const byte* dataBytes, size_t dataSize){
  byte dataByte;
  Wire.beginTransmission(addressSlave); // 7-bit slave address.
  Wire.write(dataBytes, dataSize);
  Wire.endTransmission(); //stop transmitting

#ifdef DEBUG 
  Serial.print("send bytesArray to slave ");
  Serial.print(addressSlave, HEX);
  Serial.print("\r\n");
  Serial.print("countBytes=");
  Serial.print(dataSize, DEC);
  Serial.print("\r\n");
  for(uint8_t i=0; i < dataSize; i++){
    dataByte = dataBytes[i];    
    Serial.println(dataByte, BIN);
  }
#endif

}













