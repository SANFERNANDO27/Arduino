int redColor = 8;
int greenColor = 9;
int blueColor = 10;
String color;
String msg1 = "Que color quieres prender?";

void setup() {
  Serial.begin(9600);
  pinMode(redColor, OUTPUT);
  pinMode(greenColor, OUTPUT);
  pinMode(blueColor, OUTPUT);

  digitalWrite(redColor, HIGH);
  digitalWrite(greenColor, HIGH);
  digitalWrite(blueColor, HIGH);

}

void loop() {
  Serial.println(msg1);
  color = Serial.readString();
  while (Serial.available() == 0) {

  }

  if (color == "rojo" || color == "ROJO") {
    digitalWrite(redColor, LOW);
    digitalWrite(greenColor, HIGH);
    digitalWrite(blueColor, HIGH);
  }else if (color == "verde" || color == "VERDE") {
    digitalWrite(redColor, HIGH);
    digitalWrite(greenColor, LOW);
    digitalWrite(blueColor, HIGH);
  }else if (color == "azul" || color == "AZUL") {
    digitalWrite(redColor, HIGH);
    digitalWrite(greenColor, HIGH);
    digitalWrite(blueColor, LOW);
  }else if (color == "turqueza" || color == "TURQUEZA") {
    digitalWrite(redColor, HIGH);
    digitalWrite(greenColor, LOW);
    digitalWrite(blueColor, LOW);
  } else{
    Serial.println("Selecciona un color valido");
    digitalWrite(redColor, HIGH);
    analogWrite(greenColor, 0);
    digitalWrite(blueColor, HIGH);
  }

}
