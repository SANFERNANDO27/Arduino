int zPin = 2;
int lightPin = A0;
int lightVal;
int dt = 100;
int dtZ = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(zPin, OUTPUT);

}

void loop() {
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);

  while (lightVal > 600){
    lightVal = analogRead(lightPin);
    Serial.println(lightVal);
    delay(dt);
    digitalWrite(zPin, 1);
    delayMicroseconds(dtZ);
    digitalWrite(zPin, 0);
  }

  digitalWrite(zPin, 0);
}
