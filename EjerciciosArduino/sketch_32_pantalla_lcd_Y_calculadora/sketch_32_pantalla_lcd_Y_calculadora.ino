#include <LiquidCrystal.h>

float n1;
float n2;
float r;
String operador;

int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
int numero = 0;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Elige el numero1");
  while (Serial.available() == 0){

  }
  n1 = Serial.parseFloat();
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Operacion +-*/");
  while (Serial.available() == 0){

  }
  operador = Serial.readString();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Elige el numero2");
  while (Serial.available() == 0){

  }
  n2 = Serial.parseFloat();

  if (operador == "+"){
    r = n1 + n2;
  } else if (operador == "-"){
    r = n1 - n2;
  } else if (operador == "*"){
    r = n1 * n2;
  }else if (operador == "/"){
    r = n1 / n2;
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(n1);
  lcd.print(operador);
  lcd.print(n2);
  lcd.print(" =");
  lcd.setCursor(0,1);
  lcd.print(r);
  delay(5000);

}
