#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//String data;
//int len;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Utkarsh Kunwar Singh is the freelance IoT Trainer.");
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 16; i++)
  {
    lcd.scrollDisplayLeft();
    delay(1000);
  }
}
