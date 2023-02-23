int buzz = 2;
int buttonPin = 4;
int buttonRead;

void setup() {
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  digitalWrite(buzz, LOW);
  
  buttonRead = digitalRead(buttonPin);
  Serial.println(buttonRead);
  delay(100);
  while (buttonRead == 0){
    buttonRead = digitalRead(buttonPin);
    digitalWrite(buzz, HIGH);
    Serial.println(buttonRead);
    delay(100);
  }
}
