#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>

#define Type DHT11
int dhtPin = 13;
DHT HT(dhtPin, Type);
int humidity;
float tempC;
float tempF;
float temp;

int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

int dt = 400;
int buttonPin = 7;
int buttonOld = 1;
int buttonNew;
int tempFState = 0;
int x = 0;
String U = "C";

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
void setup() {
  lcd.begin(16, 2);
  HT.begin();
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  while (tempFState == 0){
    humidity = HT.readHumidity();
    tempC = HT.readTemperature();
    tempF = HT.readTemperature(true);
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print(U);
    lcd.setCursor(0,1);
    lcd.print("Humedad: ");
    lcd.print(humidity);
    lcd.print("%");
    buttonNew = digitalRead(buttonPin);
    Serial.println(buttonNew);
    if(buttonNew == 0 && buttonOld == 1){
        U = "F";
        tempFState = 1;
    }
    buttonOld = buttonNew;

    delay(dt);
    lcd.clear();
    }
  while (tempFState == 1){
    humidity = HT.readHumidity();
    tempC = HT.readTemperature();
    tempF = HT.readTemperature(true);
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(tempF);
    lcd.print(U);
    lcd.setCursor(0,1);
    lcd.print("Humedad: ");
    lcd.print(humidity);
    lcd.print("%");
    buttonNew = digitalRead(buttonPin);
    Serial.println(buttonNew);
    if(buttonNew == 0 && buttonOld == 1){
        U = "C";
        tempFState = 0;

    }
    buttonOld = buttonNew;

    delay(dt);
    lcd.clear();
    }

}
