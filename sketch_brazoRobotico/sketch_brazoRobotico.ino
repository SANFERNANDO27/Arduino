#include <Servo.h>
#include <Stepper.h>

//stepper
  int sttepperSpeed = 50;
  Stepper myStepper(2048,8,10,9,11);

//botones
  int btn1pin = 12;
  int btn2pin = 4;

  int btn1Val;
  int btn2Val;

//joystick
int VRX = A0;
int VRY = A1;
int switchBtn = 7;

int xVal;
int yVal;
int switchVal;
int pendienteX;
int pendienteY;
float velMax = 5;

//servo
int servoPin = 2;
int servoPos = 120;
int servoPosX = 120;
Servo Servo1;

//servo2
int servo2Pin = 3;
int servo2Pos = 100;
int servoPosY = 100;
Servo Servo2;


//servo4
int servo4Pin = 5;
int servo4Pos = 90;
int grippAbierta = 90;
int grippCerrada = 0;
Servo Servo4;

//boton
int grippState = 0;
int switchOld = 1;
int switchNew;
int dt = 100;

void setup() {
  //steper y botones
  myStepper.setSpeed(10);
  pinMode(btn1pin, INPUT);
  pinMode(btn2pin, INPUT);

  digitalWrite(btn1pin, HIGH);
  digitalWrite(btn2pin, HIGH);
  Serial.begin(9600);

  //joystick
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(switchBtn, INPUT);
  digitalWrite(switchBtn, HIGH);
  Serial.begin(9600);

  //servo
  Servo1.attach(servoPin);
  Servo2.attach(servo2Pin);
  Servo4.attach(servo4Pin);


}

void loop() {
  
  //stepper gestion
  btn1Val = digitalRead(btn1pin);
  btn2Val = digitalRead(btn2pin);

  if(btn1Val == 0){
    myStepper.step(-sttepperSpeed);
  }else if(btn2Val == 0){
    myStepper.step(sttepperSpeed);
  }else{
    myStepper.step(0);
  }

  //joystick
  xVal = analogRead(VRX);
  yVal = analogRead(VRY);
  switchVal = digitalRead(switchBtn);

  //pendiente
  pendienteX = (velMax/503.)*(xVal-520.);
  pendienteY = (velMax/-503)*(yVal-503);

  //servo1
  servoPosX = servoPos-pendienteX;
  if(servoPosX >= 180){
    servoPosX = 180;
  }else if(servoPosX <= 0){
    servoPosX = 0;
  }

  servoPos = servoPosX;
  Servo1.write(servoPos);

  //servo2
  servoPosY = servo2Pos-pendienteY;
  if(servoPosY >= 180){
    servoPosY = 180;
  }else if(servoPosY <= 0){
    servoPosY = 0;
  }

  servo2Pos = servoPosY;
  Servo2.write(servo2Pos);


  //servo4
  switchNew = digitalRead(switchBtn);
  if(switchNew == 0 && switchOld == 1){
    if (grippState == 0){
      //cerrar pinza

      servo4Pos = grippCerrada;
      Servo4.write(servo4Pos);
      grippState = 1;
    } else {
      //abrir pinza

      servo4Pos = grippAbierta;
      Servo4.write(servo4Pos);
      grippState = 0;
    }
  }
  switchOld = switchNew;

  //pruebas
  Serial.print("xVal: ");
  Serial.print(xVal);

  Serial.print(" yVal: ");
  Serial.print(yVal);

  Serial.print(" switchVal: ");
  Serial.print(grippState);

  Serial.print(" btn1Val: ");
  Serial.print(btn1Val);

  Serial.print(" btn2Val: ");
  Serial.println(btn2Val);

}