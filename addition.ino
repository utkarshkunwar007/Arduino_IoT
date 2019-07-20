int a;
int b;
int c;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
a=10;
b=20;
c=a+b;
Serial.print("Input A= ");
Serial.println(a);
Serial.print("Input B= ");
Serial.println(b);
Serial.print("\nAddition: ");
Serial.println(c);
delay(5000);
c=b-a;
Serial.print("Substraction: ");
Serial.println(c);
delay(5000);
c=b*a;
Serial.print("Multiplication: ");
Serial.println(c);
delay(5000);
c=b/a;
Serial.print("Division: ");
Serial.println(c);
delay(5000);
}
