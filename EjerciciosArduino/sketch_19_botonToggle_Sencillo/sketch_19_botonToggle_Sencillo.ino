int buzzPin = 8;
int buttonPin = A0;
int buzzState = 0;
int buttonOld = 1;
int buttonNew;
int dt = 100;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
 buttonNew = digitalRead(buttonPin);
 delay(dt);
 if(buttonNew == 0 && buttonOld == 1){
   if (buzzState == 0){
     digitalWrite(buzzPin, 1);
     buzzState = 1;
   } else {
     digitalWrite(buzzPin, 0);
     buzzState = 0;
   }
 }
 buttonOld = buttonNew;
}
