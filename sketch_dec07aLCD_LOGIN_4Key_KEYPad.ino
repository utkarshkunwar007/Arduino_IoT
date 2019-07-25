#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int ok,cancel,up,down;
char bufferT[17];
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("Hello Utkarsh");
lcd.print("Login using KeyPad!");
lcd.setCursor(0,1);
delay(2000);

pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
ok=digitalRead(A0);
cancel=digitalRead(A1);
up=digitalRead(A2);
down=digitalRead(A3);
}
