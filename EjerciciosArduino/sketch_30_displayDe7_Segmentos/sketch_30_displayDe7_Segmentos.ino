int latchPin = 8;
int clockPin = 13;
int dataPin = 12;
int btnSPin = 7;
int btnAPin = 6;
int btnSVal;
int btnAVal;
int buttonSOld = 1;
int buttonAOld = 1;
int disNum = 0;
byte numbers[] = {
  0b11111100, //0
  0b01100000, //1
  0b11011010, //2
  0b11110010, //3
  0b01100110, //4
  0b10110110, //5
  0b10111110, //6
  0b11100000, //7
  0b11111110, //8
  0b11110110  //9
};

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(btnSPin, INPUT_PULLUP);
  pinMode(btnAPin, INPUT_PULLUP);

}

void loop() {
  // Sumar y restar
    btnSVal = digitalRead(btnSPin);
    btnAVal = digitalRead(btnAPin);

    if(btnSVal == 0 && buttonSOld == 1){
      if (disNum > 0){
        disNum--;
      }
    }
    if(btnAVal == 0 && buttonAOld == 1){
      if (disNum < 9){
        disNum++;
      }
    }

    buttonSOld = btnSVal;
    buttonAOld = btnAVal;
    Serial.println(disNum); 
  //Gestión del chip shift register y display
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, numbers[disNum]);
    digitalWrite(latchPin, HIGH);
  
}
