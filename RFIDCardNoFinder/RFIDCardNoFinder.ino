#include <SPI.h>
#include <RFID.h>

RFID rfid(10, 9);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
}

void loop() {
  if (rfid.isCard()) {


    if (rfid.readCardSerial()) {

      Serial.println("Card No Found: ");
      Serial.print(rfid.serNum[0]);
      Serial.print(" , ");
      Serial.print(rfid.serNum[1]);
      Serial.print(" , ");
      Serial.print(rfid.serNum[2]);
      Serial.print(" , ");
      Serial.print(rfid.serNum[3]);
      Serial.print(" , ");
      Serial.print(rfid.serNum[4]);
      Serial.println(" ");
    }
  }
  rfid.halt();
}