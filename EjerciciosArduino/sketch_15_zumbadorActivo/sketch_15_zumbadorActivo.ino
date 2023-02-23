int buzzPin = 8;
int pot = A0;
int number;
int dt = 500;
String msg1 = "Porfavor introduce tu número";

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(pot, INPUT);

}

void loop() {
  number = analogRead(pot);
  Serial.println(number);
  /*while (Serial.available() == 0){

  }
  number = Serial.parseInt();*/

  while (number > 1000){
    digitalWrite(buzzPin, HIGH);
    number = analogRead(pot);
    Serial.println(number);
  }
  digitalWrite(buzzPin, LOW);

}
