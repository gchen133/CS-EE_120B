//Lab 4 Starter
// C++ code
//Note: Upon downloading, this code does nothing except run without errors at a period of 500ms
//      It is up to you to figure out how to manipulate these timing details for your own purposes
#include "Timer.h"

int brightness = analogRead(A0);
int counter = 0;

enum STATE {ON_INITIAL, OFF_COUNTDOWN} gState = ON_INITIAL;

void tick(void) {
  int brightness = analogRead(A0);
  // transitions
  switch (gState) {
      case ON_INITIAL:
          counter = 0;
          if (brightness > 350) {
            gState = OFF_COUNTDOWN; 
          }
          else {
            gState = ON_INITIAL; 
          }
      break;

      case OFF_COUNTDOWN:
          if (brightness > 350) {
            counter = 0;
            gState = OFF_COUNTDOWN; 
          }
          if ((counter > 10)) {
            gState = ON_INITIAL; 
          }
      break;
  }
  
  // actions
  switch (gState) {
    case ON_INITIAL:
        digitalWrite(9, HIGH);
    break;

    case OFF_COUNTDOWN:
        digitalWrite(9, LOW);
        counter++;
    break;
}
}

void setup() {
  TimerSet(500); //this value (1000) is the period in ms
  TimerOn();
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  tick();
  Serial.println(brightness);
  while(!TimerFlag){}
  TimerFlag = 0;  
}