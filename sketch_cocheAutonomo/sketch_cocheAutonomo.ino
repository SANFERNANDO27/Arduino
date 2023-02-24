#include <IRremote.hpp>

#include <Servo.h>

// <>

int i;
//infra rojo
int IRpin = 8;

//servomotor
int servoPin = 2;
int servoPos = 90;
int servoPosRecto = 75;
Servo myServo;

//servomotor 2
int servoPin2 = 11;
int servoPos2 = 90;
Servo myServo2;

//motor DC
int speedPin = 3;
int dirPin1 = 4;
int dirPin2 = 5;
int speedMotor = 255;

//motor DC 2
int M2speedPin = 10;
int M2dirPin1 = 9;
int M2dirPin2 = 6;


//sensor
int trigPin = 7;
int echoPin = 12;
int pingTravelTime;

//boton
int pinButton = 8;
int buttonNew;
int buttonOld;
int dt = 100;
int carState;
int carOn = 0;

//direccion
int izq;
int der;
int x = 0;
int dtD = 1200;
int dtDA = 1700;

void setup() {
  Serial.begin(9600);

  //boton
  pinMode(pinButton, INPUT_PULLUP);

  //servo
  myServo.attach(servoPin);

  //servo2
  myServo2.attach(servoPin2);

  //DC
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  //DC2
  pinMode(M2speedPin, OUTPUT);
  pinMode(M2dirPin1, OUTPUT);
  pinMode(M2dirPin2, OUTPUT);

  //sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {

  //servo
  servoPos = servoPosRecto;
  servoPos2 = 90;
  myServo.write(servoPos);
  myServo2.write(servoPos2);

  //sensor
  for(i= 0; i <= 2; i++){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    pingTravelTime = pulseIn(echoPin, HIGH);
    delay(25);
    digitalWrite(trigPin, LOW);
    Serial.println(pingTravelTime);
    }


  //DC
  digitalWrite(dirPin1, 0);
  digitalWrite(dirPin2, 1);
  analogWrite(speedPin, speedMotor);

  //DC 2
  digitalWrite(M2dirPin1, 0);
  digitalWrite(M2dirPin2, 1);
  analogWrite(M2speedPin, speedMotor);


  //programacion
  if(pingTravelTime < 1000 && pingTravelTime > 0){

    analogWrite(speedPin, 0);
    analogWrite(M2speedPin, 0);

    delay(750);
    
    //leer distancia de nuevo
    for(i= 0; i <= 1; i++){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    pingTravelTime = pulseIn(echoPin, HIGH);
    delay(25);
    digitalWrite(trigPin, LOW);
    Serial.println(pingTravelTime);
    }
    //if pared
    if(pingTravelTime < 1000 && pingTravelTime > 0){
    
    //servos
    servoPos2 = 180;
    myServo2.write(servoPos2);
    for(i= 0; i <= 1; i++){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    pingTravelTime = pulseIn(echoPin, HIGH);
    delay(25);
    digitalWrite(trigPin, LOW);
    Serial.println(pingTravelTime);
    }
    izq = pingTravelTime;
    delay(1000);
    servoPos2 = 0;
    myServo2.write(servoPos2);
    for(i= 0; i <= 1; i++){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    pingTravelTime = pulseIn(echoPin, HIGH);
    delay(25);
    digitalWrite(trigPin, LOW);
    Serial.println(pingTravelTime);
    }
    der = pingTravelTime;
    delay(1000);
    //regresar servo 2
    servoPos2 = 90;
    myServo2.write(servoPos2);

    //izq mas distancia
    if(izq > der){
      //girar a la izquierda
      for(i = 0; i < 6; i++){
        //1 

        //DC
        digitalWrite(dirPin1, 1);
        digitalWrite(dirPin2, 0);
        analogWrite(speedPin, speedMotor);

        //DC 2
        digitalWrite(M2dirPin1, 1);
        digitalWrite(M2dirPin2, 0);
        analogWrite(M2speedPin, speedMotor);

        servoPos = 180; //180
        myServo.write(servoPos);
        delay(dtD);

        //2
        
        //DC
        digitalWrite(dirPin1, 0);
        digitalWrite(dirPin2, 1);
        analogWrite(speedPin, speedMotor);

        //DC 2
        digitalWrite(M2dirPin1, 0);
        digitalWrite(M2dirPin2, 1);
        analogWrite(M2speedPin, speedMotor);

        servoPos = 0; //0
        myServo.write(servoPos);
        delay(dtDA);
      }


    //final avanzar en linea recta
    servoPos = servoPosRecto;
      myServo.write(servoPos);
      x = 1;

    }

    //der mas distancia
    if(der>izq){
      //girar a la derecha
      for(i = 0; i < 6; i++){
        //1

        //DC
        digitalWrite(dirPin1, 1);
        digitalWrite(dirPin2, 0);
        analogWrite(speedPin, speedMotor);

        //DC 2
        digitalWrite(M2dirPin1, 1);
        digitalWrite(M2dirPin2, 0);
        analogWrite(M2speedPin, speedMotor);

        servoPos = 0; //0
        myServo.write(servoPos);
        delay(dtD);

        //2

        //DC
        digitalWrite(dirPin1, 0);
        digitalWrite(dirPin2, 1);
        analogWrite(speedPin, speedMotor);

        //DC 2
        digitalWrite(M2dirPin1, 0);
        digitalWrite(M2dirPin2, 1);
        analogWrite(M2speedPin, speedMotor);

        servoPos = 180; //180
        myServo.write(servoPos);
        delay(dtDA);
      }

      //final avanzar en linea recta
      servoPos = servoPosRecto;
      myServo.write(servoPos);
      x = 1;
    }
  }
  }
}
