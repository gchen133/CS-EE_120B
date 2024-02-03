#include "Timer.h"

//max led == 13
//min led == 7

const int buttonPin = 2;

int firstDigit = 13;
int secondDigit = 12;

// gSegPins
// An array of pins of the arduino that are connected
// to segments a, b, c, d, e... g in that order.
char gSegPins[] = {8, 10, 19, 18, 17, 11, 9};

// displayNumTo7Seg
// displays one number (between 0 and 9) "targetNum" on the digit conneceted to "digitPin"
// E.g. If I wanted to display the number 6 on the third digit of my display.
// and the third digit was connected to pin A0, then I'd write: displayNumTo7Seg(6, A0);

void displayNumTo7Seg(unsigned int targetNum, int digitPin) {
    // A map of integers to the respective values needed to display
    // a value on one 7 seg digit.
    unsigned char encodeInt[10] = {
        // 0     1     2     3     4     5     6     7     8     9
        0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67,
    };
    // Make sure the target digit is off while updating the segments iteratively

    digitalWrite(digitPin, HIGH);
    // Update the segments
    for (int k = 0; k < 7; ++k) {
        digitalWrite(gSegPins[k], encodeInt[targetNum] & (1 << k));
    }

    // Turn on the digit again
    digitalWrite(digitPin, LOW);
}

enum state {FLASH_UP, FLASH_DOWN, HOLD_STATE_UP, HOLD_STATE_DOWN} gState = FLASH_UP;

void tick_LED_flashing(void) {
  int buttonPressed = digitalRead(2);
  int i = 7;
  pinMode(7, HIGH);
  switch (gState) {
    int counter = 0;
    case FLASH_UP:
      while((buttonPressed = 0) && (i != 13)) {
        pinMode(i + 1, HIGH);
        pinMode(i, LOW);
        i++;
        if (i = 13) {
        gState = FLASH_DOWN;
        }
      }
      if (buttonPressed = 1) {
        gState = HOLD_STATE_UP;
      }

    case FLASH_DOWN:
      int i = 13;
      pinMode(13, HIGH);
      while((buttonPressed = 0) && (i != 7)) {
          pinMode(i - 1, HIGH);
          pinMode(i, LOW);
          i--;
          if (i = 7) {
          gState = FLASH_UP;
          }
      }
      if (buttonPressed = 1) {
          gState = HOLD_STATE_DOWN;
      }
    
    case HOLD_STATE_UP:
      if (i = 10) {
        counter++;
      }
      else {
        counter = 0;
      }
      if (buttonPressed = 0) {
        gState = FLASH_UP;
      }
      else {
        gState = HOLD_STATE_DOWN;
      }

    case HOLD_STATE_DOWN:
      if (i = 10) {
        counter++;
      }
      else {
        counter = 0;
      }
      if (buttonPressed = 0) {
        gState = FLASH_DOWN;
      }
      else {
        gState = HOLD_STATE_DOWN;
      }
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);

  Serial.begin(9600);
  bool buttonPressed = 0;
  const int buttonPin = 2;
  TimerSet(10);
  TimerOn();
}

void loop() {
  bool buttonPressed = digitalRead(buttonPin);
  Serial.println(buttonPressed);
  digitalWrite(1, LOW);
  int num;

  digitalWrite(secondDigit, HIGH); //turns off second digit
  displayNumTo7Seg(num, firstDigit); // puts number on first digit
  digitalWrite(firstDigit, HIGH); //turns on second digit

  
  // put your main code here, to run repeatedly:

}
