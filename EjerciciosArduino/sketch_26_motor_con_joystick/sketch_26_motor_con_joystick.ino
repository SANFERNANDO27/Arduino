int speedPin = 11;
int dirPin1 = 12;
int dirPin2 = 13;
int speedMotor = 255;
int dt = 100;
int dt2 = 5000;
int yPin = A1;
int yVal;


void setup() {
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(yPin, INPUT);

}

void loop() {
  yVal = analogRead(yPin);
  Serial.println(yVal);  
  digitalWrite(dirPin1, 1);
  digitalWrite(dirPin2, 0);
  analogWrite(speedPin, speedMotor);

  if(yVal > 590){
    speedMotor = map(yVal,590,1023,0,255);
    digitalWrite(dirPin1, 0);
    digitalWrite(dirPin2, 1);
    analogWrite(speedPin, speedMotor);
  }
  if(yVal <= 590){
    speedMotor = map(yVal,590,0,0,255);
    digitalWrite(dirPin1, 1);
    digitalWrite(dirPin2, 0);
    analogWrite(speedPin, speedMotor);
  }
}
