/*String myName;
String msg1 = "Escribe tu nombre";
String msg2 = "Hola ";
String msg3 = ", Bienvenido ";

void setup() {
  Serial.begin(115200);

}

void loop() {
  Serial.println(msg1);
  while (Serial.available() == 0){

  }

  myName = Serial.readString();
  Serial.print(msg2);
  Serial.print(myName);
  Serial.println(msg3);

}*/
int redPin = 13;
int bluePin = 11;
int yellowPin = 12;
int ledColor;
String red = "rojo";
String blue = "azul";
String yellow = "amarillo";

String msg1 = "Que color quieres prender?";

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  Serial.println(msg1);
  while (Serial.available() == 0){
    
  }
  ledColor = Serial.parseInt();

  switch(ledColor){
    case 1:
    Serial.println("El led rojo esta prendido");
    digitalWrite(redPin, HIGH);
    digitalWrite(bluePin, LOW);
    digitalWrite(yellowPin, LOW);
    break;

    case 2:
    Serial.println("El led azul esta prendido");
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, HIGH);
    digitalWrite(yellowPin, LOW);
    break;
    case 3:
    Serial.println("El led amarillo esta prendido");
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    digitalWrite(yellowPin, HIGH);
    break;

    default:
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
      Serial.println("El valor que intentas ingresar no existe.");
      
  }

  /*ledColor = Serial.readSritng();

  if (ledColor == red || ledColor == "ROJO"){
    Serial.println("El led rojo esta prendido");
    digitalWrite(redPin, HIGH);

    digitalWrite(bluePin, LOW);
    digitalWrite(yellowPin, LOW);
  }else if (ledColor == blue || ledColor == "AZUL"){
    Serial.println("El led azul esta prendido");
    digitalWrite(bluePin, HIGH);

    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
  } else if (ledColor == yellow || ledColor == "AMARILLO"){
    Serial.println("El led amarillo esta prendido");
    digitalWrite(yellowPin, HIGH);

    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
  }else{
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    Serial.println("El valor que intentas ingresar no existe.");
  }*/

  
}


