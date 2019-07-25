void setup() {
  pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
}

void loop() {

  for (int i = 0; i <= 255; i++)
  {
    analogWrite(3, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(5, i);
    delay(10);
  }
  delay(1000);
 for (int i = 0; i <= 255; i++)
  {
    analogWrite(5, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(3, i);
    delay(10);
  }
   delay(1000);
}
