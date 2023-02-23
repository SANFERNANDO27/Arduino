float V2;
int readVal;
int analogPin = A1;
int dt = 300;
int ledPin = 10;

void setup() {
 Serial.begin(9600);
 pinMode(analogPin, INPUT);
 pinMode(ledPin, OUTPUT);

}

void loop() {
  readVal = analogRead(analogPin);
  V2 = (5.*readVal)/1023.;

  if (V2  >= 2.0 && V2 <= 4.0) {
    digitalWrite(ledPin, HIGH);
  }else if (V2 < 2.0 || V2 > 4.0){
    digitalWrite(ledPin, LOW);
  }

  Serial.println(V2);
  delay(dt);

}
