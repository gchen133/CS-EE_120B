//Lab 4 Starter
// C++ code
//Note: Upon downloading, this code does nothing except run without errors at a period of 500ms
//      It is up to you to figure out how to manipulate these timing details for your own purposes
#include "Timer.h"

enum STATE {OFF_STATE, SLOW_STATE_1, SLOW_STATE_2, FAST_STATE_1, FAST_STATE_2} gState = OFF_STATE;

//const int ledPin = 2;
//const int buttonPin = 13;
bool buttonPressed = 0;
int counter = 0;

void tick(void) {
  
  // transitions
  switch (gState) {

    case OFF_STATE:
      if (buttonPressed == 1) {
        gState = SLOW_STATE_1; 
      }
      else {
        gState = OFF_STATE; 
        }
    break;
    
    case SLOW_STATE_1:
      if (buttonPressed == 1) {
        gState = FAST_STATE_1; 
        counter = 0;
      }
      if (!(counter < 8)){
        counter = 0;
        gState = SLOW_STATE_2; 
      }
    break;

    case SLOW_STATE_2:
      if (buttonPressed == 1) {
        counter = 0;
        gState = FAST_STATE_1; 
      }
      if (!(counter < 8)){
        counter = 0;
        gState = SLOW_STATE_1; 
      }
    break;

    case FAST_STATE_1:
      if (buttonPressed == 1) {
        counter = 0;
        gState = OFF_STATE; 
      }
      if (!(counter < 2)){
        counter = 0;
        gState = FAST_STATE_2; 
      }
    break;

    case FAST_STATE_2:
      if (buttonPressed == 1) {
        counter = 0;
        gState = OFF_STATE; 
      }
      if (!(counter < 2)){
        counter = 0;
        gState = FAST_STATE_1; 
      }
    break;
  }
  
  // actions
  switch (gState) {
    case OFF_STATE:
        digitalWrite(2, LOW);
    break;

    case SLOW_STATE_1:
        digitalWrite(2, LOW);
        counter++;
    break;

    case SLOW_STATE_2:
        digitalWrite(2, HIGH);
        counter++;
    break;

    case FAST_STATE_1:
        digitalWrite(2, LOW);
        counter++;
    break;

    case FAST_STATE_2:
        digitalWrite(2, HIGH);
        counter++;
    break;
}
}

void setup() {
  TimerSet(100); //this value (100) is the period in ms
  TimerOn();
  pinMode(13, INPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  counter = counter + 1;
  buttonPressed = digitalRead(13);
  tick();
  while(!TimerFlag){}
  TimerFlag = 0;  
}