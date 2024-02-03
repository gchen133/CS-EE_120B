//Lab 4 Starter
// C++ code
//Note: Upon downloading, this code does nothing except run without errors at a period of 500ms
//      It is up to you to figure out how to manipulate these timing details for your own purposes
#include "Timer.h"

enum STATE {RED_STATE, GREEN_STATE, YELLOW_STATE} gState = RED_STATE;

//const int ledPin = 2;
//const int buttonPin = 13;
bool buttonPressed = 0;
int counter = 0;

void tick(void) {
  
  // transitions
  switch (gState) {
      case RED_STATE:
          counter = 0;
          if (buttonPressed == 1) {
            gState = GREEN_STATE; 
          }
          else {
            gState = RED_STATE; 
            }
      break;

      case GREEN_STATE:
          if (counter > 20) {
            counter = 0;
            gState = YELLOW_STATE; 
          }
          else {
            gState = GREEN_STATE; 
            }
      break;

      case YELLOW_STATE:
          if (counter > 10) {
            counter = 0;
            gState = RED_STATE; 
          }
          else {
            gState = YELLOW_STATE; 
            }
      break;
  }
  
  // actions
  switch (gState) {
    case RED_STATE:
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    break;

    case GREEN_STATE:
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        counter++;
    break;

    case YELLOW_STATE:
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        counter++;
    break;

}
}

void setup() {
  TimerSet(500); //this value (1000) is the period in ms
  TimerOn();
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  buttonPressed = digitalRead(13);
  tick();
  while(!TimerFlag){}
  TimerFlag = 0;  
}