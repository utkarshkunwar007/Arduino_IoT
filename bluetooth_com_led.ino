#include<SoftwareSerial.h>

SoftwareSerial bt(10,11); // (RX,TX) or if connecting to Rx,Tx pin then always connect cross.(RXD-->Tx && TXD-->Rx)
String data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bt.available())
  {
    data = bt.readString();
    Serial.println(data);
    if (data == "on")
      digitalWrite(13, HIGH);
    if (data == "of" || data == "off")
      digitalWrite(13, LOW);
  }
}
