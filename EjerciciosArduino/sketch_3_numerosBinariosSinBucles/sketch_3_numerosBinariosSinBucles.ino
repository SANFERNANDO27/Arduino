int ledPin1 = 5;
int ledPin2 = 4;
int ledPin3 = 3;
int ledPin4 = 2;
int numero = 0;
int i = 200;

void setup() {
pinMode(ledPin1,OUTPUT);
pinMode(ledPin2,OUTPUT);
pinMode(ledPin3,OUTPUT);
pinMode(ledPin4,OUTPUT);
}

void loop() {
  if (numero > 15){
    numero = 0;
    delay(1000);
  }else if (numero >= 0){
    numero++;
    delay(1000);
  }

  if (numero == 0){
    digitalWrite(ledPin1,0);
    digitalWrite(ledPin2,0);
    digitalWrite(ledPin3,0);
    digitalWrite(ledPin4,0);
  }else if (numero == 1){
    digitalWrite(ledPin1,1);
    digitalWrite(ledPin2,0);
    digitalWrite(ledPin3,0);
    digitalWrite(ledPin4,0);
  }else if (numero == 2){
    digitalWrite(ledPin1,0);
    digitalWrite(ledPin2,1);
    digitalWrite(ledPin3,0);
    digitalWrite(ledPin4,0);
  }else if (numero == 3){
    digitalWrite(ledPin1,1);
    digitalWrite(ledPin2,1);
    digitalWrite(ledPin3,0);
    digitalWrite(ledPin4,0);
  }else if (numero == 4){
    digitalWrite(ledPin1,0);
    digitalWrite(ledPin2,0);
    digitalWrite(ledPin3,1);
    digitalWrite(ledPin4,0);
  }else if (numero == 5){
    digitalWrite(ledPin1,1);
    digitalWrite(ledPin2,0);
    digitalWrite(ledPin3,1);
    digitalWrite(ledPin4,0);
  }else if (numero == 6){
    digitalWrite(ledPin1,0);
    digitalWrite(ledPin2,1);
    digitalWrite(ledPin3,1);
    digitalWrite(ledPin4,0);
  }else if (numero == 7){
    digitalWrite(ledPin1,1);
    digitalWrite(ledPin2,1);
    digitalWrite(ledPin3,1);
    digitalWrite(ledPin4,0);
  }else if (numero == 8){
    digitalWrite(ledPin1,0);
    digitalWrite(ledPin2,0);
    digitalWrite(ledPin3,0);
    digitalWrite(ledPin4,1);
  }else if (numero == 9){
    digitalWrite(ledPin1,1);
    digitalWrite(ledPin2,0);
    digitalWrite(ledPin3,0);
    digitalWrite(ledPin4,1);
  }else if (numero == 10){
    digitalWrite(ledPin1,0);
    digitalWrite(ledPin2,1);
    digitalWrite(ledPin3,0);
    digitalWrite(ledPin4,1);
  }else if (numero == 11){
    digitalWrite(ledPin1,1);
    digitalWrite(ledPin2,1);
    digitalWrite(ledPin3,0);
    digitalWrite(ledPin4,1);
  }else if (numero == 12){
    digitalWrite(ledPin1,0);
    digitalWrite(ledPin2,0);
    digitalWrite(ledPin3,1);
    digitalWrite(ledPin4,1);
  }else if (numero == 13){
    digitalWrite(ledPin1,1);
    digitalWrite(ledPin2,0);
    digitalWrite(ledPin3,1);
    digitalWrite(ledPin4,1);
  }else if (numero == 14){
    digitalWrite(ledPin1,0);
    digitalWrite(ledPin2,1);
    digitalWrite(ledPin3,1);
    digitalWrite(ledPin4,1);
  }else if (numero == 15){
    digitalWrite(ledPin1,1);
    digitalWrite(ledPin2,1);
    digitalWrite(ledPin3,1);
    digitalWrite(ledPin4,1);
  }
}

