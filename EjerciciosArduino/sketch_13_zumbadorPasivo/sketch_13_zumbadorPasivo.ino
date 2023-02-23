int buzzPin = 4;
float buzzDelay;
int potPin = A0;
float potVal;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(buzzPin, OUTPUT);

}

void loop() {
  potVal = analogRead(potPin);
  buzzDelay = (9940./1023)*potVal + 60;

  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(buzzDelay);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(buzzDelay);

  Serial.println(potVal);

}
