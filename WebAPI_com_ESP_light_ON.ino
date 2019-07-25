#include <SoftwareSerial.h>
#include <espduino.h>
#include <rest.h>


SoftwareSerial espPort(10, 11); // RX, TX
ESP esp(&espPort, &Serial, 9);
REST rest(&esp);
boolean wifiConnected = false;

const int ESP8266_CHPD = 9;
char response[266];
char buff[64];

void(* resetFunc) (void) = 0;                          //declare reset function at address 0


void clearBuffer(void) {
  for (int i = 0; i < 266; i++ ) {
    response[i] = 0;
  }
}

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
  pinMode(13, OUTPUT);
  esp.enable();
  delay(500);
  esp.reset();
  delay(500);
  while (!esp.ready());

  Serial.println("ARDUINO: setup rest client");
  if (!rest.begin("nitinrestapi.azurewebsites.net")) { //  your API url here.
    Serial.println("ARDUINO: failed to setup rest client");
    while (1);
  }

  /*setup wifi*/
  Serial.println("ARDUINO: setup wifi");
  esp.wifiCb.attach(&wifiCb);

  esp.wifiConnect("SSID", "password"); // your wifi ssid and password
  Serial.println("ARDUINO: system started");


}

void loop() {

  esp.process();
  if (wifiConnected) {
    sprintf(buff, "/api/light");
    //Serial.println(buff);
    rest.get((const char*)buff);
    clearBuffer();
    if (rest.getResponse(response, 266) == HTTP_STATUS_OK) {
      String str(response);
      if (str == "true")
      {
        Serial.println("On");
        digitalWrite(13, HIGH);
      }
      else
      {
        Serial.println("Off ");
        digitalWrite(13, LOW);

      }
    }
    else {

    }
    delay(1000);
  }
}
