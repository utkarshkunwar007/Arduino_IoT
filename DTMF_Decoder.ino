String x, y, z, t, finalstring;
int d0 = 3;
int d1 = 4;
int d2 = 5;
int d3 = 6;
int led = 13;
int number[] = {0101, 1000, 0100, 1100, 0010, 1010, 0110, 1110, 0001, 1001, 1101, 0011}; // 0,1,2,3,4,5,6,7,8,9,*,# respectively

void setup() {
  
  pinMode(d0, INPUT);
  pinMode(d1, INPUT);
  pinMode(d2, INPUT);
  pinMode(d3, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin (9600);
}
void loop() {

  x = digitalRead(d0);
  y = digitalRead(d1);
  z = digitalRead(d2);
  t = digitalRead(d3);

  finalstring = x + y + z + t;

  Serial.print("\n");
  Serial.print(finalstring);
  if (finalstring == "1000")
  {
    digitalWrite(led, HIGH);
  }
  if (finalstring == "0100")
  {
    digitalWrite(led, LOW);
  }
  if (finalstring == "1100")
  {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
  }
  if (finalstring == "0010")
  {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
  }
  delay(1000);
}
