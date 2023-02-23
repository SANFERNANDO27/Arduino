int yellowPin = 12;
int redPin = 13;
int dt = 500;
int yellow = 2;
int red = 4;
int i;


void setup() {
  pinMode(yellowPin,OUTPUT);
  pinMode(redPin,OUTPUT);

}

void loop() {

  for (i = 0; i <= yellow; i++){
    digitalWrite(yellowPin,HIGH);
    delay(dt);
    digitalWrite(yellowPin,LOW);
    delay(dt);

  }

  for (i = 0; i <= red; i++){
    digitalWrite(redPin,HIGH);
    delay(dt);
    digitalWrite(redPin,LOW);
    delay(dt);

  }

}
