#include <Servo.h>

int servoPin = 11;
int servoPos = 0;
int pot = A2;
int potVal;
Servo myServo;
int potValMap;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);

}

void loop() {
  //potVal = analogRead(pot);
  //potValMap = map(potVal,0,1023,0,170);
  //servoPos = potValMap;
  myServo.write(servoPos);
  //Serial.println(potValMap);

}
