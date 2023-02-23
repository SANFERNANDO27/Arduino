/*int pinButton = 8;
int buttonVal;
int dt = 100;

void setup() {
  pinMode(pinButton, INPUT);
  digitalWrite(pinButton, HIGH);
  Serial.begin(9600);
}

void loop() {
  buttonVal = digitalRead(pinButton);
  Serial.println(buttonVal);
  delay(dt);

}*/
int pinButton = 8;
int buttonVal;
int dt = 100;

void setup() {
  pinMode(pinButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  buttonVal = digitalRead(pinButton);
  Serial.println(buttonVal);
  delay(dt);

}