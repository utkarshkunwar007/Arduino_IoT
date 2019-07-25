int sensorPin = A0; // select the input pin for LDR sensor
int sensorValue = 0; // variable to store the value from the LDR sensor

int ledPin = 13; //Pin where my led light is connected

void setup() {
Serial.begin(9600); //sets serial port for communication
pinMode(ledPin, OUTPUT);
}

void loop() {
sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
if(sensorValue < 250)
{
digitalWrite(ledPin, HIGH);
}
delay(500);
if(sensorValue > 100)
{
  digitalWrite(ledPin, LOW);
}
delay(500);
}
