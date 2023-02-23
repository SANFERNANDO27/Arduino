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
128 64 32 16 8 4 2 1
Binarios                  Decimales
10100000                  160
00000101                  5

01101000                  104
00001101                  13

10010100                  148
00100101                  37
*/

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte1);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  myByte1 = myByte1*2;

  /*for(i = 0; i <= 255; i++){
    digitalWrite(latchPin, LOW);
    myByte1++;
    shiftOut(dataPin, clockPin, LSBFIRST, myByte1);
    digitalWrite(latchPin, HIGH);
    delay(dt);
    Serial.println(myByte1, BIN);
  }*/

  /*digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte1);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte2);
  digitalWrite(latchPin, HIGH);
  delay(dt);*/
}
