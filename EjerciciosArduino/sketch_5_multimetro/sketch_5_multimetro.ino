int analogPin = A0;
float V2;
int delayT = 500;
int analogVal;

void setup() {
pinMode(analogPin,INPUT);
Serial.begin(9600);

}

void loop() {
  analogVal = analogRead(analogPin);
  V2 = (5.* analogVal)/1023.;
  Serial.println(V2);
  delay(delayT);
}
