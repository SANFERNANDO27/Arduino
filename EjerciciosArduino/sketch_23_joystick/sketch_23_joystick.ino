int xPin = A0;
int yPin = A1;
int buttonPin = 7;
int buttonVal;
int buttonOld = 1;
int buzzPin = 8;
int xVal;
int yVal;
int dt = 100;
int buzzState = 0;

void setup() {
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(buzzPin, LOW);
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  buttonVal = digitalRead(buttonPin);
  Serial.print("Valor de X = ");
  Serial.print(xVal);
  Serial.print(" Valor de Y = ");
  Serial.print(yVal);
  Serial.print(" Valor de botón = ");
  Serial.println(buttonVal);
  delay(dt);

  while (buttonVal == 0){
    digitalWrite(buzzPin, HIGH);
    xVal = analogRead(xPin);
    yVal = analogRead(yPin);
    buttonVal = digitalRead(buttonPin);
    Serial.print("Valor de X = ");
    Serial.print(xVal);
    Serial.print(" Valor de Y = ");
    Serial.print(yVal);
    Serial.print(" Valor de botón = ");
    Serial.println(buttonVal);
    delay(dt);
  }

  /*if(buttonVal == 0 && buttonOld == 1){
   if (buzzState == 0){
     digitalWrite(buzzPin, 1);
     buzzState = 1;
    } else {
      digitalWrite(buzzPin, 0);
      buzzState = 0;
    }
  }
    buttonOld = buttonVal;*/
  
}


