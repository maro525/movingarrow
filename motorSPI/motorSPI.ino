// SPI test Arduino: Master, DUALSHOCK: Slave
//
// Copyright (c) 2015 Kazumasa ISE
// Released under the MIT license
// http://opensource.org/licenses/mit-license.php
#include <SPI.h>
#define DEBUG
#define TRANSFER_WAIT 16
#define FRAME_WAIT 16

//const byte CMD[] = {0x01, 0x44, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00};
const byte CMD[] = {0x01, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const byte CMD_BYTES = sizeof CMD;
byte DAT[CMD_BYTES] = {0};

//motor
//左のタイヤ
const int Pin11 = 6;
const int Pin12 = 7;

//右のタイヤ
const int Pin21 = 4;
const int Pin22 = 5;

void setup() {
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV64);
  SPI.setDataMode(SPI_MODE3);
  pinMode(MISO, INPUT_PULLUP);
#ifdef DEBUG
  Serial.begin(115200);
#endif

  //motor
  pinMode(Pin11, OUTPUT);
  pinMode(Pin12, OUTPUT);
  pinMode(Pin21, OUTPUT);
  pinMode(Pin22, OUTPUT);

}
void loop() {
  digitalWrite(SS, LOW);
  delayMicroseconds(TRANSFER_WAIT);
  for (byte i = 0; i < CMD_BYTES; i++) {
    DAT[i] = SPI.transfer(CMD[i]);
    delayMicroseconds(TRANSFER_WAIT);
  }
  digitalWrite(SS, HIGH);
  delay(FRAME_WAIT);
#ifdef DEBUG
  Serial.print("DAT: ");
  for (byte i = 0; i < CMD_BYTES; i++) {
    Serial.print(DAT[i], DEC);//HEX=16進数, DEC=１０進数
    Serial.print(" ");

    if (DAT[3] == 239) {
      //前進
      digitalWrite(Pin11, HIGH);
      digitalWrite(Pin12, LOW);
      digitalWrite(Pin21, HIGH);
      digitalWrite(Pin22, LOW);
      Serial.println("GO");
      //delay(1000);
    }

    if (DAT[3] == 191) {
      //後退
      digitalWrite(Pin11, LOW);
      digitalWrite(Pin12, HIGH);
      digitalWrite(Pin21, LOW);
      digitalWrite(Pin22, HIGH);
      Serial.println("BACK");
    }

    if (DAT[3] == 255) {
      //STOP
      digitalWrite(Pin11, LOW);
      digitalWrite(Pin12, LOW);
      digitalWrite(Pin21, LOW);
      digitalWrite(Pin22, LOW);
      Serial.println("STOP");
    }

    if (DAT[3] == 223) {
      //右回る
      digitalWrite(Pin11, HIGH);
      digitalWrite(Pin12, LOW);
      digitalWrite(Pin21, LOW);
      digitalWrite(Pin22, LOW);
      Serial.println("Right");
    }

    if (DAT[3] == 127) {
      //左回る
      digitalWrite(Pin11, LOW);
      digitalWrite(Pin12, LOW);
      digitalWrite(Pin21, HIGH);
      digitalWrite(Pin22, LOW);
      Serial.println("left");
    }


  }
  Serial.println();
#endif
}
