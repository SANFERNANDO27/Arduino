/*int blinkTimes;
int ledPin = 8;
int dt = 500;
int i;
int myNumber;
String msg1 = "Por favor ingresa el numero de parpadeos: ";

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Serial.println(msg1);
  while (Serial.available() == 0) {
  }
  blinkTimes = Serial.parseInt();

  for (i = 1; i <= blinkTimes; i++) {
    digitalWrite(ledPin, HIGH);
    delay(dt);
    digitalWrite(ledPin, LOW);
    delay(dt);
  }
}*/

// A = pi * Radio al 2

float radius;
float pi = 3.1415;
float area;
int dt = 500;
String msg1 = "Escribe el radio de tu circunferencia ";
String msg2 = "El area de tu circunferencia es de: ";

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(msg1);
  while (Serial.available() == 0) {

  }
  radius = Serial.parseFloat();
  area = pi*radius*radius;
  Serial.print(msg2);
  Serial.print(area);
  Serial.println("");
}

