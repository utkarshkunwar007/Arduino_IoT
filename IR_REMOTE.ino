//#include <IRremote.h>
//int RECV_PIN = 11;
//IRrecv irrecv(RECV_PIN);
//decode_results results;
//
//void setup()
//{
//  Serial.begin(9600);
//  irrecv.enableIRIn(); // Start the receiver
//}
//
//void loop()
//{
//  if (irrecv.decode(&results))
//    {
//     //Serial.println(results.value, HEX);
//     Serial.println(results.value);
//     irrecv.resume(); // Receive the next value
//    }
//}

#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redPin = 10;
const int greenPin = 11;


void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0xFF38C7: //Keypad button "5"
          digitalWrite(redPin, HIGH);
          delay(2000);
          digitalWrite(redPin, LOW);
          }

        switch(results.value){
          case 0xFF18E7: //Keypad button "2"
          digitalWrite(greenPin, HIGH);
          delay(2000);
          digitalWrite(greenPin, LOW);
          }

        irrecv.resume(); 
    }
}
//
//#include <IRremote.h>
//
//const int RECV_PIN = 7;
//IRrecv irrecv(RECV_PIN);
//decode_results results;
//unsigned long key_value = 0;
//
//void setup(){
//  Serial.begin(9600);
//  irrecv.enableIRIn();
//  irrecv.blink13(true);
//}
//
//void loop(){
//  if (irrecv.decode(&results)){
// 
//        if (results.value == 0XFFFFFFFF)
//          results.value = key_value;
//
//        switch(results.value){
//          case 0xFFA25D:
//          Serial.println("CH-");
//          break;
//          case 0xFF629D:
//          Serial.println("CH");
//          break;
//          case 0xFFE21D:
//          Serial.println("CH+");
//          break;
//          case 0xFF22DD:
//          Serial.println("|<<");
//          break;
//          case 0xFF02FD:
//          Serial.println(">>|");
//          break ;  
//          case 0xFFC23D:
//          Serial.println(">|");
//          break ;               
//          case 0xFFE01F:
//          Serial.println("-");
//          break ;  
//          case 0xFFA857:
//          Serial.println("+");
//          break ;  
//          case 0xFF906F:
//          Serial.println("EQ");
//          break ;  
//          case 0xFF6897:
//          Serial.println("0");
//          break ;  
//          case 0xFF9867:
//          Serial.println("100+");
//          break ;
//          case 0xFFB04F:
//          Serial.println("200+");
//          break ;
//          case 0xFF30CF:
//          Serial.println("1");
//          break ;
//          case 0xFF18E7:
//          Serial.println("2");
//          break ;
//          case 0xFF7A85:
//          Serial.println("3");
//          break ;
//          case 0xFF10EF:
//          Serial.println("4");
//          break ;
//          case 0xFF38C7:
//          Serial.println("5");
//          break ;
//          case 0xFF5AA5:
//          Serial.println("6");
//          break ;
//          case 0xFF42BD:
//          Serial.println("7");
//          break ;
//          case 0xFF4AB5:
//          Serial.println("8");
//          break ;
//          case 0xFF52AD:
//          Serial.println("9");
//          break ;      
//        }
//        key_value = results.value;
//        irrecv.resume(); 
//  }
//}

