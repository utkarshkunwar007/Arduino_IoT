#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2); // RS,E,D4,D5,D6,D7
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("Hello, World! ");
lcd.setCursor(0,1);
lcd.print("Utkarsh Kunwar ");
}
