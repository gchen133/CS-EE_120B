//#include "Timer.h"
#include "Stepper.h"

Stepper Stepper_1(2048, 8, 10, 9, 11);
Stepper Stepper_2(2048, 4, 6, 5, 7);

enum STATE {RESET, INIT, MANUAL, HOLD_1, LIGHT, HOLD_2, RADIO, HOLD_3} gState = INIT;

void State_Transfer(void) {
bool buttonPressed = digitalRead(2);

int brightnessLeft = analogRead(A4);
int brightnessRight = analogRead(A5);
int brightnessTop = analogRead(A3);
int brightnessBottom = analogRead(A2);
/////////////////////////////////// TRANSITIONS
switch (gState) {
  case RESET:
    //Serial.println("STATE RESET");
    gState = INIT;
    break;

  case INIT:
    //Serial.println("STATE INIT");
    gState = MANUAL;
    break; 

  case MANUAL:
    Serial.println("STATE MANUAL");
    if (buttonPressed == 0) {
      gState = HOLD_1;
    }
  break;

  case HOLD_1:
    //Serial.println("STATE HOLD_1");
    if (buttonPressed == 1) {
      gState = LIGHT;
    }
  break;

  case LIGHT:
    Serial.println("STATE LIGHT");
    if (buttonPressed == 0) {
      gState = HOLD_2;
    }
  break;

  case HOLD_2:
    //Serial.println("STATE HOLD_2");
    if (buttonPressed == 1) {
      gState = RADIO;
    }
  break;

  case RADIO:
    Serial.println("STATE RADIO");
    if (buttonPressed == 0) {
      gState = HOLD_3;
    }
  break;

  case HOLD_3:
    //Serial.println("STATE HOLD_3");
    if (buttonPressed == 1) {
      gState = MANUAL;
    }
  break;

}
/////////////////////////////////// ACTIONS
switch (gState) {
  case RESET:
  break;

  case INIT:
  break;

  case MANUAL:
    int X = analogRead(A0)-512;
    int Y = analogRead(A1)-512;

    if (abs(Y) > 100) {
      Stepper_1.step(Y/10);
    }
    if (abs(X) > 100) {
      Stepper_2.step(X/10);
    }
  break;

  case HOLD_1:
  break;

  case LIGHT:
    if ((brightnessLeft >= brightnessRight) && (brightnessLeft < 150)) {
    Stepper_1.step(50); //stepper left rotate
    } 
    else if ((brightnessLeft <= brightnessRight) && (brightnessRight < 150)) {
    Stepper_1.step(-50); //stepper right rotate
    } 
    if ((brightnessTop >= brightnessBottom) && (brightnessTop < 150)) {
    Stepper_2.step(50); //stepper up rotate
    } 
    else if ((brightnessTop <= brightnessBottom) && (brightnessBottom < 150)) {
    Stepper_2.step(-50); //stepper down rotate
    } 
  break;

  case HOLD_2:
  break;

  case RADIO:
    /*if () {
      Stepper_1.step(50)
    }
    else if () {
      Stepper_1.step(-50)
    }
    if () {
      Stepper_2.step(50)
    }
    else if () {
      Stepper_2.step(-50)
    }*/
  break;

  case HOLD_3:
  break;

}
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bool buttonPressed = digitalRead(2);
  int stepperSpeed = 10;

  int X = analogRead(abs((A0)-512)/10);
  int Y = analogRead(abs((A1)-512)/10);
  
  Stepper_1.setSpeed(X);
  Stepper_2.setSpeed(Y);
  // put your setup code here, to run once:
  
  pinMode(2, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  State_Transfer();
}
