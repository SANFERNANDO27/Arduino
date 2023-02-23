int dt = 500;
int rad = 3;
float area;
float Pi = 3.1415;
String operacion = "El area de un circulo con area de ";
String operacionM2 = " es de: ";

void setup() {
 Serial.begin(9600);

}

void loop() {

  area = Pi*rad*rad;

  Serial.print(operacion);
  Serial.print(rad);
  Serial.print(operacionM2);
  Serial.println(area);
  delay(dt);

  rad++;

}
