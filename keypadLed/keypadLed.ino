#include <Keypad.h>

char*secretCode = "1234A";
int position = 0;
int wrong = 0;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins,colPins, ROWS, COLS);
int led_pin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  setLocked(true);
}

void loop() {
  char key = keypad.getKey();
  Serial.print(key);
  if(key == secretCode[position]) {
    position++;
    wrong=0;
  } else if(key != secretCode[position]) {
    position=0;
    setLocked(true);
    wrong++;
  }
  if(position==5) {
    setLocked(false);
  }

  delay(100);
}
  void setLocked(int locked){
    if(locked) {  // locked == true
      digitalWrite(led_pin,false);
    } else {    // locked == false
      digitalWrite(led_pin,true);
    }
}
