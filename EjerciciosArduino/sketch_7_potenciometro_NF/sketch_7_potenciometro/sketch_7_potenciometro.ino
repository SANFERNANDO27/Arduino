float vOut;
float vRead = A0;
int dt = 100;
float analogVal;

void setup() {
  pinMode(vRead, INPUT);
  Serial.begin(9600);
}

void loop() {
 analogVal = analogRead(vRead);
 vOut = (5.*analogVal)/1023.;
 Serial.print("El voltaje actual es: ");
 Serial.print(vOut);
 Serial.println(" Voltios");
 delay(dt); 

}
