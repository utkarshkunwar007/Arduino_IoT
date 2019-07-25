#include "DHT.h"
#define DHTPIN 2 // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Test!");
  dht.begin();
}

void loop() {  
  delay(2000); // Wait a few seconds between measurements.
  float h = dht.readHumidity();  //read humidity
  float t = dht.readTemperature();  //read temperature
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  //Serial.print(1.8*t+32);
  //Serial.print((float)round(1.8*t+32));
  //Serial.println(" *F");
}
