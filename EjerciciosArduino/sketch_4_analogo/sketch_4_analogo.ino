int led = 9;
int brightness1 = 0;
int brightness2 = 125;
int brightness3 = 255;
int DT = 500;

void setup() {
  pinMode(led, OUTPUT);

}

void loop() {
 analogWrite(led, brightness1);
 delay(DT);
 analogWrite(led, brightness2);
 delay(DT);
 analogWrite(led, brightness3);
 delay(DT);
 

}
