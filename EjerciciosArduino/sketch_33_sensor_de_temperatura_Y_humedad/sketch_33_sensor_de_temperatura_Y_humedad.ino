#include <DHT.h>
#include <DHT_U.h>

#define Type DHT11
int dhtPin = 13;
DHT HT(dhtPin, Type);
int humidity;
float tempC;
float tempF;
int dt = 500;

void setup() {
  Serial.begin(9600);
  HT.begin();
}

void loop() {
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  Serial.print("Humedad: ");
  Serial.print(humidity);
  Serial.print("%");

  Serial.print(" Temperatura: ");
  Serial.print(tempC);

  Serial.print(" Temperatura en F: ");
  Serial.println(tempF);
  delay(dt);
}
