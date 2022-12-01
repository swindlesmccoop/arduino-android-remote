#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  switch (customKey) {
    case '2': Keyboard.press(KEY_UP_ARROW); Serial.println("Up arrow"); Keyboard.release(KEY_UP_ARROW); break;
    case '8': Keyboard.press(KEY_DOWN_ARROW); Serial.println("Down arrow"); Keyboard.release(KEY_DOWN_ARROW); break;
    case '4': Keyboard.press(KEY_LEFT_ARROW); Serial.println("Left arrow"); Keyboard.release(KEY_LEFT_ARROW); break;
    case '6': Keyboard.press(KEY_RIGHT_ARROW); Serial.println("Right arrow"); Keyboard.release(KEY_RIGHT_ARROW); break;
    case '5': Keyboard.press(KEY_RETURN); Serial.println("Return"); Keyboard.release(KEY_RETURN); break;
    case '1': Keyboard.press(KEY_ESC); Serial.println("Escape"); Keyboard.release(KEY_ESC); break;
    case '0': Keyboard.press(KEY_LEFT_GUI); Keyboard.press(KEY_RETURN); Serial.println("Home"); Keyboard.release(KEY_LEFT_GUI); Keyboard.release(KEY_RETURN); break;
    case '*': Keyboard.press(KEY_LEFT_GUI); Keyboard.press(KEY_BACKSPACE); Serial.println("Universal back"); Keyboard.release(KEY_BACKSPACE); Keyboard.release(KEY_LEFT_GUI); break;
    default: break;
  }
}
