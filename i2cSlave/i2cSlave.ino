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
  Wire.onReceive(wireOnReceive_event); //when Master send data to me  
  Wire.onRequest(wireOnRequest_event);//when Master request data from me

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

void wireOnRequest_event(){
  int input = analogRead(A1);

  // To send multiple bytes from the slave,
  // you have to fill your own buffer and send it all at once.
  uint8_t buffer[2];
  buffer[0] = input >> 8; //MSB, first 8 digits from 2bytes 0b****************
  buffer[1] = input & 0xff;
  
  /*
  input = 10 001 000 11
  input >> 8 = 10
  input & 0xff = input & 11111111 = 001 000 11
   */
  
  
  buffer[0] = 0b11111111;
  buffer[1] = 0b11110000;
  Wire.write(buffer, 2);
}







