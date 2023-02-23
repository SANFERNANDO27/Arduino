int lightVal;
float delayTime;
int lightPin = A0;
int buzzPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(lightPin, INPUT);

}

void loop() {
  lightVal = analogRead(lightPin);
  delayTime = (9./450.)*(lightVal-270.)+1;
  Serial.println(delayTime);

  //Sonido del buzzer Pasivo
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(delayTime);
}
