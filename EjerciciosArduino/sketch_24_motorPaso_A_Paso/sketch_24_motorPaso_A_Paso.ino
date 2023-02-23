//stepper
  #include <Stepper.h>
  int sttepperSpeed = 50;
  Stepper myStepper(2048,8,10,9,11);

//boton
  int btn1pin = 12;
  int btn2pin = 13;

  int btn1Val;
  int btn1Old;

  int btn2Val;
  int btn2Old;

void setup() {
  myStepper.setSpeed(10);
  pinMode(btn1pin, INPUT);
  pinMode(btn2pin, INPUT);
  Serial.begin(9600);

}

void loop() {
  
  btn1Val = digitalRead(btn1pin);
  btn2Val = digitalRead(btn2pin);
  Serial.print("btn1Val ");
  Serial.print(btn1Val);
  Serial.print(" btn2Val ");
  Serial.println(btn2Val);

  if(btn1Val == 0){
    myStepper.step(-sttepperSpeed);
  }else if(btn2Val == 0){
    myStepper.step(sttepperSpeed);
  }else{
    myStepper.step(0);
  }

}
