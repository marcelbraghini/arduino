#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Inicializando a aplicação...!"));

  dht.begin();
  lcd.begin ();
}

void loop() {
  delay(2000);
  
  float humidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(humidade) || isnan(temperatura)) {
    Serial.println(F("Falha de leitura do sensor DHT!"));
    return;
  }

  Serial.print(F("Umidade: "));
  Serial.print(humidade);
  Serial.print(F("% Temperatura: "));
  Serial.print(temperatura);
  Serial.print(F("°C "));

  lcd.setBacklight(HIGH);

  //Umidade do AR
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Umidade do AR: "));
  lcd.setCursor(0, 1);
  lcd.print(humidade);
  lcd.setCursor(5, 1);
  lcd.print(F(" %"));
  delay(5000);

  //Temperatura:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Temperatura: "));
  lcd.setCursor(0, 1);
  lcd.print(temperatura);
  lcd.setCursor(5, 1);
  lcd.write(32);  // Caracter espaço
  lcd.write(223); // Caracter °
  lcd.print(F("C"));
  delay(2000);

  lcd.clear();
  lcd.setBacklight(LOW);

  delay(3000);
}
