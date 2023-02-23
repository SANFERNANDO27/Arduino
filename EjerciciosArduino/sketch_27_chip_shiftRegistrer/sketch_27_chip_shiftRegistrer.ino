int latchPin = 8;
int clockPin = 13;
int dataPin = 12;
byte myByte1 = 0b1010101;
byte myByte2 = 0b00000000;
int dt = 500;
int i;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

}

/*
Binarios                  Decimales
10100000                  160
01010000                  80
00101000                  40
*/

void loop() {
  /*
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte1);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  myByte1 = myByte1*2;
  */

  for(i = 0; i <= 255; i++){
    digitalWrite(latchPin, LOW);
    myByte2++;
    shiftOut(dataPin, clockPin, LSBFIRST, myByte2);
    digitalWrite(latchPin, HIGH);
    delay(dt);
    Serial.println(myByte1, BIN);
  }

  /*digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte1);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte2);
  digitalWrite(latchPin, HIGH);
  delay(dt);*/
}
