float potVal;
int analogPin = A1;
int dt = 300;
int ledPin = 10;
int light;

void setup() {
 Serial.begin(9600);
 pinMode(analogPin, INPUT);
 pinMode(ledPin, OUTPUT);

}

void loop() {
  potVal = analogRead(analogPin);
  Serial.println(potVal);
  Serial.println(light);
  light = map(potVal,0,1023,0,255);
  analogWrite(ledPin, light);
  delay(dt);

}
