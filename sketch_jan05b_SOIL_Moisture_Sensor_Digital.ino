int led_pin = 13;
int sensor_pin = 7;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(sensor_pin) == HIGH) {
    digitalWrite(led_pin, HIGH);
    Serial.print(sensor_pin);
  } else {
    digitalWrite(led_pin, LOW);
    Serial.print(sensor_pin);
    delay(1000);
  }
}

