#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); //  

#include <DHT.h>
#include <DHT_U.h>

#define Type DHT11
int dhtPin = 2;
DHT HT(dhtPin, Type);
int humidity;
float temperaturaC;
float temperaturaF;
int dt (500);

void setup() {
  
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  HT.begin();
  lcd.clear();
}

void loop() {
  
  humidity = HT.readHumidity();
  temperaturaC = HT.readTemperature();
  temperaturaF = HT.readTemperature(true);
  
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(5,0);
  lcd.print(temperaturaC);
  lcd.setCursor(10,0);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Humedad:");
  lcd.setCursor(8,1);
  lcd.print(humidity);
  lcd.setCursor(10,1);
  lcd.print("%");
}
