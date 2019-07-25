String value;
void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);    // set the baud rate to 9600, same should be of your Serial Monitor
}

void loop()
{
  if (Serial.available()) {
    value = Serial.readString(); //read the input
    Serial.println(value);
    //Serial.print("\n");
  }
}

