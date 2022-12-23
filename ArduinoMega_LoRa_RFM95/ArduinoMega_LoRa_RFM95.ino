
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>

#define ss 53
#define rst 10
#define dio0 9
//#define dio1 2
//#define dio2 4

int counter = 0;
//String inString;
 int datakirim;

void setup() {
 
  
  datakirim = 12;
//  inString = String(datakirim);

  Wire.begin();
  Serial.begin(9600); // connect gps sensor
  while (!Serial);
  Serial.println("LoRa Sender");

  //setup LoRa transceiver module
//  SPI.begin(52,50, 51, 53);
  LoRa.setPins(ss, rst, dio0);

  //replace the LoRa.begin(---E-) argument with your location's frequency
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
  // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");

}

void loop() {

  LoRa.beginPacket();

  //datakirim = datakirim.toString;
  LoRa.print(datakirim);
  LoRa.endPacket();
  counter++;

  delay(1000);
}
