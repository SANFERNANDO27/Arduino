int latchPin = 8;
int clockPin = 13;
int dataPin = 12;
byte myByteCircularRight = 0b00010111;
byte myByte2CircularLeft = 0b10010100;
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


10100000                  160
01011111                  95

01101000                  104
10010111                  151
*/

void loop() {
  digitalWrite(latchPin, LOW);
  
  while (myByteCircularRight % 2 == 0){
    myByteCircularRight = myByteCircularRight / 2;
    Serial.println(myByteCircularRight);
  }

  while ((myByte2CircularLeft*2) < 255){
    myByte2CircularLeft = myByte2CircularLeft * 2;
    Serial.println(myByte2CircularLeft);
  }

  shiftOut(dataPin, clockPin, LSBFIRST, myByte2CircularLeft);
  digitalWrite(latchPin, HIGH);
  delay(dt);
  Serial.println(myByte2CircularLeft);

}