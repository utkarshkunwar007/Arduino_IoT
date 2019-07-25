String data;
int pin = 12;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    data = Serial.readString();
    data.trim();
    Serial.println("Data is : " + data);
    if (data == "on")
    {
      digitalWrite(pin, HIGH);
      Serial.println("LED ON");
    }
    if (data == "off")
    {
      digitalWrite(pin, LOW);
      Serial.println("LED OFF");
    }
    if ((data != "on") && (data != "off"))
    {
      digitalWrite(pin, LOW);
      Serial.println("UnKnown Command");
    }
  }
}
