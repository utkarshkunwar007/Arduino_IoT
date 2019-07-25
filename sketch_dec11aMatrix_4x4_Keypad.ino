#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
}; // pins respectively of 4x4 matric keypad are (8,7,6,5,4,3,2,1)

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad (8,7,6,5) in arduino gpio pins (5,4,3,2)
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad (4,3,2,1)in arduino gpio pins (9,8,7,6)

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
   Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}

