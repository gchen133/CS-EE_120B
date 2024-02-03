#include "Timer.h"

// Helper Function display a number on ONE digit
// gSegPins
// An array of pins of the arduino that are connected
// to segments a, b, c, d, e... g in that order.

char ledPins[] = {2, 3, 4, 5, 6, 7};
char gSegPins[] = {8, 10, 19, 18, 17, 11, 9};

unsigned int buttonPin = 16;
unsigned int buttonPressed = digitalRead(buttonPin);
unsigned int ledPos = 0;
int counter = 0;

//     A
//    ---
// F |   | B
//   | G |
//    ---
// E |   | C
//   |   |
//    ---
//     D


// task function declarations
void tick_LED_flashing();
void displayNumTo7Seg();

enum STATE {INIT, FLASH_UP, FLASH_DOWN, HOLD_STATE_UP, HOLD_STATE_DOWN} gState = INIT;

void tick_LED_flashing() {

////////////////////////////////////////////FLASH STATES

  switch (gState) {

    case INIT:
      gState = FLASH_UP;
    break;

    case FLASH_UP:
      if (buttonPressed == 1) {
        //Serial.println("In HOLD_STATE_UP");
        gState = HOLD_STATE_UP;
      }
      if (ledPos <= 4) {
        ledPos++;
      }
      else {
        gState = FLASH_DOWN;
      }
    break;

    case FLASH_DOWN:
      if (buttonPressed == 1) {
        //Serial.println("In HOLD_STATE_DOWN");
        gState = HOLD_STATE_DOWN;
      }
      if (ledPos >= 1) {
        ledPos--;
      }  
      else {
        gState = FLASH_UP;
      }
    break;
////////////////////////////////////////////HOLD STATES

    case HOLD_STATE_UP:
      if (buttonPressed == 0) {
        if (ledPos == 4) {
          counter++;
          gState = FLASH_UP;
        }  
        else {
          counter = 0;
          gState = FLASH_UP;
        }
      } 
    break;

    case HOLD_STATE_DOWN:
      if (buttonPressed == 0) {
        if (ledPos == 2) {
          counter++;
          gState = FLASH_DOWN;
        }  
        else {
          counter = 0;
          gState = FLASH_DOWN;
        }
      }
    break;
  }
//////////////////////////////////////////// TRANSITION ACTIONS

  switch (gState) {
    case INIT:
      digitalWrite(ledPins[0], HIGH);
    break;
      
    case FLASH_UP:
      for(unsigned int i = 0; i < 5; i++){
        digitalWrite(ledPins[i],LOW);
      }
        digitalWrite(ledPins[ledPos],HIGH);
    break;

    case FLASH_DOWN:
      for(unsigned int i = 5; i > 0; i--){
        digitalWrite(ledPins[i],LOW);
      }
        digitalWrite(ledPins[ledPos],HIGH);
    break;

//////////////////////////////////////////// HOLD ACTIONS

    case HOLD_STATE_UP:
    break;

    case HOLD_STATE_DOWN:
    break;
  }
}
  // displayNumTo7Seg
  // displays one number (between 0 and 9) "targetNum" on the digit conneceted to "digitPin"
  // E.g. If I wanted to display the number 6 on the third digit of my display.
  // and the third digit was connected to pin A0, then I'd write: displayNumTo7Seg(6, A0);

void displayNumTo7Seg(unsigned int targetNum, int digitPin) {
    // A map of integers to the respective values needed to display
    // a value on one 7 seg digit.
    unsigned char encodeInt[10] = {
      // 0     1     2     3     4     5     6     7     8     9
        0x3f, 0x06, 0x5b,0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67,
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

void setup() {
    // put your setup code here, to run once:
    TimerSet(100);
    TimerOn();
    Serial.begin(9600);

    pinMode(2, OUTPUT);  //RED LED
    pinMode(3, OUTPUT);  //RED LED
    pinMode(4, OUTPUT);  //RED LED
    pinMode(5, OUTPUT);  //GREEN LED
    pinMode(6, OUTPUT);  //RED LED
    pinMode(7, OUTPUT);  //RED LED

    pinMode(8, OUTPUT);   // A
    pinMode(9, OUTPUT);   // G
    pinMode(10, OUTPUT);  // B
    pinMode(11, OUTPUT);  // F
    pinMode(12, OUTPUT);  // D2
    pinMode(13, OUTPUT);  // D1

    pinMode(16, INPUT_PULLUP);  // BUTTONPIN

    pinMode(17, OUTPUT);  //E
    pinMode(18, OUTPUT);  //D
    pinMode(19, OUTPUT);  //C
  }

void loop() {
    // put your main code here, to run repeatedly:
    buttonPressed = digitalRead(buttonPin);
    tick_LED_flashing();

    if (counter < 10) {
      displayNumTo7Seg(counter, 0);
      digitalWrite(12, HIGH); //turns off second degit
    }
    else { //counter > 9
      digitalWrite(12, LOW);
      displayNumTo7Seg(0, 0); //ones
      displayNumTo7Seg(1, 1); //tens
    }
    //Serial.println(counter);
    //Serial.println(counter % 10);
    //Serial.println(counter / 10);

    while (!TimerFlag){}
    TimerFlag = 0;
  }