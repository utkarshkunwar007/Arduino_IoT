#include <SoftwareSerial.h>
#include <espduino.h>
#include <rest.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

SoftwareSerial espPort(10, 11); // RX, TX
ESP esp(&espPort, &Serial, 9);
REST rest(&esp);
boolean wifiConnected = false;
const int ESP8266_CHPD = 9;
char response[266];
char buff[64];


void wifiCb(void* response)
{
  uint32_t status;
  RESPONSE res(response);

  if (res.getArgc() == 1) {
    res.popArgs((uint8_t*)&status, 4);
    if (status == STATION_GOT_IP) {
      Serial.println("WIFI CONNECTED");
      wifiConnected = true;
    } else {
      wifiConnected = false;
    }
  }
}

void setup() {
  Serial.begin(19200);
  espPort.begin(19200);
  esp.enable();
  delay(500);
  esp.reset();
  delay(500);
  while (!esp.ready());

  Serial.println("ARDUINO: setup rest client");
  if (!rest.begin("api.thingspeak.com")) {           // write your API Url here
    //if(!rest.begin("kunwarrestapi.azurewebsites.net")) {
    Serial.println("ARDUINO: failed to setup rest client");
    while (1);
  }

  /*setup wifi*/
  Serial.println("ARDUINO: setup wifi");
  esp.wifiCb.attach(&wifiCb);
  esp.wifiConnect("SSID", "Password");         // SSID and Password of your wifi hotspot respectively
  Serial.println("ARDUINO: system started");
  dht.begin();
}

void loop() {

  esp.process();
  char str_hum[6], str_temp[6];

  if (wifiConnected) {
    dtostrf(dht.readHumidity(), 4, 2, str_hum);
    dtostrf(dht.readTemperature(), 4, 2, str_temp);
    //sprintf(buff, "/update?api_key=0RELCKCC6A6LAJ0V&field1=%s&field2=%s", str_hum, str_temp);  // in case of thingspeak.com change API key here. 
    //sprintf(buff, "/temps?temp=%s&hum=%s", str_temp, str_hum);                                 // in case your own
    Serial.println(buff);
    rest.get((const char*)buff);
    Serial.println("ARDUINO: send Update Data");
    delay(5000);
  } //if WifiConnected

}
