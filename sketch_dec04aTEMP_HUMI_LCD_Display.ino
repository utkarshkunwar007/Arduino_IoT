#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{ 
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2); //16 by 2 character display
}

void loop()
{
  delay(2000); //wait a sec (recommended for DHT11)
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humi = ");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("Temp = ");
  lcd.print(t);
}
