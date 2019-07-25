// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 7; 
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   pinMode(13, OUTPUT);
}
void loop(){ 
   // Make servo go to 0 degrees 
   Servo1.write(0); 
   delay(1000); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
   //Servo1.write(180);
   digitalWrite(13, HIGH); 
   delay(1000); 
   //Servo1.write(360);
   digitalWrite(13, LOW); 
   delay(1000);
}
