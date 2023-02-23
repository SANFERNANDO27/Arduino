int trigPin = 12;
int echoPin = 11;
int pingTravelTime;
int buzzPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(buzzPin, LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  pingTravelTime = pulseIn(echoPin, HIGH);
  delay(25);
  digitalWrite(trigPin, LOW);
  Serial.println(pingTravelTime);

  while(pingTravelTime < 19000){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    pingTravelTime = pulseIn(echoPin, HIGH);
    delay(25);
    digitalWrite(trigPin, LOW);
    Serial.println(pingTravelTime);

    digitalWrite(buzzPin, HIGH);
  }
}
