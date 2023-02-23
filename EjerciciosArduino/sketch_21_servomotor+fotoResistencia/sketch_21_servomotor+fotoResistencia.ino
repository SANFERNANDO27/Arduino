#include <Servo.h>

int servoPin = 9;
int servoPos = 90;
int res = A0;
int resVal;
Servo myServo;
int resValMap;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
  pinMode(res, INPUT);

}

void loop() {
  resVal = analogRead(res);
  servoPos = (170./680.)*(resVal-320.);
  myServo.write(servoPos);
  Serial.println(servoPos);

}
