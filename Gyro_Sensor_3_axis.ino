
int x = 0;
int y = 0;
int z = 0;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop() {

  x = analogRead(A0);
  y = analogRead(A1);
  z = analogRead(A2);
  Serial.print("x=");
  Serial.print(x);
  Serial.print(", y=");
  Serial.print(y);
  Serial.print(", z=");
  Serial.print(z);
  Serial.print("\n\n");
  delay(2000);
}
